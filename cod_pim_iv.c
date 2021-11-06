#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structs

typedef struct
{
    char nome[50];
    int idade[3];
    char cpf[20];
    char telefone[20]; 
    char cep[50];
    char endereco[150];
    char data_nascimento[50];
    char email[50];
    char comor[200];
    char data_diag[50];
		int bool_comorb[1];
}paciente;

paciente lista[10];
int tam = 11;
int qt = 0;



//prototipos de função
void login();
int cadastro();
void imprimir();
void salvarArquivoComorb();

//main
int main()
{
    
    login();


    int op;

    do
    {
        printf("\n\n\n2 - Cadastrar\n");
        printf("1 - Imprimir\n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("Programa Encerrado.");
            break;
        case 1:
            imprimir();
            break;
        case 2:
            cadastro();
            break;

        default:
            printf("Opcao Invalida");
            break;
        }
    }while (op != 0);
    
    return 0;
}

    //funcoes
void login(){
		  char username[15]; 
			char password[12]; 
			
			while (1) {
				printf("Nome de usuário:\n"); 
				scanf("%s",&username);

				if(strcmp(username,"medico")!=0){
					printf("Nome de usuário inválido.Por favor, tente novamente:\n");
					continue;
				}
				else{
					break;
				}
			}
    
		while (1) {
			printf("Entre sua senha:\n"); 
      scanf("%s",&password); 

      if(strcmp(password,"1111")!=0){ 
				printf("Senha inválida.Por favor, tente novamente:\n");

					continue;
			}
			else{
				printf("\nWelcome.Login Success!");
				break;
			}
    }
		return;
	}

    int cadastro()
    {
      if(qt < tam)
      {
        system("cls");
        paciente p;
        scanf("%*c");
        printf("\tDigite o Nome do Paciente: \n");
        fflush(stdin);
        fgets(p.nome, 50, stdin);

        fflush(stdin);
        printf("\tDigite a Idade do Paciente: \n");
        fgets(p.idade, 3, stdin);

        fflush(stdin);
        printf("\tDigite o CPF do Paciente: \n");
        fgets(p.cpf, 20, stdin);
        getchar();

        fflush(stdin);
        printf("\tDigite o telefone do Paciente: \n");
        fgets(p.telefone, 20, stdin);
        getchar();

        fflush(stdin);
        printf("\tDigite o CEP: \n");
        fgets(p.cep, 50, stdin);
        getchar();

        fflush(stdin);
        printf("\tDigite o Endereco completo(Rua, Numero, bairro, Cidade e Estado): \n");
        fgets(p.endereco, 150, stdin);
        getchar();
        
        fflush(stdin);
        printf("\tDigite a data de nascimento(xx/xx/xxxx): \n");
        fgets(p.data_nascimento, 30, stdin);
        getchar();

        fflush(stdin);
        printf("\tDigite o Email do Paciente: \n");
        fgets(p.email, 50, stdin);
        getchar();

        fflush(stdin);
        printf("\tO Paciente possui alguma comorbidade?\n1-Sim\n2-Nao\n");
        scanf("%d", p.bool_comorb, 1, stdin);
        getchar();

        if (p.bool_comorb != 0) {
          fflush(stdin);
          printf("\tEscreva Patologias do Paciente(diabetes, obesidade, hipertensão, tuberculose, outros): \n");
          fgets(p.comor, 200, stdin);
        }		
        
        fflush(stdin);
        printf("\tDigite a data do Diagnostico: \n");
        fgets(p.data_diag, 30, stdin);

        if (p.idade > 65 || p.comor == 1) {
          // paciente risco, salvar nos dois arquivos
          FILE *arq = fopen("PacienteRisco.txt", "w");
          int i;
          if(arq)
          {
            for(i = 0; i < qt; i++)
              {
              fprintf(arq, "%s", lista[i].nome);
              fprintf(arq, "%d\n", lista[i].idade);
              fprintf(arq, "%s\n", lista[i].cep);
              }
            fclose(arq);
            }
          
          // paciente normal, salvar apenas em pacientes
          FILE *arq2 = fopen("pacientes.txt", "w");

          if(arq2)
          {
            for(i = 0; i < qt; i++)
              {
              fprintf(arq2, "%s", lista[i].nome);
              fprintf(arq2, "%d\n", lista[i].idade);
              fprintf(arq2, "%s\n", lista[i].cep);
              }
            fclose(arq2);
          }
        }

        lista[qt] = p;
        qt++;
        return 1;
          
      }
      else
      {
        printf("Error");
        return 0;
      }
    }

    void imprimir()
    {
      int i;
      for(i = 0; i < qt; i++)
      {
      printf("Nome: %s", lista[i].nome);
      printf("Idade: %d\n", lista[i].idade);
      printf("CEP: %s\n", lista[i].cep);
      }
    }