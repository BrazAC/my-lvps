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
#include <iostream>
#include <string>
#include <clocale>
#include <cmath>
#include <iomanip>
using namespace std;
#include "estacionamento.cpp"

int main () {
    estacionamento objetoEstacionamento;

    int horaIn, minutoIn, segundoIn = 0;
    int horaOut, minutoOut, segundoOut = 0;
    int horasTotais;
    float valorTotalaPagar;

    string placaCarroInserido, placaCarro;
    string nomeProprietarioInserido, nomeProprietario;

    cout << "Placa do carro: ";
    cin >> placaCarroInserido;
    objetoEstacionamento.setPlaca(placaCarroInserido);

    cout << "Proprietario: ";
    getline(cin>>ws, nomeProprietarioInserido);
    objetoEstacionamento.setNomeProprietario(nomeProprietarioInserido);

    cout << "Hora/Minuto/Segundo de entrada: ";
    cin >> horaIn;
    cin >> minutoIn;
    cin >> segundoIn;
    objetoEstacionamento.setHoraEntrada(horaIn, minutoIn, segundoIn);

    cout << "Hora/Minuto/Segundo de saida: ";
    cin >> horaOut;
    cin >> minutoOut;
    cin >> segundoOut;
    objetoEstacionamento.setHoraSaida(horaOut, minutoOut, segundoOut);

    placaCarro = objetoEstacionamento.getPlaca();
    cout << "Placa: " << placaCarro << endl;

    nomeProprietario = objetoEstacionamento.getNomeProprietario();
    cout << "Nome Proprietario: " << nomeProprietario << endl;

    objetoEstacionamento.setTempoTotal();
    horasTotais = objetoEstacionamento.getTempoTotal();
    cout << "Horas ocupadas: " << horasTotais << "h" << endl;

    objetoEstacionamento.setValorTotal();
    valorTotalaPagar = objetoEstacionamento.getValorTotal();
    cout << "Valor a ser pago: RS " << valorTotalaPagar;

    return 0;
}