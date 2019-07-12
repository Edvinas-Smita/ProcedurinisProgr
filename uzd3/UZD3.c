/*
Edvinas Smita VU MIF PS 1k. 2gr.
*/
#define maxLine 255

#include <stdio.h>
#include <stdlib.h>

#include <UZD3HD.h>

int main(int argc, char **argv)
{
	if(argc<3)
	{
		printf("Syntax: %s \"inputFileName.txt\" \"outputFileName.txt\"\n", argv[0]);
		return 1;
	}
	if(argv[1]==argv[2])
	{
		printf("Input and output files should not be the same.\n");
		return 2;
	}
	FILE *inFile;
	inFile=fopen(argv[1], "r");
	if(!inFile)
	{
		fclose(inFile);
		printf("Something went wrong in opening the input file \"%s\".\n", argv[1]);
		return 3;
	}
	FILE *outFile;
	outFile=fopen(argv[2], "w");
	if(!outFile)
	{
		fclose(inFile);
		fclose(outFile);
		printf("Something went wrong in opening the output file \"%s\".\n", argv[2]);
		return 4;
	}
	
	int lineLength;
	char *line=NULL;
	char *outputLine=NULL;
	
	while(readMaxLineChars(&line, inFile))
	{
		swapWordOrder(line, &outputLine);
		fprintf(outFile, "%s", outputLine);
	}
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
