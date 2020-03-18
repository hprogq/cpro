/*************************************************
  Time(When Created):    2020/03/18 11:38:06
  File & Description:    p1065.cpp
  Author & Copyright:    Hangqi (h.q_@outlook.com)
**************************************************/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pac;
typedef map<int, pac> mac;
mac r[MAXN];
int m, n, o[MAXN], p[MAXN][MAXN], t[MAXN][MAXN], d[MAXN], s1[MAXN], s2[MAXN];
bool v[MAXN][MAXN];
mac::iterator fir[MAXN][MAXN];
void input() {
    // Basic datas
    scanf("%d %d\n", &m, &n);
    // Range Order
    for (int i=1; i<=m*n; i++)
        scanf("%d", &o[i]);
    // Machine Number
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            scanf("%d", &p[i][j]);
    // Processing Time
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            scanf("%d", &t[i][j]);
    // End
    return;
}
int checkEmpty(int mah, int ti, int di, int ob) {
    int z = 0;
    mac::iterator fs = fir[mah][ob];
    if ( !v[mah][ob] ) {
        v[mah][ob] = true;
        fs = r[mah].begin();
    }
    for (mac::iterator i=fs; i!=r[mah].end(); i++) {
        pac q = (*i).second;
        int q1 = q.first, q2 = q.second;
        int emp = q1 - z;
        if ( emp >= ti && ti + di <= q1 )
            return max(z, di);
        z = q2;
    }
    return max(z, di);
}
void insertData(int mah, int we, int ts, int ti) {
    int te = ts + ti;
    pac dat(ts, te);
    pair<int, pac> daa(ts, dat);
    pair<mac::iterator, bool> ret = r[mah].insert(daa);
    if ( s1[mah] < te )
        s1[mah] = te;
    if ( s2[we] < te )
        s2[we] = te;
    fir[mah][we] = ret.first;
    return;
}
void simulation() {
    for (int i=1; i<=m*n; i++) {
        int w = o[i];
        int g = ++d[w];
        int h = p[w][g];
        int c = t[w][g];
        int l = s2[w];
        int e = checkEmpty(h, c, l, w);
        insertData(h, w, e, c);
    }
    return;
}
void getOutput() {
    int ans = -0x7fffffff;
    for (int i=1; i<=m; i++) {
        mac::iterator mc = r[i].end();
        int tm = (*(--mc)).second.second;
        if ( tm > ans )
            ans = tm;
    }
    printf("%d\n", ans);
    return;
}
void configure() {
    for (int i=1; i<=m; i++) {
        pac dat(0, 0);
        r[i][-1] = dat;
    }
    return;
}
int main() {
    input();
    configure();
    simulation();
    getOutput();
    return 0;
}

