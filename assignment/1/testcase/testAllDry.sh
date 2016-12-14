
#!/bin/bash

for i in {1..11}
do
clang -Wall -Werror -o dry$i dry$i.c textbuffer.c -g
done

for i in {1..11}
do
./dry$i
done

