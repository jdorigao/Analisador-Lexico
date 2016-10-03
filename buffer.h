/*------------------------------------------------------------------------------
                                "buffer.h"
                                ----------
			- Introdução.:
         --------------
           No arquivo "buffer.h" contem os  procedimentos de controle
	      e  armazenamento, tambem as  variaveis que serão utilizadas.
         Para que o Analizador Léxico possa varrer todo o  arquivo  e
         retornar os tokens encontrados...

         - void arquivo.:
         ----------------
           Tem  a   finalidade  de  abrir  um  arquivo  para  leitura
         e  armazenar  todo  o  conteúdo  do  arquivo  em  um vetor e
         finalizando com '\0'.

         - char ProximoCaracter.:
         ------------------------
           Tem  a  finalidade  de fazer a leitura do vetor e retornar o
         próximo caracter armazenado no vetor.

         - typedef struct token.:
         ------------------------
           É criado um registro do tipo token, no qual irá armazenar as
         informasões dos tokens encontrados no arquivo como:
           	- Classe  .: Para que classe o token pertence.
            - Valor   .: Lexema encontrado.
            - PosicaoL.: Em que linha foi encontrado.


         - Obs.:  O  vetor  está  sendo  alocado  dinamicamente com o
         			tamanho do arquivo, para que não haja desperdiço de
              		espaço na memória.
------------------------------------------------------------------------------*/



/*---------------------Declaração de bibliotecas------------------------------*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

using namespace std;
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
	int InicioDeLexema = 0;//Ponteiro para localizar o início do Lexema
	int ApontadorAdiante = 0;//Ponteiro para localizar o fim do Lexema
	char *vetor;//Ponteiro para o vetor que armazena o arquivo
/*----------------------------------------------------------------------------*/



/*------------------------Inicio void arquivo---------------------------------*/
char arquivo(char* nome_arquivo)
{


      FILE *arquivo;//Ponteiro do arquivo
      char letra;//Recebe caracteres lido do arquivo
      int bloco = 0;//Contador de coluna
      int aux=0;//Auxilia na inserção de dados no vetor


      //Abre o arquivo somente para leitura
      /*-------------------------------------------
      Se o arquivo não for encontrado ou não puder
      se aberto retornara um mensagem de erro
      --------------------------------------------*/
      if((arquivo = fopen(nome_arquivo,"r")) == NULL){
          cout << ":.Erro na Abertura do Arquivo.:" << endl;
          cout << "Verifique se o endereco do arquivo foi degitado corretamente" << endl;
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


      //Retorna o ponteiro ao início do arquivo
      rewind(arquivo);

      
      //Lê caracter por caracter do arquivo
      while((letra = getc(arquivo)) != EOF)
      {
      	//Insere caracter por caracter no vetor
         vetor[aux] = letra;
         aux++;//Próxima posição do vetor
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
     c = vetor[ApontadorAdiante++];//Incremento da posição do vetor

     if (c == '\n')
    	linha++;

    return c;//Retorna o caracter do vetor
}
/*------------------------Fim void ProximoCaracter----------------------------*/
