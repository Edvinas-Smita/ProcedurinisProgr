#uzd3.out: UZD3FUNKC.c UZD3.c
#	gcc -std=c89 UZD3.c UZD3FUNKC.c -o uzd3.out -I .
	
uzd3.out: uzd3funkc.o uzd3.o
	gcc -std=c89 uzd3.o uzd3funkc.o -o uzd3.out
	
uzd3funkc.o: UZD3FUNKC.c
	gcc -c -std=c89 UZD3FUNKC.c -o uzd3funkc.o
	
uzd3.o: UZD3.c
	gcc -c -std=c89 UZD3.c -o uzd3.o -I .
	
clean:
	rm *.o
