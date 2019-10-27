#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include	"memory.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include    "malloc.h"
#include	 "fila1.h"


int			testa_rotina(char* servico);


int			main(int argc, char** argv)
{
	//
	// opcao: rodar com 'fila rotina'
	// por exemplo 'fila NNNNPPPPLA'
	// sao NPLA para
	// N - entra cliente normal
	// P - entra cliente com prioridade de atendimento
	// L - lista a situacao
	// A - tenta atender alguem
	//
	// cad lera indica uma acao para nao ter que ficar usando o menu
	//
	if( argc > 1 )	// veio algo na linha de comando
	{	
		printf("\nRotina=[%s]\n", argv[1]);
		printf("\nFila para %d clientes, rotina [%s]\n", CAPACIDADE, argv[1]);
		testa_rotina(argv[1]);
	}	// end if
	inicia_trabalhos();
	//testa_rotina("LNNNNNNNLAAAAAAALPPPAAAL");
	//testa_rotina("LNNNPAALALAL");
	testa_rotina("LNNPNNPNNPLAAAAAAAAAA");
	return 0;
}	// end main()


int	testa_rotina(char* servico)
{
	int n = strlen(servico);
	printf("\nTotal de acoes: %d\n\n", n);
	for (int i = 0; i < n; i++)
	{
		ciclo(servico[i]);
	};	// end for
	return n;
}	// end testa_rotina()

