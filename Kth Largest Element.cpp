/*
Kth Largest Element
Find K-th largest element in an array.

Note
You can swap elements in the array

Example
In array [9,3,2,4,8], the 3th largest element is 4

Challenge
O(n) time, O(1) space
*/

/*
找第K大的数
*/
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        if (nums.empty()) {
            return 0;
        }
        int begin = 0, end = nums.size() - 1;
        int k_index = nums.size() - k;
        int pos = -1;
        while (k_index != pos) {
            pos = partition(nums, begin, end);
            if (k_index < pos) {
                end = pos - 1;
            } else {
                begin = pos + 1;
            }
        }
        return nums[k_index];
    }
    
private:
    int partition(vector<int> &nums, int begin, int end) {
        int key = nums[begin], i = begin, j = end;
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

