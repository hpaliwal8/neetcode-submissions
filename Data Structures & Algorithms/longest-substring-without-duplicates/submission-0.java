class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if(n == 0) return 0;
        Map<Character, Integer> hm = new HashMap<>();

        int left = 0, res = 0;
        char[] cArr = s.toCharArray();
        for(int right=0; right < n; right++) {
            if(hm.containsKey(cArr[right])) {
               left = Math.max(hm.get(cArr[right]) + 1, left); 
            }  
            hm.put(cArr[right], right);
            res = Math.max(res, right - left + 1);
        }

        return res;
    }
}
