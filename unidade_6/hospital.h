#ifndef HOSPITAL_H
#define HOSPITAL_H

class hospital{
    private:
        vector <paciente> filaEspera;
        vector <paciente> filaAtendidos;
        vector <paciente>::iterator it1;

    public:
    void cadastraPacienteEmFila (paciente);
    void removePacienteEspera (int);
    void atendepaciente ();
    void dadosUmPaciente(int);
    vector <paciente> dadosPacientes();
    vector <paciente> dadosPacientesAtendidos();

};

#endif "HOSPITAL_H "