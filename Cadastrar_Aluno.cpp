#include<stdio.h>
#include<string.h>
#include<locale.h>

struct disciplina{
	char Materia[30];
	float nota;
};

struct Datas{
	int dia;
	int mes;
	int ano;
};

Datas data;

typedef struct Alunos{
	int ra;
	char nome[80];
	struct disciplina disci[3];
	struct Datas data;
}Alunos;

Alunos aluno;

void menu();
void inicializar();
void cadastrar();
void imprimir();

int main(){
	menu();
}

void menu(){
	int opcao;
	do{
		printf("\n1 - INICIALIZAR A ESTRUTURA");
		printf("\n2 - CADASTRAR ALUNO");
		printf("\n3 - IMPRIMIR ALUNO");
		printf("\n4 - SAIR");
		printf("\n Digite a opcao desejada:");
		scanf("%d",&opcao);
	
	switch(opcao){
		case 1:
			inicializar();
			break;
	    case 2:
	    	cadastrar();
	    	break;
	    case 3:
	    	imprimir();
	    	break;
	    case 4:
	    	printf("O programa sera finalizado!");
	    	break;
	    default:
	    	printf("\nOpcao Invalida!");
	   }
	   
	}while(opcao != 4);
	
}

void inicializar(){
	aluno.ra=0;
	strcpy(aluno.nome,"NULL");
	aluno.data.dia=0;
	aluno.data.mes=0;
	aluno.data.ano=0;
	
	for(int i=0;i<=3;i++){
	strcpy(aluno.disci[i].Materia,"NULL");
	aluno.disci[i].nota=0;
	}
}

void cadastrar(){
	printf("Digite a RA:");
	scanf("%d",&aluno.ra);
	fflush(stdin);
	printf("Digite o nome do Aluno:");
	gets(aluno.nome);
	printf("Digite a data de nascimento do Aluno:");
	scanf("%d%d%d",&aluno.data.dia,&aluno.data.mes,&aluno.data.ano);
	fflush(stdin);
	
	for(int i=0;i<=3;i++){
	printf("Digite a Disciplina:");
	gets(aluno.disci[i].Materia);
	printf("Digite a nota da disciplina %s:",aluno.disci[i].Materia);
	scanf("%f",&aluno.disci[i].nota);
	fflush(stdin);
    }
    
}

void imprimir(){
	
	printf("\nRA:%d",aluno.ra);
	printf("\n%s",aluno.nome);
	printf("\nData de nascimento:%d/%d/%d",aluno.data.dia,aluno.data.mes,aluno.data.ano);
	
	for(int i=0;i<=3;i++){
		printf("\nDisciplina:%s - Nota:%.1f",aluno.disci[i].Materia,aluno.disci[i].nota);
	}
	printf("\n\n");
}


