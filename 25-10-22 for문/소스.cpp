#include <iostream>

using namespace std;

int main() {
    for (int dan = 2; dan <= 9; dan++) {
        cout << "\n--- " << dan << " ´Ü ---" << endl;
        for (int i = 1; i <= 9; i++) {
            cout << dan << " * " << i << " = " << dan * i << endl;
        }
    }
    return 0;
}