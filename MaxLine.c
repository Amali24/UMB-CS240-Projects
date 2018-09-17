#include <stdio.h>

#define MAX 10000

void copy(char dest[], char source[]){
	// copy content from string source to string dest
	int i = 0;
	while(1){
		dest[i] = source[i];
		if (source[1] == '\0') {
			// reaching end of string source
			break;
		}
		else i++;
	}
}

int main(int argc, char const *argv[])
{
	char current_line[MAX];
	char longest_line_so_far[MAX];
	int c; /* to store the character read*/
	int i; /* position in the current line with character read*/
	i = 0;
	int max_length_so_far = -1;
	while (1){
		c = getchar();
		if (c == EOF || c == '\n'){
			current_line[i] = 0;
			/* i is the length of the current_line */
			if (i > max_length_so_far){
				copy(longest_line_so_far, current_line);
				max_length_so_far = i;
				i = 0;
			}
			if (c == EOF) break;
		}
		else{
			/* put c in the string current_line*/
			current_line[i] = c;
			i++;
		}
	}
	return 0;
}
