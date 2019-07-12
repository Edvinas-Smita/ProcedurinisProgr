uzd4.out: uzd4funkc.o uzd4main.o
	gcc -std=c89 uzd4main.o uzd4funkc.o -o uzd4.out
	
uzd4funkc.o: UZD4FUNKC.c
	gcc -c -std=c89 UZD4FUNKC.c -o uzd4funkc.o
	
uzd4main.o: UZD4MAIN.c
	gcc -c -std=c89 UZD4MAIN.c -o uzd4main.o -I .
	
clean:
	rm *.o
