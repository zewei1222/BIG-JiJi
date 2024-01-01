#include <stdio.h>
void saveHistory(char *operation, double num1, double num2, double result) {
	FILE *fptr = fopen("history.txt", "a");
	if (fptr == NULL) {
		printf("�L�k���}�γЫ� history.txt ���C\n");
		return;
	}

	fprintf(fptr, "%.2lf %s %.2lf = %.2lf\n", num1, operation, num2, result);
	fclose(fptr);
}

void clearHistory() {
	FILE *fptr = fopen("history.txt", "w");
	if (fptr == NULL) {
		printf("�L�k���}�γЫ� history.txt ���C\n");
		return;
	}

	fclose(fptr);
	printf("���v�O���w�M���C\n");
}

void displayHistory() {
	system("cls");
	FILE *fptr = fopen("history.txt", "r");
	if (fptr == NULL) {
		printf("���v�O�����šC\n");
		return;
	}

	printf("���v�O���G\n");
	char c;
	while ((c = getc(fptr)) != EOF) {
		putchar(c);
	}
	fclose(fptr);
}