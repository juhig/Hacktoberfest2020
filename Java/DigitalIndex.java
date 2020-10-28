//When the sum of the digits of a number is taken as a single digit number it is called the Digital Index
//This code outputs the Digital Index of a given number

import java.util.*;
public class DigitalIndex {
    public static void main(String args[]){
        Scanner input=new Scanner(System.in);
        System.out.print("Enter number: ");
        int num=input.nextInt();
        int sum=addDigits(num);
        while(sum>=10){
            sum=addDigits(sum);
        }

        System.out.println("Digital Index = "+(sum));
    }

    static int addDigits(int num){
        if(num<10) return num;
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num=num/10;
        }
        return sum;
    }
}
