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
// Pos1 is out of range

// Pos2 is out of range

// Pos1 and Pos2 are out of range

// Pos1 is at the beginning of textbuffer

// Pos2 is at the beginning of textbuffer

// Pos1 is at the end of textbuffer

// Pos2 is at the end of textbuffer

// Pos1 and Pos2 are at the end and beginning of textbuffer

// Pos1 and Pos2 are in within the range of textbuffer
}

void testMergeTB() {
//Pos is 0, which is the beginning of tb1

//Pos is equal to the number of lines of tb1 subtract 1,
//which is the end of tb1

//Pos is within the range of 0 to number of lines of tb1.

//Pos is less than 0

//Pos is great than and equal to number of lines of tb1

//Merge 2 NULL text buffers

//Merge to NULL text buffer

//Merge from NULL text buffer
}

void testPasteTB() {
//Pos is 0, which is the beginning of tb1

//Pos is equal to the number of lines of tb1 subtract 1,
//which is the end of tb1

//Pos is within the range of 0 to number of lines of tb1.

//Pos is less than 0

//Pos is great than and equal to number of lines of tb1


//Paste a NULL text buffer to another NULL text buffer

//Paste to NULL text buffer

//Paste from NULL text buffer
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
