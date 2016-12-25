#include <iostream>
#include <stdlib.h> // Pour la fonction random : rand();
#include <cassert>
using namespace std;

template<typename TYPE,unsigned int size>
class Array;

template<typename TYPE,unsigned int size>
ostream & operator<<(ostream &, const Array<TYPE,size> &);


template<typename TYPE,unsigned int size>
class Array{
      
      private :
              TYPE *tab;
              unsigned int taille;
     public :
              
             Array():taille(size)
             {
              tab =new TYPE[size];
             }                           
      ~Array(){delete[] tab;}
    friend ostream & operator<< <>(ostream &, const Array<TYPE,size> &) ;
    TYPE & operator[](unsigned int) const;  
      
}   ;

template<typename TYPE,unsigned int size>
ostream & operator<<(ostream & out, const Array<TYPE,size> & vect)
{
        out<<"[";
        for (int i(0);i<vect.taille;i++) out<<vect.tab[i]<<" ";
        out<<"]"; 
        return out;
}
template<typename TYPE,unsigned int size>
TYPE &Array<TYPE,size>:: operator[](unsigned int n) const{ return  tab[n];}


template<typename TYPE,unsigned int ligne,unsigned int col>
 class Array2D;

 
template<typename TYPE,unsigned int ligne,unsigned int col>
ostream & operator<<(ostream &,const Array2D<TYPE,ligne,col> &);


template<typename TYPE,unsigned int ligne,unsigned int col>
class Array2D{
      private:
               Array<TYPE,col> *mat;
              unsigned int c;
              unsigned int l;
             
      public:
             Array2D():l(ligne),c(col) {
                                     mat= new Array<TYPE,col>[ligne];                                     
                                      
                                       }        
             ~Array2D(){delete[] mat;} 
           // friend ostream& operator<< <>(ostream & ,const Array2D<TYPE,ligne,col>&);
             friend ostream& operator<< <>(ostream&, const Array2D<TYPE,ligne,col>&);
              TYPE & operator[](unsigned int) const;  
              
                   
      };
       template<typename TYPE,unsigned int ligne,unsigned int col> 
      TYPE &Array2D<TYPE,ligne,col>:: operator[](unsigned int n) const{ return  mat[n];}
      
 template<typename TYPE,unsigned int ligne,unsigned int col> 
 ostream & operator<<(ostream & out,const Array2D<TYPE,ligne,col>  &matrice){
        
       
          for(int i(0);i<matrice.l;i++)
         out<<matrice.mat[i]<<endl;
        
         return out;
                       }
      


main(void){
           const unsigned int tail=7;
           Array< int ,tail> vect;
           cout<<vect<<endl;
           
          for (int i(0);i<tail;i++)
           //  vect[i]= (rand()%100);
           vect[i]=-10;
         cout<<vect<<endl; 
          const unsigned int l=3; // Nombre de ligne de la matrice
          const unsigned int c=5; // Nombre de colonne de la matrice
    Array2D<int,l,c>  mat; // Créationd d'une matrice de type TYPE=int
   cout<<mat;
   cout<<mat[2];
 
            
           
        //   cout<<"hello"<<endl;
           system("pause");
           return 0;
           
                                 }
      
      
             
