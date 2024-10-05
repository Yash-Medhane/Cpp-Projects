#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;

class SortingVisualizer {
public:
    void display(const vector<int>& arr) {
        for (int value : arr) {
            cout << value << " ";
        }
        cout << endl;
    }

    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
                display(arr);
                this_thread::sleep_for(chrono::milliseconds(500));
            }
        }
    }

    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
            display(arr);
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivot = arr[high];
            int i = low - 1;
            for (int j = low; j < high; ++j) {
                if (arr[j] < pivot) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);
            display(arr);
            this_thread::sleep_for(chrono::milliseconds(500));
            quickSort(arr, low, i);
            quickSort(arr, i + 2, high);
        }
    }

    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
            display(arr);
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
        for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
        display(arr);
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
};

int main() {
    SortingVisualizer visualizer;
    vector<int> arr = {5, 3, 8, 4, 2};
    int choice;

    while (true) {
        cout << "Choose a sorting algorithm:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Quick Sort\n";
        cout << "4. Selection Sort\n";
        cout << "5. Merge Sort\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) break;

        vector<int> tempArr = arr;
        switch (choice) {
            case 1:
                cout << "Bubble Sort Visualization:" << endl;
                visualizer.bubbleSort(tempArr);
                break;
            case 2:
                cout << "Insertion Sort Visualization:" << endl;
                visualizer.insertionSort(tempArr);
                break;
            case 3:
                cout << "Quick Sort Visualization:" << endl;
                visualizer.quickSort(tempArr, 0, tempArr.size() - 1);
                break;
            case 4:
                cout << "Selection Sort Visualization:" << endl;
                visualizer.selectionSort(tempArr);
                break;
            case 5:
                cout << "Merge Sort Visualization:" << endl;
                visualizer.mergeSort(tempArr, 0, tempArr.size() - 1);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
