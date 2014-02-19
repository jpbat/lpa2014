#include <stdio.h>
#include <string.h>

int diff(char* w1, char* w2)
{
	int i, x = 0;
	
	for (i = 0; w1[i] != '\0'; i++)
		if (w1[i] != w2[i])
			x++;
	return x;
}

int main(int argc, char** argv)
{
	int n, i;
	char words[26][256];
	char out[26][256];
	
	while (scanf("%d %d", &n, &i) != EOF)
	{
		scanf("%s", words[0]);
		
		strcpy(out[0], words[0]);
		
		for (i = 1; i < n; i++) {
			scanf("%s", words[i]);
			strcpy(out[diff(words[i], words[0])], words[i]);
		}
		
		for (i = 0; i < n; i++)
			printf("%s\n", out[i]);
	}
	
	return 0;
}
