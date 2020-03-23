/*************************************************
  Date(When Created):    2020/03/23 00:34:31
  File & Description:    p1591.cpp
  Author & Copyright:    Hangqi (h.q_@outlook.com)
**************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define MAXN 3000
using namespace std;
int e, r, w, n[15][MAXN], l;
/**
 * @name progress
 * @param seq Sequence of the data.
 * @param depth The depth of the process.
 * @return NULL
 */
void progress(int seq, int depth) {
    // t: Size of the carry value.
    int t = 0;
    // Start loop.
    for (int i=1; i<=l; i++) {
        int s;
        s = n[seq][i] * depth + t;
        n[seq][i] = s % 10;
        t = s / 10;
    }
    // Loop end.
    // Check length exists.
    if ( t ) {
        int x = 1 + (int) log10(t);
        while ( x-- ) {
            n[seq][++l] = t % 10;
            t /= 10;
        }
    }
    // If Progressing end.
    depth++ != r ? progress(seq, depth) : (void) NULL;
    return;
}
/**
 * @name configure
 * @description Reserved function.
 * @param seq Sequence of the data.
 * @return NULL
 */
void configure(int seq) {
    // Ensure Data Reset.
    l = 1;
    n[seq][1] = 1;
    // Start Progressing the procedure.
    progress(seq, 2);
    // Processing End.
    return;
}
/**
 * @name censor
 * @description Check and Export the result.
 * @param seq Sequence of the data.
 * @return NULL
 */
void censor(int seq) {
    // a: Answer.
    int a = 0;
    // Start Checking.
    for (int i=1; i<=l; i++)
        if ( n[seq][i] == w )
            a++;
    // Export Answer.
    printf("%d\n", a);
    // Processing Finish.
    return;
}
int main() {
    // Input Basic Data.
    scanf("%d", &e);
    // Process Start.
    while ( e ) {
        // Input sequence data.
        scanf("%d%d", &r, &w);
        // Configure and Start.
        configure(e);
        // Output results.
        censor( e-- );
    }
    return 0;
}

