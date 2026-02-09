#ifndef ALUNO_H
#define ALUNO_H

#include "linkedlist.h"

// estrutura que representa uma disciplina
typedef struct {
    char nome[100];
    float nota;
    float frequencia;
} Disciplina;

// 
// os alunos serão organizados em uma lista duplamente encadeada
typedef struct Aluno {
    char nome[100];
    int matricula;

    // lista simplesmente encadeada de disciplinas
    LinkedList disciplinas;

    // ponteiros da lista duplamente encadeada de alunos
    struct Aluno* prev;
    struct Aluno* next;
} Aluno;

#endif

