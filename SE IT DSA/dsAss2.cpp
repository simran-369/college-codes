/* 
Assignment No.2
Title:- Stack
Problem Statement:- Implement stack as an abstract data type
using singly linked list and use this ADT for conversion of infix
expression to postfix, prefix and evaluation of postfix and prefix
expression.
//CODE*/
#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};
//to make it public 
class stack1{
node *top;
    public:
    stack1(){
        top=NULL;
    }
int isEmpty(){
    if(top==NULL)
    return 1;
    else
    return 0;
}
void push(int x){
    node *temp = new node(x);
    if(top==NULL){
        temp->next=NULL;
    }
    else{
        temp->next=top;
    }
    top=temp;
}
void pop(){
    if(isEmpty()==1){
        cout<<"stack UNDERFLOW\n";
    }
    else{
        node *temp=top;
        cout<<temp->data<<"deleted from top successfully \n";
        top=top->next;
        delete temp;
    }
}
void display(){
    node *ptr = top;
    if(isEmpty()==1){
        cout<<"stack is empty \n";
    }
    else{
        while(ptr != NULL){
            cout<< ptr->data<<' ';
            ptr = ptr->next;
        }
        cout<<ptr->data<<endl;
        }
    }
};
bool isOperator(char ch){
 if (ch =='+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') 
 return true;
 else
 return false;
}
//Function to check priority of operator
int checkPrecedence(char ch){
 if (ch == '^' || ch == '$')
 return 3;
 if (ch == '*' || ch == '/')
 return 2;
 if(ch =='+' || ch == '-')
 return 1;
 else
 return -1;
}
//FUNCTION FOR INFIX TO POSTFIX CONVERSION 
string InfixToPostfix(stack<char> s, string infix ){
 string postfix;
 for (int i = 0; i < infix.length(); i++)
 {
 	if ((infix[i] >= 'A' && infix[i] <='Z')||(infix[i] >= 'a' && infix[i] <= 'z'))
 	{
 		postfix += infix[i];
 	}
 	else if(infix[i] == '('){
 		s.push(infix[i]);
	}
 	else if(infix[i] == ')')
	{
 		while ((s.top() != '(') && (!s.empty()))
 		{
 		postfix += s.top();
 		s.pop();
 		}
 		if(s.top() == '(')
 		s.pop();
 	}
 	else if(isOperator(infix[i]))
	{
 		if(s.empty())
 		{
 			s.push(infix[i]);
 		}
 		else
 		{
 			if (checkPrecedence(infix[i]) == checkPrecedence(s.top()) && infix[i] =='^')
 			{ 
			 	s.push(infix[i]);
			}
 			else
 			{
 				while ((!s.empty()) && (checkPrecedence(infix[i]) <=
				checkPrecedence(s.top())))
 				{
				    postfix+=s.top();
				    s.pop();
 				}
 			s.push(infix[i]);
 			}
 		}
 	}
}
 while (!s.empty())
 {
	 postfix += s.top();
	 s.pop();
 }
 return postfix;
}
 // INFIX TO PREFIX CONVERSION FUNCTION
 string InfixToPrefix(stack<char> s, string infix)
 {
	string prefix;
	reverse(infix.begin(), infix.end());
	for (int i = 0; i < infix.length(); i++)
 	{
	 	if (infix[i] == '(')
	 	infix[i] = ')';
	 	
 		else if (infix[i] == ')')
 		infix[i] = '(';
 	}
 	for (int i = 0; i < infix.length(); i++)
 	{
	if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i]<= 'Z'))
	prefix += infix[i];
	 
	else if (infix[i] == '(') 
	s.push(infix[i]);
	 
	else if (infix[i] == ')')
 	{
	 	while (s.top() != '(' && (!s.empty())) 
	 	{
			prefix += s.top();
			s.pop(); //remove top of the stack
  	 	}
		if (s.top() == '(') 
		{
	 		s.pop();
	 	}
 	}
 	else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] =='/' || infix[i] == '^')
 	{
 		if (s.empty())
 		s.push(infix[i]);
 		
 		else
 		{
 			if (checkPrecedence(infix[i]) > checkPrecedence(s.top())){
 				s.push(infix[i]); 
			}
 			else if ((checkPrecedence(infix[i]) == checkPrecedence(s.top())) && (infix[i] == '^'))
 			{
 				while ((s.empty() != true) && (checkPrecedence(infix[i]) ==
				checkPrecedence(s.top())) && (infix[i] == '^'))
	 			{
	 				if (s.empty() != true)
	 				{
 						prefix += s.top();
 						s.pop();
 					}
 				}
 				
 			s.push(infix[i]);
 			}
 		 	else if (checkPrecedence(infix[i]) == checkPrecedence(s.top()))
 			{
			 	s.push(infix[i]);
			}
 			else
 			{
 				while ((!s.empty()) && (checkPrecedence(infix[i]) < checkPrecedence(s.top())))
 				{
					prefix += s.top();
					s.pop(); 
 				}
 			s.push(infix[i]);
 			}
 		}
 	}
 	}
 	while (!s.empty())
 	{
 		prefix += s.top();
 		s.pop();
 	}
 	reverse(prefix.begin(), prefix.end());
 	return prefix;
 }
/*Evaluation of Postfix Expression*/
int postfixToInfix(string postfix)
{
 stack <int> s;
 int ans = 0;
 for (int i = 0; i < postfix.length(); i++)
 {
	if (((postfix[i] - '0')>= 0 && (postfix[i] - '0') <= 9))  
	s.push(postfix[i] - '0');
	
	else if (isOperator(postfix[i]))
	{
		int op1= s.top();
		s.pop();
		int op2 = s.top(); 
		s.pop();
 	switch (postfix[i])
 	{
		case '+' :
			ans = op2 + op1;
			break;
			
		case '-':
			ans = op2 - op1;
			break;
			
		case '*':
			ans = op2 * op1;
			break;
		
		case '/':
			ans = op2 / op1 ;
			break;
		
		case '^':
			ans = int(pow(op2,op1));
			break;
		
		default:
			break;
	}
 	s.push(ans);
 	}
 } 
 	return s.top();
}
/*Evaluation of Prefix Expression*/
int prefixToInfix(string prefix)
{
	stack <int> s;
	int ans = 0; 
	for (int i = prefix.length(); i >= 0; i--)
 	{
 		if (((prefix[i] - '0')>= 0 && (prefix[i] - '0') <= 9)) 
 		s.push(prefix[i] - '0');
 		
 		else if (isOperator(prefix[i]))
 		{
 		int op1= s.top();
 		s.pop();
		int op2 = s.top();
 		s.pop();
 		switch (prefix[i])
 		{
			case '+' :
			 	ans = op1 + op2;
			 	break;
			 	
			case '-':
			 	ans = op1 - op2;
			 	break;
			 	
			case '*':
			 	ans = op1 * op2;
			 	break;
			 	
			case '/': 
			 	ans = op1 / op2 ;
			 	break;
			 	
			case '^':
			 	ans = int(pow(op1,op2));
			 	break;
			 	
			default:
			 	break;	 	
		}
 		s.push(ans);
 		}
 	}
 	return s.top();
}
int main(){
	int choice;
	string postfix,infix,prefix;
	do {
		cout<<"---------------MENU!!-----------"<<endl;
		cout<<"PRESS 1. for INFIX to POSTFIX\n";
		cout<<"PRESS 2. for POSTFIX EVALUATION\n";
		cout<<"PRESS 3. for INFIX to PREFIX\n";
		cout<<"PRESS 4. for PREFIX EVALUATION\n";
		cout<<"PRESS 5. for EXIT\n";
		cout<<"ENTER your CHOICE\n";
		cin>>choice;
		cout<<endl;
		switch(choice){
			case 1:{
				cout<<"enter INFIX expression : \n";
				cin>>infix;
				stack<char>stack;
				postfix=InfixToPostfix(stack,infix);
				cout<<"\nthe POSTFIX expression is :"<<postfix<<endl;
				break;
			}
			case 2:{
				double infix;
				cout<<"enter POSTFIX expression : \n";
				cin>>postfix;
				stack<char>stack;
				infix=postfixToInfix(postfix);
				cout<<"\nthe EVALUATED POSTFIX expression is :"<<infix<<endl;
				break;
			}
			case 3:{
				cout<<"enter INFIX expression : \n";
				cin>>infix;
				stack<char>stack;
				prefix=InfixToPrefix(stack,infix);
				cout<<"\nthe PREFIX expression is :"<<prefix<<endl;
				break;
			}
			case 4:{
			double infix;
			cout<<"enter PRETFIX expression : \n";
			cin>>prefix;
			stack<char>stack;
			infix=prefixToInfix(prefix);
			cout<<"\nthe EVALUATED PRETFIX expression is :"<<infix<<endl;
			break;
			}
		}
	}while(choice!=5);
	return 0;
}
/*
OUTPUT:
---------------MENU!!-----------
PRESS 1. for INFIX to POSTFIX
PRESS 2. for POSTFIX EVALUATION
PRESS 3. for INFIX to PREFIX
PRESS 4. for PREFIX EVALUATION
PRESS 5. for EXIT
ENTER your CHOICE
1:
enter INFIX expression : 
((a+b)*(c-d))/e
the POSTFIX expression is :ab+cd-*e/

2:
enter POSTFIX expression :
53+82-*
the EVALUATED POSTFIX expression is :48

3:
enter INFIX expression :
(a-b/c)*(d*e-f)
the PREFIX expression is :*-a/bc-*def

4 :
enter PREFIX expression :
-+8/632
the EVALUATED PRETFIX expression is :8


*/