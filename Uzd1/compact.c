#include <stdio.h>
#include <math.h>
int main()
{
	int userInput, nKvadratu=0;
	scanf("%d", &userInput);
	while (userInput)
	{
		if (sqrt(userInput)==(int)sqrt(userInput))
			nKvadratu++;
		scanf("%d", &userInput);
	}
	printf("Rasta kvadratu: %d.\n", nKvadratu);
}
