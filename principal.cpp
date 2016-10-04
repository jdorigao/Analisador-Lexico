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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "lexico.h"
#include "token.h"

using namespace std;


//Chamada do Analisador Léxico
int main ()
{
   //Basta apenas digitar o  endereço  e  o nome do
   //arquivo entre aspa dupla dentro do parenteses.
	arquivo("token.t");

   //Retorna os tokens
   RetornaToken ();

   return 0;

}
