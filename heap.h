
struct ELEMENT{
    int key;
    
};

struct HEAP{
    int capacity;
    int size;
    ELEMENT *H;
    
};

HEAP* initialize(int n);

void buildHeap(HEAP* heap,ELEMENT A[],int size);

void insert(HEAP* heap, int flag, int key);

int deleteMin(HEAP* heap, int flag);

void decreaseKey(HEAP* heap, int flag, int index, int value);

void minHeapify(ELEMENT H[],int i,int size);

void printHeap(HEAP* heap);
