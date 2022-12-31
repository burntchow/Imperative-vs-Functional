// Aveline Villaganas, #026858375
// CECS 342, Section 3
// Assignment 1 
// Due 9/23 @9:00am

#include <stdio.h>
#include <stdlib.h>


void qsort1(int *a, int i, int n) {
  //printf("in qsort1");
  if (n <= 1) {
    return; 
  }
  int pivot = a[i + (rand() % n) + 1];
  int j = i;     // overall iter
  int f = i - 1; // starts front 
  int b = i + n; // starts back 
  
  int temp;

  while (j < b) { 
    
    if (a[j] < pivot) {
      //printf(" --------- ");
      f++;
      temp = a[j]; // swap 
      a[j] = a[f];
      a[f] = temp;
      j++;
    } else if (a[j] > pivot) {
      b--;
      temp = a[j]; // swap 
      a[j] = a[b];
      a[b] = temp;
    } else {
      j++;
    }
  }
  qsort1(a, i, f - i + 1); // subarray front 
  qsort1(a, b, n - (b + 1)); // subarray back 
}

// quick sort array a with n elements
void qsort2(int *a, int n) {
  //printf("hello");
  qsort1(a, 0, n);
  //printf("should end here"); 
  return;
}

// ----------------------------------------------


void merge(int *a, int n, int mid, int f, int b){ 

  // temp arrays: 
  int tempF[f]; // front temp array
  int tempB[b]; // back temp array 
  for(int i = 0; i < f; i++){
    tempF[i] = a[i];
  }
  for(int i = 0; i < b; i++){
    tempB[i] = a[i + mid]; 
  }

  int fi = 0; // front sub array index
  int bi = 0; // back sub array index 
  for(int i = 0; i < n; i++){
    if(fi == f){
      a[i] = tempB[bi];
      bi++; 
    }else if(bi == b){
      a[i] = tempF[fi];
      fi++; 
    }else if(tempF[fi] <= tempB[bi]){
      a[i] = tempF[fi]; 
      fi++;
    }else{
      a[i] = tempB[bi];
      bi++;
    }
  }
}

// merge sort array a with n elements in place 
void msort(int *a, int n){  
  //printf("in msort");
  if(n <= 1){
    return; 
  }

  int mid = n / 2; 
  int* front = &a[0]; 
  int* back = &a[mid]; 

  msort(front, mid);
  msort(back, n - mid); 
  merge(a, n, mid, mid, n-mid);
  
}

void arrayDisplay(int* arr, int n){
  for(int i = 0; i < n; i++){
    printf("%d ", *(arr + i)); 
  }
  printf("\n"); 
}

int main(void) {

  // Testing quicksort =========================
  printf("Testing quicksort\n");
  printf("Odd number elements: \n");
  int n = 9;
  int en = 4; 
  int noe = 0; 
  
  int arr[] = {1,43,123,5,2135,62,3,1,32};
  // for(int i = 0; i < n; i++){
  //   printf("%d ", *(arr + i)); 
  // }
  arrayDisplay(arr, n); 
  qsort2(arr,n); // Expected: 1 1 3 5 32 43 62 123 2135  
  //print change
  arrayDisplay(arr, n);

  int arr3[] = {76,23,62,3};
  printf("\n");
  printf("Even number elements: \n");
  arrayDisplay(arr3, en); 
  qsort2(arr3,en); // Expected: 2 23 62 76
  arrayDisplay(arr3, en); 

  printf("\n");
  printf("No elements: \n");
  int arrEmpty1[] = {};
  arrayDisplay(arrEmpty1, noe);
  qsort2(arrEmpty1, noe);  // Expected: 
  arrayDisplay(arrEmpty1, noe); 

  printf("\n");
  printf("One element: \n");
  int arrSingle[] = {99};
  arrayDisplay(arrSingle, 1); 
  qsort2(arrSingle, 1);  // Expected: 99 
  arrayDisplay(arrSingle, 1); 

  printf("\n");
  printf("Negative Input: \n");
  int arrNegs[] = {-34,-1,0,-54,32,-77};
  arrayDisplay(arrNegs, 6);
  qsort2(arrNegs, 6);  // Expected: -77 -54 -34 -1 0 32
  arrayDisplay(arrNegs, 6);

  printf("\n");
  printf("Other Inputs (With char, with string, with decimals): \n");
  int arr8[] = {'a',3,5,1,2}; // Treats in terms of ascii table  'a' = 97
  arrayDisplay(arr8, 5);
  qsort2(arr8, 5);   // Expected: 1 2 3 5 97 
  arrayDisplay(arr8, 5); 
  printf("\n");
  int arr9[] = {"apple sauce",3,5,1,2}; // Technically, still works. 
  arrayDisplay(arr9, 5);
  qsort2(arr9, 5);  
  arrayDisplay(arr9, 5); 
  printf("\n");
  int arr10[] = {0.5, 12.3, 1.2, 2.4, 1.7};  // Treats as ints so 0.5 -> 0, 12.3 -> 12 . . . 
  arrayDisplay(arr10, 5);
  qsort2(arr10, 5);  // Expected: 0 1 1 2 12 
  arrayDisplay(arr10, 5); 
  
  printf("\n");

  printf("- - - - - - - - - - - -\n\n");
  
  // Testing mergesort ==========================
  printf("Testing mergesort \n");
  printf("Odd number elements: \n");
  int arr2[] = {1,43,123,5,2135,62,3,1,32};

  arrayDisplay(arr2, n);
  msort(arr2, n); // Expected: 1 1 3 5 32 43 62 123 2135
  arrayDisplay(arr2, n);

  int arr4[] = {76,23,62,3};
  printf("\n");
  printf("Even number elements: \n");
  arrayDisplay(arr4, en); 
  msort(arr4,en); // Expected: 2 23 62 76
  arrayDisplay(arr4, en); 

  printf("\n");
  printf("No elements: \n");
  int arrEmpty2[] = {};
  arrayDisplay(arrEmpty2, noe);
  msort(arrEmpty2, noe);  // Expected: 
  arrayDisplay(arrEmpty2, noe); 

  printf("\n");
  printf("One element: \n");
  int arrSingle2[] = {99};
  arrayDisplay(arrSingle2, 1); 
  msort(arrSingle2, 1);  // Expected: 99 
  arrayDisplay(arrSingle2, 1); 

  printf("\n");
  printf("Negative Input: \n");
  int arrNegs2[] = {-34,-1,0,-54,32,-77};
  arrayDisplay(arrNegs2, 6);
  msort(arrNegs2, 6);  // Expected: -77 -54 -34 -1 0 32
  arrayDisplay(arrNegs2, 6);

  printf("\n");
  printf("Other Inputs (With char, with string, with decimals): \n");
  int arr6[] = {'a',3,5,1,2}; // Treats in terms of ascii table  'a' = 97
  arrayDisplay(arr6, 5);
  msort(arr6, 5);   // Expected: 1 2 3 5 97 
  arrayDisplay(arr6, 5); 
  printf("\n");
  int arr7[] = {"apple sauce",3,5,1,2}; // Technically, still works. 
  arrayDisplay(arr7, 5);
  msort(arr7, 5);  
  arrayDisplay(arr7, 5); 
  printf("\n");
  int arr11[] = {0.5, 12.3, 1.2, 2.4, 1.7};  // Treats as ints so 0.5 -> 0, 12.3 -> 12 . . . 
  arrayDisplay(arr11, 5);
  msort(arr11, 5);  // Expected: 0 1 1 2 12 
  arrayDisplay(arr11, 5); 
}