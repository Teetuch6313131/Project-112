using namespace std;
class people{
  long people_id;
  string name, vaccine_type, un_disease;
  int age,queue;
  people* next;

public:
  people(long id,string n, string vac,int a, string un = "NA"){
    people_id = id;
    name = n;
    vaccine_type = vac;
    un_disease = un;
    age = a;
  }
  people* move_next(){return next;}
  void set_queue(int x){queue = x;}
  int get_queue(){return queue;}
  void add_next(people* n){next = n;}

  void display(){
    cout<<people_id<<"/"<<name<<"/"<<vaccine_type<<"/"<<age<<"/"<<queue<<endl;
  }

};