
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;


int RandomPivot(int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    return randomIndex;
}

int MiddleElementPivot (int low, int high) {
    int mid = low + (high - low )/2;
    return mid;
}

int medianOfMediansPivot(vector<int>& arr, int low, int high) {
    if (high - low < 5) {
        sort(arr.begin() + low, arr.begin() + high + 1);
        return (low + high) / 2;
    }

    int subRight = low - 1;
    for (int i = low; i <= high; i += 5) {
        int subEnd = min(i + 4, high);
        sort(arr.begin() + i, arr.begin() + subEnd + 1);
        subRight++;
        swap(arr[subRight], arr[(i + subEnd) / 2]);
    }

    return medianOfMediansPivot(arr, low, subRight);
}

//Random pivot
int partition(vector<int>& arr, int low, int high) {
    // Elegimos un indice aleatorio entre low y high
    int index = medianOfMediansPivot(arr,low, high);
    swap(arr[index], arr[high]);
    //int pivot = arr[high];  // Usamos el último elemento como pivote
    
    int pivot = arr[high];
    int i = low - 1;  

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {  
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high); 
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);

    cout << "Array ordenado: ";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";
    return 0;
}
