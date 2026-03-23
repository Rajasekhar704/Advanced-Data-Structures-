#include <stdio.h>
int heap[50], size = 0, type;
/* Insert Operation */
void insert(int val)
{
    int i = ++size;
    if (type == 1)   // MIN HEAP
    {
        while (i > 1 && val < heap[i / 2])
        {
            heap[i] = heap[i / 2];
            i = i / 2;
        }
    }
    else             // MAX HEAP
    {
        while (i > 1 && val > heap[i / 2])
        {
            heap[i] = heap[i / 2];
            i = i / 2;
        }
    }
    heap[i] = val;
}
/* Delete Operation */
void deleteRoot()
{
    int last = heap[size--];
    int parent = 1, child = 2;
    if (type == 1)   // MIN HEAP
    {
        while (child <= size)
        {
            if (child < size && heap[child] > heap[child + 1])
                child++;
            if (last <= heap[child])
                break;
            heap[parent] = heap[child];
            parent = child;
            child = child * 2;
        }
    }
    else             // MAX HEAP
    {
        while (child <= size)
        {
            if (child < size && heap[child] < heap[child + 1])
                child++;
            if (last >= heap[child])
                break;
            heap[parent] = heap[child];
            parent = child;
            child = child * 2;
        }
    }
    heap[parent] = last;
}
/* Display Heap */
void display()
{
    int i;
    if (size == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    for (i = 1; i <= size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}
int main()
{
    int choice, val;
    printf("Select Heap Type:\n");
    printf("1. Min Heap\n2. Max Heap\n");
    scanf("%d", &type);
    while (1)
    {
        printf("\n1.Insert\n2.Delete Root\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            deleteRoot();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
    }
}
 

