#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // sin(), cos(), M_PI 사용

int main(void)
{
    const double m = 100.0;
    const double g = 9.81;
    const double mu_s = 0.5;
    const double mu_k = 0.4;
    const double PI = M_PI;

    double degree, radian;
    double F_gx, N, f_s_max, f_k, a;

    printf("램프의 경사각(도)을 입력하세요: ");
    scanf("%lf", &degree);

    // 입력값 유효성 검사 (0도 이상 90도 미만)
    if (degree < 0 || degree >= 90) {
        printf("invalid input\n");
        return 1;
    }

    radian = degree * PI / 180.0;

    F_gx = m * g * sin(radian);
    N = m * g * cos(radian);
    f_s_max = mu_s * N;

    printf("\n--- 분석 결과 ---\n");
    if (F_gx > f_s_max) {
        // 미끄러지는 경우
        f_k = mu_k * N;
        a = (F_gx - f_k) / m;
        printf("파렛트가 미끄러집니다.\n");
        printf("경사면 아래 방향 가속도: %.2f m/s^2\n", a); // 소수점 둘째 자리
    }
    else {
        // 정지 상태 유지
        printf("파렛트가 정지 상태를 유지합니다 (미끄러지지 않음).\n");
    }

    return 0;
}