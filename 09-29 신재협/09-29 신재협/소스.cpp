#include <stdio.h>

int main(void)
{
	int nAge = 99;
	float fHeight = 999.0f;
	double dWeghit = 999.0f;

	char chTemp = ' ';
	char chString[100] = " ";


	//printf("Input your information(Age, Height, Weight):\n");
	//scanf("%d%f%lf", &nAge, &fHeight, &dWeghit);
	printf("lnput your alphabet and word:\n");
	scanf_s("%c%s", &chTemp, sizeof(chTemp), chString, sizeof(chString));

	printf("Output\n");
	//printf("(Age:%d)(Height:%.2f)(Weight:%.1lf)\n", nAge, fHeight, dWeghit);
	printf("(Alphabet:%c)(Word:%s)\n", chTemp, chString);

	return 0;
}