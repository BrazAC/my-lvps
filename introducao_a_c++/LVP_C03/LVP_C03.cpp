//Pega o resto da divisão por 10 e divide por 10
#include <iostream>
using namespace std;

void inverte_digitos(int uVal); //Pro... antes de main
//================================================//
int main (){
    int uVal=0;

    cout << "Informe um inteiro positivo para ser invertido: ";
    cin >>uVal;

    inverte_digitos(uVal);

    return 0;
}
//================================================//
void inverte_digitos (int uVal){ //Criando a função
    int uni;
    if (uVal>=0){
        do{
            uni=uVal%10;
            cout<<uni;
            uVal=uVal/10;
            
        }while(uVal!=0);
    }
}