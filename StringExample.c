#include <stdio.h>

int main(){
	char string[50];
	string[0] = 'h';
	string[1] = 'e';
	string[2] = 'l';
	string[3] = 'l';
	string[4] = 'o';
	string[5] = ' ';
	string[6] = '1';
	string[7] = '2';
	string[8] = '\0';

	printf("%s\n", string);
	return 0;
}