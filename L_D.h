#include"Day.h"

using namespace std;
class L_D{
  Day *head_d;
public:
//////////////////////////////////////////////
  void add_Day(int x){
    Day *n = new Day(x);
    Day *t = head_d;
    Day *prev = head_d;
    if(head_d == NULL){
      head_d = n;
    }
    else{
      while(t->get_day() < x && t != NULL){
        prev = t;
        t = t->move_next();
      }
      prev->add_next(n);
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
    prev->add_next(t->move_next());
    delete t;
  }
  //////////////////////////////////////////
  void addPPL(int day, people *ppl){
    Day* t = head_d;
    while(t->get_day() != day && t != NULL){
      t = t->move_next();
    }
    if(t == NULL){
      this->add_Day(day);
      t = head_d;
      while(t->get_day() != day){
        t = t->move_next();
      }
    }
    // know t
    t->add(ppl);
  }
  ///////////////////////////////////////////////
  void display(){
    Day* t = head_d;
    while(t){
      t->display();
      t = t->move_next();
    }
  }

};