#include <stdio.h>
#include <stdlib.h>

int binarySearch(int a[],int n,int key);
int binSearch(int a[], int l, int r, int key);

int main(void){
    int size;
    int key;
    int i;
    printf("Enter number of elements:");
    scanf("%d",&size);
    printf("Enter key to search for:");
    scanf("%d",&key);
  
    int * a = malloc(size * sizeof(int));   
    printf("Enter elements:\n"); 
    for(i=0;i<size;i++){
	scanf("%d",&a[i]);
    }
    printf("Binary search\n");   
    int result = binarySearch(a,size,key);
    if(result != -1){
        printf ("Found at index %d\n",result);
    }else{
	printf ("Did not find element\n");
    }
    return 0;
}

int binarySearch(int a[],int n,int key){
    return binSearch(a,0,n-1,key);
}

int binSearch(int a[], int l, int r, int key){
   int mid, result;
   mid = (l+r)/2;
   if( r < l){
      result = -1;
   } else if(key == a[mid]){
       result = mid;
   } else if(l == r){
       result = -1;
   } else {
       if(key < a[mid]){
           result = binSearch(a,l,mid-1,key);
       } else {
           result = binSearch(a,mid+1,r,key);
       }
   }
   
   return result; 
}

