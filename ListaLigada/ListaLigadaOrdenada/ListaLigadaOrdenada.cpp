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
	// se a lista já possuir elementos
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
	
	NO* novo = (NO*)malloc(sizeof(NO)); //aloca memoria
	if (novo == NULL){ //se caso dê erro
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	
	if (primeiro == NULL) //se caso não tiver nada
	{
		primeiro = novo;
		return;
	}


	NO* aux = primeiro;
	anterior = NULL;

	
	while (aux != NULL && aux->valor < novo->valor) //percorre a lista para achar as posições corretas para fazer a inserção
	{
		anterior = aux;
		aux = aux->prox;
	}

	
	if (aux != NULL && aux->valor == novo->valor) //verificar se num já existe
	{
		cout << "O numero informado ja existe!\n";
		free(novo);
		return;
	}

	
	if (anterior == NULL) //se o valor novo for menor que o primeiro
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

	cout << "Informe o numero para excluir \n";
	cin >> numExcluir;

	NO* aux = primeiro;

	while (aux != NULL && aux->valor < numExcluir) {
		anterior = aux;
		aux = aux->prox;
	}

	if (aux != NULL && aux->valor != numExcluir)  {
		cout << "Numero nao encontrado! \n";
		return;
	}

	else if (aux == NULL) {
		cout << "Numero nao encontrado! \n";
		return;
	}
	else {

	

	if (anterior == NULL) //se o num for o primeiro
	{
		primeiro = aux->prox;
		free(aux);
		cout << "Numero excluido com sucesso! \n";
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
	anterior = NULL; //Prestar + atenção nisso aqui, errei muito

	int num;
	cout << "Informe o numero a ser buscado: \n";
	cin >> num;

	while (aux != NULL) {
		if (aux->valor == num) {
			cout << "Numero encontrado! \n";
			return;
		}

		else if (aux->valor > num) {
			cout << "Numero nao encontrado! \n";
			return;
		}
		aux = aux->prox;
	}

	cout << "Numero nao encontrado! \n";

}


