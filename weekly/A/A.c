#include <stdio.h>
#include <string.h>

#define MAX_NODES 21
#define MAX_LENGTH 31
#define CONNECTIONS 2

int nNodes, lineLength;

int matrix[MAX_NODES][CONNECTIONS];
int memory[MAX_NODES][MAX_LENGTH];
int terminals[MAX_NODES];

void viewAutomaton()
{
	int i;

	for (i = 0; i < nNodes; i++)
	{
		printf("[%d] 0->%d | 1->%d ", i+1, matrix[i][0]+1, matrix[i][1]+1);
		
		if (terminals[i])
			printf("T");

		printf("\n");
	}
}

int dfs(int node, int length, int counter)
{
	int zeroSum, oneSum;

	if (length == lineLength)
	{
		if (terminals[node] == 1)
			memory[node][length] = counter + 1;
		else
			memory[node][length] = counter;
	}

	else if (memory[node][length] == -1)
	{
		zeroSum = dfs(matrix[node][0], length + 1, counter);
		oneSum = dfs(matrix[node][1], length + 1, counter);
		memory[node][length] = counter + zeroSum + oneSum;
	}

	return memory[node][length];
}

int main()
{
	int zTrans, oTrans, i;
	char delimiter;

	while(scanf("%d %d", &nNodes, &lineLength) != EOF)
	{
		memset(terminals, 0, MAX_NODES * sizeof(int));
		memset(memory, -1, MAX_NODES * MAX_LENGTH * sizeof(int));

		for (i = 0; i < nNodes; i++)
		{
			scanf("%d %d%c", &zTrans, &oTrans, &delimiter);

			matrix[i][0] = zTrans - 1;
			matrix[i][1] = oTrans - 1;
			
			if (delimiter == ' ')
			{
				scanf(" %c", &delimiter);
				terminals[i] = 1;
			}
		}

		/*viewAutomaton();*/

		printf("%d\n", dfs(0, 0, 0));
	}

	return 0;
}