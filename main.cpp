#include <iostream>
#include <chrono>
#include "test.h"

using namespace std;
using namespace std::chrono;

//utilities algs
void performanceTestExecutor(const char *algName, void(*sortAlg)(int *arr, int size), const int *seriesSize,
                             int numOfSeries);

void saveExecutionTimeToFile(const char *fileName, int arrSize, unsigned long timeMS);

void cleanupFile(const char *fileName);

int *newArrayFromTemplate(const int *arr, int size);

int testResult(const int *expected, const int *current, int size);

void *printArray(const int *arr, int size);

void swap(int *a1, int *a2);

int *generateTestArray(int size);

void saveToFile(int arrSize, long timeMS);

// Function to perform a test
int performTest(int testData[], int expectedData[], int testDataSize, const char *algName,
                void(*sortAlg)(int *arr, int size));

// Function to perform a test
int performanceTest(const char *algName, void(*sortAlg)(int *arr, int size));

//Sorting algs
void quickSort(int *arr, int size);

void selectionSort(int *arr, int size);

void insertionSort(int *arr, int size);

void bubbleSort(int *arr, int size);


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


//TODO implement method to generate Test Array
int *generateTestArray(int size) {
    //PUT YOUR CODE HERE
}

//TODO implement a function to cleanup file before saving data there.
void cleanupFile(const char *fileName) {
    //PUT YOUR CODE HERE
}

//TODO add timing about alg execution time to corresponding file based on fileName
void saveExecutionTimeToFile(const char *fileName, int arrSize, unsigned long timeMS) {
    //PUT YOUR CODE HERE
}

//TODO implement Bubble Sort alg based on https://en.wikipedia.org/wiki/Bubble_sort
void bubbleSort(int *arr, int size) {
//PUT YOUR CODE HERE
}

//TODO implement Insertion sort alg based on https://en.wikipedia.org/wiki/Insertion_sort
void insertionSort(int *arr, int size) {
//PUT YOUR CODE HERE
}

/**
 * Implementation of Selection Sort
 */
namespace SelectionSortNS {
    int *min(int *arr, int from, int to);

    void sort(int *arr, int size);

    //TODO Implement function to find address of the minimum element of the array in the range [from, to]
    int *min(int *arr, int from, int to) {
        //PUT YOUR CODE HERE
    }

    //TODO implement Selection sorting algorithm based on https://en.wikipedia.org/wiki/Selection_sort
    void sort(int *arr, int size) {
        //PUT YOUR CODE HERE
    }

}

/**
 * Implementation of QuickSort
 */
namespace QuickSortNS {
    int partitioning(int *arr, int lo, int hi);

    void quicksort(int *arr, int low, int high);

    //TODO Implement function to partition the array based on https://en.wikipedia.org/wiki/Quicksort
    int partitioning(int *arr, int lo, int hi) {
        //PUT YOUR CODE HERE
    }

    //TODO Implement function quick sort function based on https://en.wikipedia.org/wiki/Quicksort
    void quicksort(int *arr, int low, int high) {
        //PUT YOUR CODE HERE
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

void performanceTestExecutor(const char *algName, void(*sortAlg)(int *arr, int size), const int *seriesSize,
                             int numOfSeries) {
    cleanupFile(algName);
    for (int i = 0; i < numOfSeries; i++) {
        int sizeOfArray = seriesSize[i];
        time_point<system_clock> start = high_resolution_clock::now();
        int *arr = generateTestArray(sizeOfArray);
        sortAlg(arr, sizeOfArray);
        deleteArr(arr);
        time_point<system_clock> stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        saveExecutionTimeToFile(algName, sizeOfArray, duration.count());
    }
}

int main() {


    int result = 0;
    result += performTest(TEST_ARRAY, CHECK_ARRAY, TEST_ARRAY_SIZE, "Bubble", bubbleSort);
    result += performTest(TEST_ARRAY, CHECK_ARRAY, TEST_ARRAY_SIZE, "Insertion", insertionSort);
    result += performTest(TEST_ARRAY, CHECK_ARRAY, TEST_ARRAY_SIZE, "Selection", selectionSort);
    result += performTest(TEST_ARRAY, CHECK_ARRAY, TEST_ARRAY_SIZE, "Quick", quickSort);
    if (result > 0) {
        return result;
    }
    //Here is performance test with data collection.
    performanceTestExecutor("Bubble.csv", bubbleSort, TEST_SERIES_SIZE, TEST_SERIES_NUM);
    performanceTestExecutor("Insertion.csv", insertionSort, TEST_SERIES_SIZE, TEST_SERIES_NUM);
    performanceTestExecutor("Selection.csv", selectionSort, TEST_SERIES_SIZE, TEST_SERIES_NUM);
    performanceTestExecutor("Quick.csv", quickSort, TEST_SERIES_SIZE, TEST_SERIES_NUM);

    return 0;
}
