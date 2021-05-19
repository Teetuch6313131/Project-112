using namespace std;

template <class T>
class NODE{
  protected:
    T* next;
  public:
    NODE(){
      next = NULL;
    }
    void add_next(T* n){
      next = n;
    }
    T* move_next(){return next;};
};