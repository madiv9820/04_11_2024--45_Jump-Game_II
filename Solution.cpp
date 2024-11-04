#include <iostream>
#include <vector>
#include <functional>
#include <climits>
using namespace std;

class Solution {
    public:
        int jump(vector<int> nums) {
            int n = nums.size();  // Get the size of the input vector

            // Define a lambda function to find the minimum jumps recursively
            function<int(int)> find_Minimum_Jump = [&](int index) -> int {
                // Base case: If the index exceeds the last element, return a large number
                if (index >= n) return INT_MAX;

                // Base case: If we are at the last index, no jumps are needed
                if (index == n - 1) return 0;

                int minimum_Jumps = INT_MAX;  // Initialize minimum jumps to a large number
                
                // Loop through the possible steps from the current index
                for (int steps = 1; steps <= nums[index]; ++steps) {
                    // Recursively find the minimum jumps needed from the next position
                    minimum_Jumps = min(minimum_Jumps, find_Minimum_Jump(index + steps));
                }
                
                // Increment the minimum jumps if it's not the initial maximum
                if (minimum_Jumps != INT_MAX) ++minimum_Jumps;

                return minimum_Jumps;  // Return the minimum jumps found
            };

            return find_Minimum_Jump(0);  // Start the recursive function from index 0
        }
};

int main() {
    vector<int> nums; int input; Solution sol;
    cin >> input;

    while(input != -1) {
        nums.emplace_back(input);
        cin >> input;
    }

    cout << sol.jump(nums = nums) << endl;
}