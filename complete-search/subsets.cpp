// Problem: Subsets (Complete Search / Backtracking)
// Approach: Explore all 2^n subsets by branching at each index into excluding nums[indx]
//           and including nums[indx] (backtracking with pop_back()).
// Time Complexity: O(n * 2^n)
// Space Complexity: O(n) auxiliary space (excluding output)

#include <iostream>
#include <vector>
using namespace std;

class SubsetGenerator {
public:
    void generateSubsets(int indx, vector<int>& subset, vector<vector<int>>& res, const vector<int>& nums) {
        if (indx == static_cast<int>(nums.size())) {
            res.push_back(subset);
            return;
        }

        // Exclude current element
        generateSubsets(indx + 1, subset, res, nums);

        // Include current element
        subset.push_back(nums[indx]);
        generateSubsets(indx + 1, subset, res, nums);
        subset.pop_back(); // Backtrack
    }

    vector<vector<int>> subsets(const vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        generateSubsets(0, subset, res, nums);
        return res;
    }
};

int main() {
    SubsetGenerator sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
