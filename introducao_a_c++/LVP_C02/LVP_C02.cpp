#include <iostream>
#include <vector>


using namespace std;
int main (){
    int sizevector, j = 0;
    vector<float> notas;
    float  soma, nota = 0;

    cout << "Informe as notas dos alunos (valor negativo para parar): "<<endl; //Montando o vector das notas
    do{
        cin >> nota;
        if (nota>0){
            notas.push_back(nota);
        }
    }
    while(nota>0);

    sizevector=notas.size(); //Obtendo a quantidade de componentes do vector

    for(int i=0; i<sizevector; i++){ //Somando as notas
        //cout<<notas[i];
        soma=soma+notas[i];
    }

    float media = soma / sizevector; 

    //cout << endl << "Tamanho do vetor: " << sizevector;
    //cout << endl << "Soma dos itens: "<< soma;
    cout << endl << "Média = " << soma / sizevector << endl;

    cout << "Notas abaixo da média:" << endl;
    for (j; j<sizevector; j++){
        if(notas[j]<media){
            cout<<notas[j]<<endl;
        }
    }

    return 0;
}
