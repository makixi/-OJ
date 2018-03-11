#include <iostream>
#include <cstring>
using namespace std;
struct matrix{
	long long a[8][8];
};
matrix multiply(matrix x, matrix y, int m, int n, int s){
	matrix temp;
	memset(temp.a, 0, sizeof(temp.a));
	for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			for (int k = 0; k<s; k++)
				temp.a[i][j] = (temp.a[i][j] + (x.a[i][k] * y.a[k][j]) % 99999999) % 99999999;
	return temp;
}
int main(){
	matrix temp = {
		0,1,1,0,0,0,0,0,
		1,0,0,1,0,0,0,0,
		0,0,0,0,1,0,0,0,
		0,0,0,0,0,1,0,0,
		2,3,0,0,0,0,0,0,
		0,2,0,0,0,0,0,0,
		1,0,0,0,0,0,1,0,
		0,1,0,0,0,0,0,1
	};
	matrix res;
	long long f[8] = { 6,5,1,4,2,3,5,3 }, sum1, sum2, n;
	memset(res.a, 0, sizeof(res.a));
	for (int i = 0; i<8; i++)
		res.a[i][i] = 1;
	cin >> n;
	if (n == 1) cout << "2" << endl << "3" << endl;
	if (n == 2) cout << "1" << endl << "4" << endl;
	if (n == 3) cout << "6" << endl << "5" << endl;
	if (n >= 4){
		n = n - 3;
		while (n){
			if (n & 1) res = multiply(res, temp, 8, 8, 8);
			n >>= 1;
			temp = multiply(temp, temp, 8, 8, 8);
		}
		sum1 = sum2 = 0;
		for (int i = 0; i<8; i++){
			sum1 = (sum1 + (f[i] * res.a[i][0]) % 99999999) % 99999999;
			sum2 = (sum2 + (f[i] * res.a[i][1]) % 99999999) % 99999999;
		}
		cout << sum1 << endl << sum2 << endl;
	}
	return 0;
}
