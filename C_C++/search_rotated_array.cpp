// https://leetcode.com/explore/learn/card/binary-search/125/template-i/952/

class Solution {
    int bin_search(vector<int>& asc_nums, int lo, int hi, int target) {
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            
            if (asc_nums[mid] == target) {
                return mid;
            }
            else if (asc_nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int lo, int hi, int target) {
        if (lo > hi)
            return -1;
        if (lo == hi) {
            if (nums[lo] == target)
                return lo;
            else
                return -1;
        }
        
        if (nums[lo] < nums[hi]) {
            // since there are no duplicates, this means that
            //   nums[lo ... hi] are sorted in ascending order
            return bin_search(nums, lo, hi, target);
        }
        else {
            int mid = lo + (hi - lo)/2;
            int search_result = -1;
            if (nums[lo] < nums[mid]) {
                // left part is sorted
                search_result = bin_search(nums, lo, mid, target);
                if (search_result == -1) {
                    // search in the (rotated) right part
                    search_result = search(nums, mid+1, hi, target);
                }
            }
            else {
                // right part is sorted
                search_result = bin_search(nums, mid+1, hi, target);
                if (search_result == -1) {
                    // search in the (rotated) left part
                    search_result = search(nums, lo, mid, target);
                }
            }
            return search_result;
        }
    }
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        
        return search(nums, 0, nums.size() - 1, target);
    }
};
/*
[3,1]
1
[4,5,6,7,0,1,2]
0
[4,5,6,7,0,1,2]
3
[1]
0
[10]
9
[0,1,2,4,5,6,7]
9
[0,1,2,4,5,6,7]
4
[8,0,1,2,4,5,6,7]
1
[8,0,1,2,4,5,6,7]
8
[8,0,1,2,4,5,6,7]
7
[8,0,1,2,4,5,6,7]
-1
*/
