#include <iostream>
#include <string>
using namespace std;

struct aluno{
    string nomeAluno;
    float p1, p2, p3, media = 0;
};

int main (){
    string antes;
    aluno alunos [2];   // Tamanho do vetor dos structs
    float bigMedia = 0;
    int TheChosenOne, j = 0;
    

    for (int i=0; i<=1; i++){   //Armazenando os dados nos structs no vetor
        cout << "Qual o nome do aluno? ----------------------- " << i << endl;
        cin.ignore();
        getline(cin,alunos[i].nomeAluno);
        //cin >> antes;
        //alunos[i].nomeAluno = antes;

        cout << "Qual a nota da primeira prova? " << endl;
        cin >> alunos[i].p1;
        //float a = alunos[i].p1;

        cout << "Qual a nota da segunda prova? " << endl;
        cin >> alunos[i].p2;
        //float b = alunos[i].p2;

        cout << "Qual a nota da terceira prova? " << endl;
        cin >> alunos[i].p3;
        //float c = alunos[i].p3;

        alunos[i].media = (alunos[i].p1 + alunos[i].p2 + alunos[i].p3)/3;
        //alunos[i].media = (a+b+c)/3;
    }

    //cout << "olha ai o:" <<  alunos[0].media;

    for (j; j<=1; j++){ //Descobrindo a maior média e o dono
        if (alunos[j].media >= bigMedia){
            bigMedia = alunos[j].media;
            TheChosenOne = j;
        }
    }   

    //cout << "a maior media: " << bigMedia << endl;
    cout << "O aluno com a maior nota e: " << alunos[TheChosenOne].nomeAluno << " que obteve a media: " << bigMedia;

    return 0;
}