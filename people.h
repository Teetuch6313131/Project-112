using namespace std;

class people{
    long people_id;
    string name, vaccine_type, un_disease;
    int age,hos_id;
    people* next;

  public:
    people(long id,int hd, string n, string vac, int a, string un = "NA"){
      people_id = id;
      name = n;
      vaccine_type = vac;
      un_disease = un;
      age = a;
      hos_id = hd;
    }
    people* move_next(){return next;}
    void add_next(people* n){next = n;}

    void display(){
      cout<<people_id<<"/"<<name<<"/"<<vaccine_type<<"/"<<age<<endl;
    }

    long get_id(){return people_id;}

    string get_name(){return name;}
};

