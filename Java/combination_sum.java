/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
   List<List<Integer>> result=new ArrayList<>();
        Arrays.sort(candidates);
        
        findCombinations(candidates,0,target,new ArrayList<Integer>(), result);
        return result;
    }
    
    public void findCombinations(int[] candidates, int index, int target, List<Integer> current, List<List<Integer>> result){
        if(target==0){
            result.add(new ArrayList<>(current));  //  result.add(current); don't use this(be careful)
            return;
        }
        if(target<0) return;
        
        for(int i=index;i<candidates.length;i++){
            if(i==index || candidates[i]!=candidates[i-1]){ //here candidates[i]!=candidates[i-1] is only for reducing time complexity, otherwise there is no use of this (ex-1,1,2,5,5,7,10) after checking 5 and confirm that this is not valid we dont need to check it again(think abt it)
                current.add(candidates[i]);
                findCombinations(candidates,i,target-candidates[i] ,current, result); // just change i+1 to i in index
                current.remove(current.size()-1);
            }
        }
        
    }
}
