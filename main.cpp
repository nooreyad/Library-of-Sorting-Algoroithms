#include <bits/stdc++.h>

namespace sortlib{
    template <class T>
    void bubbleSort(T data[], int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-1; j++){
                if(data[j] > data[j+1]) std::swap(data[j], data[j+1]);
            }
        }
    }
}

int random(int min, int max)
{
   return min + rand() % (( max + 1 ) - min);
}

using namespace sortlib;
using namespace std::chrono;
int main(){
    // generating an array of length 200
    char arr1[200];
    for(int i = 0; i < 200; i++){
        arr1[i] = random('A', 'z');
    }
    auto start = high_resolution_clock::now();
    bubbleSort(arr1, 200);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for bubble sort to sort an array of 200: " << duration.count() << " microseconds\n";

    // generating an array of length 500
    char arr2[500];
    for(int i = 0; i < 500; i++){
        arr2[i] = random('A', 'z');
    }
    start = high_resolution_clock::now();
    bubbleSort(arr2, 500);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for bubble sort to sort an array of 500: " << duration.count() << " microseconds\n";
    
    // generating an array of length 1000
    char arr3[1000];
    for(int i = 0; i < 1000; i++){
        arr3[i] = random('A', 'z');
    }
    start = high_resolution_clock::now();
    bubbleSort(arr3, 1000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for bubble sort to sort an array of 1000: " << duration.count() << " microseconds\n";

    // generating an array of length 5000
    char arr4[5000];
    for(int i = 0; i < 5000; i++){
        arr4[i] = random('A', 'z');
    }
    start = high_resolution_clock::now();
    bubbleSort(arr4, 5000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for bubble sort to sort an array of 5000: " << duration.count() << " microseconds\n";

    // generating an array of length 10000
    char arr5[10000];
    for(int i = 0; i < 10000; i++){
        arr5[i] = random('A', 'z');
    }
    start = high_resolution_clock::now();
    bubbleSort(arr5, 10000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for bubble sort to sort an array of 10000: " << duration.count() << " microseconds\n";

    // generating an array of length 20000
    char arr6[20000];
    for(int i = 0; i < 20000; i++){
        arr6[i] = random('A', 'z');
    }
    start = high_resolution_clock::now();
    bubbleSort(arr6, 20000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for bubble sort to sort an array of 20000: " << duration.count() << " microseconds\n";

    // generating an array of length 50000
    char arr7[50000];
    for(int i = 0; i < 50000; i++){
        arr7[i] = random('A', 'z');
    }
    start = high_resolution_clock::now();
    bubbleSort(arr7, 50000);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time took for bubble sort to sort an array of 50000: " << duration.count() << " microseconds\n";
    return 0;
}