import java.util.HashMap;

class Solution {

    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hmm = new HashMap<Integer, Integer>();
        int temp = 0;
        for (int i = 0; i < nums.length; i++) {
            temp = target - nums[i];
            if (hmm.containsKey(temp)) {
                return new int[] { hmm.get(temp), i };
            }
            hmm.put(nums[i], i);
        }
        return new int[] { -1, -1 };
    }
}