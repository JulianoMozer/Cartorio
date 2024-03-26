#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das scrings


int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/scring
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
		
	printf("Usu�rio cadastrado com sucesso!\n"); //imprime a mensagem
	system("pause"); //pausa a tela para leitura da mensagem
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //inicial uma condicional
	{
		printf("N�o foi possivel abrir o arquivo, CPF n�o cadastrado!\n\n");
	}

	while(fgets(conteudo, 200, file) != NULL) //inicia um looping
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause"); //finaliza o looping
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: \n"); //imprime a mensagem
	scanf("%s",cpf); //procura a vari�vel "cpf"
	
	remove(cpf);
	
	printf("\nUsu�rio deletado com sucesso!.\n"); //imprime a mensagem
	system("pause"); //pausa a tela para leitura da mensagem
	
	FILE *file;
	file = fopen(cpf,"r"); 
	( fclose(file) ); 
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n\n"); //imprime a mensagem
		system("pause"); //pausa a tela para leitura da mensagem
	}
}


int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senha_digitada[]="admin"; // Defina a senha correta aqui
    int comparacao;
		
	printf("### Cart�rio EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a senha: ");
	scanf("%s",senha_digitada);  // Verifica se as senhas s�o iguais
    
    comparacao = strcmp(senha_digitada, "admin");
    
   	if(comparacao == 0) 
   	{
   		system("cls"); //resposavel por limpar a tela  	
		for(laco=1;laco=1;)
		{
			system("cls"); //resposavel por limpar a tela
		
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //inicio menu
			printf("Escolha a op��o desejada do menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: ");

			scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
			system("cls"); //resposavel por limpar a tela
		
			switch(opcao) //inicio da sele��o do menu
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consulta(); //chamada de fun��es
				break;
			
				case 3:
				deletar(); //chamada de fun��es
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
				default:
				printf("Essa op��o n�o esta dispon�vel!\n\n"); //imprime a mensagem
				system("pause"); //pausa a tela para leitura da mensagem
				break;
				
			}
		}
	}
	else
		printf("Senha incorreta! Acesso negado.\n");
    
}
