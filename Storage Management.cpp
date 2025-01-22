#include <iostream>
#include <locale.h>
#include <unistd.h>
#include <iomanip>
using namespace std;

#define MAXIMO_PRODUTOS 100
#define MAXIMO_POR_PRODUTO 500

typedef struct {
	string nome;//Capacete;
	string ID;//32;
	int quantidade;//3;
	int minimo;//43
	float valor;//32,56;
} item;
//Prototipos de funções
void menu();
void registrar();
void consultar();
void atualizar();
void remover();
void relatorio();
void mostrar_dados(int i);
void reformular(int Y);
////////////////////////
int produtos_registrados = 0;
item ITENS[MAXIMO_PRODUTOS];//ARRAY GLOBAL;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	menu();

	return 0;
}

void menu() {
	cout << "\n  **STORAGE SYSTEM**" << endl;
	cout << "   ESCOLHA UMA OPÇÃO:" << endl;
	cout << "   1 - Registrar\n";
	cout << "   2 - Consultar\n";
	cout << "   3 - Atualizar\n";
	cout << "   4 - Remover\n";
	cout << "   5 - Relatorio\n";
	cout << "   6 - SAIR\n";
	int escolha;
	cin >> escolha;
	switch(escolha) {
	case 1:
		registrar();
		menu();
		break;

	case 2:
		consultar();
		menu();
		break;

	case 3:
		atualizar();
		menu();
		break;

	case 4:
		remover();
		menu();
		break;
    
    case 5:
        relatorio();
        menu();
        break;
    
	case 6:
		cout << " OBRIGADO POR VIR!!!\n";
		sleep(2);
		cout << " Tenha um bom dia!!!";
		fflush(stdout);
		sleep(1);
		break;

	default:
		cout << " OPÇÃO INVALIDA!!!\n";
		sleep(2);
		menu();
	}
}

void registrar() {
	if(produtos_registrados < MAXIMO_PRODUTOS) {
	    getchar();
		cout << " Digite o nome do produto a ser resgistrado\n";
		getline(cin,ITENS[produtos_registrados].nome);
		cout << " Digite o ID do produto\n";
		cin >> ITENS[produtos_registrados].ID;
		for(int i=0; i<produtos_registrados; i++){
		    if(ITENS[produtos_registrados].ID == ITENS[i].ID){
		        cout << " ID já utilizado em outro produto\n Digite outra!!\n";
		        cin >> ITENS[produtos_registrados].ID;
		        continue;
		    }
		}
		cout << " Digite a quantidade em estoque do produto\n";
		cin >> ITENS[produtos_registrados].quantidade;
		cout << " Qual a quantidade minima que este produto devera ter em estoque?\n";
		cin >> ITENS[produtos_registrados].minimo;
		cout << " Digite o valor do produto\n";
		cin >> ITENS[produtos_registrados].valor;
		cout << " PRODUTO REGISTRADO COM SUCESSO!!\n";
		sleep(2);
		produtos_registrados++;
	}
	else {
		cout << " LIMITE DE PRODUTOS ATINGIDO!!!\n Exclua um para poder prosseguir!!\n";
		sleep(2);
	}
}

void mostrar_dados(int i) {
	cout << " NOME: " << ITENS[i].nome << endl;
	cout << " ID: " << ITENS[i].ID << endl;
	cout << " QUANTIDADE: " << ITENS[i].quantidade << endl;
	cout << " PREÇO: " << fixed << setprecision(2) << ITENS[i].valor << endl;
	cout << "\n";
	sleep(2);
}

void consultar() {
    if(produtos_registrados == 0){
        cout << " Registre um produto antes de realizar esta ação\n";
        sleep(2);
        return;
    }
    else{
	int escolha;
	cout << " Gostaria de consultar por 1-ID, 2-NOME ou 3-LISTAR TODOS\n case contrario, digite 4 para voltar ao menu\n";
	cin >> escolha;
	bool R = true;
	string IDE;
	switch(escolha) {
	case 1:
		cout << " Digite a ID do produto que esta procurando\n";
		cin >> IDE;
		for(int i=0; i<produtos_registrados; i++) {
			if(IDE == ITENS[i].ID) {
				mostrar_dados(i);
				R = false;
			}
		}
		if(R) {
			cout << " ID do produto não encontrado ou inexistente!!\n";
			sleep(2);
		}
		break;
	
	case 2:
		cout << " Digite o nome do produto que esta procurando\n";
		cin >> IDE;
		for(int i=0; i<produtos_registrados; i++) {
			if(IDE == ITENS[i].nome) {
				mostrar_dados(i);
				R = false;
			}
		}
		if(R) {
			cout << " Produto não encontrado ou inexistente!!\n";
			sleep(2);
		}
		break;

	case 3:
		cout << " Produtos registrados!\n";
		for(int i=0; i<produtos_registrados; i++) {
			mostrar_dados(i);
		}
		break;
		
    case 4:
        menu();
    break;
    
	default:
		cout << " Opção invalida!!!\n";
		sleep(2);
		consultar();
	}
    }
}

void atualizar() {
    if(produtos_registrados == 0){
        cout << " Registre um produto antes de realizar esta ação\n";
        sleep(2);
        return;
    }
    else{
	string atualizar;
	cout << " Digite o ID do produto que deseja alterar! ou digite SAIR para voltar ao menu\n";
	cin >> atualizar;
	if(atualizar == "SAIR"){
	    return;
	}
	bool P=true;
	for(int i=0; i<produtos_registrados; i++) {
		if(atualizar == ITENS[i].ID) {
			P=false;
			cout << " Digite o que gostaria de alterar (NOME, VALOR, QUANTIDADE ou MINIMO)\n";
			string acao;
			cin >> acao;
			if(acao == "NOME" || acao == "Nome" || acao == "nome"){
			    cout << " Digite o novo nome do produto!!\n";
			    cin >> ITENS[i].nome;
			    cout << " Nome alterado com sucesso!!\n";
			    break;
			}
			else if(acao == "QUANTIDADE" || acao == "Quantidade" || acao == "quantidade"){
			    cout << " Digite a nova quantidade em estoque do produto!!\n";
			    cin >> ITENS[i].quantidade;
			    cout << " Quantidade alterada com sucesso!!\n";
			    break;
			}
			else if(acao == "VALOR" || acao == "Valor" || acao == "valor"){
			    cout << " Digite o novo valor unitario do produto selecionado!!\n";
			    cin >> ITENS[i].valor;
			    cout << " Valor unitario alterado com sucesso!!\n";
			    break;
			}
			else if(acao == "MINIMO" || acao == "Minimo" || acao == "minimo"){
			    cout << " Digite o novo valor minimo em quantidade para este produto!!\n";
			    cin >> ITENS[i].minimo;
			    cout << " Valor minimo atualizado!!\n";
			    break;
			}
			else{
			    cout << " Algo deu errado, tente novamente!!\n";
			    sleep(2);
			    break;
			}
		}
	}
	if(P){
	    cout << " Produto não encontrado\n";
	    sleep(2);
	}
    }
}

void remover(){
    if(produtos_registrados == 0){
        cout << " Registre um produto antes de realizar esta ação\n";
        sleep(2);
        return;
    }
    else{
    string REMOVER;
    cout << " Digite o ID do produto que deseja remover!\n Ou digite SAIR para voltar ao menu\n";
    cin >> REMOVER;
    if(REMOVER == "SAIR"){
        menu();
    }
    else{
    bool ACHEI = true;
    for(int i=0; i<produtos_registrados; i++){
        if(REMOVER == ITENS[i].ID){
            reformular(i);
            ACHEI = false;
            continue;
        }
    }
    if(ACHEI){
        cout << " Produto não encontrado, tente novamente!!\n";
        sleep(2);
        remover();
    }
    }
    }
    cout << " Produto removido com sucesso\n";
    produtos_registrados--;
    sleep(2);
}

void reformular(int Y){
    for(int i=Y; i<produtos_registrados; i++){
        if(i == produtos_registrados-1){
            continue;
        }
        else{
            ITENS[i] = ITENS[i+1];
        }
    }
}

void relatorio(){
    if(produtos_registrados == 0){
        cout << " Registre um produto antes de realizar esta ação\n";
        sleep(2);
        return;
    }
    else{
    string NOMES_ZERADOS[1000],NOMES_MINIMADOS[1000];
    int ZERUS = 0, MINIMOS = 0;
    bool ZERADO = false, MINIMADO = false;
    int ZERO=0, MINIMO=0;
    for(int i=0; i<produtos_registrados; i++){
        if(ITENS[i].quantidade == 0){
            ZERADO = true;
            NOMES_ZERADOS[ZERUS] = ITENS[i].nome;
            ZERO++;
            ZERUS++;
        }
        if(ITENS[i].quantidade < ITENS[i].minimo){
            MINIMADO = true;
            NOMES_MINIMADOS[MINIMOS] = ITENS[i].nome;
            MINIMO++;
            MINIMOS++;
        }
    }
    if(ZERADO){
        cout << " Há um total de " << ZERO << " produtos zerados em estoque!!\n SENDO ELES:\n";
        for(int i=0; i<ZERUS; i++){
            cout << " " << NOMES_ZERADOS[i] << endl;
            sleep(1);
        }
        cout << "\n";
    }
    else{
        cout << " Nenhum produto está zerado no estoque!!\n";
        sleep(2);
    }
    if(MINIMADO){
        cout << " Há um total de " << MINIMO << " produtos abaixo da quantidade minima em estoque!!\n SENDO ELES:\n";
        for(int i=0; i<MINIMOS; i++){
            cout << " " << NOMES_MINIMADOS[i] << endl;
            sleep(1);
        }
    }
    else{
        cout << " Nenhum produto está abaixo do minimo no estoque!!\n";
        sleep(2);
    }
    }
}
