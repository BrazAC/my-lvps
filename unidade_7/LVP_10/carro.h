#ifndef CARRO_H
#define CARRO_H

class carro : public Veiculo{
    public:
        string tipoVeiculoCR;
        string modeloVeiculoCR;
    public:
        carro(string="",string="",int=0,int=0,int=0);
        void setTipoVeiculo(int);
        void setTipo_e_ModeloVeiculoCR(int, int);
        string getModelo ();
        string getTipo();
};

#endif 