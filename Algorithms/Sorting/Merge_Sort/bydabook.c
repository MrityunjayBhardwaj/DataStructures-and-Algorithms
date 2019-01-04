
#include<stdio.h>
#include<stdlib.h>


void mergesort(int arr[],int low,int high){
    int i;
    int mid;

    if(low< high){
        mid = (low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void merge(int arr[],int low,int middle,int high){
    int i;
    queue buffer1,buffer2;

    init_queue(&buffer1);
    init_queue(&buffer2);


    for( i=low;i<middle;i++)enqueue(&buffer1,arr[i]);
    for( i=middle;i<=high;i++)enqueue(&buffer2,arr[i]);

    i = low;
    while(!(empty_queue(&buffer1))|| empty_queue(&buffer2)){
        if (headq(&buffer1) <=headq(&buffer2))
            arr[i++] = dequeue(&buffer1);
        else{
            arr[i++] = dequeue(&buffer2);
        }
    }


    while(!empty_queue(&buffer1))arr[i++] = dequeue(&buffer1);
    while(!empty_queue(&buffer2))arr[i++] = dequeue(&buffer2);
    
}