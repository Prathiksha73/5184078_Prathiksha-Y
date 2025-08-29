#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int heap[MAX];
int size = 0;

// Swap helper
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

// Heapify down
void heapifyDown(int i) {
    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

// Insert element into heap
void insert(int x) {
    heap[size] = x;
    size++;
    heapifyUp(size - 1);
}

// Delete element from heap (linear search for index)
void delete(int x) {
    int i;
    for (i = 0; i < size; i++) {
        if (heap[i] == x) {
            break;
        }
    }
    if (i == size) return; // element not found, but problem guarantees it exists

    heap[i] = heap[size - 1];
    size--;
    heapifyDown(i);
    heapifyUp(i);
}

// Print minimum (root)
void printMin() {
    if (size > 0) {
        printf("%d\n", heap[0]);
    }
}

int main() {
    int Q;
    scanf("%d", &Q);

    for (int q = 0; q < Q; q++) {
        int c, v;
        scanf("%d", &c);
        if (c == 1) {
            scanf("%d", &v);
            insert(v);
        } else if (c == 2) {
            scanf("%d", &v);
            delete(v);
        } else if (c == 3) {
            printMin();
        }
    }
    return 0;
}
