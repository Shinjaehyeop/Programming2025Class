#include

void swqp_pointer(int* pnA, int* pnB);
void swqp_normal(int nA, int nB);

int main(void)
{
	int nA = 0, nB = 0;
	nA = 10;
	nB = 20;

	int nA = 0, nB = 0;
	nA = &nA;
	nB = &nB;

	prnit("befor swap:(nA,nB)=(%d,%d)\n", nA, nB);
	swqp_pointer(pnA, pnB);

	prnit("after swap:(nA,nB)=(%d,%d)\n", nA, nB);

	return 0;

}
void swqp_pointer(int* pnA, int* pnB);
{
	int nTemp = 0;
	*pnA = *pnB
	*pnB = nTemp;
	return:
}