#include <stdio.h>
#include "automa.h"
/*
 * 'simula' un automa a stati finiti deterministico
 * */
#define MAX_NUM_DELTA 1000

int loadfile(FILE *fda_desc, struct delta *fda) {
	int start_state, end_state, fin;
	char ch;

	int i;
	struct delta temp;
	i = 0;
	while (!feof(fda_desc)) {
		fscanf(fda_desc, "%d %c %d %d\n", &start_state, &ch, &end_state, &fin);
		temp.letter = ch;
		temp.from_state= start_state;
		temp.to_state = end_state;
		temp.finale = fin;
		fda[i] = temp;
		i++;
	}
	return i;
}

/*
 * ritorna il prossimo stato
 */
int search_delta(struct delta *fda, int max, char ch, int curr_state) {
	int special = 0;
	int tmp_to_state = 0;

	for(int i = 0; i < max; i++) {
		if (fda[i].from_state == curr_state && fda[i].letter == ch) {
			printf("special %d\n", d_special(&fda[i]));
			return fda[i].to_state;
		}
		if (fda[i].from_state == curr_state && d_special(&fda[i]) == STATE_S_EVERYTHING) {
			/*
			 * Madonna che schifo di codice
			 */
			special = STATE_S_EVERYTHING;
			tmp_to_state = fda[i].to_state;
		}
	}
	if(special != 0)
		return tmp_to_state;
	return -1;
}

int is_final(struct delta *fda, int max, int stato) {
	for(int i = 0; i < max; i++) {
		if (fda[i].from_state == stato) {
			return d_final(&fda[i]);
		}
	}
	return 0;
}


int run(struct delta *fda, int max,  char *str) {
	int current_state = 0;	//stato predefinito iniziale è lo zero.
	int i = 0;
	while(str[i] != 0) {
		current_state = search_delta(fda, max, str[i], current_state);
		if(current_state == -1) {
			printf("-NO\n");
			return -1;
		}
		i++;
	}
	if (is_final(fda, max, current_state)) {
		printf("YES\n");
		return 1;
	} else {
		printf("NO\n");
	}
	return 0;
}

int main(int argc, char **argv) {
	FILE *fda_desc;
	char *input;
	char *filename;
	struct delta fda[MAX_NUM_DELTA]; // finite deterministic automa
	int num_delta;
	
	if (argc < 2) {
		printf("Mancano degli argomenti\n%s file stringa\n",argv[0]);
		return 0;
	}


	if (argc == 3) {
		input = argv[2];
		filename = argv[1];
		printf("Input string: %s\nFile: %s\n", input, filename);
		fda_desc = fopen(filename, "r");
	}
	else if (argc == 2) {
		input = argv[1];
		printf("Input from stdin\n");
		fda_desc = stdin;
	}
	
	if (fda_desc == NULL) {
		printf("Non riesco ad aprire il file\n");
		return 0;
	}

	num_delta = loadfile(fda_desc, fda);
	if(fda_desc != stdin)
		fclose(fda_desc);

	if (num_delta <= 0) {
		printf("There is nothing useful in the file\n");
		return 1;
	}

	run(fda, num_delta, input);
	
	return 0;
}
