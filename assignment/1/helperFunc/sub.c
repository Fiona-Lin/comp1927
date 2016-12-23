#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


char ** splitLines(char * s, int * l) {
    int i;
    char ** lines = NULL;
    int len = strlen(s);
    int lastI  = -1;
    for (i = 0; i < len; i++)
        if(s[i] == '\n')
            (*l)++;
    lines = malloc( (*l) * sizeof(char *));
    *l = 0;
    for (i = 0; i < len; i++) {
        if(s[i] == '\n') {
            //work out the last index and next
            lines[*l] = strndup(s+lastI+1, i - lastI);
            lastI = i;
            (*l)++;
 //           printf("l:%d\t", *l);
 //           printf("s[i]:%s\t", s+i);
 //           printf("i:%d\n", i);
        }
    }
    return lines;
}

int main(int argc, char * argv[]) {
    char s [] = "Happy hour\nis at\n5 pm.\n";
    int len = 0;
    char ** res = splitLines(s, &len);
    int i;
    for (i = 0; i < len; i++) {
        free(res[i]);
        printf("%s\n", res[i]);
    }
        free(res);
    return EXIT_SUCCESS;
}
