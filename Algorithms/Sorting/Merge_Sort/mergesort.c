//MergeSort:-

/** Strategy
 *  divide the arrays into individual elements
 *  then, compare 2 arrays and sort them
 *  then feed back the result to the sorting algo. and do the process again  
 * 

*/

#include<stdlib.h>
#include<math.h>
#include<stdio.h>

void printarr(int arr[]){
    for (int i=0;i<40;i++){
        printf("[%i] %i\n",i,arr[i]);
    }
}

int* compareNsort(int* arr1[],int* arr2[],int len){
    int i1 =0;
    int a1curr = arr1[i1];

    int i2=0;
    int a2curr = arr2[i2];

    int ansarr[len];
    int ia =0;

    while(ia<30){
        if (a1curr < a2curr){
            ansarr[ia] = a1curr;
            i2++;
            a2curr = arr1[i2];
        }
        else {
            ansarr[ia] = a2curr;
            i1++;
            a1curr = arr1[i1];
        }
        ia++;
        
    }

    return ansarr;
}

int* mergeSort(int* arr,int len){

   if(len == 1){
        return arr;
   }
   else{

        int arr_l[(int)floor(len/2)]; // array to the left  of the middle index
        int arr_r[(int)floor(len/2)]; // array to the right of the middle index

        for(int i=0;i<len/2;i++){
            arr_l[i] = arr[i];
            arr_r[i] = arr[ (int)floor(len/2) +  i];
        }

        int* al = mergeSort(arr_l,floor(len/2));
        int* ar = mergeSort(arr_r,floor(len/2));

        return compareNsort(al,ar,len);
   }
}
