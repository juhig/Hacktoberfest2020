import java.util.Random;
import java.util.Scanner;

/**
 * @author Jackson Roberio (https://jacksonroberio.com.br)
 **/
public class Guess {
	
		private static int myster;
		
		private static Scanner scan;
		
		/**
		 * Core code!
		 **/
		public static void main(String[] args) {
			System.out.println("let's Go Play?!\n");
			goValues();
			
			System.out.println("Start Now!");
			System.out.println("-> choose a number between 1 to 20 and you will have 5 attempts.");
			System.out.println("Enter number:");
		
		
			for (int trying = 4; trying >= 0; trying--) {
				int numberSelected = scan.nextInt();

				if(!isMysterTrue(numberSelected)) {
					System.out.println("You have " + trying + " attempts.\n");
					System.out.println("Play again? Enter a new number between 1 to 20:");
				} else if(trying > 0) {
					System.out.println("Number true.");
					System.out.println("End Game.");
					return ;
				}
			}
			
			System.out.println("You have no more attempts.");
			System.out.println("The correct number is: " + myster);
		}
		
		/**
		 * Generates an random number from 1 to 20, this number is the number that the user needs to guess.
		 **/
		private static int goRandomMyster() {
	        Random random = new Random();
	        return random.nextInt(20);
		}
		
		private static boolean isMysterTrue(int number) {
			if(number == myster) {
				return true;
			} else if(number > myster) {
				System.out.println("wrong number, the value is less.");
				return false;
			} else {
				System.out.println("wrong number, the value is higher.");
				return false;
			}
		}
		
		private static void goValues(){
			myster = goRandomMyster();
			scan = new Scanner(System.in);
		}
}
