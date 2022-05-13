#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int cNums = 0;  
	int wNums = 0;
	FILE* file;	
	file = fopen(argv[argc-1], "r");
	
	if (file == NULL)
	{
		printf("NO FILE");
		return 0;
	}
	
	count(file, &cNums, &wNums);

	int i=0;
	while(i<argc-1)
	{
		if (strcmp(argv[i], "-c") == 0)
		{
			printf("×Ö·ûÊý£º%d\n", cNums);
		
		} else if (strcmp(argv[i], "-w") == 0)
		{
			printf("µ¥´ÊÊý£º%d\n", wNums);
		}
		i++;
	} 
		
	fclose(file);
	
	return 0;
}

int count(FILE* file, int* cNums, int* wNums) 
{
	int flag = 0;
	char temp;
	
	while ((temp = fgetc(file)) != EOF)
	{
		(*cNums)++;
		if (flag == 0 && (temp != ' ' || temp != ',')) 
		{
			(*wNums)++;
			flag = 1;
		}
		else if (temp == ' ' || temp == ',')
			flag = 0;
	}	
	return 0;
}
