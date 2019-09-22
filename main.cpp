//=============================================================================
// The following is a partial program that calls "nextCommand" in util.cpp.
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "heap.h"
#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
#include <cmath>
using namespace std;
int main() {
    
    // variables for the parser...
    char c;
    int i, v,f;
    HEAP *mainHeap=NULL;
    while (1) {
        c = nextCommand(&i, &v, &f);
        switch (c) {
            default: break;
            case 'c':
            case 'C':printf("COMMAND: %c %d.\n", c, i); mainHeap = initialize(i);
                break;
            case 's':
            case 'S': printf("COMMAND: %c.\n", c); printf("The program is going to be terminated."); exit(0);
            case 'k':
            case 'K': printf("COMMAND: %c %d %d %d.\n", c, f, i, v);
                decreaseKey(mainHeap, f, i, v);
                break;
            case 'i':
            case 'I':printf("COMMAND: %c %d %d.\n", c, f, v);
                if (mainHeap == NULL) {
                    printf("Sorry!!! It cannot be done. Please initialize the heap first.\n");
                    break;
                }
                
                
                if (f == 2) {
                    printHeap(mainHeap);
                    printf("\n");
                }
                
                if (mainHeap->size == mainHeap->capacity && (f == 1 || f == 2)) {//allocates new memory for heap 
                    mainHeap->capacity =(int) pow(2, ceil(log(mainHeap->size + 1) / log(2)));
                    HEAP* newheap;
                    newheap = initialize(mainHeap->capacity);
                    newheap->size = mainHeap->size;
                    buildHeap(newheap, mainHeap->H, mainHeap->size);
                    mainHeap = newheap;
                }
                insert(mainHeap, f, v);
                break;
            case 'd':
            case 'D':printf("COMMAND: %c %d \n", c, f);
                int min;
                min = deleteMin(mainHeap, f);
                if (min != 0) { printf("%d\n", min); break; } break;
            case 'w':
                printf("COMMAND: %c\n", c);
            case 'W':printHeap(mainHeap); break;
            case 'r':
            case 'R':
                printf("COMMAND: %c\n", c);
                int size = 0;
                FILE *file;
                file = fopen("HEAPinput.txt", "r");
                if (mainHeap == NULL) { //Checks if heap is null
                    printf("Sorry!!! It cannot be done. Please initialize the heap first.\n");
                    break;
                }
                if (file == NULL) {
                    printf("There was a problem opening file HEAPinput.txt for reading.\n");
                    break;
                }
                fscanf(file, "%d", &size); //Takes in size of the incoming heap
                int num = 0;
                int i = 0;
                while (fscanf(file, "%d", &num) > 0) { 
                    if (mainHeap != NULL) {
                        i++;
                    }
                } //count how many lines are in the text file
                if (i < size) {
                    printf("Sorry!!! It cannot be done. The number of elements in file is less than as specified in the beginning of file.\n");
                    break;
                }
                if (i > mainHeap->capacity) {
                    printf("Sorry!!! It cannot be done. Please increase the capacity of heap first.\n");
                    break;
                }
                fseek(file, 0, SEEK_SET);//reseting pointer and variables to read back up top of the text file
                fscanf(file, "%d", &size);
                i = 1;
                ELEMENT A[100];
                while (fscanf(file, "%d", &num) > 0 && i <= size) {//Copying numbers from text file into Array A
                    if (mainHeap != NULL) {
                        A[i].key = num;
                        mainHeap->size++;
                        i++;
                    }
                }
                buildHeap(mainHeap, A, mainHeap->size); //Using buildHeap to build the heap from A
                break;
        }
        
        
        
        
    }
    exit(0);
}
