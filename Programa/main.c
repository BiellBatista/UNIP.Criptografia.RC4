#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rciv.h"

short *menu();
unsigned char *chiperText(unsigned char *, unsigned char *, unsigned short *, unsigned short *, unsigned short *, unsigned short *);
unsigned char *plainText(unsigned char *, unsigned char *, unsigned short *, unsigned short *, unsigned short *, unsigned short *);

int main(int argc, char *argv[])
{
	unsigned char *plain = (unsigned char *) calloc(256, sizeof(unsigned char));
	unsigned char *key = (unsigned char *) calloc(256, sizeof(unsigned char));
	unsigned short *i = (unsigned short *) calloc(1, sizeof(unsigned short));
	unsigned short *j = (unsigned short *) calloc(1, sizeof(unsigned short));
	unsigned short *tamanhoPlainText = (unsigned short *) calloc(1, sizeof(unsigned short));
	unsigned short *tamanhoKey = (unsigned short *) calloc(1, sizeof(unsigned short));
	FILE *texto = fopen("mensagem.txt", "w");
	fputs("Mensagem descriptografada com sucesso!!!\n\nMensagem: ", texto);
	fclose(texto);

	switch((int) menu())
	{
		case 0:
			free(plain);
			free(key);
			free(i);
			free(j);
			free(tamanhoKey);
			free(tamanhoPlainText);
			exit(0);
		break;

		case 1:
			system("cls");
			fflush(stdin);

			puts("#####################################################################");
			puts("########### Digite abaixo a Mensagem a ser Criptografada ############");
  			puts("#####################################################################");
  			gets(plain);
  			*tamanhoPlainText = strlen(plain);
  			fflush(stdin);

  			puts("#####################################################################");
  			puts("################# Digite abaixo a Chave Simetrica ###################");
  			puts("#####################################################################");
  			gets(key);
  			fflush(stdin);
  			*tamanhoKey = strlen(key);

  			puts("#####################################################################");
  			puts("##################### Mensagem Criptografada ########################");
  			puts("#####################################################################");
  			puts(chiperText(plain, key, i, j, tamanhoKey, tamanhoPlainText));
  			puts("#####################################################################");
			puts("############ Aperte qualquer tecla para voltar ao menu ##############");
			puts("#####################################################################");
			
			getch();
			free(plain);
			free(key);
			free(i);
			free(j);
			free(tamanhoKey);
			free(tamanhoPlainText);
			free(texto);
			system("start rc4");
			exit(0);
		break;

		case 2:
			system("cls");

			puts("#####################################################################");
			puts("########## Digite abaixo a Mensagem a ser Desriptografada ###########");
  			puts("#####################################################################");
  			gets(plain);
  			*tamanhoPlainText = strlen(plain);
  			fflush(stdin);

  			puts("#####################################################################");
  			puts("################# Digite abaixo a Chave Simetrica ###################");
  			puts("#####################################################################");
  			gets(key);
  			fflush(stdin);
  			*tamanhoKey = strlen(key);

  			puts("#####################################################################");
  			puts("#################### Mensagem Desriptografada #######################");
  			puts("#####################################################################");
			FILE *texto = fopen("mensagem.txt", "a+");
			fputs(plainText(plain, key, i, j, tamanhoKey, tamanhoPlainText), texto);
			fclose(texto);
			system("start mensagem.txt");
			puts("############ Aperte qualquer tecla para voltar ao menu ##############");
			puts("#####################################################################");
			
			getch();
			free(plain);
			free(key);
			free(i);
			free(j);
			free(tamanhoKey);
			free(tamanhoPlainText);
			free(texto);
			system("start rc4");
			exit(0);
		break;
		
		case 3:
			system("del mensagem.txt");
			
			puts("################# Arquivos apagados com sucesso !!! #################");
			puts("#####################################################################");
			puts("############# Aperte qualquer tecla para voltar ao menu #############");
			puts("#####################################################################");
			
			fflush(stdin);
			free(plain);
			free(key);
			free(i);
			free(j);
			free(tamanhoKey);
			free(tamanhoPlainText);
			free(texto);
			getch();
			system("cls");
			system("start rc4");
			exit(0);
		break;
		
		default:
			puts("\t\t\t Opcao Invalida!!!");
			puts("#####################################################################\n");
			
			fflush(stdin);
			free(plain);
			free(key);
			free(i);
			free(j);
			free(tamanhoKey);
			free(tamanhoPlainText);
			free(texto);
			getch();
			system("cls");
			main(0, NULL);
		break;
	}

	return 0;
}