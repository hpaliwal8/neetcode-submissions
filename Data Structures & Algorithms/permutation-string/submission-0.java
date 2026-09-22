class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 > n2) {
            return false;
        }

        int[] s1Count = new int[26];
        int[] s2Count = new int[26];

        for(int i=0; i < n1; i++) {
            s1Count[s1.charAt(i) - 'a']++;
            s2Count[s2.charAt(i) - 'a']++;
        }

        int matches = 0;
        for(int i=0;i<26;i++) {
            if(s1Count[i] == s2Count[i]) {
                matches++;
            }
        }

        int l = 0;
        for(int r=n1; r<n2; r++) {
            if(matches == 26) return true;

            int rightIndex = s2.charAt(r) - 'a';
            s2Count[rightIndex]++;
            if(s1Count[rightIndex] == s2Count[rightIndex]) {
                matches++;
            } else if(s1Count[rightIndex] == s2Count[rightIndex] - 1) {
                matches--;
            }

            int leftIndex = s2.charAt(l) - 'a';
            s2Count[leftIndex]--;
            if(s1Count[leftIndex] == s2Count[leftIndex]) {
                matches++;
            } else if(s1Count[leftIndex] == s2Count[leftIndex] + 1) {
                matches--;
            }
            l++;
        }

        return matches == 26;

    }
}
