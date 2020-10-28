import java.util.Scanner;
class triangle
{
 public static void main(String args[])
 {
 int l1,l2,l3;
 Scanner sc = new Scanner(System.in);
System.out.println("enter the length of three side of triangle");
 l1=sc.nextInt();
 l2=sc.nextInt();
 l3=sc.nextInt();
 if((l1>=(l2+l3))||(l2>=(l1+l3))||(l3>=(l1+l2)))
 {
System.out.println("triangle is formed");
}
 else
{
System.out.println("triangle cannot be formed");
}
}
}
