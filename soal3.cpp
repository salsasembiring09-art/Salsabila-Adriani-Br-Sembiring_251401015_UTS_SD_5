#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Stack {
    char data[MAX];
    int top = -1;

    void push(char c) { data[++top] = c; }
    char pop()        { return data[top--]; }
    bool empty()      { return top == -1; }
};

int main() {
    string kata;
    cout << "Masukkan kata : ";
    cin >> kata;

    Stack s;
    for (char c : kata) s.push(c);

    string dibalik;
    while (!s.empty()) dibalik += s.pop();

    cout << "Kata dibalik : " << dibalik << "\n";
    if (dibalik == kata)
        cout << "Kesimpulan : Kata ini adalah palindrom\n";
    else
        cout << "Kesimpulan : Bukan palindrom\n";
    return 0;
}