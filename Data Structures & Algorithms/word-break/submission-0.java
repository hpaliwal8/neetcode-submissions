class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        boolean[] dp = new boolean [n+1];

        dp[0] = true;

        for(int i = 1; i<=n ;i++) {
            for(String word: wordDict) {
                if(i - word.length() >= 0 && s.substring(i-word.length(), i).equals(word)) {
                    dp[i] = dp[i - word.length()];
                }
                if(dp[i]) break;
            }
        }

        return dp[n];
     }
}
