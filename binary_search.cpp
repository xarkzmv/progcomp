#include <iostream>
#include <vector>
using namespace std;

//necesita de un arreglo ordenado
int binarySearch (vector <int> A, int key, int low , int high) {
    if(low > high) return -1;
    int mid = (low + high)/2;
    if (key == A[mid]) return mid;
    else if (key < A[mid]) return binarySearch(A,key, low, mid-1);
    else return binarySearch(A,key, mid+1, high);
}


int main () {

    vector <int> A = {2,4,6,8,10,12,14};
    
    cout << binarySearch(A,10,0,6) << endl;

    
    return 0;
}