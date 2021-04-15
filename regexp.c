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

/*
 *  '[a-z]', '[1-3]'
 */
int
m_range(struct delta *current_d, int curr_state, char start_ch, char end_ch)
{
	if(end_ch < start_ch)
		return -1;

	for(;start_ch <= end_ch; start_ch++)
		output(d_set(current_d, curr_state, start_ch, curr_state+1, S_PLACEBO));

	return curr_state+1;
}

/*
 * '.' match any char
 */
int
m_everything(struct delta *current_d, int curr_state)
{
	output(d_set(current_d, curr_state, 'a', curr_state+1, S_EVERYTHING));
	return curr_state+1;
}

int
create_automa(char *regex)
{
	int curr_state = 0;
	struct delta current_d;

	curr_state = m_range(&current_d, curr_state, 'A', 'E');
	curr_state = m_everything(&current_d, curr_state);

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
