//bank problem:

package Ass9a;
import java.util.*;
class Bank{
	Scanner sc=new Scanner(System.in);
	String name,acc_id,acc_type;
	int age;
	static double balance;
	double bal;
	double withdraw_money,deposit_money;
	void create_acc() {
		System.out.print("Enter USER NAME :");
		name=sc.next();
		System.out.print("Enter the age.(Age should be above 17) :");
		age=sc.nextInt();
		while(age<18) {
			System.out.println("age cannot be less than 18. PLEASE RE-ENTER :");
			age=sc.nextInt();
		}
		System.out.println("enter account ID :");
		acc_id=sc.next();
		System.out.println("enter ACCOUNT TYPE :- 1.savings/2.current :");
		acc_type=sc.next();
		System.out.println("enter BALANCE in the account");
		balance=sc.nextInt();
		System.out.println("enter MINIMUM BALANCE in account :");
		bal=sc.nextInt();
	}
	void withdraw() {
		System.out.println("enter AMOUNT to be WITHDRAWN : ");
		withdraw_money=sc.nextInt();
		while(balance-withdraw_money<bal) {
			System.out.println("enter withdraw amount accordingly. Current balance is "+balance);
			withdraw_money=sc.nextInt();
		}
		System.out.println("BALANCE LEFT in account : "+ (balance-withdraw_money));
	}
	void deposit() {
		System.out.println("enter AMOUNT TO BE DEPOSITED : ");
		deposit_money=sc.nextInt();
		System.out.println("NEW BALANCE after deposit : "+(balance+deposit_money));
	}
	void display() {
		System.out.println("following are the ACCOUNT DETAILS :");
		System.out.println("USER NAME : "+ name);
		System.out.println("USER AGE : "+ age);
		System.out.println("ACCOUNT ID : "+acc_id);
		System.out.println("ACCOUNT TYPE : "+acc_type);
		System.out.println("BALANCE : "+balance);
		System.out.println("MINIMUM BALANCE : "+bal);
	}
	
}
public class Main1 {

	public static void main(String[] args) {
		int ch;
		Bank ob=new Bank();
		Scanner sc=new Scanner(System.in);
		
		do {
			System.out.println("*************************MENU************************");
			System.out.println("1. enter 1 to CREATE ACCOUNT");
			System.out.println("2. enter 2 to DISPLAY");
			System.out.println("3. enter 3 to DEPOSIT MONEY");
			System.out.println("4. enter 4 to WITHDRAW MONEY");
			System.out.println("5. enter 5 to EXIT ");
			System.out.print("Enter your choice : ");
			ch=sc.nextInt();
			switch(ch) {
			case 1:
				ob.create_acc();
				System.out.println("");
				break;
			case 2 :
				ob.display();
				System.out.println("");
				break;
			case 3:
				ob.deposit();
				System.out.println("");
				break;
			case 4:
				ob.withdraw();
				System.out.println("");
				break;
			case 5:
				System.out.println("exit code!!");
				break;
			default:
				System.out.println("enter valid choice");
				break;
			}
		}while(ch!=5);

	}

}
