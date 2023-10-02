#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Passagem {
private:
    int numeroAssento;
    string dataHora;
    string CPF;
    string nomePassageiro;
    int idadePassageiro;
    double preco;

public:
    Passagem(int numero, string data, string cpf, string nome, int idade, double preco) {
        this->numeroAssento = numero;
        this->dataHora = data;
        this->CPF = cpf;
        this->nomePassageiro = nome;
        this->idadePassageiro = idade;
        this->preco = preco;
    }

    double getPreco() const {
        return preco;
    }

    int getIdade() const {
        return idadePassageiro;
    }

    int getNumeroAssento() const {
        return numeroAssento;
    }

    string getDataHora() const {
        return dataHora;
    }

    string getNomePassageiro() const {
        return nomePassageiro;
    }
};

class Viagem {
private:
    string horario;
    vector<Passagem> passagens;

public:
    Viagem(string horario) {
        this->horario = horario;
    }

    void adicionarPassagem(Passagem passagem) {
        passagens.push_back(passagem);
    }

    double getTotalArrecadado() const {
        double total = 0.0;
        for (const Passagem& passagem : passagens) {
            total += passagem.getPreco();
        }
        return total;
    }

    double getTotalArrecadadoMes(int mes) const {
        double total = 0.0;
        for (const Passagem& passagem : passagens) {
            if (stoi(passagem.getDataHora().substr(5, 2)) == mes) {
                total += passagem.getPreco();
            }
        }
        return total;
    }

    string getNomePassageiroPoltrona(int numeroAssento) const {
        for (const Passagem& passagem : passagens) {
            if (passagem.getNumeroAssento() == numeroAssento) {
                return passagem.getNomePassageiro();
            }
        }
        return "Poltrona não ocupada.";
    }

    string getHorario() const {
        return horario;
    }

    int getQuantidadePassagens() const {
        return passagens.size();
    }

    double getMediaIdade() const {
        int totalIdade = 0;
        for (const Passagem& passagem : passagens) {
            totalIdade += passagem.getIdade();
        }
        return static_cast<double>(totalIdade) / passagens.size();
    }
};

int main() {
    Viagem viagem1("08:00");
    Viagem viagem2("14:00");

    Passagem passagem1(1, "2023-10-01 08:00", "12345678901", "João", 30, 80.0);
    Passagem passagem2(2, "2023-10-01 08:00", "98765432101", "Maria", 25, 80.0);
    Passagem passagem3(3, "2023-10-01 14:00", "11111111111", "Pedro", 40, 80.0);

    viagem1.adicionarPassagem(passagem1);
    viagem1.adicionarPassagem(passagem2);
    viagem2.adicionarPassagem(passagem3);

    // 1. Total arrecadado para a primeira viagem
    cout << "Total arrecadado na viagem 1: R$" << fixed << setprecision(2) << viagem1.getTotalArrecadado() << endl;

    // 2. Total arrecadado no mês 10
    int mes = 10;
    cout << "Total arrecadado no mês " << mes << ": R$" << fixed << setprecision(2) << viagem1.getTotalArrecadadoMes(mes) << endl;

    // 3. Nome do passageiro na poltrona 2 da primeira viagem
    int poltrona = 2;
    cout << "Nome do passageiro na poltrona " << poltrona << " da viagem 1: " << viagem1.getNomePassageiroPoltrona(poltrona) << endl;

    // 4. Horário da viagem mais rentável
    if (viagem1.getTotalArrecadado() > viagem2.getTotalArrecadado()) {
        cout << "A viagem mais rentável foi às " << viagem1.getHorario() << endl;
    } else if (viagem2.getTotalArrecadado() > viagem1.getTotalArrecadado()) {
        cout << "A viagem mais rentável foi às " << viagem2.getHorario() << endl;
    } else {
        cout << "Ambas as viagens tiveram o mesmo lucro." << endl;
    }

    // 5. Média de idade dos passageiros na segunda viagem
    cout << "Média de idade dos passageiros na viagem 2: " << viagem2.getMediaIdade() << " anos" << endl;

    return 0;
}
