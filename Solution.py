from typing import List

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