/*code for complex number */
import java.util.*;
public class Complex{
float real, img;
Scanner sc= new Scanner(System.in);
/* function for taking input*/
public void giveInput(){
    System.out.print("REAL part of num= ");
    real = sc.nextFloat();
    System.out.print("IMAGINARY part num= ");
    img = sc.nextFloat();
}
/*function to perform add*/
public Complex add(Complex num2){
    Complex c3= new Complex();
    c3.real = this.real + num2.real;
    c3.img = this.img + num2.img;
    return c3;
}
/*function to perform subtraction*/
public Complex sub(Complex num2){
    Complex c4= new Complex();
    c4.real = this.real - num2.real;
    c4.img = this.img - num2.img;
    return c4;
}
/*function to perform multiplication*/
public Complex mult(Complex num2){
    Complex c5= new Complex();
    c5.real = (this.real*num2.real)-(this.img*num2.img);
    c5.img = (this.real*num2.img) +(this.img* num2.real);
    return c5;
}
/*function to perform division*/

public Complex div(Complex num2){
    
    Complex c6= new Complex();
    c6.real = ((this.real*num2.real)+(this.img*num2.img))/((num2.real* num2.real) + (num2.img*num2.img));
    c6.img = ((this.img* num2.real) - (num2.img*this.real))/((num2.real* num2.real) + (num2.img*num2.img));
    return c6;
}
/*function to create menu to perform operations*/
public static void main(String [] args){
    Complex num1 = new Complex();
    Complex num2 = new Complex();
    Scanner obj = new Scanner(System.in);
    System.out.println("complex num1 :  ");
    num1.giveInput();
    System.out.println("complex num2: ");
    num2.giveInput();
    while(num2.real==0 && num2.img==0){
        System.out.println("RE-ENTER the complex number 2: ");
        num2.giveInput();
    }
    int choice;
    do{
        System.out.println("...MENU given below : ");
        System.out.println("1.for ADD ");
        System.out.println("2.for SUBTRACT ") ;
        System.out.println("3.for MULTIPLY ");
        System.out.println("4.for DIVIDE ");
        System.out.println("5.for EXIT");
        System.out.println("Enter your choice :  ");
        choice = obj.nextInt();
        /*using switch to perform operation according to choice*/
        switch(choice){
            case 1 :
                num1=num1.add(num2);
                System.out.println("addition of complex numbers = " + num1.real +"+" + num1.img +"i");
                break;
            case 2 :
                num1= num1.sub(num2);
                System.out.println("substraction of complex numbers = " + num1.real +"+" + num1.img +"i");
                break;
            case 3 :
                num1=num1.mult(num2);
                System.out.println("multiplication of complex numbers = " + num1.real +"+" + num1.img +"i");
                break;
            case 4 :
                num1=num1.div(num2);
                System.out.println("division of complex numbers = " + num1.real +"+" + num1.img +"i");
                break;
             case 5 :
                 System.out.println("exit ");
                 break;
            default:
                break;
        }
    }while(choice!=6);
   }  
}
