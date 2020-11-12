#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char MesChiaro[128], ChiaveCifratura[128], MesCifrato[128];
time_t t;
int lungMes,check = 0;
char c,sceltaUtente;


 void cifraEstampa() {      /*Funzione che cifra il messaggio inserito nell'array Meschiaro tramite ciclo for e operatore XOR, dopodiche stampa il messaggio cifrato.
                              Successivamente ricava il messaggio contenuto in Meschiaro  applicando lo XOR tra MesCifrato (il messaggio cifrato) e
                                ChiaveCifratura (la chiave di cifratura inserita dall'utente o generata dal codice) per poi stamparlo.*/
  for(int i=0;i<strlen(MesChiaro);i++) {

    MesCifrato[i]=MesChiaro[i]^ChiaveCifratura[i]; /*cifratura del MesChiaro*/
  }
  printf("\n\nIl messaggio cifrato è: ");
  for (int i=0;i<strlen(MesChiaro);i++) {

    printf("%X",MesCifrato[i]);
  }
  for(int i=0;i<strlen(MesCifrato);i++){

    MesChiaro[i]=MesCifrato[i]^ChiaveCifratura[i]; /*decifratura del MesCifrato per ottenere il MesChiaro*/
   }

  printf("\n\nIl messaggio in chiaro era: ");

  for (int i=0;i<strlen(MesChiaro);i++) {
    printf("%c",MesChiaro[i]);
  }
}

int main() {
  printf("Digitare un messaggio di massimo 128 caratteri che si desidera cifrare,\neventuali caratteri in eccesso non verranno considerati\n");
  printf("Inserire qui il suo messaggio: ");
  fgets(MesChiaro,128,stdin);
  lungMes = strlen(MesChiaro)-1;
  printf("\nIl messaggio inserito e' di %d caratteri\n",lungMes);

  do{
    printf("\nScegliere una delle seguenti opzioni:\n-> Digitare 1 per inserire manualmente la chiave di cifratura\n-> Digitare 2 per la generazione automatica della chiave di cifratura\n-> Digitare 0 per chiudere il programma\n");
    printf("Inserire qui la sua risposta: ");
  scanf("%c", &sceltaUtente);

  switch(sceltaUtente) {  /*switch utilizzato per gestire la scelta dell'utente sul metodo di ottenimento della chiave di cifratura*/

    case '1':
             printf("\nHa scelto di inserire manualmente la chiave di cifratura\n");
             check = 1;
             break;

    case '2':
             printf("\nHa scelto di generare la chiave di cifratura in maniera automatica\n");
             check = 1;
             break;

    case '0':
             return 0;

    default:
             printf("\nHa inserito un valore errato\nPuò inserire solo (0,1,2) riprovi di nuovo\n");

             }

             while((c= getchar()) != '\n' && c != EOF);

           } while(!check); /*se la variabile check ha valore 0, quindi quando viene inserito un valore diverso da quelli previsti dallo switch,
                             attraverso l'utilizzo del do e while viene riproposta la scelta all'utente*/

          if (sceltaUtente == '1') { /* if che gestisce le procedure da effettuare se la scelta dell'utente è di inserire manualmente la chiave di cifratura*/

            do {
            printf("\nInserire un messaggio di lunghezza uguale o superiore al messaggio inserito inizialmente, questo verrà usato come chiave di cifratura\n");
            printf("Inserire qui il suo messaggio: ");
            fgets(ChiaveCifratura,128,stdin);
            fflush(stdin);

            if (strlen(ChiaveCifratura)<strlen(MesChiaro)) { /* if che controlla se l'utente ha inserito un messaggio troppo corto per cifrare il MesChiaro */
              printf("\nIl messaggio deve avere tra %ld e 128 caratteri\n",strlen(MesChiaro)-1);
            }
          }while(strlen(ChiaveCifratura)<strlen(MesChiaro)); /* il ciclo riparte se l'utente ha inserito una chiave di cifratura troppo corta */

          cifraEstampa();

        }

        if (sceltaUtente == '2') {

          srand((unsigned) time(&t)); /* la funzione srand inizializza la funzione per la generazione di numeri casuali cambiando ogni volta il seme ed evitando così l'estrazione degli stessi numeri*/

          for(int i=0;i<strlen(MesChiaro);i++) {
            ChiaveCifratura[i]=rand()%128; /*con la funzione rand viene generato un numero casuale tra 0 e 127*/
          }

          printf("\nLa sua chiave di cifratura è: ");

          for(int i=0; i<strlen(MesChiaro);i++) {
          printf("%X",ChiaveCifratura[i]);
         }

        cifraEstampa();

        }
        return 0;
      }
