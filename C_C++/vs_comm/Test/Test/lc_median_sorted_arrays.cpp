// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <vector>
#include <iostream>
#include <climits>

using std::pair;
using std::vector;
using std::cout;

/*
5

5 -> 0 1 2 3 4 5 -> 2 -> 3
2 ->       3 4 5 -> 1 -> 2
0 ->           5

6 -> 0 1 2 3 4 5 6 -> 3 -> 4
2 ->         4 5 6 -> 1 -> 2
0 ->             6

4 -> 0 1 2 3 4 -> 2 -> 3
1 ->       3 4 -> 0 -> 1
0 ->         4

2 -> 0 1 2 -> 1 -> 2
0 ->     2

10 -> 0 1 2 3 4 5 6 7 8 9 10 -> 5 -> 6
 4 ->             6 7 8 9 10 -> 2 -> 3
 1 ->                   9 10 -> 0 -> 1
 0 ->                     10


5/2 = 2

3
3/2 = 1

2
2/2 = 1

1
1/2 = 0

0


*/

class Solution
{
private:
    int
        get_kth_element(vector<int>& nums1,
            vector<int>& nums2, size_t k,
            vector<int>::iterator it1,
            vector<int>::iterator it2)
    {
        if (it1 == nums1.end())
        {
            // find kth element in nums1
            return *(it2 + k);
        }
        else if (it2 == nums2.end())
        {
            // find kth element in nums2
            return *(it1 + k);
        }
	
        if (k == 0)
        {
            if (*it1 <= *it2)
            {
                return *it1;
            }
            else
            {
                return *it2;
            }
        }

        size_t m1, m2;
        m1 = m2 = k / 2;
        size_t l1 = nums1.end() - it1;
        size_t l2 = nums2.end() - it2;

        m1 = (m1 >= l1) ? 0 : m1;
        m2 = (m2 >= l2) ? 0 : m2;

        auto mid1 = it1 + m1;
        auto mid2 = it2 + m2;

        if (*mid1 <= *mid2)
        {
            return get_kth_element(nums1, nums2, k - m1 - 1, mid1 + 1, it2);
        }
        else
        {
            return get_kth_element(nums1, nums2, k - m2 - 1, it1, mid2 + 1);
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2)
    {
        size_t sz1 = nums1.size(), sz2 = nums2.size();

        if (sz1 == 0 && sz2 == 0)
        {
            // empty arrays
            return 0.0;
        }

        if (sz1 > sz2)
        {
            // we want nums1 to be the smaller
            return findMedianSortedArrays(nums2, nums1);
        }

        auto mid_boundary = (sz1 + sz2 + 1) / 2;
        // If (sz1 + sz2) is odd, say, 11 then mid_boundary 
        // = (11 + 1)/2 = 6, then there will be 1 element extra to
        // the left of mid_boundary (left 6 elements, right 5 elements).
        // If (sz1 + sz2) is odd, say, 10 then mid_boundary
        // = (10 + 1)/2 = 5, then there will be same number of elements
        // in the both left and right sides of mid_boundary

        size_t start1 = 0, end1 = sz1 - 1; // start and end of nums1

        while (start1 <= end1)
        {
            size_t mid1 = (start1 + end1) / 2;
            int u =  (mid1 > 0)? nums1[mid1 - 1] : INT_MIN;
            int v = (mid1 < sz1)? nums1[mid1] : INT_MAX; 
                // (mid1 > 0) => nums1 has exhausted
            // left side will have #mid_boundary elements, #mid1 from
            // nums1 and remaining from nums2;
            size_t mid2 = mid_boundary - mid1;
            int x =  (mid2 > 0)? nums2[mid2 - 1] : INT_MIN;
            int y = (mid2 < sz2)? nums1[mid2] : INT_MAX;

            if ((u <= y) && (x <= v))
            {
                // found correct split
                return ((sz1 + sz2) / 2);
            } 
        }
    }
};

int lc_median_sorted_arrays_main()
{
    vector<int> nums1 {0, 0, 0, 0, 0 }; // {1, 2, 3};
    vector<int> nums2 {-1, 0, 0, 0, 0, 0, 1 }; //{4};

    Solution s;
    auto median = s.findMedianSortedArrays(nums1, nums2);
    cout << "Median = " << median;

    return 0;
}