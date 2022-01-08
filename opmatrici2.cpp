// Questo programma realizza il prodotto di due matrici, la somma di due matrici e 
// il determinante di una matrice quadrata 3x3 //
#include <stdio.h>
int m1[100][100],m2[100][100],mp[100][100],ms[100][100];
int p,q,m,n,det;
int tp;
int totale=0;
void MatriceSomma(int x[][100],int y[][100],int z[][100],int l1,int l2)
{
	int i,j;
	for (i=0;i<l1;i++)	
		for (j=0;j<l2;j++)
			z[i][j]=x[i][j]+y[i][j];
}
void MatriceTotale(int x[][100],int l1,int l2,int &somma)
{
	int i,j;
	for (i=0;i<l1;i++)	
		for (j=0;j<l2;j++)
			somma=somma+x[i][j];
}
void SommaRigaColonna(int x[][100],int l1,int l2 ) 
{
	char S;
	int R,C;
	int SRiga,SCol,j;
	do
	{
		printf("\n Vuoi Sommare una riga o una colonna (R/C) ? X per uscire\n");
		getchar();
		S=getchar();
		if (S=='R')
			{
				printf("\n inserisci numero di riga\n");
				scanf("%d",&R);
				SRiga=0;
				for (j=0;j<l2;j++)
					SRiga=SRiga+x[R][j];
				printf("La somma è:\t %d \n",SRiga);
			}	
		else 
			if (S=='C')
				{
				printf("\n inserisci numero di colonna\n");
				scanf("%d",&C);
				SCol=0;
				for (j=0;j<l1;j++)
					SCol=SCol+x[j][C];
				printf("La somma è:\t %d \n",SCol);
			}	
			else
				if (S=='X')
					return;
				else
					{
						printf("Scelta non valida R/C/X" );
					}		
	}
	while (S!='R' or S!='C');
}
void stampamatrice(int m[][100],int p, int q)
{
	int i,j;
	printf("\nMatrice \n");
	for (i=0;i<p;i++)
	{
		for (j=0;j<q;j++)
			{
				printf("%d ",m[i][j]);
			}
			printf("\n");}
}

void ProdottoMatrici(int x[][100],int y[][100],int z[][100],int l1,int l2,int l3,int l4)
{
	int i,j,r;
	if (l2!=l3)
	{
		printf("\n Attenzione non posso eseguire il prodotto il numero\n delle colonne della prima\n");
		printf(" deve essere uguale al numero delle righe della seconda\n");
	}
	else 
	{
		
		for (r=0;r<l2;r++)
			for (i=0;i<l1;i++)
				for (j=0;j<l4;j++)
					z[i][j]=x[i][r]*y[r][j]+z[i][j];
	stampamatrice(mp,l1,l4);
	}
}
int det2(int x[2][2] )
{
	int det=0;
	det=x[0][0]*x[1][1]-x[1][0]*x[0][1];
	return det;
}
void stampa2matrice(int x[2][2])
{
	int i,j;
	printf("\n");
	for (i=0;i<2;i++)
	{
		for (j=0;j<2;j++)
			printf("%d ",x[i][j]);
	printf("\n");
}}
void determinante(int z[][100],int &d,int d1,int d2)
{
	int i,j;
	int r,sr,sc;
	int sub[2][2];
	if ((d1==d2) and (d2==3)){
	for (r=0;r<3;r++) {
		for (i=0;i<2;i++)
			for (j=0;j<2;j++)
				{
					sr=(i< r ? i : i+1);
					sc=j+1;
					sub[i][j]=z[sr][sc];
				}
	 stampa2matrice(sub);
	 if (r % 2==0)
	 	d=d+z[r][0]*det2(sub);
	else
		d=d-z[r][0]*det2(sub);
 	}}
   else
   	if (d2==d1 and d2==2)
   	 	d=z[0][0]*z[1][1]-z[1][0]*z[0][1];
   else
   	printf("\nNon posso calcolare il Determinante !\n");
}
void caricamatrice(int m[][100],int p, int q)
{
	int i,j;
	for (i=0;i<p;i++)
		for (j=0;j<q;j++)
			{
				printf("Inserisci elemento di posto %d,%d\n",i+1,j+1);
				scanf("%d",&m[i][j]);
			}
}
int main ()
{
	printf("\n Scegli il tipo di operazione da svolgere: \n");
	printf("1- Caricamento Matrice\n");
	printf("2- Somma degli elementi di una matrice\n");
	printf("3- Determinante di una matrice 2x3 i 2x2\n");
	printf("4- Prodotto di 2 matrici\n");
	printf("5- Somma di 2 matrici\n");
	printf("6- Somma riga o colonna di un matrice\n");
	printf("7- Stampa di una matrice\n effe5tua la scelta:\n");
	scanf("%d",&tp);
	switch (tp)
	{
 		case 1: {
				printf ("Inserisci il numero di righe e colonne della matrice\n");
	scanf("%d %d",&n,&m);
	caricamatrice(m1,n,m);
			break;
		}
		case 2: {
			printf ("Inserisci il numero di righe e colonne della matrice\n");
			scanf("%d %d",&n,&m);
			caricamatrice(m1,n,m);
				MatriceTotale(m1,n,m,totale);
				printf("\n Il totale della matrice è: %d",totale);
			break;
		} 
		case 3: {
			printf ("Inserisci il numero di righe e colonne della matrice\n");
			scanf("%d %d",&n,&m);
			caricamatrice(m1,n,m);
			determinante(m1,det,n,m);
			printf("\n Il Determinante è:\t %d\n",det);
				break;
		}
		case 4: {
				printf("Caricamento prima matrice\n");
				printf ("Inserisci il numeor di righe e colonne della matrice\n");
				scanf("%d %d",&n,&m);
				caricamatrice(m1,n,m);
				printf("Caricamento seconda matrice\n");
				printf ("Inserisci il numeor di righe e colonne della matrice\n");
				scanf("%d %d",&p,&q);
				caricamatrice(m2,p,q);
				ProdottoMatrici(m1,m2,mp,n,m,p,q);
			break;
		}
	case 5: {
				printf("Caricamento prima matrice\n");
				printf ("Inserisci il numeor di righe e colonne della matrice\n");
				scanf("%d %d",&n,&m);
				caricamatrice(m1,n,m);
				printf("Caricamento seconda matrice\n");
				printf ("Inserisci il numeor di righe e colonne della matrice\n");
				scanf("%d %d",&p,&q);
				caricamatrice(m2,p,q);

			MatriceSomma(m1,m2,ms,n,m);
			stampamatrice(ms,n,m);
		break;
	}
	case 6:
	{
						printf("Caricamento prima matrice\n");
				printf ("Inserisci il numeor di righe e colonne della matrice\n");
				scanf("%d %d",&n,&m);
				caricamatrice(m1,n,m);
				stampamatrice(m1,n,m);
				printf("\n soma di una riga o di una colonna specifica\n");
		SommaRigaColonna(m1,n,m);
		break;
	}
	case 7: {
		printf ("Inserisci il numeor di righe e colonne della matrice\n");
		scanf("%d %d",&n,&m);
		caricamatrice(m1,n,m);
		stampamatrice(m1,n,m);
		break;
	}}
	return 0;
}
