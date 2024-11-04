from typing import List
import sys

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