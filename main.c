#include <stdio.h>
#include "musica.h"
#include "lista.h"

int adiciona_musica(Lista playlist, Musica m) {
    return inserir_final(playlist, m);
}

int adiciona_musica_posicao(Lista playlist, int pos, Musica m, int *proxima) {
    if (!inserir_posicao(playlist, pos, m))
        return 0;
    if (pos < *proxima)
        (*proxima)++;
    return 1;
}

int remove_musica(Lista playlist, int pos, int *proxima) {
    if (!remover_posicao(playlist, pos))
        return 0;
    if (pos < *proxima)
        (*proxima)--;
    return 1;
}

void tempo_restante(Lista playlist, int proxima) {
    int total = 0;
    int i;
    Musica m;
    for (i = proxima; i < quantidade(playlist); i++) {
        acessar_posicao(playlist, i, &m);
        total += get_duracao(m);
    }
    printf("Tempo restante: %d:%02d\n", total / 60, total % 60);
}

int play(Lista playlist, int *proxima) {
    Musica m;
    if (!acessar_posicao(playlist, *proxima, &m)) {
        printf("A playlist acabou\n");
        return 0;
    }
    printf("Tocando: ");
    imprimir_musica(m);
    (*proxima)++;
    return 1;
}

void musicas_reproduzidas(int proxima) {
    printf("Musicas reproduzidas: %d\n", proxima);
}

int main() {
    Lista playlist = criar_lista();
    int proxima = 0;

    Musica m1 = criar_musica("Garota de Ipanema", "Tom Jobim", 185);
    Musica m2 = criar_musica("Asa Branca", "Luiz Gonzaga", 170);
    Musica m3 = criar_musica("Aquarela", "Toquinho", 240);
    Musica m4 = criar_musica("Preta Pretinha", "Novos Baianos", 215);
    Musica m5 = criar_musica("Mulher Rendeira", "Lampiao", 150);
    Musica m6 = criar_musica("Wave", "Tom Jobim", 195);
    Musica m7 = criar_musica("Sampa", "Caetano Veloso", 220);
    Musica m8 = criar_musica("Chega de Saudade", "Joao Gilberto", 130);
    Musica m9 = criar_musica("Travessia", "Milton Nascimento", 230);
    Musica m10 = criar_musica("Pais e Filhos", "Legiao Urbana", 305);

    adiciona_musica(playlist, m1);
    adiciona_musica(playlist, m2);
    adiciona_musica(playlist, m3);
    adiciona_musica(playlist, m4);
    adiciona_musica(playlist, m5);
    adiciona_musica(playlist, m6);
    adiciona_musica(playlist, m7);
    adiciona_musica(playlist, m8);
    adiciona_musica_posicao(playlist, 2, m9, &proxima);
    adiciona_musica_posicao(playlist, 0, m10, &proxima);

    printf("Musicas na playlist: %d\n", quantidade(playlist));
    tempo_restante(playlist, proxima);

    printf("\n");
    play(playlist, &proxima);
    play(playlist, &proxima);
    play(playlist, &proxima);
    play(playlist, &proxima);
    musicas_reproduzidas(proxima);
    tempo_restante(playlist, proxima);

    printf("\n");
    remove_musica(playlist, 1, &proxima);
    printf("Removida a musica da posicao 1\n");
    remove_musica(playlist, 6, &proxima);
    printf("Removida a musica da posicao 6\n");
    tempo_restante(playlist, proxima);

    printf("\n");
    while (play(playlist, &proxima));

    printf("\n");
    printf("Quantidade de musicas na playlist: %d\n", quantidade(playlist));
    printf("Posicao da proxima musica: %d\n", proxima);

    destruir(playlist);
    return 0;
}
