/*************************************************
  Date(When Created):    2020/02/05 00:09:21
  File & Description:    uva1592.cpp
  Author & Copyright:    Hangqi (h.q_@outlook.com)
**************************************************/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#define MAXN 10001
#define MAXM 11
using namespace std;
typedef pair<int, int> mkpair;
map<string, int> has;
map<mkpair, int> ans;
int data[MAXN][MAXM];
int n, m, remix = 1;
inline void sh(int i, int j) {
    string t;
    getline(cin, t, j == m ? '\n' : ',');
    map<string, int>::iterator iter = has.find(t);
    data[i][j] = iter != has.end() ? iter -> second : remix;
    if ( iter == has.end() )
        has[t] = remix++;
    return;
}
int main() {
    while ( scanf("%d %d\n", &n, &m) != EOF ) {
        remix = 1;
        has.clear();
        bool done = false;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                sh (i, j);
        for (int c1=1; c1<=m-1; c1++)
            for (int c2=c1+1; c2<=m; c2++) {
                ans.clear();
                for (int r=1; r<=n; r++) {
                    int x = data[r][c1], y= data[r][c2];
                    map<mkpair, int>::iterator iter = ans.find( mkpair(x, y) );
                    if ( iter != ans.end() ) {
                        printf("NO\n%d %d\n%d %d\n", iter -> second, r, c1, c2);
                        done = true;
                        goto ending;
                    } else ans[ mkpair(x, y) ] = r;
                }
            }
        if ( !done )
            printf("YES\n");
ending:;
    }
    return 0;
}
