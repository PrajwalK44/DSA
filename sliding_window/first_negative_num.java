import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution {

    // Function to find the first negative integer in every window of size k
    static List<Integer> FirstNegativeInteger(int arr[], int k) {
        List<Integer> ans=new ArrayList<>();
        LinkedList<Integer> negQueue=new LinkedList<>();
        
        int start=0;
        int end=0;
        while(end<arr.length){
            if(arr[end]<0){
                negQueue.add(end);
            }
            
            if(end-start+1==k){
                if(!negQueue.isEmpty() && negQueue.peek()>=start){
                    ans.add(arr[negQueue.peek()]);
                }
                 else{
                    ans.add(0);
                }
                start++;
                
                
                if(!negQueue.isEmpty() && negQueue.peek() < start){
                    negQueue.poll();
                }
                
            }
            end++;
        }
        return ans;
    }
}
