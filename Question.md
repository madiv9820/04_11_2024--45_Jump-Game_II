# [45. Jump Game II](https://leetcode.com/problems/jump-game-ii?envType=study-plan-v2&envId=top-interview-150)

__Type:__ Medium <br>
__Topics:__ Array, Dynamic Programming, Greedy <br>
__Companies:__ Amazon, Google, Bloomberg, Meta, Microsoft, TikTok, Uber, Adobe, Apple, Oracle, Walmart Labs, DE Shaw, DoorDash, MakeMyTrip, Expedia, Flipkart <br>
<hr>

You are given a __0-indexed__ array of integers `nums` of length `n`. You are initially positioned at `nums[0]`.

Each element `nums[i]` represents the maximum length of a forward jump from index `i`. In other words, if you are at `nums[i]`, you can jump to any `nums[i + j]` where:

- `0 <= j <= nums[i]` and
- `i + j < n`

Return _the minimum number of jumps to reach_ `nums[n - 1]`. The test cases are generated such that you can reach `nums[n - 1]`.
<hr>

### Examples

- __Example 1:__ <br>
__Input:__ nums = [2,3,1,1,4] <br>
__Output:__ 2 <br>
__Explanation:__ The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

- __Example 2:__ <br>
__Input:__ nums = [2,3,0,1,4] <br>
__Output:__ 2
<hr>

### Constraints

- <code>1 <= nums.length <= 10<sup>4</sup></code>
- `0 <= nums[i] <= 1000`
- It's guaranteed that you can reach `nums[n - 1]`.