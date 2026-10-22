
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int partition(vector<int>& a, int low, int high, long long& comp) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comp++;

        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

int randomizedPartition(vector<int>& a, int low, int high,
                        long long& comp) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(a[pivotIndex], a[high]);

    return partition(a, low, high, comp);
}

void quickSort(vector<int>& a, int low, int high, long long& comp) {
    if (low < high) {
        int p = partition(a, low, high, comp);
        quickSort(a, low, p - 1, comp);
        quickSort(a, p + 1, high, comp);
    }
}

void randomizedQuickSort(vector<int>& a, int low, int high,
                         long long& comp) {
    if (low < high) {
        int p = randomizedPartition(a, low, high, comp);
        randomizedQuickSort(a, low, p - 1, comp);
        randomizedQuickSort(a, p + 1, high, comp);
    }
}

void display(vector<int>& a) {
    for (int x : a)
        cout << x << " ";
    cout << "\n";
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size\n";
        return 0;
    }

    vector<int> a(n), b;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    b = a;

    long long comp1 = 0, comp2 = 0;

    quickSort(a, 0, n - 1, comp1);
    randomizedQuickSort(b, 0, n - 1, comp2);

    cout << "Deterministic Quick Sort: ";
    display(a);
    cout << "Comparisons: " << comp1 << "\n";

    cout << "Randomized Quick Sort: ";
    display(b);
    cout << "Comparisons: " << comp2 << "\n";

    return 0;
}
