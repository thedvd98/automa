
## USAGE
./automa fileconfigurazione_automa inputstring

### COSA FA?
Il programma verifica se la inputstring appartiene al linguaggio descritto dall'automa.

### FILE CONFIGURAZIONE
File di configurazione dell'automa
	Ogni riga corrisponde ad una "freccia" che va dallo stato di partenza a quello di arrivo.
	Lo stato iniziale è sempre lo zero.
	Tutti gli stati devono essere numer interi.
	Anche l'ultima riga deve avere un a capo \n
	
	Esempio:
		0 a 1 0	
		1 a 0 -1
	Con queste due righe l'automa accetterà solo stringhe con un numero di a dispari.
	la prima riga indica che dallo stato 0 si va allo stato 1 in caso si legga una 'a'. L'ultimo zero indica che non è uno stato finale.
	la seconda riga indica che quando si è nello stato 1 si va allo stato 0 se si legge un 'a'. L'ultimo -1 indica che è uno stato finale.
