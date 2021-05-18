//#include"L_D.h"
#include "Day.h"
using namespace std;

class hospital{
protected:
  long hos_id;
  string hos_name;
  Day *head_d;
  int day_use[31] = {0};
public:
  hospital(long x,string hn){
    hos_id = x;
    hos_name = hn;
    head_d = NULL;
  }
  //////////////////////////////////////////////////////
   void add_Day(int x){
    Day *n = new Day(x);
    Day *t = head_d;
    if(head_d == NULL){
      head_d = n;
    }
    else{
      while(t->get_day() < x){
        if(t->move_next() == NULL){
          t->add_next(n);
        }
        else if(t->move_next()->get_day() > x){
          cout<<x<<endl;
          n->add_next(t->move_next());
          t->add_next(n); 
          return;
        }
        else{
          t = t->move_next();
        }
      }
    }
  }
  //////////////////////////////////////
  void rmv_day(int x){
    Day* t = head_d;
    Day *prev = head_d;
    while(t->get_day() != x && t != NULL){
      prev = t;
      t = t->move_next();
    }
    if(t !== NULL){
      t->rmv_all();
      prev->add_next(t->move_next());
      delete t;
    }
  }
  //////////////////////////////////////////
  void addPPL(int day, people *ppl){
    Day* t = head_d;
    if(t == NULL){
      this->add_Day(day);
      cout<<"Add "<<day-1<<endl;
      day_use[day-1] = 1;
      t = head_d;
    }
    else{
      if(day_use[day-1] == 0){
        cout<<"Add "<<day-1<<endl;
        this->add_Day(day);
        cout<<"Add "<<day-1<<endl;
        day_use[day-1] = 1;
      }
      while(t->get_day() != day){
        t = t->move_next();
      }
    }
    // know t
    t->add(ppl);
  }
  ///////////////////////////////////////////////
  void rmvPPL(int day){
    Day* t = head_d;
      while(t->get_day() != day && t != NULL){
        t = t->move_next();
      }
      if(t == NULL){
        this->add_Day(day);
        t = head_d;
      }
      while(t->get_day() != day){
        t = t->move_next();
      }
    t->pop();
  }
  ///////////////////////////////////////////////
  void display(){
    Day* t = head_d;
    cout<<hos_id<<"  "<<hos_name<<endl;
    while(t){
      t->display();
      t = t->move_next();
    }
  }
  ////////////////////////////////////////////////
  void display(int d){
    Day* t = head_d;
    cout<<hos_id<<"  "<<hos_name<<endl;
    while(t->get_day() != d && t != NULL){
      t = t->move_next();
    }
    if(t == NULL){
      cout<<"Day "<<d<<" has 0 queue"<<endl;
    }
    else{
      t->display();
    }
  }
  ////////////////////////////////////////////////
  int check(long id){
    Day* t = head_d;
    int c = 0;
    while(t){
      c = t->check(id);
      if(c == 1){
        cout<<"You registered for vacinate in Day: "<<t->get_day()<<endl;
        return 1;
      }
      t = t->move_next();
    }
    return 0;
  }
};


//hospital -> L_D -> Day -> people