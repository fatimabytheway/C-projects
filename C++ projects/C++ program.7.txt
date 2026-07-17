
//program.7: Write a program that will take the matrix number from the user as input and will calculate the sum and multiplication of these matrix.// 
#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;
    
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;
    
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }
    
    int a[r1][c1], b[r2][c2], result[r1][c2];
    
    cout << "Enter first matrix elements:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> a[i][j];
        }
    }
    
    cout << "Enter second matrix elements:" << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> b[i][j];
        }
    }
    
    // Multiply
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    cout << "\nResult Matrix:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
