#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void replaceText(char *s, char* str1, char* str2) ;
int main(int argc, char * argv[]) {
    char *s  = strdup("Happy hour\nis 2 hour from\n5 pm.\n");
    char *s1  = strdup("Happy hour\nis 2 hour from\n5 pm.\n");

    printf("%s\n", s);
    printf("%s\n", s1);
    //s = replaceText(s, "hour", "hourhour");
    replaceText(s, "hour", "");
    printf("%s\n", s);
    free(s);
    return EXIT_SUCCESS;
}

void replaceText(char* s, char* str1, char* str2) {
        char *m;
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        m = s;
        int offset = 0;
        int diff = len2 - len1 + 1;
        while (m < s + strlen(s) && (m = strstr(m + offset, str1))!= NULL) {
            int len = strlen(s);
            char * lineCopy = strdup(m + strlen(str1));
            *m = '\0';
            offset = strlen(s);
            s = realloc(s, len + diff);
            *m = str1[0];
            m = strstr(s + offset, str1);
            strcpy(m, str2);
            strcat(s, lineCopy);
            free(lineCopy);
        }
}

//
//char* replaceText(char* s, char* str1, char* str2) {
//        char *match;
//        int len1 = strlen(str1);
//        int len2 = strlen(str2);
//        int l = 0;
//        while ((match = strstr(s+l, str1)) != NULL) {
//            char* curr = malloc(strlen(s) - len1 + len2 + 1);
//            memcpy(curr, s, match-s);
//            curr[match-s] = 0;
//            strcat(curr, str2);
//            l = strlen(curr);
//            strcat(curr,match + len1);
//
//            free(s);
//            s = curr;
//        }
//        return s;
//
//}
//
//char* replaceText(char* s, char* str1, char* str2) {
//    char * occur = NULL;
//    int i = 0;
//    int len1 = strlen(str1);
//    int len2 = strlen(str2);
//    int diff = len2 - len1;
//    occur = strstr(s,str1);
//    while (occur != NULL) {
//        occur = strstr(occur+len1,str1);
//        i++;
//    }
//    occur = s;
//    int l = strlen(s) + (i*diff) + 1;
//    char * res = calloc(l * sizeof(char), 1);
//    strcpy(res, s);
//    int off = 0;
//    while ((occur = strstr(res + off, str1)) != NULL) {
//        char * tem = strdup(occur + len1);
//        strcpy(occur, str2);
//        off = strlen(res);
//        strcpy((occur + len2), tem);
//        free(tem);
//    }
//    free(s);
//    return res;
//}
