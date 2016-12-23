#include <stdio.h>
#include <stdlib.h>

int findMax(int sequence[],int low,int high);

// This is where it all happens!
int main(int argc, char *argv[]) {
    int i, numElements;
    int *sequence;
    int maxNum;

    // Obtain number of elements and allocate memory to store them
    fprintf(stderr, "Enter number of elements\n");
    scanf("%d", &numElements);
    sequence = (int *) malloc(numElements * sizeof(int)); // Array of elements
    
    // Obtain data and store them in array sequence
    fprintf(stderr, "Enter elements\n");
    for (i = 0; (i < numElements) && (scanf("%d", &sequence[i]) != EOF); i++){
        ; // Do nothing - it's all done in the for statement!
    }
    numElements = i; // Just in case user entered fewer items

    maxNum = findMax(sequence,0,numElements-1);
    printf("Max is %d\n",maxNum);
    return 0;
}

//recursive find max function
int findMax(int sequence[], int low, int high) {
    int mid, first, second, result;
    if (low == high){
        result = sequence[low];
    }else{
        mid = (low + high)/2;
        first = findMax(sequence, low, mid);
        second = findMax(sequence, mid + 1, high);
        if (first > second){
            result = first;
        }else{
            result = second;
        }
    }
    return result;
}
