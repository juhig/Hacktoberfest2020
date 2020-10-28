import java.util.Arrays;
class ArrayProduct{
    public int[] productExceptSelf(int[] nums) {
        
        int[] l_array = new int[nums.length];
        int[] r_array = new int[nums.length];
        
        int[] output = new int[nums.length];
        
        l_array[0] = 1;
        
        int prev_val = l_array[0];
        
        for(int i=0; i< nums.length; i++){
            l_array[i] = nums[i] * prev_val;
            prev_val = l_array[i];
        }
        
        int n_length = nums.length;
        r_array[n_length-1] = 1;
        int prev_right = r_array[n_length-1];
       
        for(int j = n_length-1; j >= 0; j--){
            r_array[j] = nums[j] * prev_right;
            prev_right = r_array[j];
        }
        output[0] = r_array[1];
        output[n_length-1] = l_array[n_length-2];
        
        for(int out = 1 ; out < n_length-1; out++){
            output[out] = l_array[out-1] * r_array[out+1];
        }
        return output;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,3,4};
        ArrayProduct result = new ArrayProduct();
        System.out.println(" Product of Array Except Self " + Arrays.toString(result.productExceptSelf(nums)) );
        
    }

}