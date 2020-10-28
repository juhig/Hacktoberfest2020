
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
import java.util.Scanner;
class VolumeOfBox 
{
      
   public static void main(String args[]) 
    {   
       
        	Scanner s= new Scanner(System.in);
         	System.out.println("Enter the length of box:");
         	double l=s.nextDouble();
		System.out.println("Enter the breadth of box:");
         	double b=s.nextDouble();
		System.out.println("Enter height of box:");
         	double h=s.nextDouble();
                
                 double  volume= l*b*h;
 
             System.out.println("Volume Of boxis:" +volume);
             
          
   }
}