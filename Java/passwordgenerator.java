import java.util.Random;

public class RandomPasswordGenerator {

	static public char[] getPassword(int len) {
		
		String capital_letters ="QWERTYUIOPASDFGHJKLZXCVBNM";   // String of capital letters
		String small_letters="qwertyuiopasdfghklzxcvbnm";      //String of small letters
		String special_chars="~!@#$%^&*()_+=-`][{}|;'<>?/.,";   //String of special characters
		
		String values=capital_letters+small_letters+special_chars;   // Adding all the elements in one String
		
		char password[]=new char[len];
		Random random=new Random();   //Creating an Object of Random
		
		for(int i=0;i<len;i++) {
			
			password[i]=values.charAt(random.nextInt(values.length()));  //Using nextInt method to get an random element from String values 
		}
		
		return password;
		
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int length=8;
		System.out.println(getPassword(length));

	}

}
