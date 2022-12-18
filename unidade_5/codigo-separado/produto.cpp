#include "produto.h"
//======Funções de Set========//
void produto::setNomeProduto(string nomeProduto){
    this->nomeProduto = nomeProduto;
}
void produto::setQuatProduto(int quatProduto){
    this->quatProduto=quatProduto;
}

void produto::adicionaProduto(int quatParaSoma){
    quatProduto = quatProduto + quatParaSoma;
}
void produto::subtraiProduto(int quatParaSubtracao){

    if (quatParaSubtracao<=quatProduto){
        quatProduto = quatProduto - quatParaSubtracao;
    }
    else
    {
        cout << "Quantidade insuficiente no estoque!" << endl;
    }
    
}
//======Funções de Get========//
string produto::getNomeProduto(){
    return nomeProduto;
}
int produto::getQuatProduto(){
    return quatProduto;
}