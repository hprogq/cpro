/*************************************************
  Date(When Created):    2020/03/14 18:11:36
  File & Description:    p1601.cpp
  Author & Copyright:    Hangqi (h.q_@outlook.com)
**************************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#define MAXN 1000
using namespace std;
int n[3][MAXN], p, q, a[MAXN], w, h, die;
void inp(int x, int *pos) {
	string t;
	cin >> t;
	*pos = t.length();
	for (int i=1; i<=t.length(); i++)
    	n[x][i] = (int) t[i-1] - 48;
	return;
}

int main() {
	inp(1, &p);
	inp(2, &q);
	for (int i=1; i<=max(p,q)+1; i++) {
		int q1 = ( p - i + 1 ) > 0 ? ( p - i + 1 ) : 0;
		int q2 = ( q - i + 1 ) > 0 ? ( q - i + 1 ) : 0;
		int k1 = n[1][q1], k2 = n[2][q2];
		int stat = k1 + k2 + w;
		a[i] = stat % 10;
		h = a[i] != 0 ? 1 : 0;
		w = stat / 10;
	}
	int nume = max(p, q) + h;
	for (int i=1; i<=nume; i++)
		printf("%d", a[ nume - i + 1 ]);
	printf("\n");
	return 0;
}

