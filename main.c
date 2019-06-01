/*
 * Universidade Federal de São Paulo - Unifesp
 * Instituto de Ciência e Tecnologia - ICT
 * Unidade Curricular de Projeto e Análise de Algoritmos
 *
 * Implementação do Algoritmos de Distância de Levenshtein para diferença entre
 * sequências de DNA.
 *
 * Para comparar as sequências, a ideia é determinar quantas letras devem ser inseridas, removidas ou
 * substituídas, no mínimo, para transformar uma na outra.
 *
 *
 * last version 01 de junho de 2019
 * by Júlia Wotzasek Pereira
 *
 */

// Bibliotecas necessárias
#include <stdio.h>
#include <string.h>

// Contastante para tamaho máximo de strings lidas
#define MAX 1000

// Função auxiliar para o cálculo da distância de Levenshtein, retornando o menor entre três números
int menor(int i1, int i2, int i3){
    int min = (i1 < i2)? i1:i2;
    min = (min < i3)? min:i3;
    return min;
}

int Levenshtein(char* seq1, char* seq2){
    // variáveis auxiliares para o preenchimento da tabela
    int i,j,custo;

    // Cálculo dos tamanhos das strings com auxílio da função strlen() da biblioteca String.h
    int tam1 = strlen(seq1);
    int tam2 = strlen(seq2);

    // Instanciação da tabela de cálculo da distância
    int c[tam1+1][tam2+1];

    // Preenchimento da primeira coluna com os índices das linhas
    for(i = 0; i <= tam1; i++){
        c[i][0] = i;
    }

    // Preenchimento da primeira linha com os índices das colunas
    for(j = 0;j <= tam2;j++){
        c[0][j] = j;
    }

    /* Preenchimento da tabela, linha a linha. Obedece algumas regras:
     *      - Se os elementos comparados são iguais, então não há custo de troca ou substituição;
     *      - Se os elementos forem diferentes, consideramos custo 1 para a substituição.
     *      - Como queremos a menor distância, escolhemos o menor entre o elemento da esquerda, da direita,
     *      ou o próprio com o custo
     */
    for(i = 1; i <= tam1; i++){
        for(j = 1; j <= tam2; j++){
            if(seq1[i - 1] == seq2[j - 1]){
                custo = 0;
            }else{
                custo = 1;
            }
            c[i][j] = menor(c[i-1][j] + 1,c[i][j-1] + 1,c[i-1][j-1] + custo);
        }
    }
    return c[tam1][tam2];
}

int main(){
    // instanciação das strings
    char seq1[MAX + 1];
    char seq2[MAX + 1];

    // leitura das strings da entrada padrão
    scanf("%s",seq1);
    scanf("%s",seq2);

    // impressão da distâcia de Levenshtein entre as strings lidas
    printf("%d",Levenshtein(seq1,seq2));
    return 0;
}