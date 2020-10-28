import java.util.*;
import java.math.*;
public class Play {
	public static Scanner sc=new Scanner(System.in);
	public static int you;
	public static int comp;
	static int wicket1=3;
	static int wicket2=3;
	static  int totalScore2=0;
	 static int totalScore1=0;
	 static int tossDecision1,tossDecision2;
	 static int choice;
     public static void toss(int choice) {
    	 int letstoss= (int) (Math.random()*(1+1));
         if(choice==letstoss) {
        	 System.out.println("You have won the toss.Press 0 for batting or press 1 for fielding");
        	 tossDecision1=sc.nextInt();
        	  }
         else {
        	 System.out.println("Computer has won the toss.");
        	 tossDecision2=(int)(Math.random()*(2));
        	 if(tossDecision2==0){
        		 System.out.println("Computer decided to bat first.");}
        	 else if(tossDecision2==1){
        		 System.out.println("Computer decided to field first.");
        	 } } }
      public static void Batting() {
		while (wicket1 !=0) {
			System.out.println("You:");
			you=sc.nextInt();
			comp=(int)(Math.random()*(6)+1);
			System.out.println("Comp:"+comp);
			if(you==comp)
				{wicket1--;
			System.out.println(" xx---Wicket!--xx ");
			System.out.println("You are left with "+wicket1+" wickets.");
			if(wicket1==0)
			System.out.println("Your Score:"+totalScore1);
			if(totalScore1<totalScore2&&wicket1==0) {
				System.out.println("COMPUTER WINS!!!");
				System.out.println("Computer Wins By "+(totalScore2-totalScore1)+"runs.");
			} }
			else {
				totalScore1=totalScore1+you;
				if(totalScore1>totalScore2&&totalScore2!=0) {
					System.out.println("You Win!!. By"+wicket1+"wickets");
					System.out.println("Your Final Score:"+totalScore1);
					break;
				} } } }
	 
	public static void Fielding() {
		while(wicket2 !=0) {
			comp=(int)(Math.random()*(6)+1);
			System.out.println("You:");
			you=sc.nextInt();
			System.out.println("Comp:"+comp);
			if(you==comp) {
				wicket2--;
			System.out.println(" xx---Wicket!--xx ");
			System.out.println("Computer is left with "+wicket2+" wickets.");

			if(wicket2==0)
			System.out.println("Computer's Score:"+totalScore2);
			if(totalScore2<totalScore1&&totalScore1!=0&&wicket2==0) {
				System.out.println("YOU WIN!!!");
				System.out.println("You Win By "+(totalScore1-totalScore2)+" runs.");
			}}
			else {
			totalScore2=totalScore2+comp; 
				if(totalScore2>totalScore1&&totalScore1!=0) {
					System.out.println("Computer Wins!!. By"+wicket2+ "wickets.");
					System.out.println("Computer's Final Score:"+totalScore2);
					
					break;
				} } } }	
	
	public static void main(String args[]) {
		int BattingDone=0,FieldingDone=0;
		System.out.println("\t\t\t\t\t\t\t\tXXX---WELCOME TO HAND CRICKET---XXX");
	    System.out.println("Your call : Press 0 for heads and 1 for tails.");
	    choice=sc.nextInt();
		toss(choice);
		System.out.println("Lets begin with the first inning.");
		if(tossDecision1==0||tossDecision2==1)
		{
			System.out.println("You have chosen batting.Lets begin.");
			Batting();
			BattingDone++;
		}
		else if(tossDecision2==0||tossDecision1==1) {
			System.out.println("You have chosen fielding.Lets begin.");
         Fielding();
         FieldingDone++;
		}
		System.out.println("Lets continue with the second inning.");
		if(BattingDone==1)
		{
			Fielding();
		}
		else if(FieldingDone==1)
		{
			Batting();
		} } }
