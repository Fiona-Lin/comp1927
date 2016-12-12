#include <stdio.h>

int mystery(int a, int b, int (*fn)(int,int)) {
    return ((*fn)(a,b)); 
}

int gcd(int a, int b) {
  int c;
  while ( a != 0 ) {
     c = a; 
     a = b%a;  
     b = c;
  }
  return b;
}
int sumofsquares(int x, int y) { 
    return (x*x + y*y);
}
int sum(int x, int y) { 
    return (x + y);
}
int main(){
    int n = mystery(8,12,sum);
    printf("%d \n", n);
    printf("%d \n", mystery(8,12,gcd));
    printf("%d \n", mystery(8,12,sumofsquares));
    return 0;
} 
