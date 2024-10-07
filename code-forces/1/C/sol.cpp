#include <iostream>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    map<int, int> m = {{0b000, 0}, {0b100, -1}, {0b010, 0}, {0b110, 1}, {0b001, 1}, {0b101, 1}, {0b011, -1}, {0b111, 0}};
    for (int i = 0; i < t; i++) {
        long long b,c,d,r,res,j;
        cin >> b >> c >> d;
        res = j = 0;
        while (b > 0 || c > 0 || d > 0) {
            r = ((b&1)<<2) + ((c&1)<<1) + (d&1);
            if (m[r] == -1) {
                res = -1;
                break;
            }
            res |= m[r] << j;
            j += 1;
            b = (b >> 1), c = (c >> 1), d = (d >> 1);
        }
        cout << res << endl;
    }
}