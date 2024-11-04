- ## Approach 2:- Memoization

    - ### Intuition
        - The goal is to find the minimum number of jumps needed to reach the last index of an array, where each element indicates the maximum jump length from that position. The intuition is to explore the different paths you can take from each index and choose the path that minimizes the number of jumps. Since each jump can lead to multiple subsequent jumps, a recursive approach is suitable to explore these options efficiently.

    - ### Approach
        1. **Recursive Function with Memoization**:
            - We define a recursive function that takes an index as input and returns the minimum jumps required to reach the last index from that position.
            - For each index, we can jump to any index within the range defined by the value at the current index. We recursively call our function for all possible next positions.

        2. **Base Cases**:
            - If the index is out of bounds (greater than or equal to the size of the array), we return a large value (indicating an invalid path).
            - If the index is the last index, we return 0, as no jumps are needed.

        3. **Cache Results**:
            - To optimize the recursive approach, we use a cache (memoization) to store the results of previously computed indices. This prevents redundant calculations and speeds up the algorithm.
            - Before calculating the minimum jumps for an index, we check if it has already been computed. If it has, we return the cached value.

        4. **Calculate Minimum Jumps**:
            - We loop through all possible jumps from the current index (up to the value at that index) and recursively compute the minimum jumps needed for each possible next index.
            - After determining the minimum jumps from all valid paths, we store the result in the cache.

    - ### Time Complexity
        - In the worst case, the recursive function can explore multiple paths, leading to an exponential number of calls. However, using memoization reduces this complexity significantly.
        - The time complexity is effectively __O(n<sup>2</sup>)__ in this implementation, where __n__ is the length of the input array. This is because for each index, we may potentially check every jump, and the recursive calls are cached.

    - ### Space Complexity
        - **Space for Cache**: We maintain a cache to store results for each index, which requires __O(n)__ space.
        - **Space for Call Stack**: The maximum depth of the recursion is __O(n)__ in the worst case if the jumps are minimal.
        - Therefore, the overall space complexity is __O(n)__ due to both the cache and the recursive call stack.

    - ### Code
        - **Python Solution**
            ```python3 []
            class Solution:
                def jump(self, nums: List[int]) -> int:
                    n = len(nums)  # Get the length of the input list
                    cache = [-1] * n  # Initialize a cache to store results of subproblems

                    def find_Minimum_Jumps(index: int = 0) -> int:
                        # Base case: If index is beyond the last element, return a large number
                        if index >= n:
                            return sys.maxsize  # This indicates that this path is not valid
                        
                        # Base case: If we're at the last index, no jumps are needed
                        if index == n - 1:
                            return 0
                        
                        # Check if the result for this index has already been computed
                        if cache[index] == -1:
                            minimum_Jumps = sys.maxsize  # Initialize minimum jumps to a large number
                            
                            # Loop through all possible jump lengths from the current index
                            for steps in range(1, nums[index] + 1):
                                # Recursively calculate the minimum jumps needed from the next position
                                next_index = index + steps  # Calculate the next index after jumping
                                minimum_Jumps = min(minimum_Jumps, find_Minimum_Jumps(next_index))

                            # If a valid minimum jump count was found, increment it by one for the current jump
                            if minimum_Jumps != sys.maxsize:
                                minimum_Jumps += 1

                            # Store the computed minimum jumps in the cache for future reference
                            cache[index] = minimum_Jumps  
                        
                        # Return the cached result for the current index
                        return cache[index]  
                    
                    # Start the recursive function from the first index (0)
                    return find_Minimum_Jumps()  
            ```

        - **C++ Solution**
            ```C++ []
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
            ```