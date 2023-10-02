#include <iostream>
#include <iomanip>
using namespace std;

struct Produto {
    string codigo;
    string nome;
    double preco;
};

Produto produtos[300];
int totalProdutos = 0;

bool inserirProduto() {
    if (totalProdutos >= 300) {
        cout << "Limite de produtos atingido. Não é possível adicionar mais produtos." << endl;
        return false;
    }

    Produto novoProduto;
    cout << "Digite o código do produto (13 caracteres numéricos): ";
    cin >> novoProduto.codigo;

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == novoProduto.codigo) {
            cout << "Produto com o mesmo código já existe. Não é possível adicionar." << endl;
            return false;
        }
    }

    cout << "Digite o nome do produto (até 20 caracteres): ";
    cin.ignore(); // Limpar o buffer do teclado
    getline(cin, novoProduto.nome);

    cout << "Digite o preço do produto (com duas casas decimais): R$";
    cin >> novoProduto.preco;

    produtos[totalProdutos] = novoProduto;
    totalProdutos++;
    cout << "Produto adicionado com sucesso." << endl;
    return true;
}

bool excluirProduto() {
    string codigo;
    cout << "Digite o código do produto que deseja excluir: ";
    cin >> codigo;

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            for (int j = i; j < totalProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            totalProdutos--;
            cout << "Produto excluído com sucesso." << endl;
            return true;
        }
    }

    cout << "Produto não encontrado." << endl;
    return false;
}

void listarProdutos() {
    if (totalProdutos == 0) {
        cout << "Não há produtos cadastrados." << endl;
        return;
    }

    cout << "Lista de Produtos:" << endl;
    for (int i = 0; i < totalProdutos; i++) {
        cout << "Código: " << produtos[i].codigo << " | Nome: " << produtos[i].nome << " | Preço: R$" << fixed << setprecision(2) << produtos[i].preco << endl;
    }
}

void consultarPreco() {
    string codigo;
    cout << "Digite o código do produto que deseja consultar: ";
    cin >> codigo;

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            cout << "O preço do produto " << produtos[i].nome << " é R$" << fixed << setprecision(2) << produtos[i].preco << endl;
            return;
        }
    }

    cout << "Produto não encontrado." << endl;
}

int main() {
    int opcao;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Inserir novo produto" << endl;
        cout << "2. Excluir produto cadastrado" << endl;
        cout << "3. Listar todos os produtos" << endl;
        cout << "4. Consultar preço de um produto" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                inserirProduto();
                break;
            case 2:
                excluirProduto();
                break;
            case 3:
                listarProdutos();
                break;
            case 4:
                consultarPreco();
                break;
            case 0:
                cout << "Saindo do programa. Obrigado!" << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}
