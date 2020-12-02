#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	FILE *S1, *S2;
	int size = 1;
	scanf("%d", &size);
	printf("%d", size);
	int n, neg_pos = 0, pos_pos = 0;
	bool positive = true;
	int *pos, *neg, *numbers;
	pos = (int *)malloc(size * sizeof(int));
	neg = (int *)malloc(size * sizeof(int));
	numbers = (int *)malloc(size * sizeof(int));

	S1 = fopen("f.txt", "r");
	S2 = fopen("final.txt", "w");

	for (n = 0; !feof(S1); n++) {
		fscanf(S1, "%d", &size);
		if (size > 0) {
			pos[pos_pos] = size + 0;
			pos_pos++;
		} else if (size < 0) {
			neg[neg_pos] = size;
			neg_pos++;
		}
	}

	neg[neg_pos + 1] = 0;
	pos[pos_pos + 1] = 0;

	for (int i = 0; i < (neg_pos + pos_pos) / 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (positive && pos[j] != 0) fprintf(S2, "%2d ", pos[j]);
			else if (!positive && neg[j] != 0) fprintf(S2, "%4d", neg[j]);
		}
		positive = !positive;
	}

	for (int i = 0; i < sizeof(pos); i++) printf("%d, ", pos[i]);
	for (int i = 0; i < sizeof(neg); i++) printf("%d, ", neg[i]);

	fclose(S1);
	fclose(S2);
	
	getchar();
	return 0;
}
