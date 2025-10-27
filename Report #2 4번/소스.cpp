#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    const double D = 0.05;
    const double rho = 998.2;
    const double mu = 0.001002;
    const double Re_crit1 = 2300.0;
    const double Re_crit2 = 4000.0;

    double V;
    double Re;
    double q;
    const char* flow_status;

    printf("��� �� ��ü�� ����(m/s)�� �Է��ϼ���: ");
    scanf("%lf", &V);

    if (V < 0) {
        printf("invalid input (velocity)\n");
        return 1;
    }

    Re = (rho * V * D) / mu;

    q = 0.5 * rho * V * V;

    if (Re < Re_crit1) {
        flow_status = "���� (Laminar)";
    }
    else if (Re < Re_crit2) {
        flow_status = "õ�� (Transition)";
    }
    else {
        flow_status = "���� (Turbulent)";
    }

    printf("\n--- ���� �м� ��� ---\n");
    printf("���̳��� �� (Re): %.2f\n", Re);
    printf("���� ����: %s\n", flow_status);
    printf("���� (q): %.2f Pa\n", q);

    return 0;
}