// words.c ... Build a tree of words from /usr/dict/words
// Written by John Shepherd, August 2008
// Modified by Angela Finlayson, January 2009

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include "Item.h"
#include "Tree.h"

#define WORD_FILE "/usr/share/dict/words"
#define MAX_WORD_SIZE 100

void getAllWords(FILE *, Tree t);
void searchAllWords(FILE *f, Tree t);
void testSearchWords(Tree wordTree);

// Get words, store in tree, print tree stats
int main(int argc, char **argv){
    char *wordsFile; // name of file containing words
    FILE *wordf;     // file handle for file containing words
    Tree wordTree;
    int strategy = NO_REBALANCE;
    // access the word file
    if (argc > 1){
        wordsFile = argv[1];
    }else{
        wordsFile = WORD_FILE;
    }
    if(argc > 2){
        strategy = atoi(argv[2]);
    }
    wordf = fopen(wordsFile,"r");
    if (wordf == NULL) {
        printf("Can't open %s\n",wordsFile);
        exit(1);
    }
    wordTree = TREEinit(strategy);
    printf("Reading words from %s\n",wordsFile);
    //build tree containing all words
    getAllWords(wordf, wordTree);
    TREEshowStats(wordTree);
    searchAllWords(wordf,wordTree);
    // print some properties of the Tree
    TREEdisplay(wordTree);
    TREEshowStats(wordTree);
    testSearchWords(wordTree);
    TREEdestroy(wordTree);
    return 0;
}

// Search the given tree for all words from the given file
void searchAllWords(FILE *f, Tree wordTree){
    char word[MAX_WORD_SIZE];
    rewind(f);
    while (fgets(word,MAX_WORD_SIZE,f) != NULL) {
        int n = strlen(word);
        word[n-1] = '\0'; // strip off \n
        // filter out empty words
        if (strcmp(word,"") != 0){
            //If we are using the tree that we loaded all the words
            //into, all the words we search for should be there
            int res = TREEsearch(wordTree,word);
            assert(res == 1);
        }
    }

}


// Read all words from file into tree
void getAllWords(FILE *f, Tree wordTree){
    char word[MAX_WORD_SIZE];

    while (fgets(word,MAX_WORD_SIZE,f) != NULL) {
        int n = strlen(word);
        word[n-1] = '\0'; // strip off \n
        // filter out empty words
        if (strcmp(word,"") != 0) {
            TREEinsert(wordTree,strdup(word));
        }
    }
}

void testSearchWords(Tree wordTree){
    int size = TREEcount(wordTree);
    int i;
    char * testData[16] = { "apple","egg","lettuce","quince","turnip", "fiona","arrange","kittenish","cerulean","outermost","excising","grimmer","reform","snoop","trike","éclair"};

    if(size == 13) {
        for (i = 0; i < 6; i++) {
            clock_t begin = clock();
            int res = TREEsearch(wordTree,testData[i]);
            clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nSearch word [%s] takes %lf seconds, Found: %d\n", testData[i], time_spent, res);
            TREEshowStats(wordTree);
        }
    } else {
        for (i = 5; i < 16; i++) {
            clock_t begin = clock();
            int res = TREEsearch(wordTree,testData[i]);
            clock_t end = clock();
            double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nSearch word [%s] takes %lf seconds, Found: %d\n ", testData[i], time_spent, res);
            TREEshowStats(wordTree);
        }
    }

}


