from typing import List
import sys

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