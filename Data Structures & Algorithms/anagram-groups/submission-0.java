class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> hm = new HashMap<>();

        for(int i=0;i<strs.length;i++) {
            int[] countArr = new int[26];
            String word = strs[i];
            for(char c: word.toCharArray()) {
                countArr[c-'a']++;
            }

            List<String> temp = hm.getOrDefault(Arrays.toString(countArr), new ArrayList<>());
            temp.add(word);
            hm.put(Arrays.toString(countArr), temp);
        }

        List<List<String>> res = new ArrayList<>(hm.values());
        return res;
    }
}
