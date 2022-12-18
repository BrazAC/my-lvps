#include "veiculo.h"
void Veiculo::setAnoFabricacao(int anoFabricacao){
    this->anoFabricacao=anoFabricacao;
}
void Veiculo::setNumeroChassi(int numeroChassi){
    this->numeroChassi=numeroChassi;
}
void Veiculo::setPreco(int preco){
    this->preco=preco;
}

int Veiculo::getAnoFabricacao(){
    return anoFabricacao;
}
int Veiculo::getNumeroChassi(){
    return numeroChassi;
}
int Veiculo::getPreco(){
    return preco;
}
