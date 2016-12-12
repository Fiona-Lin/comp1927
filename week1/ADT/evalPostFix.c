#include <stdio.h>
#include <stdlib.h>

#include "Item.h"
#include "Stack.h"

int main(int argc, char * argv[]){
    char * exp; //pointer to current character in input string    
    int i;

    if(argc <= 1){
        printf("Incorrect usage: Please enter postfix expression\n");
        exit(1);
    }
    printf("My expression is %s\n",argv[1]);
    exp = argv[1];

    //Create a stack
    Stack s = createStack();

    for(i=0; exp[i] != '\0'; i++){
        if(exp[i] == '+' || exp[i] == '*' || exp[i] == '-'){
            if(stackSize(s) < 2){
                printf("Error: Invalud Expersionasdfasdf\n");
                exit(1);
            }
            Item num1 = pop(s);
            Item num2 = pop(s);
            Item result = 0;
            if(exp[i] == '+'){
                result = num1 + num2;
            } else if(exp[i] == '*'){
                result = num1 * num2;
            } else {
                result = num2 - num1;
            }
            push(s,result);
        } else if(exp[i] >= '0' && exp[i] <= '9'){
            push(s,exp[i] - '0'); //convert from char to int

        }
    }
    //Too many numbers
    if(stackSize(s) != 1){
        printf("Error: Invalid Expression\n");
    }else {
        printf("%d\n",pop(s));
    }
    destroyStack(s);
    return 0;
}
