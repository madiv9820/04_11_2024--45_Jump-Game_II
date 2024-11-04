- ## Brute Force using Recursion

    - ### Intuition
        - The problem is about finding the minimum number of jumps needed to reach the last index of an array where each element represents the maximum jump length from that position. The core idea is to explore how far you can jump from each index and to count the minimum number of jumps required to reach the end.

    - ### Approach
        1. **Recursive DFS with Memoization**:
            - We define a recursive function that calculates the minimum number of jumps required to reach the end from a given index.
            - For each position, we explore all possible jumps (from 1 up to the value of the current index) and recursively calculate the number of jumps required for each reachable position.
            - To avoid recalculating results for previously visited indices, we can use memoization (caching results of subproblems).

        2. **Base Cases**:
            - If the current index exceeds the last index, return a large number (indicating that it's not a valid path).
            - If the current index is the last index, return 0 (no jumps needed).

        3. **Calculate Minimum Jumps**:
            - For each possible jump from the current index, compute the total jumps by calling the function recursively for the next indices.
            - Keep track of the minimum jumps needed.

    - ### Time Complexity
        - In the worst case, the algorithm explores all possible combinations of jumps from each index. This can lead to an exponential number of calls, specifically \(O(2^n)\) for \(n\) being the size of the array, since each index can lead to multiple branches of recursive calls.
        - However, with memoization, we can significantly reduce this to \(O(n^2)\) because we are solving each subproblem once and storing the results.

    - ### Space Complexity
        - **Space for the call stack**: The maximum depth of the recursion will be \(O(n)\) in the worst case, where the function calls itself for each index in the array.
        - **Space for memoization**: We need additional space to store the results of subproblems, which will be \(O(n)\).
        - Therefore, the overall space complexity is \(O(n)\).

    - ### Code
        - **Python Solution** 
            ```python3 []
            class Solution:
                def jump(self, nums: List[int]) -> int:
                    n = len(nums)  # Get the length of the input list

                    def find_Minimum_Jumps(index: int = 0) -> int:
                        # Base case: If index is beyond the last element, return a large number
                        if index >= n:
                            return sys.maxsize

                        # Base case: If we're at the last index, no jumps are needed
                        if index == n - 1:
                            return 0
                        
                        minimum_Jumps = sys.maxsize  # Initialize minimum jumps to a large number
                        
                        # Loop through the possible steps from the current index
                        for steps in range(1, nums[index] + 1):
                            # Recursively find the minimum jumps needed from the next position
                            minimum_Jumps = min(minimum_Jumps, find_Minimum_Jumps(index + steps))

                        # Increment the minimum jumps if it's not the initial maximum
                        if minimum_Jumps != sys.maxsize: minimum_Jumps += 1

                        return minimum_Jumps  # Return the minimum jumps found
                    
                    return find_Minimum_Jumps()  # Start the recursive function from index 0
            ```
        - **C++ Solution** 
            ```C++ []
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
            ```