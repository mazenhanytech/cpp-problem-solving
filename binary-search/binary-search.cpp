// Problem: Binary Search (Recursive)
// Approach: Repeatedly halve the search interval on a sorted array using mid = left + (right - left) / 2
//           until the target is found or the search space becomes empty.
// Time Complexity: O(log n)
// Space Complexity: O(log n) due to recursion call stack

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int left, int right, int target) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, right, target);
    }
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 7;

    int result = binarySearch(arr, 0, static_cast<int>(arr.size()) - 1, target);

    if (result != -1) {
        cout << "The item exists at index: " << result << endl;
    } else {
        cout << "The item does not exist!" << endl;
    }

    return 0;
}
