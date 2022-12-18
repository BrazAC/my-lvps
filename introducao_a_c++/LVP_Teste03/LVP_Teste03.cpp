//Receber a quantidade de itens do array
//Criar o array
//Testar cada item do array descobrindo o menor e o maior valor
//Mostrar o menor e o maior valor
#include <iostream>
using namespace std;

int main()
{
    int sizeArray = 0;
    int value = 0;
    int smaller = 0;
    int bigger = 0;

    cout << "Insira o tamanho do Array entre 0 e 20: ";
    cin >> sizeArray;
    

    if (sizeArray<=20){ //Executa o programa somente se o tamanho do array for <20 e >0
        sizeArray = sizeArray - 1;
        int myArray [sizeArray] = {};   

        for (int i=0 ; i<=sizeArray ; i++)  //Montando o array 
        { 
            cout << "Insert the value for position " << i << ":";
            cin >> value;

            myArray [i] = value;
        }

        bigger = myArray[0];    //Atribui um valor qualquer do array na variável do maior valor
        smaller = myArray[0];   //Atribui um valor qualquer do array na variável do menor valor

        for (int j=0; j<=sizeArray; j++){
            if (myArray[j] > bigger){   //Descobre o maior valor
                bigger = myArray[j];
            }

            if (myArray[j] < smaller){    //Descobre o menor valor
                smaller=myArray[j];
            }
        }
    
        cout << smaller << " " << bigger;
    }
    else {
        cout << "Limite de indices atingido";
    }

    
    
    

    return 0;
}