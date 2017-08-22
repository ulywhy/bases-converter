#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef bool
#define bool short
#define true 1
#define false 0
#endif



#ifndef _BASIC_OP_
#define _BASIC_OP_

//a nice macro
#define NEGATIVE(x) (0 >= x)

int consume(){
	char * string = NULL;
	size_t size = 0;
	getline(&string, &size, stdin); 
	return (string != NULL) ? 1 : 0;
}

void clear(void){
	printf("\033[H\033[J");
	return;
}

short getShort(void){
	short int number;
	scanf("%hd", &number);
	consume();
	return number;
}

char getChar(){
	char letter;
	scanf("%c", &letter);
	consume();
	return letter;
}

bool binaryCharDecision(const char* statement, char yes, char no){
	char option;
	char lower, upper;
	int len = strlen(statement);
	int j;
	
	do{
		puts(statement);
		for(j= 0; j < len/2; ++j){
			printf(" ");
		}
		printf("(%c/%c)  ", yes, no);
		option = getChar();
		lower = tolower(option);
		upper = toupper(option);
		
		if(lower == tolower(yes) || upper == toupper(yes))
			return true;
		else if(lower == tolower(no) || upper == toupper(no))
			return false;
	}while(true);
}
#endif
