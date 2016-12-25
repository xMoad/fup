#include <iostream>

#include <stdlib.h> // Pour la fonction random : rand();

#include <cassert>

using namespace std;


//////////////////////////////////////////////////
/////////// ARRAY 1D /////////////////////////////
//////////////////////////////////////////////////

// Forward declaration of class model Array

template <typename TYPE,unsigned int SIZE>

class Array; // ON doit faire cette forward declaration car Array est utilisée par la surcharge de l'opérateur de flux de sortie <<


// Forward declaration of operator<<
template <typename TYPE,unsigned int SIZE>

ostream& operator<<(ostream&, const Array<TYPE,SIZE>&); // On doit faire la forward déclaration car cette fontion sera utilisé dans la déclaration de la classe



// Declaration of class Array
// Le template continent le type du tableau de donnée (ex : int, double, float, ex...) et la taille du tableau SIZE

template <typename TYPE,unsigned int SIZE>

class Array

{

    private:

        TYPE *tab; // Pointeur sur le futur tableau de donnée de type : TYPE

        unsigned int taille; // Taille du tableau de donnée



    public:
        //constructeur par defaut


        Array() : taille(SIZE) // Taille prends la valeur contenue dans size.

        {

            tab=new TYPE[taille]; // allocation d'un tableau contenant SIZE éléments de type TYPE

        }



        // Destructeur

        ~Array(){delete tab;}




        TYPE& operator[](unsigned int) const; // prototype de la surchage de l'opérateur []

        friend ostream& operator<< <>(ostream&, const Array<TYPE,SIZE>&);// prototype de la surchage de l'opérateur de flux <<, déclaré ami de la classe Array.



};



// Déclaration de la surcharge de [] qui est une méthode du model de classe ARRAY

template <typename TYPE,unsigned int SIZE> // on remet le même template

TYPE& Array<TYPE,SIZE>::operator[](unsigned int n) const

{

    return tab[n];

}


// Déclaration de la surcharge de flux qui est une méthode friend du model de classe ARRAY

template <typename TYPE,unsigned int SIZE>

ostream& operator<<(ostream& o, const Array<TYPE,SIZE>& A)

{

    o<<"[";

    for (int i=0; i<A.taille; i++) o<<A.tab[i]<<" ";

    o<<"]"<<endl;



    return o;

}



//////////////////////////////////////////////////
/////////// ARRAY 2D /////////////////////////////
//////////////////////////////////////////////////

// Forward declaration of class model Array2D

template <typename TYPE,unsigned int LIGNE,unsigned int COL>

class Array2D; // ON doit faire cette forward declaration car Array est utilisée par la surcharge de l'opérateur de flux de sortie <<


// Forward declaration of operator<<

template <typename TYPE,unsigned int LIGNE,unsigned int COL>

ostream& operator<<(ostream&, const Array2D<TYPE,LIGNE,COL>&); // On doit faire la forward déclaration car cette fontion sera utilisé dans la déclaration de la classe



// Declaration of class Array2D
// Le template continent le type du tableau de donnée (ex : int, double, float, ex...) et le nombre de ligne LIGNE et le nombre de colonne COL
// La classe Array2D est un tableau de Array à 1D

template <typename TYPE,unsigned int LIGNE,unsigned int COL>

class Array2D

{

    private:

        Array<TYPE,COL> *mat; // Pointeur sur le futur tableau de Array contenant des données de type TYPE et une taille de COL

        unsigned int l,c; // Nombre de ligne et de colonne tu Tableau



    public:
        // COnstructeur de Matrice

        Array2D() : l(LIGNE), c(COL)

        {

            mat=new Array<TYPE,COL>[LIGNE]; // Allcation des Lignes qui sont des Array 1D de type TYPE et de taille COL

            //for (int i=0;i<taille;i++) tab[i]=(TYPE) rand();

        }



        // Destructeur

        ~Array2D(){delete[] mat;}


        // prototype de la surchage de l'opérateur de flux <<, déclaré ami de la classe Array2D.

        friend ostream& operator<< <>(ostream&, const Array2D<TYPE,LIGNE,COL>&);



};


// Déclaration de la surcharge de flux qui est une méthode friend du model de classe ARRAY

template <typename TYPE,unsigned int LIGNE,unsigned int COL>

ostream& operator<<(ostream& o, const Array2D<TYPE,LIGNE,COL>& A) // NOTE : à chaque fois que j'appel Array2D , j'écris aussi le template <TYPE,LIGNE,COL> !!!

{

    for (int i=0; i<A.l; i++) o<<A.mat[i]; // Appel de la surcharge de l'opérateur de flux << pour la classe Array



    return o;

}





int main(void)

{

//////////////////////////////////////////////////
/////////// ARRAY 1D /////////////////////////////
//////////////////////////////////////////////////

    const unsigned int taille=15; // Taille du tableau


    Array<int, taille> vect; // Déclaration d'une Array 1D de type TYPE=int et de taille SIZE=taille=15

    cout<<vect; // Affichage de l'Array 1D


    for (int i=0; i<taille; i++) vect[i]=rand()%100; // Affectation aléatoire de valeur dans le vecteur

    cout<<vect; // Affichage du verteur




//////////////////////////////////////////////////
/////////// ARRAY 2D /////////////////////////////
//////////////////////////////////////////////////

    const unsigned int l=3; // Nombre de ligne de la matrice

    const unsigned int c=5; // Nombre de colonne de la matrice

    Array2D<int,l,c> mat; // Créationd d'une matrice de type TYPE=int


    cout<<mat; // Afficahge de la matrice


system("pause");
    return 0;

}

