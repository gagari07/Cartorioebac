#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro()
{
	
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // copia os valores das strings cpf para arquivo
	
	FILE *file; // cria o arquivo no banco de dados
	
	file = fopen(arquivo, "w"); // abre o arquivo com op��o de whrite ("escrever")
	fprintf(file,"CPF: "); // escreve CPF: 
	fprintf(file,cpf); // "imprime" dentro do arquivo o cpf
	fclose(file); // fecha arquivo
	
	
	file = fopen(arquivo,"a");
	fprintf(file,"\n"); // pula uma linha ap�s o dado escrito
	fclose(file);
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
    file = fopen(arquivo, "a"); // abre o arquivo com op��o de "atualizar a infomar��o"
    fprintf(file,"Nome: "); // escreve Nome: 
	fprintf(file,nome); // "imprime" dentro do arquivo o nome
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,"\n"); // pula uma linha ap�s o dado escrito
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); // abre o arquivo com op��o de "atualizar a infomar��o"
	fprintf(file,"Sobrenome: "); // escreve Sobrenome: 
	fprintf(file,sobrenome); // "imprime" dentro do arquivo o sobrenome
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,"\n"); // pula uma linha ap�s o dado escrito
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); // abre o arquivo com op��o de "atualizar a infomar��o"
	fprintf(file,"Cargo: "); // escreve Cargo: 
	fprintf(file,cargo); // "imprime" dentro do arquivo o cargo
	fclose(file); // fecha arquivo
	
	system("pause");
			
}


int consulta()

{
	
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo para ler o conteudo ("read")
	
	if (file == NULL)
	
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!.\n\n"); // escreve na tela caso o numero n�o esteja no banco de dados
		
	}
	else
	{
	
       printf("\nEssas s�o as informa��es do usu�rio: \n\n");
	
	   while(fgets(conteudo,200,file) !=NULL) // obtem os dados escritos no arquivo e coloca em "conteudo"
	  {
		
		
		printf("%s", conteudo);
	   	printf("\n");
	   } 
   }   
	printf("\n"); 
	system("pause"); // aguarda usuario pressionar tecla para continuar	
}
	
	

	


int deletar()
{
	
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	

		
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file ==  NULL)
	{
		
		printf("\nO usu�rio n�o se encontra no sistema!.\n\n");
	}
	else
	{
	  remove(cpf);
	  printf("\nArquivo deletado com sucesso! \n\n");
	}
	  system("pause");
	
		
	
}

int main ()
{
	
	
	
	int opcao=0; // Definindo vari�vel de esolha do menu.
	int laco=1; // Definindo vari�vel para la�o de repeti��o FOR.
	
	for(laco=1;laco=1;) // la�o de repeti��o 
	{
	
	system("cls"); // limpa a tela antes de aparecer as op��es do menu. �til ap�s o fim do switch case.
	
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
	printf("### Cart�rio a EBAC ###\n\n"); // inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n"); 
	printf("\t4 - Sair do programa\n\n");
	printf("Op��o: "); // fim do menu
	
	scanf("%d",&opcao); // Armazenanndo a escolha do usu�rio
	
	system("cls"); // limpa a tela de menu ap�s a escolha do usu�rio
	

	
		switch(opcao) // inicio da sele��o
		{
	
		case 1:
		registro();  
		break;
	
		case 2:
		consulta();	
		break;
	
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;
		
		
	
		default:
		printf("Esta op��o n�o est� dispon�vel!\n");
		system("pause"); // aguarda usuario pressionar tecla para continuar  
		break;
		}//fim da sele��o
	}
}
