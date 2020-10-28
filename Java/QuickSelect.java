
class QuickSelect {

	static int partition(int[] arr, int low, int high) {
		int pivot = arr[high];
		int i = low;

		for (int j = low; j < high; j++) {
			if (arr[j] < pivot) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

				i++;
			}
		}

		int temp = arr[i];
		arr[i] = arr[high];
		arr[high] = temp;

		return i;
	}

	static int kthSmallest(int[] arr, int low, int high, int k) {
		int partition = partition(arr, low, high);

		if (partition < k) {
			return kthSmallest(arr, partition + 1, high, k);
		} else if (partition > k) {
			return kthSmallest(arr, low, partition - 1, k);
		} else {
			return arr[partition];
		}
	}

	public static void main(String args[]) 
    { 
        int arr[] = {7, 10, 4, 3, 20, 15}; 
        
        int length = arr.length; 
        int k = 4;
        
        System.out.println("K-th smallest element in array : " +  
                                kthSmallest(arr, 0, length - 1, 
                                                          k - 1));  
    } 	
}