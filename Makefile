PLIKI = main.c logic.c io.c
CC = gcc

baza.exe: $(PLIKI)
	$(CC) $(PLIKI) -o baza.exe

clean:
	rm -f baza.exe