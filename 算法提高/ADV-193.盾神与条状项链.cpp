#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if(s == "DEL") {
            int p;
            cin >> p;
            for(vector<int>::iterator it = v.begin(); it != v.end(); it++) 
                if(*it == p) {
                    v.erase(it);
                    break;
                }
        }
        if(s == "ADD") {
            int p, q;
            cin >> p >> q;
            for(vector<int>::iterator it = v.begin(); it != v.end(); it++) 
                if(*it == p) {
                    v.insert(it, q);
                    break;
                }
        }
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}
