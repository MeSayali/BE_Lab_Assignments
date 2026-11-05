
#include <bits/stdc++.h>
using namespace std;

// Count actual comparisons and swaps
int comparisons, swapsCount;

// Partition for Deterministic Quick Sort
// First element is selected as pivot
int deterministicPartition(vector<int> &arr, int low, int high) {

    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (true) {

        while (left <= right) {
            comparisons++;
            if (arr[left] <= pivot)
                left++;
            else
                break;
        }

        while (left <= right) {
            comparisons++;
            if (arr[right] >= pivot)
                right--;
            else
                break;
        }

        if (left > right)
            break;

        swap(arr[left], arr[right]);
        swapsCount++;
    }

    swap(arr[low], arr[right]);
    swapsCount++;

    return right;
}

// Deterministic Quick Sort
void deterministicQuickSort(vector<int> &arr, int low, int high) {

    if (low < high) {

        int pivotIndex = deterministicPartition(arr, low, high);

        // Sort left subarray
        deterministicQuickSort(arr, low, pivotIndex - 1);

        // Sort right subarray
        deterministicQuickSort(arr, pivotIndex + 1, high);
    }
}


// Partition for Randomized Quick Sort
int randomizedPartition(vector<int> &arr, int low, int high) {

    // Select a random pivot
    int pivotIndex = low + rand() % (high - low + 1);

    // Move random pivot to first position
    swap(arr[low], arr[pivotIndex]);
    swapsCount++;

    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (true) {

        while (left <= right) {
            comparisons++;
            if (arr[left] <= pivot)
                left++;
            else
                break;
        }

        while (left <= right) {
            comparisons++;
            if (arr[right] >= pivot)
                right--;
            else
                break;
        }

        if (left > right)
            break;

        swap(arr[left], arr[right]);
        swapsCount++;
    }

    // Place pivot at correct position
    swap(arr[low], arr[right]);
    swapsCount++;

    return right;
}

// Randomized Quick Sort
void randomizedQuickSort(vector<int> &arr, int low, int high) {

    if (low < high) {

        int pivotIndex = randomizedPartition(arr, low, high);

        // Sort left subarray
        randomizedQuickSort(arr, low, pivotIndex - 1);

        // Sort right subarray
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}


// Print array
void printArray(const vector<int> &arr) {
    for (int x : arr)
        cout << x << " ";

    cout << endl;
}


// Main function
int main() {

    srand(time(0));

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!";
        return 0;
    }

    vector<int> original(n);

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
        cin >> original[i];

    int ch;

    while (true) {

        cout << "\n1. Deterministic Quick Sort";
        cout << "\n2. Randomized Quick Sort";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";

        cin >> ch;

        // Make a fresh copy for every sorting operation
        vector<int> arr = original;

        // Reset counters
        comparisons = 0;
        swapsCount = 0;

        switch (ch) {

        case 1:

            cout << "\nOriginal Array:\n";
            printArray(arr);

            deterministicQuickSort(arr, 0, n - 1);

            cout << "Sorted Array (Deterministic):\n";
            printArray(arr);

            cout << "Comparisons: " << comparisons << endl;
            cout << "Swaps: " << swapsCount << endl;

            break;

        case 2:

            cout << "\nOriginal Array:\n";
            printArray(arr);

            randomizedQuickSort(arr, 0, n - 1);

            cout << "Sorted Array (Randomized):\n";
            printArray(arr);

            cout << "Comparisons: " << comparisons << endl;
            cout << "Swaps: " << swapsCount << endl;

            break;

        case 3:
            cout << "Program exited.";
            return 0;

        default:
            cout << "Invalid choice!";
        }
    }

    return 0;
}
