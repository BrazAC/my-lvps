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
#ifndef PRODUTO_H
#define PRODUTO_H

class produto {
    private:
        string nomeProduto;
        int quatProduto;  
    public:
    //====Set====//
    void setNomeProduto(string);
    void setQuatProduto(int);

    void adicionaProduto(int);
    void subtraiProduto(int);
    //====Get====//
    string getNomeProduto();
    int getQuatProduto();
};

class vendedor{
    private:
        //Objeto Produto
        //Lista de produtos com alocação dinâmica
        produto *osProdutos;  //Nome da lista
        int tamanhoLista;   //Tamanho da lista
        int quatAtual;
    public:
        vendedor(int);
        void editQuantidade(vendedor, string, int);
        int pesquisaExistencia(produto);
        //====Set====//
        void setTamanhoLista(int);
        void cadastraProduto(produto);
        //====Get====//
        int getTamanholista();
        int pesquisaIndex(string);
        int mostraQuantidadeProduto(vendedor, string);
        string getNomeProdtLista(int);
        int getQuatProdtLista(int);

        ~vendedor();

};
#endif //PRODUTO_H