/*
> Discente: Braz Amorim Campos
> Matrícula: 121210160
> Período: 2021.2
> Curso: Engenharia elétrica
> Disciplina: Técnicas de programação
> Turma: 01
> Professor: Marcus Salerno
> Unidade 2: LVP-09
> Compilador utilizado: Visual Studio Code

> Descrição: Utilizando o LVP9 da Concessionária que vende carros e caminhões, implemente no LVP10 o salvamento e gravação em arquivo.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream> //Biblioteca para manipular arquivos
using namespace std;
#include <string>
#include "veiculo.cpp"
#include "carro.cpp"
#include "caminhao.cpp"
#include "concessionaria.cpp"

int main (){
    setlocale(LC_ALL, "Portuguese");
    concessionaria objetoConcessionaria; //Criando um objeto concessionaria
    int senha; //A senha atual é 123
    int opcao;

    cout<< "Boas vindas ao sistema, insira a senha:"<<endl;
    cin>>senha;
    system("cls");
    
    if (senha != 123)
    {
        cout<<"Senha incorreta!"<<endl;
        system("pause");
    }
    else if (senha == 123)

        do
        {
            cout<<"))==========Concessionaria==========(("<<endl;
            cout<<"Menu de opcoes: "<<endl;
            cout<<"1 - Vender um veiculo"<<endl;
            cout<<"2 - Cadastrar um veiculo"<<endl;
            cout<<"3 - Mostrar os veiculos disponiveis"<<endl;
            cout<<"0 - Encerrar o programa"<<endl;
            cout<<"OPCAO: ";
            cin>>opcao;

            system("cls");
            if (opcao == 1)
            {
                int opcao1;
                cout<<"Deseja vender carro ou caminhao?"<<endl;
                cout<<"Aperte 1 - Carro"<<endl;
                cout<<"Aperte 2 - Caminhao"<<endl;
                cout<<"OPCAO: ";
                cin>>opcao1;

                if (opcao1 == 1)
                {
                    //Retirar o carro no vetor "carros" do objetoConcessionaria
                    int numeroChassiCR;
                    cout << "\n---Venda de carro---"<<endl;
                    cout<<"Insira o chassi do carro vendido: "<<endl;
                    cin>>numeroChassiCR;
                    objetoConcessionaria.removerCarroDoVetor(numeroChassiCR);
                }
                else if (opcao1 == 2)
                {
                    //Retirar o caminhao no vetor "caminhoes" do objetoConcessionaria
                    int numeroChassiCA;
                    cout<<"---Venda de caminhao---"<<endl;
                    cout<<"Insira o chassi do caminhao vendido: "<<endl;
                    cin>>numeroChassiCA;
                    objetoConcessionaria.removerCaminhaoDoVetor(numeroChassiCA);
                    
                }

                system("pause");
                system("cls");
            }
            else if (opcao == 2)
            {
                int opcao2;
                int ano, chassi, preco;
                string tipo, modelo;

                cout << "---Cadastro de veiculos---"<<endl;

                //Perguntar se é carro ou caminhao
                cout<<"Deseja adicionar carro ou caminhao?"<<endl;
                cout<<"Aperte 1 - Carro"<<endl;
                cout<<"Aperte 2 - Caminhao"<<endl;
                cin>>opcao2;

                system("cls");
                
                //Criar um objeto carro ou caminhao e adicionando ao vetor
                if (opcao2==1)
                {
                    carro objetoCarro;
                    int opcaoTipoVeiculo, opcaoModeloVeiculo;

                    //Pedir e armazenar: ano, chassi, preço, tipo e modelo. (abrir um menu para o tipo e modelo)
                    cout<<"---Cadastro de carro----"<<endl;
                    cout<<"Ano do veiculo: "<<endl;
                    cin>>ano;
                    objetoCarro.setAnoFabricacao(ano);

                    cout<<"Chassi do veiculo: "<<endl;
                    cin>>chassi;
                    objetoCarro.setNumeroChassi(chassi);

                    cout<<"Preco do veiculo: "<<endl;
                    cin>>preco;
                    objetoCarro.setPreco(preco);

                    cout<<"Tipo de veiculo, escolha uma opcao: "<<endl;
                    cout<<"1 - CROSSOVER"<<endl;
                    cout<<"2 - HATCH"<<endl;
                    cout<<"3 - PICAPE"<<endl;
                    cout<<"4 - SEDAN"<<endl;
                    cout<<"5 - SUV"<<endl;
                    cin>>opcaoTipoVeiculo;

                    
                    cout<<"Modelo de veiculo, escolha uma opcao: "<<endl;
                    if (opcaoTipoVeiculo==1) //Crossover
                    {
                        cout<<"1 - Duster"<<endl;
                        cout<<"2 - Renegate"<<endl;
                        cout<<"3 - Ecosport"<<endl;
                        cin>>opcaoModeloVeiculo;
                    }
                    else if (opcaoTipoVeiculo==2) //Hatch
                    {
                        cout<<"1 - Gol"<<endl;
                        cout<<"2 - Uno"<<endl;
                        cout<<"3 - Corsa"<<endl;
                        cin>>opcaoModeloVeiculo;
                    }
                    else if (opcaoTipoVeiculo==3) //Picape
                    {
                        cout<<"1 - Pampa"<<endl;
                        cout<<"2 - Saveiro"<<endl;
                        cout<<"3 - Toro"<<endl;
                        cout<<"4 - Hilux"<<endl;
                        cin>>opcaoModeloVeiculo;
                    }
                    else if (opcaoTipoVeiculo==4) //Sedan
                    {
                        cout<<"1 - Polo"<<endl;
                        cout<<"2 - Fiesta"<<endl;
                        cout<<"3 - Prisma"<<endl;
                        cout<<"4 - Voyage"<<endl;
                        cin>>opcaoModeloVeiculo;
                    }
                    else if (opcaoTipoVeiculo==5) //SUV
                    {
                        cout<<"1 - Tracker"<<endl;
                        cout<<"2 - Compass"<<endl;
                        cout<<"3 - HVR"<<endl;
                        cin>>opcaoModeloVeiculo;
                    }
                    objetoCarro.setTipo_e_ModeloVeiculoCR(opcaoTipoVeiculo, opcaoModeloVeiculo);
            
                    //Adicionar o objeto carro criado ao vetor correspondente no objetoConcessionaria
                    objetoConcessionaria.addCarroNoVetor(objetoCarro);
                    
                }
                else if (opcao2==2)
                {
                    cout<<"---Cadastro de caminhao---"<<endl;
                    caminhao objetoCaminhao;
                    int ano, chassi, preco, opcaoTipoVeiculo, opcaoModeloVeiculo, rankingVendas;

                    //Pedir e armazenar: ano, chassi, preço, tipo e modelo. (abrir um menu para o tipo e modelo)
                    cout<<"Ano do veiculo: "<<endl;
                    cin>>ano;
                    objetoCaminhao.setAnoFabricacao(ano);

                    cout<<"Chassi do veiculo: "<<endl;
                    cin>>chassi;
                    objetoCaminhao.setNumeroChassi(chassi);

                    cout<<"Preco do veiculo: "<<endl;
                    cin>>preco;
                    objetoCaminhao.setPreco(preco);

                    cout<<"Tipo de veiculo, escolha uma opcao: "<<endl;
                    cout<<"1 - TOCO"<<endl;
                    cout<<"2 - TRUCK"<<endl;
                    cout<<"3 - CARRETA SIMPLES"<<endl;
                    cout<<"4 - EIXO ESTENDIDO"<<endl;
                    cin>>opcaoTipoVeiculo;

                    cout<<"Modelo de veiculo, escolha uma opcao: "<<endl;
                    if (opcaoTipoVeiculo==1) //Toco
                    {
                        cout<<"1 - Vw 15190"<<endl;
                        cout<<"2 - Ford F11000"<<endl;
                        cout<<"3 - Scania P340"<<endl;
                        cin>>opcaoModeloVeiculo;
                    }
                    else if (opcaoTipoVeiculo==2) //Truck
                    {
                        cout<<"1 - Vw 24250"<<endl;
                        cout<<"2 - Mb 1620"<<endl;
                        cout<<"3 - Ford Cargo 2428"<<endl;
                        cin>>opcaoModeloVeiculo;
                    }
                    else if (opcaoTipoVeiculo==3) //Carreta simples
                    {
                        cout<<"1 - Volvo Fh 540"<<endl;
                        cout<<"2 - Ford Cargo 1933"<<endl;
                        cin>>opcaoModeloVeiculo;
                    }
                    else if (opcaoTipoVeiculo==4) //Eixo estendido
                    {
                        cout<<"1 - Man Tgx 28440"<<endl;
                        cout<<"2 - Volvo Fh 440"<<endl;
                        cin>>opcaoModeloVeiculo;
                    }
                    objetoCaminhao.setTipo_e_ModeloVeiculoCA(opcaoTipoVeiculo,opcaoModeloVeiculo);

                    cout<<"Posicao no ranking de vendas: "<<endl;
                    cin>>rankingVendas;
                    objetoCaminhao.rankingVendas = rankingVendas;

                    objetoCaminhao.setClassificacao(rankingVendas);

                    //Adicionar o objeto caminhao criado ao vetor correspondente no objetoConcessionaria
                    objetoConcessionaria.addCaminhaoNoVetor(objetoCaminhao);
                }
                
                system("pause");
                system("cls");
            }
            else if (opcao == 3)
            {
                int opcao3;
                cout << "---Ver veiculos cadastrados---"<<endl;
                vector <carro> listaCarros;
                vector <caminhao> listaCaminhoes;
                
                cout<<"Escolha a opcao: "<<endl;
                cout<<"1 - Ver carros disponiveis"<<endl;
                cout<<"2 - Ver caminhoes disponiveis"<<endl;
                cout<<"OPCAO: ";
                cin>>opcao3;

                system("cls");

                //Mostrar os vetores do objetoConcessionaria
                if (opcao3 == 1)
                {
                    listaCarros = objetoConcessionaria.getVetorCarros();
                    //Mostrar os objetos do vetor carros em ordem alfabetica
                    cout<<"---Mostrando carros disponiveis---"<<endl<<endl;
                    int tam = listaCarros.size();
                    sort(objetoConcessionaria.carros.begin(),objetoConcessionaria.carros.end(),comparacaoSTR); //Organizador por ordem alfabetica
                    for (int i = 0; i < tam; i++)
                    {
                        cout<<"===== Veiculo de chassi: "<<listaCarros[i].numeroChassi<<" ====="<<endl;
                        cout<<"Ano de fabricacao: "<<listaCarros[i].anoFabricacao<<endl;
                        cout<<"Preco: "<<listaCarros[i].preco<<" RS"<<endl;
                        cout<<"Tipo de veiculo: "<<listaCarros[i].tipoVeiculoCR<<endl;
                        cout<<"Modelo de veiculo: "<<listaCarros[i].modeloVeiculoCR<<endl<<endl;
                    }   
                }
                else if (opcao3 == 2)
                {
                    listaCaminhoes = objetoConcessionaria.getVetorCaminhoes();
                    //Mostrar os objetos do vetor caminhao
                    cout<<"---Mostrando caminhoes disponiveis---"<<endl<<endl;
                    int tam = listaCaminhoes.size();
                    sort(objetoConcessionaria.caminhoes.begin(),objetoConcessionaria.caminhoes.end(),comparacaoINT); //Organizador por ranking de vendas
                    for (int i = 0; i < tam; i++)
                    {
                        cout<<"===== Veiculo de chassi: "<<listaCaminhoes[i].numeroChassi<<" ====="<<endl;
                        cout<<"Ano de fabricacao: "<<listaCaminhoes[i].anoFabricacao<<endl;
                        cout<<"Preco: "<<listaCaminhoes[i].preco<<" RS"<<endl;
                        cout<<"Tipo de veiculo: "<<listaCaminhoes[i].tipoVeiculoCA<<endl;
                        cout<<"Modelo de veiculo: "<<listaCaminhoes[i].modeloVeiculoCA<<endl;
                        cout<<"Capacidade de carga: "<<listaCaminhoes[i].capacidadeCarga<<" ton"<<endl;
                        cout<<"----- ---- ----"<<endl;
                        cout<<"Ranking de vendas: "<<listaCaminhoes[i].rankingVendas<<endl;
                        cout<<"Classificacao de vendas: "<< listaCaminhoes[i].classificacao<<endl<<endl;
                    }
                }
                system("pause");
                system("cls");
            }
 
        } while (opcao != 0);
        
    return 0;
    
}