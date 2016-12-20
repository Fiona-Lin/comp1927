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

void testCreateReleaseDumpLinesTB() ;
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
void testUndoTB();
void testRedoTB();

int main(int argc, char* argv []) {
    //testCreateReleaseDumpLinesTB();
    //testSwapTB();
    //testMergeTB();
    testPasteTB();
    //   testCutTB();
    //   testCopyTB();
    //   testDeleteTB();
    //   testReplaceText();
    //   // testDiffTB();
    //   testUndoTB();
    //   testRedoTB();
    return EXIT_SUCCESS;
}

void testCreateReleaseDumpLinesTB() {
    printf("\n#1\tTest Create Release Dump Lines Text Buffer\n");
    int i;
    printf("\n#1.1 test create an ordinary text buffer\n");
    char *str1 = "this is\nsome text\n";
    printf("Original Tb:\n%s\n",str1);
    TB new = newTB(str1);
    printf("Created Tb \n");
    assert(new != NULL);
    printf("\n#1.2 test get number of lines of an ordinary text buffer\n");
    printf("Dumped Tb containing %d lines...\n", linesTB(new));
    assert(linesTB(new) == 2);
    printf("\n#1.3 test dump an ordinary text buffer\n");
    char *str2 = dumpTB(new);
    printf("%s\n", str2);
    assert(strcmp(str1,str2) == 0);
    printf("\n##Passed!##\n");
    free(str2);
    releaseTB(new);
    printf("Released Tb \n");

    printf("\n#2.1 test create an empty text buffer\n");
    str1 = "";
    printf("Original Tb:\n%s\n",str1);
    new = newTB(str1);
    printf("Created Tb \n");
    assert(new != NULL);
    printf("\n#2.2 test get number of lines of an empty text buffer\n");
    printf("Dumped Tb containing %d lines...\n", linesTB(new));
    assert(linesTB(new) == 0);
    printf("\n#2.3 test dump an empty text buffer\n");
    str2 = dumpTB(new);
    printf("%s\n", str2);
    assert(strcmp(str1,str2) == 0);
    printf("\n##Passed!##\n");
    free(str2);
    releaseTB (new);
    printf("Released Tb \n");

    printf("\n#3.1 create an text buffer has 1 line\n");
    str1 = "this is\n";
    printf("Original Tb:\n%s\n",str1);
    new = newTB(str1);
    printf("Created Tb \n");
    assert(new != NULL);
    printf("\n#3.2 test get number of lines of text buffer\n");
    printf("Dumped Tb containing %d lines...\n", linesTB(new));
    assert(linesTB(new) == 1);
    printf("\n#3.3 test dump a 1 line text buffer\n");
    str2 = dumpTB(new);
    printf("%s\n", str2);
    assert(strcmp(str1,str2) == 0);
    printf("\n##Passed!##\n");
    free(str2);
    releaseTB(new);
    printf("Released Tb \n");

    //create an text buffer has 50 lines
    printf("\n#4.1 test create an text buffer has 50 line\n");
    char str[] = "line 01\n" "line 02\n" "line 03\n" "line 04\n" "line 05\n" "line 06\n" "line 07\n" "line 08\n" "line 09\n" "line 10\n" "line 01\n" "line 02\n" "line 03\n" "line 04\n" "line 05\n" "line 06\n" "line 07\n" "line 08\n" "line 09\n" "line 10\n" "line 01\n" "line 02\n" "line 03\n" "line 04\n" "line 05\n" "line 06\n" "line 07\n" "line 08\n" "line 09\n" "line 10\n" "line 01\n" "line 02\n" "line 03\n" "line 04\n" "line 05\n" "line 06\n" "line 07\n" "line 08\n" "line 09\n" "line 10\n" "line 01\n" "line 02\n" "line 03\n" "line 04\n" "line 05\n" "line 06\n" "line 07\n" "line 08\n" "line 09\n" "line 10\n";
    printf("Original Tb:\n%s\n",str1);
    new = newTB(str);
    printf("Created Tb \n");
    assert(new != NULL);
    printf("\n#4.2 test get number of lines of an 50 lines text buffer\n");
    printf("Dumped Tb containing %d lines...\n", linesTB(new));
    assert(linesTB(new) == 50);
    printf("\n#4.3 test dump an 50 lines text buffer\n");
    str2 = dumpTB(new);
    printf("Dumped Tb containing %d lines...\n", linesTB(new));
    printf("%s\n", str2);
    assert(strcmp(str,str2) == 0);
    printf("\n##Passed!##\n");
    free(str2);
    releaseTB(new);
    printf("Released Tb \n");


    printf("\n#5.1 create an text buffer has 100 thousand new lines\n");
    str1 = calloc(800000 * sizeof(str), 1);
    for (i = 0; strlen(str1) < 800000 ; i++) {
        strcat(str1, str);
    }
    printf("Original Tb:\n%s\n",str1);
    new = newTB(str1);
    printf("Created Tb \n");
    assert(new != NULL);
    printf("\n#5.2 test get number of lines of text buffer\n");
    printf("Dumped Tb containing %d lines...\n", linesTB(new));
    assert(linesTB(new) == 100000);
    printf("\n#5.3 test dump a 100 thousand lines text buffer\n");
    str2 = dumpTB(new);
    printf("%s\n", str2);
    assert(strcmp(str1,str2) == 0);
    printf("\n##Passed!##\n");
    free(str1);
    free(str2);
    releaseTB(new);
    printf("Released Tb \n");

}

void testSwapTB() {
    printf("\n#2\tTest swap 2 lines in Text Buffer\n");
    TB tb1 = newTB("1.1 abc\n1.2 def\n");
    char* str = dumpTB(tb1) ;

    printf("\n#1.1 Pos1 is at the beginning of textbuffer\n\tPos2 is at the end of textbuffer\n");
    printf("Original Tb:\n%s\n",str) ;
    free(str) ;
    swapTB(tb1,0,1) ;
    str = dumpTB(tb1) ;
    printf("First and second lines are swapped...\n%s\n",str) ;
    assert(strcmp(str,"1.2 def\n1.1 abc\n") == 0);
    free(str) ;
    printf("\n##Passed!##\n");

    printf("\n#1.2 Pos1 is at the end of textbuffer\n\tPos2 is at the beginning of textbuffer\n");
    str = dumpTB(tb1) ;
    printf("Original Tb:\n%s\n",str) ;
    free(str) ;
    swapTB(tb1,1,0) ;
    str = dumpTB(tb1) ;
    printf("Swapped again...\n%s\n",str) ;
    assert(strcmp(str,"1.1 abc\n1.2 def\n") == 0);
    free(str) ;
    printf("\n##Passed!##\n");

    printf("\n#1.3 Pos1 and Pos2 are at the beginning of textbuffer\n");
    str = dumpTB(tb1) ;
    printf("Original Tb:\n%s\n",str) ;
    free(str) ;
    swapTB(tb1,0,0) ;
    str = dumpTB(tb1) ;
    printf("Swapped again...\n%s\n",str) ;
    assert(strcmp(str,"1.1 abc\n1.2 def\n") == 0);
    free(str) ;
    printf("\n##Passed!##\n");

    printf("\n#1.4 Pos1 and Pos2 are at the end of textbuffer\n");
    str = dumpTB(tb1) ;
    printf("Original Tb:\n%s\n",str) ;
    free(str) ;
    swapTB(tb1,1,1) ;
    str = dumpTB(tb1) ;
    printf("Swapped again...\n%s\n",str) ;
    assert(strcmp(str,"1.1 abc\n1.2 def\n") == 0);
    free(str) ;
    printf("\n##Passed!##\n");

    releaseTB (tb1);
    printf("Released Tb \n");


    printf("\n#1.5 Pos1 and Pos2 are in within the range of textbuffer\n");
    tb1 = newTB("1.1 abc\n1.2 def\n1.3 abc\n1.4 def\n");
    str = dumpTB(tb1) ;
    printf("Original Tb:\n%s\n",str) ;
    free(str) ;
    swapTB(tb1,1,2) ;
    str = dumpTB(tb1) ;
    printf("Swapped again...\n%s\n",str) ;
    assert(strcmp(str,"1.1 abc\n1.3 abc\n1.2 def\n1.4 def\n") == 0);
    free(str) ;
    printf("\n##Passed!##\n");



    // printf("\n#1.6 Pos1 is out of range of textbuffer\n");
    // swapTB(tb1,-1,1) ;
    // printf("\n#1.7 Pos2 is out of range of textbuffer\n");
    // swapTB(tb1,1,21) ;
    // printf("\n#1.8 Pos1 and Pos2 is out of range of textbuffer\n");
    // swapTB(tb1,21,-21) ;
    releaseTB (tb1);
    printf("Released Tb \n");
}

void testMergeTB() {
    printf("\n#3\tTest merge 2 Text Buffers\n");

    TB tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    TB tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    char * str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    free(str) ;

    printf("\n#1.1 Pos is 0, which is the beginning of tb0\n");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    free(str) ;

    mergeTB(tb0,0,tb1);
    str = dumpTB(tb0) ;
    char *str1 = "new stuff\nblah blah blah\nqwer\n1.1 abc\n1.2 def\nxxxxx\n";
    printf("Merged...\n%s\n",str) ;
    assert(strcmp(str, str1) == 0);
    printf("\n##Passed!##\n");
    free(str) ;
    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.2 Pos is within the range of 0 to number of lines of tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    free(str) ;

    mergeTB(tb0, 1, tb1);
    str = dumpTB(tb0) ;
    str1 = "1.1 abc\nnew stuff\nblah blah blah\nqwer\n1.2 def\nxxxxx\n";
    printf("Merged...\n%s\n",str) ;
    assert(strcmp(str, str1) == 0);
    printf("\n##Passed!##\n");
    free(str);
    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.3 Pos is the end of tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    free(str) ;

    mergeTB(tb0, 2, tb1);
    str = dumpTB(tb0) ;
    str1 = "1.1 abc\n1.2 def\nnew stuff\nblah blah blah\nqwer\nxxxxx\n";
    printf("Merged...\n%s\n",str) ;
    assert(strcmp(str, str1) == 0);
    printf("\n##Passed!##\n");
    free(str);
    releaseTB (tb0);
    printf("Released Tb \n");


    printf("\n#1.4 Pos is equal to the number of lines of tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    free(str) ;

    mergeTB(tb0, 3, tb1);
    str = dumpTB(tb0) ;
    str1 = "1.1 abc\n1.2 def\nxxxxx\nnew stuff\nblah blah blah\nqwer\n";
    printf("Merged...\n%s\n",str) ;
    assert(strcmp(str, str1) == 0);
    printf("\n##Passed!##\n");
    free(str);
    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.5 Merge a empty text buffer at pos within tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    str1 = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str1) ;
    free(str1);

    mergeTB(tb0, 2, tb1);
    str1 = dumpTB(tb0) ;
    printf("Merged...\n%s\n",str1) ;
    assert(strcmp(str, str1) == 0);
    printf("\n##Passed!##\n");
    free(str);
    free(str1);
    releaseTB (tb0);
    releaseTB (tb1);
    printf("Released Tb \n");

    printf("\n#1.6 Merge tb0 itself at pos within tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;

    mergeTB(tb0, 2, tb0);
    str1 = dumpTB(tb0) ;
    printf("Merged...\n%s\n",str1) ;
    assert(strcmp(str, str1) == 0);
    printf("\n##Passed!##\n");
    free(str) ;
    free(str1);
    releaseTB (tb0);
    printf("Released Tb \n");


    printf("\n#1.7 test all invalid pos for merge text buffer\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    free(str) ;

    //   printf("\nPos is less than 0\n");
    //   mergeTB(tb0, -1, tb1);

    //   printf("\nPos is great than the number of lines of tb0\n");
    //   mergeTB(tb0, linesTB(tb0)+1, tb1);
    //
    //   printf("\nMerge 2 NULL text buffers\n");
    //   mergeTB(NULL, 1, NULL);
    //
    //   printf("\nMerge to NULL text buffer\n");
    //   mergeTB(NULL, 1, tb0);

    releaseTB (tb0);
    releaseTB (tb1);
    printf("Released Tb \n");

}

void testPasteTB() {
    printf("\n#4\tTest paste 2 Text Buffers\n");

    TB tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    TB tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    char * str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    free(str) ;
    char * str0 = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str0) ;

    printf("\n#1.1 Pos is 0, which is the beginning of tb0\n");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    free(str) ;

    pasteTB(tb0,0,tb1);
    str = dumpTB(tb0) ;
    char *str1 = "new stuff\nblah blah blah\nqwer\n1.1 abc\n1.2 def\nxxxxx\n";
    printf("Pasted...\n%s\n",str) ;
    assert(strcmp(str, str1) == 0);
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    assert(strcmp(str, str0) == 0);
    free(str) ;
    printf("\n##Passed!##\n");
    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.2 Pos is within the range of 0 to number of lines of tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    free(str) ;

    pasteTB(tb0, 1, tb1);
    str = dumpTB(tb0) ;
    str1 = "1.1 abc\nnew stuff\nblah blah blah\nqwer\n1.2 def\nxxxxx\n";
    printf("Pasted...\n%s\n",str) ;
    assert(strcmp(str, str1) == 0);
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    assert(strcmp(str, str0) == 0);
    free(str) ;
    printf("\n##Passed!##\n");
    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.3 Pos is the end of tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    free(str) ;

    pasteTB(tb0, 2, tb1);
    str = dumpTB(tb0) ;
    str1 = "1.1 abc\n1.2 def\nnew stuff\nblah blah blah\nqwer\nxxxxx\n";
    printf("Pasted...\n%s\n",str) ;
    assert(strcmp(str, str1) == 0);
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    assert(strcmp(str, str0) == 0);
    free(str) ;
    printf("\n##Passed!##\n");
    releaseTB (tb0);
    printf("Released Tb \n");


    printf("\n#1.4 Pos is equal to the number of lines of tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    free(str) ;

    pasteTB(tb0, 3, tb1);
    str = dumpTB(tb0) ;
    str1 = "1.1 abc\n1.2 def\nxxxxx\nnew stuff\nblah blah blah\nqwer\n";
    printf("Pasted...\n%s\n",str) ;
    assert(strcmp(str, str1) == 0);
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    assert(strcmp(str, str0) == 0);
    free(str) ;
    printf("\n##Passed!##\n");
    releaseTB (tb0);
    printf("Released Tb \n");

    printf("\n#1.5 Paste a empty text buffer at pos within tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    str1 = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str1) ;
    free(str1);

    pasteTB(tb0, 2, tb1);
    str1 = dumpTB(tb0) ;
    printf("Pasted...\n%s\n",str1) ;
    assert(strcmp(str, str1) == 0);
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    assert(strcmp(str, str0) == 0);
    free(str) ;
    printf("\n##Passed!##\n");
    free(str1);
    releaseTB (tb0);
    releaseTB (tb1);
    printf("Released Tb \n");

    printf("\n#1.6 Paste tb0 itself at pos within tb0\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;

    pasteTB(tb0, 2, tb0);
    str1 = dumpTB(tb0) ;
    printf("Pasted...\n%s\n",str1) ;
    assert(strcmp(str, str1) == 0);
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    assert(strcmp(str, str0) == 0);
    free(str) ;
    printf("\n##Passed!##\n");
    free(str1);
    releaseTB (tb0);
    printf("Released Tb \n");


    printf("\n#1.7 test all invalid pos for paste text buffer\n");
    tb0 = newTB("1.1 abc\n1.2 def\nxxxxx\n");
    tb1 = newTB("new stuff\nblah blah blah\nqwer\n");
    str = dumpTB(tb0) ;
    printf("Original Tb0:\n%s\n",str) ;
    free(str) ;
    str = dumpTB(tb1) ;
    printf("Original Tb1:\n%s\n",str) ;
    free(str) ;

    //   printf("\nPos is less than 0\n");
    //   pasteTB(tb0, -1, tb1);

    //   printf("\nPos is great than the number of lines of tb0\n");
    //   pasteTB(tb0, linesTB(tb0)+1, tb1);
    //
    //   printf("\nPaste 2 NULL text buffers\n");
    //   pasteTB(NULL, 1, NULL);
    //
    //   printf("\nPaste to NULL text buffer\n");
    //   pasteTB(NULL, 1, tb0);

    releaseTB (tb0);
    releaseTB (tb1);
    printf("Released Tb \n");
}

void testCutTB() {
    // from is great than and equal to number of lines of tb1

    // to is great than and equal to number of lines of tb1

    // from and to are great than and equal to number of lines of tb1

    // from is less than 0

    // to is less than 0

    // from and to are less than 0

    // from is at the beginning of textbuffer

    // to is at the beginning of textbuffer

    // from and to are at the beginning of textbuffer

    // from is at the end of textbuffer

    // to is at the end of textbuffer

    // from and to are at the end of textbuffer

    // from and to are at the end and beginning of textbuffer

    // from and to are within the range of 0 to number of lines of tb1.

}

void testCopyTB() {
    // from is great than and equal to number of lines of tb1

    // to is great than and equal to number of lines of tb1

    // from and to are great than and equal to number of lines of tb1

    // from is less than 0

    // to is less than 0

    // from and to are less than 0

    // from is at the beginning of textbuffer

    // to is at the beginning of textbuffer

    // from and to are at the beginning of textbuffer

    // from is at the end of textbuffer

    // to is at the end of textbuffer

    // from and to are at the end of textbuffer

    // from and to are at the end and beginning of textbuffer

    // from and to are within the range of 0 to number of lines of tb1.
}


void testDeleteTB() {
    char str1[] = "line 01\n" "line 02\n" "line 03\n" "line 04\n" "line 05\n" "line 06\n" "line 07\n" "line 08\n" "line 09\n" "line 10\n";

    TB tb1 = newTB(str1);
    char* str = dumpTB(tb1) ;
    printf("Original Tb:\n%s\n",str) ;
    free(str) ;

    // from and to are at the beginning of textbuffer
    deleteTB(tb1,0,0) ;
    str = dumpTB(tb1) ;
    printf("\nFirst line is deleted...\n%s\n",str) ;
    free(str) ;


    printf("Original Tb:\n%s\n",str) ;
    free(str) ;
    // from and to are within the range of 0 to number of lines of tb1.
    deleteTB(tb1,4,6) ;
    str = dumpTB(tb1) ;
    printf("\nLast line is deleted...\n%s\n",str) ;
    free(str) ;

    printf("Original Tb:\n%s\n",str) ;
    free(str) ;

    // from and to are at the end of textbuffer
    deleteTB(tb1,9,9) ;
    str = dumpTB(tb1) ;
    printf("\nLast line is deleted...\n%s\n",str) ;
    free(str) ;

    releaseTB (tb1);
    printf("Released Tb \n");

    // from and to are at the end and beginning of textbuffer


    // from is great than and equal to number of lines of tb1

    // to is great than and equal to number of lines of tb1

    // from and to are great than and equal to number of lines of tb1

    // from is less than 0

    // to is less than 0

    // from and to are less than 0


}

void testReplaceText() {
    //string1 is not in text buffer

    //string1 is same length as string2

    //string1 is shorter than string2

    //string1 is longer than string2

    //string1 is replace with empty string2
}

void testDiffTB() { }

void testUndoTB() { }

void testRedoTB() { }
