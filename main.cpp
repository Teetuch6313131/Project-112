#include <iostream>
#include <string>
#include <cstring>
//#include<cctype>
//#include<cstdio>
using namespace std;
#include"hospital.h"


int main() {
  int limit_per_day = 3,checkH;
  int o,age,y,daycheck,day=1,check,i,TTTT=1,day_come,hospital_array;
  hospital H[3] = {{24748,"Siriraj Hospital"},{22952,"Golden Jubilee Medical Center"},{10734,"Samut Sakhon Hospital"}};
  string name,un_disease,vaccine_name,hospital_name,vaccine_name_real,hospital_name_real,hospital_name_check;
  people* current_p;
  long hospital_id,pp_id,pp_id_check;
  Linked_people *lp;

  do{ 
  cout<<endl<<"Day : "<<day<<endl;
  cout<<"================================================================"<<endl;
  cout <<"What are you gonna do"<<endl;
  cout <<"Type 1 for Book a queue"<<endl;
  cout <<"Type 2 for Check the queue of the hospital"<<endl;
  cout <<"Type 3 for Check the vaccination location of the reservation"<<endl;
  cout <<"Type 4 for Pass a day"<<endl;
  cout <<"Type 0 for Exit the program"<<endl;
  cout<<"================================================================"<<endl;
  cin >> o;
  cout<<endl;
  /*people *p3 = new people(3,1,"YYYZZ","T",age);
  H[0].addPPL(1, p3);*/

  switch (o){
        case 1:
            cout<<"What is your name : ";
            cin>>name;
            do{
              y=1;
              try{
              
            cout<<"How old are you : ";
            cin>>age;
            if(0<=age&&18>age)
            {
              throw 1;
              
              
            }
            
              }
              catch(int a)
              {
                if(a==1)
                {
                  cout<<"***People who have age 0 to 18 can't get vaccine***"<<endl;
                }
                y=0;
              }
            }while(y==0);
            
            cout<<"Your student ID number is : ";
            cin>>pp_id;
            
            cout<<"Do you have any underlying disease : ";
            cin>>un_disease;
            do{
              try{
              y=1;
              cout<<"A : Sinovac"<<endl;
              cout<<"B : Astrazeneca"<<endl;
              cout<<"C : Pfizer"<<endl;
              cout<<"D : Johnson & Johnson"<<endl;
              cout<<"E : Sputnik V"<<endl;
              cout<<"F : Moderna"<<endl;
              cout<<"Which vaccine you want to get (A/B/C/D/E/F): ";
              cin>>vaccine_name;
              if((vaccine_name.compare("A"))==0 && age>=60)
              {
                throw 1;
              }
              else if((vaccine_name.compare("A"))==0)
              {
                vaccine_name_real="Sinovac";
              }
              else if((vaccine_name.compare("B"))==0)
              {
                vaccine_name_real="Astrazeneca";
              }
              else if((vaccine_name.compare("C"))==0)
              {
                vaccine_name_real="Pfizer";
              }
              else if((vaccine_name.compare("D"))==0)
              {
                vaccine_name_real="Johnson & Johnson";
              }
              else if((vaccine_name.compare("E"))==0)
              {
                vaccine_name_real="Sputnik V";
              }
              else if((vaccine_name.compare("F"))==0)
              {
                vaccine_name_real="Moderna";
              }
              else{
                throw 2;
              }
              }
              catch(int a)
              {
                if(a==1)
                {
                    cout<<endl<<"***Your age is too high!***"<<endl;
                
                }
                if(a==2)
                {
                   cout<<"You can type only A,B,C,D,F"<<endl;
                }
                y=0;
              }
            }while(y==0);
            cout<<endl<<"A : ";
            cout<<"Hospital name : Siriraj Hospital"<<endl;
            cout<<"    Hospital ID : 24748"<<endl;
            cout<<"    Address : 2 Wang Lang Road,"<<endl;
            cout<<"              Siriraj Subdistrict,"<<endl;
            cout<<"              Bangkok Noi District,"<<endl;
            cout<<"              Bangkok Province"<<endl;
            cout<<"              10700"<<endl;
            cout<<"B : ";
            cout<<"Hospital name : Golden Jubilee Medical Center"<<endl;
            cout<<"    Hospital ID : 22952"<<endl;
            cout<<"    Address : 999 Boromarajajonani Road,"<<endl;
            cout<<"              Salaya Subdistrict,"<<endl;
            cout<<"              Phutthamonthon District,"<<endl;
            cout<<"              Nakhon Pathom Province"<<endl;
            cout<<"              73170"<<endl;
            cout<<"C : ";
            cout<<"Hospital name : Samut Sakhon Hospital"<<endl;
            cout<<"    Hospital ID : 10734"<<endl;
            cout<<"    Address : 1500 Ekachai Road,"<<endl;
            cout<<"              Mahachai Subdistrict,"<<endl;
            cout<<"              Mueang Samut Sakhon District,"<<endl;
            cout<<"              Samut Sakhon Province"<<endl;
            cout<<"              74000"<<endl;
            cout<<"Which hospital you want to go (A/B/C): ";
            cin>>hospital_name;
            if((hospital_name.compare("A"))==0)
            {
              hospital_array=0;
              hospital_name_real="Siriraj Hospital";
              hospital_id=24748;
            }
            if((hospital_name.compare("B"))==0)
            {
              hospital_array=1;
              hospital_name_real="Golden Jubilee Medical Center";
              hospital_id=22952;
            }
            if((hospital_name.compare("C"))==0)
            {
              hospital_array=2;
              hospital_name_real="Samut Sakhon Hospital";
              hospital_id=10734;
            }
            do{
              y=1;
            cout<<endl<<"When do you come to get vaccine (type date only 1-31)(You cannot book today's queue.) : ";
            cin>>day_come;
            try{
            if(day_come<day)
            {
              throw 1;
            }
            else if(day_come==day)
            {
              throw 2;
            }
            else if(H[hospital_array].check_day(day_come) >= limit_per_day)
            {
              throw 3;
            }
            }
            catch(int error)
            {
              if(error == 1){
                cout <<"***You book can't a past day!***"<<endl;
              }
              else if(error == 2){
                cout<<"***You can't book today!***"<<endl;
              }
              else if(error == 3){
                cout<<"***Day "<<day_come<<" is full***"<<endl;
              }
              y=0;
            }
            }while(y==0);
            current_p = new people(pp_id,hospital_id,name,vaccine_name_real,age,un_disease);
            H[hospital_array].addPPL(day_come, current_p);
            //cout<<endl<<"================================================================"<<endl;
            cout<<endl<<"***Complete vaccine reservation***"<<endl;
            cout<<"Name : "<<name<<endl<<"Age : "<<age<<endl;
            cout<<"Underlying disease : "<<un_disease<<endl;
            cout<<"Selected vaccines : "<<vaccine_name_real<<endl;
            cout<<"Appointment date : Day "<<day_come<<endl;
            cout<<"***Please get enough rest and arrive at the hospital before the appointment time.***"<<endl;

        break;
              
        case 2:
        //add 0,1,2 to hnc
            cout<<"A : ";
            cout<<"Hospital name : Siriraj Hospital"<<endl;
            cout<<"B : ";
            cout<<"Hospital name : Golden Jubilee Medical Center"<<endl;
            cout<<"C : ";
            cout<<"Hospital name : Samut Sakhon Hospital"<<endl;
            cout<<"Which hospital you want to check (A/B/C) : ";
            cin>>hospital_name_check;
            cout <<"Which Days you want to check (1-31) : ";
            cin>>daycheck;
            cout<<endl;
            if((hospital_name_check.compare("A"))==0)
            {
              hospital_array=0;
            }
            else if((hospital_name_check.compare("B"))==0)
            {
              hospital_array=1;
            }
            else if((hospital_name_check.compare("C"))==0)
            {
              hospital_array=2;
            }
            if(H[hospital_array].check_day(daycheck)){
              H[hospital_array].display(daycheck);
            }
            else{
              cout<<"Day "<<daycheck<<" has 0 queue"<<endl;
            }
            
            //try catch day_check
            break;
        //Nedd to be check case 3
        case 3:
            cout<<"which ID you want to check : ";
            cin>>pp_id_check;
            check = 0;
            for(i = 0; i < 3; i++){
              check = H[i].check(pp_id_check);
              if(check == 1){break;}
            }
            if(i == 3) cout<<pp_id_check<<" has not registerd yet."<<endl;
            break;
        case 4:
            //while()
              for(int i = 0; i< 3 ;i++){
                H[i].rmvPPL_all(day);
              }
              day++;
              //delete day past
            break ;
        case 5:
              for(int i = 0; i < 3; i++){
                H[i].giveAllPPL(lp);
              }
              lp->selection_sort();
              cout<<"Sorted by Age"<<endl;
              lp->display();
        break;       

        case 0: 
            cout<<"Goodbye, Thank you for coming to get vaccinated."<<endl;
            return 0 ;

        default:
        break;
  }
  }while(TTTT);
}
/////////////////////////////////////////////////////////////////////////
  /*people *p = new people(1,1,"YXX","X",age);
  people *p2 = new people(2,1,"YYY","Z",age);
  people *p3 = new people(3,1,"YYYZZ","T",age);
  H[0].addPPL(1, p);
  H[0].addPPL(2, p2);
  H[0].addPPL(2, p3);
  //people(long id,string n, string vac,int a, string un = "NA")
  H[0].display();
  //H[0].display();

}*/


