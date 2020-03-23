/*************************************************
  Date(When Created):    2020/03/23 08:58:36
  File & Description:    p1098.cpp
  Author & Copyright:    Hangqi (h.q_@outlook.com)
**************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int p1, p2, p3;
bool d, e;
char k;
string s;
void input() {
    scanf("%d %d %d\n", &p1, &p2, &p3);
    cin >> s;
    return;
}
bool genre(int f) {
    if ( f >= 97 && f <= 122 )
        return true;
    else if ( f >= 48 && f <= 57 )
        return false;
    return false;
}
void progress(char x, char y) {
    // Configure param 'p1'.
    int o;
    switch ( p1 ) {
        case 1:
            o = 0;
            break;
        case 2:
            o = -32;
            break;
        case 3:
            o = -1;
            break;
    }
    // Start.
    printf("%c", x);
    for (int i=(int) x+1; i<=(int) y-1; i++) {
        char z;
        if ( o == -1 )
            z = '*';
        else z = (char) ( ( p3 == 2 ? (int) x + (int) y - i : i ) + ( genre(x) ? o : 0 ) );
        for (int j=1; j<=p2; j++)
            printf("%c", z);
    }
    return;
}
void configure() {
    for (int i=0; i<=(int) s.length(); i++) {
        if ( i == (int) s.length() ) {
            if ( d )
                printf("%c", k);
            if ( e )
                printf("%c", '-');
            return;
        }
        char t = s[i];
        if ( !d && t != '-' )
            k = t, d = true, e = false;
        else if ( d && t == '-' && !e )
            e = true;
        else if ( d && e && (int) k < (int) t && genre(k) == genre(t) ) {
            progress(k, t);
            d = true;
            k = t;
            e = false;
        } else {
            if ( d )
                printf("%c", k);
            if ( e )
                printf("%c", '-');
            d = e = false;
            if ( t != '-' ) {
                d = true;
                k = t;
            } else printf("%c", t);
        }
    }
    return;
}
int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    input();
    configure();
    return 0;
}

