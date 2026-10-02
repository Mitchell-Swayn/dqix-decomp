// Storage used by the MODSN2/MODSN3 decoder. Arena 3 holds a relocatable
// executable decoder image; arena 4 holds lookup tables. The image and 0x2100
// table remain original fallback dependencies, with no source credit here.
struct DecoderTableCache
{
    unsigned char* table300;
    unsigned char* table2100;
    unsigned char* decoderImage;
    unsigned tableBytesRemaining;
    unsigned char* tableCursor;
    unsigned imageBytesRemaining;
    unsigned char* imageCursor;
    unsigned unknown1c;
    unsigned char* clampTable;
};
typedef char DecoderTableCacheSizeCheck[sizeof(DecoderTableCache) == 0x24 ? 1 : -1];

extern "C" {
DecoderTableCache data_ov016_0219d1c0;
extern unsigned char data_ov016_02195f78[0x659c];
extern unsigned char data_ov016_02193e78[0x2100];
extern const unsigned char data_ov016_0219cbe0[0x300];
extern const unsigned char data_ov016_0219ca60[0x180];
void func_020ca4b4(const void* source, void* destination, unsigned bytes);

unsigned func_ov016_0218fc78() { return 0x659c; }
unsigned func_ov016_0218fc84() { return 0x2580; }

void func_ov016_0218fc8c(unsigned char* storage, unsigned bytes)
{
    data_ov016_0219d1c0.imageCursor = storage;
    data_ov016_0219d1c0.imageBytesRemaining = bytes & ~3u;
    data_ov016_0219d1c0.decoderImage = 0;
}

void func_ov016_0218fcac(unsigned char* storage, unsigned bytes)
{
    data_ov016_0219d1c0.tableCursor = storage;
    data_ov016_0219d1c0.tableBytesRemaining = bytes & ~3u;
    data_ov016_0219d1c0.table2100 = 0;
    data_ov016_0219d1c0.table300 = 0;
    data_ov016_0219d1c0.clampTable = 0;
}

unsigned char* func_ov016_0218fcd4()
{
    if (!data_ov016_0219d1c0.decoderImage) {
        if (data_ov016_0219d1c0.imageBytesRemaining >= 0x659c) {
            data_ov016_0219d1c0.decoderImage = data_ov016_0219d1c0.imageCursor;
            func_020ca4b4(data_ov016_02195f78, data_ov016_0219d1c0.imageCursor, 0x659c);
            data_ov016_0219d1c0.imageCursor += 0x659c;
            data_ov016_0219d1c0.imageBytesRemaining -= 0x659c;
        } else {
            return data_ov016_02195f78;
        }
    }
    return data_ov016_0219d1c0.decoderImage;
}

unsigned char* func_ov016_0218fd50()
{
    if (!data_ov016_0219d1c0.table2100) {
        if (data_ov016_0219d1c0.tableBytesRemaining >= 0x2100) {
            data_ov016_0219d1c0.table2100 = data_ov016_0219d1c0.tableCursor;
            func_020ca4b4(data_ov016_02193e78, data_ov016_0219d1c0.tableCursor, 0x2100);
            data_ov016_0219d1c0.tableCursor += 0x2100;
            data_ov016_0219d1c0.tableBytesRemaining -= 0x2100;
        } else {
            return data_ov016_02193e78;
        }
    }
    return data_ov016_0219d1c0.table2100;
}

const unsigned char* func_ov016_0218fdc0()
{
    if (!data_ov016_0219d1c0.table300) {
        if (data_ov016_0219d1c0.tableBytesRemaining >= 0x300) {
            data_ov016_0219d1c0.table300 = data_ov016_0219d1c0.tableCursor;
            func_020ca4b4(data_ov016_0219cbe0, data_ov016_0219d1c0.tableCursor, 0x300);
            data_ov016_0219d1c0.tableCursor += 0x300;
            data_ov016_0219d1c0.tableBytesRemaining -= 0x300;
        } else {
            return data_ov016_0219cbe0;
        }
    }
    return data_ov016_0219d1c0.table300;
}

const unsigned char* func_ov016_0218fe30()
{
    if (!data_ov016_0219d1c0.clampTable) {
        if (data_ov016_0219d1c0.tableBytesRemaining >= 0x180) {
            data_ov016_0219d1c0.clampTable = data_ov016_0219d1c0.tableCursor;
            func_020ca4b4(data_ov016_0219ca60, data_ov016_0219d1c0.tableCursor, 0x180);
            data_ov016_0219d1c0.tableCursor += 0x180;
            data_ov016_0219d1c0.tableBytesRemaining -= 0x180;
        } else {
            return data_ov016_0219ca60;
        }
    }
    return data_ov016_0219d1c0.clampTable;
}
}
