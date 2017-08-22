#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "basic.h"

#ifndef HEX_LUT
#define HEX_LUT (char*) {"ABCDEF\0"}
#endif

#ifndef __BASE_OPERATIONS__
#define __BASE_OPERATIONS__


bool sign(const char *, short);
int getHexValue(char);
void Comp1(char *, short);
void Comp2(char *, short);
char * extend(char *, short, char);

bool sign(const char * number, short base){
	int length = strlen(number);
	int num_of_digits = ceil(log2(base));
	int num_of_bits = num_of_digits * length;
	int msb = 0;//most significant bit
	int new_length = 0;

	for(new_length = 1; new_length < num_of_bits; new_length *= 2);
		
	msb = getHexValue(number[0]);
	//if msb is less than base/2 (half the digits on that base) then is positive
	return ( msb >= base/2 && num_of_bits == new_length) ? true : false;
}

char getHexDigit(int h){
	char c;
	if(h > 10){
		sprintf(&c, "%c", 'A' + (h - 10) );
	}else{
		sprintf(&c, "%d", h);
	}
	return c;
}

int getHexValue(char d){
	int value = 0;
	char digit = d;
	if( isalpha(digit) ){
		value = (int)(toupper(digit) - 'A');//get the index of the digit
		value += 10;
	}else{
		value = atoi(&digit);
	}
	return value;
}

void Comp1(char * num, short base){
	//expevts num to be a string of only digits
	printf("\t(Complement %d)", base-1);
	int a = 0;
	int b = base-1;//higher digit for the given base
	int len = strlen(num);
	int limit = 0;
	for(int x = len - 1; x >= 0; --x){
		a = getHexValue(num[x]);
		//take away from b and get its corresponding hex digit
		num[x] = getHexDigit(b - a);
	}
	printf(" %s\n", num);
}

void Comp2(char * num, short base){
	printf("\t(Complement %d)", base);
	int a = 0;
	int b = base - 1;
	int carr = 1;//begins at 1 to add the 1 needed for the compliment
	int len = strlen(num);
	int x;
	
	for(x = len - 1; x >= 0 && carr != 0 ; --x){
		a = getHexValue(num[x]) + carr;//convert to integer
		if(a >= base){//add 1
			carr = 1;//still carring
			a -= base;//get the units
		}else{//no more carriage to be done
			carr = 0;
		}
		//update num 'x' place
		num[x] = getHexDigit(a);//return to digits of given base
	}
	//check for overflow
	if(len == x && carr == 1){
		puts("overflow");
		//sign is involved here
	}
	printf(" %s\n", num);
}

char * extend(char * number, short base, char digit){
	//current number of digits
	int length = strlen(number);
	int new_length;

	for(new_length = 1; new_length <= length; new_length *= 2);
		
	new_length++;//make space for the null character
	number = realloc(number, new_length * sizeof(char));
	
	for(int j = length; j < new_length - 1; j++){
		number[j] = digit;
	}
	number[new_length - 1] = '\0';
	return number;
}

#endif
