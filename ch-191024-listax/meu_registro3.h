#pragma once
// meu_registro2.h
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include	"memory.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include    "malloc.h"


struct item_de_compra
{
	char	codigo[20];
	char	descricao[40];
	int		quantidade;
	char	unidade[10];
	float	valor;
};
typedef struct item_de_compra Item;


struct registro
{
	int		n_caixa;
	int		n_ticket;
	time_t	hora_da_compra;
	int		n_itens;


};
typedef struct registro Registro;

// fim de meu_registro2.h
