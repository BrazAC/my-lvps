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

>Obs: Deixei funções comentadas que construi para testar pontos do código, pois as mesmas podem ser usadas
    em futuros testes por outrem e não atrapalham a visualização do programa.
*/


#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> //Biblioteca para a função "setprecision()"
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

        //void valorAreaMin();
        float getValorAreaMin();

        //void ValorEcono();
        float getValorEcono();
};
//-------------------------------------------------------------CLASSE
void empresa_solar::setPot_imovel(float x){
    pot_imovel = x;
}
void empresa_solar::setVal_mensal(float y){
    val_mensal = y;
}
/* 
float empresa_solar::getPotImovel (){ 
    float c = pot_imovel;
    return c;
}
float empresa_solar::getVal_mensal (){
    float v = val_mensal;
    return v;
}
*/
//-----------------------------------------------------------=
void empresa_solar::quantidade_pain(){
    quant_painel = ceil(pot_imovel/pot_painel);
}
int empresa_solar::getQuantidade_pain(){
    int j = quant_painel;
    return j;
}
//-----------------------------------------------------------=
/*
void empresa_solar::valorAreaMin(){
    area_min = quant_painel * area_painel;
}
*/
float empresa_solar::getValorAreaMin(){
    float l = quant_painel * area_painel;
    return l;
}
//-----------------------------------------------------------=
/*
void empresa_solar::ValorEcono(){
    econ_anual = (val_mensal*90/100) * 12;
}
*/
float empresa_solar::getValorEcono(){
    float p = (val_mensal*90/100) * 12;
    return p;
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

    //cout << endl << "A potencia do imovel e: " << cliente.getPotImovel();
    //cout << endl << "O gasto  do imovel e: " << cliente.getVal_mensal();
    return 0;
}