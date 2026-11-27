// Problem: Search Insert Position
// Approach: Use recursive binary search on a sorted array. If the target is found, return its index;
//           otherwise, when left > right, return 'left' as the exact insertion index.
// Time Complexity: O(log n)
// Space Complexity: O(log n) due to recursion call stack

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& nums, int left, int right, int target) {
    if (left > right) {
        return left;
    }

    int mid = left + (right - left) / 2;

    if (nums[mid] == target) {
        return mid;
    } else if (nums[mid] < target) {
        return binarySearch(nums, mid + 1, right, target);
    } else {
        return binarySearch(nums, left, mid - 1, target);
    }
}

int searchInsert(const vector<int>& nums, int target) {
    return binarySearch(nums, 0, static_cast<int>(nums.size()) - 1, target);
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    cout << "Insert index for " << target << ": " << searchInsert(nums, target) << endl;

    return 0;
}
