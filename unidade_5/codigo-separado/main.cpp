/*
> Discente: Braz Amorim Campos
> Matrícula: 121210160
> Período: 2021.2
> Curso: Engenharia elétrica
> Disciplina: Técnicas de programação
> Turma: 01
> Professor: Marcus Salerno
> Unidade 2: LVP-07
> Compilador utilizado: Visual Studio Code

>   Um vendedor está precisando de um programa para armazenar os seus produtos em uma lista para poder vender aos seus clientes. 
    Para realizar a manipulação dessa lista, ele precisa inserir um produto e sua quantidade na lista. 
    Ele pode também adicionar uma certa quantidade para um determinado produto, vender uma determinada quantidade de um produto 
    (só pode subtrair se tiver essa quantidade no estoque); pesquisar um determinado produto, apresentando a quantidade existente; 
    e exibir os produtos existentes na lista com as respectivas quantidades.
*/
#include <iostream>
#include <string>
using namespace std;
#include "produto.cpp"
#include "vendedor.cpp"

int main (){
    
    int tamanhoLista, opcaoMenu;
    vendedor objetoVendedor(tamanhoLista);
    //Pedir tamanho da lista
    cout << "Insira a quantidade de produtos: ";
    cin >> tamanhoLista;
    objetoVendedor.setTamanhoLista(tamanhoLista);

    //Exibir o menu com os métodos
    do
    {
        cout << "Menu: escolha uma opcao:"<<endl;
        cout << "1 - Cadastrar um novo produto"<<endl;
        cout << "2 - Editar a quantidade de um produto"<<endl;
        cout << "3 - Verificar o estado um produto"<<endl;
        cout << "4 - Exibir os produtos disponiveis"<<endl;
        cout << "Pressione 0 para encerrar o programa." << endl;
        cout << "Opcao: " << endl;
        cin >> opcaoMenu;

        if (opcaoMenu==1)
        {
            string nomeNovoProduto;
            int quantNovoProduto;

            produto novoProduto;

            cout<<"Insira o nome do novo produto: "<< endl;
            cin>>nomeNovoProduto;
            novoProduto.setNomeProduto(nomeNovoProduto);

            cout<<"Insira a quantidade do novo produto: " << endl;
            cin>>quantNovoProduto;
            novoProduto.setQuatProduto(quantNovoProduto);

            objetoVendedor.cadastraProduto(novoProduto);
        }
        else if (opcaoMenu==2)
        {
            int subOpcao2;
            string nomeDoProduto;
            cout<< "1 - Adicionar produtos ao estoque"<<endl;
            cout<< "2 - Remover produtos do estoque"<<endl;
            cin >> subOpcao2;
            cout<<"Insira o nome do produto: ";
            cin>>nomeDoProduto;

            if (subOpcao2==1)
            {
                objetoVendedor.editQuantidade(objetoVendedor,nomeDoProduto,1);
            }
            else
            {
                objetoVendedor.editQuantidade(objetoVendedor,nomeDoProduto,2);
            }

        }
        else if (opcaoMenu==3)
        {
            string nomeDoProduto;
            cout << "Insira o nome do produto: ";
            cin>>nomeDoProduto;
            int quatDeProduto = objetoVendedor.mostraQuantidadeProduto(objetoVendedor,nomeDoProduto);

            cout << "O produto " << nomeDoProduto << " tem " <<quatDeProduto<<" unidades no estoque"<<endl;


        }
        else if (opcaoMenu==4)
        {
            for(int i=0;i<tamanhoLista;i++){
                string nomeProdutdoAtual = objetoVendedor.getNomeProdtLista(i);
                int quatProdutoAtual = objetoVendedor.getQuatProdtLista(i);

                cout << "Produto: " << nomeProdutdoAtual << " Quantidade: " << quatProdutoAtual << endl;
            }
        }
        
        
    } while (opcaoMenu!=0);
    
    return 0;
}