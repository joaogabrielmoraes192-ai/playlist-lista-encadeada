#ifndef MUSICA_H
#define MUSICA_H

typedef struct musica *Musica;

Musica criar_musica(char titulo[], char artista[], int duracao);
char *get_titulo(Musica m);
char *get_artista(Musica m);
int get_duracao(Musica m);
void imprimir_musica(Musica m);
void destruir_musica(Musica m);

#endif
