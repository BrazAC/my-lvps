#include "hospital.h"
#include "paciente.h"

void hospital::cadastraPacienteEmFila(paciente novoPaciente){
    for (int i = 0; i < filaEspera.size(); i++)
    {

        if (filaEspera[i].registroPaciente == novoPaciente.registroPaciente)
        {
            cout<<"Não foi possível cadastrar o paciente!"<<endl;
        }
        
    }
    
    filaEspera.push_back(novoPaciente);
}

void hospital::removePacienteEspera(int registroPaciente){

    for (int i = 0; i < filaEspera.size(); i++){
        int registroAtual = filaEspera[i].getRegistroPaciente();
        if (registroPaciente == registroAtual)
        {
            filaEspera.erase(filaEspera.begin())+i;
        }
        else
        {
            cout << "Paciente não encontrado!"<<endl;
        }
        
    }
}

void hospital::atendepaciente(){
    if (filaEspera.size() > 0)
    {
        filaAtendidos.push_back(filaEspera.front());
	    filaEspera.erase(filaEspera.begin());
        cout<< "O primeiro paciente da fila foi antendido!"<<endl;
    }
    else
    {
        cout<<"Nenhum paciente na fila de espera!"<<endl;
    }
    
    
}

vector <paciente> hospital::dadosPacientes(){
    return filaEspera;
}

vector <paciente> hospital::dadosPacientesAtendidos(){
    return filaAtendidos;
}

void hospital::dadosUmPaciente(int numeroRegistro){
    int estado;
    if (filaEspera.empty())
    {
        estado = 0;
    }
    else
    {
        estado = 1;
    }

    for (int i = 0; i < filaEspera.size(); i++)
    {
        if (1)
        {
            if (numeroRegistro == filaEspera[i].registroPaciente)
            {
            cout<< "==== Paciente na posição " << i << " ====" <<  endl;
            cout << "Nome: " << filaEspera[i].nomePaciente << endl;
            cout << "Motivo de atendimento: " << filaEspera[i].motivoEntrada << endl;
            cout << "Número de registro: " << filaEspera[i].registroPaciente << endl << endl;
            } 
        }
        else
        {
            cout << "Paciente não encontrado ou fila vazia"<<endl;
        }
            

    }
    
    
}