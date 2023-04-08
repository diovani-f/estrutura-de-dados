#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lseVoid.h"
#include "turma.h"
#include "menu.h"


// Mostra na tela os dados
void imprimirAluno(void* aluno){
	printf("Matricula:%i\nNome:%sCurso:%s\n", ((Aluno*) aluno)->matricula, ((Aluno*) aluno)->nome, ((Aluno*) aluno)->curso);	
}
void imprimirProf(void* prof){
	printf("Codigo:%i\nNome:%s\n", ((Prof*) prof)->codigo, ((Prof*) prof)->nome);	
}
void imprimirDisciplina(void* disc){
	printf("Codigo:%i\nNome:%s\nCarga Horario:%f\nCurso:%s\n------------------\n", ((Disc*) disc)->codigo, ((Disc*) disc)->nome,((Disc*)disc)->cargaH,((Disc*)disc)->curso);	
}
void imprimirTurma(void* turma){
	Turma* t = (Turma*) turma;
	printf("----------------------------\n");
	printf("Codigo:%d\n", t->codigo);
   printf("-----Professor da Turma-----\n");
   imprimirProfs(t->prof);
	printf("-----Alunos da Turma--------\n");
   imprimirAlunos(t->alunos);
	printf("----------------------------\n");
}


// Compara a igualdade 
bool turmasIguais(void* turma1, void* turma2){
	return ((Turma*) turma1)->codigo == ((Turma*) turma2)->codigo;
}
bool alunosIguais(void* aluno1, void* aluno2){
	return ((Aluno*) aluno1)->matricula == ((Aluno*) aluno2)->matricula;
}
bool profsIguais(void* prof1, void* prof2){
	return ((Prof*) prof1)->codigo == ((Prof*) prof2)->codigo;
}
bool DiscIguais(void* disc1, void* disc2){
	return ((Disc*) disc1)->codigo == ((Disc*) disc2)->codigo;
}



// Cria um turma
Turma* criarTurmaPK(int codigo){
  	Turma* t = (Turma*) malloc(sizeof(Turma));
	t->codigo = codigo;
	t->alunos = criar();
   t->prof = NULL;
	return t;
}
Turma* criarTurma(int codigo){

   Turma* t;
   
   t = criarTurmaPK(codigo);
   printf("Turma criada com sucesso!!\n");
   return t;
   
}



// Cria um aluno
Aluno* criarAlunoPK(int matricula){
  	Aluno* j = (Aluno*) malloc(sizeof(Aluno));
	j->matricula = matricula;
	return j;
}
Aluno* criarAluno(int matricula){

	char nome[50], curso[50];
   Aluno* j;


	fflush(stdin);
    printf("Digite o nome do aluno:\n");
    fgets(nome, 30, stdin);

	fflush(stdin);
    printf("Digite o curso do aluno:\n");
    fgets(curso, 30, stdin);

   j = criarAlunoPK(matricula);
   strcpy(j->curso, curso);
   strcpy(j->nome, nome);
   printf("Aluno criado com sucesso!\n");
   return j;

}

// Cria um Prof
Prof* criarProfPK(int codigo){
  	Prof* j = (Prof*) malloc(sizeof(Prof));
	j->codigo = codigo;
	return j;
}
Prof* criarProf(int codigo){

	char nome[50];
   Prof* j;


	fflush(stdin);
   printf("Digite o nome do professor:\n");
   fgets(nome, 30, stdin);

   j = criarProfPK(codigo);
   strcpy(j->nome, nome);
   printf("Professor criado com sucesso.\n");
   return j;
}


// Cria um disciplina
Disc* criarDiscPK(int codigo){
  	Disc* j = (Disc*) malloc(sizeof(Disc));
	j->codigo = codigo;
	return j;
}
Disc* criarDisc(int codigo){

   Disc* j;
   float cargaH;
	char nome[50], curso[50];


	fflush(stdin);
   printf("Digite o nome da disciplina:\n");
   fgets(nome, 30, stdin);

   fflush(stdin);
   printf("Digite o curso da disciplina:\n");
   fgets(curso, 30, stdin);

   printf("Digite a carga horaria da discilina:\n");
   scanf("%f", &cargaH);

   
   j = criarDiscPK(codigo);
   strcpy(j->nome, nome);
   strcpy(j->curso, curso);
   j->cargaH = cargaH;
   printf("Disciplina criada com sucesso!!");
   return j;

}



// Busca um aluno/prof/disciplina/turma pelo codigo
Aluno* buscarAluno(Lista* alunos, int inscricao){
   return (Aluno*) buscar(alunos, criarAlunoPK(inscricao), &alunosIguais);
}
Disc* buscarDisc(Lista* disc, int inscricao){
   return (Disc*) buscar(disc, criarDiscPK(inscricao), &DiscIguais);
}
Prof* buscarProf(Lista* profs, int codigo){
   return (Prof*) buscar(profs, criarProfPK(codigo), &profsIguais);
}
Turma* buscarTurma(Lista* turmas, int codigo){
   return (Turma*) buscar(turmas, criarTurmaPK(codigo), &turmasIguais);
}


// Adiciona um aluno ou prof a um turma.
void inscrever(Turma* turma, Aluno* aluno){
   turma->alunos = inserirFim(turma->alunos, aluno);
}
void inscreverProf(Turma* turma, Prof* prof){
   turma->prof = inserirFim(turma->prof, prof);
}


// Retira um aluno ou prof de um turma. 
void desinscrever(Turma* turma, int inscricao){
   turma->alunos = retirarAlunoP(turma->alunos, buscarAluno(turma->alunos, inscricao));
}
void desinscreverProf(Turma* turma, int inscricao){
   turma->prof = retirarProfP(turma->prof, buscarProf(turma->prof, inscricao));
}

//retira item da lista geral
Lista* retirarTurmaP(Lista* turmas, Turma* turma){
   return retirar(turmas, turma, &turmasIguais);
}
Lista* retirarTurma(Lista* turmas, int codigo){
   return retirarTurmaP(turmas, buscarTurma(turmas, codigo));
}

Lista* retirarAlunoP(Lista* alunos, Aluno* aluno){
   return retirar(alunos, aluno, &alunosIguais);
}
Lista* retirarAluno(Lista* alunos, int inscricao){
   return retirarAlunoP(alunos, buscarAluno(alunos, inscricao));
}


Lista* retirarProfP(Lista* profs, Prof* prof){
   return retirar(profs, prof, &profsIguais);
}
Lista* retirarProf(Lista* profs, int inscricao){
   return retirarProfP(profs, buscarProf(profs, inscricao));
}

Lista* retirarDiscP(Lista* discs, Disc* disc){
   return retirar(discs, disc, &DiscIguais);
}
Lista* retirarDisc(Lista* discs, int inscricao){
   return retirarDiscP(discs, buscarDisc(discs, inscricao));
}


// Imprime a lista usando funcao auxiliar 
void imprimirTurmas(Lista* turmas){
   imprimir(turmas, &imprimirTurma);
}
void imprimirAlunos(Lista* alunos){
   imprimir(alunos, &imprimirAluno);
}
void imprimirProfs(Lista* profs){
   imprimir(profs, &imprimirProf);
}
void imprimirDisciplinas(Lista* disc){
   imprimir(disc, &imprimirDisciplina);
}






