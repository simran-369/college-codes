
package sim;
import java.util.*;
class Employee {
    Scanner sc = new Scanner(System.in);
    String name;
    int empID;
    String address;
    String mobileNo;
    String email;
    void getData(){
    	System.out.println("enter employee NAME");
        name=sc.nextLine();
        while(!name.matches("^[-a-zA-Z]*$")) {
        	System.out.println("re-enter a valid name");
        	name=sc.nextLine();
        }
        System.out.println("enter employee ID");
        empID= sc.nextInt();
        System.out.println("enter employee ADDRESS");
        address = sc.next();
        System.out.println("enter employee MOBILE NUM");
        mobileNo = sc.next();
        while((mobileNo.length()!=10) || mobileNo.matches("[a-zA-Z]+") || mobileNo.charAt(0)=='0') {
        	 System.out.println("Re-enter valid employee MOBILE NUM");
             mobileNo = sc.next();
        }
        System.out.println("enter employee EMAIL");
        email = sc.next();
        while(!email.matches(".+@gmail.com")) {
        	System.out.println("re-enter a valid email");
        	email=sc.next();
        }
    }
        void display() {
        	System.out.println(".....*****   PAY SLIP   *****.....");
        	System.out.println("EMPLOYEE NAME : " + name);
        	System.out.println("EMPLOYEE ID  : " + empID);
        	System.out.println("EMPLOYEE ADDRESS : " + address);
        	System.out.println("EMPLOYEE MOBILE NUMBER : " + mobileNo) ;
        	System.out.println("EMPLOYEE EMAIL ADDRESS : " + email) ;
        	
        }
    }

    class Programmer extends Employee{
        Scanner obj = new Scanner(System.in);
        double BP;
        void basic_pay_prog(){
        System.out.println("enter BASIC PAY of PROGRAMMER");
        BP = obj.nextDouble();
        }
        double DA,HRA,PF,SCF,grossSalary,netSalary;
        void calculation_prog(){
            DA = 0.97*BP;
            HRA = 0.1*BP;
            PF= 0.12*BP;
            SCF=0.001*BP;
            grossSalary= BP+DA+HRA;
            netSalary = grossSalary - PF- SCF;
            System.out.println("GROSS SALARY of employee is : " + grossSalary );
            System.out.println("NET SALARY of employee is : " + netSalary );
        }

    }
    class TeamLead extends Employee{
    	  Scanner scn = new Scanner(System.in);
          double BP;
          void basic_pay_tl(){
          System.out.println("enter BASIC PAY of TEAM LEAD");
          BP = scn.nextDouble();
          }
          double DA,HRA,PF,SCF,grossSalary,netSalary;
          void calculation_tl(){
              DA = 0.97*BP;
              HRA = 0.1*BP;
              PF= 0.12*BP;
              SCF=0.001*BP;
              grossSalary= BP+DA+HRA;
              netSalary = grossSalary -PF-SCF;
              System.out.println("GROSS SALARY of employee is : " + grossSalary );
              System.out.println("NET SALARY of employee is : " + netSalary );
          }

      }
    class APM extends Employee{
    	  Scanner obj = new Scanner(System.in);
          double BP;
          void basic_pay_apm(){
          System.out.println("enter BASIC PAY of ASSISTANT PROJECT MANAGER");
          BP = obj.nextDouble();
          }
          double DA,HRA,PF,SCF,grossSalary,netSalary;
          void calculation_apm(){
              DA = 0.97*BP;
              HRA = 0.1*BP;
              PF= 0.12*BP;
              SCF=0.001*BP;
              grossSalary= BP+DA+HRA;
              netSalary = grossSalary -PF-SCF;
              System.out.println("GROSS SALARY of employee is : " + grossSalary );
              System.out.println("NET SALARY of employee is : " + netSalary );
          }

      }
      
    class PM extends Employee{
  	  Scanner obj = new Scanner(System.in);
      double BP;
      void basic_pay_pm(){
      System.out.println("enter BASIC PAY of PROJECT MANAGER");
      BP = obj.nextDouble();
      }
      double DA,HRA,PF,SCF,grossSalary,netSalary;
      void calculation_pm(){
          DA = 0.97*BP;
          HRA = 0.1*BP;
          PF= 0.12*BP;
          SCF=0.001*BP;
          grossSalary= BP+DA+HRA;
          netSalary = grossSalary -PF-SCF;
          System.out.println("GROSS SALARY of employee is : " + grossSalary );
          System.out.println("NET SALARY of employee is : " + netSalary );
      } 	
    }
    	
public class Driver{
    public static void main(String[]args){
    	Scanner obj =new Scanner(System.in);
        Programmer emp1 = new Programmer();
        TeamLead emp2 = new TeamLead();
        APM emp3 = new APM();
        PM emp4 = new PM();
        //creating MENU
        int choice;
        do {
        	System.out.println("....***********MENU given below*************");
        	System.out.println(" 1. for PROGRAMMER");
        	System.out.println(" 2. for TEAM LEAD");
        	System.out.println(" 3. for ASSISTANT PROJECT MANAGER ");
        	System.out.println(" 4. for PROJECT MANAGER");
        	System.out.println(" 5. for EXIT");
        	System.out.print(" enter your CHOICE");
        	choice = obj.nextInt();
        	switch(choice) {
        	case 1 :
                emp1.getData();
                emp1.basic_pay_prog();
                emp1.display();
                emp1.calculation_prog();
                System.out.println();
                break;
        	case 2 :
                emp2.getData();
                emp2.basic_pay_tl();
                emp2.display();
                emp2.calculation_tl();
                System.out.println();
                break;
        	case 3 :
                emp3.getData();
                emp3.basic_pay_apm();
                emp3.display();
                emp3.calculation_apm();
                System.out.println();
                break;
        	case 4 :
                emp4.getData();
                emp4.basic_pay_pm();
                emp4.display();
                emp4.calculation_pm();
                System.out.println();
                break;
        	case 5 :
        		System.out.println("EXIT");
        		break;
        	default :
        		break;
        	}
    } 
        while(choice!=8);
}
}


