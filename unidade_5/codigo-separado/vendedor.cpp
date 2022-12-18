#include "vendedor.h"

//====Construct Vendedor====//
vendedor::vendedor(int tamanhoLista){
    this->tamanhoLista = (tamanhoLista>=0) ? tamanhoLista:0;
    osProdutos = new produto[tamanhoLista];

    quatAtual=0;
}
//=====Destruct Vendedor====//
vendedor::~vendedor(){
}


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