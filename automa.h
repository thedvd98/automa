#define STATE_FINAL -1
#define STATE_NOFINAL 0
#define STATE_PLACEBO 1 // serve a niente
#define STATE_S_EVERYTHING 2

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
	if(d->finale >= 0)
		return d->finale;
	return (-1)*(d->finale);
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

