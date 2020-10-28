import java.util.Scanner;
public class Palindrome { 
  
    // Function that returns true if a string is a Palindrome
    
    static boolean isPalindrome(String str) 
    { 
        int i = 0, j = str.length() - 1; // Pointers pointing to the beginning  and the end of the string 
       
       while (i < j) {  // While there are characters to compare
            if (str.charAt(i) != str.charAt(j)) 
                return false;
            i++; 
            j--; 
        } 
  
       return true; // Given string is a palindrome 
    } 
  
    public static void main(String[] args) 
    { 
        Scanner in = new Scanner (System.in);
        String str = in.nextLine();
  
        if (isPalindrome(str)) 
            System.out.print("Yes"); 
        else
            System.out.print("No"); 
    } 
} 
