- ## Approach 4:- Greedy

    - ### Intuition
        - The goal of the problem is to find the minimum number of jumps required to reach the last index of an array, where each element specifies the maximum jump length from that position. The intuition here is to think about how far we can go with each jump and to make strategic decisions about when to jump. By iterating through the reachable indices, we can continuously extend our range until we reach or surpass the last index.

        - Please checkout this video for reference:- [Jump Game II - Greedy - Leetcode 45 - Python](https://www.youtube.com/watch?v=dJ7sWiOoK7g)

    - ### Approach
        1. **Greedy Algorithm**:
            - We use a greedy approach where we keep track of two pointers: `left_Ptr` and `right_Ptr`. 
            - The `right_Ptr` defines the current farthest point we can reach with the current number of jumps, while `left_Ptr` marks the beginning of the range we are currently evaluating for the next jump.

        2. **Initialization**:
            - We start with both pointers at the beginning of the array and initialize a counter `minimum_Jumps` to zero.

        3. **Iterate Until the Last Index**:
            - We loop until `right_Ptr` is less than `n - 1` (the last index).
            - For each position from `left_Ptr` to `right_Ptr`, we calculate the farthest distance that can be reached based on the jump lengths available at each index.
            - After determining the farthest distance we can cover in this jump, we update `left_Ptr` to `right_Ptr + 1` (moving to the next range) and set `right_Ptr` to the farthest distance we can reach.

        4. **Increment Jump Count**:
            - Each time we complete a range check (from `left_Ptr` to `right_Ptr`), we increment the `minimum_Jumps` counter, indicating that we've made a jump.

        5. **Result**:
            - Once the loop completes, `minimum_Jumps` will contain the minimum number of jumps required to reach the last index.

    - ### Time Complexity
        - The time complexity of this approach is __O(n)__. In the worst case, each index is visited once when extending the range of reachable indices, making the traversal linear.

    - ### Space Complexity
        - The space complexity is __O(1)__. We only use a fixed amount of extra space for the pointers and the jump counter, regardless of the size of the input array. No additional data structures are required that grow with the input size.

    - ### Code
        - **Python Solution**
            ```python3 []
            class Solution:
                def jump(self, nums: List[int]) -> int:
                    n = len(nums)  # Get the length of the input list
                    left_Ptr = right_Ptr = minimum_Jumps = 0  # Initialize pointers and jump count

                    # While we haven't reached the last index
                    while right_Ptr < n - 1:
                        farthest_Distance_Covered = 0  # Reset the farthest distance covered in this jump
                        
                        # Iterate through the current range of indices we can jump from
                        for index in range(left_Ptr, right_Ptr + 1):
                            # Calculate the farthest distance that can be reached from the current index
                            farthest_Distance_Covered = max(farthest_Distance_Covered, index + nums[index])

                        # Move the left pointer to the next range (after the current right pointer)
                        left_Ptr = right_Ptr + 1
                        
                        # Update the right pointer to the farthest distance we can reach
                        right_Ptr = farthest_Distance_Covered
                        
                        # Increment the count of jumps
                        minimum_Jumps += 1

                    return minimum_Jumps  # Return the total number of jumps needed
            ```
        - **C++ Solution**
            ```C++ []
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
            ```