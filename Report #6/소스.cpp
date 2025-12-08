// =================================================================
// [C4996 보안 경고 해결] 표준 C 함수 (scanf) 사용을 위한 전처리기 정의
// =================================================================
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <math.h>

// 물리 상수 정의
#define G 9.81              // 중력 가속도 (m/s^2)
#define PI 3.141592653589793 // 원주율
#define DT 0.1              // 궤적 시뮬레이션 시간 간격 (s)

// 함수 원형 정의 (프로토타입)
double deg_to_rad(double degree);
void calculate_key_results(double v0, double theta_rad, double* Tf, double* Hmax, double* R);

int main() {
    // 1. 변수 선언 및 초기화
    double v0, angle_deg, angle_rad;
    double time = 0.0;

    // Call by Reference를 위한 결과 변수
    double total_flight_time;
    double max_height;
    double range;

    printf("=== 포물체 운동 시뮬레이션 프로그램 ===\n");

    // 2. 사용자 입력 (표준 C 라이브러리 함수 사용)
    printf("초기 속도 v0 (m/s)를 입력하세요: ");
    scanf("%lf", &v0); // & 연산자로 주소 전달
    printf("발사 각도 theta (0~90 도)를 입력하세요: ");
    scanf("%lf", &angle_deg);

    // 3. 입력 유효성 검사 (if 조건문 활용)
    if (angle_deg < 0.0 || angle_deg > 90.0 || v0 <= 0.0) {
        printf("\n[오류] 입력된 속도나 각도 값이 유효하지 않습니다.\n");
        return 1;
    }

    // 4. 각도 변환 및 주요 결과 계산 (함수 호출)
    angle_rad = deg_to_rad(angle_deg);
    calculate_key_results(v0, angle_rad, &total_flight_time, &max_height, &range); // Call by Reference로 결과 전달

    // 5. 주요 결과 출력
    printf("\n--- 분석 결과 ---\n");
    printf("총 비행 시간 (Tf): %.2lf s\n", total_flight_time); // 수정 완료
    printf("최대 높이 (Hmax): %.2lf m\n", max_height);      // 수정 완료
    printf("수평 도달 거리 (R): %.2lf m\n", range);        // 수정 완료
    printf("------------------\n");

    // 6. 궤적 시뮬레이션 및 출력 (for 반복문 및 동역학 공식 활용)
    printf("\n--- 시간에 따른 궤적 (x, y) ---\n");
    printf("Time(s) | X Position(m) | Y Position(m)\n");

    // 초기 속도 벡터 성분 분해
    double v0x = v0 * cos(angle_rad);
    double v0y = v0 * sin(angle_rad);

    for (time = 0.0; time <= total_flight_time + DT / 2.0; time += DT) {
        // 시간에 따른 수평/수직 위치 계산 공식 적용
        double x_pos = v0x * time;
        double y_pos = v0y * time - 0.5 * G * time * time;

        if (y_pos < 0.0) { // 땅에 닿으면 높이를 0으로 처리
            y_pos = 0.0;
        }

        printf("%.1lf\t| %.2lf\t\t| %.2lf\n", time, x_pos, y_pos); // 수정 완료

        // 지면에 닿은 후 루프 종료 조건
        if (y_pos == 0.0 && time > 0.0) {
            break;
        }
    }

    printf("------------------------------------\n");

    return 0;
}

// ===============================================
// 함수 정의
// ===============================================

/**
 * @brief 각도(Degree)를 라디안(Radian)으로 변환합니다.
 * @param degree : 입력된 각도 (도)
 * @return 라디안 값
 */
double deg_to_rad(double degree) {
    // 라디안 변환 공식 적용: degree * (PI / 180.0)
    return degree * (PI / 180.0);
}

/**
 * @brief 총 비행 시간(Tf), 최대 높이(Hmax), 수평 도달 거리(R)를 계산합니다.
 * @param Tf, Hmax, R : 결과를 저장할 포인터 (Call by Reference)
 */
void calculate_key_results(double v0, double theta_rad, double* Tf, double* Hmax, double* R) {
    // 초기 속도 성분 계산 (v0x, v0y)
    double v0x = v0 * cos(theta_rad);
    double v0y = v0 * sin(theta_rad);

    // 포물체 운동 동역학 수식 적용 및 포인터를 이용한 값 저장
    *Tf = (2.0 * v0y) / G; // 비행 시간 공식
    *Hmax = (v0y * v0y) / (2.0 * G); // 최대 높이 공식
    *R = v0x * (*Tf); // 수평 거리 공식 (v0x * Tf)
}