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
                                "tokens.h"
                                ----------

            - Introdu��o.:
            --------------
            	No arquivo "token.h" contem o procedimentos RetornaToken,
            que  chama  o  prcedimento  ProximoToken e retorna os tokens
            encontrados.

            - void RetornaToken.:
            ---------------------
              	Ele  recebe  os  tokens  encontrado,  e para  uma melhor
            visualiza��o a classe foi posto em um case, para  que  seja
            impresso o nome da classe e n�o o valor. 

               Obs.: Os  tokens  retornados  est�o  sendo  impressos  na
                 	   tela para a verifica��o do comportamento do c�digo.
                     Para uma melhor verifica��o esta sendo  impresso  o
                     nome da classe e n�o seu valor, para a  verifica��o
                     ser� usado o valor, facilitando a compara��o. 
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



/*------------------------------Token Retornado-------------------------------*/
void RetornaToken ()
{
   token t;
		do
     	{
         t = ProximoToken();

          //Imprime na tela os tekens retornados
          switch(t.classe)
   		{
   			case  1:  cout<<"Classe = "<<"if"<< endl;         				break;
         	case  2:  cout<<"Classe = "<<"then"<< endl;       				break;
         	case  3:  cout<<"Classe = "<<"else"<< endl;       				break;
         	case  4:  cout<<"Classe = "<<"end"<< endl;        				break;
         	case  5:  cout<<"Classe = "<<"repeat"<< endl;     				break;
         	case  6:  cout<<"Classe = "<<"until"<< endl;      				break;
         	case  7:  cout<<"Classe = "<<"read"<< endl;       				break;
         	case  8:  cout<<"Classe = "<<"write"<< endl;                break;
         	case  9:  cout<<"Classe = "<<"+"<< endl;                    break;
         	case 10:  cout<<"Classe = "<<"-"<< endl;                    break;
         	case 11:  cout<<"Classe = "<<"*"<< endl;                    break;
         	case 12:  cout<<"Classe = "<<"/"<< endl;                    break;
         	case 13:  cout<<"Classe = "<<"="<< endl;                    break;
         	case 14:  cout<<"Classe = "<<"<"<< endl;                    break;
         	case 15:  cout<<"Classe = "<<"("<< endl;                    break;
         	case 16:  cout<<"Classe = "<<")"<< endl;                    break;
         	case 17:  cout<<"Classe = "<<";"<< endl;                    break;
         	case 18:  cout<<"Classe = "<<":="<< endl;                   break;
         	case 19:  cout<<"Classe = "<<"numero"<< endl;               break;
         	case 20:  cout<<"Classe = "<<"identificador"<< endl;        break;
         	case 21:  cout<<"Classe = "<<"final de sentenca"<< endl;    break;
            case 22:  cout<<"Classe = "<<"erro"<< endl;                 break;
   		}
          cout<<"Lexema = "<< t.valor  << endl;
          cout<<"Linha  = "<< t.posicaoL << endl;
          cout<<endl;

          getch();

      }while(t.classe != 21);//Encerra quando for final de senten�a

      //Liberando mem�ria
      delete[] vetor;
}

/*----------------------------------------------------------------------------*/
