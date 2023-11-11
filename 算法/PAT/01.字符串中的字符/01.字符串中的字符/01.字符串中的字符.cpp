#include <iostream>

using namespace std;
char s[100010];
int main() {

    cin >> s;
    long long p = 0;
    long long a = 0;
    long long t = 0;
    for (int i = 0; s[i];i++)
    {
        if (s[i] == 'P')
        {
            p += 1;
        }
        else if (s[i] == 'A')
        {
            a = a + p;
        }
        else if (s[i] == 'T')
        {
            t = t + a;
        }
    }
    t = t % 1000000007;
    cout << t << endl;
    return 0;
    
}
// 64 位输出请用 printf("%lld")
