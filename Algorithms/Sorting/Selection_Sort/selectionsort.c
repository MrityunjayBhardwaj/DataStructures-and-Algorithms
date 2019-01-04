#include "sortlib.h"

void selection_sort(int arr[],int len){
    int min=0;
    for(int i=0;i<len;i++){
        min = i;
        for(int j=i+1;j<len;j++){
            if (arr[j] < arr[min]){
                //swap `em
                swap(&arr[j],&arr[min]);
                min = j;
            }
        }
    }
}
