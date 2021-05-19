#include "people.h"
using namespace std;
class Day: public NODE<Day>{
  int day,size;
  //Day *next;
  people* ppl_head;
public:
  Day(int x):NODE(){day = x;size = 0;ppl_head = NULL;}
  ~Day(){}
  int get_day(){return day;}
  int get_size(){return size;}
  //Day* move_next(){return next;}
  //void add_next(Day* n){next = n;}
  ////////////////////////////////////////////////
  void add(people* p){
    people* t = ppl_head;
    if(ppl_head == NULL){
      size = size+1;
      ppl_head = p;
      return;
    }
    while(t->move_next() != NULL){
      t->move_next();
    }
    size = size+1;
    t->add_next(p);
  }
  //////////////////////////////////////////
  void pop(){
    people* t = ppl_head;
    ppl_head = t->move_next();
    cout<<t->get_name()<<" has been vacinated!"<<endl;
    delete t;
  }
  ///////////////////////////////////////////
  void display(){
    people* t= ppl_head;
    int q = 1;
    cout<<"Day "<<day<<" has "<<size<<" queue(s)"<<endl;
    while(t){
      cout<<q<<". ";
      t->display();
      t = t->move_next();
      q = q+1;
    }
  }
////////////////////////////////////////////////////////////////////////////
  int check(long id){
    people* t = ppl_head;
    while(t){
      if(t->get_id() == id){
        if(t->get_hos() == 24748){
          cout<<"Hospital: Siriraj Hospital"<<endl;
        }
        else if(t->get_hos() == 22952){
          cout<<"Hospital: Golden Jubilee Medical Center"<<endl; 
        }
        else if(t->get_hos() == 10734){
          cout<<"Hospital: Golden Samut Sakhon Hospital"<<endl;
        }
        t->display();
        return 1;
      }
      t = t->move_next();
    }
    return 0;
  }
  //////////////////////////////
  void rmv_all(){
    people* t;
    while(ppl_head){
      t = ppl_head;
      ppl_head = t->move_next();
      delete t;
    }
  }
};

