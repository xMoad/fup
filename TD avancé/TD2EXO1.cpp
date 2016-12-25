#include <iostream>
using namespace std;
// Forward declaration of List, needed by the forward declaration of operator<<
template <typename ELEM>
class List;
// Forward declaration of operator<<
template <typename ELEM>
ostream& operator<<(ostream&, const List<ELEM>&);
template <typename ELEM>
class List
{
private:
   // The list Cell type
    struct Cell
    {
        ELEM val;
        Cell *next;
        Cell(ELEM v, Cell *n = 0) : val(v), next(n) {}
        ~Cell() {delete next;} // Recursive destructor
    };
    //
    Cell *head;         // Pointer to first cell
    Cell *tail;         // Pointer to last cell
public:
    // Exception
    class Empty {};
    // Construction and destruction
    List() : head(0), tail(0) {}
    // Destroy first cell (recursive destruction)
    // It's not necessary to be virtual, but if it is not we get a
    // warning in Queu !
    virtual ~List() {delete head;}
    // Copy constructor and copy assignment
    List(const List&);
    List& operator=(const List&);
    // Accessor ?
    bool is_empty() const {return head == 0;}
    // Adding elements to the list
    void append(ELEM);  // at the end
    void prepend(ELEM); // at the beginning
    void insert(ELEM);  // at its place, according to ELEM::operator<
    // Removing elements from the list en tete de liste

    ELEM get_first();
    // Display (obey the g++ warning message and add <>!)
    friend ostream& operator<< <>(ostream&, const List&);
    bool operator<(ELEM);
};
template<typename ELEM > 
List<ELEM> ::List(const List& l):head(0),tail(0)
          {
           for (Cell* c= l.head;c!=0;c=c->next)
           append(c->val);
           }
template<typename ELEM>
List<ELEM>  &List<ELEM> ::operator=(const List &l){
            if (this != &l){
                     delete head;
                     tail=head=0;
                     for (Cell* c= l.head;c!=0;c=c->next)
                     append(c->val);
                    }
             }
template<typename ELEM>
void  List<ELEM>:: append(ELEM e){
     Cell* c=new Cell(e);
      if (is_empty())
         head=tail=c;
      else {
      tail->next=c;
      tail=c;     
           }
      }  
                 
template<typename ELEM> 
void List<ELEM> :: prepend(ELEM e){
      Cell* c=new Cell(e);
      if (is_empty())
      tail=head=c;
      else {
           c->next=head;
           head=c;
           }
     }           
template<typename ELEM> 
void List<ELEM> :: insert(ELEM e){
     Cell *c=new Cell(e);
     if (is_empty())
        head=tail=c;
     else
         if(e<head->val){
               prepend(e);  
                while(c->next!=0)
        {
           c=c->next;}}
         else 
         append(e);}
template<typename ELEM> 
ELEM List<ELEM>::get_first(void){
     if(is_empty()){
      cout<< "la list est vide "<<endl;
    return 0;}
     else{
     ELEM i=head->val;
         if (head ==tail)
          {  tail=0;head=0;}
             Cell* c=head->next;
             head->next=0;
             delete head;
             head=c;
             return i;     
             }
     }
     template <typename ELEM>
ostream& operator<<(ostream& o, const List<ELEM>& l)
{
    if (l.is_empty()) o<<"liste vide"<<endl;
    else
    {
        typename List<ELEM>::Cell *c=l.head;
        o<<c->val;
        while(c->next!=0)
        {
           c=c->next;
            o<<c->val;
        }
        o<<endl;
    }
    return o;
}
//template<typename ELEM>
//ostream & operator<<(ostream &out,const List<ELEM> &list)
//{
  //     if (list.is_empty())
    //   out<<"la liste est vide"<<endl;
      // else{
       //typename List<ELEM>::Cell *c=list.head;
       //for(*c=list.head;c!=0;c=c->next)
       //out<<c->val;
       //}
       //return out;}
   template<typename ELEM>
   bool List<ELEM>::operator<(ELEM e)
 {
   if (*this<e)return 1;
   else 
   return 0;    
}    
main()
{
//cout<<"aaaaaaaaaaa"<<endl;
 List<int> mlist;
 cout<<"je ss laaaa"<<endl;
   mlist.prepend(4);
    cout<<mlist;
    mlist.append(2);
    cout<<mlist;
    mlist.append(3);
    cout<<mlist;
    cout<<"ssssssssssss"<<endl;
    mlist.prepend(5);
    cout<<mlist;
    mlist.insert(8);
    cout<<mlist;
    mlist.insert(3);
    cout<<mlist;
    mlist.insert(6);
    cout<<mlist;
    mlist.insert(5);
    cout<<mlist;
    mlist.insert(7);
    cout<<mlist;
    List<int> l2(mlist);
    cout<<l2;
    List<int> l3;
    l3=l2;
    cout<<l3;
    int i=l3.get_first();
    cout<<"valeur retirée "<<i<<endl;
    cout<<l3;

system("pause");
return 0;
}
