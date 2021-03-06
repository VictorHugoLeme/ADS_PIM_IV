#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//structs

typedef struct
{
    char nome[50];
    int idade[50];
    int cpf[50];
    char telefone[50]; 
    char cep[50];
    char endereco[150];
    char data_nascimento[50];
    char email[50];
    char comor[200];
    char data_diag[50];
}paciente;

paciente lista[10];
int tam = 10;
int qt = 0;



//prototipos de função
void login();
int cadastro();
void imprimir();
void salvarArquivo();




//main
int main()
{
    
    login();


    int op;

    do
    {
        printf("\n\n\n3 - Cadastrar\n");
        printf("2 - Salvar em Arquivo\n");
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
            salvarArquivo();
            break;
        case 3:
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
			printf("Nome de usuario:\n"); 
			scanf("%s",&username);

			if(strcmp(username,"medico")!=0){
				printf("Nome de usuario invalido.Por favor, tente novamente:\n");
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
				printf("Senha invalida.Por favor, tente novamente:\n");

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
            printf("\t\tDigite o Nome do Paciente: \n");
            fflush(stdin);
            fgets(p.nome, 50, stdin);

            fflush(stdin);
            printf("\t\tDigite a Idade do Paciente: \n");
            scanf("%d", p.idade);

            fflush(stdin);
            printf("\t\tDigite o CPF do Paciente: \n");
            fgets(p.cpf, 20, stdin);

            fflush(stdin);
            printf("\t\tDigite o telefone do Paciente: \n");
            fgets(p.telefone, 20, stdin);

            fflush(stdin);
            printf("\t\tDigite o CEP: \n");
            fgets(p.cep, 50, stdin);

            fflush(stdin);
            printf("\t\tDigite o Endereco completo(Rua, Numero, bairro, Cidade e Estado): \n");
            fgets(p.endereco, 150, stdin);
            
            fflush(stdin);
            printf("\t\tDigite a data de nascimento(xx/xx/xxxx): \n");
            fgets(p.data_nascimento, 30, stdin);

            printf("\t\tDigite o Email do Pacinte: \n");
            fgets(p.email, 50, stdin);

            printf("\t\tEscreva Patologias do Paciente(diabetes, obesidade, hipertensao, tuberculose, outros): \n");
            fgets(p.comor, 200, stdin);

            printf("\t\tDigite a data do Diagnostico: \n");
            fgets(p.data_diag, 30, stdin);

            


            lista[qt] = p;
            qt++;
            return 1;
            
        }else{
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



    void salvarArquivo()
    {
        FILE *arq = fopen("paciente.txt", "w");
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
        else
        printf("error.");
    }