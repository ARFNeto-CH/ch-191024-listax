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
		inicia_trabalhos();
		testa_rotina(argv[1]);
		return 0;
	}	// end if
	inicia_trabalhos();
	//char* rotina = "LNNNNNNNLAAAAAAALPPPAAAL";
	//char* rotina = "LNNNPAALALAL";
	//char* rotina = "LNNNNPPPPLAAAAAAAL";
	//char* rotina = "LNNNNPPPPLAAAAAAAPPPPLAAALAL";
	char* rotina = "A";
	testa_rotina(rotina);
	return 0;
}	// end main()


int	testa_rotina(char* servico)
{
	printf("\n\n***** Rotina=[%s] *****\n", servico);
	int n = strlen(servico);
	printf("\nTotal de acoes: %d\n\n", n);
	for (int i = 0; i < n; i++)
	{
		ciclo(servico[i]);
	};	// end for


	int matriz[10];
	matriz[0] = 27102019;
	printf("\nmatriz[0]=%d\n", matriz[0]);

	int* m = &*matriz;
	printf("\n[m = &*matriz] m=%d\n",*m);

	m = &*&*&*&*&*&*&*&*&*&*&*&*&*&*matriz;
	printf("[m = &*&*&*&*&*&*&*&*&*&*&*&*&*&*matriz] m=%d\n", *m);

	return n;
}	// end testa_rotina()

