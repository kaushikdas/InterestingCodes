package kaushik.java.leetcode;

import java.util.HashMap;

public class TwoSum {
    /**
     * Solves the Two Sum problem using *HashMap*
     * @param nums: Input array of numbers
     * @param target: Target sum
     * @return the array contains indexes of the array elements that
     * adds upto the given sum
     */
    public static int[] solve(int[] nums, int target) {
        int[] res = {-1, -1};
        if (nums == null || nums.length == 0)
            return res;

        HashMap<Integer, Integer> deficit = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (deficit.containsKey(target - nums[i])) {
                // target - a[i] is already seen => we can form the sum
                res[0] = deficit.get(target - nums[i]);
                res[1] = i;
            }
            else {
                // Put the [nums[i] : i] as [k:v] in the map
                deficit.put(nums[i], i);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int a[] = {2,7,11,15}, target = 9;
        int[] res = solve(a, target);
        System.out.println("[" + res[0] + ", " +  res[1] + "]");
    }
}
