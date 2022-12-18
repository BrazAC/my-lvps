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
#endif //PRODUTO_H