class Solution {
    public int maxProfit(int[] prices) {
        int minTillNow = Integer.MAX_VALUE;
        int profit = 0;

        for(int i=0;i<prices.length;i++) {
            minTillNow = Math.min(minTillNow, prices[i]);
            if(minTillNow < prices[i]) {
                profit = Math.max(profit, prices[i] - minTillNow);
            }
        }

        return profit;
    }
}
