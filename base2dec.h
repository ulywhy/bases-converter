#include "baseOp.h" //has functions to operate on non decimal base numbers

#ifndef _BASE_2_BASE_CONVERT_
#define _BASE_2_BASE_CONVERT_

#define BASE_10 10

char * toDec(char* num, const short base){
	int length = strlen(num);
	bool is_negative = false;
	char * new_number = NULL; 
	long long number = 0;
	long long weight = 0;
	short digit_value = 0;
	
  printf("\n---- Base %d to decimal\n", base);
  if(is_negative = sign(num, base)){
    printf("\tNumber %s is negative, then take complement %d\n", num, base);
    Comp1(num, base);
    Comp2(num, base);
  }
	//convert to integer
  for(int index = 1; index <= length; index++){
    digit_value = getHexValue(num[length - index]);//return an int if base is less than 10
    weight = pow(base, index - 1);
    number += (digit_value != 0) ? digit_value * weight : 0;
  }

  length = log10(number) + 1;
  length++; //add a null character
  new_number = calloc(length, sizeof(char));

  if(is_negative){
    new_number = realloc(new_number, ++length);//add a char for the '-' sign
  }

	sprintf(new_number, "%lld", (is_negative) ? -number : number);
  printf("\tDecimal value is %s\n", new_number);
  return new_number;
}
#endif
