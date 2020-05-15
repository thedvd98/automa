#include <stdio.h>
/*
 * 'simula' un automa a stati finiti deterministico
 * */
#define MAX_NUM_DELTA 1000

struct delta {
	char letter; // la lettera per passare a next_state
	int from_state;
	int to_state;
	int finale; // 1 se lo stato è finale
};

int loadfile(char *filename, struct delta *fda) {
	int start_state, end_state, fin;
	char ch;

	int i;
	struct delta temp;
	FILE *fda_desc;
	fda_desc = fopen(filename, "r");
	if (fda_desc == NULL) {
		printf("Non riesco ad aprire il file\n");
		return 0;
	}
	
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
	printf("File caricato con successo! Composto da %d righe\n", i);
	fclose(fda_desc);
	return i;
}

int search_delta(struct delta *fda, int max, char ch, int curr_state) {
	for(int i = 0; i < max; i++) {
		if (fda[i].from_state == curr_state && fda[i].letter == ch) {
			return fda[i].to_state;
		}
	}
	return -1;
}

int is_final(struct delta *fda, int max, int stato) {
	for(int i = 0; i < max; i++) {
		if (fda[i].from_state == stato) {
			return fda[i].finale;
		}
	}
	return -1;
}


int run(struct delta *fda, int max,  char *str) {
	int current_state = 0;	//stato predefinito iniziale è lo zero.
	int i = 0;
	while(str[i] != 0) {
		current_state = search_delta(fda, max, str[i], current_state);
		if(current_state == -1) {
			printf("Probabilmente stai usando caratteri non presenti nell'alfabeto dell'automa\n");
			return -1;
		}
		i++;
	}
	if (is_final(fda, max, current_state)) {
		printf("La stringa appartiene al linguaggio definito dall'automa!\n");
		return 1;
	} else {
		printf("La stringa non appartiene al linguaggio!\n");
	}
	return 0;
}

int main(int argc, char **argv) {
	char *input;
	char *filename;
	struct delta fda[MAX_NUM_DELTA]; // finite deterministic automa
	int num_delta;
	
	if (argc < 3) {
		printf("Mancano degli argomenti\n%s file stringa\n",argv[0]);
		return 0;
	}
	
	input = argv[2];
	filename = argv[1];
	printf("Input string: %s\nFile: %s\n", input, filename);

	num_delta = loadfile(filename, fda);
	if (num_delta <= 0) {
		return 1;
	}
	run(fda, num_delta, input);
	
	return 0;
}
