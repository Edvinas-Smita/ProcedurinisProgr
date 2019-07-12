/*
Edvinas Smita VU MIF PS 1k. 2gr.
*/
#ifndef maxLine
#define maxLine 255
#endif

#include <stdio.h>
#include <stdlib.h>

void exchangeSubstrings(int startPos1, int endPos1, int startPos2, int endPos2, const char const *inputString, const int stringLength, char **outputString)
{
	int subLen1=endPos1-startPos1+1, subLen2=endPos2-startPos2+1, i;
	char temp[stringLength];
	for(i=0; i<(stringLength+1); i++)
		temp[i]=inputString[i];
	
	for(i=0; i<startPos1; i++)
		(*outputString)[i]=temp[i];						/*Nekeiciama viskas kaireje*/
	for(i=0; i<subLen2; i++)
		(*outputString)[startPos1+i]=temp[startPos2+i];				/*Pirma dalis <- Antra dalis*/
	for(i=0; i<(startPos2-endPos1); i++)
		(*outputString)[startPos1+subLen2+i]=temp[startPos1+subLen1+i];		/*Vidurine dalis slenkasi per substringu ilgio skirtuma*/
	for(i=0; i<subLen1; i++)
		(*outputString)[startPos2-subLen1+subLen2+i]=temp[startPos1+i];		/*Pirma dalis -> Antra dalis*/
	for(i=0; i<(stringLength-endPos2); i++)
		(*outputString)[endPos2+1+i]=temp[endPos2+1+i];				/*Nekeiciama viskas desineje*/
	
	/*printf("________________________________________________________________________________\n");
	printf("%d %d %d %d\n", startPos1, endPos1, startPos2, endPos2);
	printf("%*s%*s%*s%*s\n", startPos1+1, "v", subLen1-1, "v", startPos2-endPos1, "v", subLen2-1, "v");
	printf("%s", inputString);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%s", *outputString);
	printf("________________________________________________________________________________\n");*/
}

int findAndSwapWords(const char const *inputLine, const int lineLength, char **outputLine, int j)
{
	int i, nWords=0, wordStartBool=0;
	int zodzioVieta[lineLength];
	for(i=0; i<lineLength+1; i++)
	{
		if(wordStartBool)
		{
			if((inputLine[i]==' ') || (inputLine[i]=='\n'))
			{
				zodzioVieta[2*nWords+1]=i-1;
				wordStartBool=0;
				++nWords;
			}
		}
		else
		{
			if((inputLine[i]!=' ') && (inputLine[i]!='\n') && (inputLine[i]!='	'))
			{
				zodzioVieta[2*nWords]=i;
				wordStartBool=1;
			}
		}
	}
	if(nWords>1)
	{
		exchangeSubstrings(zodzioVieta[2*j], zodzioVieta[2*j+1], zodzioVieta[2*nWords-2*(j+1)], zodzioVieta[2*nWords-2*(j+1)+1], inputLine, lineLength, outputLine);
		if(j<nWords/2-1)
			findAndSwapWords(*outputLine, lineLength, outputLine, j+1);
		return nWords/2;
	}
	return 0;
}

int readMaxLineChars(char **line, FILE *inFile)
{
	int lineLength=-1, i;
	
	if((*line)!=NULL)
		free((*line));
	(*line)=malloc(maxLine*sizeof(char));
	for(i=0; i<maxLine; (*line)[i++]=0);
	
	do
		(*line)[++lineLength]=getc(inFile);
	while(((*line)[lineLength]!='\n') && ((*line)[lineLength]!=EOF) && (lineLength<maxLine));
	
	if((lineLength==maxLine) && ((*line)[lineLength]!='\n'))
		while(getc(inFile)!='\n');
	if((*line)[lineLength]==EOF)
		return 0;
	return 1;
}

void swapWordOrder(const char const *line, char **outputLine)
{
	int lineLength=0, i;
	while(line[lineLength+1]!=0)
		lineLength++;
	
	if((*outputLine)!=NULL)
	{
		for(i=0; i<maxLine; (*outputLine)[i++]=0);
		free((*outputLine));
	}
	(*outputLine)=malloc(maxLine*sizeof(char));
	for(i=0; i<maxLine; i++)
		(*outputLine)[i]=line[i];
	
	findAndSwapWords(line, lineLength, outputLine, 0);
}
