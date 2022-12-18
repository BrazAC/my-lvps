#ifndef VEICULO_H
#define VEICULO_H

class Veiculo{
    public:
        int anoFabricacao;
        int numeroChassi;
        int preco;
    public:
    void setAnoFabricacao(int);
    void setNumeroChassi(int);
    void setPreco(int);

    int getAnoFabricacao();
    int getNumeroChassi();
    int getPreco();
};

#endif 