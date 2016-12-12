#include <stdio.h>

// what is this type?
typedef int (*IntFunction)(int);

int decrement(int);
int doublify(int);
int factorial(int);
int fibonacci(int);

int main(int argc, char *argv[])
{
	int i, j;
	char *fnames[4];
	IntFunction funcs[4]; //int (*funcs[4])(int);

	// set up array of functions
	fnames[0] = "dec"; funcs[0] = &decrement;
	fnames[1] = "doub"; funcs[1] = &doublify;
	fnames[2] = "fac"; funcs[2] = &factorial;
	fnames[3] = "fib"; funcs[3] = &fibonacci;

	// for each value from 1..9
	for (i = 1; i < 10; i++) {
		printf("%d: ",i);
		for (j = 0; j < 4; j++) {
			// apply the j'th function to i
			printf("%s:%d  ", fnames[j], (*funcs[j])(i));
		}
		printf("\n");
	}
	// show function addresses
	for (i = 0; i < 4; i++)
		printf("%s @ %p\n", fnames[i], funcs[i]);
	return 1;
}

int decrement(int n)
{
	return n-1;
}

int doublify(int n)
{
	return 2*n;
}

int factorial(int n)
{
	int i, fac;
	for (i = 1, fac = 1; i <= n; i++)
		fac = fac * i;
	return fac;
}

int fibonacci(int n)
{
	if (n < 1) return 0;
	if (n == 1) return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}

