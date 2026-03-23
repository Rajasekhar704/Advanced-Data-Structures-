#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int linear[SIZE];
int quadratic[SIZE];
int doubleHash[SIZE];

struct node
{
    int data;
    struct node *next;
};

struct node* chain[SIZE];

/* Second hash function */
int hash2(int key)
{
    return 1 + (key % (SIZE - 1)); // safe step for double hashing
}

/* Linear Probing */
void insertLinear(int key)
{
    int index = key % SIZE;
    int i = 0;
    while(i < SIZE && linear[index] != -1)
    {
        index = (index + 1) % SIZE;
        i++;
    }
    if(i == SIZE)
        printf("Linear table full\n");
    else
        linear[index] = key;
}

/* Quadratic Probing */
void insertQuadratic(int key)
{
    int originalIndex = key % SIZE;
    int index = originalIndex;
    int i = 1;
    while(i < SIZE && quadratic[index] != -1)
    {
        index = (originalIndex + i*i) % SIZE;
        i++;
    }
    if(i == SIZE)
        printf("Quadratic table full\n");
    else
        quadratic[index] = key;
}

/* Double Hashing */
void insertDoubleHash(int key)
{
    int index = key % SIZE;
    int step = hash2(key);
    int i = 0;
    while(i < SIZE && doubleHash[index] != -1)
    {
        index = (index + step) % SIZE;
        i++;
    }
    if(i == SIZE)
        printf("Double hashing table full\n");
    else
        doubleHash[index] = key;
}

/* Separate Chaining */
void insertChaining(int key)
{
    int index = key % SIZE;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = key;
    newNode->next = chain[index];
    chain[index] = newNode;
}

/* Display Functions */
void displayLinear()
{
    int i;
    printf("\nLinear Probing:\n");
    for(i = 0; i < SIZE; i++)
    {
        if(linear[i] != -1)
            printf("%d -> %d\n", i, linear[i]);
        else
            printf("%d -> Empty\n", i);
    }
}

void displayQuadratic()
{
    int i;
    printf("\nQuadratic Probing:\n");
    for(i = 0; i < SIZE; i++)
    {
        if(quadratic[i] != -1)
            printf("%d -> %d\n", i, quadratic[i]);
        else
            printf("%d -> Empty\n", i);
    }
}

void displayDoubleHash()
{
    int i;
    printf("\nDouble Hashing:\n");
    for(i = 0; i < SIZE; i++)
    {
        if(doubleHash[i] != -1)
            printf("%d -> %d\n", i, doubleHash[i]);
        else
            printf("%d -> Empty\n", i);
    }
}

void displayChaining()
{
    int i;
    struct node *temp;
    printf("\nSeparate Chaining:\n");
    for(i = 0; i < SIZE; i++)
    {
        temp = chain[i];
        printf("%d -> ", i);
        while(temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int n, key, i;

    /* Initialize all arrays */
    for(i = 0; i < SIZE; i++)
    {
        linear[i] = -1;
        quadratic[i] = -1;
        doubleHash[i] = -1;
        chain[i] = NULL;
    }

    printf("Enter number of elements (max %d): ", SIZE);
    scanf("%d", &n);

    if(n > SIZE)
    {
        printf("Number of elements cannot exceed %d\n", SIZE);
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("Enter key: ");
        scanf("%d", &key);
        insertLinear(key);
        insertQuadratic(key);
        insertDoubleHash(key);
        insertChaining(key);
    }

    displayLinear();
    displayQuadratic();
    displayDoubleHash();
    displayChaining();

    return 0;
}
