/*
> Discente: Braz Amorim Campos
> Matrícula: 121210160
> Período: 2021.2
> Curso: Engenharia elétrica
> Disciplina: Técnicas de programação
> Turma: 01
> Professor: Marcus Salerno
> Unidade 2: LVP-05
> Compilador utilizado: Visual Studio Code

>   Implemente um sistema de gerenciamento de banco de baterias (BMS). O BMS é composto de sensores, um concentrador e acessórios. 
    Sua função principal é, a partir do sensoriamento de variáveis importantes, comparar os dados recebidos com valores ideais de funcionamento. 
    Em caso de valores não conformes com condições pré-definidas, o Controlador BMS detecta a disparidade e emite um aviso sobre tal condição, 
    com o objetivo de garantir segurança. Utilizado principalmente em veículos elétricos, o programa controlador BMS coleta e testa os dados. 
    Dessa forma, o programa deverá inicializar o valor dos atributos dos dados sensoriados através do construtor e demonstrar a utilização do 
    método destrutor através de uma mensagem de sinalização da execução do método.
*/
#include <iostream>
using namespace std;
//--------------------------------------------------------------------------------//
class bms {
    private:
        float tensaoInst, temperBat, correnteBat, cargaBateria, correnteMax, potenciaSist;

    public:
        bms();
        //-------MAIN----------//
        void estadoDaCarga ();
        void estadoDaTemperatura ();
        void estadoDaCorrente ();
        void calculoPote();
        //--------GET----------//
        float getTensaoInst ();
        float getTemperBat();
        float getCorrenteBat();
        float getCargaBateria();
        float getCorrenteMax();
        float getPotenciaSist();
        //---------SET---------//
        void setTensaoInst (float);
        void setTemperBat(float);
        void setCorrenteBat(float);
        void setCargaBateria(float);
        void setCorrenteMax(float);
        //---------------------//
        ~bms();
};
//--------------------------------------------------------------------------------//
bms::bms(){
    tensaoInst=temperBat=correnteBat=cargaBateria=correnteMax=potenciaSist = 0;
};
bms::~bms(){
    cout << endl << "TESTES REALIZADOS COM SUCESSO!";
};
//==========//==========//==========//==========//
void bms::setTensaoInst(float tensaoInstInserida){
    tensaoInst = tensaoInstInserida;
};
void bms::setTemperBat (float temperBatInserida){
    temperBat = temperBatInserida;
};
void bms::setCorrenteBat(float correnteBatInserida){
    correnteBat = correnteBatInserida;
};
void bms::setCargaBateria(float cargaBateriaInserida){
    cargaBateria = cargaBateriaInserida;
};
void bms::setCorrenteMax (float correnteMaxInserida){
    correnteMax = correnteMaxInserida;
};
//==========//==========//==========//==========//
float bms::getTensaoInst(){
    return tensaoInst;
};
float bms::getTemperBat(){
    return temperBat;
};
float bms::getCorrenteBat(){
    return correnteBat;
};
float bms::getCargaBateria(){
    return cargaBateria;
};
float bms::getCorrenteMax(){
    return correnteMax;
};
float bms::getPotenciaSist(){
    return potenciaSist;
};
//==========//==========//==========//==========//
void bms::estadoDaCarga(){
    (cargaBateria < 30) ? cout<<"Estado de carga anormal (estado de alerta)" : cout << "Estado de carga normal";
};
void bms::estadoDaCorrente(){
    (correnteBat >= correnteMax) ? cout<<"Corrente anormal (estado de alerta)" : cout << "Corrente normal";
};
void bms::estadoDaTemperatura(){
    (temperBat > 25) ? cout<<"Temperatura anormal (estado de alerta)" : cout << "Temperatura normal";
};
void bms::calculoPote(){                        
    potenciaSist = (correnteBat * tensaoInst);
};
//==========//==========//==========//==========//
int main (){
    float inputTensaoIst, inputTemperatura, inputCorrente, inputCargaBateria, inputCorrenteMax;
    bms bateria;


    cout<<"Digite o valor da tensão instantanea: ";
    cin >> inputTensaoIst;
    bateria.setTensaoInst(inputTensaoIst);

    cout<<"Digite o valor da corrente: ";
    cin>>inputCorrente;
    bateria.setCorrenteBat(inputCorrente);

    cout<<"Digite o valor da temperatura: ";
    cin>>inputTemperatura;
    bateria.setTemperBat(inputTemperatura);

    cout<<"Insira o valor da corrente de sobrecarga: ";
    cin>>inputCorrenteMax;
    bateria.setCorrenteMax(inputCorrenteMax);

    cout<<"Digite o nivel de carga da bateria (em porcentagem): ";
    cin>>inputCargaBateria;
    bateria.setCargaBateria(inputCargaBateria);

    //=======================================//

    cout<< endl << endl <<"Tensao da bateria: " << bateria.getTensaoInst() << "V" << endl;

    cout<<"Corrente da Bateria: " << bateria.getCorrenteBat() << "A ";
    bateria.estadoDaCorrente();

    bateria.calculoPote();
    cout<< endl <<"Potencia da bateria: " << bateria.getPotenciaSist() << "W " << endl;

    cout<<"Sensor de temperatura: " << bateria.getTemperBat() << "C ";
    bateria.estadoDaTemperatura();

    cout<< endl <<"Estado da carga: " << bateria.getCargaBateria() << " porcento "; 
    bateria.estadoDaCarga();

    return 0;
}