#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "textBuffer.h"

int main(int argc, char *argv[]) {
    TB tb1 = newTB("1.1 abc\n1.2 def\n");
    char* str = dumpTB(tb1) ;     
    
    printf("Original Tb:\n%s\n",str) ; 
    free(str) ; 
        
    deleteTB(tb1,1,1) ; 
    str = dumpTB(tb1) ; 
    printf("Second line is deleted...\n%s\n",str) ; 
    free(str) ;     
         
    releaseTB (tb1);
    printf("Released Tb \n");

    return EXIT_SUCCESS;
}
