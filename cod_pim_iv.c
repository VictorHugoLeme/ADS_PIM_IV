#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

//structs

typedef struct
{
    char nome[50];
    char idade[50];
    char cpf[50];
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
int risco = 65;



//prototipos de função
void login();
int cadastro();
void imprimir();
void salvarArquivo();
void salvarArquivogrisco();




//main
int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    login();

    int op2;
    int op;

    do
    {
        printf("\n\n\n3 - Cadastrar\n");
        printf("2 - Salvar em Arquivos\n");
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
                do
                {
                    printf("\n2 - Salvar em Arquivos Comuns\n");
                    printf("1 - Salvar em grupo de risco\n");
                    printf("0 - Voltar ao Menu\n");
                    scanf("%d", &op2);


                    switch (op2)
                    {
                    case 1:
                        salvarArquivogrisco();
                        break;
                    case 2:
                        salvarArquivo();
                        break;
                    case 0:
                        printf("Programa encerrado");
                        break;
                    default:
                        printf("Opcao Invalida");
                        break;
                    }
                } while (op2 != 0);
           
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
    void login()
    {
        char username[15]; 
        char password[12]; 
    
    
        printf("Enter your username:\n"); 
        scanf("%s",&username); 
    
        printf("Enter your password:\n"); 
        scanf("%s",&password); 
    
        if(strcmp(username,"medico")==0){ 
            if(strcmp(password,"1111")==0){ 
    
            printf("\nWelcome.Login Success!"); 
    
    
            }else{ 
        printf("\nwrong password"); 
    } 
        }else{ 
        printf("\nUser doesn't exist"); 
    } 
        return 0;
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
            fgets(p.idade, 50, stdin);

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

            printf("\t\tEscreva Patologias do Paciente(diabetes, obesidade, hipertensão, tuberculose, outros): \n");
            fgets(p.comor, 200, stdin);

            printf("\t\tDigite a data do Diagnostico: \n");
            fgets(p.data_diag, 30, stdin);

            printf("\t\t\n\nSe o paciente está a cima dos 65 anos. vá em Salvar em Arquivos");


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
        printf("\nNome: %s", lista[i].nome);
        printf("Idade: %s\n", lista[i].idade);
        printf("CEP: %s\n", lista[i].cep);
        }

    }

    void salvarArquivogrisco()
    {
        FILE *arq2 = fopen("pacienterisco.txt", "w");
        int i;
        if(arq2)
        {
            for(i = 0; i < qt; i++)
            {
                fprintf(arq2, "Nome: %s\n", lista[i].nome);
                fprintf(arq2, "Idade: %s\n", lista[i].idade);
                fprintf(arq2, "CEP: %s\n", lista[i].cep);

            }
            fclose(arq2);
            printf("\t\t\n!!!!********Arquivo salvo********!!!!");

            
        }
        else
        printf("error.");
    }



    void salvarArquivo()
    {
        FILE *arq = fopen("paciente.txt", "w");
        int i;
        if(arq)
        {
            for(i = 0; i < qt; i++)
            {
            fprintf(arq, "Nome: %s\n", lista[i].nome);
            fprintf(arq, "Idade: %s\n", lista[i].idade);
            fprintf(arq, "CEP: %s\n", lista[i].cep);
            fprintf(arq, "CPF: %s\n", lista[i].cpf);
            fprintf(arq, "Telefone: %s\n", lista[i].telefone);
            fprintf(arq, "Endereço: %s\n", lista[i].endereco);
            fprintf(arq, "Data de Nascimento: %s\n", lista[i].data_nascimento);
            fprintf(arq, "Email: %s\n", lista[i].email);
            fprintf(arq, "Patologias: %s\n", lista[i].comor);
            fprintf(arq, "Data do Diagnostico: %s\n\n", lista[i].data_diag);

            }
            fclose(arq);
            printf("\t\t\n\n!!!!********Arquivo salvo********!!!!\n");

            
        }
        else
        printf("Error.");
    }