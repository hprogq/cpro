/*************************************************
  Date(When Created):    2020/03/14 18:34:26
  File & Description:    p1042.cpp
  Author & Copyright:    Hangqi (h.q_@outlook.com)
**************************************************/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 100000
using namespace std;
int r;
bool m[MAXN];
void coll( int rule ) {
    int c1 = 0, c2 = 0;
    for (int i=1; i<=r; i++) {
        c1 += m[i] == true ? 1 : 0;
        c2 += m[i] == false ? 1 : 0;
        if ( ( ( c1 >= rule || c2 >= rule ) && abs( c1 - c2 ) >= 2 ) || i == r ) {
            printf("%d:%d\n", c1, c2);
            c1 = 0, c2 = 0;
        }
    }
    if ( r % rule == 0 )
        printf("0:0\n");
    return;
}
bool exec() {
    char d;
    scanf("%c", &d);
    switch (d) {
        case 69:
            return false;
            break;
        case 10:
            break;
        case 87:
            m[++r] = true;
            break;
        case 76:
            m[++r] = false;
            break;
    }
    return true;
}
int main() {
    while ( exec() );
    coll(11);
    printf("\n");
    coll(21);
    return 0;
}

