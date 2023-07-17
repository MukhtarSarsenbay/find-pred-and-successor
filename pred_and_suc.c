#include <stdio.h>

// Функция для поиска предшественника и последователя в отсортированном массиве
void findPredecessorAndSuccessor(int arr[], int n, int key, int *predecessor, int *successor) {
    *predecessor = -1;
    *successor = -1;

    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            // Элемент найден
            if (mid > 0) {
                *predecessor = arr[mid - 1];
            }
            if (mid < n - 1) {
                *successor = arr[mid + 1];
            }
            return;
        } else if (arr[mid] < key) {
            // Искомый элемент находится во второй половине массива
            *predecessor = arr[mid];
            low = mid + 1;
        } else {
            // Искомый элемент находится в первой половине массива
            *successor = arr[mid];
            high = mid - 1;
        }
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 6;
    int predecessor, successor;

    findPredecessorAndSuccessor(arr, n, key, &predecessor, &successor);

    printf("Предшественник: %d\n", predecessor);
    printf("Последователь: %d\n", successor);

    return 0;
}
