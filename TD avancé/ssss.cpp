
 
#include <iostream>
#include <sstream>
using namespace std; 
 
int main()
{
  stringstream strStream("Bienvenu sur www.mesexemples.com."); 
 
  // Obtenir un string
  string str = strStream.str();
  //Afficher le string
  cout << str << endl; 
 
  // Ecrire dans le 'stringstream'
  strStream << "Valeurs: " << 10 << " " << 3.14; 
 
  int i;
  double d;
  strStream >> str >> i >> d ;
  cout << str << " " << i << " " << d<<endl; 
 system("pause");
  return 0;
}
