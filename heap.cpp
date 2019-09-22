#include "heap.h"
#include <cmath>
#include <stdio.h>
#include <stdlib.h>


HEAP* initialize(int n){ //initalize function which return pointer to a heap
    
   struct HEAP* h=new HEAP();
    h->capacity=n;
    h->size=0;
	h->H = (ELEMENT*)malloc(sizeof(ELEMENT)*h->capacity);
    
    return h;
}

void buildHeap(HEAP* heap,ELEMENT A[],int size){ 
    for(int i=1; i<=size; i++ ){//Copy elements from A to heap->H
        heap->H[i]=A[i];
        
    }
    
    
    
    for(int j=size/2; j>=1; j--){ //Uses linear time "build heap algorithim" to obtain a min heap of size n.
       
        minHeapify(heap->H, j, size);
        
    }
    
}


void minHeapify(ELEMENT H[],int i,int size){//"build heap algorithim"
    int l=2*i;
    int r=(2*i)+1;
    int smallest;
    int temp;
    
    if(l <= size && H[l].key < H[i].key ){ //checks if left is smaller 
        smallest=l;
    }
    else {
        smallest=i;
    }
    if(r<= size && H[r].key < H[smallest].key){ // checks if right is smaller than the above result
        smallest=r;
    }
    if(smallest != i){  
        temp=H[i].key;     //swaps nodes and places the smallest one up top
        H[i].key=H[smallest].key; 
        H[smallest].key=temp;
        minHeapify(H, smallest, size); //calls minHeapify again to continue minHeapifying all nodes
    }
    
}


void insert(HEAP* heap, int flag, int key){
    
   
    
    if(flag!=1 && flag!=2 ){
        printf("This is not a valid flag value. This operation cannot be completed.\n");
		return;
    }
    
    

    
    if(flag==1){
        int num=1000000;
        heap->size++; //creates space for new node
        heap->H[heap->size].key=num;  //places node in new space
        decreaseKey(heap, 1, heap->size, key);
        return;

    }
    
    if(flag==2){
        int num=100000;
        heap->size++; //creates space for new node
        heap->H[heap->size].key=num; //places node in new space
        decreaseKey(heap, 1, heap->size, key); 
        printHeap(heap);
        printf("\n");
        return;
    }

}

int deleteMin(HEAP* heap, int flag){
    
    
    if(heap==NULL){
        printf("Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it.\n");
        return 0;
    }
    
    if(heap->size==0){
        printf("There are no elements in heap to delete.\n");
        return 0;
    }
    
    if(flag!=1 && flag!=2 ){
        printf("This is not a valid flag value. This operation cannot be completed.\n");
        return 0;
    }


    
    if (flag==2){
    printHeap(heap);
    printf("\n");
    int min=heap->H[1].key;
    heap->H[1].key=heap->H[heap->size].key; //sets root to last node
    heap->size=heap->size-1;
    minHeapify(heap->H, 1, heap->size); //cals minHeapify on top node to make sure its a min heap again
    printHeap(heap);
    printf("\n");
    return min;
    }
    
    if (flag==1){
        int min=heap->H[1].key; 
        heap->H[1].key=heap->H[heap->size].key;  //sets root to last node
        heap->size=heap->size-1;
        minHeapify(heap->H, 1, heap->size);  //cals minHeapify on top node to make sure its a min heap again
        return min;
    }
    
    
    return 0;
    
}


void decreaseKey(HEAP* heap, int flag, int i, int value){
    int temp=0;
    
    if(flag!=1 && flag!=2 ){
        printf("This is not a valid flag value. This operation cannot be completed.\n");
    }
    
    if(heap==NULL){
        printf("Sorry!!! It cannot be done. Please initialize the heap first and put the elements into it.\n");
        return;
    }
    
    if(i>heap->size){
        printf("There are only %d elements in the heap. Hence this operation cannot be completed.\n",heap->size );
        return;
    }
    
    if(value > heap->H[i].key && i < heap->size){
        printf("\n%d cannot be larger than the current value in the heap at index %d. Hence this operation cannot be completed.\n", value,i);
        return;
    }
    
    if(flag==2){
        printHeap(heap);
        printf("\n");
     heap->H[i].key=value;
    
    while(i > 1 && heap->H[i/2].key > heap->H[i].key){ //This while loop checks all children to peserve the minHeap property 
        temp=heap->H[i].key;
        heap->H[i].key=heap->H[i/2].key;
        heap->H[i/2].key=temp;
        i=i/2;
        //printf("index 0:%d index 1:%d\n",heap->H[0].key,heap->H[1].key);
       
    }
    }
    
    if(flag==1){
        heap->H[i].key=value;
        
        while(i > 1 && heap->H[i/2].key > heap->H[i].key){  //This while loop checks all children to peserve the minHeap property 
            temp=heap->H[i].key;
            heap->H[i].key=heap->H[i/2].key;
            heap->H[i/2].key=temp;
            i=i/2;
            //printf("index 0:%d index 1:%d\n",heap->H[0].key,heap->H[1].key);
            
        }
    }
    
  
}
    
    
    
    




void printHeap(HEAP* heap){
    if(heap==NULL){
        printf("Sorry!!! It cannot be done. Please initialize the heap first.\n");
        return;
    }
    printf("The capacity is %d\n",heap->capacity); 
    printf("The size is %d\n",heap->size);
    for (int i=1; i<=heap->size; i++) { //Loop through heap until size and print contents.
        printf("%d ",heap->H[i].key);
    
    }
    if(heap->size!=0){
        printf("\n");}
}
    





