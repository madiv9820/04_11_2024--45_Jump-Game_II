#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int jump(vector<int> nums) {
            int n = nums.size();  // Get the size of the input vector
            int left_Ptr = 0, right_Ptr = 0, minimum_Jumps = 0;  // Initialize pointers and jump count
            
            // While we haven't reached the last index
            while (right_Ptr < n - 1) {
                int farthest_Distance_Covered = 0;  // Reset the farthest distance covered for this jump
                
                // Iterate through the current range of indices we can jump from
                for (int index = left_Ptr; index <= right_Ptr; ++index) {
                    // Calculate the farthest distance that can be reached from the current index
                    farthest_Distance_Covered = max(farthest_Distance_Covered, index + nums[index]);
                }

                // Move the left pointer to the next range (after the current right pointer)
                left_Ptr = right_Ptr + 1;
                
                // Update the right pointer to the farthest distance we can reach
                right_Ptr = farthest_Distance_Covered;
                
                // Increment the count of jumps
                ++minimum_Jumps;
            }

            return minimum_Jumps;  // Return the total number of jumps needed
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