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
#include "estacionamento.h"
//============================\\Construct e Destruct
estacionamento::estacionamento(){
    valorHoraInicial = 7.0;
    horaIn.hora = horaIn.minuto = horaIn.segundo = 0;
    horaOut.hora = horaOut.minuto = horaOut.segundo = 0;
};
estacionamento::~estacionamento(){
    cout<< endl <<"FIM DO PROGRAMA";
};
//============================\\Métodos
void estacionamento::setPlaca(string placa){
    this->placa = placa;
};
string estacionamento::getPlaca(){
    return placa;
};
//------------------------------
void estacionamento::setNomeProprietario(string nomeProprietario){
    this -> nomeProprietario = nomeProprietario;
};
string estacionamento::getNomeProprietario(){
    return nomeProprietario;
};
//-----------------------------
void estacionamento::setHoraEntrada(int horaIn, int minutoIn, int segundoIn){ 
    this -> horaIn.hora = ceil(horaIn);
    this -> horaIn.minuto = ceil(minutoIn);
    this -> horaIn.segundo = ceil(segundoIn);
};
void estacionamento::setHoraSaida(int horaOut, int minutoOut, int segundoOut){ 
   this -> horaOut.hora = ceil(horaOut);
   this -> horaOut.minuto = ceil(minutoOut);
   this -> horaOut.segundo = ceil(segundoOut);
};
//-----------------------------
void estacionamento::setTempoTotal(){
    //Essas 3 variaveis contem as entradas do momento da entrada em segundos
    int horaEntradaConvertido = horaIn.hora*3600;
    int minutoEntradaConvertido = horaIn.minuto*60;
    int segundosEntrada = horaIn.segundo;
    //Soma das convercoes    
    int somaSegundosEntrada = horaEntradaConvertido + minutoEntradaConvertido + segundosEntrada; 

    //Essas 3 variaveis contem as entradas do momento da saida em segundos
    int horaSaidaConvertido = horaOut.hora*3600;
    int minutoSaidaConvertido = horaOut.minuto*60;
    int segundosSaida = horaOut.segundo;
    //Soma das convercoes  
    int somaSegundosSaida = horaSaidaConvertido + minutoSaidaConvertido + segundosSaida; 

    //Tempo total ocupado
    tempoTotal = ceil((double(somaSegundosSaida - somaSegundosEntrada)/3600.0));
};

int estacionamento::getTempoTotal(){
    return tempoTotal;
};
//-----------------------------
void estacionamento::setValorTotal(){
    valorTotal = (2*(tempoTotal - 1.0)) + valorHoraInicial;

};

float estacionamento::getValorTotal(){
    return valorTotal;
};
