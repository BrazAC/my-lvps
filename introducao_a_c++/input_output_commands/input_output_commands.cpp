#include <iostream>
using namespace std;

int main()
{
    //-----------------------Tipos de dados---------------------//
    int a, b = 0;   //SEMPRE iniciar as variáveis com algum valor
    float k = 0;                                        
    short c = 0;                                           
    bool d;      
    char e = 'E';                                             
                                            
    //------------------Operadores Aritiméticos-----------------//
    //São eles: * / - + %
  
    //----------------------Entrada e saída---------------------//
    cout << "Insert the 1 value: " << "\n";
    cin >> a; //Atribui a informação digitada a variável "a"

    cout << "Inser the 2 value: " << endl;
    cin >> b; //Atribui a informação digitada a variável "b"

    cout << "O resultado é: " << a % b;
    //---------------------------------------------------------//

    return 0;
}

