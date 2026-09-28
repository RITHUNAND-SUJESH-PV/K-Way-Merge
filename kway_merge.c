#include <stdio.h>

#define K 3
#define N 4

typedef struct {
    int value;
    int list_no;
    int index;
} HeapNode;

HeapNode heap[K];
int heapSize = 0;

int heapComparisons = 0;
int heapOperations = 0;

/* Swap two heap nodes */
void swap(HeapNode *a, HeapNode *b)
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

/* Insert an element into Min Heap */
void insertHeap(HeapNode node)
{
    int i = heapSize++;

    heap[i] = node;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        heapComparisons++;

        if (heap[parent].value <= heap[i].value)
            break;

        swap(&heap[parent], &heap[i]);
        heapOperations++;

        i = parent;
    }
}

/* Delete minimum element */
HeapNode deleteMin()
{
    HeapNode min = heap[0];

    heap[0] = heap[heapSize - 1];
    heapSize--;

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heapSize)
        {
            heapComparisons++;

            if (heap[left].value < heap[smallest].value)
                smallest = left;
        }

        if (right < heapSize)
        {
            heapComparisons++;

            if (heap[right].value < heap[smallest].value)
                smallest = right;
        }

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        heapOperations++;

        i = smallest;
    }

    return min;
}

/* Display heap */
void displayHeap()
{
    printf("[ ");

    for (int i = 0; i < heapSize; i++)
    {
        printf("%d", heap[i].value);

        if (i < heapSize - 1)
            printf(", ");
    }

    printf(" ]\n");
}

/* K-way merge */
void kWayMerge(int lists[K][N])
{
    heapSize = 0;
    heapComparisons = 0;
    heapOperations = 0;

    printf("\n--- K-WAY MERGE USING MIN HEAP ---\n");

    /* Insert first element of each list */
    for (int i = 0; i < K; i++)
    {
        HeapNode node;

        node.value = lists[i][0];
        node.list_no = i;
        node.index = 0;

        insertHeap(node);
    }

    printf("Initial Heap: ");
    displayHeap();

    printf("\nMerged Output: ");

    while (heapSize > 0)
    {
        HeapNode min = deleteMin();

        printf("%d ", min.value);

        /* Insert next element from same list */
        if (min.index + 1 < N)
        {
            HeapNode next;

            next.value = lists[min.list_no][min.index + 1];
            next.list_no = min.list_no;
            next.index = min.index + 1;

            insertHeap(next);
        }

        printf("\nHeap: ");
        displayHeap();
    }

    printf("\nHeap comparisons = %d\n", heapComparisons);
    printf("Major heap operations = %d\n", heapOperations);
}

/* Pairwise merge */
int merge(int a[], int n1, int b[], int n2, int result[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    int comparisons = 0;

    while (i < n1 && j < n2)
    {
        comparisons++;

        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while (i < n1)
        result[k++] = a[i++];

    while (j < n2)
        result[k++] = b[j++];

    return comparisons;
}

/* Pairwise merge */
void pairwiseMerge(int lists[K][N])
{
    int temp[8];
    int result[12];

    int comparisons1;
    int comparisons2;

    printf("\n--- PAIRWISE MERGE ---\n");

    comparisons1 = merge(
        lists[0], 4,
        lists[1], 4,
        temp
    );

    printf("L1 + L2 = ");

    for (int i = 0; i < 8; i++)
        printf("%d ", temp[i]);

    printf("\n");

    comparisons2 = merge(
        temp, 8,
        lists[2], 4,
        result
    );

    printf("Final Result = ");

    for (int i = 0; i < 12; i++)
        printf("%d ", result[i]);

    printf("\n");

    printf("Pairwise comparisons = %d\n",
           comparisons1 + comparisons2);
}

int main()
{
    int lists[K][N] =
    {
        {10, 30, 50, 70},
        {20, 40, 60, 80},
        {15, 35, 55, 75}
    };

    printf("INPUT LISTS\n");

    for (int i = 0; i < K; i++)
    {
        printf("L%d: ", i + 1);

        for (int j = 0; j < N; j++)
            printf("%d ", lists[i][j]);

        printf("\n");
    }

    kWayMerge(lists);

    pairwiseMerge(lists);

    return 0;
}
