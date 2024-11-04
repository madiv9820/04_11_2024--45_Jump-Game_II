#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
        int jump(vector<int> nums) {
            int n = nums.size();  // Get the size of the input vector
            vector<int> minimum_Jumps_For_Each_Index(n, INT_MAX);  // Initialize the jumps array with large values
            minimum_Jumps_For_Each_Index[n-1] = 0;  // No jumps needed from the last index

            // Iterate from the second last index to the first index
            for(int index = n-2; index >= 0; --index) {
                int minimum_Jumps = INT_MAX;  // Initialize the minimum jumps for the current index
                
                // Loop through all possible steps from the current index
                for(int steps = 1; steps <= nums[index]; ++steps) {
                    // Ensure we don't go out of bounds
                    if(index + steps < n) {
                        // Update the minimum jump needed to reach the end from the next index
                        minimum_Jumps = min(minimum_Jumps, minimum_Jumps_For_Each_Index[index + steps]);
                    }
                }

                // If a valid minimum jump count was found, increment it by one for the current jum
                if(minimum_Jumps != INT_MAX) ++minimum_Jumps;

                // Store the minimum jumps needed for the current index (plus one for the current jump)
                minimum_Jumps_For_Each_Index[index] = minimum_Jumps;
            }

            // Return the minimum jumps needed from the first index
            return minimum_Jumps_For_Each_Index[0];
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