CC=gcc

ALL=automa regexp

all:V: $ALL

automa: automa.c automa.h
	$CC -o automa automa.c

regexp: regexp.c automa.h
	$CC -o regexp regexp.c

clean:
	rm automa regexp
