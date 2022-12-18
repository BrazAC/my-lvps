#ifndef PACIENTE_H
#define PACIENTE_H

class paciente{
    public:
    string nomePaciente, motivoEntrada;
    int registroPaciente;

    public:
    void setNomePaciente (string);
    void setMotivoEntrada (string);
    void setRegistroPaciente (int);
    //===========================//
    string getNomePaciente ();
    int getRegistroPaciente ();

};
#endif "PACIENTE_H"