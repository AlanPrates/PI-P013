#include <iostream>
using namespace std;

// Definindo a struct Empregado
struct Empregado {
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    double salario;
};

// Função para reajustar salários em 10%
void Reajusta_dez_porcento(Empregado empregados[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        empregados[i].salario *= 1.1; // Aumento de 10%
    }
}

int main() {
    // Criando um vetor de empregados com capacidade para 50 elementos
    Empregado empregados[50];

    // Adicionando alguns empregados para teste
    empregados[0] = {"Joao", "Silva", 1985, "1234567", 2010, 3000.0};
    empregados[1] = {"Maria", "Oliveira", 1990, "7654321", 2015, 2500.0};

    // Chamando a função para reajustar os salários
    Reajusta_dez_porcento(empregados, 2); // 2 é a quantidade de empregados no vetor

    // Exibindo os salários após o reajuste
    for (int i = 0; i < 2; i++) {
        cout << empregados[i].nome << " " << empregados[i].sobrenome << " - Salário: " << empregados[i].salario << endl;
    }

    return 0;
}
