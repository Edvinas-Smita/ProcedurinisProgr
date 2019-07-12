#include <stdio.h>

void calc(int menBool[], int menLiko[], int *dienuSkaicius)
{
	int likoLaisvuDienuBool, i;
	do
	{
		likoLaisvuDienuBool=0;
		for(i=0; i<12; i++)
			if(menBool[i] && menLiko[i]>0)
				likoLaisvuDienuBool=1;
		for(i=0; i<12; i++)
			if(menBool[i] && menLiko[i] && *dienuSkaicius>0)
			{
				menLiko[i]--;
				(*dienuSkaicius)--;
			}
	} while(likoLaisvuDienuBool && *dienuSkaicius>0);
}

int main()
{
	int menBool[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};		//ar menesis pasirinktas (bool)
	int menDienu[12] = {22, 19, 23, 19, 22, 22, 20, 22, 21, 22, 21, 19};		//menesiu darbo dienu skaicius
	int menLiko[12] = {22, 19, 23, 19, 22, 22, 20, 22, 21, 22, 21, 19};		//menesyje likusiu darbo dienu skaicius
	int menesiuPasirinkimas, dienuSkaicius, i;
	printf("Iveskite mokslo menesiu skaicius. Ivedus 0 ivedimas baigiamas:\n");
	do
	{
		printf("Menuo: ");
		scanf("%d", &menesiuPasirinkimas);
		if(menesiuPasirinkimas>0 && menesiuPasirinkimas<13 && menBool[menesiuPasirinkimas-1])
		{
			menBool[menesiuPasirinkimas-1]=0;
			printf("%d men. pasirinkimas panaikintas\n", menesiuPasirinkimas);
		}
		else if(menesiuPasirinkimas>0 && menesiuPasirinkimas<13 && !menBool[menesiuPasirinkimas-1])
		{
			menBool[menesiuPasirinkimas-1]=1;
			printf("%d men. pasirinktas\n", menesiuPasirinkimas);
		}
		if(menesiuPasirinkimas<0 || menesiuPasirinkimas>12)
			printf("Neteisingas ivedimas. Iveskite sveika skaiciu is sio intervalo: [0; 12].\n");
	} while(menesiuPasirinkimas!=0);
	printf("Pasirinkimas baigtas.\nIveskite kiek dienu bus mokomasi:\n");
	scanf("%d", &dienuSkaicius);
	calc(menBool, menLiko, &dienuSkaicius);
	for(i=0; i<12; i++)
		if(menBool[i])
			printf("%d menesio mokslo dienu skaicius: %d.\n", (i+1), (menDienu[i]-menLiko[i]));
	if(dienuSkaicius>0)
		printf("Netilpusiu dienu kiekis: %d\n", dienuSkaicius);
	return 0;
}
