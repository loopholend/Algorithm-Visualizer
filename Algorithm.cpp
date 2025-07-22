#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Utility print
void printArray(const vector<int>& arr, int h1 = -1, int h2 = -1) {
    for (int i = 0; i < arr.size(); ++i) {
        if (i == h1 || i == h2) cout << "[" << arr[i] << "] ";
        else cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble Sort
void bubbleSortStepByStep(vector<int> arr) {
    int n = arr.size();
    cout << "Initial array:\n";
    printArray(arr);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            cout << "\nComparing index " << j << " and " << j+1 << ": ";
            printArray(arr, j, j+1);
            if (arr[j] > arr[j+1]) {
                cout << "Swapping " << arr[j] << " and " << arr[j+1] << endl;
                swap(arr[j], arr[j+1]);
                printArray(arr, j, j+1);
            } else {
                cout << "No swap needed.\n";
            }
            cout << "Press Enter to continue."; cin.get();
        }
    }
    cout << "\nSorted array:\n";
    printArray(arr);
}

// Selection Sort
void selectionSortStepByStep(vector<int> arr) {
    int n = arr.size();
    cout << "Initial array:\n";
    printArray(arr);
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            cout << "Comparing current min at " << minIdx << " with " << j << ": ";
            printArray(arr, minIdx, j);
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
                cout << "New min found at index " << minIdx << endl;
            } else cout << "No change.\n";
            cout << "Press Enter to continue.\n"; cin.get();
        }
        if (minIdx != i) {
            cout << "Swapping " << arr[i] << " and " << arr[minIdx] << endl;
            swap(arr[i], arr[minIdx]);
            printArray(arr, i, minIdx);
        } else {
            cout << "No swap needed.\n";
        }
        cout << "Press Enter to continue.\n"; cin.get();
    }
    cout << "Sorted array:\n";
    printArray(arr);
}

// Insertion Sort
void insertionSortStepByStep(vector<int> arr) {
    int n = arr.size();
    cout << "Initial array:\n";
    printArray(arr);
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        cout << "\nInserting " << key << " at position " << i << endl;
        while (j >= 0 && arr[j] > key) {
            cout << "Comparing " << arr[j] << " and " << key << ", shifting " << arr[j] << " to right\n";
            arr[j+1] = arr[j];
            printArray(arr, j, j+1);
            cout << "Press Enter to continue.\n"; cin.get();
            --j;
        }
        arr[j+1] = key;
        cout << "Inserted " << key << " at position " << j+1 << endl;
        printArray(arr, j+1);
        cout << "Press Enter to continue.\n"; cin.get();
    }
    cout << "Sorted array:\n";
    printArray(arr);
}

// Merge Sort
void printRange(const vector<int>& arr, int l, int r, string label) {
    cout << label << ": ";
    for (int i = l; i <= r; ++i) cout << arr[i] << " ";
    cout << endl;
}
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    printRange(arr, l, m, "Left");
    printRange(arr, m+1, r, "Right");
    cout << "Merging...\n";
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        cout << "Comparing " << left[i] << " and " << right[j] << endl;
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
        printArray(arr);
        cout << "Press Enter...\n"; cin.get();
    }
    while (i < left.size()) {
        arr[k++] = left[i++];
        printArray(arr);
        cout << "Press Enter...\n"; cin.get();
    }
    while (j < right.size()) {
        arr[k++] = right[j++];
        printArray(arr);
        cout << "Press Enter...\n"; cin.get();
    }
}
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
void mergeSortStepByStep(vector<int> arr) {
    cout << "Initial array:\n";
    printArray(arr);
    mergeSort(arr, 0, arr.size()-1);
    cout << "Sorted array:\n";
    printArray(arr);
}

// Quick Sort
void printArrayQuick(const vector<int>& arr, int pivot = -1, int i = -1, int j = -1) {
    for (int idx = 0; idx < arr.size(); ++idx) {
        if (idx == pivot) cout << "(" << arr[idx] << ") ";  // Pivot in ()
        else if (idx == i || idx == j) cout << "[" << arr[idx] << "] ";
        else cout << arr[idx] << " ";
    }
    cout << endl;
}
int partition(vector<int>& arr, int low, int high) {
    int pivotVal = arr[high];
    cout << "Partitioning with pivot (" << pivotVal << ")\n";
    printArrayQuick(arr, high);
    int i = low - 1;
    for (int j = low; j <= high-1; ++j) {
        cout << "Comparing " << arr[j] << " with pivot " << pivotVal << ": ";
        printArrayQuick(arr, high, i+1, j);
        if (arr[j] <= pivotVal) {
            i++;
            swap(arr[i], arr[j]);
            cout << "Swapped " << arr[i] << " and " << arr[j] << endl;
            printArrayQuick(arr, high, i, j);
        }
        cout << "Press Enter to continue.\n"; cin.get();
    }
    swap(arr[i+1], arr[high]);
    cout << "Swapped pivot to position " << i+1 << endl;
    printArrayQuick(arr, i+1);
    cout << "Press Enter to continue.\n"; cin.get();
    return i+1;
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
void quickSortStepByStep(vector<int> arr) {
    cout << "Initial array:\n";
    printArrayQuick(arr);
    quickSort(arr, 0, arr.size()-1);
    cout << "Sorted array:\n";
    printArrayQuick(arr);
}

// Universal Count Sort (for all integers)
void countSortStepByStep(vector<int> arr) {
    if (arr.empty()) { cout << "Array is empty.\n"; return; }
    int maxV = *max_element(arr.begin(), arr.end());
    int minV = *min_element(arr.begin(), arr.end());
    int range = maxV - minV + 1;
    vector<int> count(range, 0);

    cout << "Counting occurrences:\n";
    for (int v : arr) {
        count[v - minV]++;
        cout << "Incremented count for " << v << ": ";
        for (int k = 0; k < range; ++k) if (count[k]) cout << (k+minV) << ":" << count[k] << " ";
        cout << endl << "Press Enter.\n"; cin.get();
    }
    cout << "Building sorted array:\n";
    int idx = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i]--) {
            arr[idx++] = i + minV;
            printArray(arr, idx-1);
            cout << "Press Enter.\n"; cin.get();
        }
    }
    cout << "Sorted array:\n";
    printArray(arr);
}

// Universal Radix Sort (for all integers)
int getMaxAbs(const vector<int>& arr) {
    int mx = 0;
    for(int v : arr) if(abs(v) > mx) mx = abs(v);
    return mx;
}

void countSortRadixSigned(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);
    for (int i = 0; i < n; ++i)
        count[abs(arr[i])/exp % 10]++;
    for (int i = 1; i < 10; ++i)
        count[i] += count[i-1];
    for (int i = n-1; i >=0; --i) {
        int dig = abs(arr[i])/exp%10;
        output[--count[dig]] = arr[i];
    }
    for (int i = 0; i < n; ++i) arr[i] = output[i];
}

void radixSortStepByStep(vector<int> arr) {
    if (arr.empty()) { cout << "Array is empty.\n"; return; }
    // Separate negatives and non-negatives
    vector<int> neg, pos;
    for(int v : arr) {
        if(v < 0) neg.push_back(-v); // Store as positive for radix sort
        else pos.push_back(v);
    }
    int maxNeg = neg.empty() ? 0 : getMaxAbs(neg);
    int maxPos = pos.empty() ? 0 : getMaxAbs(pos);

    // Sort negatives
    for (int exp = 1; maxNeg/exp > 0; exp *= 10) {
        countSortRadixSigned(neg, exp);
        cout << "Negatives after exp " << exp << ": ";
        for (int x : neg) cout << -x << " "; cout << endl;
        cout << "Press Enter.\n"; cin.get();
    }
    // Sort positives
    for (int exp = 1; maxPos/exp > 0; exp *= 10) {
        countSortRadixSigned(pos, exp);
        cout << "Positives after exp " << exp << ": ";
        for (int x : pos) cout << x << " "; cout << endl;
        cout << "Press Enter.\n"; cin.get();
    }
    // Build result: reverse negatives (because -100 < -10), restore sign
    vector<int> result;
    for (int i = neg.size()-1; i >= 0; --i)
        result.push_back(-neg[i]);
    for (int x : pos)
        result.push_back(x);

    cout << "Sorted array:\n";
    printArray(result);
}

// Linear Search
void linearSearchStepByStep(const vector<int>& arr, int x) {
    cout << "Searching for " << x << ":\n";
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            if (j == i) cout << "[" << arr[j] << "] ";
            else cout << arr[j] << " ";
        }
        cout << " <- checking " << arr[i] << endl;
        if (arr[i] == x) {
            cout << "Found " << x << " at index " << i << endl; return;
        }
        cout << "Press Enter to continue.\n"; cin.get();
    }
    cout << x << " not found in array.\n";
}

// Binary Search
void binarySearchStepByStep(const vector<int>& arr, int x) {
    if (!is_sorted(arr.begin(), arr.end())) {
        cout << "Array is not sorted! Binary search aborted.\n";
        return;
    }
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        for (int i = 0; i < arr.size(); ++i) {
            if (i == mid) cout << "[" << arr[i] << "] ";
            else cout << arr[i] << " ";
        }
        cout << "   (l=" << l << ", mid=" << mid << ", r=" << r << ")" << endl;
        if (arr[mid] == x) {
            cout << "Found " << x << " at index " << mid << endl; return;
        } else if (arr[mid] < x) {
            cout << arr[mid] << " < " << x << ", searching right.\n";
            l = mid + 1;
        } else {
            cout << arr[mid] << " > " << x << ", searching left.\n";
            r = mid - 1;
        }
        cout << "Press Enter to continue.\n"; cin.get();
    }
    cout << x << " not found in array.\n";
}

// Main menu
void menu() {
    vector<int> array;
    int choice;
    while (true) {
        cout << "\n--- Algorithm Visualizer Menu ---\n";
        cout << "1. Input array manually\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Selection Sort\n";
        cout << "4. Insertion Sort\n";
        cout << "5. Merge Sort\n";
        cout << "6. Quick Sort\n";
        cout << "7. Count Sort\n";
        cout << "8. Radix Sort\n";
        cout << "9. Linear Search\n";
        cout << "10. Binary Search\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                array.clear();
                int n;
                cout << "Enter array length: ";
                cin >> n;
                cout << "Now enter " << n << " elements: ";
                array.resize(n);
                for (int i = 0; i < n; ++i) cin >> array[i];
                cin.ignore();
                cout << "Array set: "; printArray(array);
                break;
            }
            case 2: if(array.empty()) { cout << "Input an array first.\n"; break; }
                bubbleSortStepByStep(array); break;
            case 3: if(array.empty()) { cout << "Input an array first.\n"; break; }
                selectionSortStepByStep(array); break;
            case 4: if(array.empty()) { cout << "Input an array first.\n"; break; }
                insertionSortStepByStep(array); break;
            case 5: if(array.empty()) { cout << "Input an array first.\n"; break; }
                mergeSortStepByStep(array); break;
            case 6: if(array.empty()) { cout << "Input an array first.\n"; break; }
                quickSortStepByStep(array); break;
            case 7: if(array.empty()) { cout << "Input an array first.\n"; break; }
                countSortStepByStep(array); break;
            case 8: if(array.empty()) { cout << "Input an array first.\n"; break; }
                radixSortStepByStep(array); break;
            case 9: {
                if(array.empty()) { cout << "Input an array first.\n"; break; }
                int target; cout << "Enter number to search: "; cin >> target; cin.ignore();
                linearSearchStepByStep(array, target); break;
            }
            case 10: {
                if(array.empty()) { cout << "Input an array first.\n"; break; }
                int target; cout << "Enter number to search: "; cin >> target; cin.ignore();
                binarySearchStepByStep(array, target); break;
            }
            case 11: cout << "Exiting..." << endl; return;
            default: cout << "Invalid choice, try again.\n"; break;
        }
    }
}

int main() {
    menu();
    return 0;
}
