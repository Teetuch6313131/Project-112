#include<iomanip>
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
    ~people(){}
    //people* move_next(){return next;}
    //void add_next(people* n){next = n;}

    void display(){
      cout<<setw(-14)<<people_id<<setw(-40)<<name<<setw(-18)<<vaccine_type<<setw(-5)<<age<<endl;
    }

    int get_age(){return age;}

    long get_id(){return people_id;}

    string get_name(){return name;}

    long get_hos(){return hos_id;}

    string get_vac(){return vaccine_type;}

    string get_un(){return un_disease;}
};

class Linked_people: public NODE<people>{
    people* p_head;
    int size;
  public:
    Linked_people():NODE(){p_head = NULL;size = 0;}
    ~Linked_people(){}

    void push(people *p){
      people *t = new people(p->get_id(), p->get_hos(), p->get_name(), p->get_vac(), p->get_age(), p->get_un());
      people *h = p_head;
      if(h == NULL){
        h = t;
      }
      else{
        while(h->move_next()){
          h = h->move_next();
        }
        h->add_next(t);
      }
      cout<<"push"<<endl;
      size = size+1;
    }
/////////////////////////////////////////////////////////
  void swap(int x,int y){
    people *t1,*t2,*t3,*t4,*t5;
    people *xp = p_head;
    people *yp = p_head;
    for(int i = 1; i < y; i++){
      yp = yp->move_next();
    }
    if(x != 0){
      for(int i = 1; i < x; i++){
        xp = xp->move_next();
      }
    }
    t1 = xp;
    t2 = yp;

    if(x == 0){
      t3 = t2->move_next();
      t3 = t3->move_next();
      t4 = p_head->move_next();
      p_head = yp->move_next();
      yp->add_next(t1->move_next());
      t1->add_next(t3);
      p_head->add_next(t4);
    }
    else{
      t3 = t2->move_next();
      t3 = t3->move_next();
      t4 = t1->move_next();
      t5 = t4->move_next();
      xp->add_next(yp->move_next());
      yp->move_next()->add_next(t5);
      t2->add_next(t4);
      t4->add_next(t3);
    }
  }
/////////////////////////////////////////////////////////
    void selection_sort(){
      people *h = p_head;
      int i,j,min_age,index2;
      for(i = 0; i < size; i++){
        for(j = 0; j < i; j++){
          h = h->move_next();
        }
        min_age = h->get_age();
        index2 = i;
        for(j = i; i < size; j++){
          if(h->get_age() < min_age){
            index2 =j;
            min_age = h->get_age();
          }
        }
        if(i != index2){this->swap(i,index2);}
      }    
    }
  ///////////////////////////////////////////////////////
  void display(){
    people *h = p_head;
    while(h){
      h->display();
      cout<<"Display"<<endl;
      h = h->move_next();
    }
  }
};