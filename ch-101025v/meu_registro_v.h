#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include	"memory.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include    "malloc.h"

struct registro
{
	int		CPF;
	int		RG;
	char	CEP[9];
	char	nome[20];
	char	sobrenome[20];
};

typedef struct registro Registro;

// fim de meu_registro_v.h
