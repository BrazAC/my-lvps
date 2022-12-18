/*
> Discente: Braz Amorim Campos
> Matrícula: 121210160
> Período: 2021.2
> Curso: Engenharia elétrica
> Disciplina: Técnicas de programação
> Turma: 01
> Professor: Marcus Salerno
> Unidade 2: LVP-06
> Compilador utilizado: Visual Studio Code

>   Crie uma classe Estacionamento para armazenar dados de um estacionamento. Os atributos devem representar a placa e o nome do proprietário do carro, 
    além das horas de entrada e de saída do estacionamento (a hora deve ser uma struct). 
    Inclua também um atributo para armazenar o valor da hora inicial do estacionamento que deve ter o valor R$7,00.
*/
#ifndef ESTACIONAMENTO_H
#define ESTACIONAMENTO_H

struct horas{
    int hora, minuto, segundo;
};

class estacionamento {
    private:
        string placa, nomeProprietario;
        float valorHoraInicial;
        int tempoTotal;
        float valorTotal;
        horas horaIn;
        horas horaOut;
    public:
        estacionamento();
        //========SET========//
        void setPlaca(string);
        void setNomeProprietario(string);
        void setHoraEntrada(int, int, int);
        void setHoraSaida(int, int, int);      
        void setValorTotal();
        void setTempoTotal();  
        
        //========GET========//
        string getPlaca();
        string getNomeProprietario();
        int getHoraEntrada(); 
        int getHoraSaida();  
        int getTempoTotal();
        float getValorTotal();

        void getDadosCarro();
        //===================//
        ~estacionamento();
};

#endif  //ESTACIONAMENTO_H