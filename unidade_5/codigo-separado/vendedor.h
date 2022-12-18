#ifndef VENDEDOR_H
#define VENDEDOR_H
class vendedor{
    private:
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
#endif //VENDEDOR_H