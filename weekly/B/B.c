#include <stdio.h>
#include <math.h>
#include <float.h>

#define MAX_N 60

float pizza[MAX_N];
float cumm[MAX_N + 1];
float best;
int n;

void calc(int pos, float diff)
{
	float simple = fabs(diff - cumm[pos]);

	if (simple < best)
		best = simple;

	if (best < 0.005)
		return;

	if (pos == n)
		return;

	if (diff - cumm[pos] > best)
		return;

	calc(pos+1, fabsf(diff - pizza[pos]));		
	calc(pos+1, diff + pizza[pos]);
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%f", &pizza[n - i - 1]);

		float sum = 0;

		for (int i = n; i > 0; i--)
		{
			cumm[i] = sum;
			sum += pizza[i-1];
		}

		cumm[0] = sum;

		best = std::numeric_limits<float>::infinity();
		calc(0, 0);

		printf("%.2f\n", best);
	}

	return 0;
}
