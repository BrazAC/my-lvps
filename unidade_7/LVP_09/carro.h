#ifndef CARRO_H
#define CARRO_H

class carro : public Veiculo{
    public:
        string tipoVeiculoCR;
        string modeloVeiculoCR;
    public:
        void setTipoVeiculo(int);
        void setTipo_e_ModeloVeiculoCR(int, int);
        string getModelo ();
};

#endif 