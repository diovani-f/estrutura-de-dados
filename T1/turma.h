
typedef struct{
   int matricula;
   char curso[50];
   char nome[50];
} Aluno;

typedef struct{
   int codigo;
   char nome[50];
} Prof;

typedef struct{
   int codigo;
   float cargaH;
   char curso[50];
   char nome[50];
} Disc;

typedef struct {
   int codigo;
   Prof* prof;
   Lista* alunos;
} Turma;

Aluno* criarAluno(int matricula);
Prof* criarProf(int codigo);
Disc* criarDisc(int codigo);
Turma* criarTurma(int codigo);

Aluno* buscarAluno(Lista* alunos, int matricula);
Turma* buscarTurma(Lista* turmas, int codigo);
Disc* buscarDisc(Lista* disc, int codigo);
Prof* buscarProf(Lista* profs, int codigo);

/* Em C++ as funcoes retirarAluno e retirarAlunoP poderiam ser 
   sobrecarregadas (terem o mesmo nome) */
Lista* retirarAluno(Lista* alunos, int matricula);
Lista* retirarAlunoP(Lista* alunos, Aluno* aluno);


Lista* retirarProf(Lista* profs, int inscricao);
Lista* retirarProfP(Lista* profs, Prof* prof);

Lista* retirarDiscP(Lista* discs, Disc* disc);
Lista* retirarDisc(Lista* discs, int inscricao);


/* Em C++ as funcoes retirarTurma e retirarTurmaP poderiam ser 
   sobrecarregadas (terem o mesmo nome) */
Lista* retirarTurma(Lista* turmas, int codigo);
Lista* retirarTurmaP(Lista* turmas, Turma* turma);

void inscrever(Turma* turma, Aluno* aluno);
void inscreverProf(Turma* turma, Prof* prof);
void desinscrever(Turma* turma, int matricula);
void desinscreverProf(Turma* turma, int inscricao);

void imprimirTurmas(Lista* turmas);
void imprimirAlunos(Lista* alunos);
void imprimirDisciplinas(Lista* disc);
void imprimirProfs(Lista* profs);

