#include <stdio.h>
#include <string.h>
struct alunno {
	char nome[30];
	char cognome[30];
	int age;
};
alunno classe[100];
int n;
void caricatabella(alunno x[],int &s)
{
	int k;
	printf("\n Quanti alunni ? ");
	scanf("%d",&s);
	for (k=0;k<s;k++)
		{
			printf("\n Inserisci i dati nell'ordine \n");
			printf("Cognome: ");
			getchar();
			gets(x[k].cognome);
			printf("\n Nome: ");
			getchar();
			gets(x[k].nome);
			printf("\n Età: ");
			scanf("%d",&x[k].age);
		}
}
int main ()
{
	caricatabella(classe,n);
	printf("\n Ho inserito %d alunni",n);
	return 0;
}
