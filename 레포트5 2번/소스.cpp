#include <stdio.h>
#include <math.h> // sin, cos, M_PI 사용 (M_PI는 표준 C가 아닐 수 있으므로 3.1415926535로 대체)

// 문제 요구사항 상수 정의
#define G 9.81           // 중력 가속도 [m/s^2]
#define DT 0.01          // 미소 시간 간격 [sec]
#define V_INITIAL 15.0   // 초기 속도 [m/s]
#define THETA_DEG 75.0   // 초기 발사 각도 [deg]
#define PI 3.1415926535

// 상태 변수를 포인터로 받아 갱신하는 함수
void UpdateMotion(double* x, double* y, double* vx, double* vy, double* t);

// 메인 함수
int main(void) {
    // 로켓 상태 변수 선언 및 초기화
    double x = 0.0;    // 수평 위치 [m]
    double y = 0.0;    // 수직 위치 [m]
    double vx;         // 수평 속도 [m/s]
    double vy;         // 수직 속도 [m/s]
    double t = 0.0;    // 시간 [sec]

    double max_height = 0.0; // 최고 도달 높이 기록 변수
    double theta_rad = THETA_DEG * (PI / 180.0); // 각도 변환 (deg -> rad)

    // 초기 속도 분해
    vx = V_INITIAL * cos(theta_rad);
    vy = V_INITIAL * sin(theta_rad);

    printf("--- 소형 물로켓 운동 시뮬레이션 ---\n");
    printf("초기 속도: %.2lf m/s, 각도: %.1lf deg\n", V_INITIAL, THETA_DEG);
    printf("-----------------------------------\n");

    // 시뮬레이션 반복 (Y > 0 일 때까지)
    while (y >= 0.0) {

        // 1. 상태 갱신 함수 호출 (Call by Reference - 주소를 전달)
        UpdateMotion(&x, &y, &vx, &vy, &t);

        // 2. 최고 높이 기록 (선택문 활용)
        if (y > max_height) {
            max_height = y;
        }

        // 3. 착지 후 y가 음수가 되는 경우, 루프 종료
        if (y < 0.0) {
            break;
        }
    }

    // 결과 출력
    printf("1. 체공 시간: %.2lf [sec]\n", t);
    printf("2. 최고 도달 높이: %.2lf [m]\n", max_height);
    printf("3. 수평 사거리: %.2lf [m]\n", x); // x는 시뮬레이션 최종 위치
    printf("-----------------------------------\n");

    return 0;
}

// 상태 갱신 함수: 현재 상태의 주소를 받아 값을 갱신 (Call by Reference)
void UpdateMotion(double* x, double* y, double* vx, double* vy, double* t) {
    // 속도 갱신 (수직 속도만 중력의 영향을 받음)
    *vy = *vy - G * DT;

    // 위치 갱신
    *x = *x + *vx * DT;
    *y = *y + *vy * DT;

    // 시간 갱신
    *t = *t + DT;
}