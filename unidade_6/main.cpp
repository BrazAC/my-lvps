/*
> Discente: Braz Amorim Campos
> Matrícula: 121210160
> Período: 2021.2
> Curso: Engenharia elétrica
> Disciplina: Técnicas de programação
> Turma: 01
> Professor: Marcus Salerno
> Unidade 2: LVP-08
> Compilador utilizado: Visual Studio Code

> Descrição: Neste LVP você irá implementar um sistema muito importante para o Hospital de CG: 
  o sistema de controle da sala de espera dos pacientes. 
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
#include "paciente.cpp"
#include "hospital.cpp"

int main(){
    setlocale(LC_ALL, "Portuguese");

    int opcaoMenu = 0;
    hospital objetoHospital;
    vector <paciente> lista;

    do
    {
        cout <<"------------------------"<< endl;
        cout <<"     HOSPITAL SE CG      "<< endl;
        cout <<"    -Sala de espera-     "<< endl;
        cout <<"------------------------"<< endl;
        cout <<"1) Adicionar um novo paciente"<<endl;
        cout <<"2) Atender um paciente"<<endl;
        cout <<"3) Remover um paciente da fila"<<endl;
        cout <<"4) Exibir fila"<<endl;
        cout <<"5) Exibir dados de um paciente"<<endl;
        cout <<"6) Exibir lista dos paciente atendidos"<<endl;
        cout <<"0) Encerrar o programa"<<endl;
        cin>>opcaoMenu;
        
        system("cls");

        if (opcaoMenu==1) //Adicionar um novo paciente
        {
            string nomePaciente, motivoEntrada;
            int numeroRegistro;
            paciente novoPaciente;

            //======================Criando um novo paciente
            cout<<"Insira o nome do novo paciente: ";
            cin>> nomePaciente;
            novoPaciente.setNomePaciente(nomePaciente);

            cout<<"Insira o motivo da entrada: ";
            getline(cin>>ws,motivoEntrada);
            novoPaciente.setMotivoEntrada(motivoEntrada);

            cout<<"Insira o número de registro do paciente: ";
            cin>>numeroRegistro;
            novoPaciente.setRegistroPaciente(numeroRegistro);

            //===Registrando o novo paciente na fila de espera
            objetoHospital.cadastraPacienteEmFila(novoPaciente);

            system("pause");
            system("cls");

        }
        else if (opcaoMenu==2) //Atender um paciente
        {
            objetoHospital.atendepaciente();
            
            system("pause");
            system("cls");
        }
        else if (opcaoMenu==3) //Remover paciente da fila 
        {
            int nPacienteRemocao = 0;
            cout<<"Insira o número de registro do paciente para remover: ";
            cin>>nPacienteRemocao;

            objetoHospital.removePacienteEspera(nPacienteRemocao);

            system("pause");
            system("cls");
        }
        else if (opcaoMenu==4) //Exibir dados de todos os pacientes na fila 
        {
            lista = objetoHospital.dadosPacientes();
            if (lista.size()>0)
            {
                for (int i = 0; i < lista.size(); i++)
                {
                cout<< "==== Paciente na posição " << i << " da espera====" <<  endl;
                cout << "Nome: " << lista[i].nomePaciente << endl;
                cout << "Motivo de atendimento: " << lista[i].motivoEntrada << endl;
                cout << "Numero de registro: " << lista[i].registroPaciente << endl << endl;
                }
            }
            else
            {
                cout<<"Nenhum paciente na fila de espera!"<<endl;
            }

            system("pause");
            system("cls");
        }
        else if (opcaoMenu==5)
        {
            int nRegistroUnico = 0;
            cout << "Insira o número de registro do paciente: ";
            cin>>nRegistroUnico;

            objetoHospital.dadosUmPaciente(nRegistroUnico);

            system("pause");
            system("cls");
        }
        else if(opcaoMenu==6) //Exibir pacientes atendidos
        {
            lista = objetoHospital.dadosPacientesAtendidos();

            if (lista.size() > 0)
            {
                for (int i = 0; i < lista.size(); i++)
                {
                cout<< "==== Paciente na posição " << i << " dos atendidos====" <<  endl;
                cout << "Nome: " << lista[i].nomePaciente << endl;
                cout << "Motivo de atendimento: " << lista[i].motivoEntrada << endl;
                cout << "Numero de registro: " << lista[i].registroPaciente << endl << endl;
                }
            }
            else
            {
                cout<<"Não há pacientes no relatório"<<endl;
            }
                
            system("pause");
            system("cls");
        }

    } while (opcaoMenu!=0);
    
    return 0;
};