#include <globaldefs.h>
ARM
extern "C" void __clear(void*, unsigned);
extern "C" unsigned int strlen(const char*);
extern "C" int ProfileTextFilter_ContainsCharacterInSet(unsigned char*, unsigned char*, int, int);
// Original: arm9/ov012 @ 0x02185684; symbol: func_ov012_02185684; size: 0x370.
extern "C" int Util_MatchBytePattern(unsigned char* self, unsigned char* pattern, unsigned char* text, int unused, int length) {
    unsigned char *p, *t;
    unsigned int ch;
    int n, min, neg, max;
    int any = self[0x2a], open = self[0x2b], close = self[0x2c], repeat = self[0x2d], endrepeat = self[0x2e], seek = self[0x31];
    for (int pos=0;pos<length;pos++,text++) {
        p = pattern;
        t = text;
        for (;;) {
            if (*p == 0) return 1;
            min = 1;
            ch = *t;
            max = 1;
            unsigned char* q = p;
            if (*p == open) {
                for (;;) {
                    if (*q == close) { q++; break; }
                    q++;
                }
            } else q = p+1;
            if (*q == repeat) {
                min = q[1]-8;
                max = q[3]-8;
                if (q[4]-8 == 0) max *= 10;
            }
            int match=1;
            if (*p == seek) {
                if (min == 0 && max == 60) {
                    int target = p[7];
                    for (;;) {
                        if (*t == 0 || *t == 255) return 0;
                        if (target == *t) break;
                        t++;
                    }
                    p+=8;
                    t++;
                    continue;
                }
            } else if (*p == any) {
                if (ch < 0x12 || ch > 0x2b) match=0;
            } else if (*p == open) {
                unsigned char set[8] = {};
                neg=0;
                unsigned char *src, *dst;
                dst=set; src=p+1;
                n=0;
                int rangechar, negchar, terminator;
                terminator=self[0x2c]; negchar=self[0x2f]; rangechar=self[0x30];
                while (*src != terminator) {
                    int value = *src;
                    *dst = value;
                    if (value == negchar) n=2;
                    if (value == rangechar) neg=1;
                    src++; dst++;
                }
                neg+=n;
                n=strlen((char*)set);
                if (neg==0) match=ProfileTextFilter_ContainsCharacterInSet(self,set,n,ch);
                else if (neg==1) { unsigned int hi=set[n-1]; match=(set[0]<=ch && ch<=hi); }
                else if (neg==2) match=!ProfileTextFilter_ContainsCharacterInSet(self,set+1,n-1,ch);
                else if (neg==3) { unsigned char *base=set+1; unsigned int hi=base[n-2]; match=!(set[1]<=ch && ch<=hi); }
                p+=n+1;
            } else if(*p!=ch) match=0;
            if (match) {
                for (int i=0;i<min;) {
                    if (ch!=*t) { match=0; break; }
                    i++; t++;
                }
                if (!match) break;
                while(min<max) {
                    if(ch!=*t) break;
                    min++;t++;
                }
            } else { if (!match) { if (min!=0) break; } }
            p++;
            if (*p==repeat) {
                for (;;) { if (*p==endrepeat) break; p++; }
                p++;
            }
        }
    }
    return 0;
}
