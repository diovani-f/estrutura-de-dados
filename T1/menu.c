#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lseVoid.h"
#include "turma.h"
#include "menu.h"



Lista* menuAluno(Lista* alunos, int opcao){
    Aluno* j;
    int matricula;
    
    if(opcao == 1){                         //insere

        printf("Digite a matricula do aluno que deseja inserir\n");
        scanf("%d", &matricula);
        j = buscarAluno(alunos, matricula);
        if(j == NULL){
            alunos = inserirFim(alunos, criarAluno(matricula));
        }
        else{
            printf("Ja existe aluno com essa matricula!\n");
        }
    }
    else if(opcao == 2){                    //remove

        printf("Digite a matricula do aluno que deseja remover\n");
        scanf("%d", &matricula);
        j = buscarAluno(alunos, matricula);
        if(j != NULL){
            alunos = retirarAluno(alunos, matricula);
            printf("Aluno removido.\n");
        }
        else{
            printf("Não foi encontrado matricula!\n");
        }
       
        
    }
    else if(opcao == 3){                    //busca

        printf("Digite a matricula do aluno que deseja buscar\n");
        scanf("%d", &matricula);
        j = buscarAluno(alunos, matricula);
        if(j == NULL)
            printf("Aluno não encontrado!\n");
        else{
            printf("-------Aluno Encontrado-------\n");
            imprimirAluno(j);
        }
    }
    else if(opcao == 4){                    ////imprime
        printf("---------Aluno(s)---------\n");
        imprimirAlunos(alunos);
    }
    return alunos;
}

Lista* menuProf(Lista* prof, int opcao){
    Prof* j;
    int codigo;

    if(opcao == 1){                         //insere

        printf("Digite o codigo do professor\n");
        scanf("%d", &codigo);

        j = buscarProf(prof, codigo);
        if(j == NULL){
            prof = inserirFim(prof, criarProf(codigo));
        }
        else{
            printf("Ja existe professor com este codigo!\n");
        }


    }
    else if(opcao == 2){

        printf("Digite o codigo do professor que deseja remover\n");
        scanf("%d", &codigo);
        j = buscarProf(prof, codigo);
        if(j != NULL){
            prof = retirarProf(prof, codigo);
            printf("Professor removido.\n");
        }
        else{
            printf("Não foi encontrado codigo!\n");
        }
        
    }
    else if(opcao == 3){                    //busca

        printf("Digite o codigo do professor que deseja buscar\n");
        scanf("%d", &codigo);
        j = buscarProf(prof, codigo);
        if(j == NULL)
            printf("Professor não encontrado!\n");
        else{
            printf("-------Professor Encontrado-------\n");
            imprimirProf(j);
        }
    }
    else if(opcao == 4){                    ////imprime
        printf("---------Professor(es)---------\n");
        imprimirProfs(prof);
    }
    return prof;
}

Lista* menuDisc(Lista* disc, int opcao){
    int codigo;
    Disc* j;

    if(opcao == 1){                         //insere


        printf("Digite o codigo da disciplina que deseja criar\n");
        scanf("%d", &codigo);
        j = buscarDisc(disc, codigo);
        if(j == NULL){
            disc = inserirFim(disc, criarDisc(codigo));
        }
        else{
            printf("Ja existe disciplina com esse código!\n");
        }

    }
    else if(opcao == 2){
        

        printf("Digite o codigo da disciplina que deseja remover\n");
        scanf("%d", &codigo);
        j = buscarDisc(disc, codigo);
        if(j != NULL){
            disc = retirarDisc(disc, codigo);
            printf("Disciplina removida.\n");
        }
        else{
            printf("Não foi encontrado codigo!\n");
        }
        
    }
    else if(opcao == 3){                    //busca

        printf("Digite o codigo da disciplina que deseja buscar\n");
        scanf("%d", &codigo);
        j = buscarDisc(disc, codigo);
        if(j == NULL)
            printf("Professor não encontrado!\n");
        else{
            printf("-------Professor Encontrado-------\n");
            imprimirDisciplina(j);
        }
    }
    else if(opcao == 4){                    ////imprime
        printf("---------Disciplina(s)---------\n");
        imprimirDisciplinas(disc);
    }
    return disc;
}

Lista* menuTurma(Lista* turmas, Lista* alunos, Lista* prof, int opcao){
    int codigo, cod, matricula;
    Turma* j;
    Aluno* a;
    Prof* p;



    if(opcao == 1){                         //insere

        printf("Digite o codigo da tuma que deseja criar\n");
        scanf("%d", &codigo);
        Turma* j = buscarTurma(turmas, codigo);
        if(j == NULL){
            turmas = inserirFim(turmas, criarTurma(codigo));
        }
        else{
            printf("Ja existe turma com esse codigo!\n");
        }
    }
    else if(opcao == 2){                    //remover

        printf("Digite o codigo da tuma que deseja remover\n");
        scanf("%d", &codigo);
        Turma* j = buscarTurma(turmas, codigo);
        if(j != NULL){
            turmas = retirarTurma(turmas, codigo);
            printf("Disciplina removida.\n");
        }
        else{
            printf("Não foi encontrado codigo!\n");
        }
        
    }   
    else if(opcao == 3){                    //busca

        printf("Digite o codigo da turma que deseja buscar\n");
        scanf("%d", &codigo);

        j = buscarTurma(turmas, codigo);
        if(j == NULL)
            printf("Turma não encontrado!\n");
        else{
            printf("-------Turma Encontrado-------\n");
            imprimirTurma(j);
        }
    }
    else if(opcao == 4){                    //imprime
        printf("---------Turma(s)---------\n");
        imprimirTurmas(turmas);
    }
    else if(opcao == 5){                    //insere aluno

        printf("Digite o codigo da turma para inserir o aluno:");
        scanf("%d", &cod);

        printf("Digite a matricula do aluno para inserir na turma:");
        scanf("%d", &matricula);

        j = buscarTurma(turmas, cod);
        if (j != NULL){
            a = buscarAluno(alunos, matricula);
            if (a != NULL)
                inscrever(j, a);
            else
                printf("Voce digitou uma matricula de aluno inexistente");
	    }
        else
            printf("Voce digitou um codigo de turma inexistente");
    }
    else if (opcao == 6)
    {

        printf("Digite a matricula do aluno que deseja remover da turma:\n");
        scanf("%i", &matricula);

        printf("Digite o codigo da turma qe deseja remover aluno:\\n");
        scanf("%i", &codigo);

        
        j = buscarTurma(turmas, codigo);
        a = buscarAluno(alunos, matricula);
        if(j != NULL || a != NULL){
            desinscrever(j, matricula);	
            printf("Aluno desinscrito com sucesso\n");
        }
        else{
            printf("Matricula ou codigo inexistente\n");
        }
    }
    else if(opcao == 7){                    //insere professor

        printf("Digite o codigo da turma para inserir o professor:");
        scanf("%d", &cod);

        printf("Digite o cod do professor para inserir na turma:");
        scanf("%d", &codigo);


        
        j = buscarTurma(turmas, cod);
        if(j ->prof == NULL){
            if (j != NULL){
                p = buscarProf(prof, codigo);
                if (p != NULL)
                    inscreverProf(j, p);
                else
                    printf("Voce digitou um codigo de professor inexistente");
            }
            else
                printf("Voce digitou um codigo de turma inexistente");
        }
        else{
            printf("Não eh possivel adicionar mais de um professor por turma!!");
        }
    }
    else if (opcao == 8)
    {

        printf("Digite a matricula do aluno que deseja remover da turma:\n");
        scanf("%i", &cod);

        printf("Digite o codigo da turma qe deseja remover aluno:\\n");
        scanf("%i", &codigo);

        
        j = buscarTurma(turmas, codigo);
        p = buscarProf(prof, cod);
        if(j != NULL || p != NULL){
            desinscreverProf(j, cod);	
            printf("Professor desinscrito com sucesso\n");
        }
        else{
            printf("Codigo de profesor ou codigo de turma inexistente\n");
        }
    }
  
    return turmas;
}

void menuPrincipal(){

    Lista* turmas = criar();
    Lista* alunos = criar();
	Lista* profs = criar();
    Lista* disc = criar();


    int opcao=0, opAluno=0, opProf=0, opDisc=0, opTurma=0;

    do{
        printf("Digite em qual campo deseja fazer alteracao ou vizualizar:\n1 - Aluno\n2 - Professor\n3-  Disciplina\n4 - Turma\n5 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            do{
                printf("O que deseja fazer?\n1 - Criar Aluno\n2 - Excluir Aluno\n3 - Buscar Aluno\n4 - Vizualizar todos alunos\n");
                scanf("%d", &opAluno);
            } while (opAluno < 1 || opAluno > 4);
            alunos = menuAluno(alunos, opAluno);
            break;
        case 2:
            do{
                printf("O que deseja fazer?\n1 - Criar Professor\n2 - Excluir Professor\n3 - Buscar Professor\n4 - Vizualizar todos Professores\n");
                scanf("%d", &opProf);
            } while (opProf < 1 || opProf > 4);
            profs = menuProf(profs, opProf);
            break;
        case 3:
            do{
                printf("O que deseja fazer?\n1 - Criar Disciplina\n2 - Excluir Disciplina\n3 - Buscar Disciplina\n4 - Vizualizar todas Disciplinas\n");
                scanf("%d", &opDisc);
            } while (opDisc < 1 || opDisc > 4);
            disc = menuDisc(disc, opDisc);
            break;
        
        case 4:
            do{
                printf("O que deseja fazer?\n1 - Criar Turma\n2 - Excluir Turma\n3 - Buscar Turma\n4 - Vizualizar todas Turmas\n5 - Inserir Aluno\n6 - Remover Aluno\n7 - Inserir Professor\n8 - Remover Professor\n");
                scanf("%d", &opTurma);
            } while (opTurma < 1 || opTurma > 8);
            turmas = menuTurma(turmas, alunos, profs, opTurma);
            break;
        
        
        default:
            break;
        }
    }while(opcao != 5);

    liberar(turmas);
    liberar(alunos);
    liberar(disc);
    liberar(profs);
}