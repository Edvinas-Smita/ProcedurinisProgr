/*
Edvinas Smita - VU MIF PS 1k. 2gr.
*/

#include <stdio.h>
#include <stdlib.h>

#include <UZD4HDR.h>

listName *structPointer=NULL;

int main()
{
	unsigned int choice;
	char correctInputBool;
	
	printf("'1'-prideti N saraso elementu su ivestomis reiksmemis po dabartinio saraso galo\n");
	printf("'2'-irasyti reiksme X i I-taji saraso elementa\n");
	printf("'3'-iterpti N saraso elementu nuo I pozicijos su ivestomis reiksmemis\n");
	printf("'5'-istrinti N saraso elementu nuo galo\n");
	printf("'6'-istrinti N saraso elementu nuo I-tojo elemento\n");
	printf("'7'-sukeisti saraso elementus I ir J\n");
	printf("'8'-sukeisti N saraso elementu nuo I su M saraso elementu nuo J\n");
	printf("'9'-atvaiztuoti sarasa\n");
	printf("'10'-uzpildyti saraso sarasa didejancioms reiksmemis\n");
	printf("'11'-apkeisti saraso krypti nuo I iki J\n");
	printf("'12'-istrinti visa sarasa\n");
	
	printf("'0'-iseiti\n");
	
	printf("Iveskite skaiciu funkcijos, ka programa turi daryti: ");
	correctInputBool=scanf("%d", &choice);
	if(correctInputBool==0 || correctInputBool==EOF)
	{
		printf("T A I   N E   S K A I C I U S\n");
		return 123456789;
	}
	if(structPointer==NULL && choice!=1 && choice!=0)
	{
		printf("Dar nera sukurto saraso. Sarasa galite sukurti ivede '1'\n");
		main();
	}
	int X, i, additional;
	unsigned int N, M, I, J;
	switch(choice)
	{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			printf("Pasirinkta '1'-prideti N saraso elementu su ivestomis reiksmemis po dabartinio saraso galo\n");
			printf("Iveskite N>0: ");
			scanf("%d", &N);
			for(i=0; i<N; i++)
			{
				printf("Turima %d is %d reiksmiu. Iveskite %d reiksme: ", i, N, i+1);
				scanf("%d", &X);
				additional=appendOneItemToEndWithValX(&structPointer, X);
				if(additional)
				{
					break;
				}
			}
			if(additional)
			{
				printf("Nepavyko sukurti visu elementu.\n", additional);
				break;
			}
			else
			{
				printf("Sekmingai sukurti visi elementai.\n");
			}
	
			break;
		}
		case 2:
		{
			printf("Pasirinkta '2'-irasyti reiksme X i I-taji saraso elementa\n");
			printf("Iveskite X ir I: ");
			scanf("%d %d", &X, &I);
			if(setValueXToStructItemI(structPointer, X, I))
			{
				printf("Nepavyko priskirti reiksmes.\n");
			}
			else
			{
				printf("Reiksme priskirta sekmingai.\n");
			}
			break;
		}
		case 3:
		{
			printf("Pasirinkta '3'-iterpti N saraso elementu nuo I pozicijos su ivestomis reiksmemis\n");
			printf("Iveskite N>0, I: ");
			scanf("%d %d", &N, &I);
			for(i=0; i<N; i++)
			{
				printf("Turima %d is %d reiksmiu. Iveskite %d reiksme: ", i, N, i+1);
				scanf("%d", &X);
				additional=insertOneItemAtIPosWithValX(&structPointer, I+i, X);
				if(additional)
				{
					break;
				}
			}
			if(additional)
			{
				printf("Nepavyko sukurti visu elementu.\n", additional);
				break;
			}
			else
			{
				printf("Sekmingai sukurti visi elementai.\n");
			}
	
			break;
		}
		case 5:
		{
			printf("Pasirinkta '5'-istrinti N saraso elementu nuo galo\n");
			printf("Iveskite N>0: ");
			scanf("%d", &N);
			if(deleteNItemsFromStructEnd(&structPointer, N))
			{
				printf("Istrintas visas sarasas.\n");
			}
			else
			{
				printf("Sekmingai sutrumpintas sarasas.\n");
			}
			break;
		}
		case 6:
		{
			printf("Pasirinkta '6'-istrinti N saraso elementu nuo I-tojo elemento\n");
			printf("Iveskite N ir I: ");
			scanf("%d %d", &N, &I);
			if(deleteNItemsFromIPos(&structPointer, N, I))
			{
				printf("Nesekmingai sutrumpintas sarasas.\n");
			}
			else
			{
				printf("Sekmingai sutrumpintas sarasas.\n");
			}
			break;
		}
		case 7:
		{
			printf("Pasirinkta '7'-sukeisti saraso elementus I ir J\n");
			printf("Iveskite I ir J: ");
			scanf("%d %d", &I, &J);
			if(swapStructItemsByIndex(&structPointer, I, J))
			{
				printf("Nepavyko apkeisti elementu.\n");
			}
			else
			{
				printf("Elementai apkeisti sekmingai.\n");
			}
			break;
		}
		case 8:
		{
			printf("Pasirinkta '8'-sukeisti N saraso elementu nuo I su M saraso elementu nuo J\n");
			printf("Iveskite N>0, I, M>0, J: ");
			scanf("%d %d %d %d", &N, &I, &M, &J);
			if(swapMultipleStructItemsByIndex(&structPointer, N, I, M, J))
			{
				printf("Nepavyko apkeisti elementu.\n");
			}
			else
			{
				printf("Elementai apkeisti sekmingai.\n");
			}
			break;
		}
		case 9:
		{
			printf("Pasirinkta '9'-atvaiztuoti sarasa\n");
			printStructChain(structPointer);
			break;
		}
		case 10:
		{
			printf("Pasirinkta '10'-uzpildyti saraso sarasa didejancioms reiksmemis\n");
			fillValues(structPointer);
			break;
		}
		case 11:
		{
			printf("Pasirinkta '11'-apkeisti saraso krypti nuo I iki J\n");
			printf("Iveskite I ir J: ");
			scanf("%d %d", &I, &J);
			if(reverseOrderIToJ(&structPointer, I, J))
			{
				printf("Nepavyko apkeisti krypties.\n");
			}
			else
			{
				printf("Kryptis apkeista sekmingai.\n");
			}
			break;
		}
		case 12:
		{
			printf("Pasirinkta '12'-istrinti visa sarasa\n");
			if(freeAll(&structPointer))
			{
				printf("Sarasas istrintas sekmingai.\n");
			}
			else
			{
				printf("Sarasas istrintas nesekmingai.\n");
			}
			break;
		}
		default:
		{
			printf("Neatpazintas pasirinkimas! Bandykite dar karta!\n");
			break;
		}
	}
	main();
}
