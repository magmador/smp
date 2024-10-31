#include <stdio.h>

void print_arr(int *arr, const size_t arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void swap(int *arr1, int *arr2) {
    int tmp = *arr1;
    *arr1 = *arr2;
    *arr2 = tmp;
}

// arr_size - number of elements in array
void quick_sort(int *arr, const size_t arr_size) {
    if (arr_size == 1) return;

    size_t i = 0;
    size_t j = arr_size - 1;
    size_t middle_point = arr_size / 2;
    int pivot = arr[middle_point]; // we assume that middle element is pivot

    while (i < j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    quick_sort(arr, j + 1);
    quick_sort(arr + j, middle_point);

}

int main() {
    int arr[] = {19, 17, 15, 12, 16, 18, 4, 7, 13};
    size_t arr_size = sizeof(arr)/sizeof(int);

    printf("Before sort: \n");
    print_arr(arr, arr_size);

    quick_sort(arr, arr_size);

    printf("After sort: \n");
    print_arr(arr, arr_size);
    return 0;
}
