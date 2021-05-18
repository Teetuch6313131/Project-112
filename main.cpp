#include <iostream>
#include <string>
using namespace std;

#include"hospital.h"
#include"NODE.h"


int main() {
  int o,age,y,daycheck,day=1,hospital_name_check,check,i,TTTT=1;
  hospital H[3] = {{1,"A"},{2,"B"},{3,"C"}};
  string name,un_disease,vaccine_name,hospital_name;
  long hospital_id,pp_id,pp_id_check;
  do{ 
  cout<<"Day: "<<day<<endl;
  cout <<"What are you gonna do"<<endl;
  cout <<"Type 1 for Book a queue"<<endl;
  cout <<"Type 2 for Check the queue of the hospital"<<endl;
  cout <<"Type 3 for Check the vaccination location of the reservation"<<endl;
  cout <<"Type 0 for Exit the program"<<endl;
  cin >> o;
  
  /*people *p3 = new people(3,1,"YYYZZ","T",age);
  H[0].addPPL(1, p3);*/

  switch (o){
        case 1:
            cout<<"What is your name : ";
            cin>> name;
            cout<<"How old are you : ";
            cin>> age;
            cout<<"Your national ID number is : ";
            cin>>pp_id;
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
              
        case 2:
            cout <<"Which hospital you want to check? : ";
            cin>>hospital_name_check;
            cout <<"Which Days you want to check? : ";
            cin>>daycheck;
            H[hospital_name_check].display(daycheck);
            break;
        //Nedd to be check case 3
        case 3:
            cout<<"which ID you want to check? : ";
            cin>>pp_id_check;
            check = 0;
            for(i = 0; i < 3; i++){
              cout << i <<endl;
              check = H[i].check(pp_id_check);
              if(check == 1){break;}
            }
            if(i == 3) cout<<pp_id_check<<" has not registerd yet."<<endl;
            break;
        case 4:
            {
              //while()
              day++;
            }

        case 0: 
            cout<<"Goodbye, Thank you for coming to get vaccinated."<<endl;
            return 0 ;

        default:
        break;
  }
  }while(TTTT);
}
/////////////////////////////////////////////////////////////////////////
 /* people *p = new people(1,1,"YXX","X",age);
  people *p2 = new people(2,1,"YYY","Z",age);
  people *p3 = new people(3,1,"YYYZZ","T",age);
  H[0].addPPL(1, p);
  H[0].addPPL(2, p2);
  H[0].addPPL(2, p3);
  //people(long id,string n, string vac,int a, string un = "NA")
  H[0].display();
  //H[0].display();

}*/

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
  




  
   