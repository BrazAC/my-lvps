/*
> Discente: Braz Amorim Campos
> Matrícula: 121210160
> Período: 2021.2
> Curso: Engenharia elétrica
> Disciplina: Técnicas de programação
> Turma: 01
> Professor: Marcus Salerno
> Unidade 2: LVP-04
> Compilador utilizado: Visual Studio Code

> Descrição do LVP: Crie uma classe Empresa_Solar para calcular a quantidade de painéis solares 
    necessários para uma residência em função do consumo mensal em kWh do imóvel. Além do número de 
    painéis deverá ser determinado também a área mínima que esses painéis ocupam e a economia anual 
    gerada pela adoção do sistema com base no valor mensal gasto pelo imóvel, fornecido pelo usuário em reais.
*/
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
//-------------------------------------------------------------CLASSE
class empresa_solar{
    private:
        float pot_imovel, val_mensal;
        float pot_painel = 32.0;
        float area_painel = 2.5;
        float quant_painel; 

    public:
        void setPot_imovel(float);
        void setVal_mensal(float);
        float getPotImovel ();
        float getVal_mensal();


        void quantidade_pain();
        int getQuantidade_pain();

        float getValorAreaMin();

        float getValorEcono();
};
//-------------------------------------------------------------CLASSE
void empresa_solar::setPot_imovel(float potenciaInserida){
    pot_imovel = potenciaInserida;
}
void empresa_solar::setVal_mensal(float valMensalInserido){
    val_mensal = valMensalInserido;
}

//-----------------------------------------------------------=
void empresa_solar::quantidade_pain(){
    quant_painel = ceil(pot_imovel/pot_painel);
}
int empresa_solar::getQuantidade_pain(){
    int quantidadeDePainel = quant_painel;
    return quantidadeDePainel;
}
//-----------------------------------------------------------=
float empresa_solar::getValorAreaMin(){
    float areaMinima = quant_painel * area_painel;
    return areaMinima;
}
//-----------------------------------------------------------=
float empresa_solar::getValorEcono(){
    float valorEconomizado = (val_mensal*90/100) * 12;
    return valorEconomizado;
}
//-----------------------------------------------------------=
int main (){
    empresa_solar cliente;
    float inPot, inGasto;

    cout << "Potencia mensal kwh: ";
    cin >> inPot;
    cliente.setPot_imovel(inPot);

    cout << "Gasto mensal em RS: ";
    cin >> inGasto;
    cliente.setVal_mensal(inGasto);

    cliente.quantidade_pain();

    cout << fixed << setprecision(2);
    cout << endl << "Quantidade de paineis necessarios: " << cliente.getQuantidade_pain() << endl;
    cout << "Area minima para instalacao: " << cliente.getValorAreaMin() << endl;
    cout << "Economia anual: RS " << cliente.getValorEcono() << endl;

    return 0;
}