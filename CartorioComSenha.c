#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das scrings


int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/scring
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
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
		printf("Não foi possivel abrir o arquivo, não localizado!\n\n");
	}

	while(fgets(conteudo, 200, file) != NULL) //inicia um looping
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause"); //finaliza o looping
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: \n"); //imprime a mensagem
	scanf("%s",cpf); //procura a variável "cpf"
	
	remove(cpf);
	
	printf("Usuário deletado com sucesso!.\n"); //imprime a mensagem
	system("pause"); //pausa a tela para leitura da mensagem
	
	FILE *file;
	file = fopen(cpf,"r"); 
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n\n"); //imprime a mensagem
		system("pause"); //pausa a tela para leitura da mensagem
	}
}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senha_digitada[]="admin"; // Defina a senha correta aqui
    int comparacao;
		
	printf("### Cartório EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a senha: ");
	scanf("%s",senha_digitada);  // Verifica se as senhas são iguais
    
    comparacao = strcmp(senha_digitada, "admin");
    
   	if(comparacao == 0) 
   	{
   		system("cls"); //resposavel por limpar a tela  	
		for(laco=1;laco=1;)
		{
			system("cls"); //resposavel por limpar a tela
		
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cartório da EBAC ###\n\n"); //inicio menu
			printf("Escolha a opção desejada do menu: \n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: ");

			scanf("%d", &opcao); //armazenando a escolha do usuário
	
			system("cls"); //resposavel por limpar a tela
		
			switch(opcao) //inicio da seleção do menu
			{
				case 1:
				registro(); //chamada de funções
				break;
			
				case 2:
				consulta(); //chamada de funções
				break;
			
				case 3:
				deletar(); //chamada de funções
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
				default:
				printf("Essa opção não esta disponível!\n\n"); //imprime a mensagem
				system("pause"); //pausa a tela para leitura da mensagem
				break;
				
			}
		}
	}
	else
		printf("Senha incorreta! Acesso negado.\n");
    
}
