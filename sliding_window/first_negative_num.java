import java.util.HashMap;

class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        long max_sum=0;
        long win_sum=0;
        HashMap<Integer, Integer> freq=new HashMap<>();

        for(int i=0; i<nums.length; i++){
            win_sum+=nums[i];
            freq.put(nums[i], freq.getOrDefault(nums[i],0)+1);

            if(i>=k){
                win_sum-=nums[i-k];
                freq.put(nums[i-k], freq.getOrDefault(nums[i-k],0)-1);
                if(freq.get(nums[i-k])==0){
                    freq.remove(nums[i-k]);
                }
            }

            if(i>=k-1 && freq.size()==k){
                max_sum=Math.max(win_sum, max_sum);
            }
        }
        return max_sum;
    }
}
