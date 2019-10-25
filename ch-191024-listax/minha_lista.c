#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include	"memory.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include    "malloc.h"
#include	"minha_lista.h"


int			apaga_registro(int(*criterio)(Registro*, Registro*), Registro* exemplo, Lista** pLista)
{
	Lista* lista = *pLista;
	// a ideia aqui nao e nada original: e igual ao caso do sort por
	// exemplo em muitas linguagens, como C C++ e java. O usuario
	// fornece a funcao que retorna 1 se o registro obedece ao criterio
	// e a rotina apaga o primeiro registro que satisfaz o criterio
	// pesquisando ate o fim da lista. Se apagou retorna 1 se nao 
	// apagou retorna zero
	//printf("***** apaga_registro()\n");
	if (lista == NULL)		return -1;	// nao iniciada
	if (lista->r == NULL)	return 0;	// vazia 
	Lista* p = lista;					// aponta para o inicio
	int n = 0;							// se estivesse vazio ja teria retornado 0
	do
	{
		//printf(
		//	"    %4d: nome:'%s' sobrenome:'%s' RG: %d\n",
		//	n, p->r->nome, p->r->sobrenome, p->r->RG);
		if ( criterio( (p->r), exemplo) )
			return remove_item(p, pLista);	// chama a funcao que remove a chave p
		p = p->proximo;
	} while (p != NULL);
	printf("\n");						// sim, uma linha em branco
	return 0;
}	// end apaga_registro()


int			da_um_fim_na_lista(Lista** lista)
{
	int		n = 0;					// conta os itens apagados
	Lista*		p = *lista;
	Lista*		proximo;

	if ((lista == NULL) || (p == NULL))	return -1;	// nao existe lista
	if (p->r == NULL)
	{
		free(*lista);
		return 0;
	}	// end if

	do  // a lista existe e nao esta vazia
	{	// apaga um por um	
		proximo = p->proximo;		// salva 
		free((void*)(p->r));		// apaga o registro correspondente a esse item
		free((void*)p);				// apaga o item da lista
		p = proximo;				// vai pro proximo
		n = n + 1;					// conta esse como apagado
	} while (p != NULL);			// e continua ate apagar tudo
	*lista = NULL;					// invalida o ponteiro original afinal liberou tudo
	return n;
}	// end da_um_fim_na_lista()


int			insere_ao_final(Registro* r, Lista** ppLista)
{
	if (ppLista == NULL) return -1;
	// essa funcao insere sempre no final da lista
	Lista* node = (Lista*)malloc(sizeof(Lista));	// aloca o item
	node->r = (Registro*)malloc(sizeof(Registro));
	memcpy( node->r, r, sizeof(Registro));
	node->proximo = NULL;
	if ( *ppLista == NULL)
	{	// no inicio: insere o primeiro
		*ppLista = node;	// novo inicio da lista
		return 1;
	}	// end if
	// lista ja iniciada entao
	Lista* p = *ppLista;
	while (p->proximo != NULL) p = p->proximo;
	p->proximo = node;		// o anterior agora aponta para esse
	return 1;
}	// end insere_registro()


int insere_na_ordem(int(*criterio)(Registro*, Registro*), Registro* novo, Lista** ppLista)
{
	// usando a funcao fornecida, insere o registro na ordem
	if (ppLista == NULL) return -1;
	Lista* node = (Lista*)malloc(sizeof(Lista));	// cria o elemento na lista
	node->r =	(Registro*)malloc(sizeof(Registro));	// cria o registro
	memcpy(node->r, novo, sizeof(Registro));		// copia os dados
	node->proximo = NULL;
	if (*ppLista == NULL)
	{	// no inicio: insere o primeiro, facil
		*ppLista = node;	// novo inicio da lista
		return 1;
	}	// end if
	//
	// a lista nao esta vazia: procura o posicao
	//
	Lista*	p = *ppLista;
	Lista*	anterior = NULL;
	//
	while( 1 )
	{
		if (criterio(p->r, novo) <= 0)
		{
			// ainda nao, vai seguir
			if (p->proximo == NULL)
			{
				// vai inserir no final
				p->proximo = node;
				return 1;
			}
			anterior = p;
			p = p->proximo;	// adiante entao
			continue;
		}
		// esse e o ponto de insercao
		if (anterior == NULL)
		{
			*ppLista = node;	// nova origem
			node->proximo = p;
		}
		else
		{
			anterior->proximo = node;
			node->proximo = p;
		}
		return 1;
	};	// end while
	
	p->proximo = node;		// o anterior agora aponta para esse
	return 1;
	return 0;
}


Registro*	pesquisa_registro(int(*criterio)(Registro*, Registro*), Registro* exemplo,  Lista** pLista)
{
	Lista* lista = *pLista;
	// pesquisar e como apagar, apenas ao localizar ao inves
	// de apagar devolve o endereco
	if (lista == NULL)		return -1;	// nao iniciada
	if (lista->r == NULL)	return 0;	// vazia 
	Lista* p = lista;					// aponta para o inicio
	int n = 0;							// se estivesse vazio ja teria retornado 0
	do
	{	// se enontrou retorna o endereco. so isso
		if (criterio( (p->r), exemplo))	return p->r;
		p = p->proximo;
	} while (p != NULL);
	return NULL;						// nao achou afinal
}


int			remove_item(Lista* item, Lista** lista)
{	// remove item da lista. Assume que ele esta na lista
	Lista* p = *lista;				// usa o ponteiro recebido
	if (item == p)
	{	// vai remover o primeiro. pode ser o unico
		if (p->proximo == NULL)
		{	// era o unico:
			*lista = NULL;			// invalida o ponterio da lista
		}
		else
		{	// primeiro mais tinha outros
			*lista = p->proximo;	// era o segundo agora e o primeiro
		}
		free(p->r);					// ja era de qualquer jeito o registro
		free(p);
		return 1;
	}	// end if
	Lista* anterior = p;			// anterior ao segundo: o primeiro
	p = p->proximo;					// aponta para o segundo entao
	// vai remover do segundo pra frente entao todos os itens tem um antecessor
	// e apenas o ultimo nao tem um proximo item
	do
	{
		if (item == p)
		{
			// vai apagar p
			anterior->proximo = p->proximo;
			free(p->r);				// remove o registro
			free(p);				// apaga afinal
			return 1;
		}
		else
		{
			anterior = p;			// salva o valor
			p = p->proximo;			// continua procurando
		}
	} while (p != NULL);
	// remove_item() foi chamada a partir de um criterio confirmado pelo 
	// usuario entao nao pode acontecer de nao ser encontrado: erro de logica
	return -1;
};	// end remove_item()


int			remove_registro(int(*criterio)(Registro*, Registro*), Registro* exemplo, Lista** pLista)
{
	Lista* lista = *pLista;
	// para remover fazemos uma esquisa pelo endereco do registro e 
	// chamamos remove_item() com o endereco do item na lista
	if (lista == NULL)		return -1;	// nao iniciada
	if (lista->r == NULL)	return 0;	// vazia 
	Lista* p = lista;					// aponta para o inicio
	int n = 0;							// se estivesse vazio ja teria retornado 0
	do
	{	// se enontrou retorna o endereco. so isso
		if (criterio((p->r), exemplo))
		{	// esse e o cara
			remove_item(p, pLista);
			return 1;
		}
		p = p->proximo;
	} while (p != NULL);
	return -1;							// nao achou pra remover
}


