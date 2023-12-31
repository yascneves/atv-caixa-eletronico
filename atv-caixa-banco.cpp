// No trabalho prático, vocês deverão simular as operações realizadas em um caixa eletrônico. Para isso, o sistema deve gerar um saldo, de forma aleatória, para o cliente, e novas operações devem ser ofertadas a ele. Operações como saque, depósito, empréstimo, aplicações em fundo e outras podem ser disponibilizadas. Em uma operação de saque, por exemplo, deve-se solicitar ao cliente o valor de saque, que deve ser subtraído do valor que ele já possui na conta. Deve-se também dar a opção do cliente de finalizar o programa. Ao final, deve ser mostrado o saldo final e uma mensagem de despedida. Deve-se também gerar um relatório contendo as funcionalidades disponíveis no programa.

// O trabalho deve ser realizado em grupos de até 4 pessoas. A apresentação ocorrerá no mesmo dia da entrega e deve durar entre 15 e 20 minutos.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //biblioteca para funcionar o time NULL

// função para mostrar o menu no programa
void mostrarMenu(float saldo)
{
  printf("\n___________________________________________________\n"
         "Olá! Você tem R$%2.f de saldo em sua conta\nEscolha uma operação:\n"
         "1. Saque\n"
         "2. Depósito\n"
         "3. Empréstimo\n"
         "4. Consultar Saldo\n"
         "5. Finalizar\n"
         "Opção:",
         saldo);
}

// função 1.saque
float saque(float saldo)
{
  float valorSaque;
  printf("\nInforme o valor do saque: R$");
  scanf("%f", &valorSaque);

  if (valorSaque > saldo)
  {
    printf("\nSaldo indisponível.\n"
           "Voltando ao inicío\n");
  }
  else
  {
    saldo = saldo - valorSaque;
    printf("\nSaque aprovado.\n"
           "Processando sua solicitação de saque de R$%2.f\n",
           valorSaque);
  }
  return saldo;
}

// função 2.depósito
float deposito(float saldo)
{
  float valorDeposito;
  printf("\nInforme o valor do depósito:\nR$");
  scanf("%f", &valorDeposito);

  if (valorDeposito <= 0)
  {
    printf("\nValor inválido.\n"
           "Retornando ao menu inicial\n");
  }
  else
  {
    saldo = saldo + valorDeposito;
    printf("\nDepósito efetuado. Seu novo saldo é de R$%2.f", saldo);
  }
  return saldo;
}

// função 3.empréstimo
float emprestimo(float saldo)
{
  float valorEmprestimo;
  printf("\nDigite o valor do empréstimo.\nR$");
  scanf("%f", &valorEmprestimo);

  if (valorEmprestimo > 10000)
  {
    printf("\nEmpréstimo Indisponível\n"
           "Voltando ao menu inicial");
  }
  else
  {
    // informando o usuário das condições do empréstimo
    float mensalidade;
    int confirmacao;
    mensalidade = (valorEmprestimo * (1 + 0.05 * 10)) / 10;
    printf("\nSeu empréstimo de R$%2.f será parcelado em 10 vezes.\n"
           "A mensalidade será de R$%2.f",
           valorEmprestimo, mensalidade);
    printf("\nDeseja confirmar o empréstimo?\n"
           "Digite 1 para \"SIM\" e 0 para \"NÃO\"\n");
    scanf("%d", &confirmacao);

    // sem verificação no if porque 1 é true e 0 é false
    if (confirmacao)
    {
      // calculo do saldo final com o empréstimo
      saldo = saldo + valorEmprestimo;
      printf("\nOperação realizada com sucesso.\n"
             "Seu novo saldo é de R$%2.f",
             saldo);
    }
    else
    {
      printf("\nOperação Cancelada!\n"
             "Voltando ao menu inicial");
    }
  }
  return saldo;
}

// função 4.consultar saldo
float consultarSaldo(float saldo)
{
  printf("\nSeu saldo é de R$%2.f\n", saldo);
  return saldo;
}

int main()
{
  srand(time(NULL)); // time(NULL) return the number (after conversion) of seconds since about midnight 1970-01-01. That number changes every second, so using that number to "select a book" pretty much guarantees a new sequence of "random" numbers every time your program runs.
  float saldo = rand();
  int operacao = 0;

  while (operacao != 5) // vai repetir enquanto for diferente de 5
  {
    mostrarMenu(saldo);
    scanf("%d", &operacao);

    if (operacao == 1)
    {
      saldo = saque(saldo);
    }
    else if (operacao == 2)
    {
      saldo = deposito(saldo);
    }
    else if (operacao == 3)
    {
      saldo = emprestimo(saldo);
    }
    else if (operacao == 4)
    {
      saldo = consultarSaldo(saldo);
    }
    else if (operacao == 5)
    {
      break;
    }
    else
    {
      printf("\nOpção inválida. Retornando ao menu inicial...\n");
    }
  }
  printf("\nSeu saldo final é de:\n"
         "\nR$%2.f\n"
         "\nEstamos finalizando as operações.\n"
         "O BANCO agradece sua preferência!\n"
         "Tenha um ótimo dia.\n",
         saldo);
  return 0;
}
