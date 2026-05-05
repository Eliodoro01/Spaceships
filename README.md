# Progetto d'Esame di Laboratorio — Mascolo Eliodoro

Progetto universitario sviluppato in C per l'esame di Laboratorio presso l'**Università degli Studi di Napoli Parthenope**.  
Matricola: `0124002547`

---

## Struttura del progetto

```
├── ProgettiC/
│   ├── Progetto_navicelle/   # Simulazione navicelle spaziali
│   └── Corso_universitario/  # Gestione studenti corso universitario
├── images/                   # Immagini e screenshot delle simulazioni
├── index.html                # Pagina principale del progetto
├── navicelle.html            # Pagina del progetto navicelle
├── corsouniversitario.html   # Pagina del progetto corso universitario
└── Pr_Mascolo_Eliodoro.pdf   # Traccia del progetto
```

---

## Progetto 1 — Navicelle Spaziali

### Descrizione

Simulazione di un gioco ispirato alla battaglia navale su una mappa rettangolare **8×7**.  
Tre navicelle si muovono sul campo e devono essere abbattute da un cannone fisso.

### Elementi del campo

| Simbolo | Elemento |
|---------|----------|
| `G` | Navicella Gialla |
| `B` | Navicella Blu |
| `V` | Navicella Verde |
| `R` | Cannone (fisso in posizione `[7][3]`) |
| `.` | Cella vuota |

### Regole di movimento

Ogni turno viene generato un numero casuale da 0 a 9 per ciascuna navicella:

- **Gialla (G):** 60% di probabilità di muoversi di 1 passo a destra, 40% di restare ferma.
- **Blu (B):** 70% di probabilità di muoversi di 2 passi a sinistra, 30% di muoversi di 1 passo a sinistra.
- **Verde (V):** 40% di muoversi di 3 passi a destra, 30% di 2 passi a destra, 30% di 1 passo a destra.

Le navicelle si avvolgono al bordo opposto quando raggiungono il limite del campo.

### Meccanica di sparo

Il cannone colpisce una navicella se questa si trova nelle colonne **2, 3 o 4** (zona centrale).  
La partita termina quando tutte e tre le navicelle sono state distrutte oppure dopo **100 passi**.

### Funzioni principali

| Funzione | Descrizione |
|----------|-------------|
| `muovi_gialla()` | Sposta la navicella gialla in base al numero random |
| `muovi_verde()` | Sposta la navicella verde in base al numero random |
| `muovi_blu()` | Sposta la navicella blu in base al numero random |
| `controllo()` | Controlla se una navicella si trova nella zona di fuoco |
| `pulisci()` | Rimuove dalla matrice la navicella colpita |

### Compilazione ed esecuzione

```bash
gcc main.c -o navicelle
./navicelle
```

---

## Progetto 2 — Gestione Corso Universitario

### Descrizione

Programma per la gestione dei dati degli studenti di un corso universitario della durata di **20 giorni**.  
L'elenco contiene 10 studenti pre-caricati, con relative informazioni anagrafiche e di residenza.

### Strutture dati

```c
struct studente {
    char *nome, *cognome;
    int matricola, assenze;
    char *luogo_nascita;
    struct data data_nascita;
    struct indirizzo dati_ind;
};
```

### Funzionalità

Il programma presenta un menù interattivo con due operazioni:

1. **Ricerca studente** — inserendo nome e cognome, visualizza tutti i dati e le assenze dello studente.
2. **Studente con più assenze** — trova e visualizza lo studente che ha accumulato il maggior numero di assenze durante il corso.

Le assenze vengono assegnate casualmente (0 o 1 per ogni giorno) usando un seme inserito dall'utente.

### Algoritmi implementati

- **Ricerca sequenziale iterativa** — per trovare uno studente per nome e cognome.
- **Massimo ricorsivo** — `max_assenze()` usa la tecnica *divide et impera* per trovare il massimo numero di assenze nell'array di strutture.

### Compilazione ed esecuzione

```bash
gcc main.c -o corso_universitario
./corso_universitario
```

---

## Interfaccia Web

Le pagine HTML (`index.html`, `navicelle.html`, `corsouniversitario.html`) presentano entrambi i progetti con la traccia del problema, il codice sorgente e gli screenshot delle simulazioni effettuate.

---

## Tecnologie utilizzate

- **Linguaggio:** C (standard C99)
- **IDE:** Code::Blocks
- **Librerie:** `stdio.h`, `stdlib.h`, `time.h`, `string.h`
- **Frontend:** HTML
