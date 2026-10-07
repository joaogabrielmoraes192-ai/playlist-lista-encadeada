#ifndef LISTA_H
#define LISTA_H

#include "musica.h"

typedef struct lista *Lista;

Lista criar_lista();
int inserir_inicio(Lista li, Musica m);
int inserir_final(Lista li, Musica m);
int inserir_posicao(Lista li, int pos, Musica m);
int remover_inicio(Lista li);
int remover_final(Lista li);
int remover_posicao(Lista li, int pos);
int acessar_inicio(Lista li, Musica *m);
int acessar_posicao(Lista li, int pos, Musica *m);
int quantidade(Lista li);
void destruir(Lista li);

#endif
