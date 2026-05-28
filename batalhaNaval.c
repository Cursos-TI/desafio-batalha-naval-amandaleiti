#include <stdio.h>

int main() {
    // Desafio Batalha Naval - MateCheck
    // Nivel Mestre - Habilidades especiais e areas de efeito
    // Neste nivel, eu mantenho o tabuleiro 10x10 e adiciono habilidades especiais.
    // 0 = agua
    // 3 = navio
    // 5 = area afetada pela habilidade

    int tabuleiro[10][10];
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    int tamanhoTabuleiro = 10;
    int tamanhoHabilidade = 5;
    int tamanhoNavio = 3;

    // Coordenadas dos navios
    int linhaNavioVertical = 1;
    int colunaNavioVertical = 2;

    int linhaNavioHorizontal = 6;
    int colunaNavioHorizontal = 4;

    int linhaNavioDiagonal1 = 0;
    int colunaNavioDiagonal1 = 0;

    int linhaNavioDiagonal2 = 2;
    int colunaNavioDiagonal2 = 8;

    // Pontos de origem das habilidades no tabuleiro
    int origemConeLinha = 1;
    int origemConeColuna = 5;

    int origemCruzLinha = 5;
    int origemCruzColuna = 2;

    int origemOctaedroLinha = 6;
    int origemOctaedroColuna = 7;

    // Primeiro eu inicializo o tabuleiro com 0.
    // Isso significa que todas as posicoes começam como agua.
    for (int linha = 0; linha < tamanhoTabuleiro; linha++) {
        for (int coluna = 0; coluna < tamanhoTabuleiro; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Aqui eu posiciono o navio vertical.
    // A linha muda e a coluna fica fixa.
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
    }

    // Aqui eu posiciono o navio horizontal.
    // A coluna muda e a linha fica fixa.
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
    }

    // Aqui eu posiciono o primeiro navio diagonal.
    // A linha e a coluna aumentam juntas.
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavioDiagonal1 + i][colunaNavioDiagonal1 + i] = 3;
    }

    // Aqui eu posiciono o segundo navio diagonal.
    // A linha aumenta e a coluna diminui.
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavioDiagonal2 + i][colunaNavioDiagonal2 - i] = 3;
    }

    // Aqui eu crio a matriz da habilidade Cone.
    // O cone começa pequeno em cima e aumenta para baixo.
    for (int linha = 0; linha < tamanhoHabilidade; linha++) {
        for (int coluna = 0; coluna < tamanhoHabilidade; coluna++) {
            if (coluna >= 2 - linha && coluna <= 2 + linha) {
                cone[linha][coluna] = 1;
            } else {
                cone[linha][coluna] = 0;
            }
        }
    }

    // Aqui eu crio a matriz da habilidade Cruz.
    // A linha do meio e a coluna do meio recebem 1.
    for (int linha = 0; linha < tamanhoHabilidade; linha++) {
        for (int coluna = 0; coluna < tamanhoHabilidade; coluna++) {
            if (linha == 2 || coluna == 2) {
                cruz[linha][coluna] = 1;
            } else {
                cruz[linha][coluna] = 0;
            }
        }
    }

    // Aqui eu crio a matriz da habilidade Octaedro.
    // O formato fica parecido com um losango.
    for (int linha = 0; linha < tamanhoHabilidade; linha++) {
        for (int coluna = 0; coluna < tamanhoHabilidade; coluna++) {
            if ((linha == 0 && coluna == 2) ||
                (linha == 1 && coluna >= 1 && coluna <= 3) ||
                (linha == 2 && coluna >= 0 && coluna <= 4) ||
                (linha == 3 && coluna >= 1 && coluna <= 3) ||
                (linha == 4 && coluna == 2)) {
                octaedro[linha][coluna] = 1;
            } else {
                octaedro[linha][coluna] = 0;
            }
        }
    }

    // Aqui eu aplico a habilidade Cone no tabuleiro.
    // Quando a matriz cone tiver valor 1, eu marco 5 no tabuleiro.
    for (int linha = 0; linha < tamanhoHabilidade; linha++) {
        for (int coluna = 0; coluna < tamanhoHabilidade; coluna++) {
            int linhaTabuleiro = origemConeLinha + linha;
            int colunaTabuleiro = origemConeColuna + coluna - 2;

            if (cone[linha][coluna] == 1 &&
                linhaTabuleiro >= 0 && linhaTabuleiro < tamanhoTabuleiro &&
                colunaTabuleiro >= 0 && colunaTabuleiro < tamanhoTabuleiro &&
                tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
            }
        }
    }

    // Aqui eu aplico a habilidade Cruz no tabuleiro.
    // A habilidade so marca a posicao se ela estiver dentro do tabuleiro e ainda for agua.
    for (int linha = 0; linha < tamanhoHabilidade; linha++) {
        for (int coluna = 0; coluna < tamanhoHabilidade; coluna++) {
            int linhaTabuleiro = origemCruzLinha + linha - 2;
            int colunaTabuleiro = origemCruzColuna + coluna - 2;

            if (cruz[linha][coluna] == 1 &&
                linhaTabuleiro >= 0 && linhaTabuleiro < tamanhoTabuleiro &&
                colunaTabuleiro >= 0 && colunaTabuleiro < tamanhoTabuleiro &&
                tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
            }
        }
    }

    // Aqui eu aplico a habilidade Octaedro no tabuleiro.
    // O valor 5 representa a area atingida pela habilidade.
    for (int linha = 0; linha < tamanhoHabilidade; linha++) {
        for (int coluna = 0; coluna < tamanhoHabilidade; coluna++) {
            int linhaTabuleiro = origemOctaedroLinha + linha - 2;
            int colunaTabuleiro = origemOctaedroColuna + coluna - 2;

            if (octaedro[linha][coluna] == 1 &&
                linhaTabuleiro >= 0 && linhaTabuleiro < tamanhoTabuleiro &&
                colunaTabuleiro >= 0 && colunaTabuleiro < tamanhoTabuleiro &&
                tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
            }
        }
    }

    // Exibicao da matriz Cone
    printf("===== Habilidade Cone =====\n");
    for (int linha = 0; linha < tamanhoHabilidade; linha++) {
        for (int coluna = 0; coluna < tamanhoHabilidade; coluna++) {
            printf("%d ", cone[linha][coluna]);
        }
        printf("\n");
    }

    printf("\n");

    // Exibicao da matriz Cruz
    printf("===== Habilidade Cruz =====\n");
    for (int linha = 0; linha < tamanhoHabilidade; linha++) {
        for (int coluna = 0; coluna < tamanhoHabilidade; coluna++) {
            printf("%d ", cruz[linha][coluna]);
        }
        printf("\n");
    }

    printf("\n");

    // Exibicao da matriz Octaedro
    printf("===== Habilidade Octaedro =====\n");
    for (int linha = 0; linha < tamanhoHabilidade; linha++) {
        for (int coluna = 0; coluna < tamanhoHabilidade; coluna++) {
            printf("%d ", octaedro[linha][coluna]);
        }
        printf("\n");
    }

    printf("\n");

    // Aqui eu mostro o tabuleiro completo com navios e areas de habilidade.
    printf("===== Tabuleiro com Navios e Habilidades =====\n");
    printf("0 = Agua | 3 = Navio | 5 = Area afetada\n\n");

    for (int linha = 0; linha < tamanhoTabuleiro; linha++) {
        for (int coluna = 0; coluna < tamanhoTabuleiro; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}