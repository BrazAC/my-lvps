#ifndef CAMINHAO_H
#define CAMINHAO_H

class caminhao : public Veiculo{
    public:
        string tipoVeiculoCA;
        string modeloVeiculoCA;
        string classificacao;
        int capacidadeCarga, rankingVendas;
    public:
        caminhao(string="",string="", string="",int=0,int=0,int=0,int=0,int=0);
        void setTipo_e_ModeloVeiculoCA(int, int);
        void setClassificacao(int);
        int getRankingVenda();
        int getCapacidadeCarga();
        string getTipoVeiculoCA();
        string getModeloVeiculoCA();
        string getClassificacao();

};
#endif 