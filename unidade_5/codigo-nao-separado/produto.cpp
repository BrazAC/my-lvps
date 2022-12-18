/*
> Discente: Braz Amorim Campos
> Matrícula: 121210160
> Período: 2021.2
> Curso: Engenharia elétrica
> Disciplina: Técnicas de programação
> Turma: 01
> Professor: Marcus Salerno
> Unidade 2: LVP-07
> Compilador utilizado: Visual Studio Code

>   Um vendedor está precisando de um programa para armazenar os seus produtos em uma lista para poder vender aos seus clientes. 
    Para realizar a manipulação dessa lista, ele precisa inserir um produto e sua quantidade na lista. 
    Ele pode também adicionar uma certa quantidade para um determinado produto, vender uma determinada quantidade de um produto 
    (só pode subtrair se tiver essa quantidade no estoque); pesquisar um determinado produto, apresentando a quantidade existente; 
    e exibir os produtos existentes na lista com as respectivas quantidades.
*/
#include "produto.h"

//====Construct Vendedor====//
vendedor::vendedor(int tamanhoLista){
    this->tamanhoLista = (tamanhoLista>=0) ? tamanhoLista:0;
    osProdutos = new produto[tamanhoLista];

    quatAtual=0;
}
//=====Destruct Vendedor====//
vendedor::~vendedor(){
}

//==========================METODOS DE "PRODUTO"============================//
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

//================================METODOS DE "VENDEDOR"=====================//
void vendedor::setTamanhoLista(int tamanhoLista){
    this->tamanhoLista = tamanhoLista;
}
void vendedor::editQuantidade(vendedor nomeObjeto, string nomeProduto, int subOpcao){
    int indexDoProduto = nomeObjeto.pesquisaIndex(nomeProduto);
    int opcao = subOpcao;
    int testeExistencia = nomeObjeto.pesquisaExistencia(osProdutos[indexDoProduto]);

    if (testeExistencia!=0){
        if(opcao == 1){
            int quatUnidades;
            cout<<"Insira a quantidade de unidades para adicionar ao estoque: ";
            cin>>quatUnidades;
            osProdutos[indexDoProduto].adicionaProduto(quatUnidades);
        }
        else
        {
            int quatUnidades;
            cout<<"Insira a quantidade de unidades para remover do estoque: ";
            cin>>quatUnidades;
            osProdutos[indexDoProduto].subtraiProduto(quatUnidades);
        }
    }
    else
    {
        cout<<"O produto inserido nao existe";
    }
    
}
void vendedor::cadastraProduto(produto produtoAtual){
    //Limitando o armazenamento ao tamanho da lista
    if (quatAtual<tamanhoLista){
        int condicao = 1;
        string nomeInserido = produtoAtual.getNomeProduto();

        //Descobrindo se o nome do produto já está na lista
        for(int i=0;i<tamanhoLista;i++){
            
            string nomeAtual = osProdutos[i].getNomeProduto();

            if(nomeAtual == nomeInserido){
                condicao = 0;
            }     
        }

        //Armazenando ou não o produto na lista
        if (condicao==0){
            cout<< "Produto já cadastrado!"<< endl;
            
        }
        else{
            osProdutos[quatAtual]=produtoAtual;
            quatAtual++;
        }

    }
    else
    {
        cout << "Estoque cheio! Nao e possivel cadastrar mais produtos." << endl;
    }   
}
int vendedor::pesquisaIndex(string nomeProdutoRecebido){
    int index;

    for (int i=0;i<tamanhoLista;i++){
        string nomeProdutoAtual = osProdutos[i].getNomeProduto();
        if(nomeProdutoAtual==nomeProdutoRecebido){
            index=i;
        }
    }
    return index;
}
int vendedor::pesquisaExistencia(produto produtoAtual){
    string nomeInserido = produtoAtual.getNomeProduto();
    int condicao = 1;
    for(int i=0;i<tamanhoLista;i++){
        string nomeAtual = osProdutos[i].getNomeProduto();
        if(nomeAtual == nomeInserido){
        condicao = 0;
        }     
    }
    if (condicao == 0){
        return 1;
    }
    else
    {
        return 0;
    }
    //Se retornar 1 o produto existe, se retornar 0 nao existe.
}
int vendedor::mostraQuantidadeProduto(vendedor nomeObjeto, string nomeProduto){
    int indexDoProduto = nomeObjeto.pesquisaIndex(nomeProduto);
    int testeExistencia = nomeObjeto.pesquisaExistencia(osProdutos[indexDoProduto]);

    if (testeExistencia!=0){
        int quatProduto = osProdutos[indexDoProduto].getQuatProduto();
        return quatProduto; 
    }
    else
    {
        cout<<"O produto inserido nao existe";
    }

}
string vendedor::getNomeProdtLista(int index){
    string nomeDoProduto = osProdutos[index].getNomeProduto();
    return nomeDoProduto;
}
int vendedor::getQuatProdtLista(int index){
    int quatDoProduto = osProdutos[index].getQuatProduto();
    return quatDoProduto;
}

