#pragma optimization_level 4
#pragma optimize_for_size off
#define SIGDIGLEN 32
typedef struct decimal {
    char sign;
    short exp;
    struct { unsigned char length; unsigned char text[SIGDIGLEN]; } sig;
} decimal;
// Original: arm9/main @ 0x02009EDC; symbol: func_02009edc; size: 0x2A4.
// MSL ansi_fp.c __minus_dec: decimal subtraction, discarded-digit rounding and normalization.
// Pinned C reference zeldaret/tp c8fa8c9e2aab72cf4e5db0e5d1c84a9ea6ee6eb0;
// NDS variant uses32significant digits instead of36.
void __minus_dec(decimal* z, const decimal* x, const decimal* y) {
    int zlen, dexp;
    unsigned char *ib, *i, *ie;
    unsigned char const *jb, *j, *jn;

    *z = *x;

    if (y->sig.text[0] == 0)
        return;

    zlen = z->sig.length;
    if (zlen < y->sig.length)
        zlen = y->sig.length;

    dexp = z->exp - y->exp;
    zlen += dexp;

    if (zlen > SIGDIGLEN)
        zlen = SIGDIGLEN;

    while (z->sig.length < zlen) {
        z->sig.text[z->sig.length++] = 0;
    }

    ib = z->sig.text;
    i = ib + zlen;

    if (y->sig.length + dexp < zlen) {
        i = ib + (y->sig.length + dexp);
    }

    jb = y->sig.text;
    j = jb + (i - ib - dexp);
    jn = j;

    while (i > ib && j > jb) {
        i--;
        j--;
        if (*i < *j) {
            unsigned char* k = i - 1;
            while (*k == 0)
                k--;
            while (k != i) {
                --*k;
                *++k += 10;
            }
        }
        *i -= *j;
    }

    if (jn - jb < y->sig.length) {
        int round_down = 0;
        if (*jn < 5)
            round_down = 1;
        else if (*jn == 5) {
            unsigned char const* ibPtr = y->sig.text + y->sig.length;

            for (j = jn + 1; j < ibPtr; j++) {
                if (*j != 0)
                    goto done;
            }
            i = ib + (jn - jb) + dexp - 1;
            if (*i & 1)
                round_down = 1;
        }
        if (round_down) {
            if (*i < 1) {
                unsigned char* k = i - 1;
                while (*k == 0)
                    k--;
                while (k != i) {
                    --*k;
                    *++k += 10;
                }
            }
            *i -= 1;
        }
    }
done:
    for (i = ib; *i == 0; ++i) {
    }

    if (i > ib) {
        unsigned char dl = (unsigned char)(i - ib);
        z->exp -= dl;
        ie = ib + z->sig.length;
        for (; i < ie; ++i, ++ib)
            *ib = *i;
        z->sig.length -= dl;
    }

    ib = z->sig.text;
    for (i = ib + z->sig.length; i > ib;) {
        i--;
        if (*i != 0)
            break;
    }
    z->sig.length = (unsigned char)(i - ib + 1);
}
