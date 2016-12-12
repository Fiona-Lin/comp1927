#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Different ways to create strings.
//Be careful when using "string literals" 

int main(int argc, char * argv[]){
   char str1[] = "Hello"; //string literal is used to initialise the array
                          //we can access individual chars and change them
   char * str2 = "Hello"; //points to string literal in Read Only Memory
                          //individual chars can't be modified
   char * str3 = str1;
   
   
   char * str4;
   char str5[6];
   char * str6 = malloc(sizeof(char) * 6);
 
  
   //We can modify characters of str1
   str1[0] = 'Z';
   
   printf("%s\n",str1);

   //We can't modify letters of the string str2
   //is pointing to
   str2[0] = 'Z';

   printf("%s\n",str2);

   //str3 is just pointing to str1
   //so we can modify the chars inside it
   //but it changes str1
   str3[0] = 'A';

   printf("%s\n",str1);
   printf("%s\n",str3);

   //We can make str4 point to the string literal "Hello"    
   str4 = "Hello";
   //We can't modify the constant string with "Hello" in it
   //str4[0] = 'Z';
   printf("%s\n",str4);
   str4 = "Dog";

   //We can't make str5 point anywhere else so this does not work
   //we would need to use strcpy or something that copies
   //the chars into the array - taking care to not overwrite past
   //the end of the array
   //str5 = "Hello";
   strcpy(str5,"Hello");
   str5[0] = 'Z';
   printf("%s\n",str5);
   
   
   strcpy(str6,"Hello");
   str6[0] = 'Z';
   printf("%s\n",str6);
   //We now have a memory leak as str6 is pointing to this string
   //now instead of the string we malloced.
   str6 = "Goodbye";
   //str6[0] = 'Z'; //we now have a constant string so can't modify it
   printf("%s\n",str6);
   
   

   return 0;
}
