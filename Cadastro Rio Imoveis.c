#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<locale.h>
#include<windows.h>
#include<time.h>

#define LIMITE_STRING 20
#define LIMITE_REGISTRO 5
#define LIMITE_CEP 9
#define LIMITE_SENHA 10
#define LIMITE_PRECO 10

char endereco[LIMITE_REGISTRO][LIMITE_STRING], num_pesquisa[LIMITE_STRING], cep[LIMITE_REGISTRO][LIMITE_CEP], nome[LIMITE_STRING], senha[LIMITE_SENHA], nome_pesquisa[LIMITE_STRING], senha_pesquisa[LIMITE_STRING], preco[LIMITE_REGISTRO][LIMITE_PRECO], numero[LIMITE_REGISTRO][LIMITE_STRING];
int opcao, cadastros_concluidos, contador;
bool sair = false, encontrou = false;
void mascara_cep(), saida(), cadastro(), menu_principal(), info_system(), login(), listar(), buscar(), apagar(), menu_inicial(), registro(), alterar(), mascara_senha(char decidir_senha[LIMITE_SENHA]), preenchimento(int linha);
//FILE *pont_arq;
//char* myName;

int main()
{
	setlocale(LC_ALL, "portuguese");
	menu_inicial();
	//menu_principal();
	//cadastro();
	system("pause");
	return(0);
}

void mascara_cep(int linha)
{
	for(contador = 0; contador < strlen(cep[linha]) - 3; contador++)
	{
		printf("%c", cep[linha][contador]);
	}
	printf("-");
	for(contador = strlen(cep[linha]) - 3; contador < strlen(cep[linha]); contador++)
	{
		printf("%c", cep[linha][contador]);
	}
	printf("\n");
}

void erro(char texto[])
{
	opcao = -1;
	sair = false;
	while(opcao < 1 || opcao > 2)
	{
		system("cls");
		system("color 04");
		printf("%s\n", texto);
		printf("Deseja voltar ao menu?\n[1] Sim\n[2] Não\nOpção: ");
		scanf("%d", &opcao);
		if(opcao < 1 || opcao > 2)
		{
			system("cls");
			printf("Valor digitado inválido.\n");
			Beep(800, 500);
		}
		else if(opcao == 1)
		{
			sair = true;
		}
	}
}

void mascara_senha(char decidir_senha[LIMITE_SENHA])
{
	int i;
	char car;
	printf("Senha: ");
	for(i = 0; i < LIMITE_SENHA; i++)
	{
		car = getch();
		decidir_senha[i] = car;
		if(decidir_senha[i] == '\b')
		{
			printf("\b \b");
			contador -= 2;
			continue;
		}
		else if(decidir_senha[i] == ' ' || decidir_senha[i] == '\r')
		{
			break;
		}
		else
		{
			printf("*");
		}
	}
}

void menu_inicial()
{
	sair = false;
	opcao = -1;
	while(sair != true)
	{
		while(opcao < 1 || opcao > 3)
		{
			system("cls");
			system("color 0A");
			printf("Bem-Vindo ao cadastro de imóveis 2.0v\n\n\n						     Rio Imóveis\n\n						  Sessão do Usuário\n				   __________________________________________________\n\n						    [1] Registrar\n						    [2] Login\n	 					    [3] Sair\n\n	 					    Opção: ");
			scanf("%d", &opcao);
			if(opcao < 1 || opcao > 3)
			{
				system("cls");
				system("color 04");
				printf("Valor digitado inválido.\n");
				Beep(800, 500);
			}
		}
		switch(opcao)
		{
			case 1:
				registro();
				break;
			case 2:
				login();
				break;
			case 3:
				sair = true;
				break;
			default:
				system("cls");
				printf("Valor digitado inválido.\n");
				system("pause");
				break;
		}
		opcao = -1;
	}
}

void registro()
{
	system("color 0A");
	system("cls");
	printf("Nome: ");
	scanf("%s", &nome);
	mascara_senha(senha);
	/*pont_arq = fopen("arquivo_palavra.txt", "a");
	if(pont_arq == NULL)
	{
		printf("Erro na abertura do arquivo!");
	}
	fprintf(pont_arq, "%s\n%s", nome, senha);
	fclose(pont_arq);*/
}

void login()
{
	sair = false;
	opcao = -1;
	while(sair != true)
	{
		system("cls");
		system("color 0A");
		printf("Nome: ");
		scanf("%s", &nome_pesquisa);
		mascara_senha(senha_pesquisa);
		//pont_arq = fopen("arquivo_palavra.txt", "r");
		//if(fgets(nome_pesquisa, LIMITE_STRING, pont_arq) != NULL && fgets(senha_pesquisa, LIMITE_STRING, pont_arq) != NULL)
		if(strcmp(nome_pesquisa,nome) == 0 && strcmp(senha_pesquisa,senha) == 0)
		{
		//	myName = strdup(nome_pesquisa);
			sair = true;
		//	fclose(pont_arq);
			menu_principal();
		}
		else
		{
			erro("Login Incorreto.\n");
			if(opcao == 1)
			{
				menu_inicial();
			}
			else
			{
				login();
			}
		}
	}
	menu_inicial();
}

void menu_principal()
{
	opcao = -1;
	sair = false;
	encontrou = false;
	while(sair != true)
	{
		while(opcao < 1 || opcao > 7)
		{
			system("color 0A");
			system("cls");
			printf("\t\t\t\t\t\t   Olá %s\n\t\t\t\t Seja muito bem-vindo ao cadastro de imóveis \n\n\n",nome);
			printf("\t\t\t\t ---------------------Menu---------------------\n\t\t\t\t [1] Cadastro\n\t\t\t\t [2] Listar Imóveis\n\t\t\t\t [3] Buscar\n\t\t\t\t [4] Remover Imóvel\n\t\t\t\t [5] Alterar Imóvel\n\t\t\t\t [6] Informações do Sistema\n\t\t\t\t [7] Deslogar\n\n\t\t\t\t Opção: ");
			scanf("%d", &opcao);
			if(opcao < 1 || opcao > 7)
			{
				system("cls");
				system("color 04");
				printf("Valor digitado inválido.\n");
				Beep(800, 500);
			}
		}
		switch(opcao)
		{
			case 1:
				cadastro();
				break;
			case 2:
				listar();
				break;
			case 3:
				buscar();
				break;
			case 4:
				apagar();				
				break;
            case 5:
              alterar();
                break;
            case 6:
            	info_system();
            	break;
			case 7:
				sair = true;
				break;
			default:
				system("cls");
				printf("Valor digitado inválido.\n");
				system("pause");
				break;
		}
		opcao = -1;
	}
}

void info_system()
{
	system("color 0A");
	system("cls");
    printf("Informações do aplicativo:\n\nWindows 10,8,7\nFeito em Linguagem C\n\nRequisitado para Rio Imóveis\n\nFeito por:\n\n-Victor da Silva\n-Diego Augusto\n-Guilherme Samuel\n-Camily Vitória\n-Diego Artur\n");
    printf("\nTivemos ajuda de pessoas de fora e de sites especializados\n");
    printf("\nMuito obrigado pela confiança e incentivo");
    printf("\nInstruções: Professor Sudário");
    printf("\n\n\n\n\n\n\n ;)\n\n");
    system("pause");
}

void preenchimento(int linha)
{
    int i, contador_pontos;
    encontrou = true;
    while(strlen(cep[linha]) != LIMITE_CEP - 1 || encontrou == true)
    {
    	
        encontrou = false;
        printf("Digite o CEP (apenas números): ");
        scanf("%s", cep[linha]);
        for(i = 0; i < LIMITE_REGISTRO; i++)
        {
            for(contador = 0; contador < strlen(cep[linha]); contador++)
            {
                if(cep[linha][contador] < '0' || cep[linha][contador]> '9')
                {
                    encontrou = true;
                }
            }
        }
        if(strlen(cep[linha]) != LIMITE_CEP - 1 || encontrou == true)
        {
            printf("CEP inválido, digite apenas números.\n");
        }
    }
    //printf("%s\n", cep[0]);
    printf("Digite o endereço: ");
    fflush(stdin);
    scanf("%[^\n]s", &endereco[linha]);
    encontrou = true;
    while(encontrou == true)
    {
        encontrou = false;
        printf("Digite o número do imóvel: ");
        scanf("%s", numero[linha]);
        i++;
        contador++;
    }
    encontrou = true;
    while(encontrou == true)
    {
        encontrou = false;
        printf("Digite o preço: ");
        scanf("%s", preco[linha]);
        for(i=0;i<LIMITE_REGISTRO;i++)
        {
            for(contador = 0; contador < strlen(preco[linha]); contador++)
            {
                if(preco[linha][contador] < '0' || preco[linha][contador]> '9')
                {
                    encontrou = true;
                }
            }
        }
        if(encontrou == true)
        {
            printf("Preço inválido, digite apenas números.\n");
        }
    }
}

void cadastro()
{
	system("color 0A");
	static int linha;
	do
	{
		system("cls");
		preenchimento(linha);	
		cadastros_concluidos++;
		opcao = -1;
		system("cls");
		printf("Digite 1 para continuar ou qualquer para sair\nOpção: ");
		scanf("%d", &opcao);
		linha++;
	} while(opcao==1);
}

void listar()
{
	int linha=0;
	contador=0;
	
	system("color 0A");
	system("cls");
	while (true)
	{
		if(linha == cadastros_concluidos)
		{
			break;
		}
		if(strcmp(cep[linha],"")!= 0)
		{
			printf("Endereço: %s\nNúmero do imóvel: %s\nPreço: R$%s.00\nCEP: ", endereco[linha], numero[linha], preco[linha]);
			mascara_cep(linha);
		}
		linha++;
		printf("\n\n");
	}
	system("pause");
}

void buscar()
{
	int indice,i;
	system("color 0A");
	system("cls");
	printf("Digite o número do imóvel: ");
	scanf("%s", &num_pesquisa);
	
	for(contador=0;contador<cadastros_concluidos;contador++)
	{
		if(strcmp(numero[contador],num_pesquisa)==0 && strcmp(numero[contador],"")!= 0)
		{
			encontrou = true;
			indice = contador;
			break;
		}
	}
	if(encontrou == false)
	{
		erro("Número não encontrado.\n");
		if(opcao == 1)
		{
			menu_principal();
		}
		else
		{
			buscar();
		}
	}
	else
	{
		printf("Endereço: %s\nNúmero do imóvel: %s\nPreço: R$%s.00\nCEP: ", endereco[indice], numero[indice], preco[indice]);
		mascara_cep(indice);
	}
	encontrou = false;
	printf("\n\n");
	system("pause");
}

void apagar()
{
	system("color 0A");
	int indice;
	system("cls");
	printf("Digite o número do imóvel: ");
	scanf("%s", &num_pesquisa);
	for(contador = 0; contador < cadastros_concluidos; contador++)
	{
		if(strcmp(numero[contador], num_pesquisa) == 0 && strcmp(numero[contador], "") != 0)
		{
			system("cls");
			encontrou = true;
			indice = contador;
		}
	}
	if(encontrou == false)	
	{
		erro("Número não encontrado.\n");
		if(opcao == 1)
		{
			menu_principal();
		}
		else
		{
			apagar();
		}
	}
	else
	{
		while(opcao < 1 || opcao > 3)
		{
			printf("Endereço: %s\nNúmero do imóvel: %s\nPreço: R$%s.00\nCEP: ", endereco[indice], numero[indice], preco[indice]);
			mascara_cep(indice);
			printf("\nDeseja deletar o seguinte imóvel?\n[1] Sim\n[2] Não\n[3] Voltar ao Menu\nOpção: ");
			scanf("%d", &opcao);
			if(opcao < 1 || opcao > 3)
			{
				system("cls");
				system("color 04");
				printf("Valor digitado inválido.\n");
				Beep(800, 500);
			}
		}
		if(opcao == 1)
		{
			strcpy(endereco[indice], "");
			strcpy(cep[indice], "");
			strcpy(numero[indice], "");
			strcpy(preco[indice], "");	
			for(contador = indice; contador < LIMITE_REGISTRO; contador++)
			{
				if(contador + 1 < LIMITE_REGISTRO)
				{
					strcpy(endereco[contador], endereco[contador+1]);
					strcpy(cep[contador], cep[contador+1]);
					strcpy(numero[contador], numero[contador+1]);
					strcpy(preco[contador], preco[contador+1]);
				}
			}
			strcpy(endereco[LIMITE_REGISTRO], "");
			strcpy(cep[LIMITE_REGISTRO], "");
			strcpy(numero[LIMITE_REGISTRO],"");
			strcpy(preco[LIMITE_REGISTRO], "");		
		}
		else if(opcao == 2)
		{
			apagar();
		}
		else if(opcao == 3)
		{
			menu_principal();
		}
	}
}

void alterar()
{
	int indice;
	system("color 0A");
    system("cls");
	printf("Digite o número do imóvel: ");
	scanf("%s", &num_pesquisa);
	for(contador = 0; contador < cadastros_concluidos; contador++)
	{
		if(strcmp(numero[contador], num_pesquisa) == 0 && strcmp(numero[contador], "") != 0)
		{
			system("cls");
			encontrou = true;
			indice = contador;
		}
	}
	if(encontrou == false)	
	{
		erro("Número não encontrado.\n");
		if(opcao == 1)
		{
			menu_principal();
		}
		else
		{
			alterar();
		}
	}
	else
	{
		opcao = -1;
		while(opcao < 1 || opcao > 3)
		{
			system("color 0A");
			printf("Endereço: %s\nNúmero do imóvel: %s\nPreço: R$%s.00\nCEP: ", endereco[indice], numero[indice], preco[indice]);
			mascara_cep(indice);
			printf("\nDeseja alterar o seguinte imóvel?\n[1] Sim\n[2] Não\n[3] Voltar ao menu\nOpção: ");
			scanf("%d", &opcao);
			if(opcao < 1 || opcao > 3)
			{
				system("cls");
				system("color 04");
				printf("Valor digitado inválido.\n");
				Beep(800, 500);
			}
		}
		if(opcao == 1)
		{
			system("cls");
			preenchimento(indice);
		}
		else if(opcao == 2)
		{
			system("cls");
			alterar();
		}
		else if(opcao == 3)
		{
			menu_principal();
		}
	}
	encontrou = false;
}
