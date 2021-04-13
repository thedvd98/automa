/*
 * see man 7 regexp (plan9port man page)
 */
#include <stdio.h>

#include "automa.h"

#define DEBUG 1

void
usage()
{
	printf("Usage: regexp 'regularexpression'\n");
}

void debug(char *str) {
	fprintf(stderr, "debug: %s");
}


void
output(struct delta *d)
{
	fprintf(stdout, "%d %c %d %d\n",
				d->from_state,
				d->letter,
				d->to_state,
				d->finale);
}

int
create_automa(char *regex)
{
	int curr_state = 0;
	struct delta current_d;

	int i=0;
	while(*regex != '\0') {
		if(*(regex+1) == '\0') {
			d_set(&current_d, curr_state, *regex, curr_state+1, STATE_NOFINAL);
			output(&current_d);
			d_set(&current_d, curr_state+1, *regex, curr_state+2, STATE_FINAL);
			output(&current_d);
		}
		else {
			d_set(&current_d, curr_state, *regex, curr_state+1, STATE_NOFINAL);
			output(&current_d);
		}
		curr_state += 1;
		regex++;
	}

	return 0;
}

int
main(int argc, char *argv[])
{
	char *regex;
	if(argc < 2) {
		usage();
		return 0;
	}

	regex = argv[1];
	/*TODO
	 * directly create a file (substitute stdout with fd)
	 * more regex at once (more arguments)
	 */
	return create_automa(regex);
}
