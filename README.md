# Minimum Jump Game Solutions

- ## Approach 1:- Brute Force using Recursion

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
        - In the worst case, the algorithm explores all possible combinations of jumps from each index. This can lead to an exponential number of calls, specifically __O(2<sup>n</sup>)__ for __n__ being the size of the array, since each index can lead to multiple branches of recursive calls.
        - However, with memoization, we can significantly reduce this to __(O(n<sup>2</sup>)__ because we are solving each subproblem once and storing the results.

    - ### Space Complexity
        - **Space for the call stack**: The maximum depth of the recursion will be __O(n)__ in the worst case, where the function calls itself for each index in the array.
        - **Space for memoization**: We need additional space to store the results of subproblems, which will be __O(n)__.
        - Therefore, the overall space complexity is __O(n)__.

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

- ## Approach 4:- Greedy
    
    - ### Intuition
        - The goal of the problem is to find the minimum number of jumps required to reach the last index of an array, where each element specifies the maximum jump length from that position. The intuition here is to think about how far we can go with each jump and to make strategic decisions about when to jump. By iterating through the reachable indices, we can continuously extend our range until we reach or surpass the last index.

        - Please checkout this explanation video by __NeetCode__ *(no paid promotion)* for reference:- [Jump Game II - Greedy - Leetcode 45 - Python](https://www.youtube.com/watch?v=dJ7sWiOoK7g)

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