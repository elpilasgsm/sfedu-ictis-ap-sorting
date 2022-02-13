#include "iostream"

using namespace std;

int *newArrayFromTemplate(const int *arr, int size);

void *printArray(const int *arr, int size);

void bubbleSort(int *arr, int size);

void swap(int *a1, int *a2);

void quickSort(int *arr, int size);

void mergeSort(int *arr, int size);

int testResult(const int *expected, const int *current, int size);

int testResult(const int *expected, const int *current, int size) {
    int retVal = 0;
    for (int i = 0; i < size; i++) {
        retVal += (expected[i] == current[i]) ? 0 : 1;
    }
    return retVal;
}

int *newArrayFromTemplate(const int *arr, const int size) {
    int *newArr = new int[size];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    return newArr;
}

void *printArray(const int *arr, const int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    return nullptr;
}

void deleteArr(const int *arr) {
    delete[] arr;
}


void swap(int *a1, int *a2) {
    int tmp = *a1;
    *a1 = *a2;
    *a2 = tmp;
}

void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

const int TEST_ARRAY[] = {4, 2, 1, 5, 1, 6, 1, 3, 5, 6, 8, 9, 12, 66, 11, 6, 22, 123, 0, 98};
const int CHECK_ARRAY[] = {0, 1, 1, 1, 2, 3, 4, 5, 5, 6, 6, 6, 8, 9, 11, 12, 22, 66, 98, 123};
const int TEST_ARRAY_SIZE = 20;


int main() {
    int *arr = newArrayFromTemplate(TEST_ARRAY, TEST_ARRAY_SIZE);
    printArray(arr, TEST_ARRAY_SIZE);
    bubbleSort(arr, TEST_ARRAY_SIZE);
    printArray(arr, TEST_ARRAY_SIZE);
    int check = testResult((int *) CHECK_ARRAY, arr, TEST_ARRAY_SIZE);
    if (check != 0) {
        cout << "Bubble sort is incorrect. Number of errors " << check;
        return 1;
    }
    deleteArr(arr);
    return 0;
}
