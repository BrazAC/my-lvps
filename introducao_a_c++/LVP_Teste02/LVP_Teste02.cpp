//Obter a quantidade de lados
//Trabalhar os dados
//Mostrar o resultado
#include <iostream>
using namespace std;

int main()
{
    int lados = 0;
    int result = 0;

    cout << "Insira a quantidade de lados: ";
    cin >> lados;

    result = lados*(lados-3)/2;

    cout << "A quantidade de diagonais e: " << result;
    return 0;
}