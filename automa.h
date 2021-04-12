#define STATE_NOFINAL 0
#define STATE_FINAL 1
#define STATE_SPECIAL_EVERYTHING 2
#define STATE_SPECIAL_EVERYTHING_FINAL 3

struct delta {
	char letter; // la lettera per passare a next_state
	int from_state;
	int to_state;
	int finale; // 1 se lo stato è finale
};

int
d_final(struct delta *d)
{
	switch(d->finale) {
		case STATE_FINAL:
			return 1;
			break;
		case STATE_SPECIAL_EVERYTHING_FINAL:
			return 1;
			break;
		default:
			return 0;
	}
	return 0;
}

void
set_delta(struct delta *d, int from_state, char letter, int to_state, int finale)
{
	d->from_state = from_state;
	d->letter = letter;
	d->to_state = to_state;
	d->finale = finale;
}
