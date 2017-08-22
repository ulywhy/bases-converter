#include "baseOp.h"//has functions to operate on non decimal base numbers

#ifndef _DEC_2_BASE_CONVERT_
#define _DEC_2_BASE_CONVERT_

#define MIN_LEN 2

char* fromDec(const char* number, const short base){
	long long number_value = abs(atoll(number));
	int num_of_digits = ceil( log10(number_value) / log10(base) );
  num_of_digits = (0 == num_of_digits) ? MIN_LEN : num_of_digits;//add a digit for the zero digit 2^0
  int digit_value = 0;
  int pow_of_two = 0;

  printf("\n---- Decimal to base %d\n", base);
  //quantisize the number
  for( pow_of_two = 1; pow_of_two <= num_of_digits; pow_of_two *= 2);
  num_of_digits = pow_of_two;

  printf("\t%s takes %d digits in base %d\n",number, num_of_digits, base);

  char *new_number = calloc(num_of_digits + 1, sizeof(char));//the number writen in the new base
  //null terminate new number
  new_number[num_of_digits] = '\0';
  //convert to new base
  for(int bk_index = num_of_digits - 1; bk_index >= 0; bk_index--){
    //get residue
    digit_value = number_value % base;
    //get quotient
    number_value /= base;
    //add next digit
    new_number[bk_index] = getHexDigit(digit_value);
  }

  //if number is negative
	if(number[0] == '-'){
    printf("decimal number %s is negative, then take complement %d\n", number, base);
		Comp1(new_number, base);//get one's complement
		Comp2(new_number, base);//get two's complement
	}
	return new_number;
}
#endif