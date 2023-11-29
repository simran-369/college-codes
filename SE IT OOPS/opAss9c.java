//tourist management system

package Ass9c;
import java.util.*;
public class Tourist {
Scanner sc=new Scanner(System.in);
String name,source,destination;
int days,pp;
int totalPrice=days*pp;
void create() {
	System.out.println("enter PERSON NAME : ");
	name=sc.next();
	System.out.println("enter SOURCE place : ");
	source=sc.next();
	System.out.println("enter DESTINATION place: ");
	destination=sc.next();
	System.out.println("enter PRICE PER DAY: ");
	pp=sc.nextInt();
	System.out.println("enter NUMBER OF DAYS: ");
	days=sc.nextInt();
}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		ArrayList<Tourist>t=new ArrayList<Tourist>();
		ArrayList<Integer>ar=new ArrayList<Integer>();
		ArrayList<Integer>dt=new ArrayList<Integer>();
		int ch,size,s,d;
		do {
			System.out.println("******************MENU****************");
			System.out.println("1. enter 1 for ENTER tourist details:");
			System.out.println("2. enter 2 for UPDATE tourist details:");
			System.out.println("3. enter 3 for DELETE tourist details:");
			System.out.println("4. enter 4 for DISPLAY tourist details: ");
			System.out.println("5. enter 5 to exit code:");
			System.out.print("enter your choice : ");
			ch=sc.nextInt();
			switch(ch) {
				case 1:
					System.out.println("enter the TOTAL NUMBER OF TOURIST :");
					size=sc.nextInt();
					for(int i=0;i<size;i++) {
						Tourist tr=new Tourist();
						System.out.println("details of TOURIST "+(i+1));
						tr.create();
						t.add(tr);
					}
					System.out.println("");
					break;
				case 2:
					System.out.println("enter the TOTAL NUMBER of tourist details you want to UPDATE");
					s=sc.nextInt();
					System.out.println("enter TOURIST NUMBER you want to update :");
					for(int i=0;i<s;i++) {
						System.out.println((i+1)+" TOURIST NUMBER : ");
						ar.add(sc.nextInt());
					}
					for(int i=0;i<ar.size();i++) {
						Tourist tr=t.get(ar.get(i)-1);
						System.out.println("enter new details");
						tr.create();
						t.set(ar.get(i)-1,tr);
					}
					System.out.println("");
					break;
				case 3:
					System.out.println("enter the TOTAL NUMBER of tourist details you want to DELETE");
					d=sc.nextInt();
					System.out.println("enter TOURIST NUMBER you want to delete :");
					for(int i=0;i<d;i++) {
						System.out.println((i+1)+" TOURIST NUMBER : ");
						dt.add(sc.nextInt());
					}
					for(int i=0;i<d;i++) {
						Tourist tr=t.get(dt.get(i)-1);
						t.remove(tr);
					}
					System.out.println("");
					break;
				case 4:
					System.out.println("****LIST OF TOURIST******");
					for(int i=0;i<t.size();i++) {
						Tourist tr=t.get(i);
						System.out.println("TOURIST NUMBER: "+(i+1)+", NAME: "+tr.name+", SOURCE: "+tr.source+", DESTINATION: "+tr.destination+", DAYS: "+tr.days+", TOTAL PRICE"+tr.days*tr.pp);
					}
					System.out.println("");
					break;
				case 5:
					System.out.println("exit code: ");
					break;
				default:
					System.out.println("please enter valid input: ");
					break;
					
			}
			
		}while(ch!=5);

	}

}
