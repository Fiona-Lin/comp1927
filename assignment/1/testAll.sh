#!/bin/bash


for i in {1..11}
do
	echo
	echo $i#;
	# cat  testfiles/test$i
 clang -Wall -Werror -g testcase/dry$i.c textbuffer.c -o dry$i
 ./dry$i >result
 diff -iEBw testoutput/result$i result
 valgrind --leak-check=full -v ./dry$i
rm dry$i
done

