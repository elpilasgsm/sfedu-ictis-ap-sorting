#include "iostream"

using namespace std;


//test data

//utilities algs
int *newArrayFromTemplate(const int *arr, int size);

void *printArray(const int *arr, int size);

void swap(int *a1, int *a2);

//Sorting algs
void quickSort(int *arr, int size);

void selectionSort(int *arr, int size);

void insertionSort(int *arr, int size);

void bubbleSort(int *arr, int size);

// Function to perform a test
int performTest(int testData[], int expectedData[], int testDataSize, const char *algName,
                void(*sortAlg)(int *arr, int size));
/**
 * Implementation of QuickSort
 */
namespace QuickSortNS {
    int partitioning(int *arr, int lo, int hi);

    void quicksort(int *arr, int low, int high);

    void quicksort(int *arr, int low, int high) {
        if (low < high) {
            int p = partitioning(arr, low, high);
            quicksort(arr, low, p - 1);
            quicksort(arr, p + 1, high);
        }
    }

    int partitioning(int *arr, int lo, int hi) {
        int p = arr[hi];
        int i = lo - 1;
        for (int j = lo; j < hi; j++) {
            if (arr[j] < p) {
                swap(&arr[j], &arr[++i]);
            }
        }
        swap(&arr[i + 1], &arr[hi]);
        return i + 1;
    }
}


/**
 * Implementation of Selection Sort
 */
namespace SelectionSortNS {
    int *min(int *arr, int from, int to) {
        int *minA = nullptr;
        for (int i = from; i < to; i++) {
            if (minA == nullptr || arr[i] < *minA) {
                minA = &arr[i];
            }
        }
        return minA;
    }

    void sort(int *arr, int size) {
        for (int i = 0; i < size; i++) {
            int *minA = min(arr, i, size);
            swap(&arr[i], minA);
        }
    }
}

void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[++j] = key;
    }
}

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
        cout << arr[i] << ", ";
    }
    cout << endl;
    return nullptr;
}

void deleteArr(const int *arr) {
    delete[] arr;
}


void swap(int *a1, int *a2) {
    if (a1 == nullptr || a2 == nullptr || a1 == a2) {
        return;
    }
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

void quickSort(int *arr, int size) {
    QuickSortNS::quicksort(arr, 0, size - 1);
}

void selectionSort(int *arr, int size) {
    SelectionSortNS::sort(arr, size);
}


int performTest(int testData[], int expectedData[], int testDataSize, const char *algName,
                void(*sortAlg)(int *arr, int size)) {
    int *arr = newArrayFromTemplate(testData, testDataSize);
    sortAlg(arr, testDataSize);
    int check = testResult((int *) expectedData, arr, testDataSize);
    deleteArr(arr);

    if (check != 0) {
        cerr << "[FAIL] " << algName << " is incorrect. Number of errors " << check << endl;
        return 1;
    } else {
        cout << "[OK] " << algName << " passed Successfully" << endl;
        return 0;
    }
}

int main() {
    int TEST_ARRAY[] = {4, 2, 1, 5, 1, 6, 1, 3, 5, 6, 8, 9, 12, 66, 11, 6, 22, 123, 0, 98};
    int CHECK_ARRAY[] = {0, 1, 1, 1, 2, 3, 4, 5, 5, 6, 6, 6, 8, 9, 11, 12, 22, 66, 98, 123};
    const int TEST_ARRAY_SIZE = 20;

    int result = 0;
    result += performTest(TEST_ARRAY, CHECK_ARRAY, TEST_ARRAY_SIZE, "Bubble", bubbleSort);
    result += performTest(TEST_ARRAY, CHECK_ARRAY, TEST_ARRAY_SIZE, "Insertion", insertionSort);
    result += performTest(TEST_ARRAY, CHECK_ARRAY, TEST_ARRAY_SIZE, "Selection", selectionSort);
    result += performTest(TEST_ARRAY, CHECK_ARRAY, TEST_ARRAY_SIZE, "Quick", quickSort);
    return result;
}
