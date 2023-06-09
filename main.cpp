#include <bits/stdc++.h>

using namespace std;

namespace sortlib{
    // Bubble Sort
    template <class T>
    void bubbleSort(T data[], int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-1; j++){
                if(data[j] > data[j+1]) std::swap(data[j], data[j+1]);
            }
        }
    }

    // Insertion Sort
    template<typename T>
    void insertionSort(T arr[], int n){
        for (int i=1; i < n; i++){
            int j=i;
            while (j > 0 && arr[j-1] > arr[j]){
                swap(arr[j], arr[j-1]);
                j--;
            }
        }
    }

    // Merge Sort
    template<typename T>
    void merge(int left, int right, int mid, T arr[]){
        int size1 = mid - left + 1;
        int size2 = right - mid;

        T arr1[size1];
        T arr2[size2];

        for (int i=0; i < size1; i++)
            arr1[i] = arr[left+i];
        for (int i=0; i < size2; i++)
            arr2[i] = arr[mid+1+i];

        int index1 = 0;
        int index2 = 0;
        int indexMerge = left;

        while (index1 < size1 && index2 < size2){
            if (arr1[index1] <= arr2[index2]){
                arr[indexMerge] = arr1[index1];
                index1++;
            }
            else{
                arr[indexMerge] = arr2[index2];
                index2++;
            }
            indexMerge++;
        }

        while(index1 < size1){
            arr[indexMerge] = arr1[index1];
            index1++;
            indexMerge++;
        }

        while (index2 < size2){
            arr[indexMerge] = arr2[index2];
            index2++;
            indexMerge++;
        }
    }

    template<typename T>
    void mergeSort(T arr[], int start, int end){
        if (start >= end)
            return;
        int mid = start + (end - start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(start, end, mid, arr);
    }

    // Selection Sort
    template<class T>
    void selectionSort(T data[], int n){
        for(int i = 0; i < n-1; i++){
            int minIndex = i;
            for(int j = i+1; j < n; j++){
                if(data[minIndex] > data[j]) minIndex = j;
            }
            swap(data[i], data[minIndex]);
        }
    }

    // Quick Sort
    template <typename T>
    int partition(int low, int high, T A[]){
        // take the first element as pivot
        int i, j;
        T pivot = A[low];
        i = low;
        j = high + 1;
        do{
            do{i++;} while(A[i] <= pivot && i <= high);
            do{j--;} while(A[j] > pivot);
            if(i < j)
                swap(A[i], A[j]);
        }while(i < j);
        swap(A[low], A[j]);
        return j;
    }
    
    template <typename T>
    void quickSort(int low, int high, T A[]){
        if(low < high){
            int j = partition(low, high, A);
            quickSort(low, j-1, A);
            quickSort(j+1, high, A);
        }
    }
    
    // Count Sort
    template <typename T>
    void countSort(T A[], int n){
        T max = *max_element(A, A + n);
        T min = *min_element(A, A + n);
        int countArrSize = max - min + 1;
        int* countArr = new int[countArrSize];

        for (int i = 0; i < countArrSize; i++) {
            countArr[i] = 0;
        }
        for (int i = 0; i < n; i++){
            countArr[A[i] - min]++;
        }
        int countArrIndex = 0;
        int arrIndex = 0;

        while (arrIndex < n){
            if (countArr[countArrIndex] > 0){
                A[arrIndex] = countArrIndex + min;
                arrIndex++;
                countArr[countArrIndex]--;
            }
            else{
                countArrIndex++;
            }
        }
        delete[] countArr;
    }

    // Shell sort
    template<typename T>
    void shellSort(T data[], const int n){
        for(int diff = n/2; diff > 0; diff/=2){
            for(int i = diff; i < 2*diff; i++){
                for(int j = i; j < n; j+=diff){
                    T tmp = data[j];
                    int k;
                    for(k = j; k-diff >= 0 && tmp < data[k-diff]; k-= diff){
                        data[k] = data[k-diff];
                    }
                    data[k] = tmp;
                }
            }
        }
    }
}

int random(int min, int max)
{
   return min + rand() % (( max + 1 ) - min);
}

template<class T>
void generate(T data[], int n){
    for(int i = 0; i < n; i++){
        data[i] = random(0, 100000);
    }
}

template<class T> 
void printArr(T arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

using namespace sortlib;
using namespace std::chrono;
int main(){
    // generating an array of length 200
    int arr1[200];
    generate(arr1, 200); 
    auto start = high_resolution_clock::now();
    bubbleSort(arr1,  200);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for bubble sort to sort an array of 200: " << duration.count() << " microseconds\n";
    std::cout << "The first 20 elements are: ";
    printArr(arr1, 20);

    // generating an array of length 500
    int arr2[500];
    generate(arr2, 500); 
    start = high_resolution_clock::now();
    insertionSort(arr2, 500);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for insertion sort to sort an array of 500: " << duration.count() << " microseconds\n";
    std::cout << "The first 20 elements are: ";
    printArr(arr2, 20);
    
    // generating an array of length 1000
    int arr3[1000];
    generate(arr3, 1000);
    start = high_resolution_clock::now();
    selectionSort(arr3, 1000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for selection sort to sort an array of 1000: " << duration.count() << " microseconds\n";
    std::cout << "The first 20 elements are: ";
    printArr(arr3, 20);

    // generating an array of length 5000
    int arr4[5000];
    generate(arr4, 5000);
    start = high_resolution_clock::now();
    quickSort(0, 5000, arr4);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for quick sort to sort an array of 5000: " << duration.count() << " microseconds\n";
    std::cout << "The first 20 elements are: ";
    printArr(arr4, 20);

    // generating an array of length 10000
    int arr5[10000];
    generate(arr5, 10000);
    start = high_resolution_clock::now();
    countSort(arr5, 10000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for count sort to sort an array of 10000: " << duration.count() << " microseconds\n";
    std::cout << "The first 20 elements are: ";
    printArr(arr5, 20);

    // generating an array of length 20000
    int arr6[20000];
    generate(arr6, 20000);
    start = high_resolution_clock::now();
    shellSort(arr6, 20000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for shell sort to sort an array of 20000: " << duration.count() << " microseconds\n";
    std::cout << "The first 20 elements are: ";
    printArr(arr6, 20);

    // generating an array of length 50000
    int arr7[50000];
    generate(arr7, 50000);
    start = high_resolution_clock::now();
    mergeSort(arr7,0, 50000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for merge sort to sort an array of 50000: " << duration.count() << " microseconds\n";
    std::cout << "The first 20 elements are: ";
    printArr(arr7, 20);

    return 0;
}
