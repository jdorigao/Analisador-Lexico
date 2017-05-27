# Definição da implementação do Analisador Léxico

	Introdução

  	A função de um analisador léxico consiste em ler os caracteres do programa-fonte e produzir uma seqüência de componentes léxicos ( tokens ) que serão utilizados pelo analisador sintático e/ou identificar erros léxicos na entrada. Além de sua função básica, o analisador léxico em geral está encarregado de fazer algumas tarefas secundárias como a eliminação de comentários, espaços em branco e tabulações. Outra função associada ao analisador léxico é o controle das linhas onde são encontrados erros e avisos.
	
	Implementação 
	
	A implementação foi feita utilizando o Borland C++ versão 5.02, os arquivos referente à implementação são:

    	1. principal.ide
    	2. buffer.h
    	3. lexico.h
		4. token.h
		5. principal.cpp

	1. Principal.ide

  	Foi criado para a implementação um projeto para o sistema DOS, no qual gera um arquivo .ide que foi nomeado principal, onde estarão os arquivos necessários para a implementação do Analisador Léxico, como buffer.h, léxico.h, token.h e principal.cpp e será gerado o principal.exe o arquivo executável.

	2. Buffer.h

  	A criação do buffer.h surgiu da necessidade da declaração de variáveis e a utilização de funções utilizados na execução do Analisador Léxico, não importando a linguagem que esta sendo analisada para isso foram criados as funções  “char arquivo(char* nome_arquivo)” e “char ProximoCaracter ( )”.

	2.1. char arquivo(char* nome_arquivo)
  
	Criada uma função que passa como argumento o endereço do arquivo. Será feita a verificação do arquivo, se ele pode ser aberto, caso não consiga será emitido um erro na tela informando que o arquivo não pode ser aberto.
	É feita a leitura até o final do arquivo para que possa identificar o seu tamanho para armazena-lo em um vetor dinamicamente, em sua ultima posição o vetor recebera ‘\0’ para que possa identificar o final.

	2.2. char ProximoCaracter ( )

	Essa função  controla o ApontadorAdiante e a quantidade de linha para que possa retornar  do vetor o caracter correto para a verificação do lexema.

	3. Lexico.h

	Nesse arquivo é onde esta a linguagem  TINY que contem apenas a implementação do código em base de geração de autômatos e a função FalhouAutomatos, caso haja a necessidade de uma troca de linguagem ao alguma alteração na própria linguagem, a modificação será feita apenas nesse arquivo não precisando alterar o restante.
	
	3.1. int FalhouAutomatos (int &partida)
  	
	Tem a finalidade de retornar o estado inicial do próximo token. Foi posto em um case que recebera o valor referente a o token verificado e retorna o estado inicial do próximo token.
	
	Exemplo.: case  0: return  3;      Se não for comentário retorna o inicio do token de if
 
	3.2. token ProximoToken ( )
  
	A verificação da linguagem TINY foi feita através da implementação do código em base de geração de autômatos, no qual será informado cada caractere com a função ProximoCaracter( ) e verificado se ele encontra-se na linguagem senão, será tratado como erro pelo Analisador Léxico, logo abaixo esta descrita o autômato infinito determinístico utilizado para a verificação:

	4. Léxico.h

	Nesse arquivo esta a função “void RetornaToken ()”que  chama  o  prcedimento  ProximoToken e retorna os tokens encontrados.

	4.1. void RetornaToken ()

	Recebe os tokens encontrado, e para uma melhor visualização a classe foi posto em um case, para que seja impresso o nome da classe e não o valor.

	5. Principal.cpp

	No arquivo contem o corpo principal, estão sendo chamados os procedimentos arquivo("Nome_Arquivo") e RetornaToken, necessário para a execução do Analisador Léxico.

	5.1. arquivo("token.t")

	Chama o procedimento que abre o arquivo e armazena todo o seu conteúdo em um vetor. Para identificar o arquivo, basta apenas por o endereço com o nome do arquivo entre aspa dupla dentro do parentes após a palavra arquivo.

	5.2. RetornaToken( )
	
	Chama o procedimento que retorna o próximo token e imprime na tela para que possa visualizar quais os tokens encontrados.
