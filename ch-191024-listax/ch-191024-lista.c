#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include	"memory.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include    "malloc.h"
#include	"minha_lista.h"


int			busca_por_RG(Registro*, Registro*);
int			compare_RG(Registro*, Registro*);
int			insere_via_3_campos(char[], char[], int, Lista**);
int			mostra_lista( Lista*);
int			mostra_um(Registro*);


int		a_teste1()
{
	// cria a lista com um item e apaga em seguida
	Lista* pLista = NULL;			// um ponteiro para a lista	
	int			n;
	const int	tamanho_do_teste = 1;	// teste com esse total de itens
	// monta um registro padrao, "Jhonny Cash", RG = 1..n
	char* nome_teste = "Johnny";
	char* sobrenome_teste = "Cash";
	int			rg = 1;
	// cria um
	n = mostra_lista(pLista);			// NULL
	printf("mostra_lista(com zero) retornou %d para lista vazia\n\n", n);
	n = insere_via_3_campos(nome_teste, sobrenome_teste, rg, &pLista);	// insere
	// mostra um
	n = mostra_lista(pLista);				// vazia
	printf("mostra_lista(depois de tentar inserir %d): retornou %d\n", tamanho_do_teste, n);
	// agora tenta apagar o unico
	printf("remove o primeiro\n");
	Registro	a_apagar;
	a_apagar.RG = 1;
	apaga_registro(busca_por_RG, &a_apagar, &pLista);

	// mostra: deve estar vazia
	n = mostra_lista(pLista);				// vazia
	printf("mostra_lista(%d): retornou %d\n", tamanho_do_teste, n);

	// agora da um fim na lista
	n = da_um_fim_na_lista(&pLista);		// pense nisso: importante
	printf("da_um_fim_na_lista(): apagou %d itens\n", n);

	return 0;
}	// end a_teste1()


int		a_teste_na_ordem_A(int tamanho_do_teste)
{
	Lista* pLista = NULL;			// um ponteiro para a lista	
	int		n;
	char* nome_teste = "Johnny";
	char* sobrenome_teste = "Cash";
	int		rg = tamanho_do_teste;

	Registro	 r;
	strcpy(r.nome, nome_teste);
	strcpy(r.sobrenome, sobrenome_teste);

	for (int i = 1; i <= tamanho_do_teste; i++)
	{
		r.RG = i;
		printf("    RG = %d\n", r.RG);
		insere_na_ordem(compare_RG, &r, &pLista);
	}
	n = mostra_lista(pLista);			// NULL
	printf("mostra_lista() retornou %d\n", n);
	n = da_um_fim_na_lista(&pLista);

	return 0;
}


int		a_teste_na_ordem_D(int tamanho_do_teste)
{
	Lista* pLista = NULL;			// um ponteiro para a lista	
	int		n;
	char* nome_teste = "Johnny";
	char* sobrenome_teste = "Cash";
	int		rg = tamanho_do_teste;

	Registro	 r;
	strcpy(r.nome, nome_teste);
	strcpy(r.sobrenome, sobrenome_teste);

	for (int i = tamanho_do_teste; i>0; i--)
	{
		r.RG = i;
		printf("    RG = %d\n", r.RG);
		insere_na_ordem(compare_RG, &r, &pLista);
	}
	n = mostra_lista(pLista);			// NULL
	printf("mostra_lista() retornou %d\n", n);
	n = da_um_fim_na_lista(&pLista);

	return 0;
}


int		a_teste_na_ordem_R(int tamanho_do_teste)
{
	Lista* pLista = NULL;			// um ponteiro para a lista	
	int		n;
	char* nome_teste = "Johnny";
	char* sobrenome_teste = "Cash";
	int		rg = tamanho_do_teste;

	Registro	 r;
	strcpy(r.nome, nome_teste);
	strcpy(r.sobrenome, sobrenome_teste);

	for (int i = rg; i > 0; i--)
	{
		r.RG = 1 + rand() % 100;
		printf("    RG = %d\n", r.RG);
		strcpy(r.sobrenome, sobrenome_teste);
		insere_na_ordem(compare_RG, &r, &pLista);
		strcpy(r.sobrenome, "Winter");
		insere_na_ordem(compare_RG, &r, &pLista);
	}
	n = mostra_lista(pLista);			// NULL
	printf("mostra_lista() retornou %d\n", n);
	n = da_um_fim_na_lista(&pLista);
	printf("da_um_fim_na_lista() retornou %d\n", n);

	return 0;
}


int		a_teste_n(const int tamanho_do_teste)
{	
	// 
	// esse teste
	//    cria n registros
	//    apaga o primeiro
	//	  apaga o ultimo
	//    apaga todos os outros
	//	  apaga a lista
	//
	Lista* pLista = NULL;			// um ponteiro para a lista	
	int			n;
	// monta um registro padrao, "Jhonny Cash", RG = 1..n
	char* nome_teste = "Johnny";
	char* sobrenome_teste = "Cash";
	int			rg = 1;

	n = mostra_lista(pLista);			// NULL
	printf("mostra_lista(vazia) retornou %d para lista vazia\n\n", n);

	printf("***** Vai inserir %d registros\n", tamanho_do_teste);
	for (int i = 0; i < tamanho_do_teste; i += 1, rg += 1)
		n = insere_via_3_campos(nome_teste, sobrenome_teste, rg, &pLista);	// insere
	printf("***** %d registros inseridos\n", tamanho_do_teste);
		n = mostra_lista(pLista);				// vazia
	printf("mostra_lista(depois de tentar inserir %d): retornou %d\n", tamanho_do_teste, n);
	// criou e mostrou os n registros

	// agora tenta apagar o primeiro
	printf("    remove o primeiro\n");
	Registro	a_apagar;
	a_apagar.RG = 1;
	apaga_registro(busca_por_RG, &a_apagar, &pLista);
	n = mostra_lista(pLista);				// vazia
	printf("mostra_lista() retornou %d\n\n", n);

	// agora tenta apagar o ultimo
	printf("    remove o ultimo\n");
	a_apagar.RG = tamanho_do_teste;
	apaga_registro(busca_por_RG, &a_apagar, &pLista);
	n = mostra_lista(pLista);				// vazia
	printf("mostra_lista() retornou %d\n\n", n);

	// agora tenta apagar no meio deles
	a_apagar.RG = tamanho_do_teste / 2;
	printf("vai tentar remover RG=%d\n", a_apagar.RG);
	apaga_registro(busca_por_RG, &a_apagar, &pLista);
	n = mostra_lista(pLista);				// vazia
	printf("mostra_lista() retornou %d\n\n", n);

	// agora aponta para o inicio e apaga um por um
	while (pLista != NULL)
	{
		// lista nao esta vazia: apaga o proximo
		a_apagar.RG = pLista->r->RG;
		printf("Apagando RG=%d\n", a_apagar.RG);
		apaga_registro(busca_por_RG, &a_apagar, &pLista);
	};
	printf("Ao final deve estar vazia a lista\n");
	n = mostra_lista(pLista);				// vazia
	printf("mostra_lista() retornou %d\n\n", n);

	return 0;
}	// end a_teste_n()


int		a_teste_pesquisa(int busca, int tamanho_do_teste)
{
	int			n;
	char*		nome_teste = "Johnny";
	char*		sobrenome_teste = "Cash";
	Lista*		pLista = NULL;
	int			rg = 1;
	for (int i = 0; i < tamanho_do_teste; i += 1, rg += 1)
		n = insere_via_3_campos(nome_teste, sobrenome_teste, rg, &pLista);	// insere
	n = mostra_lista(pLista);				// vazia
	// criou e mostrou os n registros
	printf("Buscando registro com RG = %d\n", busca);
	Registro	procurado;
	procurado.RG = busca;
	Registro* p = pesquisa_registro(busca_por_RG, &procurado, &pLista);
	if (p == NULL)
	{
		printf("    RG nao encontrado\n");
	}
	else
	{
		printf("    registro  LOCALIZADO!\n");
		mostra_um(p);
	}	// end if
	da_um_fim_na_lista(&pLista);
	return 0;
}




int		a_teste_remove(int tamanho_do_teste)
{
	Lista* pLista = NULL;
	int		n;
	char* nome_teste = "Johnny";
	char* sobrenome_teste = "Cash";
	int		rg = tamanho_do_teste;

	Registro	 r;
	strcpy(r.nome, nome_teste);
	strcpy(r.sobrenome, sobrenome_teste);

	for (int i = 1; i <= tamanho_do_teste; i++)
	{
		r.RG = i;
		insere_na_ordem(compare_RG, &r, &pLista);
	}
	n = mostra_lista(pLista);			// NULL
	printf("mostra_lista() retornou %d\n", n);

	printf("\nTentando remover um a um:\n\n");
	// criou todos agora remove um a um pelo RG
	for (int i = 1; i <= tamanho_do_teste; i++)
	{
		r.RG = i;
		n = remove_registro(busca_por_RG, &r, &pLista);
		printf("remove_registro(%d) retornou %d\n", i, n);
	}
	n = mostra_lista(pLista);			// NULL
	printf("mostra_lista() retornou %d\n", n);
	n = da_um_fim_na_lista(&pLista);
	printf("da_um_fim_na_lista() retornou %d\n", n);

	return 0;
}	// end a_teste_remove()


int		main(int argc, char** argv)
{
	//a_teste1();
	//a_teste_n(10);
	//a_teste_pesquisa(1, 10);
	//a_teste_pesquisa(6, 10);
	//a_teste_pesquisa(10, 10);
	//a_teste_pesquisa(1000, 10);
	//a_teste_na_ordem_A(15);
	//a_teste_na_ordem_D(15);
	//a_teste_na_ordem_R(15);
	a_teste_remove(15);
	return  0;
}	// end main()


int			busca_por_RG(Registro* r, Registro* criterio)
{
	return(criterio->RG == r->RG);
}	// end ve_se_apaga_por_RG()


int			compare_RG(Registro* A, Registro* B)
{
	return (A->RG - B->RG);
}	// end compare_RG()


int			insere_via_3_campos(char nome[], char sobrenome[], int RG, Lista** pLista)
{
	int n;
	//printf(
	//	"***** insere_via_3_campos('%s' '%s' [RG %d])\n",
	//	nome, sobrenome, RG
	//);
	// monta a estrutura
	Registro	 r;	// cria um registro
	strcpy(r.nome, nome);
	strcpy(r.sobrenome, sobrenome);
	r.RG = RG;
	n = insere_ao_final(&r, pLista);
	return n;
}	// end insere_3_campos()


int			mostra_lista( Lista* pLista)
{
	Lista*		lista = pLista;
	printf("\n***** mostra_lista()\n\n");

	if (lista == NULL)		return -1;	// nao iniciada
	if (lista->r == NULL)	return -2;	// erro de logica
	Lista* p = lista;					// aponta para o inicio
	int n = 0;							// se estivesse vazio ja teria retornado 0
	do
	{
		n = n + 1;
		mostra_um(p->r);
		p = p->proximo;
	} while (p != NULL);
	printf("\n");						// sim, uma linha em branco
	return n;
}	// end mostra_lista()


int			mostra_um(Registro* r)
{
	printf(
		"nome:'%s' sobrenome:'%s' RG: %d\n",
		r->nome, r->sobrenome, r->RG);
	return 0;
}
