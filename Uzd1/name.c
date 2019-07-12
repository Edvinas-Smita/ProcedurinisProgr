#include <stdio.h>
#include <math.h>

void main()
{
	int userInput, nKvadratu=0;
	printf("Iveskite skaiciu seka ir baikite su 0:\n");
	scanf("%d", &userInput);
	while (userInput)
	{
		if (sqrt(userInput)==(int)sqrt(userInput))
			nKvadratu++;
		scanf("%d", &userInput);
	}
	if ((10<nKvadratu && nKvadratu<20) || nKvadratu==0)
		printf("Sekoje rasta %d kvadratu.\n", nKvadratu);
	else if (nKvadratu%10==1)
		printf("Sekoje rastas %d kvadratas.\n", nKvadratu);
	else
		printf("Sekoje rasti %d kvadratai.\n", nKvadratu);
}
