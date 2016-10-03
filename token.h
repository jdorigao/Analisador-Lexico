/*------------------------------------------------------------------------------
                                "tokens.h"
                                ----------

            - Introdução.:
            --------------
            	No arquivo "token.h" contem o procedimentos RetornaToken,
            que  chama  o  prcedimento  ProximoToken e retorna os tokens
            encontrados.

            - void RetornaToken.:
            ---------------------
              	Ele  recebe  os  tokens  encontrado,  e para  uma melhor
            visualização a classe foi posto em um case, para  que  seja
            impresso o nome da classe e não o valor.

               Obs.: Os  tokens  retornados  estão  sendo  impressos  na
                 	   tela para a verificação do comportamento do código.
                     Para uma melhor verificação esta sendo  impresso  o
                     nome da classe e não seu valor, para a  verificação
                     será usado o valor, facilitando a comparação.
------------------------------------------------------------------------------*/



/*---------------------Declaração de bibliotecas------------------------------*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

using namespace std;
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
   			case  1:  cout << "Classe = " << "if" << endl;         			break;
         	case  2:  cout << "Classe = " << "then" << endl;       			break;
         	case  3:  cout << "Classe = " << "else" << endl;       			break;
         	case  4:  cout << "Classe = " << "end" << endl;        			break;
         	case  5:  cout << "Classe = " << "repeat" << endl;     			break;
         	case  6:  cout << "Classe = " << "until" << endl;      			break;
         	case  7:  cout << "Classe = " << "read" << endl;       			break;
         	case  8:  cout << "Classe = " << "write" << endl;               break;
         	case  9:  cout << "Classe = " << "+" << endl;                   break;
         	case 10:  cout << "Classe = " << "-" << endl;                   break;
         	case 11:  cout << "Classe = " << "*" << endl;                   break;
         	case 12:  cout << "Classe = " << "/" << endl;                   break;
         	case 13:  cout << "Classe = " << "=" << endl;                   break;
         	case 14:  cout << "Classe = " << "<" << endl;                   break;
         	case 15:  cout << "Classe = " << "(" << endl;                   break;
         	case 16:  cout << "Classe = " << ")" << endl;                   break;
         	case 17:  cout << "Classe = " << ";" << endl;                   break;
         	case 18:  cout << "Classe = " << ":=" << endl;                  break;
         	case 19:  cout << "Classe = " << "numero" << endl;              break;
         	case 20:  cout << "Classe = " << "identificador" << endl;       break;
         	case 21:  cout << "Classe = " << "final de sentenca" << endl;   break;
            case 22:  cout << "Classe = " << "erro" << endl;                break;
   		}
          cout << "Lexema = " << t.valor << endl;
          cout << "Linha  = " << t.posicaoL << endl;
          cout << endl;


      }while(t.classe != 21);//Encerra quando for final de sentença

      //Liberando memória
      delete[] vetor;
}

/*----------------------------------------------------------------------------*/
