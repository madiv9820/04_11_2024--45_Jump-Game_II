- ## Approach 3:- Dynamic Programming

    - ### Intuition
        - The problem requires finding the minimum number of jumps needed to reach the last index of an array where each element indicates the maximum jump length from that position. The intuition behind the solution is to work backwards from the last index to the first. By calculating the minimum jumps required for each index, we can determine the number of jumps needed to reach the last index from the first index. This method efficiently utilizes previous results to minimize calculations.

    - ### Approach
        1. **Dynamic Programming**:
            - We use a dynamic programming approach where we create a `minimum_Jumps_For_Each_Index` array. This array will store the minimum jumps needed to reach the end from each index.

        2. **Initialization**:
            - We initialize the last index of the array to `0`, as no jumps are required to reach the end from the last position. All other indices are initialized to `INT_MAX`, representing an initially unknown and large number of jumps.

        3. **Backward Iteration**:
            - We iterate from the second-to-last index down to the first index. For each index:
                - We check all possible jumps from that index (from 1 up to the value at that index).
                - For each potential jump, we check the corresponding position (`index + steps`).
                - We update the minimum jumps needed based on the values already computed for the next indices.

        4. **Result**:
            - After processing all indices, the value at `minimum_Jumps_For_Each_Index[0]` will contain the minimum jumps needed to reach the last index from the first index.

    - ### Time Complexity
        - The time complexity of this approach is __O(n<sup>2</sup>)__. This is because for each index (in the worst case), we may have to check all possible steps from that index, leading to a nested iteration over the length of the array.

    - ### Space Complexity
        - The space complexity is __O(n)__. This is due to the `minimum_Jumps_For_Each_Index` array, which stores the minimum jumps for each index. We do not use any additional space that grows with the input size beyond this array.

    - ### Code
        - **Python Solution**
            ```python3 []
            class Solution:
                def jump(self, nums: List[int]) -> int:
                    n = len(nums)  # Get the length of the input list
                    minimum_Jumps_For_Each_Index = [sys.maxsize] * n  # Initialize the jumps array with large values
                    minimum_Jumps_For_Each_Index[n-1] = 0  # No jumps needed from the last index

                    # Iterate from the second last index to the first index
                    for index in range(n-2, -1, -1):
                        minimum_Jumps = sys.maxsize  # Initialize the minimum jumps for the current index
                        
                        # Loop through all possible steps from the current index
                        for steps in range(1, nums[index] + 1):
                            # Ensure we don't go out of bounds
                            if index + steps < n:
                                # Update the minimum jump needed to reach the end from the next index
                                minimum_Jumps = min(minimum_Jumps, minimum_Jumps_For_Each_Index[index + steps])
                        
                        # If a valid minimum jump count was found, increment it by one for the current jum
                        if minimum_Jumps != sys.maxsize: minimum_Jumps += 1

                        # Store the minimum jumps needed for the current index (plus one for the current jump)
                        minimum_Jumps_For_Each_Index[index] = minimum_Jumps

                    # Return the minimum jumps needed from the first index
                    return minimum_Jumps_For_Each_Index[0]
            ```
        - **C++ Solution**
            ```C++ []
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
            ```