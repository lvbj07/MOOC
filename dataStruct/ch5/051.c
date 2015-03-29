#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *data;
    int size;
    int capacity;
} *MinHeap;

MinHeap create(int maxsize);
int isFull(MinHeap heap);
int isEmpty(MinHeap heap);
void insert(MinHeap heap, int x);
void showPath(MinHeap heap, int idx);

int main()
{
    int maxSize;
    int countOfIndices;
    int number;
    scanf("%d %d", &maxSize, &countOfIndices);

    MinHeap heap = create(1000);
    for (int i = 0; i != maxSize; ++i)
    {
        scanf("%d", &number);
        insert(heap, number);
    }

    for (int i = 0; i != countOfIndices; ++i)
    {
        scanf("%d", &number);
        showPath(heap, number);
    }

    return 0;
}

// function definitions

MinHeap create(int maxsize)
{
    MinHeap heap = malloc(sizeof(heap));
    heap -> data = malloc(sizeof(int) * (maxsize + 1));
    heap -> data[0] = -99999;
    heap -> capacity = maxsize;
    heap -> size = 0;
    return heap;
}

int isFull(MinHeap heap)
{
    return heap -> capacity == heap -> size;
}

int isEmpty(MinHeap heap)
{
    return heap -> size == 0;
}

void insert(MinHeap heap, int x)
{
    if (isFull(heap))
    {
        printf("heap is full\n");
        return;
    }

    heap -> size += 1;
    int i = heap -> size;

    while (x < heap -> data[i / 2])
    {
        heap -> data[i] = heap -> data[i / 2];
        

        i = i / 2;
    }
    heap -> data[i] = x;

}

void showPath(MinHeap heap, int idx)
{
    printf("%d", heap -> data[idx]);
    idx /= 2;
    while (idx != 0)
    {
        printf(" %d", heap -> data[idx]);
        idx /= 2;
    }
    printf("\n");
}
