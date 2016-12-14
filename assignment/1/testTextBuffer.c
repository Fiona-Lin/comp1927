/*
 * assign2.c
 * Description:
 * a simplified scoring system for Yahtzee
 * Tutorial class: T14A
 * Tutor name: Curtis Millar
 * Author: Fiona Lin(Z5131048)
 * Date:8 Oct 2016
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "textBuffer.h"

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

    testReleaseTB();
    testDumpTB();
    testLinesTB();
    testSwapTB();
    testMergeTB();
    testPasteTB();
    testCutTB();
    testCopyTB();
    testDeleteTB();
    testReplaceText();
   // testDiffTB();
   // testUndoTB();
   // testRedoTB();
 return EXIT_SUCCESS;
}

void testCreateTB() {
    printf("\n#1 create an ordinary text buffer\n");
    char *str = "this\nis\nsome\ntext";
    TB new = createTB(str);
    char *str2 = dumpTB(new)
    assert(strcmp(str1,str2) == 0);
    assert(linesTB(new) == 4);
    printf("\n##Passed!##\n");
//create a NULL text buffer
//create an empty text buffer
    printf("#1 create an empty text buffer");
    *str = "";
//create an text buffer end with non new line character
//create an text buffer has 1 line
//create an text buffer has 50 lines
//create million new lines text buffer
}

void testReleaseTB() {
//release empty text buffer
//release an ordinary text buffer
//indeed we can test the releaseTB
}

void testDumpTB() {
//dump an empty text buffer
//dump an
}

void testLinesTB() {
//0 when text buffer is NULL
//0 when text buffer is empty
//1 when text buffer has only 1 line
//10 when text buffer has 10 lines
//200 when text buffer has 200 lines
//3000 when text buffer has 3000 lines
}

void testSwapTB() {
// swap line
// pos1 is out of range
// pos2 is out of range
// pos1 and pos2 are out of range
// pos1 or pos2 is at the beginning of textbuffer
// pos1 or pos2 is at the end of textbuffer
// pos1 and pos2 are at the end and beginning of textbuffer
}

void testMergeTB() {
//Merge 2 NULL text buffers
//Merge to NULL text buffer
//Merge from NULL text buffer
//Merge 2 ordinary text buffers
}

void testPasteTB() {

}

void testCutTB() { }

void testCopyTB() { }

void testDeleteTB() { }

void testReplaceText() { }

void testDiffTB() { }

void testUndoTB() { }

void testRedoTB() { }
