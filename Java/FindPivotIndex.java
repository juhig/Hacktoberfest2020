class Solution {
    public int pivotIndex(int[] nums) {
    int sum = 0;
    for(int i=0; i<nums.length; i++){
    sum+= nums[i];
    }
    int s = 0;
    for(int i=0; i<nums.length; i++){
    sum = sum - nums[i];
    if(sum == s){
    return i;
    }
    s = s + nums[i];
    }
    return -1;
}
}
