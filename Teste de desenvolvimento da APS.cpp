/*
	Nome: Sistema de Gerenciamento de Aluno
	Inicio: 18/05/2020 16:37
	Término: 24/05/2020 19:34
Autores:
	Felipe Silva Joaquim | RA: 3333294	 
	Guilherme Mandeli Fernandes Camacho | RA: 3210023
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale>
#define MAX 4

//     ----------------8<-------------[ Corte Aqui ]------------------

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3, media;
};

typedef struct fila Fila;

//     ----------------8<-------------[ Corte Aqui ]------------------

struct fila{
    int inicio, final, qtd;
    struct aluno dados[MAX];
};

//     ----------------8<-------------[ Corte Aqui ]------------------

Fila* cria_Fila();
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);

//     ----------------8<-------------[ Corte Aqui ]------------------

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	system("cls");
	
	struct aluno al,a[4] = {{2,"Rennan",9.5,7.8,8.5},
                        {4,"Carol",7.5,8.7,6.8},
                         {1,"Guilherme",9.7,6.7,8.4},
                         {3,"Arthur",5.7,6.1,7.4}};
	Fila* fi = cria_Fila();
	int opcao;
    int i;
    
    printf("1. Ver lista de Alunos\n");
    printf("Escolha uma opção: \n");
    scanf("%d", &opcao);
    
    
	switch(opcao){
		
		case 0:
			system("pause");
    		return 0;
			break;
		
		case 1:
			for(i=0; i < 4; i++){
        		insere_Fila(fi,a[i]);
        		consulta_Fila(fi,&al);
    		}
    		imprime_Fila(fi);
    		printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
			break;
		
		default:
			printf("\nOpção inválida. Digite novamente.\n\n");
			system("pause");
			main();
	}
}

//     ----------------8<-------------[ Corte Aqui ]------------------

Fila* cria_Fila(){
    Fila *fi;
    fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    *al = fi->dados[fi->inicio];
    return 1;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    if(Fila_cheia(fi))
        return 0;
    fi->dados[fi->final] = al;
    fi->final = (fi->final+1)%MAX;
    fi->qtd++;
    return 1;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return -1;
    return fi->qtd;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int Fila_cheia(Fila* fi){
    if(fi == NULL)
        return -1;
    if (fi->qtd == MAX)
        return 1;
    else
        return 0;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return -1;
    if (fi->qtd == 0)
        return 1;
    else
        return 0;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    int n, i = fi->inicio;
    for(n=0; n < fi->qtd; n++){
        printf("Matricula: %d\n",fi->dados[i].matricula);
        printf("Nome: %s\n",fi->dados[i].nome);
        printf("Notas: %.2f %.2f %.2f\n",fi->dados[i].n1,
                                   fi->dados[i].n2,
                                   fi->dados[i].n3);
        printf("-------------------------------\n");
        i = (i + 1) % MAX;
    }
    
    printf("\n\n");
    system("pause");
    main();
}
