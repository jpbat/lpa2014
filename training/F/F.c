#include <stdio.h>
#include <string.h>

#define MAX_STRING 32
#define MAX_SYMBOLS 512

char mirrors[MAX_SYMBOLS];

int mirrored(char *s)
{
	int size = strlen(s), i;
	for(i = 0; i < size; i++)
	{
		if(mirrors[(int) s[i]] == 0)
			return 0;
		
		if(mirrors[(int) s[i]] != s[size - i - 1])
			return 0;
	}

	return 1;
}

int palind(char *s)
{
	int size = strlen(s), i;

	for(i = 0; i < size / 2; i++)
		if(s[i] != s[size - i - 1])
			return 0;

	return 1;	
}


int main(int argc, char **argv)
{
	char s[MAX_STRING];

	memset(mirrors, 0, MAX_SYMBOLS * sizeof(char));
	
	mirrors[(int)'A'] = 'A';
	mirrors[(int)'E'] = '3';
	mirrors[(int)'H'] = 'H';
	mirrors[(int)'I'] = 'I';
	mirrors[(int)'J'] = 'L';
	mirrors[(int)'L'] = 'J';
	mirrors[(int)'M'] = 'M';
	mirrors[(int)'O'] = 'O';
	mirrors[(int)'S'] = '2';
	mirrors[(int)'T'] = 'T';
	mirrors[(int)'U'] = 'U';
	mirrors[(int)'V'] = 'V';
	mirrors[(int)'W'] = 'W';
	mirrors[(int)'X'] = 'X';
	mirrors[(int)'Y'] = 'Y';
	mirrors[(int)'Z'] = '5';
	mirrors[(int)'1'] = '1';
	mirrors[(int)'2'] = 'S';
	mirrors[(int)'3'] = 'E';
	mirrors[(int)'5'] = 'Z';
	mirrors[(int)'8'] = '8';
	
	while(scanf("%s", s) != EOF)
	{
		int mirror = mirrored(s);
		int palindrome = palind(s);
		if (mirror && palindrome)
			printf("%s -- is a mirrored palindrome.\n", s);
		else if (mirror && !palindrome)
			printf("%s -- is a mirrored string.\n", s);
		else if (!mirror && palindrome)
			printf("%s -- is a regular palindrome.\n", s);
		else
			printf("%s -- is not a palindrome.\n", s);
		printf("\n");
	}

	return 0;
}

