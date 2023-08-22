# ifndef SORTING_SORTLIB_H
# define SORTING_SORTLIB_H
# include <iostream>
using namespace std ;

namespace Sortlib {
    template<typename Type>
    void insertionSort(Type arr[], int n) {
        Type k;
        int j;
        for (int i = 1; i < n; ++i) {
            k = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > k) {
                arr[j + 1] = arr[j];
                j -= 1;
            }
            arr[j + 1] = k;

        }
    }
    //---------------------------------------------

    template<typename Type>
    void selectionSort(Type arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            int Min_index = i;
            int j;

            for (j = i + 1; j < n; ++j) {
                if (arr[j] < arr[Min_index]) {
                    Min_index = j;
                }
            }
            swap(arr[i], arr[Min_index]);
        }
    }
    //---------------------------------------------

    template<typename Type>
    void bubbleSort(Type arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
    }
    //---------------------------------------------

    template<typename Type>
    void shellSort(Type arr[], int n) {
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int j = gap; j < n; ++j) {
                int Temp = arr[j];
                int k;

                for (k = j; k >= gap; k -= gap) {
                    if (arr[k - gap] > Temp) {
                        arr[k] = arr[k - gap];
                    } else {
                        break;
                    }
                }
                arr[k] = Temp;
            }
        }
    }
    //---------------------------------------------

    template<typename Type>
    void merge(Type arr[], int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
        Type arr1[n1];
        Type arr2[n2];

        for (i = 0; i < n1; ++i) {
            arr1[i] = arr[l + i];
        }
        for (j = 0; j < n2; ++j) {
            arr2[j] = arr[j + m + 1];
        }
        i = 0;
        j = 0;
        k = l;
        while ((i < n1) && (j < n2)) {
            if (arr1[i] < arr2[j]) {
                arr[k] = arr1[i];
                i++;
            }
            else {
                arr[k] = arr2[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = arr1[i];
            k++;
            i++;
        }
        while (j < n2) {
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }
    //---------------------------------------------

    template<typename Type>
    void mergeSort(Type arr[], int l, int r) {
        if (l >= r)
            return;
        else {
            int m = (l + r) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
    //---------------------------------------------

    void countSort(int arr[], int n) {
        int Max = *max_element(arr, arr + n);
        int C[Max + 1];
        int B[n];

        for (int i = 0; i <= Max; ++i) {
            C[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            ++C[arr[i]];
        }
        for (int i = 1; i <= Max; ++i) {
            C[i] += C[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            B[C[arr[i]] - 1] = arr[i];
            --C[arr[i]];
        }
        for (int i = 0; i < n; ++i) {
            arr[i] = B[i];
        }
    }
    //---------------------------------------------

    template<typename Type>
    int partition(Type arr[], int First, int Last) {
//        int Random = First + (rand() % (Last - First + 1));
//        swap(arr[Random], arr[First]);

        Type pivot = arr[First];
        int i = First ;

        for (int j = First + 1; j <= Last; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i], arr[First]);

        return i;
    }
    //---------------------------------------------

    template<typename Type>
    void quickSort(Type arr[], int First, int Last) {
        if (First >= Last) {
            return;
        } else {
            int pivot = partition(arr, First, Last);
            quickSort(arr, First, pivot - 1);
            quickSort(arr, pivot + 1, Last);
        }
    }
    //---------------------------------------------

    template<typename Type>
    void Print(Type arr[], int n) {
        cout << '{';
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) {
                cout << arr[i] << "}\n";
                break;
            }
            cout << arr[i] << ", ";
        }
    }
}

#endif //SORTING_SORTLIB_H