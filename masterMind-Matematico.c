#include <stdio.h>    // per le operazioni di i/o
#include <time.h>     // per il seme del random
#include <windows.h>  // per il random
#include <conio.h>    // per il getch()
#define randomize srand((unsigned)time(NULL))
#define GetRandom( min, max ) ((rand() % (int)(((max) + 1) - (min))) + (min))

int segreto,n,s[20],t[20],tentativo;                   // dichiarazioni globali
int generasegreto(int n);                             //    
void generastringasegreto(int segreto, int n);       // Prototipi di funzioni
void generastringatentativo(int tentativo, int n);  //
int verifica(int n);                               //
/*
 La seguente funzione ha lo scopo di generare un numero
 di pari cifre quanto il numero n inserito dall'utente 
 ovviamente pi� la cifra � alta parimenti lo sar� il 
 grado di difficolta. Grado massimo 20
*/
int generasegreto(int n)
{ int segreto,a,i;
a=1;
for (i=1;i<=(n-1);i++)
a=a*10;
randomize;
segreto=GetRandom(a,((a*10)-1));
//printf("%d\n", segreto);
return segreto;
}

/*
 La seguente funzione ha lo scopo di spacchettare
 il numero segreto in una array di pari dimensioni
*/

void generastringasegreto(int segreto, int n)
{
int aux=segreto;
int a,b,i;
   for (i=1; i<=n; i++)
   {
    a=(aux/10);
    b=aux-(a*10);
    s[n-i]=b;
    aux=a;
    a=b=0; 
   }
}

/*
 La seguente funzione ha lo scopo di spacchettare
 il tentativo in una array di pari dimensioni
*/

void generastringatentativo(int tentativo, int n)
{
int aux=tentativo;
int a,b,i;
   for (i=1; i<=n; i++)
   {
    a=(aux/10);
    b=aux-(a*10);
    t[n-i]=b;
    aux=a;
    a=b=0; 
   }
}
/*
 La seguente funzione verifica se il codice segreto
 e il tentativo sono uguali
*/
int verifica(int n)
{
int i,punteggio=0;
for (i=0;i<n;i++)
{
if (s[i]==t[i])
punteggio++;
}
  return punteggio;
}

//main program

main()
{
int giusto=0;
printf("Mastermind matematico\n");
printf("Limite Massimo: 20 tentativi\n");
printf("Inserisci numero di identificazione (0 se non ce l'hai): ");
int id;
scanf("%d",&id);
printf("Inserisci cifre numero: ");
scanf("%d",&n);
segreto=generasegreto(n);
printf("Benvenuto Giocatore\n");
int i;
//inizializziamo il vettore
for (i=0; i<20; i++)
s[i]=0;
generastringasegreto(segreto,n);
printf("\n");
int j=1;
do
{
printf("Tentativo no. %d inserisci numero: ",j);
scanf("%d",&tentativo);
j++;
generastringatentativo(tentativo,n);
int punti;
punti=verifica(n);
printf("%d/%d numeri al posto giusto\n",punti,n);
if (punti==n)
giusto=1;
} while ((giusto==0) && (j<=20));
  if (giusto==1)
  {
  printf("Bravo. Hai indovinato il numero segreto");
  }
  else if (j==21)
  {
  printf("Tentativi scaduti. Il numero segreto era: %d",segreto);
  }
getch();
}
