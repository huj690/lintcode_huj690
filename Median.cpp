/*
Given a unsorted array with integers, find the median of it. 

A median is the middle number of the array after it is sorted. 

If there are even numbers in the array, return the N/2-th number after sorted.

样例
Given [4, 5, 1, 2, 3], return 3

Given [7, 9, 4, 5], return 5

挑战
O(n) time.
*/
/*
找第K大的数，
1. 用快排划分的思想
2. 维护一个大小为K的小顶堆
*/


class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        if (nums.empty()) {
            return 0;
        }
        int begin = 0, end = nums.size() - 1;
        int median = nums.size() % 2 == 0 ? nums.size() / 2 - 1 : nums.size() / 2;
        while (1) {
            int pos = partition(nums, begin, end);
            if (pos == median) {
                break;
            } else if (pos < median) {
                begin = pos + 1;
            } else {
                end = pos - 1;
            }
        }
        return nums[median];
    }

private:
    int partition(vector<int> &nums, int begin, int end) {
        int i = begin, j = end;
        int key = nums[begin]; //begin is a keng
        while (i < j) {
            while (i < j && nums[j] > key) {
                j--;
            }
            if (i < j) {
                nums[i] = nums[j];
                i++;
            }
            while (i < j && nums[i] <= key) {
                i++;
            }
            if (i < j) {
                nums[j] = nums[i];
                j--;
            }
        }
        nums[i] = key;
        return i;
    }
};
