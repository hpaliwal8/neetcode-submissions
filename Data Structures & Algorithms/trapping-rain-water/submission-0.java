class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] leftMaxArray = new int[n];
        int[] rightMaxArray = new int[n];

        leftMaxArray[0] = height[0];
        for(int i=1;i<n;i++) {
            leftMaxArray[i] = Math.max(leftMaxArray[i-1], height[i]);
        }

        rightMaxArray[n-1] = height[n-1];
        for(int i=1;i<n;i++) {
            rightMaxArray[n-i-1] = Math.max(rightMaxArray[n-i], height[n-i-1]);
        }

        int res = 0;
        for(int i=0;i<n;i++) {
            res += Math.min(leftMaxArray[i], rightMaxArray[i]) - height[i];
        }

        return res;

    }
}
