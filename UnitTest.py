from Solution import Solution
import unittest
from timeout_decorator import timeout

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testCases = {1: ([2,3,1,1,4], 2), 2: ([2,3,0,1,4], 2)}
        self.__obj = Solution()
        return super().setUp()
    
    @timeout(0.5)
    def test_Case1(self):
        nums, output = self.__testCases[1]
        result = self.__obj.jump(nums = nums)
        self.assertIsInstance(result, int)
        self.assertEqual(result, output)
    
    @timeout(0.5)
    def test_Case2(self):
        nums, output = self.__testCases[2]
        result = self.__obj.jump(nums = nums)
        self.assertIsInstance(result, int)
        self.assertEqual(result, output)

if __name__ == '__main__': unittest.main()