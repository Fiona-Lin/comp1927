#include <stdlib.h>
#include <stdio.h>

int fac(int);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr,"Usage asdf: %s N\n",argv[0]);
		exit(1);
	}

	int i = atoi(argv[1]);

	printf("%d! = %d\n", i, fac(i));

	return 0;
}

int fac(int n)
{
	int prod = 1;
	if (n > 1) {
		int i;
		for (i = 2; i <= n; i++)
			prod *= n;
	}
	return prod;
}
