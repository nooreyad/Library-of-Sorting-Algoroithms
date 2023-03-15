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
}

int random(int min, int max)
{
   return min + rand() % (( max + 1 ) - min);
}

template<class T>
void generate(T data[], int n){
    for(int i = 0; i < n; i++){
        data[i] = random('A', 'z');
    }
}


using namespace sortlib;
using namespace std::chrono;
int main(){
    // generating an array of length 200
    char arr1[200];
    generate(arr1, 200); 
    auto start = high_resolution_clock::now();
    selectionSort(arr1, 200);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for selection sort to sort an array of 200: " << duration.count() << " microseconds\n";

    // generating an array of length 500
    char arr2[500];
    generate(arr2, 500); 
    start = high_resolution_clock::now();
    selectionSort(arr2, 500);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for selection sort to sort an array of 500: " << duration.count() << " microseconds\n";
    
    // generating an array of length 1000
    char arr3[1000];
    generate(arr3, 1000);
    start = high_resolution_clock::now();
    selectionSort(arr3, 1000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for selection sort to sort an array of 1000: " << duration.count() << " microseconds\n";

    // generating an array of length 5000
    char arr4[5000];
    generate(arr4, 5000);
    start = high_resolution_clock::now();
    selectionSort(arr4, 5000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for selection sort to sort an array of 5000: " << duration.count() << " microseconds\n";

    // generating an array of length 10000
    char arr5[10000];
    generate(arr5, 10000);
    start = high_resolution_clock::now();
    selectionSort(arr5, 10000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for selection sort to sort an array of 10000: " << duration.count() << " microseconds\n";

    // generating an array of length 20000
    char arr6[20000];
    generate(arr6, 20000);
    start = high_resolution_clock::now();
    selectionSort(arr6, 20000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for selection sort to sort an array of 20000: " << duration.count() << " microseconds\n";

    // generating an array of length 50000
    char arr7[50000];
    generate(arr7, 50000);
    start = high_resolution_clock::now();
    selectionSort(arr7, 50000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for selection sort to sort an array of 50000: " << duration.count() << " microseconds\n";
    return 0;
}