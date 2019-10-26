#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include	"meu_registro_v.h"

struct lista
{
	void*			r;
	struct lista*	proximo;
};	// Lista
typedef struct lista Lista;

int			apaga_registro(int(*)(void*, void*), void*, Lista**);

int			da_um_fim_na_lista(Lista**);

int			insere_ao_final(void*, Lista**);

int			insere_na_ordem(int (*)(void*, void*), void*, Lista**);

void*		pesquisa_registro(int(*)(void*, void*), void*, Lista**);

int			remove_item(Lista*, Lista**);

int			remove_registro(int(*)(void*, void*), void*, Lista**);

// fim de minha_lista.h