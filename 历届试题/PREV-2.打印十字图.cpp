#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int row = 9 + 4 * (n - 1);
    //init
    char a[150][150];
    for(int i = 1; i <= row; i++) 
        for (int j = 1; j <= row; j++) 
            a[i][j] = '.';
    int mid = row / 2 + 1;
    //�м�ʮ�ּ�
    for (int i = mid - 2; i <= mid + 2; i++) {
        a[i][mid] = '$';
        a[mid][i] = '$';
    }
    //�߿�ʮ�ּ�
    int tn = n;
    while (tn != 0) {
        int trow = 9 + 4 * (tn - 1);
        // ��һ�к����һ�У���һ�к����һ��
        for (int i = mid - 2 * tn; i <= mid + 2 * tn; i++) {
            a[mid - 2 * (tn + 1)][i] = '$';
            a[mid + 2 * (tn + 1)][i] = '$';
            a[i][mid - 2 * (tn + 1)] = '$';
            a[i][mid + 2 * (tn + 1)] = '$';
        }
        //�ڶ��к͵����ڶ��У��ڶ��к͵����ڶ���
        a[mid - 2 * tn - 1][mid - 2 * tn] = '$';
        a[mid - 2 * tn - 1][mid + 2 * tn] = '$';
        a[mid - 2 * tn][mid - 2 * tn - 1] = '$';
        a[mid + 2 * tn][mid - 2 * tn - 1] = '$';
        a[mid + 2 * tn + 1][mid - 2 * tn] = '$';
        a[mid + 2 * tn + 1][mid + 2 * tn] = '$';
        a[mid - 2 * tn][mid + 2 * tn + 1] = '$';
        a[mid + 2 * tn][mid + 2 * tn + 1] = '$';
        //�ĸ�����Ľ�
        a[mid - 2 * tn][mid - 2 * tn] = '$';
        a[mid - 2 * tn][mid + 2 * tn] = '$';
        a[mid + 2 * tn][mid - 2 * tn] = '$';
        a[mid + 2 * tn][mid + 2 * tn] = '$';
        //��һ��
        tn--;
    }
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= row; j++) cout << a[i][j];
        cout << endl;
    }
    return 0;
}
