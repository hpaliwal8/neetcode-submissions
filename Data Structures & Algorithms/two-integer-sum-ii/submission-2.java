class Solution {
    public int[] twoSum(int[] numbers, int target) {
        /**
        HashMap solution
        */

        /**
        HashMap<Integer, Integer> hm = new HashMap<>();

        for(int i=0;i<numbers.length;i++) {
            int diff = target - numbers[i];
            if(hm.containsKey(diff)) {
                return new int[]{Math.min(i, hm.get(diff)) + 1, Math.max(i, hm.get(diff)) + 1};
            } else {
                hm.put(numbers[i], i);
            }
        }
        */

        /**
        Two ptr solution
        */
        int left = 0;
        int right = numbers.length - 1;

        while(left < right) {
            int intSum = numbers[left] + numbers[right];
            if(intSum == target) {
                return new int[]{left + 1, right + 1};
            } else if(intSum > target) {
                right--;
            } else {
                left++;
            }
        }

        return new int[]{-1, -1};
    }
}
