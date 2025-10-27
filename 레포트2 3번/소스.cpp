// Visual Studio�� scanf ���� ��� ��Ȱ��ȭ�ϱ� ���� ��ũ�� ����
#define _CRT_SECURE_NO_WARNINGS

// ǥ�� ����� �Լ�(printf, scanf)�� ����ϱ� ���� �ʿ�
#include <stdio.h>
// ���� �Լ� pow() ����� ���� �ʿ� (���� ����, V*V�� ��ü ����)
#include <math.h>
// ���α׷� ����(return 1)�� ���� �ʿ� (���� ����)
#include <stdlib.h>

// ���α׷��� �������� main �Լ�
int main(void)
{
    // ��� ����: �������� �־��� ������ ����� ����
    const double D = 0.05;         // ��� ���� (m)
    const double rho = 998.2;      // �ð��� �е� (kg/m^3)
    const double mu = 0.001002;    // �ð��� ���� (Pa.s �Ǵ� kg/(m.s))
    const double Re_crit1 = 2300.0; // ����-õ�� ��� ���̳��� ��
    const double Re_crit2 = 4000.0; // õ��-���� ��� ���̳��� ��

    // ���� ����: ��꿡 �ʿ��� �������� ����
    double V;             // ����ڷκ��� �Է¹��� ���� (m/s)
    double Re;            // ���� ���̳��� ��
    double q;             // ���� ���� (Pa)
    char* flow_status;    // �Ǻ��� ���� ���¸� ������ ���ڿ� ������ (C���� ���ڿ��� �ٷ�� ��� �� �ϳ�)

    // ����ڷκ��� ���� �Է� ��û
    printf("��� �� ��ü�� ����(m/s)�� �Է��ϼ���: ");
    scanf("%lf", &V);

    // �Է°� ��ȿ�� �˻� (������ ������ �� �� ����)
    if (V < 0) {
        printf("invalid input (velocity)\n"); // ���� �޽��� ���
        return 1; // ������ ����
    }

    // ���̳��� �� ��� (Re = rho * V * D / mu)
    Re = (rho * V * D) / mu;

    // ���� ��� (q = 0.5 * rho * V^2)
    q = 0.5 * rho * V * V; // V*V ��� pow(V, 2) �Լ��� ����ص� ������

    // ���� ���� �Ǻ� (���̳��� �� ����)
    if (Re < Re_crit1) { // Re < 2300 �̸� ����
        flow_status = "���� (Laminar)";
    }
    else if (Re < Re_crit2) { // 2300 <= Re < 4000 �̸� õ��
        flow_status = "õ�� (Transition)";
    }
    else { // Re >= 4000 �̸� ����
        flow_status = "���� (Turbulent)";
    }

    // ��� ���
    printf("\n--- ���� �м� ��� ---\n");
    printf("���̳��� �� (Re): %.2f\n", Re); // ���� ���̳��� ���� �Ҽ��� ��° �ڸ����� ���
    printf("���� ����: %s\n", flow_status);   // �Ǻ��� ���� ���� ���ڿ� ���
    printf("���� (q): %.2f Pa\n", q);        // ���� ������ �Ҽ��� ��° �ڸ����� ��� (����: �Ľ�Į)

    // ���α׷� ���� ����
    return 0;
}
