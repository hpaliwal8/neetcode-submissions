class Solution {
    public int characterReplacement(String s, int k) {
        int n = s.length();
        int res = 0;
        int left = 0;
        int maxFrequency = 0;

        Map<Character, Integer> countMap = new HashMap<>();

        for(int right=0; right<n; right++) {
            char c = s.charAt(right);
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
            maxFrequency = Math.max(maxFrequency, countMap.get(c));
            while((right - left + 1) - maxFrequency > k) {
                countMap.put(s.charAt(left), countMap.get(s.charAt(left)) - 1);
                left++;
            }

            res = Math.max(res, right - left + 1);
        }

        return res;
    }
}
