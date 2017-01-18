#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>


int main(int argc, char * argv[]){
  
  
    int seed = time(NULL);
   
    if(argc == 2) 
         seed = atoi(argv[1]);
 
    
    printf("The seed is %d\n",seed);
    srand(seed);


    int i;
    for(i=0; i < 10; i++){
        printf("%d\n",rand()%50);
        
    }

    return 0;
}
