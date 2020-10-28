/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package typetriangle;

import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class TypeTriangle {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        int a,b,c;
        
        Scanner sc=new Scanner(System.in);
        
        System.out.println("Enter Side A:");
        a=sc.nextInt();
        
        System.out.println("Enter Side B:");
        b=sc.nextInt();
        
        System.out.println("Enter Side C:");
        c=sc.nextInt();

        if(a==b && b==c)
            System.out.println("It ia an EQUILATERAL triangle.");
        
        else if(a==b || b==c || c==a)
            System.out.println("It is an ISOSCELES Triangle");
        
        else
            System.out.println("It is a SCALENE Triangle.");
    }
    
}
