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
range_match(struct delta *current_d, int curr_state, char start_ch, char end_ch)
{
	if(end_ch < start_ch){
		//error
		return -1;
	}

	for(;start_ch <= end_ch; start_ch++){
		output(d_set(current_d, curr_state, start_ch, curr_state+1, STATE_NOFINAL));
	}
	return curr_state+1;
}

int
create_automa(char *regex)
{
	int curr_state = 0;
	struct delta current_d;

	curr_state = range_match(&current_d, curr_state, 'A', 'E');
	printf("%d %d\n", curr_state, -1);
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
