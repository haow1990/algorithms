#include <cstdio>
#include <iostream>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

int getBinaryInt()
{
    static string tmp;
    int result = 0;
    cin >> tmp;
    for (int j = 0; j < 7; ++j) {
        result <<= 1;
        if (tmp[j] == '1') {
            result |= 1;
        }
    }
    return result;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main(int argc, char **argv)
{
    int correct[10] = {
        0b1111110,  // 0
        0b0110000,  // 1
        0b1101101,  // 2
        0b1111001,  // 3
        0b0110011,  // 4
        0b1011011,  // 5
        0b1011111,  // 6
        0b1110000,  // 7
        0b1111111,  // 8
        0b1111011   // 9
    };
    bitset<7> orignals[10];
    for (int i = 0; i < 10; ++i) {
        orignals[i] |= bitset<7>(correct[i]);
    }
    bitset<10> ok[128];
    for (int i = 0; i < 128; ++i) {
        for (int j = 0; j < 10; ++j) {
            if ((i & ~correct[j]) == 0) {
                ok[i].set(j);
            }
        }
    }
    int cases;
    cin >> cases;
    bitset<7> displays[200];
    for (int c = 1; c <= cases; ++c) {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            displays[i].reset();
            displays[i] |= bitset<7>(getBinaryInt());
        }
        bool good = true;
        for (int n = 10; n < N; ++n) {
            if (displays[n] != displays[n % 10]) {
                good = false;
                break;
            }
        }
        if (good == false) {
            printf("Case #%d: ERROR!", c);
            if (c < cases) {
                printf("\n");
            }
            continue;
        }
        bitset<7> ok;
        bitset<7> bad;
        bool possible = false;
        bool agree = false;
        bitset<7> result;
        for (int begin = 0; begin < 10; ++begin) {
            ok.reset();
            bad.reset();
            bool valid = true;
            for (int n = 0; n < min(N, 10); ++n) {
                if ((displays[n] & bad).any()) {
                    valid = false;
                    break;
                }
                int num = (begin + 10 - n) % 10;
                if ((~orignals[num] & displays[n]).any()) {
                    valid = false;
                    break;
                }
                ok |= displays[n];
                bad |= orignals[num] & ~displays[n];
                if ((ok & bad).any()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                possible = true;
                int num = (begin + 10 - N % 10) % 10;
                if ((orignals[num] & ~(bad | ok)).any() == false) {
                    bitset<7> thisresult = orignals[num] & ok;
                    if (agree == false) {
                        result |= thisresult;
                        agree = true;
                    } else if (result != thisresult) {
                        agree = false;
                        break;
                    }
                } else {
                    agree = false;
                    break;
                }
            }
        }
        if (!possible) {
            printf("Case #%d: ERROR!", c);
        } else if (N >= 10) {
            string str = displays[N % 10].to_string();
            printf("Case #%d: %s", c, str.c_str());
        } else if (agree) {
            string str = result.to_string();
            printf("Case #%d: %s", c, str.c_str());
        } else {
            printf("Case #%d: ERROR!", c);
        }
        if (c < cases) {
            printf("\n");
        }
    }
    return 0;
}

