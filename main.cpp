//#include<bits/stdc++.h>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include "addition.h"
#include<math.h>
//#include<strstream>
#include<string>
#include<limits.h>
#include<windows.h>

using namespace std;

int num=0,zee=0;
int initial=0;

struct node{
int empid,age;string name;
double  salary;double pf;double health;string email;node *next;
};
void pushX(int num){
    for(int i=0;i<num;i++)
        cout<<" ";
}


class empl{
    node *head,*tail;
public:
    empl(){head=NULL;tail=NULL;}
    void inser(int emp,string nam,int age,double sal,double pff,double hea,string ema){num++;
            node *temp=new node;
            temp->next=NULL;temp->age=age;temp->email=ema;temp->empid=emp;temp->salary=sal;temp->pf=pff;temp->health=hea;temp->name=nam;
            starname.push_back(temp->empid);
            rating.push_back("");
            if(head==NULL){
                head=temp;tail=temp;
            }
            else{
                tail->next=temp;tail=temp;
            }
            //cout<<"added successfully"<<endl;

    }
    void display(){
        cout<<endl;
cout<<setw(10)<<left<<"Empid"
    <<setw(24)<<left<<"Name"
    <<setw(15)<<left<<"Age"
    <<setw(30)<<left<<"Email"
    <<setw(15)<<right<<"Salary"
    <<setw(15)<<right<<"PF"
    <<setw(15)<<right<<"Health"
    //<<setw(15)<<right<<"net pay"
    <<endl<<endl;

        node *temp=new node;
        temp=head;
        while(temp!=NULL){
        cout<<setw(10)<<left<<temp->empid
        <<setw(24)<<left<<temp->name
        <<setw(15)<<left<<temp->age
        <<setw(30)<<left<<temp->email
        <<setw(15)<<fixed<<right<<setprecision(2)<<temp->salary
        <<setw(15)<<fixed<<right<<setprecision(2)<<temp->pf
        <<setw(15)<<fixed<<right<<setprecision(2)<<temp->health
        //<<setw(10)<<fixed<<right<<setprecision(2)<<netsal(emplo)
        <<endl;
        /*
            cout<<temp->empid<<"  "<<temp->name<<" "<<temp->email<<" "<<temp->salary<<" "<<temp->pf<<" "<<temp->health;
            */cout<<endl;
            temp=temp->next;
        }


    }
    void dispar(int pos){
        cout<<endl;
        cout<<setw(10)<<left<<"Empid"
    <<setw(24)<<left<<"Name"
    <<setw(15)<<left<<"Age"
    <<setw(30)<<left<<"Email"
    <<setw(15)<<right<<"salary"
    <<setw(15)<<right<<"pf"
    <<setw(15)<<right<<"Health"
    //<<setw(15)<<right<<"net pay"
    <<endl<<endl;
        pos--;node *temp=new node;temp=head;
        if(pos==0){
            //cout<<temp->empid<<"  "<<temp->name<<"  "<<temp->age<<" "<<temp->email<<"  "<<temp->salary<<"  "<<temp->pf<<"  "<<temp->health;
            cout<<setw(10)<<left<<temp->empid
        <<setw(24)<<left<<temp->name
        <<setw(15)<<left<<temp->age
        <<setw(30)<<left<<temp->email
        <<setw(15)<<fixed<<right<<setprecision(2)<<temp->salary
        <<setw(15)<<fixed<<right<<setprecision(2)<<temp->pf
        <<setw(15)<<fixed<<right<<setprecision(2)<<temp->health
        //<<setw(10)<<fixed<<right<<setprecision(2)<<netsal(emplo)
        <<endl;
            return;
        }
        for(int i=0;i<pos;i++){
            temp=temp->next;
        }
        //cout<<temp->empid<<"  "<<temp->name<<"  "<<temp->age<<" "<<temp->email<<"  "<<temp->salary<<"  "<<temp->pf<<"  "<<temp->health;
        cout<<setw(10)<<left<<temp->empid
        <<setw(24)<<left<<temp->name
        <<setw(15)<<left<<temp->age
        <<setw(30)<<left<<temp->email
        <<setw(15)<<fixed<<right<<setprecision(2)<<temp->salary
        <<setw(15)<<fixed<<right<<setprecision(2)<<temp->pf
        <<setw(15)<<fixed<<right<<setprecision(2)<<temp->health
        //<<setw(10)<<fixed<<right<<setprecision(2)<<netsal(emplo)
        <<endl;
    }
    void delet(int pos){
    pos--;
    if(head==NULL){cout<<"empty list,cannot delete"<<endl;return;}
    if(pos==0){
        if(head->next==NULL){
            delete head;delete tail;head=NULL;tail=NULL;return;
        }
        else{
            node *temp=new node;
            temp=head->next;delete head;
            head=temp;
            cout<<"deleted successfully"<<endl;
            return;
        }
    }
    else{
        node *cur=head,*pre;
        for(int i=0;i<pos;i++){
            pre=cur;cur=cur->next;
        }
        pre->next=cur->next;
        delete cur;//cur=pre;
        cout<<"deleted successfully"<<endl;
        return;
    }
    starname.erase(starname.begin()+pos,starname.begin()+pos+1);
    rating.erase(rating.begin()+pos,rating.begin()+pos+1);
    }

    int check(int idd){
        int c=0,flag=0;
    if(head==NULL){
        cout<<"list already empty"<<endl;return 0;
    }
    else{
        node *temp=new node;temp=head;
        while(temp!=NULL){c++;
            if(idd==temp->empid){
                flag=1;break;
            }
            temp=temp->next;

        }
        if(flag==1){
            return c;
        }
        else{
            return 0;
        }
    }
    }
    void autosave(){
        ofstream fout("empsdfs.txt", ios::out | ios::trunc);node *it=new node;it=head;int rec(0);
    if(!fout){cout<<"file was not opened.Please check if it exists"<<endl;return;}
    while(it!=NULL){rec++;
        fout<<it->empid<<","<<it->name<<","<<it->age<<","<<it->email<<","<<it->salary<<","<<it->pf<<","<<it->health;it=it->next;
    if(rec<num){fout<<endl;}

    }
    fout.close();
    }
    void savestar(){
        starname.clear();rating.clear();
        node *temp=new node;
        temp=head;
        while(temp!=NULL){
            starname.push_back(temp->empid);
            temp=temp->next;
        }
        rating.resize(starname.size(),"");
    }
};

void checkbonus();
void moree(empl);
void dotask(int n,empl &);
void readfile(empl &);
void printmenu();
void enterdata(empl &);
void more();
void askfor(empl &);
bool checkpass();
bool checkpass2();
string getpass(const char *,bool);
void updatestar();
void getreport();
void updatesal();

int main()
{

    for(int j=0;j<50;j++){
        system("CLS");
        pushX(j);
        cout<<"WELCOME TO THE EMPLOYEE MANAGEMENT SYSTEM"<<endl;
        Sleep(20);
    }
    if(checkpass2()){cout<<"password correct"<<endl<<endl;}
    else{
        exit(1);
    }
    empl emp;
    cout<<"\ndata already existing:\n\n"<<endl;
    readfile(emp);
    askfor(emp);
    /*vector<int> vec;
    for(int i=0;i<5;i++){
		cin>>vec[i];
	}
	cout<<vec[0];*/
    return 0;
}

void askfor(empl &emplo){

    while(1){
    printmenu();
    cout<<endl<<"enter your choice:";
    int x;cin>>x;
    dotask(x,emplo);
    }
}

void readfile(empl &emplo){
    ifstream fin;
    fin.open("empsdfs.txt");
    if(!fin){
        cout<<"file does not exist";
        exit(1);
    }
    string line;int norec;
    cout<<setw(10)<<left<<"EMPID"
        <<setw(24)<<left<<"NAME"
        <<setw(15)<<left<<"AGE"
        <<setw(30)<<left<<"EMAIL"
        <<setw(15)<<right<<"SALARY"
        <<setw(15)<<right<<"PF"
        <<setw(15)<<right<<"HEALTH"
    //<<setw(15)<<right<<"net pay"
    <<endl<<endl;
    while(!fin.eof()){initial++;
        getline(fin,line);norec++;
        istringstream iss(line);string empid,age,nam,salar,pff,healt,emails;
        getline(iss,empid,',');
        getline(iss,nam,',');
        getline(iss,age,',');
        getline(iss,emails,',');
        getline(iss,salar,',');
        getline(iss,pff,',');
        getline(iss,healt,',');


    cout<<setw(10)<<left<<empid
        <<setw(24)<<left<<nam
        <<setw(15)<<left<<age
        <<setw(30)<<left<<emails
        <<setw(15)<<fixed<<right<<setprecision(2)<<salar
        <<setw(15)<<fixed<<right<<setprecision(2)<<pff
        <<setw(15)<<fixed<<right<<setprecision(2)<<healt
        //<<setw(10)<<fixed<<right<<setprecision(2)<<netsal(emplo)
        <<endl;
        //cout<<empid<<"   "<<nam<<"  "<<salar<<"   "<<pff<<"   "<<healt<<"  "<<emails<<endl;
        stringstream geek(empid);
        int emid;
        geek>>emid;
        stringstream geek1(salar);
        double sala;
        geek1>>sala;
        stringstream geek6(age);
        double aggg;
        geek6>>aggg;
        stringstream geek2(pff);
        double pfff;
        geek2>>pfff;
        stringstream geek3(healt);
        double heal;
        geek3>>heal;
        emplo.inser(emid,nam,aggg,sala,pfff,heal,emails);
    }
    fin.close();
}


void printmenu(){
    cout<<"\nPress Any Of The Following Keys:-"<<endl<<endl
        <<"1-Add Employee"<<endl
        <<"2-Print Employee Report"<<endl
        <<"3-Search Employee"<<endl
        <<"4-Delete Employee"<<endl
        <<"5-SAVE"<<endl
        <<"6-EXIT"<<endl
        <<"7-MORE"<<endl;

}


void enterdata(empl &emplo){
    int empid,age;string name;
double salary;double pf;
double health;string email;
cout<<"enter empid:";cin>>empid;
cin.clear();
cin.ignore(INT_MAX,'\n');
cout<<"enter name:";getline(cin,name);
cout<<"enter age:";cin>>age;
cout<<"enter salary:";cin>>salary;
cout<<"enter pf:";cin>>pf;
cout<<"enter health:";cin>>health;
cin.clear();
cin.ignore(INT_MAX,'\n');
cout<<"enter email id:";cin>>email;
emplo.inser(empid,name,age,salary,pf,health,email);
}



void dotask(int n,empl &emplo){
    int g,gg;
    switch(n){
    case 1:enterdata(emplo);cout<<"\nADDED SUCCESSFULLY"<<endl;break;
    case 2:emplo.display();break;
    case 3:int x;cout<<"\nEnter the empid of the employee you want to search:";cin>>x;g=emplo.check(x);if(g!=0){cout<<"\nEmployee found at position "<<g-1<<" with following info:-"<<endl;emplo.dispar(g);}else{cout<<"\nNo such employee found"<<endl;}break;
    case 4:int y;cout<<"\nEnter the empid of the employee you want to delete:";cin>>y;gg=emplo.check(y);if(gg!=0){emplo.delet(gg);}else{cout<<"\nNo such employee found"<<endl;}break;
    case 5:emplo.autosave();/*emplo.savestar();*/cout<<"\nChanges Saved Successfully"<<endl;break;
    case 6:cout<<"\nTHANK YOU"<<endl;exit(0);
    case 7:if(checkpass()){moree(emplo);}else{emplo.autosave();cout<<"exit";exit(1);}break;/*if(checkpass(emplo)){cout<<"You have entered the administration section:-"<<endl;moree(emplo);}else{cout<<"You have exceeded the limit.We have locked the system.We are directing you back to the main menu...."<<endl;}break;*/
    default:cout<<"\nEnter again please "<<endl;
    }
}

void more(){
    cout<<endl<<"WELCOME TO THE SPECIAL MENU"<<endl
        <<"a-for updating star report of employees"<<endl
        <<"b-for getting the star report of employees"<<endl
        <<"c-to exit this section"<<endl
        <<"d-for updating the bonus of the employees"<<endl
        <<"e-check the bonus of the employees"<<endl;
}

void moree(empl emplo){

    while(1){
            more();
            abc:
       char c;cout<<endl<<"Enter your choice:";cin>>c;
       switch(c){
        case 'a':updatestar();break;
        case 'b':getreport();break;
        case 'c':cout<<"Thank You.Redirecting to the main menu"<<endl;askfor(emplo);break;
        case 'd':updatesal();break;
        case 'e':checkbonus();break;
        default:cout<<"Enter again"<<endl;goto abc;
    }
    }
}
void checkbonus(){
     cout<<setw(20)<<left<<"EMPID"<<setw(20)<<left<<"BONUS"<<endl;
    for(int i=0;i<starname.size();i++){
        cout<<setw(20)<<left<<starname[i]<<setw(20)<<left<<bonus[i]<<endl;
    }
}
void updatesal(){
    bonus.clear();
    for(int i=0;i<rating.size();i++){
        string b=rating[i];
        int cc=b.length();
        switch(cc){
            case 1:bonus.push_back(2000);break;
            case 2:bonus.push_back(4000);break;
            case 3:bonus.push_back(6000);break;
            case 4:bonus.push_back(8000);break;
            case 5:bonus.push_back(10000);break;
            default:bonus.push_back(0);break;
        }
    }
    cout<<"\nSuccessfully updated the extra pay"<<endl;
}
void getreport(){
    cout<<setw(20)<<left<<"EMPID"<<setw(20)<<left<<"RATING"<<endl;
    for(int i=0;i<starname.size();i++){
        cout<<setw(20)<<left<<starname[i]<<setw(20)<<left<<rating[i]<<endl;
    }
}
void updatestar(){
    int empi;string rati;cout<<"enter the empid for which you want to update the star rating:";
    cin>>empi;
    int a;
    for(int i=0;i<starname.size();i++){
        if(starname[i]==empi){
            a=i;
        }
    }
    cout<<"enter the new rating(*):";
    cin>>rati;
    rating[a]=rati;
    cout<<"Successfully Updated"<<endl;
}
string getpass(const char *prompt, bool show_asterisk=true)
{
  const char BACKSPACE=8;
  const char RETURN=13;

  string password;
  unsigned char ch=0;

  cout <<prompt<<endl;

  DWORD con_mode;
  DWORD dwRead;

  HANDLE hIn=GetStdHandle(STD_INPUT_HANDLE);

  GetConsoleMode( hIn, &con_mode );
  SetConsoleMode( hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

  while(ReadConsoleA( hIn, &ch, 1, &dwRead, NULL) && ch !=RETURN)
    {
       if(ch==BACKSPACE)
         {
            if(password.length()!=0)
              {
                 if(show_asterisk)
                     cout <<"\b \b";
                 password.resize(password.length()-1);
              }
         }
       else
         {
             password+=ch;
             if(show_asterisk)
                 cout <<'*';
         }
    }
  cout <<endl;
  return password;
}

bool checkpass(){
    const char *correct_password="yushant";int o=3,flag=0;
/*
  cout <<"Test 1: echoing enabled"<<endl;
  string password=getpass("Please enter the password: ",true); // Show asterisks
  if(password==correct_password)
      cout <<"Correct password"<<endl;
  else
      cout <<"Incorrect password. Try again"<<endl;
*/
    while(o--){
  //cout <<"\nTest 2: echoing disabled"<<endl;
  string password=getpass("Please enter the password: ",false); // Do not show asterisks
  if(password==correct_password)
      {cout <<"Correct password"<<endl;flag=1;break;}
  else
      {cout <<"Incorrect password."<<endl;if(o>1){cout<<"Try Again"<<endl;}}
    if(o==1){
        cout<<"This is your last attempt. Failing to enter the correct password will lock the system."<<endl;
    }
    }
    system("pause");
    if(flag==0){
    /*cout<<"You have exceeded the limit.We have locked the system.We are directing you back to the main menu...."<<endl;
    printmenu();*/
    return false;
    }
    else{
        /*cout<<"You have entered the administration section:-"<<endl;*/
        return true;
    }
}
bool checkpass2(){
    const char *correct_password="dfs";int o=3,flag=0;
/*
  cout <<"Test 1: echoing enabled"<<endl;
  string password=getpass("Please enter the password: ",true); // Show asterisks
  if(password==correct_password)
      cout <<"Correct password"<<endl;
  else
      cout <<"Incorrect password. Try again"<<endl;
*/
    while(o--){
  //cout <<"\nTest 2: echoing disabled"<<endl;
  string password=getpass("Please enter the password: ",false); // Do not show asterisks
  if(password==correct_password)
      {flag=1;break;}
  else
      {cout <<"Incorrect password."<<endl;if(o>1){cout<<"Try Again"<<endl;}}
    if(o==1){
        cout<<"This is your last attempt. Failing to enter the correct password will lock the system."<<endl;
    }
    }
    system("pause");
    if(flag==0){
    /*cout<<"You have exceeded the limit.We have locked the system.We are directing you back to the main menu...."<<endl;
    printmenu();*/
    return false;
    }
    else{
        /*cout<<"You have entered the administration section:-"<<endl;*/
        return true;
    }
}
