using namespace std;
#include "NODE.h"
class people: public NODE<people>{
    long people_id,hos_id;
    string name, vaccine_type, un_disease;
    int age;
    //people* next;

  public:
    people(long id,long hd, string n, string vac, int a, string un = "NA"):NODE(){
      people_id = id;
      name = n;
      vaccine_type = vac;
      un_disease = un;
      age = a;
      hos_id = hd;
    }
    ~people(){cout<<name<<" got vaccinated!"<<endl;}
    //people* move_next(){return next;}
    //void add_next(people* n){next = n;}

    void display(){
      cout<<people_id<<"/"<<name<<"/"<<vaccine_type<<"/"<<age<<endl;
    }

    long get_id(){return people_id;}

    string get_name(){return name;}

    long get_hos(){return hos_id;}
};

