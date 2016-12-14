#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "textBuffer.h"

typedef struct textLine * Line;

struct textbuffer{
    Line head;
    Line tail;
    int size;
    //Opt history;
};

struct textLine{
    char * s;
    Line prev;
    Line next;
};


//typedef struct operation * Opt;
//struct operation{
//
//};

static Line newTextLine(char s[]) {
    Line new = malloc(sizeof(struct textLine));
    assert(new != NULL);
    new -> s = strdup(s);
    new -> prev = NULL;
    new -> next = NULL;
    return new;
}

static void destroyLine(Line l) {
    assert(l != NULL);
    if(l -> s != NULL) {
        free(l->s);
    }
    free(l);
}
static Line getLine(TB tb, int pos) {
    Line l = NULL;
    if (tb != NULL && pos < linesTB(tb) && pos >= 0) {
        l = tb -> head;
        int i = 0;
        while (l != NULL && i <= pos) {
            l = l-> next;
            i++;
        }
    }
    return l;
}
static char ** splitLines(char * s, int * l) {
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

/* Allocate a new textbuffer whose contents is initialised with the text given
 * in the array.
 */
TB newTB (char text[]) {
    TB new = malloc(sizeof(struct textbuffer));
    int i;
    Line newLine = NULL;
    Line curr = NULL;
    assert(new != NULL);
    char ** lines = splitLines(text, &(new -> size));
    for (i = 0; i < (new -> size); i++) {
        newLine = newTextLine(lines[i]);
        if (i == 0) {
            new -> head = newLine;
            curr = newLine;
        } else {
            curr -> next = newLine;
            curr = curr -> next;
        }
        if (i == (new -> size - 1)) {
            new -> tail = curr;
        }
    }
    return new;
}

/* Free the memory occupied by the given textbuffer.  It is an error to access
 * the buffer afterwards.
 */
void releaseTB (TB tb) {
    Line cur = NULL;
    Line tmp = NULL;
    assert(tb != NULL);
    cur = tb -> head;
    while (cur != NULL) {
        tmp = cur;
        destroyLine(tmp);
        cur = cur -> next;
    }
    free(tb);
}

/* Allocate and return an array containing the text in the given textbuffer.
*/
char *dumpTB (TB tb) {
    char * res = malloc(sizeof(char));
    if (res != NULL){
        res[0] = '\n';
    }
    if (tb != NULL) {
        Line cur = tb -> head;
        while(cur != NULL) {
            res = realloc(res, sizeof(strlen(res)+strlen(cur -> s)+1));
            strcat(res, cur -> s);
            cur = cur -> next;
        }
    }
    return res;
}

/* Return the number of lines of the given textbuffer.
*/
int linesTB (TB tb) {
    int res = 0;
    if (tb != NULL) {
        res = tb -> size;
    }
    return res;
}

/* Swap the two given lines in the textbuffer.
 *
 * - The program is to abort() with an error message if line 'pos1' or line
 *   'pos2' is out of range.  The first line of a textbuffer is at position 0.
 */
void swapTB (TB tb, int pos1, int pos2) {
    assert(tb != NULL);
    int total = linesTB(tb);
    if (pos2 >= total) {
        printf("%d is invalid Postion 2 value\npos2 must be positive integer less than %d\n", pos2, linesTB(tb));
    } else if (pos1 < 0 || pos1 > pos2) {
        printf("%d is invalid Postion 1 value\npos1 must be positive integer less than %d\n", pos1, pos2);
    } else{
        Line l1 = getLine(tb, pos1);
        Line l2 = getLine(tb, pos2);
        Line pre1 = l1 -> prev;
        Line nex1 = l1 -> next;
        Line pre2 = l2 -> prev;
        Line nex2 = l2 -> next;
        l2 -> prev = pre1;
        l2 -> next = nex1;
        l1 -> next = nex2;
        l1 -> prev = pre2;
        if (l1 -> prev != NULL)
            pre1 -> next = l2;
        else tb -> head = l2;
        if (l2 -> prev != NULL)
            pre2 -> next = l1;
        else tb -> head = l2;
        if (l1 -> next != NULL)
            nex1 -> prev = l2;
        else tb -> tail = l2;
        if (l2 -> next != NULL)
            nex2 -> prev = l1;
        else tb -> tail = l1;
    }
}
/* Merge 'tb2' into 'tb1' at line 'pos'.
 *
 * - Afterwards line 0 of 'tb2' will be line 'pos' of 'tb1'.
 * - The old line 'pos' of 'tb1' will follow after the last line of 'tb2'.
 * - After this operation 'tb2' can not be used anymore (as if we had used
 *   releaseTB() on it).
 * - The program is to abort() with an error message if 'pos' is out of range.
 */
void mergeTB (TB tb1, int pos, TB tb2){
    pasteTB(tb1, pos, tb2);
    releaseTB(tb2);
}
/* Paste 'tb2' into 'tb1' at line 'pos'.
 *
 * - Afterwards line 0 of 'tb2' will be line 'pos' of 'tb1'.
 * - The old line 'pos' of 'tb1' will follow after the last line of 'tb2'.
 * - After this operation 'tb2' is unmodified and remains usable independent
 *   of 'tb1'.
 * - The program is to abort() with an error message if 'pos' is out of range.
 */
void pasteTB (TB tb1, int pos, TB tb2) {
    assert(tb1 != NULL && tb2 != NULL);
    if(pos < linesTB(tb1) && pos >= 0) {
        Line l = getLine(tb1, pos);
        if (l -> prev != NULL) {
            l -> prev -> next = tb2 -> head;
            tb2 -> head -> prev = l -> prev;
        } else {
            tb1 -> head = tb2 -> head;
        }
        l -> prev = tb2 -> tail;
        tb2 -> tail -> next = l;
    } else {
        printf("Invalid %d position in text buffer1", pos);
        abort();
    }
}

/* Cut the lines between and including 'from' and 'to' out of the textbuffer
 * 'tb'.
 *
 * - The result is a new textbuffer (much as one created with newTB()).
 * - The cut lines will be deleted from 'tb'.
 * - The program is to abort() with an error message if 'from' or 'to' is out
 *   of range.
 */
TB cutTB (TB tb, int from, int to) {
    assert(tb != NULL);
    TB res = NULL;
    int total = linesTB(tb);
    if (from >= 0 && from <= to && to < total) {
        res = newTB("");
        char * f = res -> head -> s;
        free(f);
        Line lF = getLine(tb, from);
        res -> head = lF;
        Line lT = lF;
        if (from != to) {
            getLine(tb, to);
        }
        res -> tail = lT;
        if (lF -> prev != NULL)
            lF -> prev -> next = lT -> next;
        else tb -> head = lT -> next;
        if (lT -> next != NULL)
            lT -> next -> prev = lF -> prev;
        else tb -> tail = lF -> prev;
    } else if (to >= total || from >= total) {
        printf("From:%d or to:%d is out of tb range %d\n", from, to, total);
        abort();
    } else if(from < 0 || to < 0) {
        printf("From:%d or To:%d is less than 0\n", from, to);
        abort();
    }
    return res;
}

/* Copy the lines between and including 'from' and 'to' of the textbuffer
 * 'tb'.
 *
 * - The result is a new textbuffer (much as one created with newTB()).
 * - The textbuffer 'tb' will remain unmodified.
 * - The program is to abort() with an error message if 'from' or 'to' is out
 *   of range.
 */
TB copyTB (TB tb, int from, int to) {
    TB res = cutTB(tb, from, to);
    pasteTB(tb, from, res);
    return res;
}


/* Remove the lines between and including 'from' and 'to' from the textbuffer
 * 'tb'.
 *
 * - The program is to abort() with an error message if 'from' or 'to' is out
 *   of range.
 */
void deleteTB (TB tb, int from, int to) {
    TB res = cutTB(tb, from, to);
    releaseTB(res);
}



/* Search every line of tb for each occurrence of str1 and replaces them
 * with str2
 */
void replaceText (TB tb, char* str1, char* str2) {
    char * occur = NULL;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int diff = len2 - len1;
    char * s = tb -> head -> s;
    while (occur = strstr(s, str1) != NULL) {
        s = realloc(s, sizeof(strlen(s) + diff));
        char * tem = strdup(occur + len1);
        strcpy(occur, str2);
        strcpy(occur + str2, tem);
        free(tem);
    }
}
/* Bonus Challenges
*/

char* diffTB (TB tb1, TB tb2) ;

void undoTB (TB tb) ;

void redoTB (TB tb) ;

