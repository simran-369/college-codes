package sim;
import java.util.*;
public interface Vehicle {
 void Speed();
 void GearChange();
 void ApplyBreaks();
}
class Bicycle implements Vehicle{
	public int speed,gear;
	Bicycle(int speed,int gear){
		this.speed=speed;
		this.gear=gear;
	}
	public void Speed() {
		System.out.println("Speed after changes : ");
	}
	public void GearChange() {
		System.out.println("Gear after changes : ");
	}
	public void ApplyBreaks() {
		if(speed<=50 && speed>=5) {
			speed=speed-5;
		}
		else {
			System.out.println("vehicle is at rest");
		}
		System.out.println("new speed after APPLYING BREAKS is : "+" "+speed+" "+"km/hr");
	}
	public void SpeedDown() {
		if(speed<=50 && speed>=5) {
			speed=speed-5;
		}
		else {
			System.out.println("vehicle is at rest");
		}
		System.out.println("new speed after SPEED DOWN is : "+" "+speed+" "+"km/hr");
	}
	public void SpeedUp() {
		if(speed<=45 && speed>=0) {
		speed=speed+5;
		}
		else {
			speed=50;
		}
		System.out.println("new speed after SPEED UP is : "+" "+speed+" "+"km/hr");
	}
	public void GearDown() {
		if(gear>=1 && gear<6) {
		gear=gear-1;
		}
		else {
			gear=0;
		}
		System.out.println("new gear after GEAR DOWN is : "+" "+gear);
	}
	public void GearUp() {
		if(gear<5) {
			gear=gear+1;
		}
		else {
			gear=5;
		}
		System.out.println("new gear after GEAR UP is : "+" "+gear);
	}
}
	class Bike implements Vehicle{
		public int speed,gear;
		Bike(int speed,int gear){
			this.speed=speed;
			this.gear=gear;
		}
		public void Speed() {
			System.out.println("Speed after changes : ");
		}
		public void GearChange() {
			System.out.println("Gear after changes : ");
		}
		public void ApplyBreaks() {
			if(speed<=80 && speed>=10) {
				speed=speed-10;
			}
			else {
				System.out.println("vehicle is at rest");
			}
			System.out.println("new speed after APPLYING BREAKS is : "+" "+speed+" "+"km/hr");
		}
		public void SpeedDown() {
			if(speed<=80 && speed>=10) {
				speed=speed-10;
			}
			else {
				System.out.println("vehicle is at rest");
			}
			System.out.println("new speed after SPEED DOWN is : "+" "+speed+" "+"km/hr");
		}
		public void SpeedUp() {
			if(speed<=70 && speed>=0) {
			speed=speed+10;
			}
			else {
				speed=80;
			}
			System.out.println("new speed after SPEED UP is : "+" "+speed+" "+"km/hr");
		}
		public void GearDown() {
			if(gear>=1 && gear<6) {
			gear=gear-1;
			}
			else {
				gear=0;
			}
			System.out.println("new gear after GEAR DOWN is : "+" "+gear);
		}
		public void GearUp() {
			if(gear<5 && gear>=0) {
				gear=gear+1;
			}
			else {
				gear=5;
			}
			System.out.println("new gear after GEAR UP is : "+" "+gear);
		}
	}
		 class Car implements Vehicle{
			public int speed,gear;
			Car(int speed,int gear){
				this.speed=speed;
				this.gear=gear;
			}
			public void Speed() {
				System.out.println("Speed after changes : ");
			}
			public void GearChange() {
				System.out.println("Gear after changes : ");
			}
			public void ApplyBreaks() {
				if(speed<=100 && speed>=20) {
					speed=speed-20;
				}
				else {
					System.out.println("vehicle is at rest");
				}
				System.out.println("new speed after APPLYING BREAKS is : "+" "+speed+" "+"km/hr");
			}
			public void SpeedDown() {
				if(speed<=100 && speed>=20) {
					speed=speed-20;
				}
				else {
					System.out.println("vehicle is at rest");
				}
				System.out.println("new speed after SPEED DOWN is : "+" "+speed+" "+"km/hr");
			}
			public void SpeedUp() {
				if(speed<=80 && speed>=0) {
				speed=speed+20;
				}
				else {
					speed=100;
				}
				System.out.println("new speed after SPEED UP is : "+" "+speed+" "+"km/hr");
			}
			public void GearDown() {
				if(gear>=1 && gear<6) {
				gear=gear-1;
				}
				else {
					gear=0;
				}
				System.out.println("new gear after GEAR DOWN is : "+" "+gear);
			}
			public void GearUp() {
				if(gear<5) {
					gear=gear+1;
				}
				else {
					gear=5;
				}
				System.out.println("new gear after GEAR UP is : "+" "+gear);
			}
		
			public static void main(String args[]) {
				Bicycle bic1= new Bicycle(0,0);
				Car car1=new Car(0,0);
				Bike bike1=new Bike(0,0);
				Scanner sc=new Scanner(System.in);
				int ch;
				int opt;
				do {
					System.out.println("**********MENU********");
					System.out.println("press 1 : for car");
					System.out.println("press 2 : for bike");
					System.out.println("press 3 : for bicycle");
					System.out.println("press 4 for EXIT CODE");
					System.out.print("Enter your choice :");
					ch=sc.nextInt();
					switch(ch) {
					case 1 :
						do {
						    System.out.println("**********for CAR********");
							System.out.println("press 1 : for SPEED UP");
							System.out.println("press 2 : for SPEED DOWN");
							System.out.println("press 3 : for GEAR UP");
							System.out.println("press 4 : for GEAR DOWN");
							System.out.println("press 5 : for APPLYING BREAKS");
							System.out.println("press 6 : EXIT CODE :");
							System.out.print("enter your sub choice : ");
							opt=sc.nextInt();
							switch(opt) {
							case 1 :
								car1.SpeedUp();
								car1.GearUp();
								System.out.println();
								break;
							case 2 :
								car1.SpeedDown();
								car1.GearDown();
								System.out.println();
								break;
							case 3 :
								car1.GearUp();
								car1.SpeedUp();
								System.out.println();
								break;
							case 4 :
								car1.GearDown();
								car1.SpeedDown();
								System.out.println();
								break;
							case 5 :
								car1.ApplyBreaks();
								car1.GearDown();
								System.out.println();
								break;
							case 6 :
								System.out.println("exit code : ");
								break;
							}
						}while(opt!=6);
						break;
					case 2 :
						do {
						    System.out.println("*******for BIKE**********");
							System.out.println("press 1 : for SPEED UP");
							System.out.println("press 2 : for SPEED DOWN");
							System.out.println("press 3 : for GEAR UP");
							System.out.println("press 4 : for GEAR DOWN");
							System.out.println("press 5 : for APPLYING BREAKS");
							System.out.println("press 6 : EXIT CODE :");
							System.out.print("enter your sub choice : ");
							opt=sc.nextInt();
							switch(opt) {
							case 1 :
								bike1.SpeedUp();
								bike1.GearUp();
								System.out.println();
								break;
							case 2 :
								bike1.SpeedDown();
								bike1.GearDown();
								System.out.println();
								break;
							case 3 :
								bike1.GearUp();
								bike1.SpeedUp();
								System.out.println();
								break;
							case 4 :
								bike1.GearDown();
								bike1.SpeedDown();
								System.out.println();
								break;
							case 5 :
								bike1.ApplyBreaks();
								bike1.GearDown();
								System.out.println();
							
								break;
							case 6 :
								System.out.println("exit code : ");
								break;
							}
							
						}while(opt!=6);
						break;
					case 3 :
						do {
						    System.out.println("****************for BICYCLE*************");
							System.out.println("press 1 : for SPEED UP");
							System.out.println("press 2 : for SPEED DOWN");
							System.out.println("press 3 : for GEAR UP");
							System.out.println("press 4 : for GEAR DOWN");
							System.out.println("press 5 : for APPLYING BREAKS");
							System.out.println("press 6 : EXIT CODE :");
							System.out.print("enter your sub choice : ");
							opt=sc.nextInt();
							switch(opt) {
							case 1 :
								bic1.SpeedUp();
								bic1.GearUp();
								System.out.println();
								break;
							case 2 :
								bic1.SpeedDown();
								bic1.GearDown();
								System.out.println();
								break;
							case 3 :
								bic1.GearUp();
								bic1.SpeedUp();
								System.out.println();
								break;
							case 4 :
								bic1.GearDown();
								bic1.SpeedDown();
								System.out.println();
								break;
							case 5 :
								bic1.ApplyBreaks();
								bic1.GearDown();
								System.out.println();
							
								break;
							case 6 :
								System.out.println("exit code : ");
								break;
							}
						}while(opt!=6);
						break;
					case 4 :
						System.out.println("exit code : ");
						break;
					}
				}while(ch!=4);
			}
			
}
