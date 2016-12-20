/*
 * testTextBuffer.c
 * Description:
 *
 * Tutorial class: F13A
 * Tutor name:
 * Author: Fiona Lin(Z5131048)
 * Date:19 Dec 2016
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "textBuffer.h"

void testCreateReleaseDumpLinesTB();
void testReleaseTB();
void testDumpTB();
void testLinesTB();
void testSwapTB();
void testMergeTB();
void testPasteTB();
void testCutTB();
void testCopyTB();
void testDeleteTB();
void testReplaceText();
void testDiffTB();
void testUndoNRedoTB();

int main(int argc,  char* argv []) {
//    testCreateReleaseDumpLinesTB();
//    testSwapTB();
//    testMergeTB();
//    testPasteTB();
//    testCutTB();
//    testCopyTB();
//    testDeleteTB();
//    testReplaceText();
//    // testDiffTB();
    testUndoNRedoTB();
    return EXIT_SUCCESS;
}

void testCreateReleaseDumpLinesTB() {
    printf("\n#1\tTest Create Release Dump Lines Text Buffer\n");
    int i;
    printf("\n#1.1 test create an ordinary text buffer\n");
    char *str1 = "this is\nsome text\n";
    printf("Original Tb:\n%s\n", str1);
    TB new = newTB(str1);
    printf("Created Tb \n");
    assert(new != NULL);
    printf("\n#1.2 test get number of lines of an ordinary text buffer\n");
    printf("Dumped Tb containing %d lines...\n",  linesTB(new));
    assert(linesTB(new) == 2);
    printf("\n#1.3 test dump an ordinary text buffer\n");
    char *str2 = dumpTB(new);
    printf("%s\n",  str2);
    assert(strcmp(str1, str2) == 0);
    printf("\n##Passed!##\n");
    free(str2);
    releaseTB(new);
    printf("Released Tb \n");

    printf("\n#2.1 test create an empty text buffer\n");
    str1 = "";
    printf("Original Tb:\n%s\n", str1);
    new = newTB(str1);
    printf("Created Tb \n");
    assert(new != NULL);
    printf("\n#2.2 test get number of lines of an empty text buffer\n");
    printf("Dumped Tb containing %d lines...\n",  linesTB(new));
    assert(linesTB(new) == 0);
    printf("\n#2.3 test dump an empty text buffer\n");
    str2 = dumpTB(new);
    printf("%s\n",  str2);
    assert(strcmp(str1, str2) == 0);
    printf("\n##Passed!##\n");
    free(str2);
    releaseTB (new);
    printf("Released Tb \n");

    printf("\n#3.1 create an text buffer has 1 line\n");
    str1 = "this is\n";
    printf("Original Tb:\n%s\n", str1);
    new = newTB(str1);
    printf("Created Tb \n");
    assert(new != NULL);
    printf("\n#3.2 test get number of lines of text buffer\n");
    printf("Dumped Tb containing %d lines...\n",  linesTB(new));
    assert(linesTB(new) == 1);
    printf("\n#3.3 test dump a 1 line text buffer\n");
    str2 = dumpTB(new);
    printf("%s\n",  str2);
    assert(strcmp(str1, str2) == 0);
    printf("\n##Passed!##\n");
    free(str2);
    releaseTB(new);
    printf("Released Tb \n");

    //create an text buffer has 50 lines
    printf("\n#4.1 test create an text buffer has 50 line\n");
    char str[] = "line 01\n" "line 02\n" "line 03\n" "line 04\n" "line 05\n" "line 06\n" "line 07\n" "line 08\n" "line 09\n" "line 10\n" "line 01\n" "line 02\n" "line 03\n" "line 04\n" "line 05\n" "line 06\n" "line 07\n" "line 08\n" "line 09\n" "line 10\n" "line 01\n" "line 02\n" "line 03\n" "line 04\n" "line 05\n" "line 06\n" "line 07\n" "line 08\n" "line 09\n" "line 10\n" "line 01\n" "line 02\n" "line 03\n" "line 04\n" "line 05\n" "line 06\n" "line 07\n" "line 08\n" "line 09\n" "line 10\n" "line 01\n" "line 02\n" "line 03\n" "line 04\n" "line 05\n" "line 06\n" "line 07\n" "line 08\n" "line 09\n" "line 10\n";
    printf("Original Tb:\n%s\n", str1);
    new = newTB(str);
    printf("Created Tb \n");
    assert(new != NULL);
    printf("\n#4.2 test get number of lines of an 50 lines text buffer\n");
    printf("Dumped Tb containing %d lines...\n",  linesTB(new));
    assert(linesTB(new) == 50);
    printf("\n#4.3 test dump an 50 lines text buffer\n");
    str2 = dumpTB(new);
    printf("Dumped Tb containing %d lines...\n",  linesTB(new));
    printf("%s\n",  str2);
    assert(strcmp(str, str2) == 0);
    printf("\n##Passed!##\n");
    free(str2);
    releaseTB(new);
    printf("Released Tb \n");


    printf("\n#5.1 create an text buffer has 100 thousand new lines\n");
    str1 = calloc(800000 * sizeof(str),  1);
    for (i = 0; strlen(str1) < 800000; i++) {
        strcat(str1,  str);
    }
    printf("Original Tb:\n%s\n", str1);
    new = newTB(str1);
    printf("Created Tb \n");
    assert(new != NULL);
    printf("\n#5.2 test get number of lines of text buffer\n");
    printf("Dumped Tb containing %d lines...\n",  linesTB(new));
    assert(linesTB(new) == 100000);
    printf("\n#5.3 test dump a 100 thousand lines text buffer\n");
    str2 = dumpTB(new);
    printf("%s\n",  str2);
    assert(strcmp(str1, str2) == 0);
    printf("\n##Passed!##\n");
    free(str1);
    free(str2);
    releaseTB(new);
    printf("Released Tb \n");

}

void testSwapTB() {
    printf("\n#2\tTest swap 2 lines in Text Buffer\n");
    TB tb1 = newTB("1.1 abc\n1.2 def\n");
    char* str = dumpTB(tb1);

    printf("\n#1.1 Pos1 is at the beginning of textbuffer\n\tPos2 is at the end of textbuffer\n");
    printf("Original Tb:\n%s\n", str);
    free(str);
    swapTB(tb1, 0, 1);
    str = dumpTB(tb1);
    printf("First and second lines are swapped...\n%s\n", str);
    assert(strcmp(str, "1.2 def\n1.1 abc\n") == 0);
    free(str);
    printf("\n##Passed!##\n");

    printf("\n#1.2 Pos1 is at the end of textbuffer\n\tPos2 is at the beginning of textbuffer\n");
    str = dumpTB(tb1);
    printf("Original Tb:\n%s\n", str);
    free(str);
    swapTB(tb1, 1, 0);
    str = dumpTB(tb1);
    printf("Swapped again...\n%s\n", str);
    assert(strcmp(str, "1.1 abc\n1.2 def\n") == 0);
    free(str);
    printf("\n##Passed!##\n");

    printf("\n#1.3 Pos1 and Pos2 are at the beginning of textbuffer\n");
    str = dumpTB(tb1);
    printf("Original Tb:\n%s\n", str);
    free(str);
    swapTB(tb1, 0, 0);
    str = dumpTB(tb1);
    printf("Swapped again...\n%s\n", str);
    assert(strcmp(str, "1.1 abc\n1.2 def\n") == 0);
    free(str);
    printf("\n##Passed!##\n");

    printf("\n#1.4 Pos1 and Pos2 are at the end of textbuffer\n");
    str = dumpTB(tb1);
    printf("Original Tb:\n%s\n", str);
    free(str);
    swapTB(tb1, 1, 1);
    str = dumpTB(tb1);
    printf("Swapped again...\n%s\n", str);
    assert(strcmp(str, "1.1 abc\n1.2 def\n") == 0);
    free(str);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    printf("Released Tb \n");


    printf("\n#1.5 Pos1 and Pos2 are in within the range of textbuffer\n");
    tb1 = newTB("1.1 abc\n1.2 def\n1.3 abc\n1.4 def\n");
    str = dumpTB(tb1);
    printf("Original Tb:\n%s\n", str);
    free(str);
    swapTB(tb1, 1, 2);
    str = dumpTB(tb1);
    printf("Swapped again...\n%s\n", str);
    assert(strcmp(str, "1.1 abc\n1.3 abc\n1.2 def\n1.4 def\n") == 0);
    free(str);
    printf("\n##Passed!##\n");



    // printf("\n#1.6 Pos1 is out of range of textbuffer\n");
    // swapTB(tb1, -1, 1);
    // printf("\n#1.7 Pos2 is out of range of textbuffer\n");
    // swapTB(tb1, 1, 21);
    // printf("\n#1.8 Pos1 and Pos2 is out of range of textbuffer\n");
    // swapTB(tb1, 21, -21);
    releaseTB (tb1);
    printf("Released Tb \n");
}

void testMergeTB() {
    printf("\n#3\tTest merge 2 Text Buffers\n");

    TB tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    TB tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    char * str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    free(str);

    printf("\n#1.1 Pos is 0,  which is the beginning of tb0\n");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    free(str);

    mergeTB(tb0, 0, tb1);
    str = dumpTB(tb0);
    char *str1 = "new stuff\nblah blah blah\nqwer\n1.1 abc\n1.2 def\nxxxxx\n";
    printf("Merged...\n%s\n", str);
    assert(strcmp(str,  str1) == 0);
    printf("\n##Passed!##\n");
    free(str);
    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.2 Pos is within the range of 0 to number of lines of tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    free(str);

    mergeTB(tb0,  1,  tb1);
    str = dumpTB(tb0);
    str1 = "1.1 abc\nnew stuff\nblah blah blah\nqwer\n1.2 def\nxxxxx\n";
    printf("Merged...\n%s\n", str);
    assert(strcmp(str,  str1) == 0);
    printf("\n##Passed!##\n");
    free(str);
    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.3 Pos is the end of tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    free(str);

    mergeTB(tb0,  2,  tb1);
    str = dumpTB(tb0);
    str1 = "1.1 abc\n1.2 def\nnew stuff\nblah blah blah\nqwer\nxxxxx\n";
    printf("Merged...\n%s\n", str);
    assert(strcmp(str,  str1) == 0);
    printf("\n##Passed!##\n");
    free(str);
    releaseTB (tb0);
    printf("Released Tb \n");


    printf("\n#1.4 Pos is equal to the number of lines of tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    free(str);

    mergeTB(tb0,  3,  tb1);
    str = dumpTB(tb0);
    str1 = "1.1 abc\n1.2 def\nxxxxx\nnew stuff\nblah blah blah\nqwer\n";
    printf("Merged...\n%s\n", str);
    assert(strcmp(str,  str1) == 0);
    printf("\n##Passed!##\n");
    free(str);
    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.5 Merge a empty text buffer at pos within tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    str1 = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str1);
    free(str1);

    mergeTB(tb0,  2,  tb1);
    str1 = dumpTB(tb0);
    printf("Merged...\n%s\n", str1);
    assert(strcmp(str,  str1) == 0);
    printf("\n##Passed!##\n");
    free(str);
    free(str1);
    releaseTB (tb0);
    releaseTB (tb1);
    printf("Released Tb \n");

    printf("\n#1.6 Merge tb0 itself at pos within tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);

    mergeTB(tb0,  2,  tb0);
    str1 = dumpTB(tb0);
    printf("Merged...\n%s\n", str1);
    assert(strcmp(str,  str1) == 0);
    printf("\n##Passed!##\n");
    free(str);
    free(str1);
    releaseTB (tb0);
    printf("Released Tb \n");


    printf("\n#1.7 test all invalid pos for merge text buffer\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    free(str);

    //   printf("\nPos is less than 0\n");
    //   mergeTB(tb0,  -1,  tb1);

    //   printf("\nPos is great than the number of lines of tb0\n");
    //   mergeTB(tb0,  linesTB(tb0)+1,  tb1);
    //
    //   printf("\nMerge 2 NULL text buffers\n");
    //   mergeTB(NULL,  1,  NULL);
    //
    //   printf("\nMerge to NULL text buffer\n");
    //   mergeTB(NULL,  1,  tb0);

    releaseTB (tb0);
    releaseTB (tb1);
    printf("Released Tb \n");

}

void testPasteTB() {
    printf("\n#4\tTest paste 2 Text Buffers\n");

    TB tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    TB tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    char * str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    free(str);
    char * str0 = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str0);

    printf("\n#1.1 Pos is 0,  which is the beginning of tb0\n");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    free(str);

    pasteTB(tb0, 0, tb1);
    str = dumpTB(tb0);
    char *str1 = "new stuff\nblah blah blah\nqwer\n1.1 abc\n1.2 def\nxxxxx\n";
    printf("Pasted...\n%s\n", str);
    assert(strcmp(str,  str1) == 0);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    assert(strcmp(str,  str0) == 0);
    free(str);
    printf("\n##Passed!##\n");
    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.2 Pos is within the range of 0 to number of lines of tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    free(str);

    pasteTB(tb0,  1,  tb1);
    str = dumpTB(tb0);
    str1 = "1.1 abc\nnew stuff\nblah blah blah\nqwer\n1.2 def\nxxxxx\n";
    printf("Pasted...\n%s\n", str);
    assert(strcmp(str,  str1) == 0);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    assert(strcmp(str,  str0) == 0);
    free(str);
    printf("\n##Passed!##\n");
    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.3 Pos is the end of tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    free(str);

    pasteTB(tb0,  2,  tb1);
    str = dumpTB(tb0);
    str1 = "1.1 abc\n1.2 def\nnew stuff\nblah blah blah\nqwer\nxxxxx\n";
    printf("Pasted...\n%s\n", str);
    assert(strcmp(str,  str1) == 0);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    assert(strcmp(str,  str0) == 0);
    free(str);
    printf("\n##Passed!##\n");
    releaseTB (tb0);
    printf("Released Tb \n");


    printf("\n#1.4 Pos is equal to the number of lines of tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    free(str);

    pasteTB(tb0,  3,  tb1);
    str = dumpTB(tb0);
    str1 = "1.1 abc\n1.2 def\nxxxxx\nnew stuff\nblah blah blah\nqwer\n";
    printf("Pasted...\n%s\n", str);
    assert(strcmp(str,  str1) == 0);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    assert(strcmp(str,  str0) == 0);
    free(str);
    printf("\n##Passed!##\n");
    releaseTB (tb0);
    releaseTB (tb1);
    printf("Released Tb \n");

    printf("\n#1.5 Paste a empty text buffer at pos within tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    char *str2 = dumpTB(tb1);

    pasteTB(tb0,  2,  tb1);
    str1 = dumpTB(tb0);
    printf("Pasted...\n%s\n", str1);
    assert(strcmp(str1,  str) == 0);
    free(str1);
    str1 = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    assert(strcmp(str1,  str2) == 0);
    free(str);
    printf("\n##Passed!##\n");
    free(str1);
    free(str2);
    releaseTB (tb0);
    releaseTB (tb1);
    printf("Released Tb \n");

    printf("\n#1.6 Paste tb0 itself at pos within tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);

    pasteTB(tb0,  2,  tb0);
    str1 = dumpTB(tb0);
    printf("Pasted...\n%s\n", str1);
    assert(strcmp(str,  str1) == 0);
    free(str);
    printf("\n##Passed!##\n");
    free(str1);
    releaseTB (tb0);
    printf("Released Tb \n");


    printf("\n#1.7 test all invalid pos for paste text buffer\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0);
    printf("Original Tb0:\n%s\n", str);
    free(str);
    str = dumpTB(tb1);
    printf("Original Tb1:\n%s\n", str);
    free(str);

    //   printf("\nPos is less than 0\n");
    //   pasteTB(tb0,  -1,  tb1);

    //   printf("\nPos is great than the number of lines of tb0\n");
    //   pasteTB(tb0,  linesTB(tb0)+1,  tb1);
    //
    //   printf("\nPaste 2 NULL text buffers\n");
    //   pasteTB(NULL,  1,  NULL);
    //
    //   printf("\nPaste to NULL text buffer\n");
    //   pasteTB(NULL,  1,  tb0);

    free(str0);
    releaseTB (tb0);
    releaseTB (tb1);
    printf("Released Tb \n");
}

void testCutTB() {
    printf("\n#5\tTest cut from Text Buffers\n");
    char str[] = "line 01\n"
        "line 02\n"
        "line 03\n"
        "line 04\n"
        "line 05\n"
        "line 06\n"
        "line 07\n"
        "line 08\n"
        "line 09\n"
        "line 10\n";
    TB tb1 = newTB(str);
    TB tb2;
    char *s;
    char *c;
    int from,  to,  diff;


    printf("\n#1.1 test cut from and to,  which are at the beginning of text buffer\n");
    from = 0;
    to = 0;
    tb2 = cutTB(tb1,  from,  to);
    s = dumpTB(tb1);
    c = dumpTB(tb2);
    diff = to - from + 1;
    assert(strcmp(s, str + diff *8) == 0);
    assert(strcmp(c, "line 01\n") == 0);
    assert(linesTB(tb2) == diff);
    printf ("tb2 = cutTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    free(c);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    releaseTB (tb2);
    printf("Released Tb \n");

    printf("\n#1.2 test cut from the beginning of text buffer\n");
    tb1 = newTB(str);
    from = 0;
    to = 2;
    tb2 = cutTB(tb1,  from,  to);
    s = dumpTB(tb1);
    c = dumpTB(tb2);
    diff = to - from + 1;
    assert(strcmp(s, str + diff *8) == 0);
    assert(strcmp(c, "line 01\nline 02\nline 03\n") == 0);
    assert(linesTB(tb2) == diff);
    printf ("tb2 = cutTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    free(c);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    releaseTB (tb2);
    printf("Released Tb \n");



    printf("\n#1.3 test cut from and to are within the range of 0 to number of lines of text buffer tb1\n");
    tb1 = newTB(str);
    from = 1;
    to = 5;
    tb2 = cutTB(tb1,  from,  to);
    s = dumpTB(tb1);
    c = dumpTB(tb2);
    diff = to - from + 1;
    assert(strcmp(s, "line 01\nline 07\nline 08\nline 09\nline 10\n") == 0);
    assert(strcmp(c, "line 02\nline 03\nline 04\nline 05\nline 06\n") == 0);
    assert((linesTB(tb2) - diff ) == 0);
    printf ("tb2 = cutTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    free(c);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    releaseTB (tb2);


    printf("\n#1.4 test cut from is at the end of textbuffer,  from and to are at the end of textbuffer \n");
    tb1 = newTB(str);
    char str1[] = "line 01\n"
        "line 02\n"
        "line 03\n"
        "line 04\n"
        "line 05\n"
        "line 06\n"
        "line 07\n"
        "line 08\n"
        "line 09\n";
    to = linesTB(tb1) - 1;
    from = to;
    tb2 = cutTB(tb1,  from,  to);
    s = dumpTB(tb1);
    c = dumpTB(tb2);
    diff = to - from + 1;
    assert(strcmp(s, str1) == 0);
    assert(strcmp(c, "line 10\n") == 0);
    assert((linesTB(tb2) - diff ) == 0);
    printf ("tb2 = cutTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    free(c);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    releaseTB (tb2);

    printf("\n#1.5 test cut to the end of textbuffe\n");
    tb1 = newTB(str);
    char str2 [] = "line 01\n"
        "line 02\n"
        "line 03\n"
        "line 04\n"
        "line 05\n";
    to = linesTB(tb1) - 1;
    from = 5;
    tb2 = cutTB(tb1,  from,  to);
    s = dumpTB(tb1);
    c = dumpTB(tb2);
    diff = to - from + 1;
    assert(strcmp(s, str2) == 0);
    assert(strcmp(c, str+diff*8) == 0);
    assert((linesTB(tb2) - diff ) == 0);
    printf ("tb2 = cutTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    free(c);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    releaseTB (tb2);

    printf("\n#1.7 test cut from greater than to\n");
    tb1 = newTB(str);
    from = linesTB(tb1) - 1;
    to = 5;
    tb2 = copyTB(tb1,  from,  to);
    s = dumpTB(tb1);
    assert(tb2 == NULL);
    assert(strcmp(s, str) == 0);
    free(s);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    releaseTB (tb2);


    printf("\n#1.7 test all invalid pos for  text buffer\n");
    //tb1 = newTB(str);

    //    printf("\n** From is less than 0,  from and to are less than 0 **\n");
    //    from = -5;
    //    to = - 1;
    //    tb2 = cutTB(tb1,  from,  to);
    //
    //    printf("\n** To is less than 0 **\n");
    //    from = 5;
    //    to = - 1;
    //    tb2 = cutTB(tb1,  from,  to);
    //
    //
    //    // from and to are great than and equal to number of lines of tb1
    //    printf("\n** From is great than and equal to number of lines of tb1 **\n");
    //    from = linesTB(tb1);
    //    to = from + 1;
    //    tb2 = cutTB(tb1,  from,  to);
    //
    //    printf("\n** To is great than and equal to number of lines of tb1 **\n");
    //    to = linesTB(tb1);
    //    from = to - 4;
    //    tb2 = cutTB(tb1,  from,  to);

    //releaseTB (tb1);
    //releaseTB (tb2);

}

void testCopyTB() {
    printf("\n#6\tTest copy from Text Buffers\n");
    char str[] = "line 01\n"
        "line 02\n"
        "line 03\n"
        "line 04\n"
        "line 05\n"
        "line 06\n"
        "line 07\n"
        "line 08\n"
        "line 09\n"
        "line 10\n";
    TB tb1 = newTB(str);
    TB tb2;
    char *s;
    char *c;
    int from,  to,  diff;


    printf("\n#1.1 test copy from and to,  which are at the beginning of text buffer\n");
    from = 0;
    to = 0;
    tb2 = copyTB(tb1,  from,  to);
    s = dumpTB(tb1);
    c = dumpTB(tb2);
    diff = to - from + 1;
    assert(strcmp(s, str) == 0);
    assert(strcmp(c, "line 01\n") == 0);
    assert(linesTB(tb2) == diff);
    printf ("tb2 = copyTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    free(c);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    releaseTB (tb2);
    printf("Released Tb \n");

    printf("\n#1.2 test copy from the beginning of text buffer\n");
    tb1 = newTB(str);
    from = 0;
    to = 2;
    tb2 = copyTB(tb1,  from,  to);
    s = dumpTB(tb1);
    c = dumpTB(tb2);
    diff = to - from + 1;
    assert(strcmp(s, str) == 0);
    assert(strcmp(c, "line 01\nline 02\nline 03\n") == 0);
    assert(linesTB(tb2) == diff);
    printf ("tb2 = copyTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    free(c);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    releaseTB (tb2);
    printf("Released Tb \n");



    printf("\n#1.3 test copy from and to are within the range of 0 to number of lines of text buffer tb1\n");
    tb1 = newTB(str);
    from = 1;
    to = 5;
    tb2 = copyTB(tb1,  from,  to);
    s = dumpTB(tb1);
    c = dumpTB(tb2);
    diff = to - from + 1;
    assert(strcmp(s, str) == 0);
    assert(strcmp(c, "line 02\nline 03\nline 04\nline 05\nline 06\n") == 0);
    assert((linesTB(tb2) - diff ) == 0);
    printf ("tb2 = copyTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    free(c);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    releaseTB (tb2);


    printf("\n#1.4 test copy from is at the end of textbuffer,  from and to are at the end of textbuffer \n");
    tb1 = newTB(str);
    to = linesTB(tb1) - 1;
    from = to;
    tb2 = copyTB(tb1,  from,  to);
    s = dumpTB(tb1);
    c = dumpTB(tb2);
    diff = to - from + 1;
    assert(strcmp(s, str) == 0);
    assert(strcmp(c, "line 10\n") == 0);
    assert((linesTB(tb2) - diff ) == 0);
    printf ("tb2 = copyTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    free(c);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    releaseTB (tb2);

    printf("\n#1.5 test copy to the end of textbuffer\n");
    tb1 = newTB(str);
    to = linesTB(tb1) - 1;
    from = 5;
    tb2 = copyTB(tb1,  from,  to);
    s = dumpTB(tb1);
    c = dumpTB(tb2);
    diff = to - from + 1;
    assert(strcmp(s, str) == 0);
    assert(strcmp(c, str+diff*8) == 0);
    assert((linesTB(tb2) - diff ) == 0);
    printf ("tb2 = copyTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    releaseTB (tb2);

    printf("\n#1.6 test copy from greater than to\n");
    tb1 = newTB(str);
    from = linesTB(tb1) - 1;
    to = 5;
    tb2 = copyTB(tb1,  from,  to);
    s = dumpTB(tb1);
    assert(tb2 == NULL);
    assert(strcmp(s, str) == 0);
    free(s);
    free(c);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    releaseTB (tb2);

    printf("\n#1.7 test all invalid pos for  text buffer\n");
    //tb1 = newTB(str);

    //    printf("\n** From is less than 0,  from and to are less than 0 **\n");
    //    from = -5;
    //    to = - 1;
    //    tb2 = copyTB(tb1,  from,  to);
    //
    //    printf("\n** To is less than 0 **\n");
    //    from = 5;
    //    to = - 1;
    //    tb2 = copyTB(tb1,  from,  to);
    //
    //
    //    // from and to are great than and equal to number of lines of tb1
    //    printf("\n** From is great than and equal to number of lines of tb1 **\n");
    //    from = linesTB(tb1);
    //    to = from + 1;
    //    tb2 = copyTB(tb1,  from,  to);
    //
    //    printf("\n** To is great than and equal to number of lines of tb1 **\n");
    //    to = linesTB(tb1);
    //    from = to - 4;
    //    tb2 = copyTB(tb1,  from,  to);

    // releaseTB (tb1);
    // releaseTB (tb2);

}


void testDeleteTB() {
    printf("\n#7\tTest delete from Text Buffers\n");
    char str[] = "line 01\n"
        "line 02\n"
        "line 03\n"
        "line 04\n"
        "line 05\n"
        "line 06\n"
        "line 07\n"
        "line 08\n"
        "line 09\n"
        "line 10\n";
    TB tb1 = newTB(str);
    char *s;
    int from,  to,  diff;


    printf("\n#1.1 test delete from and to,  which are at the beginning of text buffer\n");
    from = 0;
    to = 0;
    deleteTB(tb1,  from,  to);
    s = dumpTB(tb1);
    diff = to - from + 1;
    assert(strcmp(s, str + diff *8) == 0);
    assert(10 - linesTB(tb1) == diff);
    printf ("deleteTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    printf("Released Tb \n");

    printf("\n#1.2 test delete from the beginning of text buffer\n");
    tb1 = newTB(str);
    from = 0;
    to = 2;
    deleteTB(tb1,  from,  to);
    s = dumpTB(tb1);
    diff = to - from + 1;
    assert(strcmp(s, str + diff *8) == 0);
    assert(10 - linesTB(tb1) == diff);
    printf ("deleteTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    printf("Released Tb \n");



    printf("\n#1.3 test delete from and to are within the range of 0 to number of lines of text buffer tb1\n");
    tb1 = newTB(str);
    from = 1;
    to = 5;
    deleteTB(tb1,  from,  to);
    s = dumpTB(tb1);
    diff = to - from + 1;
    assert(strcmp(s, "line 01\nline 07\nline 08\nline 09\nline 10\n") == 0);
    assert(10 - linesTB(tb1) == diff);
    printf ("deleteTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    printf("Released Tb \n");


    printf("\n#1.4 test delete from is at the end of textbuffer,  from and to are at the end of textbuffer \n");
    tb1 = newTB(str);
    char str1[] = "line 01\n"
        "line 02\n"
        "line 03\n"
        "line 04\n"
        "line 05\n"
        "line 06\n"
        "line 07\n"
        "line 08\n"
        "line 09\n";
    to = linesTB(tb1) - 1;
    from = to;
    deleteTB(tb1,  from,  to);
    s = dumpTB(tb1);
    diff = to - from + 1;
    assert(strcmp(s, str1) == 0);
    assert(10 - linesTB(tb1) == diff);
    printf ("deleteTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    printf("\n##Passed!##\n");
    releaseTB (tb1);
    printf("Released Tb \n");

    printf("\n#1.5 test delete to the end of textbuffe\n");
    tb1 = newTB(str);
    char str2 [] = "line 01\n"
        "line 02\n"
        "line 03\n"
        "line 04\n"
        "line 05\n";
    to = linesTB(tb1) - 1;
    from = 5;
    deleteTB(tb1,  from,  to);
    s = dumpTB(tb1);
    diff = to - from + 1;
    assert(strcmp(s, str2) == 0);
    assert(10 - linesTB(tb1) == diff);
    printf ("deleteTB(tb1,  %d,  %d)\nno. of lines in tb1 = %d\ntb1 = \n%s\n",  from,  to,  linesTB(tb1),  s);
    free(s);
    printf("\n##Passed!##\n");
    releaseTB (tb1);
    printf("Released Tb \n");

    printf("\n#1.6 test delete from greater than to\n");
    tb1 = newTB(str);
    from = linesTB(tb1) - 1;
    to = 5;
    copyTB(tb1,  from,  to);
    s = dumpTB(tb1);
    assert(strcmp(s, str) == 0);
    assert(linesTB(tb1) == 10);
    free(s);
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    printf("Released Tb \n");


    printf("\n#1.7 test all invalid pos for  text buffer\n");
    //tb1 = newTB(str);

    //    printf("\n** From is less than 0,  from and to are less than 0 **\n");
    //    from = -5;
    //    to = - 1;
    //    deleteTB(tb1,  from,  to);
    //
    //    printf("\n** To is less than 0 **\n");
    //    from = 5;
    //    to = - 1;
    //    deleteTB(tb1,  from,  to);
    //
    //
    //    // from and to are great than and equal to number of lines of tb1
    //    printf("\n** From is great than and equal to number of lines of tb1 **\n");
    //    from = linesTB(tb1);
    //    to = from + 1;
    //    deleteTB(tb1,  from,  to);
    //
    //    printf("\n** To is great than and equal to number of lines of tb1 **\n");
    //    to = linesTB(tb1);
    //    from = to - 4;
    //    deleteTB(tb1,  from,  to);

    //releaseTB (tb1);
    //

}

void testReplaceText() {
    printf("\n#8\tTest replace text in Text Buffers\n");

    printf("\n#1.1 test string1 is not in text buffer\n");
    TB tb0 = newTB("1.1 abc\ndef\nghc\nklmnbc\n");
    char* str0 = dumpTB(tb0);
    printf("Original Tb:\n%s\n", str0);
    replaceText (tb0,  "hd",  "YY");
    char * str1 = dumpTB(tb0);
    assert(strcmp(str0, str1) == 0);
    printf("replaced  hd   with YY...\n%s\n", str1);
    free(str0);
    free(str1);
    printf("\n##Passed!##\n");

    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.2 test string1 is same length as string2\n");
    tb0 = newTB("1.1 abc\ndef\nghc\nklmnbc\n");
    str0 = dumpTB(tb0);
    printf("Original Tb:\n%s\n", str0);
    replaceText (tb0,  "bc",  "YY");
    str1 = dumpTB(tb0);
    assert(strcmp(str1, "1.1 aYY\ndef\nghc\nklmnYY\n") == 0);
    assert(strlen(str0) == strlen(str1));
    printf("replaced  bc   with YY...\n%s\n", str1);
    free(str0);
    free(str1);
    printf("\n##Passed!##\n");

    releaseTB (tb0);
    printf("Released Tb \n");


    printf("\n#1.3 test string1 is replaced with empty string2\n");
    tb0 = newTB("1.1 abc\ndef\nghc\nklmnbc\n");
    str0 = dumpTB(tb0);
    printf("Original Tb:\n%s\n", str0);
    replaceText (tb0,  "bc",  "");
    str1 = dumpTB(tb0);
    assert(strcmp(str1, "1.1 a\ndef\nghc\nklmn\n") == 0);
    assert(strlen(str0) > strlen(str1));
    printf("replaced  bc with empty string...\n%s\n", str1);
    free(str0);
    free(str1);
    printf("\n##Passed!##\n");

    releaseTB (tb0);
    printf("Released Tb \n");


    printf("\n#1.4 test string1 is replaced by a longer string2\n");
    tb0 = newTB("1.1 abc\ndef\nghc\nklmnbc\n");
    str0 = dumpTB(tb0);
    printf("Original Tb:\n%s\n", str0);
    replaceText (tb0,  "bc",  "Y");
    str1 = dumpTB(tb0);
    assert(strcmp(str1, "1.1 aY\ndef\nghc\nklmnY\n") == 0);
    assert(strlen(str1) < strlen(str0));
    printf("replaced  bc   with Y...\n%s\n", str1);
    free(str0);
    free(str1);
    printf("\n##Passed!##\n");

    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.5 test string1 is replaced by a shorter string2\n");
    tb0 = newTB("1.1 abc\ndef\nghc\nklmnbc\n");
    str0 = dumpTB(tb0);
    printf("Original Tb:\n%s\n", str0);
    replaceText (tb0,  "bc",  "YYY");
    str1 = dumpTB(tb0);
    assert(strcmp(str1, "1.1 aYYY\ndef\nghc\nklmnYYY\n") == 0);
    assert(strlen(str1) > strlen(str0));
    printf("replaced  bc   with YYY...\n%s\n", str1);
    free(str0);
    free(str1);
    printf("\n##Passed!##\n");

    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.6 test string1 is replaced by a double itself string\n");
    tb0 = newTB("1.1 abc\ndef\nghc\nklmnbc\n");
    str0 = dumpTB(tb0);
    printf("Original Tb:\n%s\n", str0);
    replaceText (tb0,  "bc",  "bcbc");
    str1 = dumpTB(tb0);
    assert(strcmp(str1, "1.1 abcbc\ndef\nghc\nklmnbcbc\n") == 0);
    assert(strlen(str1) > strlen(str0));
    printf("replaced  bc   with bcbc...\n%s\n", str1);
    free(str0);
    free(str1);
    printf("\n##Passed!##\n");

    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.7 test string1 is replaced by itself\n");
    tb0 = newTB("1.1 abc\ndef\nghc\nklmnbc\n");
    str0 = dumpTB(tb0);
    printf("Original Tb:\n%s\n", str0);
    replaceText (tb0,  "bc",  "bc");
    str1 = dumpTB(tb0);
    assert(strcmp(str1, str0) == 0);
    assert(strlen(str0) == strlen(str1));
    printf("replaced  bc   with bc...\n%s\n", str1);
    free(str0);
    free(str1);
    printf("\n##Passed!##\n");

    releaseTB (tb0);
    printf("Released Tb \n");
}

void testDiffTB() { }

void testUndoNRedoTB() {
    char str1[] = "1 line 01\n"
        "1 line 02\n"
        "1 line 03\n"
        "1 line 04\n"
        "1 line 05\n";

    char str2[] = "2 line 01\n"
        "2 line 02\n"
        "2 line 03\n"
        "2 line 04\n";


    char* b1;
    char* b2;
    char* a;

    TB tb1 = newTB(str1);
    TB tb2 = newTB(str2);

    // swap undo & redo
    printf("test 1 : swap undo & redo\n");
    swapTB(tb1, 0, 2);
    swapTB(tb1, 1, 3);
    b1 = dumpTB(tb1);
    swapTB(tb1, 2, 4);
    printf("%s", b1);

    printf("\nafter undo 3 times...\n");
    undoTB(tb1);
    undoTB(tb1);
    undoTB(tb1);
    a = dumpTB(tb1);
    assert(strcmp(a,  str1) == 0);
    printf("%s", a);
    free(a);
    printf("\n##Passed!##\n");

    printf("\nafter redo 2 times...\n");
    redoTB(tb1);
    redoTB(tb1);
    a = dumpTB(tb1);
    printf("%s", b1);
    assert(strcmp(a,  b1) == 0);
    free(a);
    free(b1);
    printf("\n##Passed!##\n");
    printf("\n\n");

    // delete
    releaseTB(tb1);
    tb1 = newTB(str1);
    printf("test 2 : delete undo & redo\n");
    deleteTB(tb1, 3, 4);
    b1 = dumpTB(tb1);
    deleteTB(tb1, 0, 1);
    b2 = dumpTB(tb1);
    printf("%s", b2);

    printf("\nafter undo 1 time...\n");
    undoTB(tb1);
    a = dumpTB(tb1);
    printf("%s",  a);
    assert(strcmp(a,  b1) == 0);
    free(a);
    printf("\n##Passed!##\n");
    printf("\n\n");

    printf("\nafter redo 1 time...\n");
    redoTB(tb1);
    a = dumpTB(tb1);
    printf("%s", a);
    assert(strcmp(a,  b2) == 0);
    free(a);
    free(b2);
    free(b1);
    printf("\n##Passed!##\n");
    printf("\n\n");



    // paste & merge undo
    releaseTB(tb1);
    tb1 = newTB(str1);
    printf("test 3 : paste / merge undo & redo\n");
    pasteTB(tb1, 3, tb2);
    b1 = dumpTB(tb1);
    printf("%s", b1) ;
    free(b1);

    printf("\nafter undo ...\n");
    undoTB(tb1);
    b2 = dumpTB(tb1);
    printf("%s",  b2);
    assert(strcmp(b2,  str1) == 0);
    printf("\n##Passed!##\n");
    printf("\n\n");

    printf("\nafter merge ...\n");
    mergeTB(tb1, linesTB(tb1), tb2);
    b1 = dumpTB(tb1);
    printf("%s", b1);

    printf("\nafter redo ...\n");
    redoTB(tb1);
    a = dumpTB(tb1);
    printf("%s", a);
    assert(strcmp(a,  b1) == 0);
    free(a);
    printf("\n##Passed!##\n");
    printf("\n\n");


    undoTB(tb1);
    printf("\nafter undo ...\n");
    a = dumpTB(tb1);
    assert(strcmp(a,  b2) == 0);
    printf("%s", a);
    free(a);
    free(b1);
    free(b2);
    printf("\n##Passed!##\n");
    printf("\n\n");


    // cut undo
    releaseTB(tb1);
    tb1 = newTB(str1);

    printf("test 5 : cut undo & redo\n");
    printf("%s", str1);

    TB res = cutTB(tb1, 3, 4);
    b1 = dumpTB(tb1);
    releaseTB(res);
    res = cutTB(tb1, 0, 1);
    releaseTB(res);
    printf("\nafter 2 cuts ...\n");
    b2 = dumpTB(tb1);
    printf("%s", b2);

    printf("\nafter undo 2 times...\n");
    undoTB(tb1);
    undoTB(tb1);
    a = dumpTB(tb1);
    assert(strcmp(a,  str1) == 0);
    printf("%s", a);
    free(a);

    printf("\nafter redo 1 time...\n");
    redoTB(tb1);
    a = dumpTB(tb1);
    assert(strcmp(a,  b1) == 0);
    printf("%s", a);
    free(a);
    free(b1);
    free(b2);
    printf("\n##Passed!##\n");
    printf("\n\n");

    releaseTB(tb1);
}

