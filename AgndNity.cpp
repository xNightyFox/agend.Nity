#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <sstream>
#include <thread>


//   [Variaveis Globais]

std::string nome, Tel, email, end,search_cpf , cpf;
int tam = 0; // numero inicial de contatos = 0
int i;       // indice do vetor


//   [Classe]

class Contato {

public:
  // Classse contato precisa armazenar as informacoes
  // Atributos da Classe:
  std::string nome;
  std::string Tel;
  std::string email;
  std::string end;
  std::string search_cpf;
  std:: string cpf;
  // Contato vai armazenar os atributos das classe no vetor
  Contato() {}
  Contato(std::string nome, std::string Tel, std::string email,std::string end, std::string cpf) // Declarando Constructo

  {
    // Definindo Constructo

    // Atribuindo valores aos atributos:

    this->nome = nome;
    this->Tel = Tel;
    this->email = email;
    this->end = end;
    this->cpf = cpf;
  }

  ~Contato() {} // Destructo

private:
};
std::vector<Contato> vetor;


//Função (1)  [Adcionar Contato]   OK!

void Adc_cont() {


      std::cout << "\n\n(1)\t\t\t[Adcionar contatos]\n";

      std::cout << "\nDigite o nome:\n";
      std::cin.ignore();
      std::getline(std::cin, nome);

      std::cout << "\nDigite o Telefone/celular:\n";
      std::getline(std::cin, Tel);

      std::cout << "\nDigite o e-mail:\n";
      std::getline(std::cin, email);

      std::cout << "\nDigite o CPF:\n";
      std::getline(std::cin,cpf);
      //std::cout << "\nDigite o Endereço:\n";
      //std::getline(std::cin, end);

      //for (i = 0; i < 10; i++) // For para guardar um conjunto de informacoes
       {

          vetor.push_back ( Contato(nome, Tel, email, end,cpf));
      i++;
        }



}



//Função (4)  [Consultar Contato]  OK!

void C_contato() {

    std::cout << "\n\n(4)\t\t\t[Colsultar Contato]\n";

    std::cout << "\nDigite o cpf:\n";
    std::cin.ignore();
    std::getline(std::cin, search_cpf);
    //std::cout << "\n\n\t\t\tProcurando cpf digitado...";

    sleep(3);




    for (i = 0; i < 10; i++)//Procurando cpf digitado...
      {

        //Obs.:Procurar o conteudo do vetor todo, nao apenas da variavel "cpf"
        if(search_cpf == vetor[i].cpf)
        {

          std::cout << "\n\t\t\t !CPF verificado!\n\n";
          sleep(3);

          std:: cout << "NOME:\t\t" << vetor[i].nome <<  "\n";
          std:: cout << "TELEFONE:\t"<< vetor[i].Tel <<  "\n";
          std:: cout << "E-MAIL:\t\t"<< vetor[i].email <<  "\n";
          std:: cout << "CPF:\t\t"<< vetor[i].cpf <<  "\n\n";
          sleep(5);


      break;

        }
      }


}



//Função (2)  [Remover contato]    OK!

void Rem_cont() {

  std::cout << "\n\n(2)\t\t\t[Remover contato]\n";

  std::cout << "\nDigite o cpf:\n";
  std::cin.ignore();
  std::getline(std::cin, search_cpf);

  //int indice_rem = -1;

  for (i = 0; i < 10; i++)//Procurando cpf digitado...
    {
      //Obs.:Procurar o conteudo do vetor todo, nao apenas da variavel "cpf"
      if(search_cpf == vetor[i].cpf)
      {
        //indice_rem = i;
        std::cout << "\n\t\t\t!CPF verificado!\n";

        std:: cout << "NOME:\t\t" << vetor[i].nome <<  "\n";
        std:: cout << "TELEFONE:\t"<< vetor[i].Tel <<  "\n";
        std:: cout << "E-MAIL:\t\t"<< vetor[i].email <<  "\n";
        std:: cout << "CPF:\t\t"<< vetor[i].cpf <<  "\n\n";

        for (std::vector<Contato>::iterator it = vetor.begin(); it != vetor.end(); ) {
        if (search_cpf == vetor[i].cpf) {
            it = vetor.erase(it);
            sleep(3);
            std::cout << "\n\t\t\t!Contato Removido!\n";
            sleep(5);
        } else {
            ++it;
        }}

    break;

      }
    }

}


//Função (3)  [Editar contato]     OK!

void Ed_contato() {
    std::cout << "\n\n(2)\t\t\t[Editar Contato]\n";

    std::cout << "\nDigite o cpf:\n";
    std::cin.ignore();
    std::getline(std::cin, search_cpf);

    //int indice_rem = -1;

    for (i = 0; i < 10; i++)//Procurando cpf digitado...
      {
        //Obs.:Procurar o conteudo do vetor todo, nao apenas da variavel "cpf"
        if(search_cpf == vetor[i].cpf)
        {

          std::cout << "\n\t\t\t!CPF verificado!\n";

          std:: cout << "NOME = " << vetor[i].nome <<  "\n";

          std::cout << "\nDigite o Telefone/celular:\n";
          std::getline(std::cin , vetor[i].Tel);

          std::cout << "\nDigite o e-mail:\n";
          std::getline(std::cin, vetor[i].email);

          std::cout << "\nDigite o CPF:\n";
          std::getline(std::cin,vetor[i].cpf);

      break;

        }
      }

  }



//Função (5)  [Mostrar Lista]      OK!
void mostrarLista(){
    std::cout << "\n\n(1)\t\t\t[Lista de contatos]\n\n";
  for (i = 0; i < vetor.size(); i++) // For mostrar dados do vetor
    {
      std:: cout << "NOME:\t\t" << vetor[i].nome <<  "\n";
      std:: cout << "TELEFONE:\t"<< vetor[i].Tel <<  "\n";
      std:: cout << "E-MAIL:\t\t"<< vetor[i].email <<  "\n";
      std:: cout << "CPF:\t\t"<< vetor[i].cpf <<  "\n\n";


      }
  sleep(5);
}



int main() {

  //int n_contatos = 0;

  //--------------------[MENU]---------------------------

  // void menu()//funcao menu

  int opc = 0;
  while (opc != 9) {
    std::cout << "\n\n\t\t\t[MENU]\n\nSelecione uma das opções abaixo:\n";

    std::cout << "\n(1) Adcionar contatos\n";
    std::cout << "\n(2) Remover contato\n";
    std::cout << "\n(3) Editar Contato\n";
    std::cout << "\n(4) Consultar contato\n";
    std::cout << "\n(5) Mostrar lista de contatos \n"; // TESTAR!
    std::cout << "\n(9) SAIR \n";

    std::cout << "\nDigite a opção: ";

    std::cin >> opc;

    if (opc != 9) {
      switch (opc) {
      case 1:
        Adc_cont();

        break;

      case 2: Rem_cont();
      break;

      case 3: Ed_contato();
      break;

      case 4:
        C_contato();
        break;

      case 5:
        mostrarLista();
      break;

      default:
        std::cout << "\n\t\t\t!OPÇÃO INVALIDA! \n";
        sleep(2);
      }

    } else {
      std::cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\tEncerrando...\n\n\n\n\n\n\n\n\n";
    }
  }
}
