#include "people.h"
using namespace std;
class Day: public NODE<Day>{
  int day,size;

  people* ppl_head;
public:
  Day(int x):NODE(){day = x;size = 0;ppl_head = NULL;}
  ~Day(){}
  int get_day(){return day;}
  int get_size(){return size;}
  ////////////////////////////////////////////////
  void add(people* p){
    people* t = ppl_head;
    if(ppl_head == NULL){
      size = size+1;
      ppl_head = p;
      return;
    }
    while(t->move_next() != NULL){
      t = t->move_next();
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
    cout<<"   ID            "<<"Name                          "<<"Vaccine           "<<"Age  "<<endl;
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
          cout<<"ID            "<<"Name                          "<<"Vaccine           "<<"Age  "<<endl;
        }
        else if(t->get_hos() == 22952){
          cout<<"Hospital: Golden Jubilee Medical Center"<<endl;
          cout<<"ID            "<<"Name                          "<<"Vaccine           "<<"Age  "<<endl; 
        }
        else if(t->get_hos() == 10734){
          cout<<"Hospital: Golden Samut Sakhon Hospital"<<endl;
          cout<<"ID            "<<"Name                          "<<"Vaccine           "<<"Age  "<<endl;
        }
        t->display();
        return 1;
      }
      t = t->move_next();
    }
    return 0;
  }
  //////////////////////////////
  void rmv_all(Vac_Infected *V){
    people* t;
    string hn,tid;
    int random;
    while(ppl_head){
      t = ppl_head;
      ppl_head = t->move_next();
      cout<<t->get_name()<<" got vaccinated!"<<endl;
      //
      srand(time(NULL));
      if((t->get_vac().compare("Sinovac"))==0)
      {
      random=(rand()%1000)+1 ;
      ///////////////////////////
      if(random>550)//550
      {
        tid="Infected Covid-19";
      }
      else
      {
        tid="Not Infected Covid-19";
      }
      }
      if((t->get_vac().compare("Astrazeneca"))==0)
      {
      random=(rand()%1000)+1 ;
      ///
      if(random>900)//900
      {
        tid="Infected Covid-19";
      }
      else
      {
        tid="Not Infected Covid-19";
      }
      }
      if((t->get_vac().compare("Pfizer"))==0)
      {
      random=(rand()%1000)+1 ;
      if(random>950)//950
      {
        tid="Infected Covid-19";
      }
      else
      {
        tid="Not Infected Covid-19";
      }
      }
      if((t->get_vac().compare("Johnson & Johnson"))==0)
      {
      random=(rand()%1000)+1 ;
      if(random>669)//669
      {
        tid="Infected Covid-19";
      }
      else
      {
        tid="Not Infected Covid-19";
      }
      }
      if((t->get_vac().compare("Sputnik V"))==0)
      {
      random=(rand()%1000)+1 ;
      if(random>914)//914
      {
        tid="Infected Covid-19";
      }
      else
      {
        tid="Not Infected Covid-19";
      }
      }
      if((t->get_vac().compare("Moderna"))==0)
      {
      random=(rand()%1000)+1 ;
      if(random>945)//945
      {
        tid="Infected Covid-19";
      }
      else
      {
        tid="Not Infected Covid-19";
      }
      }
      if(tid=="Infected Covid-19"){
        for(int i = 0; i < 6; i++){
          if((t->get_vac().compare(V[i].get_name()))==0){V[i].infected();}
        }
      }
     if(t->get_hos()==24748)
      {
          hn="Siriraj Hospital";
      }
      else if(t->get_hos()==22952)
      {
        hn="Golden Jubilee Medical Center";
      }
      else if(t->get_hos()==10734)
      {
        hn="Samut Sakhon Hospital";
      }
      cout<<"Name : "<<t->get_name()<<endl<<"Age : "<<t->get_age()<<endl;
      cout<<"ID : "<<t->get_id()<<endl;
      cout<<"Underlying disease : "<<t->get_un()<<endl;
      cout<<"Hospital Name : "<<hn<<endl;
      cout<<"Have been vaccinated : "<<t->get_vac()<<endl;
      cout<<"Infectation : "<<tid<<endl<<endl;
    }
      delete t;
  }

////////////////////////////////////////////////////////////
};

