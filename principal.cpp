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
                                "principal.cpp"
                                ---------------

            - Introdu��o.:
            --------------
            	No arquivo "principal.h" contem o corpo  principal, est�o
            sendo  chamados  os  procedimentos arquivo("Nome_Arquivo") e
            RetornaToken,necess�rio para a execu��o do Analisador L�xico.


				- arquivo("token.t").:
            ----------------------
              Chama o procedimento que  abre o arquivo e armazena todo o
            seu conteudo em um vetor.
              Para identificar o arquivo, basta apenas por o  endere�o e
            do o nome do arquivo  entre   aspa  dupla dentro do parentes
            ap�s a palavra arquivo.


            - RetornaToken.:
            ----------------
              Chama o procedimento que retorna o pr�ximo token e imprime
            na tela para que possa verificar quais os tokens encontrados.


              Obs.: Observei que quando declaramos as bibliotecas do c++
                    antes  dos arquivo .h, eles erdam as declara��es das
                    bibliotecas. Ser� bem parecido com token.h necessita
                    de lexico.h e esse por sua vez de buffer.h  est�o na
                    mesma  situa��o,  se  mudada a ordem  haver� erro de
                    declara��o de variaveis.
------------------------------------------------------------------------------*/



//Declara��o de bibliotecas
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include "buffer.h"
#include "lexico.h"
#include "token.h"


//Chamada do Analisador L�xico
void main ()
{
   //Basta apenas digitar o  endere�o  e  o nome do
   //arquivo entre aspa dupla dentro do parenteses.
	arquivo("token.t");

   //Retorna os tokens
   RetornaToken ();

}