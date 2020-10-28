import java.util.Scanner; //importing the Scanner class

public class SelectionSort {
public static void main(String[] args) {
	Scanner sc= new Scanner(System.in);
    System.out.println("Please enter the length of the array:");
    int n= sc.nextInt();
    
    int[] a= new int[n];
    System.out.println("Please enter the numbers of the array, separated by space:");
    for(int i=0;i<n;i++)
    { a[i]= sc.nextInt();
    }
    int minIndex, temp;
    for(int i=0;i<n-1;i++) {
    	minIndex=i;
    	for(int j=i+1;j<n;j++) {
    		if(a[j]<a[minIndex]) {
    			minIndex=j; //Searching for lowest index
    		}
        }
    		temp=a[i];
    		a[i]=a[minIndex];
    		a[minIndex]= temp;  	
    }
    for(int i=0;i<n;i++)
    System.out.print(a[i]+" "); //Printing the sorted array (in ascending order)
       
}
}
