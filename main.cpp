#include <iostream>
#include <string>
using namespace std;

#include"hospital.h"
#include"NODE.h"


int main() {
  int o,age,y;
  hospital H[3] = {{1,"A"},{2,"B"},{3,"C"}};
  string name,un_disease,hospital_name,vaccine_name;
  long hospital_id;
  cout <<"What are you gonna do"<<endl;
  cout <<"Type 1 for Book a queue"<<endl;
  cout <<"Type 2 for Book a queue"<<endl;
  cout <<"Type 2 for Book a queue"<<endl;
  cin >> o;
  
  switch (o){
        case 1:
            cout<<"What is your name : ";
            cin>> name;
            cout<<"How old are you : ";
            cin>> age;
            cout<<"Do you have any underlying disease : ";
            cin>>un_disease;
            do{
              y=0;
              cout<<"Which vaccine you want to get (A/B/C): ";
              cin>>vaccine_name;
              //string x = "A";
              if((vaccine_name.compare("A"))==0 && age>=60)
              {
               y=1;
              }
            }while(y==0);
            cout<<"Which hospital you want to go (A/B/C): ";
            cin>>hospital_id>>hospital_name;
            break;
              
        case 2:   break;
        case 3:   break;
        default:;
  
  }
/////////////////////////////////////////////////////////////////////////
 /* people *p = new people(1,"YXX","X",age);
  people *p2 = new people(2,"YYY","Z",age);
  people *p3 = new people(3,"YYYZZ","T",age);
  H[0].addPPL(1, p);
  H[0].addPPL(2, p2);
  H[0].addPPL(2, p3);
  //people(long id,string n, string vac,int a, string un = "NA")
  H[0].display();
  H[0].rmvPPL(1);
  H[0].display();*/

}

 /*
 cout<<"A : Sinovac"<<endl;
 cout<<"B : Astrazeneca"<<endl;
 cout<<"C : Pfizer"<<endl;
*/

/*A : cout<<"Hospital name : Siriraj Hospital"<<endl;
  cout<<Hospital ID: 24748<<endl;
  cout<<"Address : 2 Wang Lang Road,"<<endl;
  cout<<"Siriraj Subdistrict,"<<endl;
  cout<<"Bangkok Noi District,"<<endl;
  cout<<"Bangkok Province"<<endl;
  cout<<"10700"<<endl*/

/*B : cout<<"Hospital name : Golden Jubilee Medical Center"<<endl;
  cout<<Hospital ID: 22952<<endl;
  cout<<"Address : 999 Boromarajajonani Road,"<<endl;
  cout<<"Salaya Subdistrict,"<<endl;
  cout<<"Phutthamonthon District,"<<endl;
  cout<<"Nakhon Pathom Province"<<endl;
  cout<<"73170"<<endl*/

/*C : cout<<"Hospital name : Samut Sakhon Hospital"<<endl;
  cout<<Hospital ID: 10734<<endl;
  cout<<"Address : 1500 Ekachai Road,"<<endl;
  cout<<"Mahachai Subdistrict,"<<endl;
  cout<<"Mueang Samut Sakhon District,"<<endl;
  cout<<"Samut Sakhon Province"<<endl;
  cout<<"74000"<<endl*/

/*cout<<"Complete vaccine reservation"<<endl;
  cout<<"Name : "<<name<<endl<<"Age : "<<age<<endl;
  cout<<"Underlying disease : "<<un_disease<<endl;
  cout<<"Selected vaccines : "<<vaccine_name<<endl;
  cout<<"Appointment date : "<<endl;
  cout<<"***Please get enough rest and arrive at the hospital before the appointment time.***"<<endl;
*/
  




  
   