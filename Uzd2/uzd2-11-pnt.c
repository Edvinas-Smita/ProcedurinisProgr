/*
Edvinas Smita VU MIF PS 1k. 2gr.
*/
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

void **apdorojimas(int **ab, int g, int n, int *nApdoroto, int ***apdorotas)
{
	int i, j=0, tinkamuPoruSkaicius=0;
	for(i=0; i<n; i++)
		if(checkIfInIntervalBool(ab[0][i], ab[1][i], g))
			tinkamuPoruSkaicius++;
	*(apdorotas)=malloc(3*sizeof(int*));
	*(*(apdorotas))=malloc(tinkamuPoruSkaicius*sizeof(int));
	*(*(apdorotas)+1)=malloc(tinkamuPoruSkaicius*sizeof(int));
	*(*(apdorotas)+2)=malloc(tinkamuPoruSkaicius*sizeof(int));
	for(i=0; i<n; i++)
		if(checkIfInIntervalBool(*(*(ab)+i), *(*(ab+1)+i), g))
		{
			*(*(*(apdorotas))+j)=*(*(ab)+i);
			*(*(*(apdorotas)+1)+j)=*(*(ab+1)+i);
			*(*(*(apdorotas)+2)+j)=i;
			j++;
		}
	*nApdoroto=tinkamuPoruSkaicius;
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
	int **ab;
	ab=malloc(2*sizeof(int*));
	*ab=malloc(n*sizeof(int));
	*(ab+1)=malloc(n*sizeof(int));
	printf("Iveskite %d skaiciu poru:\n", n);
	for(i=0; i<n; i++)
	{
		printf("Turima %d is %d poru. Iveskite %d pora: ", i, n, (i+1));
		yraSkaicius=scanf("%d %d", (*ab)+i, (*(ab+1)+i));
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
	int **apdorotas;
	int nApdoroto;
	apdorojimas(ab, g, n, &nApdoroto, &apdorotas);
	for(i=0; i<nApdoroto; i++)
		printf("%d-os poros intervale [%d, %d] yra skaicius %d.\n", (*(*(apdorotas+2)+i)+1), *(*(apdorotas)+i), *(*(apdorotas+1)+i), g);
	return 0;
}
