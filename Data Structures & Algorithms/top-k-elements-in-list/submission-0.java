class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> hm = new HashMap<>();
        for(int num: nums) {
            int count = hm.getOrDefault(num, 0) + 1;
            hm.put(num, count);
        }

        List<int[]> al = new ArrayList<>();
        for(Map.Entry<Integer, Integer> me: hm.entrySet()) {
            al.add(new int[]{me.getValue(), me.getKey()});
        }

        al.sort((a,b) -> b[0] - a[0]);

        int[] res = new int[k];
        for(int i=0;i<k;i++) {
            res[i] = al.get(i)[1];
        }

        return res;
    }

}


