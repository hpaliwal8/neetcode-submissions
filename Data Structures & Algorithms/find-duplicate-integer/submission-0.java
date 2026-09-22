class Solution {
    public int findDuplicate(int[] nums) {

        /*
            1. Identify that it is a Linked List problem
            2. Use Floyd's Cycle Detection Algo
        */
        int fast = 0;
        int slow = 0;

        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast) {
                break;
            }
        }

        int slow2 = 0;

        while(true) {
            slow = nums[slow];
            slow2 = nums[slow2];

            if(slow == slow2) {
                break;
            }
        }

        return slow2;

    }
}
