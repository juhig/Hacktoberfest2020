class Bank{
	String name;
	int account_no;
	String type;
	int balance;
	Bank(String name, int account_no, String type, int balance){
		this.name=name;
		this.account_no=account_no;
		this.type=type;
		this.balance=balance;
	}
	void deposit(int depo_amount){
		balance= balance+depo_amount;
	}
	void withdraw(int with_amount){
		if(balance>with_amount)
		balance=balance-with_amount;
		else
		System.out.println("Not enough balance!");
	}
	void display(){
	System.out.println("Name: "+ name);
	System.out.println("Balance: Rs."+ balance);
	}
}
class Bank_account{
	public static void main(String args[]){
		Bank a=new Bank("Aarushi",1234,"official",3400);
		a.withdraw(4000);
		a.display();
	}
}