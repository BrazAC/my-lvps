//Que conversão o usuário deseja (de para)
//Receber a velocidade
//Imprimir a velocidade convertiva com duas casas
#include <iostream>
#include <string>
#include <iomanip>	
using namespace std;

union speed{
    float kmH, mpS, mpH = 0; 
};

int main (){
    int op = 0;
    speed velocidades;

    cout << "Selecione: " << endl << "(1)    Quilometros/hora (km/h) para metros/segundo (m/s)" << endl << "(2)    Metros/segundo (m/s) para Quilometros/hora (km/h)" << endl << "(3)    Metros/hora (m/h) para Quilometros/hora (km/h)" << endl;
    cin >> op;

    cout << "Insira a velocidade para conversao: ";
    cout << fixed << setprecision (2);
    if (op == 1)
    {
        cin >> velocidades.kmH;
        cout << "O valor da velocidade em (m/s) e: " << velocidades.kmH/3.6;
    }
    else if (op == 2)
    {
        cin >> velocidades.mpS;
        cout << "O valor da velocidade em (km/h) e: " << velocidades.mpS*3.6;
    }
    else
    {
        cin >> velocidades.mpH;
        cout << "O valor da velocidade em (km/h) e: " << velocidades.mpH/1000;
    }    


    return 0;
}