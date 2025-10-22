#include <iostream>
#include <cmath>

using namespace std;

int calculate_gcd_while(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    cout << "Enter the first integer: ";
    if (!(cin >> num1)) return 1;

    cout << "Enter the second integer: ";
    if (!(cin >> num2)) return 1;

    if (num1 == 0 || num2 == 0) {
        cout << "GCD: " << abs(num1) + abs(num2) << endl;
        cout << "LCM: 0" << endl;
        return 0;
    }

    int gcd_result = calculate_gcd_while(num1, num2);

    long long lcm_result = (long long)num1 / gcd_result * num2;

    cout << "\n--- Results (while loop) ---" << endl;
    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    cout << "GCD (Greatest Common Divisor): " << gcd_result << endl;
    cout << "LCM (Least Common Multiple): " << lcm_result << endl;

    return 0;
}