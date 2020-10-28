import java.util.*;
class Removing_Duplicates_In_Array
{
    public int removeDuplicates(int[] nums)
    {
        int r=1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]!=nums[i-1])
                {
                  nums[r++]=nums[i]; 
                }
        }
        for(int i=0;i<r;i++)
        System.out.println(nums[i]);
        return r;
    }
}
