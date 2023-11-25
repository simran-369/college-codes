package oppsAss;
import java.util.*;
abstract class Shape{ //creation of abstract class
	double num1,num2;
	void input() { // creation of non-abstract method
		Scanner sc=new Scanner(System.in);
		System.out.println("enter FIRST PARAMETER of given shape  : ");
		num1=sc.nextDouble();
		System.out.println("enter SECOND PARAMETER of given shape : ");
		num2=sc.nextDouble();	
	}
	abstract void compute_area();
		//creation of abstract method
	
}
class Triangle extends Shape{
	void compute_area() { //using inheritance to use abstract method
		double area = 0.5*num1*num2;
		System.out.println("the area of triangle is : "+ area + " unit square");
	}
}
class Rectangle extends Shape{
	void compute_area() { //run time polymorphism
		double area = num1*num2;
		System.out.println("the area of rectangle is : "+ area + " unit square");
	}
}
class Circle extends Shape{
	double radius;
	void input() {
		Scanner sc=new Scanner(System.in);
		System.out.println("enter radius");
		radius=sc.nextDouble();
	}
	void compute_area() {
		double area= 3.14*radius*radius;
		System.out.println("area of given circle is : "+ area + " unit square");
	}
}
public class Driver {

	public static void main(String[] args) {
		Shape t = new Triangle(); //object creation
		Shape r = new Rectangle();
		Shape c= new Circle();
		Scanner sc = new Scanner(System.in);
		int choice;
		do {
			System.out.println("*******MENU*******");
			System.out.println("press 1. for TRIANGLE");
			System.out.println("press 2. for RECTANGLE");
			System.out.println("press 3. for CIRCLE");
			System.out.println("press 4. for EXIT");
			System.out.println("enter your CHOICE");
			choice=sc.nextInt();
			switch(choice) {
			case 1 :
				t.input();
				t.compute_area(); //showcasing method-overridding
				break;
			case 2 :
				r.input();
				r.compute_area();
				break;
			case 3 :
				c.input();
				c.compute_area();
				break;
			case 4 :
				System.out.println("exit code : ");
				break;
			default:
				System.out.println("enter valid choice");
				break;
			}
		}while(choice!=4);
		
	}

}
