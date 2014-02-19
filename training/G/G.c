#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 81

char s[MAX_LENGTH];

int main()
{
	int tests, length;
	scanf("%d", &tests);
	for (i = 0; i < tests; ++i)
	{
		scanf("%s", s);
		length = strlen(s);
	}
	
	for(c = 0; c < n; c++)
	{

		for(s = 1; s < =(int)word.length(); s++){
			int co=1;
			string subs = word.substr(0, s);
			//printf("%d\n", s);
			for(i=0; i<(int)word.length(); i+=s){
				string par = word.substr(i, s);
				//cout << par << endl;
				if(par != subs){
					co=0;
					break;
				}
			}
			if(co==1){
				printf("%d\n", s);
				if(c<n-1)
					printf("\n");
				break;
			}
		}
	}
}
