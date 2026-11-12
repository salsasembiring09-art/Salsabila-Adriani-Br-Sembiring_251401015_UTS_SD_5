#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[2][3][4];

    int ganjil = 1, kelipatan = 5;
    for (int j = 0; j < 3; j++)
        for (int k = 0; k < 4; k++) {
            arr[0][j][k] = ganjil;     
            ganjil += 2;
        }
    for (int j = 0; j < 3; j++)
        for (int k = 0; k < 4; k++) {
            arr[1][j][k] = kelipatan;  
            kelipatan += 5;
        }

    int hasil[3][4];
    for (int j = 0; j < 3; j++)
        for (int k = 0; k < 4; k++)
            hasil[j][k] = max(arr[0][j][k], arr[1][j][k]);

    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 4; k++)
            cout << hasil[j][k] << (k < 3 ? " " : "");
        cout << "\n";
    }
    return 0;
}