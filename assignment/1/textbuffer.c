#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "textBuffer.h"
#define HIST_SIZE 10

typedef struct textLine * Line;

struct textbuffer{
    Line head;
    Line tail;
    int size;
    char * history[HIST_SIZE];// free history in release TB
    int hist_top;
    int hist_cur;
};

struct textLine{
    char * s;
    Line prev;
    Line next;
};

static void checkTB(TB tb){
    assert(tb != NULL);
    if (tb -> head == NULL) {
        assert(tb -> tail == NULL);
        assert(tb -> size == 0);
        return;
    }
    assert(tb -> head -> prev == NULL);
    assert(tb -> tail -> next == NULL);
    Line cur = tb -> head;
    int size = 1;
    while (cur -> next != NULL) {
        assert(cur -> next -> prev == cur);
        cur = cur -> next;
        size ++;
    }
    assert(tb -> tail == cur);
    assert(tb -> size == size);
}

static void snapshot(TB tb) {
    //check if it needs to shift (top is equal to 10)
    assert(tb != NULL);
    int i;

    if (tb -> hist_top == HIST_SIZE) {
        free(tb -> history[0]);
        for (i = 0; i < (HIST_SIZE - 1); i++) {
            tb -> history[i] = tb -> history[i + 1];
        }
        tb -> hist_cur--;
    }
    //advance cur to next slot
    tb -> hist_cur ++;
    //before I dump check if there is occupied before if so free it;
    if (tb -> history[tb -> hist_cur] != NULL)
        free(tb -> history[tb -> hist_cur]);
    //dump current tb into cur slot of the array history
    tb -> history[tb -> hist_cur] = dumpTB(tb);
    //set top to that current + 1;
    tb -> hist_top = (tb -> hist_cur + 1);

}
static void restoreFromSnapshot(TB tb, char * s){
    //don't amend history
    TB temp = newTB(s);
    int size = tb -> size;
    //free all the lines
    Line lH = tb -> head;
    Line lT = tb -> tail;
    //set head tail and size according to the string
    tb -> head = temp -> head;
    tb -> tail = temp -> tail;
    tb -> size = temp -> size;
    temp -> head = lH;
    temp -> tail = lT;
    temp -> size = size;
    releaseTB(temp);
    checkTB(tb);
}

static Line newTextLine(char s[]) {
    Line new = calloc(sizeof(struct textLine), 1);
    assert(new != NULL);
    new ->  s = s;
    new ->  prev = NULL;
    new ->  next = NULL;
    return new;
}

static void destroyLine(Line l) {
    if (l != NULL && l ->  s != NULL) {
        free(l -> s);
    }
    free(l);
}
static Line getLine(TB tb, int pos) {
    Line l = NULL;
    if (tb != NULL && pos < linesTB(tb) && pos >= 0) {
        l = tb ->  head;
        int i = 0;
        while (l -> next != NULL && i < pos) {
            l = l -> next;
            i ++ ;
        }
    }
    return l;
}
static char ** splitLines(char * s, int * l) {
    int i;
    int c = 0;
    char ** lines = NULL;
    int len = strlen(s);
    int lastI  = -1;
    for (i = 0; i < len; i ++ )
        if (s[i] == '\n')
            c ++ ;
    lines = calloc(c * sizeof(char *), 1);
    *l = c;
    c = 0;
    for (i = 0; i < len; i ++ ) {
        if (s[i] == '\n') {
            lines[c] = strndup(s + lastI + 1, i - lastI);
            lastI = i;
            c ++ ;
        }
    }
    return lines;
}
static void appendTB(TB tb, Line l) {
    if (tb != NULL) {
        if (tb ->  head == NULL) {
            tb ->  head = l;
        } else {
            tb ->  tail ->  next = l;
            l ->  prev = tb ->  tail;
        }
        tb ->  tail = l;
        tb ->  size ++ ;
    } else {
        tb = newTB(l -> s);
    }
    checkTB(tb);
}
/* Allocate a new textbuffer whose contents is initialised with the text given
 * in the array.
 */
TB newTB(char text[]) {
    int i, l;
    char ** lines = NULL;
    TB new = NULL;
    Line newLine = NULL;
    if (text != NULL) {
        new = calloc(sizeof(struct textbuffer), 1);
        assert(new != NULL);
        lines = splitLines(text, &l);
        for (i = 0; i < l; i ++ ) {
            newLine = newTextLine(lines[i]);
            appendTB(new, newLine);
        }
    }
    free(lines);
    new -> hist_cur = -1;
    //snapshot(new);
    checkTB(new);
    return new;
}

/* Free the memory occupied by the given textbuffer.  It is an error to access
 * the buffer afterwards.
 */
void releaseTB(TB tb) {
    Line cur = NULL;
    Line tmp = NULL;
    int i;
    if (tb != NULL) {
        cur = tb ->  head;
        while (cur != NULL) {
            tmp = cur;
            cur = cur ->  next;
            destroyLine(tmp);
        }
        for (i = 0; i < HIST_SIZE; i++) {
            free(tb -> history[i]);
        }
    }
    free(tb);
}

/* Allocate and return an array containing the text in the given textbuffer.
*/
char *dumpTB(TB tb) {
    char * res = NULL;
    if (tb != NULL) {
        res = calloc(sizeof(char), 1);
        Line cur = tb ->  head;
        while (cur != NULL) {
            res = realloc(res,(strlen(res) + strlen(cur ->  s) + 1));
            strcat(res, cur ->  s);
            cur = cur ->  next;
        }
    }
    return res;
}

/* Return the number of lines of the given textbuffer.
*/
int linesTB(TB tb) {
    int res = 0;
    if (tb != NULL) {
        res = tb ->  size;
    }
    return res;
}

/* Swap the two given lines in the textbuffer.
 *
 * - The program is to abort() with an error message if line 'pos1' or line
 *   'pos2' is out of range.  The first line of a textbuffer is at position 0.
 */
void swapTB(TB tb, int pos1, int pos2) {
    assert(tb != NULL);
    int total = linesTB(tb);
    int diff = pos1 - pos2;
    if ((pos2 < total && pos2 >= 0) ||(pos1 < total && pos1 >= 0)) {
        // [ ..., a, b, ... ]
        // [ ..., a, ..., b, ... ]
        // [ a, ... ] and [ ..., b ]

        if (pos1 > pos2) {
            int temp = pos1;
            pos1 = pos2;
            pos2 = temp;
        }
        Line l1 = getLine(tb, pos1);
        Line l2 = getLine(tb, pos2);
        Line prev1 = l1 ->  prev;
        Line next1 = l1 ->  next;
        l1 ->  prev = l2 ->  prev;
        l1 ->  next = l2 ->  next;
        l2 ->  prev = prev1;
        l2 ->  next = next1;
        if (diff == 1 || diff == -1) {
            l1 ->  prev = l2;
            l2 ->  next = l1;
        }
        if (l1 ->  prev != NULL)
            l1 ->  prev -> next = l1;
        else tb ->  head = l1;
        if (l1 ->  next != NULL)
            l1 ->  next ->  prev = l1;
        else tb ->  tail = l1;
        if (l2 -> prev != NULL)
            l2 -> prev -> next = l2;
        else tb ->  head = l2;
        if (l2 -> next != NULL)
            l2 -> next ->  prev = l2;
        else tb ->  tail = l2;
        // char * temp = l1 -> s;
        // l1 -> s = l2 -> s;
        // l2 -> s = temp;
    } else if (pos1 < 0 || pos2 < 0)
        printf("Invalid pos must be greater than 0.\n");
    else printf("Invalid pos must be less than %d\n", linesTB(tb));
    checkTB(tb);
    snapshot(tb);
}
/* Merge 'tb2' into 'tb1' at line 'pos'.
 *
 * - Afterwards line 0 of 'tb2' will be line 'pos' of 'tb1'.
 * - The old line 'pos' of 'tb1' will follow after the last line of 'tb2'.
 * - After this operation 'tb2' can not be used anymore(as if we had used
 *   releaseTB() on it).
 * - The program is to abort() with an error message if 'pos' is out of range.
 */
void mergeTB(TB tb1, int pos, TB tb2) {
    assert(tb1 != NULL && tb2 != NULL);
    if (pos < linesTB(tb1) && pos >= 0) {
        Line l = getLine(tb1, pos);
        if (l ->  prev != NULL) {
            l ->  prev ->  next = tb2 ->  head;
            tb2 ->  head ->  prev = l ->  prev;
        } else {
            tb1 ->  head = tb2 ->  head;
        }
        l ->  prev = tb2 ->  tail;
        tb2 -> tail -> next = l;
        tb1 -> size += tb2 -> size;
    } else {
        printf("Invalid %d position in text buffer1", pos);
        abort();
    }
    checkTB(tb1);
    free(tb2);
    //    snapshot(tb1);
}
/* Paste 'tb2' into 'tb1' at line 'pos'.
 *
 * - Afterwards line 0 of 'tb2' will be line 'pos' of 'tb1'.
 * - The old line 'pos' of 'tb1' will follow after the last line of 'tb2'.
 * - After this operation 'tb2' is unmodified and remains usable independent
 *   of 'tb1'.
 * - The program is to abort() with an error message if 'pos' is out of range.
 */
void pasteTB(TB tb1, int pos, TB tb2) {
    char *s = dumpTB(tb2);
    TB merge = newTB(s);
    free(s);
    mergeTB(tb1, pos, merge);
    checkTB(tb1);
    checkTB(tb2);
}

/* Cut the lines between and including 'from' and 'to' out of the textbuffer
 * 'tb'.
 *
 * - The result is a new textbuffer(much as one created with newTB()).
 * - The cut lines will be deleted from 'tb'.
 * - The program is to abort() with an error message if 'from' or 'to' is out
 *   of range.
 */
TB cutTB(TB tb, int from, int to) {
    assert(tb != NULL);
    TB res = NULL;
    int total = linesTB(tb);
    if (from >= 0 && from <= to && to < total) {
        res = calloc(sizeof(struct textbuffer), 1);
        Line lF = getLine(tb, from);
        Line lT = lF;
        if (from != to) {
            lT = getLine(tb, to);
        }
        if (lF ->  prev != NULL)
            lF ->  prev ->  next = lT ->  next;
        else tb ->  head = lT ->  next;
        if (lT ->  next != NULL)
            lT ->  next ->  prev = lF ->  prev;
        else tb ->  tail = lF ->  prev;
        lF ->  prev = NULL;
        lT ->  next = NULL;
        res -> head = lF;
        res -> tail = lT;
        res -> size = to - from + 1;
        tb ->  size -= linesTB(res);
        res -> hist_cur = -1;
        snapshot(res);
    } else if (to >= total || from >= total) {
        printf("From:%d or to:%d is out of tb range %d\n", from, to, total);
        abort();
    } else if (from < 0 || to < 0) {
        printf("From:%d or To:%d is less than 0\n", from, to);
        abort();
    }
    checkTB(tb);
    checkTB(res);
    snapshot(tb);
    return res;
}

/* Copy the lines between and including 'from' and 'to' of the textbuffer
 * 'tb'.
 *
 * - The result is a new textbuffer(much as one created with newTB()).
 * - The textbuffer 'tb' will remain unmodified.
 * - The program is to abort() with an error message if 'from' or 'to' is out
 *   of range.
 */
TB copyTB(TB tb, int from, int to) {
    TB res = cutTB(tb, from, to);
    pasteTB(tb, from, res);
    checkTB(tb);
    checkTB(res);
    return res;
}


/* Remove the lines between and including 'from' and 'to' from the textbuffer
 * 'tb'.
 *
 * - The program is to abort() with an error message if 'from' or 'to' is out
 *   of range.
 */
void deleteTB(TB tb, int from, int to) {
    TB res = cutTB(tb, from, to);
    releaseTB(res);
    checkTB(tb);
}



/* Search every line of tb for each occurrence of str1 and replaces them
 * with str2
 */
void replaceText(TB tb, char* str1, char* str2) {
    char * occur = NULL;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int diff = len2 - len1 + 1;
    char * s = tb ->  head -> s;

    while ((occur = strstr(s, str1)) != NULL) {
        s = realloc(s, (strlen(s) + diff));
        char * tem = strdup(occur + len1);
        
        strcpy((occur + len2), tem);
        free(tem);
    }
    checkTB(tb);
}
/* Bonus Challenges
*/

char* diffTB(TB tb1, TB tb2) ;

void undoTB(TB tb) {
    //cur == 0 , nothing to undo
    if (tb -> hist_cur == 0) {
        return ;
    }
    //move current to left
    tb -> hist_cur --;
    char * s  = tb -> history[tb -> hist_cur];
    //restore snapshot
    restoreFromSnapshot(tb,s);
    checkTB(tb);
}

void redoTB(TB tb) {
    //curr + 1 = top do nothing
    if(tb -> hist_cur + 1 == tb -> hist_cur)
        return ;
    else{
        //otherwise we move cur to the right
        tb -> hist_cur ++;
        char * s  = tb -> history[tb -> hist_cur];
        //restore from that snapshot
        restoreFromSnapshot(tb,s);
        //checkTB
        checkTB(tb);
    }
}

