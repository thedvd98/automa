#define S_PLACEBO 0
#define S_EVERYTHING 1

struct delta {
	char letter; // la lettera per passare a next_state
	int from_state;
	int to_state;
	int finale;
};

/*
 * positivizza stati speciali anche finali
 * ottiene il valore speciale
 */
int
d_special(struct delta *d)
{
	return d->finale;
}
	
/*
 * NO.
 */
struct delta*
d_set(struct delta *d, int from_state, char letter, int to_state, int finale)
{
	d->from_state = from_state;
	d->letter = letter;
	d->to_state = to_state;
	d->finale = finale;
	return d;
}

