#include "people.h"
using namespace std;
class Day{
  int day,size;
  Day *next;
  people* ppl_head;
public:
  Day(int x){day = x;size = 0;}
  ~Day();
  int get_day(){return day;}
  Day* move_next(){return next;}
  void add_next(Day* n){next = n;}
  ////////////////////////////////////////////////
  void add(people* p){
    people* t = ppl_head;
    if(ppl_head == NULL){
      size = size+1;
      p->set_queue(size);
      ppl_head = p;
      return;
    }
    while(t->move_next() != NULL){
      t->move_next();
    }
    size = size+1;
    p->set_queue(size);
    t->add_next(p);
  }
  //////////////////////////////////////////
  people* pop(){
    people* t = ppl_head;
    people* re = t;
    ppl_head = t->move_next();
    return re;
  }
  ///////////////////////////////////////////
  void display(){
    people* t= ppl_head;
    while(t){
      t->display();
      t = t->move_next();
    }
  }
/////////////////////////////////////////////////////////////////////////////////
 
};

