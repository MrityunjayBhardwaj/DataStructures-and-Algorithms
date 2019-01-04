#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int arr[],int pivot_index,int start_index,int end_index){
    // end_index = end index of this subset of the array
    // start_index = start index  of this subset
    // pivot_index = pivot index of this subset

    if (start_index == end_index)return NULL;// that means there is only one element remaining. so, just return it

    int p_i = start_index;
    int pivot_val = arr[pivot_index];

    for (int i=0;i<end_index;i++){

        if ( arr[i]< pivot_val){
            swap(arr[i], arr[p_i]);
            p_i++;
        }

    }

    swap(pivot_val, arr[p_i]);

    quicksort(arr, p_i, 0, p_i-1);
    quicksort(arr, end_index, p_i+1, end_index);
}


