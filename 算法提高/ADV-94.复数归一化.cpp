#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a, b;
    double p, q;
    cin >> a >> b;
    p = a / sqrt(a * a + b * b);
    q = b / sqrt(a * a + b * b);
    printf("%.1lf",p);
    if(q > 0) cout << "+";
    printf("%.1lfi",q);
    return 0;
}
