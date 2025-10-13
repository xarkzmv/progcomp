#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

std::vector<int> sortArray(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());  // std::sort de la STL
    return arr;
}

int main () {

    std::vector <int> nums = {4, 10, 15, 22, 6, 20, 21, 2, 11, 1, 18, 19, 5, 29, 26, 16, 23, 9, 25, 8, 14, 30, 12, 13, 24, 27, 17, 28, 3, 7};
    sortArray(nums);

    for(auto x : nums) cout << x << " ";
    cout << "\n";
    return 0;
}