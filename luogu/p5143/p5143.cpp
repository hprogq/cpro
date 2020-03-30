/*************************************************
  Date(When Created):    2020/03/30 09:43:55
  File & Description:    p5143.cpp
  Author & Copyright:    Hangqi (h.q_@outlook.com)
**************************************************/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 100000
using namespace std;
int n;
double a;
struct w {
    double x, y, z;
    bool operator < ( const w &other ) const {
        return z < other.z;
    }
} m[MAXN], l;
double sqr(double q) {
    return q * q;
}
int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%lf%lf%lf", &m[i].x, &m[i].y, &m[i].z);
    sort(m + 1, m + n + 1);
    l = m[1];
    for (int i=2; i<=n; i++) {
        w v = m[i];
        a += sqrt( sqr( v.x - l.x ) + sqr( v.y - l.y ) + sqr( v.z - l.z ) );
        l = v;
    }
    printf("%.3lf\n", a);
    return 0;
}

