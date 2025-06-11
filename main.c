#include <stdio.h>
#include <string.h>
#define SIZE 2

//Criando as structs
typedef struct {
  int codigoTipoCurso;
  char nome[50];
  char turno[10];
} TipoCurso;

typedef struct {
  int matricula;
  char cpf[15];
  char nome[50];
  char sexo[20];
  char email[50];
  int codigoTipoCurso;
} Aluno;

typedef struct {
  int codigoDisciplina;
  int codigoTipoCurso;
  char nome[50];
  char nomeProfessor[50];
} Disciplina;

typedef struct {
  int matricula;
  int codigoDisciplina;
  char dataInscricao[20];
} InscricaoDisciplina;

//variavel global
Aluno aluno[SIZE];
TipoCurso tipocurso[SIZE];
Disciplina disciplina[SIZE];
InscricaoDisciplina inscricaodisciplina[SIZE];



//CRUD TipoCurso
void adicionarTipoCurso (int opcao) {
  // implementação da função TipoCurso
    int numCurso;
    

    if (opcao == 1) {
        printf("\n---------- Adicionando Tipo de Curso ----------\n");
        getchar();
    }
    
    

    printf("\nQuantos cursos deseja adicionar (1 ou 2): ");
    scanf("%d", &numCurso);

    if (numCurso != 1 && numCurso != 2) {
        printf("\nQUANTIDADE DE CURSOS NÃO PERMITIDA!\n");
        return;
    } 

    
    
    for (int i = 0; i < numCurso; i++) {
        while (tipocurso[i].codigoTipoCurso) {
            i++;
        }
        
        printf("\nDigite o código do curso %d: ", i + 1);
        scanf("%d", &tipocurso[i].codigoTipoCurso);
        
        printf("Digite o nome do curso %d: ", i + 1);
        scanf("%s", tipocurso[i].nome);
        
        printf("Digite o turno que deseja %d: ", i + 1);
        scanf("%s", tipocurso[i].turno);
        
        printf("\nCurso adicionado com sucesso!\n");
        printf("\n-----------------------------------------------\n");
        
    }

}

void mostrarTipoCurso (int opcao) {
  // implementação da função mostrarTipoCurso
  int cursosCadastrados = 0;
  
  if (opcao == 2) {
        printf("\n---------- Mostrar cursos cadastrados ----------\n");
        getchar();
    }

    for (int i = 0; i < SIZE; i++) {
        if (tipocurso[i].codigoTipoCurso != 0) {
            printf("\nCódigo do curso: %d\n", tipocurso[i].codigoTipoCurso);
            printf("Nome do curso: %s\n", tipocurso[i].nome);
            printf("Turno: %s\n", tipocurso[i].turno);
            printf("\n-----------------------------------------------\n");
            cursosCadastrados++;
        }
    }

    if (cursosCadastrados == 0) {
        printf("\nNÃO EXISTE CURSO CADASTRADO!\n");
    }   

}

void editarTipoCurso (int opcao) {
  // implementação da função editarTipoCurso
  int cursosCadastrados = 0;
  int editarcurso;
  
  if (opcao == 3) {
        printf("\n--------------- Editar Informações --------------\n");
        getchar();
    }
  
   for (int i = 0; i < SIZE; i++) {
      if (tipocurso[i].codigoTipoCurso != 0) {
            
            printf("\nCódigo do curso: %d\n", tipocurso[i].codigoTipoCurso);
            printf("Nome do curso: %s\n", tipocurso[i].nome);
            printf("Turno: %s\n", tipocurso[i].turno);
            
            printf("\n-----------------------------------------------\n");
            cursosCadastrados++;
        }
        
   }
   
    if (cursosCadastrados == 0) {
        printf("\nNÃO EXISTE CURSO CADASTRADO!\n");
        return;
    }   

    printf("\nInforme o código do curso que deseja editar: ");
    scanf("%d", &editarcurso);

    for (int i = 0; i < SIZE; i++) {
        
        if (editarcurso == tipocurso[i].codigoTipoCurso) {
            
            printf("\nDigite o código do curso %d: ", i + 1);
            scanf("%d", &tipocurso[i].codigoTipoCurso);
            
            printf("Digite o nome do curso %d: ", i + 1);
            scanf("%s", tipocurso[i].nome);
            
            printf("Digite o turno que deseja %d: ", i + 1);
            scanf("%s", tipocurso[i].turno);
            
            printf("\nCurso editado com sucesso!\n");
            printf("\n-----------------------------------------------\n");
        }    
    }    
}

void excluirTipoCurso (int opcao) {
  // implementação da função excluirTipoCurso
  int cursosCadastrados = 0;
  int excluircurso;
  
  if (opcao == 4) {
        printf("\n-------------- Excluir Informações -------------\n");
        getchar();
    } 
   
   for (int i = 0; i < SIZE; i++) {
      if (tipocurso[i].codigoTipoCurso != 0) {
            
            printf("\nCódigo do curso: %d\n", tipocurso[i].codigoTipoCurso);
            printf("Nome do curso: %s\n", tipocurso[i].nome);
            printf("Turno: %s\n", tipocurso[i].turno);
            
            printf("\n-----------------------------------------------\n");
            cursosCadastrados++;
        }
        
   }
    
    if (cursosCadastrados == 0) {
        printf("\nNÃO EXISTE CURSO CADASTRADO!\n");
        return;
    }
    
    printf("\nInforme o código do curso que deseja excluir: ");
    scanf("%d", &excluircurso);
    
    for (int i = 0; i < SIZE; i++) {
        if (excluircurso == tipocurso[i].codigoTipoCurso) {
            tipocurso[i].codigoTipoCurso = 0;
            strcpy(tipocurso[i].nome, "");
            strcpy(tipocurso[i].turno, "");
            printf("\nCurso excluido com sucesso!\n");
            return;
        }
    }
}




void menuTipoCurso () {
  int opcao = 0;

  do
    {
      printf ("\n---------------- Menu Tipo Curso ---------------\n");
      printf ("\n1. Adicionar Curso");
      printf ("\n2. Mostrar Curso");
      printf ("\n3. Editar Curso");
      printf ("\n4. Excluir Curso");
      printf ("\n0. Sair");
      printf ("\nEscolha uma opção: ");
      scanf ("%i", &opcao);

      switch (opcao)
	{
	case 1:
	  adicionarTipoCurso (opcao);
	  break;
	case 2:
	  mostrarTipoCurso (opcao);
	  break;
	case 3:
	  editarTipoCurso (opcao);
	  break;
	case 4:
	  excluirTipoCurso (opcao);
	  break;
	case 0:
	  printf ("Finalizado com sucesso!\n");
	  break;
	default:
	  printf ("\n* Opção selecionada inválida\n");
	}
    }
  while (opcao != 0);
}

//CRUD Aluno
void adicionarAluno (int opcao) {
  // implementação da função Aluno
  int numAluno;
  int alunosCadastrados = 0;

    if (opcao == 1) {
        printf("\n-------------- Adicionando Aluno --------------\n");
        getchar();
    }
    
    


    printf("\nQuantos alunos deseja adicionar (1 ou 2): ");
    scanf("%d", &numAluno);

    if (numAluno != 1 && numAluno != 2) {
        printf("\nQUANTIDADE DE ALUNOS NÃO PERMITIDA!\n");
        return;
    }
    
    
    for (int i = 0; i < numAluno; i++) {
        while (aluno[i].matricula) {
            i++;
        }
        
        printf("\nDigite a matricula do aluno %d: ", i + 1);
        scanf("%d", &aluno[i].matricula);
        
        printf("Digite o CPF do aluno %d: ", i + 1);
        scanf("%s", aluno[i].cpf);
        
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", aluno[i].nome);
        
        printf("Digite o sexo do aluno %d: ", i + 1);
        scanf("%s", aluno[i].sexo);
        
        printf("Digite o e-mail do aluno %d: ", i + 1);
        scanf("%s", aluno[i].email);
        
        for (int i = 0; i < SIZE; i++) {
            if (tipocurso[i].codigoTipoCurso != 0) {
                printf("Código do curso: %d\n", tipocurso[i].codigoTipoCurso);
                alunosCadastrados++;
            } 
            
        }
        
        if (alunosCadastrados == 0) {
            printf("\nNÃO EXISTE CURSO CADASTRADO!\n");
        }
        
        printf("\nAluno adicionado com sucesso!\n");
        printf("\n-----------------------------------------------\n");
        
    }

}

void mostrarAluno (int opcao) {
  // implementação da função mostrarAluno
    int alunosCadastrados = 0;
  
  if (opcao == 2) {
        printf("\n---------- Mostrar alunos cadastrados ----------\n");
        getchar();
    }

    for (int i = 0; i < SIZE; i++) {
        if (aluno[i].matricula != 0) {
            printf("\nMatricula do aluno: %d\n", aluno[i].matricula);
            printf("CPF do aluno: %s\n", aluno[i].cpf);
            printf("Nome do aluno: %s\n", aluno[i].nome);
            printf("Sexo do aluno: %s\n", aluno[i].sexo);
            printf("E-mail do aluno: %s\n", aluno[i].email);
            printf("Código do curso: %d\n", tipocurso[i].codigoTipoCurso);
            printf("\n-----------------------------------------------\n");
            alunosCadastrados++;
        }
    }

    if (alunosCadastrados == 0) {
        printf("\nNÃO EXISTE ALUNO CADASTRADO!\n");
    } 
}

void editarAluno (int opcao) {
  // implementação da função editarAluno
  int alunosCadastrados = 0;
  int editaraluno;
  
  if (opcao == 3) {
        printf("\n------------------ Editar Alunos -----------------\n");
        getchar();
    }
  
   for (int i = 0; i < SIZE; i++) {
      if (aluno[i].matricula != 0) {
            
            printf("\nMatricula do aluno: %d\n", aluno[i].matricula);
            printf("CPF do aluno: %s\n", aluno[i].cpf);
            printf("Nome do aluno: %s\n", aluno[i].nome);
            printf("Sexo do aluno: %s\n", aluno[i].sexo);
            printf("E-mail do aluno: %s\n", aluno[i].email);
            
            printf("\n-----------------------------------------------\n");
            alunosCadastrados++;
        }
        
   }
   
    if (alunosCadastrados == 0) {
        printf("\nNÃO EXISTE ALUNO CADASTRADO!\n");
        return;
    }   

    printf("\nInforme a matricula do aluno que deseja editar: ");
    scanf("%d", &editaraluno);

    for (int i = 0; i < SIZE; i++) {
        
        if (editaraluno == aluno[i].matricula) {
            
            printf("\nDigite a matricula do aluno %d: ", i + 1);
            scanf("%d", &aluno[i].matricula);
            
            printf("Digite o CPF do aluno %d: ", i + 1);
            scanf("%s", aluno[i].cpf);
            
            printf("Digite o nome do aluno %d: ", i + 1);
            scanf("%s", aluno[i].nome);
            
            printf("Digite o sexo do aluno %d: ", i + 1);
            scanf("%s", aluno[i].sexo);
            
            printf("Digite o e-mail do aluno %d: ", i + 1);
            scanf("%s", aluno[i].email);
            
            printf("\nAluno editado com sucesso!\n");
            printf("\n-----------------------------------------------\n");
        }    
    }  
}

void excluirAluno (int opcao) {
  // implementação da função excluirAluno
  int alunosCadastrados = 0;
  int excluiraluno;
  
  if (opcao == 4) {
        printf("\n----------------- Excluir Alunos ----------------\n");
        getchar();
    } 
   
    for (int i = 0; i < SIZE; i++) {
        if (aluno[i].matricula != 0) {
            printf("\nMatricula do aluno: %d\n", aluno[i].matricula);
            printf("CPF do aluno: %s\n", aluno[i].cpf);
            printf("Nome do aluno: %s\n", aluno[i].nome);
            printf("Sexo do aluno: %s\n", aluno[i].sexo);
            printf("E-mail do aluno: %s\n", aluno[i].email);
            printf("\n-----------------------------------------------\n");
            alunosCadastrados++;
        }
    }
    
    if (alunosCadastrados == 0) {
        printf("\nNÃO EXISTE ALUNO CADASTRADO!\n");
        return;
    }
    
    printf("\nInforme a matricula do aluno que deseja excluir: ");
    scanf("%d", &excluiraluno);
    
    for (int i = 0; i < SIZE; i++) {
        if (excluiraluno == aluno[i].matricula) {
            aluno[i].matricula = 0;
            strcpy(aluno[i].cpf, "");
            strcpy(aluno[i].nome, "");
            strcpy(aluno[i].sexo, "");
            strcpy(aluno[i].email, "");
            printf("\nAluno excluido com sucesso!\n");
            return;
        }
    }  
}

void menuAluno () {
  int opcao = 0;

  do
    {
      printf ("\n------------------ Menu Aluno -----------------\n");
      printf ("\n1. Adicionar Aluno");
      printf ("\n2. Mostrar Aluno");
      printf ("\n3. Editar Aluno");
      printf ("\n4. Excluir Aluno");
      printf ("\n0. Sair");
      printf ("\nEscolha uma opção: ");
      scanf ("%i", &opcao);

      switch (opcao)
	{
	case 1:
	  adicionarAluno (opcao);
	  break;
	case 2:
	  mostrarAluno (opcao);
	  break;
	case 3:
	  editarAluno (opcao);
	  break;
	case 4:
	  excluirAluno (opcao);
	  break;
	case 0:
	  printf ("Finalizado com sucesso!\n");
	  break;
	default:
	  printf ("\n* Opção selecionada inválida\n");
	}
    }
  while (opcao != 0);

}

//CRUD Disciplina
void adicionarDisciplina (int opcao) {
  // implementação da função adicionarDisciplina
  int numDisciplina;
  int disciplinaCadastrados = 0;

    if (opcao == 1) {
        printf("\n---------------- Adicionando Disciplina ----------------\n");
        getchar();                          
    }

    printf("\nQuantas disciplinas deseja adicionar (1 ou 2): ");
    scanf("%d", &numDisciplina);

    if (numDisciplina != 1 && numDisciplina != 2) {
        printf("\nQUANTIDADE DE DISCIPLINAS NÃO PERMITIDA!\n");
        return;
    }
    
    
    for (int i = 0; i < numDisciplina; i++) {
        while (disciplina[i].codigoDisciplina) {
            i++;
        }
        
        printf("\nDigite o código da disciplina %d: ", i + 1);
        scanf("%d", &disciplina[i].codigoDisciplina);
        
        for (int i = 0; i < SIZE; i++) {
            if (tipocurso[i].codigoTipoCurso != 0) {
                printf("Código do curso: %d\n", tipocurso[i].codigoTipoCurso);
                disciplinaCadastrados++;
            } 
            
        }
        
        
        printf("Digite o nome da disciplina %d: ", i + 1);
        scanf("%s", disciplina[i].nome);
        
        printf("Digite o nome do professor %d: ", i + 1);
        scanf("%s", disciplina[i].nomeProfessor);
        
        if (disciplinaCadastrados == 0) {
            printf("\nNÃO EXISTE CURSO CADASTRADO!\n");
        }
        
        printf("\nDisciplina adicionada com sucesso!\n");
        printf("\n-----------------------------------------------\n");
        
    }
  
  
}

void mostrarDisciplina (int opcao) {
  // implementação da função mostrarDisciplina
    int disciplinaCadastrados = 0;
  
  if (opcao == 2) {
        printf("\n------------ Mostrar disciplinas cadastradas ------------\n");
        getchar();
    }

    for (int i = 0; i < SIZE; i++) {
        if (disciplina[i].codigoDisciplina != 0) {
            printf("\nCódigo da disciplina: %d\n", disciplina[i].codigoDisciplina);
            printf("Código do curso: %d\n", tipocurso[i].codigoTipoCurso);
            printf("Nome da disciplina: %s\n", disciplina[i].nome);
            printf("Nome do professor: %s\n", disciplina[i].nomeProfessor);
            printf("\n-----------------------------------------------\n");
            disciplinaCadastrados++;
        }
    }

    if (disciplinaCadastrados == 0) {
        printf("\nNÃO EXISTE DISCIPLINA CADASTRADA!\n");
    }  
  
}

void editarDisciplina (int opcao) {
  // implementação da função editarDisciplina
  int disciplinaCadastrados = 0;
  int editardisciplina;
  
  if (opcao == 3) {
        printf("\n-------------- Editar Disciplinas --------------\n");
        getchar();                          
    }
  
   for (int i = 0; i < SIZE; i++) {
      if (disciplina[i].codigoDisciplina != 0) {
            
            printf("\nCódigo da disciplina: %d\n", disciplina[i].codigoDisciplina);
            printf("Nome da disciplina: %s\n", disciplina[i].nome);
            printf("Nome do professor: %s\n", disciplina[i].nomeProfessor);
            
            printf("\n-----------------------------------------------\n");
            disciplinaCadastrados++;
        }
        
   }
   
    if (disciplinaCadastrados == 0) {
        printf("\nNÃO EXISTE DISCIPLINA CADASTRADA!\n");
        return;
    }   

    printf("\nInforme o código da disciplina que deseja editar: ");
    scanf("%d", &editardisciplina);

    for (int i = 0; i < SIZE; i++) {
        
        if (editardisciplina == disciplina[i].codigoDisciplina) {
            
            printf("\nDigite o código da disciplina %d: ", i + 1);
            scanf("%d", &disciplina[i].codigoDisciplina);
            
            printf("Digite o nome da disciplina %d: ", i + 1);
            scanf("%s", disciplina[i].nome);
            
            printf("Digite o nome do professor %d: ", i + 1);
            scanf("%s", disciplina[i].nomeProfessor);
            
            printf("\nDisciplina editada com sucesso!\n");
            printf("\n-----------------------------------------------\n");
        }    
    }
  
}

void excluirDisciplina (int opcao) {
  // implementação da função excluirDisciplina
  int disciplinaCadastrados = 0;
  int excluirdisciplina;
  
  if (opcao == 4) {
        printf("\n-------------- Excluir Disciplinas -------------\n");
        getchar();                          
    } 
   
    for (int i = 0; i < SIZE; i++) {
        if (disciplina[i].codigoDisciplina != 0) {
            printf("\nCódigo da disciplina: %d\n", disciplina[i].codigoDisciplina);
            printf("Nome da disciplina: %s\n", disciplina[i].nome);
            printf("Nome do professor: %s\n", disciplina[i].nomeProfessor);
            printf("\n-----------------------------------------------\n");
            disciplinaCadastrados++;
        }
    }
    
    if (disciplinaCadastrados == 0) {
        printf("\nNÃO EXISTE DISCIPLINA CADASTRADA!\n");
        return;
    }
    
    printf("\nInforme o código da disciplina que deseja excluir: ");
    scanf("%d", &excluirdisciplina);
    
    for (int i = 0; i < SIZE; i++) {
        if (excluirdisciplina == disciplina[i].codigoDisciplina) {
            disciplina[i].codigoDisciplina = 0;
            strcpy(disciplina[i].nome, "");
            strcpy(disciplina[i].nome, "");
            strcpy(disciplina[i].nomeProfessor, "");
            printf("\nDisciplina excluida com sucesso!\n");
            return;
        }
    }  

}


void menuDisciplina () {
  int opcao = 0;

  do
    {
      printf ("\n---------------- Menu Disciplina ---------------\n");
      printf ("\n1. Adicionar Disciplina");
      printf ("\n2. Mostrar Disciplina");
      printf ("\n3. Editar Disciplina");
      printf ("\n4. Excluir Disciplina");
      printf ("\n0. Sair");
      printf ("\nEscolha uma opção: ");
      scanf ("%i", &opcao);

      switch (opcao)
	{
	case 1:
	  adicionarDisciplina (opcao);
	  break;
	case 2:
	  mostrarDisciplina (opcao);
	  break;
	case 3:
	  editarDisciplina (opcao);
	  break;
	case 4:
	  excluirDisciplina (opcao);
	  break;
	case 0:
	  printf ("Finalizado com sucesso!\n");
	  break;
	default:
	  printf ("\n* Opção selecionada inválida\n");
	}
    }
  while (opcao != 0);

}

//CRUD Inscricao Disciplina
void adicionarInscricaoDisciplina(int opcao) {
    // implementação da função adicionarInscricaoDisciplina
    int numInscricao;
    int inscricaoCadastrados = 0;
    int matriculacadastrada = 0;
    int disciplinacadastrada = 0;

    if (opcao == 1) {
        printf("\n------- Adicionando Inscriçãoo Disciplina -------\n");
        getchar();
    }

    for (int i = 0; i < SIZE; i++) {
        if (aluno[i].matricula != 0 && disciplina[i].codigoDisciplina != 0) {
            matriculacadastrada++;
            disciplinacadastrada++;
        }
    }

    if (matriculacadastrada == 0 || disciplinacadastrada == 0) {
        printf("\nNÃO EXISTE MATRICULA OU DISCIPLINA CADASTRADA!\n");
        return;
    }

    printf("\nQuantas inscrições deseja adicionar (1 ou 2): ");
    scanf("%d", &numInscricao);

    if (numInscricao != 1 && numInscricao != 2) {
        printf("\nQUANTIDADE DE INSCRIÇÕES NÃO PERMITIDA!\n");
        return;
    }

    for (int i = 0; i < numInscricao; i++) {
        while (inscricaodisciplina[i].dataInscricao[0] != '\0') {
            i++;
        }

        for (int j = 0; j < SIZE; j++) {
            if (aluno[j].matricula != 0 && disciplina[j].codigoDisciplina != 0) {
                printf("Matricula do aluno: %d\n", aluno[j].matricula);
                printf("Código da disciplina: %d\n", disciplina[j].codigoDisciplina);
                inscricaoCadastrados++;
            }
        }

        printf("Digite a data de inscrição (dd/mm/aaaa) %d: ", i + 1);
        scanf("%s", inscricaodisciplina[i].dataInscricao);

        printf("\nInscrição feita com sucesso!\n");
        printf("\n-----------------------------------------------\n");
    }
}


void mostrarInscricaoDisciplina (int opcao) {
  // implementação da função mostrarInscricaoDisciplina
  int inscricaoCadastradas = 0;
  
  if (opcao == 2) {
        printf("\n-------------- Mostrar Inscrição Disciplina --------------\n");
        getchar();                     
    }

    for (int i = 0; i < SIZE; i++) {
        if (inscricaodisciplina[i].dataInscricao[0] != '\0') {
            printf("\nMatricula do aluno: %d\n", aluno[i].matricula);
            printf("Código da disciplina: %d\n", disciplina[i].codigoDisciplina);
            printf("Data de inscrição: %s\n", inscricaodisciplina[i].dataInscricao);
            printf("\n-----------------------------------------------\n");
            inscricaoCadastradas++;
        }
    }

    if (inscricaoCadastradas == 0) {
        printf("\nNÃO EXISTE INSCRIÇÃO CADASTRADA!\n");
    }
}

void editarInscricaoDisciplina(int opcao) {
    // implementação da função editarInscricaoDisciplina
    int inscricaoCadastradas = 0;
    char editarinscricao[20];

    if (opcao == 3) {
        printf("\n-------------- Editar Inscrição Disciplina --------------\n");
        getchar();
    }

    for (int i = 0; i < SIZE; i++) {
        if (inscricaodisciplina[i].dataInscricao[0] != '\0') {
            printf("\nData de inscrição: %s\n", inscricaodisciplina[i].dataInscricao);
            printf("\n-----------------------------------------------\n");
            inscricaoCadastradas++;
        }
    }

    if (inscricaoCadastradas == 0) {
        printf("\nNÃO EXISTE INSCRIÇÃO CADASTRADA!\n");
        return;
    }

    printf("\nInforme a data de inscrição que deseja editar (dd/mm/aaaa): ");
    scanf("%s", editarinscricao);

    printf("\n-----------------------------------------------\n");

    for (int i = 0; i < SIZE; i++) {
        if  (strcmp(editarinscricao, inscricaodisciplina[i].dataInscricao) == 0) {
            printf("\nInforme a nova data de inscrição (dd/mm/aaaa) %d: ", i + 1);
            scanf("%s", inscricaodisciplina[i].dataInscricao);
            printf("\nInscrição editada com sucesso!\n");
            printf("\n-----------------------------------------------\n");
            
        }
    }
}


void excluirInscricaoDisciplina(int opcao) {
    // implementação da função excluirInscricaoDisciplina
    int inscricaoCadastradas = 0;
    char excluirinscricao[20]; 

    if (opcao == 4) {
        printf("\n-------------- Excluir Inscrição Disciplina --------------\n");
        getchar();
    }

    for (int i = 0; i < SIZE; i++) {
        if (inscricaodisciplina[i].dataInscricao[0] != '\0') {
            printf("\nData de inscrição: %s\n", inscricaodisciplina[i].dataInscricao);
            printf("\n-----------------------------------------------\n");
            inscricaoCadastradas++;
        }
    }

    if (inscricaoCadastradas == 0) {
        printf("\nNÃO EXISTE INSCRIÇÃO CADASTRADA!\n");
        return;
    }

    printf("\nInforme a data de inscrição que deseja excluir (dd/mm/aaaa): ");
    scanf("%s", excluirinscricao);

    for (int i = 0; i < SIZE; i++) {
        if (strcmp(excluirinscricao, inscricaodisciplina[i].dataInscricao) == 0) {
            strcpy(inscricaodisciplina[i].dataInscricao, ""); 
            printf("\nInscrição excluída com sucesso!\n");
            return;
        }
    }
}

void menuInscricaoDisciplina () {
  int opcao = 0;

  do
    {
      printf ("\n----------- Menu Inscrição Disciplina ----------\n");
      printf ("\n1. Adicionar Inscricao Disciplina");
      printf ("\n2. Mostrar Inscricao Disciplina");
      printf ("\n3. Editar Inscricao Disciplina");
      printf ("\n4. Excluir Inscricao Disciplina");
      printf ("\n0. Sair");
      printf ("\nEscolha uma opção: ");
      scanf ("%i", &opcao);

      switch (opcao)
	{
	case 1:
	  adicionarInscricaoDisciplina (opcao);
	  break;
	case 2:
	  mostrarInscricaoDisciplina (opcao);
	  break;
	case 3:
	  editarInscricaoDisciplina (opcao);
	  break;
	case 4:
	  excluirInscricaoDisciplina (opcao);
	  break;
	case 0:
	  printf ("Finalizado com sucesso!\n");
	  break;
	default:
	  printf ("\n* Opção selecionada inválida\n");
	}
    }
  while (opcao != 0);

}

//MENU PRINCIPAL
void menu () {
  int opcao = 0;

  do
    {
      printf ("\n--------------------- Menu --------------------\n");
      printf ("\n1. Tipo Curso");
      printf ("\n2. Aluno");
      printf ("\n3. Disciplina");
      printf ("\n4. Inscricao Disciplina");
      printf ("\n0. Sair");
      printf ("\nEscolha uma opção: ");
      scanf ("%i", &opcao);

      switch (opcao)
	{
	case 1:
	  menuTipoCurso (opcao);
	  break;
	case 2:
	  menuAluno (opcao);
	  break;
	case 3:
	  menuDisciplina (opcao);
	  break;
	case 4:
	  menuInscricaoDisciplina (opcao);
	  break;
	case 0:
	  printf ("Finalizado com sucesso!\n");
	  break;
	default:
	  printf ("\n* Opção selecionada inválida\n");
	}
    }
  while (opcao != 0);

}

int main () {
  menu ();
  return 0;
}
