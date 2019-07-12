#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2)
{
	int temp=*num1;
	*num1=*num2;
	*num2=temp;
}

int checkIfInIntervalBool(int intervalStart, int intervalEnd, int num)
{
	if(intervalStart>intervalEnd) swap(&intervalStart, &intervalEnd);
	if(num>=intervalStart && num<=intervalEnd)
		return 1;
	return 0;
}

void apdorojimas(int ab[][2], int g, int n, int *nApdoroto, int apdorotas[][3])
{
	int i, j=0;
	for(i=0; i<n; i++)
		if(checkIfInIntervalBool(ab[i][0], ab[i][1], g))
		{
			apdorotas[j][0]=ab[i][0];
			apdorotas[j][1]=ab[i][1];
			apdorotas[j][2]=i;
			j++;
		}
	*nApdoroto=j;
}

int main()
{
	int n, g, i, yraSkaicius;
	printf("Iveskite skaiciu N: ");
	yraSkaicius=scanf("%d", &n);
	if(yraSkaicius!=1)
	{
		printf("Tai ne skaicius.\n");
		return 0;
	}
	int ab[n][2];
	printf("Iveskite %d skaiciu poru:\n", n);
	for(i=0; i<n; i++)
	{
		printf("Turima %d is %d poru. Iveskite %d pora: ", i, n, (i+1));
		yraSkaicius=scanf("%d %d", &ab[i][0], &ab[i][1]);
		if(yraSkaicius!=2)
		{
			printf("Tai ne skaicius.%d\n", yraSkaicius);
			return 0;
		}
	}
	printf("Iveskite G: ");
	yraSkaicius=scanf("%d", &g);
	if(yraSkaicius!=1)
	{
		printf("Tai ne skaicius.\n");
		return 0;
	}
	int apdorotas[n][3];
	int nApdoroto;
	apdorojimas(ab, g, n, &nApdoroto, apdorotas);
	for(i=0; i<nApdoroto; i++)
		printf("%d-os poros intervale [%d, %d] yra skaicius %d.\n", apdorotas[i][2]+1, apdorotas[i][0], apdorotas[i][1], g);
	return 0;
}
