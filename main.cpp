
#include <iostream>
#include <locale.h>
using namespace std;

int main() {
    // ================
    setlocale(LC_CTYPE, "Polish");
    // ================

    cout << "Witaj świecie!\n";

    return 0;
}
