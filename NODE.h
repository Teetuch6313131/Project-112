using namespace std;
class NODE{
  protected:
    NODE* next;
  public:
    NODE(){
      next = NULL;
    }
    void add_next(NODE* n){
      next = n;
    }
    NODE* move_next(){return next;};
    ~NODE();
};