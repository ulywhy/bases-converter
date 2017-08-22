#include <stdio.h>
#include <string.h>
#include "baseOp.h"
#include "basic.h"

#define LEN_NUM 30
#define SIZE_FILE 50
#define MENU_ROWS 22
#define SENTENCE_ROWS 3

#define DECIMAL 10

#define ANSI_COLOR_GREEN   "\x1b[81m"
#define ANSI_COLOR_RESET   "\x1b[92m"

#define ANSI_BACK_COLOR_UN     "\x1b[80m"
#define ANSI_BACK_COLOR_RESET    "\x1b[49m"


int main(int argc, char** argv){
	const char * title[] = {	

		"                                             ___          ___          ___                                        \n",
		"                               _____        /  /\\        /  /\\        /  /\\                                      \n",
		"                              /  /::\\      /  /::\\      /  /:/_      /  /:/_                                     \n",
		"                             /  /:/\\:\\    /  /:/\\:\\    /  /:/ /\\    /  /:/ /\\                                    \n",
		"                            /  /:/~/::\\  /  /:/~/::\\  /  /:/ /::\\  /  /:/ /:/_                                   \n",
		"                           /__/:/ /:/\\:|/__/:/ /:/\\:\\/__/:/ /:/\\:\\/__/:/ /:/ /\\                                  \n",
		"                           \\  \\:\\/:/~/:/\\  \\:\\/:/__\\/\\  \\:\\/:/~/:/\\  \\:\\/:/ /:/                                  \n",
		"                            \\  \\::/ /:/  \\  \\::/      \\  \\::/ /:/  \\  \\::/ /:/                                   \n",
		"                             \\  \\:\\/:/    \\  \\:\\       \\__\\/ /:/    \\  \\:\\/:/                                    \n",
		"                              \\  \\::/      \\  \\:\\        /__/:/      \\  \\::/                                     \n",
		"                               \\__\\/        \\__\\/        \\__\\/        \\__\\/                                      \n",
		"     ___          ___          ___                      ___          ___                   ___          ___      \n",
		"    /  /\\        /  /\\        /__/\\         ___        /  /\\        /  /\\         ___     /  /\\        /  /\\     \n",
		"   /  /:/       /  /::\\       \\  \\:\\       /__/\\      /  /:/_      /  /::\\       /  /\\   /  /:/_      /  /::\\    \n",
		"  /  /:/       /  /:/\\:\\       \\  \\:\\      \\  \\:\\    /  /:/ /\\    /  /:/\\:\\     /  /:/  /  /:/ /\\    /  /:/\\:\\   \n",
		" /  /:/  ___  /  /:/  \\:\\  _____\\__\\:\\      \\  \\:\\  /  /:/ /:/_  /  /:/~/:/    /  /:/  /  /:/ /:/_  /  /:/~/:/   \n",
		"/__/:/  /  /\\/__/:/ \\__\\:\\/__/::::::::\\ ___  \\__\\:\\/__/:/ /:/ /\\/__/:/ /:/___ /  /::\\ /__/:/ /:/ /\\/__/:/ /:/___ \n",
		"\\  \\:\\ /  /:/\\  \\:\\ /  /:/\\  \\:\\~~\\~~\\//__/\\ |  |:|\\  \\:\\/:/ /:/\\  \\:\\/::::://__/:/\\:\\  \\:\\/:/ /:/\\  \\:\\/:::::/ \n",
		" \\  \\:\\  /:/  \\  \\:\\  /:/  \\  \\:\\  ~~~ \\  \\:\\|  |:| \\  \\::/ /:/  \\  \\::/~~~~ \\__\\/  \\:\\  \\::/ /:/  \\  \\::/~~~~  \n",
		"  \\  \\:\\/:/    \\  \\:\\/:/    \\  \\:\\      \\  \\:\\__|:|  \\  \\:\\/:/    \\  \\:\\          \\  \\:\\  \\:\\/:/    \\  \\:\\      \n",
		"   \\  \\::/      \\  \\::/      \\  \\:\\      \\__\\::::/    \\  \\::/      \\  \\:\\          \\__\\/ \\  \\::/      \\  \\:\\     \n",
		"    \\__\\/        \\__\\/        \\__\\/          ~~~~      \\__\\/        \\__\\/                 \\__\\/        \\__\\/     \n"
};

const char * pedir_numero[] = {
		"\n			 ___ __  __  __   __  ___                    ,      ___ __  __  \n",
		"			|__ /__`/  `|__)||__)|__    |  ||\\ |   |\\ ||  ||\\/||__ |__)/  \\ \n",
		"			|___.__/\\__,|  \\||__)|___   \\__/| \\|   | \\|\\__/|  ||___|  \\\\__/ .......................  "
};

const char * pedir_origen[] = {
		"\n			 ___ __  __  __   __  ___               __      __  ___    __  __   __  ___     \n",
		"			|__ /__`/  `|__)||__)|__    |    /\\    |__) /\\ /__`|__    /  \\|__)|/ _`|__ |\\ |   \n", 
		"			|___.__/\\__,|  \\||__)|___   |___/~~\\   |__)/~~\\.__/|___   \\__/|  \\|\\__>|___| \\| .............  "
};

const char * pedir_destino[] = {
		"\n			 ___ __  __  __   __  ___               __      __  ___    __  ___ _____      __  \n",
		"			|__ /__`/  `|__)||__)|__    |    /\\    |__) /\\ /__`|__    |  \\|__ /__`| ||\\ |/  \\		\n", 
		"			|___.__/\\__,|  \\||__)|___   |___/~~\\   |__)/~~\\.__/|___   |__/|___.__/| || \\|\\__/ ...........  "
};

	char * number;
	size_t num_size;
	short origin_base, dest_base, base_guessed, digit_value;
	char command[50];

	printf(ANSI_BACK_COLOR_UN);
	printf(ANSI_COLOR_GREEN);

		
	/*MENU*/
	do{
		num_size = 0;
		number = NULL;//to make getline allocate memory for us
		origin_base = 0;
		dest_base = 0;
		base_guessed = 0;
		digit_value = 0;

		//print title
		clear();
		for(int j = 0; j < MENU_ROWS; ++j)	printf("%s", title[j]);
		/*INTERFACE*/
		for(int j = 0; j < SENTENCE_ROWS; ++j)	printf("%s", pedir_numero[j]);
		getline(&number, &num_size, stdin);
		//null terminate the number string ----> number[strlen(number) - 1] = '\0';
		number[strlen(number)-1] = '\0';
		
		if('-' == number[0]){//number is decimal
			origin_base = DECIMAL;
		}else{//guess base
			for(int j = 0, len = strlen(number); j <= len; j++){
				digit_value = getHexValue(number[j]);
				if(digit_value > base_guessed){
					base_guessed = digit_value;
				}
			}
		
			do{
				//menu
				clear();
				for(int j = 0; j < MENU_ROWS; ++j)	printf("%s", title[j]);
		
				for(int j = 0; j < SENTENCE_ROWS; ++j)	printf("%s", pedir_origen[j]);
				origin_base = getShort();
			}while(origin_base <= base_guessed);
		}

		do{
			//menu
			clear();
			for(int j = 0; j < MENU_ROWS; ++j)	printf("%s", title[j]);
		
			for(int j = 0; j < SENTENCE_ROWS; ++j)	printf("%s", pedir_destino[j]);
			dest_base = getShort();
		}while(origin_base == dest_base || NEGATIVE(dest_base) );
		
		//menu
		clear();
		for(int j = 0; j < MENU_ROWS; ++j)	printf("%s", title[j]);
		
		/*CALL BASE CONVERTER*/
		//core program
		sprintf(command, "./base_convert %s %hd %hd", number, origin_base, dest_base);
		//create PIPE to base_convert
		short flag = 0;
		FILE * pipe = NULL;
		do{
			++flag;
			pipe = popen(command, "we\0");
		}while(pipe == NULL || flag >= 5);
		if (pipe != NULL ){
			pclose(pipe);
		}else{
			fprintf(stderr, "could'n call %s\n", command);
			return -1;
		}
		free(number);//free if needed to store another number
	}while(binaryCharDecision("¿desea convertir otro número?", 's','n'));
	/*END MENU*/
	printf(ANSI_BACK_COLOR_RESET);
	clear();
	return 0;
}