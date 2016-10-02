/*==============================================================================
|           UNIGRAN - CENTRO UNIVERSIT�RIO DA GRANDE DOURADOS                  |
|               		 3� ANO Ci�ncia da Computa��o                             |
|                                                                              |
|                                                                              |
|                 		   :.Alunos.:                                          |
|                          ----------                                          |
|            	JULIANO BARBIEIRO DORIG�O - RGM: 122.213                        |
|	  	 			DALILA CRISTINA CIVIDINI  - RGM: 122.281                        |
|	 				PATR�CIA RIBEIRO DE SOUZA - RGM: 122.308                        |
|                                                                              |
|               			  :.Professor.:                                        |
|                         -------------                                        |
|               Fabio                                                          |
|                                                                              |
|                                                                              |
|               		Trabalho de Compiladores                                  |
|                    ------------------------                                  |
|                                                                              |
|          IMPLEMENTA��O DE UM ANALISADOR L�XICO PARA TINY                     |
|                                                                              |
|          		- Defini��o da gera��o de c�digo                                |
|          		- Implementa��o de um analisador l�xico                         |
|                                                                              |
==============================================================================*/



/*------------------------------------------------------------------------------
                                "buffer.h"
                                ----------
			- Introdu��o.:
         --------------
           No arquivo "buffer.h" contem os  procedimentos de controle
	      e  armazenamento, tambem as  variaveis que ser�o utilizadas.
         Para que o Analizador L�xico possa varrer todo o  arquivo  e
         retornar os tokens encontrados...

         - void arquivo.:
         ----------------
           Tem  a   finalidade  de  abrir  um  arquivo  para  leitura
         e  armazenar  todo  o  conte�do  do  arquivo  em  um vetor e
         finalizando com '\0'.

         - char ProximoCaracter.:
         ------------------------
           Tem  a  finalidade  de fazer a leitura do vetor e retornar o
         pr�ximo caracter armazenado no vetor.

         - typedef struct token.:
         ------------------------
           � criado um registro do tipo token, no qual ir� armazenar as
         informa��es dos tokens encontrados no arquivo como:
           			-	Classe  .: Para que classe o token pertence.
                  -  Valor   .: Lexema encontrado.
                  -	PosicaoL.: Em que linha foi encontrado.


         - Obs.:  O  vetor  est�  sendo  alocado  dinamicamente com o
         			tamanho do arquivo, para que n�o haja desperdi�o de
              		espa�o na mem�ria.
------------------------------------------------------------------------------*/



/*---------------------Declara��o de bibliotecas------------------------------*/
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <io.h>
/*----------------------------------------------------------------------------*/



/*---------------------------Definindo tipo-----------------------------------*/
	typedef struct token	{
                   			int classe;//Classe do token
   					 			char valor[100];//Lexema
                   			int posicaoL;//Linha do lexema
                    		}token;
/*----------------------------------------------------------------------------*/

  

/*-------------------------Declarando variaveis-------------------------------*/
   char c;//Recebe o caracter para ser analizado
	int linha = 1;//Contador de linha
	int InicioDeLexema = 0;//Ponteiro para localizar o in�cio do Lexema
	int ApontadorAdiante = 0;//Ponteiro para localizar o fim do Lexema
	char *vetor;//Ponteiro para o vetor que armazena o arquivo
/*----------------------------------------------------------------------------*/



/*------------------------Inicio void arquivo---------------------------------*/
char arquivo(char* nome_arquivo)
{


    	FILE *arquivo;//Ponteiro do arquivo
      char letra;//Recebe caracteres lido do arquivo
      int bloco = 0;//Contador de coluna
      int aux=0;//Auxilia na inser��o de dados no vetor


      //Abre o arquivo somente para leitura
      /*-------------------------------------------
      Se o arquivo n�o for encontrado ou n�o puder
      se aberto retornara um mensagem de erro
      --------------------------------------------*/
      if((arquivo = fopen(nome_arquivo,"r")) == NULL)
		{
          clrscr();
          textcolor(LIGHTRED +BLINK);
      	 gotoxy(25,10);
          cprintf(":.Erro na Abertura do Arquivo.:");
          textcolor(YELLOW);
          gotoxy(10,12);
          cprintf("Verifique se o endereco do arquivo foi degitado corretamente");
          getch();
          exit(1);
      }

      
      //L� caracter por caracter do arquivo
      while((letra = getc(arquivo)) != EOF)
      {
         bloco++;//Conta quantos caracter contem no arquivo...
      }

      /*--------------------------------------------
      Alocando vetor dinamicamente com a quantidade
          de caracter que contem no arquivo
      --------------------------------------------*/
      vetor = new char[bloco];

      //Limpando o vetor
      for(int l = 0; l < bloco; l++)
      		vetor[l] = NULL;


      //Retorna o ponteiro ao in�cio do arquivo
      rewind(arquivo);

      
      //L� caracter por caracter do arquivo
      while((letra = getc(arquivo)) != EOF)
      {
      	//Insere caracter por caracter no vetor
         vetor[aux] = letra;
         aux++;//Pr�xima posi��o do vetor
      }

      //Insere '\0' no final do vetor para
      //que possa identificar o final.
      vetor[bloco] = '\0';

	   //Fecha o arquivo
      fclose(arquivo);
}
/*---------------------------Fim void arquivo---------------------------------*/



/*---------------------Inicio void ProximoCaracter----------------------------*/
char ProximoCaracter ( )
{
     c = vetor[ApontadorAdiante++];//Incremento da posi��o do vetor

     if (c == '\n')
    	linha++;

    return c;//Retorna o caracter do vetor
}
/*------------------------Fim void ProximoCaracter----------------------------*/
