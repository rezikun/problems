#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int four = (int(s[s.size() - 2]) - int('0')) * 10;
    four += int(s[s.size() - 1]) - int('0');
    int fourhun = (int(s[0]) - int('0')) * 10;
    fourhun += int(s[1]) - int('0');
    bool flag = false;
    if (four % 4 == 0 && (int(s[s.size() - 2]) - int('0') != 0 || int(s[s.size() - 1]) - int('0') != 0)) {
        printf("This is leap year.\n");
        flag = true;
    }
    if ((int(s[s.size() - 2]) - int('0') == 0 && int(s[s.size() - 1]) - int('0') == 0) && fourhun % 4 == 0){
        printf("This is leap year.\n");
        flag = true;
    }
    int sum3 = 0;
    int sum11 = 0;
    for (int i = 0; i < s.size(); ++i) {
        sum3 += (int(s[i]) - int('0'));
        if (i % 2 == 0)
            sum11 += (int(s[i]) - int('0'));
        else
            sum11 -= (int(s[i]) - int('0'));
    }
    if ((int(s[s.size() - 1]) - int('0') == 5 || int(s[s.size() - 1]) - int('0') == 0) && sum3 % 3 == 0) {
        printf("This is huluculu festival year\n");
        flag = true;
    }
    if ((int(s[s.size() - 1]) - int('0') == 5 || int(s[s.size() - 1]) - int('0') == 0) && sum11 % 11 == 0) {
        printf("This is bulukulu festival year\n");
        flag = true;
    }
    if (!flag)
        printf("This is an ordinary year\n");
    return 0;
}
