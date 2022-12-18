#include "concessionaria.h"
void concessionaria::addCarroNoVetor(carro objetoCarro){
    int condicaoExistencia = testaExisteCarro(objetoCarro.numeroChassi);
    if (condicaoExistencia == 0)
    {
        carros.push_back(objetoCarro);
        cout<<"Veiculo cadastrado com sucesso!"<<endl;
    }
    else if (condicaoExistencia > 0)
    {
        cout<<"Esse chassi ja esta cadastrado no sistema"<<endl;
    }
}

void concessionaria::addCaminhaoNoVetor(caminhao objetoCaminhao){
    int condicaoExistencia = testaExisteCaminhao(objetoCaminhao.numeroChassi);
    if (condicaoExistencia == 0)
    {
        caminhoes.push_back(objetoCaminhao);
        cout<<"Veiculo cadastrado com sucesso!"<<endl;
    }
    else if (condicaoExistencia > 0)
    {
        cout<<"Esse chassi ja esta cadastrado no sistema"<<endl;
    }
}

void concessionaria::removerCarroDoVetor(int numeroChassi){
    int tam = carros.size();
    if (tam == 0)
    {
        cout<<"Nao existem carros cadastrados no sistema"<<endl;
    }
    else if (tam > 0)
    {
        int soma=0;
        for (int i = 0; i < tam; i++)
        {
            int chassiAtual = carros[i].numeroChassi;
            
            if (chassiAtual == numeroChassi)
            {
                carros.erase(carros.begin()+i);
                cout<<"Carro vendido com sucesso"<<endl;
            }
            else if (chassiAtual != numeroChassi)
            {
                soma++;
            }
        }
        if (soma==tam)
        {
            cout<<"Nao existe carro com esse chassi no sistema"<<endl;
        }
    }
}

void concessionaria::removerCaminhaoDoVetor(int numeroChassi){
    int tam = caminhoes.size();
    if (tam == 0)
    {
        cout<<"Nao existem caminhoes cadastrados no sistema"<<endl;
    }
    else if (tam > 0)
    {
        int soma = 0;
        for (int i = 0; i < tam; i++)
        {
            int chassiAtual = caminhoes[i].numeroChassi;
            if (chassiAtual == numeroChassi)
            {
                caminhoes.erase(caminhoes.begin()+i);
                cout<<"Caminhao vendido com sucesso"<<endl;
            }
            else if (chassiAtual != numeroChassi)
            {
                soma++;
            }
        }
        if (soma == tam)
        {
            cout<<"Nao existe caminhao com esse chassi no sistema"<<endl;  
        }
    }   
}

vector<carro> concessionaria::getVetorCarros(){
    return carros;
}

vector<caminhao> concessionaria::getVetorCaminhoes(){
    return caminhoes;
}

bool comparacaoSTR(carro objetoCarro1, carro objetoCarro2){
    return objetoCarro1.getModelo() < objetoCarro2.getModelo();
}

bool comparacaoINT(caminhao objetoCaminhao1, caminhao objetoCaminhao2){
    return objetoCaminhao1.getRankingVenda() < objetoCaminhao2.getRankingVenda();
}


int concessionaria::testaExisteCarro(int numeroChassi){
    vector <carro> listaCarros = getVetorCarros();
    int testador = 0;
    int tam = listaCarros.size();
    for (int i = 0; i < tam; i++)
    {
        if (numeroChassi == listaCarros[i].numeroChassi)
        {
            testador++;
        }
            
    }
    return testador;
}
int concessionaria::testaExisteCaminhao(int numeroChassi){
    vector <caminhao> listaCaminhoes = getVetorCaminhoes();
    int testador = 0;
    int tam = listaCaminhoes.size();
    for (int i = 0; i < tam; i++)
    {
        if (numeroChassi == listaCaminhoes[i].numeroChassi)
        {
            testador++;
        }
            
    }
    return testador;
}

concessionaria::concessionaria(){ //Construtor que cria o arquivo e armazena os dados
    ifstream arquivoCarro; //cria o arquivo
	arquivoCarro.open("listaCarros.txt"); //abre o  arquivo
    int anoFabricacao, numeroChassi, preco;
    string tipoVeiculoCR, modeloVeiculoCR;

    if(arquivoCarro.is_open()){
		while(!arquivoCarro.eof()){

            arquivoCarro>>anoFabricacao;
            arquivoCarro>>numeroChassi;
            arquivoCarro>>preco;
            arquivoCarro.ignore();
            getline(arquivoCarro,modeloVeiculoCR);
            getline(arquivoCarro,tipoVeiculoCR);
            carro liaux(tipoVeiculoCR, modeloVeiculoCR, anoFabricacao, numeroChassi, preco); //cria um objeto livro com os dados lidos no arquivo
            carros.push_back(liaux);  //insere o objeto livro na lista
        }
        carros.pop_back();
		arquivoCarro.close(); //fecha o arquivo
    }
    else{
	    cout<<"Nao foi possivel abrir o arquivo"<<endl;
	}
    //======================================//======================================//
    ifstream arquivoCaminhao; //cria o arquivo
	arquivoCaminhao.open("listaCaminhoes.txt"); //abre o  arquivo
    int anoFabricacao2, numeroChassi2, preco2, capacidadeCarga, rankingVendas;
    string tipoVeiculoCA, modeloVeiculoCA, classificacao;

    if(arquivoCaminhao.is_open()){
		while(!arquivoCaminhao.eof()){
            arquivoCaminhao>>anoFabricacao2;
            arquivoCaminhao>>numeroChassi2;
            arquivoCaminhao>>preco2;
            arquivoCaminhao>>capacidadeCarga;
            arquivoCaminhao>>rankingVendas;
            arquivoCaminhao.ignore();
            getline(arquivoCaminhao,classificacao);
            getline(arquivoCaminhao,modeloVeiculoCA);
            getline(arquivoCaminhao,tipoVeiculoCA);
            caminhao liaux2(tipoVeiculoCA, modeloVeiculoCA, classificacao, anoFabricacao2, numeroChassi2, preco2, capacidadeCarga, rankingVendas); //cria um objeto livro com os dados lidos no arquivo
            caminhoes.push_back(liaux2);  //insere o objeto livro na lista
        }
        caminhoes.pop_back();
		arquivoCaminhao.close(); //fecha o arquivo
    }
    else{
	    cout<<"Nao foi possivel abrir o arquivo"<<endl;
	}

}

concessionaria::~concessionaria(){ //Destrutor abre o arquivo e armazena os dados
    ofstream arquivoCarros; //arquivo de escrita
	arquivoCarros.open("listaCarros.txt",ios::trunc); // abre arquivo
	
	if (arquivoCarros.is_open()){
		for (unsigned i=0;i<carros.size();i++){
			arquivoCarros<<carros[i].getAnoFabricacao()<<endl;
			arquivoCarros<<carros[i].getNumeroChassi()<<endl;
			arquivoCarros<<carros[i].getPreco()<<endl;
			arquivoCarros<<carros[i].getModelo()<<endl;
            arquivoCarros<<carros[i].getTipo()<<endl;	
            
		}

		arquivoCarros.close(); //fecha arquivo
	}else{
		cout<<"Nao foi possivel gravar no arquivo"<<endl;
	}
    //======================================//======================================//
    ofstream arquivoCaminhao; //arquivo de escrita
	arquivoCaminhao.open("listaCaminhoes.txt",ios::trunc); // abre arquivo
	
	if (arquivoCaminhao.is_open()){
		for (unsigned i=0;i<caminhoes.size();i++){
			arquivoCaminhao<<caminhoes[i].getAnoFabricacao()<<endl;
			arquivoCaminhao<<caminhoes[i].getNumeroChassi()<<endl;
			arquivoCaminhao<<caminhoes[i].getPreco()<<endl;
            arquivoCaminhao<<caminhoes[i].getModeloVeiculoCA()<<endl;
            arquivoCaminhao<<caminhoes[i].getTipoVeiculoCA()<<endl;
            arquivoCaminhao<<caminhoes[i].getCapacidadeCarga()<<endl;
            arquivoCaminhao<<caminhoes[i].getClassificacao()<<endl;
            arquivoCaminhao<<caminhoes[i].getRankingVenda()<<endl;
			
		}

		arquivoCaminhao.close(); //fecha arquivo
	}else{
		cout<<"Nao foi possivel gravar no arquivo"<<endl;
	}
}