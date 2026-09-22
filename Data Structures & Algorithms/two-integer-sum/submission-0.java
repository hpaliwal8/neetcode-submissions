class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> hm = new HashMap<>();

        for(int i=0;i<nums.length;i++) {
            int diff = target - nums[i];

            if(hm.keySet().contains(diff)) {
                return new int[]{Math.min(hm.get(diff), i), Math.max(hm.get(diff), i)};
            } else {
                hm.put(nums[i], i);
            }
        }

        return new int[]{-1, -1};
    }
}
