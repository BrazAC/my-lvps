//Obter o primeiro operando, o segundo operando e o operador 
//Identificar o operador inserido
//  Se for válido (+ - / *) efetue a operação desejada, se não, encerre o programa.
//      Mostre o resultado.
#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main ()
{
    setlocale(LC_ALL,"Portuguese");

    float op1=0;
    float op2=0;
    string operador;

    cout << "Informe o primeiro operando: ";
    cin >> op1;

    cout << "Informe o segundo operando: ";
    cin >> op2;

    cout << "Informe o operador (+, -, * ou /): ";
    cin >> operador;
    
    if (operador == "+"){
        cout << "Resultado da adição = " << op1 + op2;
    }
    else if (operador == "-"){
        cout << "Resultado da subtração = " << op1 - op2;
    }
    else if (operador == "*"){
        cout << "Resultado da multiplicação = " << op1 * op2;
    }
    else if (operador == "/"){
        if (op2 == 0){
            cout << "Divisão por zero inválida!";
        }
        else{
            cout << "Resultado da divisão = " << op1 / op2;
        }
    }
    else{
        cout << "Operador inválido!";
    }
    
    return 0;
}