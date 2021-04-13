
## USAGE
./automa fileconfigurazione inputstring

./regexp something | ./automa inputstring

### COSA FA?
Automa: Il programma verifica se la inputstring appartiene al linguaggio descritto dall'automa.
Regexp: ...

### FILE CONFIGURAZIONE
File di configurazione dell'automa
	Ogni riga corrisponde ad una "freccia" che va dallo stato di partenza a quello di arrivo.
	Lo stato iniziale è sempre lo zero.
	Tutti gli stati devono essere numer interi.
	Anche l'ultima riga deve avere un a capo \n
	
	Esempio:
		1 -1
		0 a 1 0	
		1 a 0 0
	Con queste tre righe l'automa accetterà solo stringhe con un numero di a dispari.
	La prima riga è la lista di stati finali separati da spazio e che termina sempre in -1
	la seconda riga indica che dallo stato 0 si va allo stato 1 in caso si legga una 'a'. L'ultimo zero è riservato per operazioni speciali
	la terza riga indica che quando si è nello stato 1 si va allo stato 0 se si legge un 'a'. L'ultimo 0 è riservato
