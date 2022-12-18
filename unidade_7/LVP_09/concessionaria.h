#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H
class concessionaria{
    public:
        vector <carro> carros;
        vector <caminhao> caminhoes;
    public:
        void addCarroNoVetor(carro);
        void addCaminhaoNoVetor(caminhao);
        void removerCarroDoVetor(int);
        void removerCaminhaoDoVetor(int);
        int testaExisteCarro(int);
        int testaExisteCaminhao(int);

        vector<carro> getVetorCarros();
        vector<caminhao> getVetorCaminhoes();
};

#endif 