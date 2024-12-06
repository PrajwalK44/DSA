class Solution {
    public int[] twoSum(int[] nums, int target) {
       int diff;
       int res[]=new int[2];
       HashMap<Integer, Integer> mapSum=new HashMap<>();
       for(int i=0; i<nums.length; i++){
         diff=target-nums[i];
        if(mapSum.containsKey(diff)){
            res[0]=i;
            res[1]=mapSum.get(diff);
            return res;
        }
        else{
            mapSum.put(nums[i], i);
        }
       }
        return null;

    }
}
