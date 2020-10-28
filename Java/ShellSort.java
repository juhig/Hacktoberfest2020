//Code contributed by Aditya Prakash(@PrakashAditya17)
import java.io.*;
import java.util.*;
public class ShellSort
{
        public static void main(String args[])throws IOException
        {
                Scanner sc=new Scanner(System.in);
                System.out.println("Enter the size");
                int n=sc.nextInt();
                System.out.println("Enter the elements");
                int a[]=new int[n];
                for(int i=0;i<n;i++)
                        a[i]=sc.nextInt();
                
                //We will use the intervals as N/2,N/4,N/8....so on.
                int interval=n/2;
                while(interval > 0)
                {
                        for(int i=interval;i<n;i++)
                        {
                                int tmp=a[i];
                                int j;
                                for(j=i;j>=interval && a[j-interval]>tmp ;j-=interval)
                                {
                                        a[j]=a[j-interval];
                                }
                                a[j]=tmp;
                        }
                        interval=interval/2;
                }
                System.out.println("Sorted array is");
                for(int i=0;i<n;i++)
                        System.out.print(a[i]+",");
         }
}         
              
