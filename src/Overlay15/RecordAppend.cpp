#pragma always_inline on

struct Overlay15Record {
    unsigned int word_00;
    unsigned int word_04;
    unsigned short halfword_08;
    unsigned char byte_0a;
    unsigned char byte_0b;
};

struct Overlay15RecordList {
    Overlay15Record* records;
    unsigned int capacity;
    unsigned int count;
};

extern "C" void func_ov015_0218b9d4(
    Overlay15RecordList* list,
    const Overlay15Record* record)
{
    list->records[list->count++] = *record;
}
