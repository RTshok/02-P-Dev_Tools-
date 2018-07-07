#include <stdio.h>
#include "factorization.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

double timespec_diff(struct timespec *stop, struct timespec *start)
{
	double diff = difftime(stop->tv_sec, start->tv_sec);
	diff *= 1000;
	diff += (stop->tv_nsec - start->tv_nsec) / 1e6;
	return diff;
}

void fillarray( int *array,int amountofelements,int base)
{
for (int i = 0; i<amountofelements;i++)
array[i] = i+base*i;
}


int main(int argc,char *argv[])
{
char FileName[20];
int amountofarrays = 0;
int base = 2;
if (argc == 1)	goto exc_noargs;
if(argc>1){
amountofarrays = atoi(argv[1]);
if (argc==3)
base = atoi(argv[2]);
if (argc ==4)
strcpy(FileName,argv[3]);


if (amountofarrays <=0)
goto one_element;

}

FILE *file;
file = fopen (FileName,"w");
fprintf(file,"#AmountOfElements,N		#TimeOfSorting,ms");
struct timespec time_now, time_after;
double time=0; 
int tmp = amountofarrays;
int *array;
for (int i =0; i<amountofarrays;i++)
{
tmp = tmp*i*i*i+tmp;
array = malloc(tmp*sizeof(*array));
fillarray(array,tmp,base);
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_now);
for(int j = 0;j<tmp;j++)
{
NumFactor(array[j]);
}
clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_after);
time = timespec_diff(&time_after, &time_now);
fprintf(file,"\n%d					%g",tmp,time);
free(array);
tmp = amountofarrays;
}
fflush(file);
fclose(file);
return 0;

exc_noargs:
	printf("Error: no arguments provided\n");
	goto exc_usage;
exc_usage:
	printf("Usage:\n <AmountOfArrays> <Base to pow f.e 3,4..> <file name>or <0||-1>to input one exact num \n");
	return 1;
one_element:
	printf("Print the element to factorize :\n");
	 int elem = 0;
	scanf("%i",&elem);
	NumFactor(elem);
	return 0;

}