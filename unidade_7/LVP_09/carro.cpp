#include "carro.h"
string carro::getModelo(){
    return modeloVeiculoCR;
}

void carro::setTipo_e_ModeloVeiculoCR(int opcaoTipoVeiculo, int opcaoModeloVeiculo){
    if (opcaoTipoVeiculo == 1)
    {
        tipoVeiculoCR="CROSSOVER";
        if (opcaoModeloVeiculo==1)
        {
            modeloVeiculoCR="Duster";
        }
        else if (opcaoModeloVeiculo==2)
        {
            modeloVeiculoCR="Renegate";
        }
        else if (opcaoModeloVeiculo==3)
        {
            modeloVeiculoCR="Ecosport";
        }
    }
    else if (opcaoTipoVeiculo == 2)
    {
        tipoVeiculoCR="HATCH";
        if (opcaoModeloVeiculo==1)
        {
            modeloVeiculoCR="Gol";
        }
        else if (opcaoModeloVeiculo==2)
        {
            modeloVeiculoCR="Uno";
        }
        else if (opcaoModeloVeiculo==3)
        {
            modeloVeiculoCR="Corsa";
        }
    }
    else if (opcaoTipoVeiculo == 3)
    {
        tipoVeiculoCR="PICAPE";
        if (opcaoModeloVeiculo==1)
        {
            modeloVeiculoCR="Pampa";
        }
        else if (opcaoModeloVeiculo==2)
        {
            modeloVeiculoCR="Saveiro";
        }
        else if (opcaoModeloVeiculo==3)
        {
            modeloVeiculoCR="Toro";
        }
        else if (opcaoModeloVeiculo==4)
        {
            modeloVeiculoCR="Hilux";
        }  
    }
    else if (opcaoTipoVeiculo == 4)
    {
        tipoVeiculoCR="SEDAN";
        if (opcaoModeloVeiculo==1)
        {
            modeloVeiculoCR="Polo";
        }
        else if (opcaoModeloVeiculo==2)
        {
            modeloVeiculoCR="Fiesta";
        }
        else if (opcaoModeloVeiculo==3)
        {
            modeloVeiculoCR="Prisma";
        }
        else if (opcaoModeloVeiculo==4)
        {
            modeloVeiculoCR="Voyage";  
        }  
    }
    else if (opcaoTipoVeiculo == 5)
    {
        tipoVeiculoCR="SUV";
        if (opcaoModeloVeiculo==1)
        {
            modeloVeiculoCR="Tracker";
        }
        else if (opcaoModeloVeiculo==2)
        {
            modeloVeiculoCR="Compass";
        }
        else if (opcaoModeloVeiculo==3)
        {
            modeloVeiculoCR="HVR";
        }
    }
}