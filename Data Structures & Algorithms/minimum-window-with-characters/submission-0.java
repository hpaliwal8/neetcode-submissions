class Solution {
    public String minWindow(String s, String t) {
        if(s.length() < t.length()) {
            return "";
        }

        Map<Character, Integer> countT = new HashMap<>();
        Map<Character, Integer> window = new HashMap<>();

        int[] res = new int[]{-1, -1};
        int resLen = Integer.MAX_VALUE;

        // Setting count of T's
        for(char c: t.toCharArray()) {
            countT.put(c, countT.getOrDefault(c, 0) + 1);
        }

        int have = 0;
        int need = countT.size();
        int left = 0;

        for(int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            window.put(c, window.getOrDefault(c, 0) + 1);

            if(countT.containsKey(c) && window.get(c).equals(countT.get(c))) {
                have++;
            }

            while(have == need) {
                if(right - left + 1 < resLen) {
                    res[0] = left;
                    res[1] = right;
                    resLen = right - left + 1;
                }

                char leftChar = s.charAt(left);
                window.put(leftChar, window.get(leftChar) - 1);
                if(countT.containsKey(leftChar) && window.get(leftChar) < countT.get(leftChar)) {
                    have--;
                }
                left++;
            }
        }

        return resLen == Integer.MAX_VALUE ?  "" : s.substring(res[0], res[1] + 1);
    }
}
