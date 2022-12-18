#include "paciente.h"
#include "hospital.h"

void paciente::setNomePaciente(string nomePaciente){
    this -> nomePaciente = nomePaciente;
}

void paciente::setMotivoEntrada(string motivoEntrada){
    this -> motivoEntrada = motivoEntrada;
}

void paciente::setRegistroPaciente(int registroPaciente){
    this -> registroPaciente = registroPaciente;
}

string paciente::getNomePaciente(){
    return nomePaciente;
}

int paciente::getRegistroPaciente(){
    return registroPaciente;
}