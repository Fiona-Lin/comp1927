#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//strtok
//strsep

void modifyString(char * s){
    char * sCopy = strdup(s);
    strtok(sCopy);

    free(sCopy);
}

int main(int argc, char * argv[]){
   char str1[] = "Hello";
   //char * str2 = "Hello";

   modifyString(str1);
   printf("%s\n",str1);

   //modifyString(str2);
   //printf("%s\n",str2);

   modifyString("Hello");
   return 0;
}
