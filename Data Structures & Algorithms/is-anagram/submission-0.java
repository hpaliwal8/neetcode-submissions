class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) {
            return false;
        }
        int len = s.length();

        int[] sCount = new int[26];
        int[] tCount = new int[26];

        for(int i=0;i<len;i++) {
            sCount[s.charAt(i) - 'a']++;
            tCount[t.charAt(i) - 'a']++;
        }

        String sArr = Arrays.toString(sCount);
        String tArr = Arrays.toString(tCount);

        if(sArr.equals(tArr)) {
            return true;
        }

        return false;

    }
}
