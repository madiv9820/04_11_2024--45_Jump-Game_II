#include <iostream>
#include <vector>
#include <functional>
#include <climits>
using namespace std;

class Solution {
    public:
        int jump(vector<int> nums) {
            int n = nums.size();  // Get the size of the input vector
            vector<int> cache(n, -1);  // Initialize a cache to store results of subproblems

            // Define a lambda function to find the minimum jumps recursively
            function<int(int)> find_Minimum_Jump = [&](int index) -> int {
                // Base case: If the index exceeds the last element, return a large number
                if (index >= n) return INT_MAX;  // This indicates an invalid path

                // Base case: If we are at the last index, no jumps are needed
                if (index == n - 1) return 0;

                // Check if the result for this index has already been computed
                if (cache[index] == -1) {
                    int minimum_Jumps = INT_MAX;  // Initialize minimum jumps to a large number
                    
                    // Loop through the possible steps from the current index
                    for (int steps = 1; steps <= nums[index]; ++steps) {
                        // Recursively find the minimum jumps needed from the next position
                        minimum_Jumps = min(minimum_Jumps, find_Minimum_Jump(index + steps));
                    }
                    
                    // If a valid minimum jump count was found, increment it by one for the current jump
                    if (minimum_Jumps != INT_MAX) ++minimum_Jumps;

                    // Store the computed minimum jumps in the cache for future reference
                    cache[index] = minimum_Jumps;  
                }

                // Return the cached result for the current index
                return cache[index];  
            };

            // Start the recursive function from the first index (0)
            return find_Minimum_Jump(0);  
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