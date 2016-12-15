#!/bin/bash


for i in {5..6}
do
	echo
	echo $i#;
	# cat  testfiles/test$i
clang -Wall -Werror -g testcase/dry$i.c textbuffer.c -o dry$i
./dry$i >result
diff -iEBw testoutput/result$i result
rm dry$i
done

