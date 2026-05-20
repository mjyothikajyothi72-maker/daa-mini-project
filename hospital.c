#include <stdio.h>
#include <string.h>

struct Patient {
    char name[50];
    int priority;
};

void heapify(struct Patient p[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Compare left child
    if (left < n && p[left].priority > p[largest].priority)
        largest = left;

    // Compare right child
    if (right < n && p[right].priority > p[largest].priority)
        largest = right;

    // Swap if needed
    if (largest != i) {
        struct Patient temp = p[i];
        p[i] = p[largest];
        p[largest] = temp;

        heapify(p, n, largest);
    }
}

void heapSort(struct Patient p[], int n) {
    int i;

    // Build max heap
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(p, n, i);

    // Heap sort
    for (i = n - 1; i > 0; i--) {
        struct Patient temp = p[0];
        p[0] = p[i];
        p[i] = temp;

        heapify(p, i, 0);
    }
}

int main() {
    int n, i;

    printf("Enter number of patients: ");
    scanf("%d", &n);

    struct Patient p[n];

    // Input patient details
    for (i = 0; i < n; i++) {
        printf("\nEnter patient name: ");
        scanf("%s", p[i].name);

        printf("Enter priority value: ");
        scanf("%d", &p[i].priority);
    }

    // Sort patients using Heap Sort
    heapSort(p, n);

    // Display treatment order
    printf("\n--- Emergency Treatment Order ---\n");

    for (i = n - 1; i >= 0; i--) {
        printf("%s - Priority: %d\n",
               p[i].name,
               p[i].priority);
    }

    return 0;
}