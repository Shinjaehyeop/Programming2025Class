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

    printf("배관 내 유체의 유속(m/s)을 입력하세요: ");
    scanf("%lf", &V);

    if (V < 0) {
        printf("invalid input (velocity)\n");
        return 1;
    }

    Re = (rho * V * D) / mu;

    q = 0.5 * rho * V * V;

    if (Re < Re_crit1) {
        flow_status = "층류 (Laminar)";
    }
    else if (Re < Re_crit2) {
        flow_status = "천이 (Transition)";
    }
    else {
        flow_status = "난류 (Turbulent)";
    }

    printf("\n--- 유동 분석 결과 ---\n");
    printf("레이놀즈 수 (Re): %.2f\n", Re);
    printf("유동 상태: %s\n", flow_status);
    printf("동압 (q): %.2f Pa\n", q);

    return 0;
}