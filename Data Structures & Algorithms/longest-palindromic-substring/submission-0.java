class Solution {
    public String longestPalindrome(String s) {
        int resIdx = 0;
        int resLen = 0;

        int n = s.length();

        boolean[][] dp = new boolean[n][n];

        for(int i=0;i<n;i++) {
            for(int j=0;j<=i;j++) {
                if(s.charAt(i) == s.charAt(j) && 
                (i - j <= 2 || dp[i-1][j+1])) {
                    dp[i][j] = true;

                    if(resLen < i - j + 1) {
                        resLen = i - j + 1;
                        resIdx = j;
                    }
                }
            }
        }

        return s.substring(resIdx, resIdx + resLen);


    }
}
