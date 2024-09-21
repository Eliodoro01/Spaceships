#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lungh_elenco 10


/*************************************** STRUCT ********************************************/

struct data
{
int giorno;
char *mese;
int anno;
};


struct indirizzo
{
int cap;
int n_civico;
char *strada;
};


struct studente
{
char *nome;
char *cognome;
int matricola;
int assenze;
char *luogo_nascita;
struct data data_nascita;
struct indirizzo dati_ind;              //Per memorizzare le informazioni di ogni studente
}elenco[lungh_elenco]={                 //Viene utilizzato un array di struct
{"Eliodoro","Mascolo",12402547,0,"Castellammare Di Stabia",13,"Novembre",2001,80058,1,"Via Andolfi"},
{"Lorenzo","Ammendola",10138643,0,"Napoli",19,"Maggio",2000,80145,3,"Via Roma"},
{"Salvatore","Gallo",12918375,0,"Milano",21,"Marzo",2001,20122,15,"Via Roma"},
{"Giuseppe","Buonocore",17610182,0,"Roma",6,"Novembre",2001,00100,27,"Via Condotti"},
{"Vincenzo","Somma",12261494,0,"Pollena Trocchia",10,"Luglio",1999,80040,5,"Via Roma"},
{"Ugo","Coppola",13717442,0,"Milano",20,"Giugno",1967,20122,3,"Via Palazzo"},
{"Francesco","Cimmino",13026644,0,"Napoli",17,"Maggio",2002,80145,11,"Via Chiaia"},
{"Alessandro","Cesarano",14163033,0,"Bacoli",6,"Febbraio",2002,80070,19,"Via Catullo"},
{"FrancescaMaria","Luisi",11767696,0,"Napoli",2,"Agosto",2002,80145,31,"Via Montesanto"},
{"Francesco","Dantuono",12710908,0,"Napoli",30,"Settembre",2001,80145,15,"Via Salvatore Tommasi"},
};



/*************************************** PROCEDURE ********************************************/


// Procedure delle Funzioni

void assenze_corso(struct studente *);

void visualizza(struct studente *);

int ricerca_stud(struct studente *, char *,char *);

int max_assenze(struct studente *,int );

int max_I(int ,int );



/*************************************** MAIN ********************************************/


/*  La finalità di questo programma è quella di gestire i dati degli studenti di un corso universitario della durata
    di 20 giorni ed, in base alle nostre richieste, visualizzare lo studente con più assenze oppure cercare tramite
    nome e cognome un determinato studente e, se resente nell'elenco, visualizzare le sue informazioni.
*/


void main()
{
// Dichiaro le variabili che verranno utilizzate nel main

int scelta;                 //Scelta dell'utente
int i;                      //Variabile contatore del for
int i_trov;                 //Variabile usata per la chiamata alla funzione della ricerca dello studente
int i_max;                  //Variabile contenente l'indice dello studente con più assenze
int scelta_while;           //Variabile che conterrà la scelta dell'utente di rieseguire o meno il programma
int n = lungh_elenco;       //Variabile della lunghezza dell'array di struct dichiarata con il define
char cognome[20],nome[20];  //Stringhe contenti il cognome ed il nome inseriti dall'utente





printf("\n\t\tMenu per la gestione delle informazioni degli studenti di un corso universitario\n\n\n");

assenze_corso(elenco);      //Chiamata della funzione per la gestione delle assenze


do
{
//Menù visualizzato sul terminale
printf("\nElenco operazione effettuabili :");
printf("\n\nOperazione numero 1: Inserisci un nome e un cognome per visualizzare i dati e le assenze totali dello studente;\n\n");
printf("\n\nOperazione numero 2: Stampa il nome e il cognome dello studente che ha fatto piu assenze durante il corso universitario;\n\n");

//Scelta dell'operazione
printf("\nScegliere l' operazione che si vuole effetture\t ");
scanf("%d",&scelta);


//Esecuzione dell'operazione scelta
switch(scelta)
{

case 1:
//Visualizza le informazioni e le assenze dello studente cercato
{
//Richiesta del nome e del cognome dello studente
printf("\nInserisci il cognome da ricercare dello studente\n");

scanf("%s", &cognome);

printf("\nInserisci il nome da ricercare dello studente\n");
scanf("%s", &nome);

i_trov=ricerca_studente(elenco,cognome,nome);//Chiamata alla funzione che cerca lo studente


if (i_trov==-1)
//Se lo studente non è stato trovato la funzione ritorna -1 e viene stampato il messaggio "Lo studente non e' presente nell' elenco"
printf("\nLo studente non e' presente nell' elenco\n");
else
{
//Se lo studente è presente nell'elenco stampa le informazioni e le assenze
printf("\nDati dello studente:\n\n");               // stampo la persona in base all'indice che ritorna la funzione
printf("%s %s\nMatricola N.%d\nNumero di assenze:%d",elenco[i_trov].nome, elenco[i_trov].cognome,elenco[i_trov].matricola,elenco[i_trov].assenze);
printf("\nNato a %s il giorno %d %s %d",elenco[i_trov].luogo_nascita, elenco[i_trov].data_nascita.giorno,elenco[i_trov].data_nascita.mese,elenco[i_trov].data_nascita.anno);
printf("\nResidente in %s %d, CAP: %d\n\n",elenco[i_trov].dati_ind.strada, elenco[i_trov].dati_ind.n_civico,elenco[i_trov].dati_ind.cap);
printf("\n");
}
};break;

case 2:
//Se l'utente digita 2 lo switch eseguirà la funzione "max_assenze" e restituirà in output lo studente con più assenze
{
i_max=max_assenze(elenco,n);

for (i=0;i<lungh_elenco;i++)    //Ciclo for che stampa le informazioni dello studente con più assenze

if( i_max==elenco[i].assenze)   //Controllo se il valore massimo delle assenze è uguale all'indice i-esimo
{
//SE E' UGUALE, ALLORA STAMPA DEI DATI DELLO STUDENTE CHE HA EFFETTUATO PIU ASSENZE.
printf("\nDati dello studente che ha effattuato piu assenze:\n");
printf("%s %s\nMatricola:%d\nNumero di assenze:%d",elenco[i].nome,elenco[i].cognome,elenco[i].matricola,elenco[i].assenze);
printf("\nNato a %s il giorno %d %s %d",elenco[i].luogo_nascita,elenco[i].data_nascita.giorno,elenco[i].data_nascita.mese,elenco[i].data_nascita.anno);
printf("\nResidente in %s %d, CAP: %d\n\n",elenco[i].dati_ind.strada,elenco[i].dati_ind.n_civico,elenco[i].dati_ind.cap);
printf("\n");
}
};break;

default:
    printf("\n Opzione non presente nel Menu\n");

}//Fine dello switch

printf("\n\t\t\t\tPer Rieseguire il programma digitare 1\n\n \t\t\t\tPer Uscire digitare 0\n\n\t\t\t\t ");
scanf("%d",&scelta_while);


}

//Ciclo che si ripete fino a quando non si digita 0 e quindi si sceglie di uscire
while(scelta_while!=0); //Fine do-while

}//Fine Main



/*************************************** FUNZIONI ********************************************/



/*Questa function assegna casualmente le assenze grazie alla function C Rand che genera due valori:
0 e 1 inserendo il modulo %2, che vengono sommate al relativo studente giorno per giorno.
Il for esterno scorre i giorni mentre quello interno assegna 0 oppure 1 studente per studente.
A questa function viene passato l'array di strutture e in output non restiuisce nessun valore,
ma va a modificare, per indirizzo,il campo assenze di ogni array di strutture. */
void assenze_corso (struct studente *elenco)
{
int i,j;
int assenza_casuale;
int seed;


//Inserimento del seme che verrà utilizzato per generare numeri pseudo-casuali
printf("\nInserire il seme per simulare le assenze durante il corso \t ");
scanf("%d",&seed);
srand(seed);

for(i=0;i<20;i++) //Ciclo for esterno della durata del corso

for(j=0;j<lungh_elenco;j++) //Ciclo for interno che scorre tutti gli studenti ogni giorno e gli assegna i valori delle assenze
{
assenza_casuale=rand()%2;   //Rand ci restituirà i valori 0 o 1
elenco[j].assenze=(elenco[j].assenze+assenza_casuale); //Assegnazione valore casuale ad ogni studente

}

}//Fine function




/*Questa function usa la ricerca sequenziale con approccio iterativo per la ricerca di uno studente,
le vengono passate la struttura e le due chiavi(cognome e nome),e ritorna
un valore intero che corrisponde all'indice dello studente se è stato trovato.
Se non è stato trovato alcuno studente che corrisponda con i dati immessi da input
allora ritornerà il valore -1.*/

// Io ho ipotizzato che la ricerca studente mi ritorni una sola persona non prendo in considerazione omonimi
int ricerca_studente(struct studente *elenco, char *cognome, char *nome)
{
int i=0;
int ind_trovato=-1;
do{
    if(strcmp(elenco[i].cognome,cognome)==0) //Compara il cognome inserito all' i-esimo elemento dell' array con il cognome dato in input


    if(strcmp(elenco[i].nome,nome)==0) //Compara il nome inserito all' i-esimo elemento dell' array con il nome dato in input
    ind_trovato=i;                        //Se entrambi gli if sono veri allora l'indice_trovato è proprio i-esimo elemento che si sta comparando
i++;
}
while(ind_trovato<-1||i<lungh_elenco);    //Il ciclo si ripete fino a quando indice_trovato è minore di -1 oppure i è minore della lunghezza dell'elenco(10)

return ind_trovato;                        //Ritorna il valore dell'indice trovato
}//Fine function



/*Questa function calcola il massimo valore delle assenze dell'array di strutture.
Per questa function è stata utilizzata la tecnica della programmazione ricorsiva.
Viene passato l'array di strutture e il size dell'array di struttura e ritorna il valore massimo di assenze effettuate dagli studenti.*/
int max_assenze(struct studente *elenco,int n)
{
int med;                            //Valore mediano dell'array

if(n==1)                            //Caso banale, se n è uguale ad 1 abbiamo trovato il nostro obiettivo
{
return elenco[0].assenze;           //Ritorna l'elemento di indice 0 (il primo elemento) dell'array di struct
}
else                                //Se n è diverso da 1
{
med=(n-1)/2;                        //Calcolo del mediano

return max_I(max_assenze(elenco,med+1),max_assenze(elenco+med+1,n-med-1)); /*richiamo un'altra funzione che mi dice chi è il massimo tra due numeri interi a cui passo proprio
                                                                            questa funzione così che l'array verrà diviso, fino a quando non si presenterà il caso banale (n == 1) dove si troverà l'elemeno più grande*/
}
}//Fine function

/*Questa function calcola il massimo tra due numeri interi, come input ha due interi e ritorna il numero maggiore tra i due.*/
int max_I(int a,int b)
{
if (a<b)
return b;   //Se a è minore di b ritorna b
else
return a;   //Altrimenti ritorna a

}
