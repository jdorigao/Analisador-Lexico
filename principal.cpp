/*==============================================================================
|           UNIGRAN - CENTRO UNIVERSITÁRIO DA GRANDE DOURADOS                  |
|               		 3º ANO Ciência da Computação                             |
|                                                                              |
|                                                                              |
|                 		   :.Alunos.:                                          |
|                          ----------                                          |
|            	JULIANO BARBIEIRO DORIGÃO - RGM: 122.213                        |
|	  	 			DALILA CRISTINA CIVIDINI  - RGM: 122.281                        |
|	 				PATRÍCIA RIBEIRO DE SOUZA - RGM: 122.308                        |
|                                                                              |
|               			  :.Professor.:                                        |
|                         -------------                                        |
|               Fabio                                                          |
|                                                                              |
|                                                                              |
|               		Trabalho de Compiladores                                  |
|                    ------------------------                                  |
|                                                                              |
|          IMPLEMENTAÇÃO DE UM ANALISADOR LÉXICO PARA TINY                     |
|                                                                              |
|          		- Definição da geração de código                                |
|          		- Implementação de um analisador léxico                         |
|                                                                              |
==============================================================================*/



/*------------------------------------------------------------------------------
                                "principal.cpp"
                                ---------------

            - Introdução.:
            --------------
            	No arquivo "principal.h" contem o corpo  principal, estão
            sendo  chamados  os  procedimentos arquivo("Nome_Arquivo") e
            RetornaToken,necessário para a execução do Analisador Léxico.


				- arquivo("token.t").:
            ----------------------
              Chama o procedimento que  abre o arquivo e armazena todo o
            seu conteudo em um vetor.
              Para identificar o arquivo, basta apenas por o  endereço e
            do o nome do arquivo  entre   aspa  dupla dentro do parentes
            após a palavra arquivo.


            - RetornaToken.:
            ----------------
              Chama o procedimento que retorna o próximo token e imprime
            na tela para que possa verificar quais os tokens encontrados.


              Obs.: Observei que quando declaramos as bibliotecas do c++
                    antes  dos arquivo .h, eles erdam as declarações das
                    bibliotecas. Será bem parecido com token.h necessita
                    de lexico.h e esse por sua vez de buffer.h  estão na
                    mesma  situação,  se  mudada a ordem  haverá erro de
                    declaração de variaveis.
------------------------------------------------------------------------------*/



//Declaração de bibliotecas
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include "buffer.h"
#include "lexico.h"
#include "token.h"


//Chamada do Analisador Léxico
void main ()
{
   //Basta apenas digitar o  endereço  e  o nome do
   //arquivo entre aspa dupla dentro do parenteses.
	arquivo("token.t");

   //Retorna os tokens
   RetornaToken ();

}