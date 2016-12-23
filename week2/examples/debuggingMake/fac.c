#include <stdlib.h>
#include <stdio.h>

int fac(int);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr,"Usage: %s N\n",argv[0]);
		exit(1);
	}

	int i = atoi(argv[1]);

	printf("%d! = %d\n", i, fac(i));
        printf("asdfasdf");
	return 0;
}

int fac(int n)
{
	if (n < 2)
		return 1;
	else
		return n * fac(n-1);
}
