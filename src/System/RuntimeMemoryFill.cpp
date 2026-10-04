#pragma optimize_for_size off

// Aligned word stores handle full blocks; byte stores handle the edges.
extern "C" void func_02001b2c(void* destination, int value, unsigned int count)
{
    unsigned char* dest = (unsigned char*)destination;
    unsigned int word = (unsigned char)value;
    if (count >= 32) {
        unsigned int leading = -(unsigned int)dest & 3;
        if (leading) {
            count -= leading;
            do {
                *dest++ = (unsigned char)word;
            } while (--leading);
        }
        if (word) {
            word |= (word << 24) | (word << 16) | (word << 8);
        }
        unsigned int blocks = count >> 5;
        if (blocks) {
            do {
                ((unsigned int*)dest)[0] = word;
                ((unsigned int*)dest)[1] = word;
                ((unsigned int*)dest)[2] = word;
                ((unsigned int*)dest)[3] = word;
                ((unsigned int*)dest)[4] = word;
                ((unsigned int*)dest)[5] = word;
                ((unsigned int*)dest)[6] = word;
                ((unsigned int*)dest)[7] = word;
                dest += 32;
            } while (--blocks);
        }
        unsigned int words = (count & 31) >> 2;
        if (words) {
            do {
                *(unsigned int*)dest = word;
                dest += 4;
            } while (--words);
        }
        count &= 3;
    }
    if (count) {
        do {
            *dest++ = (unsigned char)word;
        } while (--count);
    }
}
