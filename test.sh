#!/bin/sh

CMD=./automa 
echo TEST 1

function esegui_test() {
	echo ======== $FILE ========
	echo = YES =
	for arg in ${YES[@]}; do
		echo -ne "$arg\t"
		$CMD $FILE $arg
	done
	echo = NO =
	for arg in ${NO[@]}; do
		echo -ne "$arg\t"
		$CMD $FILE $arg
	done
}

YES=(0001 01 1 11)
NO=(0 10 000 11110)
FILE=finiscein1.txt
esegui_test

YES=(01 1 11 aaa1 b1 31)
NO=(0 10 000 11110 212 1a bbb)
FILE=complete_finiscein1.txt
esegui_test

YES=(a aaa aaaaa)
NO=(b aa aaaa)
FILE=adispari.txt
esegui_test
