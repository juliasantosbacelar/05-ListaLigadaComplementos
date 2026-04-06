#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* anterior = NULL;
// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* anterior;
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL) 
	{
		primeiro = novo;
		return;
	}


	
	NO* novo = (NO*)malloc(sizeof(NO)); 
	if (novo == NULL){ 
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	
	if (primeiro == NULL) 
	{
		primeiro = novo;
		return;
	}


	NO* aux = primeiro;
	anterior = NULL;

	
	while (aux != NULL && aux->valor < novo->valor) 
	{
		anterior = aux;
		aux = aux->prox;
	}

	
	if (aux != NULL && aux->valor == novo->valor) 
	{
		cout << "O numero informado existe!\n";
		free(novo);
		return;
	}

	
	if (anterior == NULL) 
	{
		novo->prox = primeiro;
		primeiro = novo;
	}
	
	else
	{
		anterior->prox = novo;
		novo->prox = aux;
	}
}

void excluirElemento()
{
	int numExcluir;

	anterior = NULL;

	cout << "Digite o numero que quer excluir \n";
	cin >> numExcluir;

	NO* aux = primeiro;

	while (aux != NULL && aux->valor < numExcluir) {
		anterior = aux;
		aux = aux->prox;
	}

	if (aux != NULL && aux->valor != numExcluir)  {
		cout << "O numero foi encontrado! \n";
		return;
	}

	else if (aux == NULL) {
		cout << "O numero nao foi encontrado! \n";
		return;
	}
	else {

	

	if (anterior == NULL) //se o num for o primeiro
	{
		primeiro = aux->prox;
		free(aux);
		cout << "O numero foi excluido com sucesso! \n";
		return;
	}

	else
	{
		anterior->prox = aux->prox;
		free(aux);
	}
	}
}

void buscarElemento()
{
	NO* aux = primeiro;
	anterior = NULL; 

	int num;
	cout << "Informe o numero a ser buscado: \n";
	cin >> num;

	while (aux != NULL) {
		if (aux->valor == num) {
			cout << "O numero foi encontrado! \n";
			return;
		}

		else if (aux->valor > num) {
			cout << "O numero nao foi encontrado! \n";
			return;
		}
		aux = aux->prox;
	}

	cout << "Numero nao foi encontrado! \n";
}


