#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../calculator/history.h"
#define PI 3.1415926


char* calculator(double *num1, double *num2, double *result)
{
	char* fuck = malloc(100);
	char operator[10];
	printf("�п�J�B���(+, -, *, /, ^, %%, sqrt,log, sin, cos, tan): ");
	scanf(" %s", operator);

	printf("�п�J��ӼƦr: ");
	scanf("%lf %lf", num1, num2);

	if (strcmp(operator, "+") == 0) *result = *num1 + *num2;
	else if(strcmp(operator, "-") == 0) *result = *num1 - *num2;
	else if (strcmp(operator, "*") == 0) *result = *num1 * *num2;
	else if (strcmp(operator, "/") == 0) {
		if (num1 != 0) *result = *num1 / *num2;
		else printf("���~�G���Ƥ��ର0\n");
	}
	else if (strcmp(operator, "%") == 0) *result = (int)*num1 % (int)*num2;
	else if (strcmp(operator, "^") == 0) *result = pow(*num1, *num2);
	else if (strcmp(operator, "sqrt") == 0) {
		if (num1 >= 0) *result = sqrt(*num1);
		else printf("���~�G�t�ƵL�k�p�⥭���\n");
	}
	else if (strcmp(operator, "log") == 0) *result = log(*num2) / log(*num1);

	else if (strcmp(operator, "sin") == 0) *result = sin(*num1 / 180 * PI);
	else if (strcmp(operator, "cos") == 0) *result = cos(*num1 / 180 * PI);
	else if (strcmp(operator, "tan") == 0) *result = tan(*num1 / 180 * PI);
	else if (strcmp(operator, "asin") == 0) *result = (asin(*num1) / PI * 180);
	else if (strcmp(operator, "acos") == 0) *result = (acos(*num1) / PI * 180);
	else if (strcmp(operator, "atan") == 0) *result = (atan(*num1) / PI * 180);
	else printf("���~�G�L�Ī��B���\n");
	
	printf("���G: %.2lf %s %.2lf = %.2lf\n", *num1, operator, *num2, *result);
	saveHistory(operator, *num1, *num2, *result);

	if(operator=="+"||"-"||"*"||"/"|| "%"||"^"||"log"){
		snprintf(fuck, 100, "%f %s %f %c %f\n", *num1, operator, *num2, '=', *result);
	}else if(operator=="sqrt" || "sin" || "cos" || "tan" || "asin" || "acos" || "atan"){
		snprintf(fuck, 100, "%s%f  %c %f\n", operator,*num1, '=', *result);
	}
	return fuck;
}