// minha_lista.h
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include	"meu_registro.h"

struct lista
{
	Registro*		r;
	struct lista*	proximo;
};	// Lista

typedef struct lista Lista;

int			apaga_registro( int(*)(Registro*, Registro*), Registro*,  Lista**);
int			da_um_fim_na_lista(	Lista**);
int			insere_ao_final( Registro*, Lista**);
int			insere_na_ordem( int (*)(Registro*, Registro*), Registro*, Lista**);
Registro*   pesquisa_registro( int(*)(Registro*, Registro*), Registro*, Lista**);
int			remove_item( Lista*, Lista**);
int			remove_registro( int(*)(Registro*, Registro*), Registro*, Lista**);

// fim de minha_lista.h