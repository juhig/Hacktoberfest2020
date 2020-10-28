/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package case;

import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class Case {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        // TODO code application logic here
        char c;
        
        Scanner sc=new Scanner(System.in);
        
        System.out.println("Enter Alphabet:");
        c=(char)System.in.read();
        
        if(c>='A' && c<='Z') 
            System.out.println("It is an UPPERCASE ALPHABET.");
        
        else if(c>='a' && c<='z'))
            System.out.println("It is a LOWERCASE ALPHABET.");
            
        else
        System.out.println("It is not an ALPHABET.");
    }
    
}
