#include "concessionaria.h"
void concessionaria::addCarroNoVetor(carro objetoCarro){
    int condicaoExistencia = testaExisteCarro(objetoCarro.numeroChassi);
    if (condicaoExistencia == 0)
    {
        carros.push_back(objetoCarro);
        cout<<"Veiculo cadastrado com sucesso!"<<endl;
    }
    else if (condicaoExistencia > 0)
    {
        cout<<"Esse chassi ja esta cadastrado no sistema"<<endl;
    }
}

void concessionaria::addCaminhaoNoVetor(caminhao objetoCaminhao){
    int condicaoExistencia = testaExisteCaminhao(objetoCaminhao.numeroChassi);
    if (condicaoExistencia == 0)
    {
        caminhoes.push_back(objetoCaminhao);
        cout<<"Veiculo cadastrado com sucesso!"<<endl;
    }
    else if (condicaoExistencia > 0)
    {
        cout<<"Esse chassi ja esta cadastrado no sistema"<<endl;
    }
}

void concessionaria::removerCarroDoVetor(int numeroChassi){
    int tam = carros.size();
    if (tam == 0)
    {
        cout<<"Nao existem carros cadastrados no sistema"<<endl;
    }
    else if (tam > 0)
    {
        int soma=0;
        for (int i = 0; i < tam; i++)
        {
            int chassiAtual = carros[i].numeroChassi;
            
            if (chassiAtual == numeroChassi)
            {
                carros.erase(carros.begin()+i);
                cout<<"Carro vendido com sucesso"<<endl;
            }
            else if (chassiAtual != numeroChassi)
            {
                soma++;
            }
        }
        if (soma==tam)
        {
            cout<<"Nao existe carro com esse chassi no sistema"<<endl;
        }
    }
}

void concessionaria::removerCaminhaoDoVetor(int numeroChassi){
    int tam = caminhoes.size();
    if (tam == 0)
    {
        cout<<"Nao existem caminhoes cadastrados no sistema"<<endl;
    }
    else if (tam > 0)
    {
        int soma = 0;
        for (int i = 0; i < tam; i++)
        {
            int chassiAtual = caminhoes[i].numeroChassi;
            if (chassiAtual == numeroChassi)
            {
                caminhoes.erase(caminhoes.begin()+i);
                cout<<"Caminhao vendido com sucesso"<<endl;
            }
            else if (chassiAtual != numeroChassi)
            {
                soma++;
            }
        }
        if (soma == tam)
        {
            cout<<"Nao existe caminhao com esse chassi no sistema"<<endl;  
        }
    }   
}

vector<carro> concessionaria::getVetorCarros(){
    return carros;
}

vector<caminhao> concessionaria::getVetorCaminhoes(){
    return caminhoes;
}

bool comparacaoSTR(carro objetoCarro1, carro objetoCarro2){
    return objetoCarro1.getModelo() < objetoCarro2.getModelo();
}

bool comparacaoINT(caminhao objetoCaminhao1, caminhao objetoCaminhao2){
    return objetoCaminhao1.getRankingVenda() < objetoCaminhao2.getRankingVenda();
}


int concessionaria::testaExisteCarro(int numeroChassi){
    vector <carro> listaCarros = getVetorCarros();
    int testador = 0;
    int tam = listaCarros.size();
    for (int i = 0; i < tam; i++)
    {
        if (numeroChassi == listaCarros[i].numeroChassi)
        {
            testador++;
        }
            
    }
    return testador;
}
int concessionaria::testaExisteCaminhao(int numeroChassi){
    vector <caminhao> listaCaminhoes = getVetorCaminhoes();
    int testador = 0;
    int tam = listaCaminhoes.size();
    for (int i = 0; i < tam; i++)
    {
        if (numeroChassi == listaCaminhoes[i].numeroChassi)
        {
            testador++;
        }
            
    }
    return testador;
}
