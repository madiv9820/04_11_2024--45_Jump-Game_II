from typing import List
import sys

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