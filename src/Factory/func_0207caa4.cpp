struct LookupRecord {
    unsigned char pad0[0xbd0];
    short *lists[8];
    unsigned char pad1[0x20];
    short lengths[8];
    unsigned char keys[8];
};

extern "C" int func_0207caa4(LookupRecord *base, int value, unsigned char key) {
    if (value < 0) {
        return -2;
    }

    unsigned int index = ~0u;
    int i = 0;
    while (i < 8) {
        if (base->keys[i] == key) {
            index = i;
            break;
        }
        ++i;
    }
    if (index == ~0u) {
        return -2;
    }

    short *entries = base->lists[index];
    short count = base->lengths[index];
    short item = 0;
    while (item < count) {
        if (entries[item] == value)
            return item;
        item++;
    }
    return -1;
}
