#include <string>
#include <iostream>
using namespace std;

struct horario{
    int horas, minut, seg;
};

struct data{
    int dia, mes, ano;
};

struct compromise{
    string descritivo;
    int fData[3];
    int fHorario[3];
};

int main (){
    horario time;
    data day;
    compromise compromisso;

    cout << "Insira o valor da hora: ";
    cin >> time.horas;  //-
    cout << "Insira o valor do minuto: ";
    cin >> time.minut;  //-
    cout << "Insira o valor do segundo: ";
    cin >> time.seg;    //-

    cout << "Insira o dia: ";
    cin >> day.dia; //-
    cout << "Insira o mes: ";
    cin >> day.mes; //-
    cout << "Insira o ano: ";
    cin >> day.ano; //-

    cout << "Qual o compromisso?" << endl;
    getline (cin>>ws, compromisso.descritivo);
    //-
    compromisso.fData[0] = day.dia;
    compromisso.fData[1] = day.mes;
    compromisso.fData[2] = day.ano;
    //-
    compromisso.fHorario[0] = time.horas;
    compromisso.fHorario[1] = time.minut;
    compromisso.fHorario[2] = time.seg;

    cout << endl << "Horario: " << compromisso.fHorario[0] << ":" << compromisso.fHorario[1] << ":" << compromisso.fHorario[2] << endl;
    cout << "Data: " << compromisso.fData[0] << "/" << compromisso.fData[1] << "/" << compromisso.fData[2] << endl;
    cout << "Compromisso: " << compromisso.descritivo;

    return 0;
}