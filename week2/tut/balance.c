#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE !FALSE

int balance(char * s);

int main(int argc, char * agrv []) {
    if (argc )
        return EXIT_SUCCESS;
}

int balance(char * s) {
    int len = strlen(s);
    int res = (len % 2 != 0 );
    int rRoundcounter = 0;
    int rCurlycounter = 0;
    int rSquarecounter = 0;
    int lRoundcounter = 0;
    int lCurlycounter = 0;
    int lSquarecounter = 0;
    int i = 0;
    if (res) {
        for (i = 0; i < len; i++) {
            switch(s[i]) {
                case '(':
                    rRoundcounter ++;
                    break;
                case '{':
                    rCurlycounter ++;
                    break;
                case '[':
                    rSquarecounter ++;
                    break;
                case ')':
                    lRoundcounter ++;
                    break;
                case '}':
                    lCurlycounter ++;
                    break;
                case ']':
                    lSquarecounter ++;
                    break;
            }
            res = (lRoundcounter > rRoundcounter)? FALSE : TRUE;
            res = (lCurlycounter > rCurlycounter)? FALSE : TRUE;
            res = (lSquarecounter > rSquarecounter)? FALSE : TRUE;
        }
    }
    return res;
}

