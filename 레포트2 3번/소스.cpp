// Visual Studio의 scanf 보안 경고를 비활성화하기 위한 매크로 정의
#define _CRT_SECURE_NO_WARNINGS

// 표준 입출력 함수(printf, scanf)를 사용하기 위해 필요
#include <stdio.h>
// 수학 함수 pow() 사용을 위해 필요 (선택 사항, V*V로 대체 가능)
#include <math.h>
// 프로그램 종료(return 1)를 위해 필요 (선택 사항)
#include <stdlib.h>

// 프로그램의 시작점인 main 함수
int main(void)
{
    // 상수 정의: 문제에서 주어진 값들을 상수로 선언
    const double D = 0.05;         // 배관 내경 (m)
    const double rho = 998.2;      // 냉각수 밀도 (kg/m^3)
    const double mu = 0.001002;    // 냉각수 점도 (Pa.s 또는 kg/(m.s))
    const double Re_crit1 = 2300.0; // 층류-천이 경계 레이놀즈 수
    const double Re_crit2 = 4000.0; // 천이-난류 경계 레이놀즈 수

    // 변수 선언: 계산에 필요한 변수들을 선언
    double V;             // 사용자로부터 입력받을 유속 (m/s)
    double Re;            // 계산될 레이놀즈 수
    double q;             // 계산될 동압 (Pa)
    char* flow_status;    // 판별된 유동 상태를 저장할 문자열 포인터 (C언어에서 문자열을 다루는 방법 중 하나)

    // 사용자로부터 유속 입력 요청
    printf("배관 내 유체의 유속(m/s)을 입력하세요: ");
    scanf("%lf", &V);

    // 입력값 유효성 검사 (유속은 음수가 될 수 없음)
    if (V < 0) {
        printf("invalid input (velocity)\n"); // 오류 메시지 출력
        return 1; // 비정상 종료
    }

    // 레이놀즈 수 계산 (Re = rho * V * D / mu)
    Re = (rho * V * D) / mu;

    // 동압 계산 (q = 0.5 * rho * V^2)
    q = 0.5 * rho * V * V; // V*V 대신 pow(V, 2) 함수를 사용해도 동일함

    // 유동 상태 판별 (레이놀즈 수 기준)
    if (Re < Re_crit1) { // Re < 2300 이면 층류
        flow_status = "층류 (Laminar)";
    }
    else if (Re < Re_crit2) { // 2300 <= Re < 4000 이면 천이
        flow_status = "천이 (Transition)";
    }
    else { // Re >= 4000 이면 난류
        flow_status = "난류 (Turbulent)";
    }

    // 결과 출력
    printf("\n--- 유동 분석 결과 ---\n");
    printf("레이놀즈 수 (Re): %.2f\n", Re); // 계산된 레이놀즈 수를 소수점 둘째 자리까지 출력
    printf("유동 상태: %s\n", flow_status);   // 판별된 유동 상태 문자열 출력
    printf("동압 (q): %.2f Pa\n", q);        // 계산된 동압을 소수점 둘째 자리까지 출력 (단위: 파스칼)

    // 프로그램 정상 종료
    return 0;
}
