#include "dec2base.h"//functions to convert decimal to another base
#include "base2dec.h"//functions to convert from any base to decimal

int main (int argc, char** argv){
	if (argc != 4){
		/*usage: number, [origin_base], target_base*/
		fprintf(stderr, "Usage: %s <number> <origin_base> <target_base>\n", argv[0]);
	}
	char* number = strdup(argv[1]);
	short origin_base = (short)atoi(argv[2]);
	short target_base = (short)atoi(argv[3]);
	char * target, * decimal;
	
	if(origin_base < 2 || target_base < 2){
		fprintf(stderr, "can use base fewer than 2\n");
		return -2;
	}
	//update to convert between any base below HEX
	if(origin_base == 10){
			decimal = number;//kepp track of number pointee
			number = fromDec(decimal, target_base);
			free(decimal);
	}else if(origin_base != target_base){
		//get decimal number
		decimal = toDec(number, origin_base);
		if(target_base != 10){
			free(number);
			number = fromDec(decimal, target_base);
			free(decimal);
		}else{
			number = decimal;
		}
	}else{
		//can't convert between bases
		fprintf(stderr, "can't convert %s base %d to base %d\n", number, origin_base, target_base);
		return -1;
	}
	printf("\n\t%s base %d == %s base %d\n", argv[1], origin_base, number, target_base);
	free(number);
	return 0;
}
