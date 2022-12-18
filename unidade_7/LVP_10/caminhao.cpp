#include "caminhao.h"
caminhao::caminhao(string tipoVeiculoCA, string modeloVeiculoCA, string classificacao,int anoFabricacao, int numeroChassi ,int preco, int capacidadeCarga, int rankingVendas){
    this->tipoVeiculoCA=tipoVeiculoCA;
    this->modeloVeiculoCA=modeloVeiculoCA;
    this->classificacao=classificacao;
    this->anoFabricacao=anoFabricacao;
    this->numeroChassi=numeroChassi;
    this->preco=preco;
    this->capacidadeCarga=capacidadeCarga;
    this->rankingVendas=rankingVendas;
}

int caminhao::getRankingVenda(){
    return rankingVendas;
}
int caminhao::getCapacidadeCarga(){
    return capacidadeCarga;
}
string caminhao::getTipoVeiculoCA(){
    return tipoVeiculoCA;
}
string caminhao::getModeloVeiculoCA(){
    return modeloVeiculoCA;
}
string caminhao::getClassificacao(){
    return classificacao;
}

void caminhao::setClassificacao(int rankingVendas){
    if ( rankingVendas > 0 && rankingVendas < 11)
    {
        classificacao = "Otima";
    }
    else if (rankingVendas > 20)
    {
        classificacao = "Nao classificado";
    }
    else if (rankingVendas > 10 && rankingVendas < 21)
    {
        classificacao = "Muito boa";
    }
}

void caminhao::setTipo_e_ModeloVeiculoCA(int opcaoTipoVeiculo, int opcaoModeloVeiculo){
    if (opcaoTipoVeiculo == 1)
    {
        tipoVeiculoCA="TOCO";
        capacidadeCarga = 5;
        if (opcaoModeloVeiculo==1)
        {
            modeloVeiculoCA="Vw 15190";
        }
        else if (opcaoModeloVeiculo==2)
        {
            modeloVeiculoCA="Ford F11000";
        }
        else if (opcaoModeloVeiculo==3)
        {
            modeloVeiculoCA="Scania P340";
        }
    }
    else if (opcaoTipoVeiculo == 2)
    {
        tipoVeiculoCA="TRUCK";
        capacidadeCarga = 11;
        if (opcaoModeloVeiculo==1)
        {
            modeloVeiculoCA="Vw 24250";
        }
        else if (opcaoModeloVeiculo==2)
        {
            modeloVeiculoCA="Mb 1620";
        }
        else if (opcaoModeloVeiculo==3)
        {
            modeloVeiculoCA="Ford Cargo 2428";
        }
    }
    else if (opcaoTipoVeiculo == 3)
    {
        tipoVeiculoCA="CARRETA SIMPLES";
        capacidadeCarga = 25;
        if (opcaoModeloVeiculo==1)
        {
            modeloVeiculoCA="Volvo Fh 540";
        }
        else if (opcaoModeloVeiculo==2)
        {
            modeloVeiculoCA="Ford Cargo 1933";
        } 
    }
    else if (opcaoTipoVeiculo == 4)
    {
        tipoVeiculoCA="EIXO ESTENDIDO";
        capacidadeCarga=33;
        if (opcaoModeloVeiculo==1)
        {
            modeloVeiculoCA="Man Tgx 28440";
        }
        else if (opcaoModeloVeiculo==2)
        {
            modeloVeiculoCA="Volvo Fh 440";
        } 
    }
}