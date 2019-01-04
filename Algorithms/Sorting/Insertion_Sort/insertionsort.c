// TODO: Create Insertion Sort
#include <stdio.h>
#include "sortlib.h"

void insertion_sort(int arr[],int len){
// method select any value in the array and compare it to all the values that come before the current value
// and if the any of the previous[j-1] value is smaller then the currently[j] survayed value (inside 2nd loop) then swap `em

    for ( int i =1; i<len;i++){
        for (int j =i; j>0;j--){
            if (arr[j]<arr[j-1]){
                swap(&arr[j],&arr[j-1]);
            }
        }
    }

}
