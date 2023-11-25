/* Assignment:- 01 :
student database and showcase bubble sort,insertion sortr,quick sort etc on fields like name,roll no,sgpa 
*/
//CODE:

#include<bits/stdc++.h>
using namespace std;
int i;
struct student{
    int roll;
    string name;
    float sgpa;
} ;
void display(student *s[],int i){
    for(int j=0;j<i;j++){
              cout<<s[j]->roll<<" "<<s[j]->name<<" "<<s[j]->sgpa<<endl;
    }
}
void linearSearch(float x,int i,student *s[]){
    bool b=0;
    for(int j=0;j<i;j++){
        if(s[j]->sgpa==x){
            cout<<s[j]->roll<<" "<<s[j]->name<<" "<<s[j]->sgpa<<endl;
            b=1;
        }
    }
    if(b==0){
        cout<<"NO STUDENT FOUND"<<endl;
    }
}
void bubble_sort_roll(student *s[],int n){
    bool b=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(s[j]->roll>s[j+1]->roll){
                //swaping(s[j],s[j+1])
                student *temp=new student;
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                b=1;
            }
        }
        if(b==0)break;
    }
}
void bubble_sort_name(student *s[],int n){
    bool b=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(s[j]->name>s[j+1]->name){
                //swaping(s[j],s[j+1])
                student *temp=new student;
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                b=1;
            }
        }
        if(b==0)break;
    }
}
void binarySearch(string s1,int i,student *s[]){
    int lb=0;
    int ub=i-1;
    int mid=(lb+ub)/2;
    bool b=1;
    while(lb<=ub){
        if(s[mid]->name==s1){
            cout<<s[mid]->roll<<" "<<s[mid]->name<<" "<<s[mid]->sgpa<<endl;
            b=0;
            return;
        }
        else if(s[mid]->name>s1){
            ub=mid-1;
        }
        else{
            lb=mid+1;
        }
        mid=(ub+lb)/2;
    }
    if(b==1){
        cout<<"NO STUDENT FOUND"<<endl;
    }
}
void insertion_sort_name(student *s[],int i){
    for(int t=1;t<i;t++){
        for(int j=t;j>0;j--){
            if(s[j-1]->name > s[j]->name){
                student *temp =new student;
                temp =s[j];
                s[j]=s[j-1];
                s[j-1]=temp;
            }

        }
    }
}
int lomuto(student *s[],int l,int h){
	float pivot=s[h]->sgpa;
	int i=l-1;
	//c(pivot);
	for(int j=l;j<h;j++){
		//c(s[j]);
		if((s[j]->sgpa)>pivot){
			i++;
			swap(s[i],s[j]);
		}
	}//c(i);
	swap(s[i+1],s[h]);
	return (i+1);
}
void qsort(student *s[],int l,int h){
	if(l<h){
		int p=lomuto(s,l,h);
		qsort(s,l,p-1);
		qsort(s,p+1,h);

	}
}
  
int main(){
    int n;
    student *s[60];
    int i=0;
    do{
        s[i]=new student;
        cout<<"enter the ROLL_NUM"<<endl;
        cin>>s[i]->roll;
        cout<<"enter the NAME"<<endl;
        cin>>s[i]->name;
        cout<<"enter the SGPA"<<endl;
        cin>>s[i]->sgpa;
        i++;
        cout<<"do you want to store data?";
        cin>>n;
    }while(n==1);
    int k;
    do{
        cout<< "press 1 for DISPLAY"<<endl;
cout<<"press 2 for LINEAR SEARCH"<<endl<<"press 3 for BUBBLE SORT"<<endl;
cout<<"press 4 for BINARY SEARCH"<<endl<<"press 5 for INSERTION SORT"<<endl;
cout<<"press 6 for QUICK SORT"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1 :
                 { display(s,i);
                    break;}

            case 2 :
             {cout<<"enter SGPA to be found"<<endl;
                float x; cin>>x;
                linearSearch(x,i,s);
                break;}     

            case 3 :
            {bubble_sort_roll(s,i);
            for(int j=0;j<i;j++){
                    cout<<s[j]->roll<<" "<<s[j]->name<<" "<<s[j]->sgpa<<endl;
                }
            break;}

            case 4 :
            {cout<<"enter NAME to be found"<<endl;
            string s1; cin>>s1;
             bubble_sort_name(s,i);
             binarySearch(s1,i,s);
             break;}

             case 5 :
             {insertion_sort_name(s,i);
             for(int j=0;j<i;j++){
                    cout<<s[j]->roll<<" "<<s[j]->name<<" "<<s[j]->sgpa<<endl;
                }
                break;}

             case 6 :
             {qsort(s,0,i-1);
              for(int j=i-1;j>=(i-10);j--){
                    cout<<s[j]->roll<<" "<<s[j]->name<<" "<<s[j]->sgpa<<endl;
                }
                break;
                }
        }
        cout<<"DO YOU WANT TO CONTINUE"<<endl;
        cin>>k;
    }while(k==1);    
    return 0;
}

/*
OUTPUT :

enter the ROLL_NUM
50
enter the NAME
aaA
enter the SGPA
7.3
do you want to store data?1
enter the ROLL_NUM
12
enter the NAME
aaa
enter the SGPA
7.2
do you want to store data?1
enter the ROLL_NUM
35
enter the NAME
aAA
enter the SGPA
7.4
do you want to store data?1
enter the ROLL_NUM
15
enter the NAME
aAa
enter the SGPA
7.2
do you want to store data?1
enter the ROLL_NUM
29
enter the NAME
aaA
enter the SGPA
7.4
do you want to store data?1
enter the ROLL_NUM
12
enter the NAME
aaaa
enter the SGPA
7.8
do you want to store data?1
enter the ROLL_NUM
47
enter the NAME
aAAa
enter the SGPA
7.2
do you want to store data?1
enter the ROLL_NUM
1
enter the NAME
aAA 
enter the SGPA
7.3
do you want to store data?1
enter the ROLL_NUM
43
enter the NAME
aaa
enter the SGPA
7.9
do you want to store data?1
enter the ROLL_NUM
17
enter the NAME
aaA
enter the SGPA
7.9
do you want to store data?1
enter the ROLL_NUM
38
enter the NAME
aaB
enter the SGPA
7.1
do you want to store data?1
enter the ROLL_NUM
25
enter the NAME
aaBb
enter the SGPA
7.1
do you want to store data?1
enter the ROLL_NUM
49
enter the NAME
aabb
enter the SGPA
7.2
do you want to store data?1
enter the ROLL_NUM
10
enter the NAME
aabB
enter the SGPA
7.3
do you want to store data?2
press 1 for DISPLAY
press 2 for LINEAR SEARCH
press 3 for BUBBLE SORT
press 4 for BINARY SEARCH
press 5 for INSERTION SORT
press 6 for QUICK SORT
1
50 aaA 7.3
12 aaa 7.2
35 aAA 7.4
15 aAa 7.2
29 aaA 7.4
12 aaaa 7.8
47 aAAa 7.2
1 aAA 7.3
43 aaa 7.9
17 aaA 7.9
38 aaB 7.1
25 aaBb 7.1
49 aabb 7.2
10 aabB 7.3

2:
enter SGPA to be found
7.9
43 aaa 7.9
17 aaA 7.9

3:
1 aAA 7.3
10 aabB 7.3
12 aaa 7.2
12 aaaa 7.8
15 aAa 7.2
17 aaA 7.9
25 aaBb 7.1
29 aaA 7.4
35 aAA 7.4
38 aaB 7.1
43 aaa 7.9
47 aAAa 7.2
49 aabb 7.2
50 aaA 7.3

4:
enter NAME to be found
aaa
43 aaa 7.9

5:
1 aAA 7.3
35 aAA 7.4
47 aAAa 7.22
15 aAa 7.2
17 aaA 7.9
29 aaA 7.4
50 aaA 7.3
38 aaB 7.1
25 aaBb 7.1
12 aaa 7.2
43 aaa 7.9
12 aaaa 7.8
10 aabB 7.3
49 aabb 7.2

6:
38 aaB 7.1
25 aaBb 7.1
15 aAa 7.2
12 aaa 7.2
47 aAAa 7.2
49 aabb 7.2
50 aaA 7.3
1 aAA 7.3
10 aabB 7.3
35 aAA 7.4
*/