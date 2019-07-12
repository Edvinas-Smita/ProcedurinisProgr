#include <stdio.h>
#include <stdlib.h>

void calc(int* men, int* nDien)
{
	int i=0, dienNetelpa=0;
	if(*nDien>240)
	{
		dienNetelpa=(*nDien)-240;
		*nDien=240;
	}
	while(*nDien)
	{
		if(i==0) (*(men))++;
		else if(i==1) (*(men+6))++;
		else if(i==2) (*(men+3))++;
		else if(i==3) (*(men+9))++;
		else if(i==4) (*(men+4))++;
		else if(i==5) (*(men+10))++;
		else if(i==6) (*(men+1))++;
		else if(i==7) (*(men+2))++;
		else if(i==8) (*(men+5))++;
		else if(i==9) (*(men+7))++;
		else if(i==10) (*(men+8))++;
		else if(i==11) (*(men+11))++;
		i++;
		if(i==12) i=0;
		(*nDien)--;
	}
	*nDien=dienNetelpa;
}

int main()
{
	int *men;
	men=malloc(12*sizeof(int));
	int dienuSkaicius, i;
	printf("Iveskite kiek dienu bus mokomasi:\n");
	scanf("%d", &dienuSkaicius);
	calc(men, &dienuSkaicius);
	for(i=0; i<12; i++)
		printf("%d menesio mokslo dienu skaicius: %d.\n", (i+1), *(men+i));
	if(dienuSkaicius>0)
		printf("Netilpusiu dienu kiekis: %d\n", dienuSkaicius);
	return 0;
}
