#include <stdio.h>
#include <stdlib.h>
#include "../calculator//history.h"
#include "../calculator//Operation.h"
#include "../calculator//animation.h"

#define MAX_HISTORY_LENGTH 100 
char option;
double num1, num2, result;
char dick[100] = "";

int main() {

	do {
		system("cls");

		printf("\n��ܥ\��G\n");
		printf("1. �p��\��\n");
		printf("2. �G�i���ഫ\n");
		printf("3. �ʵe\n");
		printf("4. �R�����v����\n");
		printf("5. �[�ݾ��v����\n");
		printf("6. �����{��\n");
		printf("�п�ܥ\��]1/2/3/4/5/6�^�G");
		scanf(" %c", &option);

		switch (option) {

		case '1':
			snprintf(dick, 100, "%s", calculator(&num1, &num2, &result));
			//free(calculator);
			break;
		case '2':
			//binary();
			break;
		case '3':
			animation(dick);
			break;
		case '4':
			clearHistory();
			break;
		case '5':
			displayHistory();
			break;
		case '6':
			printf("�{���w�����C\n");
			break;
		default:
			printf("�п�ܦ��Ī��ﶵ�]1/2/3/4/5�^�C\n");
			break;
		}
		system("pause");
	} while (option != '6');

	return 0;
}
