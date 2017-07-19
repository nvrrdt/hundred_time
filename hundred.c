/* Writes the time with one major difference:
 * one day has 100 hours
 * one hour has 100 minutes
 * one minute has 100 seconds
 */



#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char h[4], m[4], s[4];
    char *hp, *mp, *sp;
    long hl, ml, sl;
    double timeperc;
    double hh, hm, hs; //hundred hours, hundred minutes and hundred seconds

    strftime(h, sizeof(h), "%H", tm);
    strftime(m, sizeof(m), "%M", tm);
    strftime(s, sizeof(s), "%S", tm);
    
    hl = strtol(h, &hp, 10);
    ml = strtol(m, &mp, 10);
    sl = strtol(s, &sp, 10);

    timeperc = ((double) hl + ((double) ml / 60) + ((double) sl / 3600)) / 24;

    hh = floor(100 * timeperc);
    hm = floor(100 * 100 * timeperc) - (100 * hh);
    hs = floor(100 * 100 * 100 * timeperc) - (100 * 100 * hh) - (100 * hm);

    printf("Hundred time: %d:%d:%d\n", (int) hh, (int) hm, (int) hs);
    printf("One day has 100 hours, one hour has 100 minutes and one minute has 100 seconds\n");

    return 0;
}
