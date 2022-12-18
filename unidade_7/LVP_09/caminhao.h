#ifndef CAMINHAO_H
#define CAMINHAO_H

class caminhao : public Veiculo{
    public:
        string tipoVeiculoCA;
        string modeloVeiculoCA;
        string classificacao;
        int capacidadeCarga, rankingVendas;
    public:
        void setTipo_e_ModeloVeiculoCA(int, int);
        void setClassificacao(int);
        int getRankingVenda();

};
#endif 