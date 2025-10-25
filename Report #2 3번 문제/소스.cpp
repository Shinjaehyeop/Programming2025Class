#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // sin(), cos(), M_PI ���

int main(void)
{
    const double m = 100.0;
    const double g = 9.81;
    const double mu_s = 0.5;
    const double mu_k = 0.4;
    const double PI = M_PI;

    double degree, radian;
    double F_gx, N, f_s_max, f_k, a;

    printf("������ ��簢(��)�� �Է��ϼ���: ");
    scanf("%lf", &degree);

    // �Է°� ��ȿ�� �˻� (0�� �̻� 90�� �̸�)
    if (degree < 0 || degree >= 90) {
        printf("invalid input\n");
        return 1;
    }

    radian = degree * PI / 180.0;

    F_gx = m * g * sin(radian);
    N = m * g * cos(radian);
    f_s_max = mu_s * N;

    printf("\n--- �м� ��� ---\n");
    if (F_gx > f_s_max) {
        // �̲������� ���
        f_k = mu_k * N;
        a = (F_gx - f_k) / m;
        printf("�ķ�Ʈ�� �̲������ϴ�.\n");
        printf("���� �Ʒ� ���� ���ӵ�: %.2f m/s^2\n", a); // �Ҽ��� ��° �ڸ�
    }
    else {
        // ���� ���� ����
        printf("�ķ�Ʈ�� ���� ���¸� �����մϴ� (�̲������� ����).\n");
    }

    return 0;
}