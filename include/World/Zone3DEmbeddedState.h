#pragma once

class SafeAllocator;

// Partial embedded types. Names retain offsets until their gameplay purposes
// are established. Only fields touched by recovered routines are identified.
extern "C" void func_020982b4(void*);

struct ZoneState0840
{
    char unknown[0x1b78];
    ZoneState0840() { func_020982b4(this); }
    ~ZoneState0840() { Finish(); }
    void Finish();
};
struct ZoneState2664
{
    int unknown_0;
    int unknown_4;
    char unknown_8[0xb4 - 8];
    unsigned char unknown_b4;
    unsigned char unknown_b5;
    unsigned char unknown_b6;
    signed char unknown_b7;
    signed char unknown_b8;
    char unknown_b9;
    unsigned short unknown_ba;
    signed char unknown_bc;
    char unknown_bd[3];
    ZoneState2664() { Reset(); }
    ~ZoneState2664() { Reset(); }
    void Reset();
};
struct ZoneState2724
{
    struct Entry
    {
        unsigned short unknown_0, unknown_2, unknown_4, unknown_6;
        union Coordinates
        {
            struct { int x, y, z; };
            int entries[3];
        } coordinates;
    };
    Entry* entries;
    int unknown_4;
    int unknown_8;
    void SetEntry(const Entry* entry, int index);
    Entry* GetEntry(int index);
    ZoneState2724() { Reset(); }
    ~ZoneState2724() { Reset(); }
    void Reset();
};
struct ZoneSerializedRecord
{
    union { unsigned int index; ZoneSerializedRecord* pointer; } secondary;
    union { unsigned int offset; void* pointer; } payload;
    unsigned int unknown_8;
    struct FilterBits
    {
        unsigned int low : 12;
        unsigned int category : 11;
        unsigned int high : 9;
    } filter;
    struct Attributes
    {
        unsigned int first : 10;
        unsigned int second : 10;
        unsigned int group : 8;
        unsigned int unknown : 4;
    } attributes;
    unsigned short unknown_14;
    unsigned short unknown_16;
    short key;
    char unknown_1a[6];
};

struct ZoneState2754
{
    // Also used independently as a 20-byte stack temporary by the builders.
    struct Data
    {
        unsigned short primaryCount;
        struct SecondaryCount
        {
            unsigned short count : 15;
            unsigned short hasExtraBlock : 1;
        } secondary;
        unsigned short unknownCount4;
        unsigned short unknown6;
        unsigned int payloadSize : 31;
        unsigned int relocated : 1;
        char* records;
        void* payload;
        ZoneSerializedRecord* FindByAttributes(int group, int first, int second);
        ZoneSerializedRecord* FindRelatedRecord(int group, const ZoneSerializedRecord* record);
        short GetRecordCountBound();
        ZoneSerializedRecord* GetRecordAtIndex(int index);
        short CountMatchingRecords(int alternate, unsigned int kind, int first, signed char second);
        ZoneSerializedRecord* FindMatchingRecord(int index, int alternate, unsigned int kind, signed char first, signed char second);
        bool RelocateSecondaryRecordLinks();
        bool ApplySpecialRecordFlags();
        bool LoadSerializedData(void* file, unsigned int size);
        bool AttachSerializedData(void* file, bool* alreadyRelocated, bool (*callback)(Data*, void*));
        void* FindPrimaryRecord(int key, int (*getKey)(const void*));
        unsigned int GetRecordStorageSize();
        bool VisitPrimaryRecords(bool (*callback)(Data*, void*));
    } data;
    unsigned char unknown_14;
    char padding[3];
    ZoneState2754();
    bool BuildForKey(SafeAllocator* allocator, void* file, unsigned int size, short key);
    bool BuildForKeys(SafeAllocator* allocator, void* file, unsigned int size, const short* keys, unsigned short count);
    bool BuildAlternateForKey(SafeAllocator* allocator, void* file, unsigned int size, short key);
    bool BuildAlternateForKeys(SafeAllocator* allocator, void* file, unsigned int size, const short* keys, short count);
    void Clear();
    void Reset();
};

int GetSerializedRecordKey(const void* record);

bool RelocateSerializedRecordPayload(ZoneState2754::Data* state, void* record);

typedef bool (*ZoneRecordMatchFunction)(ZoneSerializedRecord*, int, int, int);
bool MatchRecordFirstAttribute(ZoneSerializedRecord* record, int group, int first, int second);
bool MatchRecordSecondAttribute(ZoneSerializedRecord* record, int group, int first, int second);
bool MatchRecordBothAttributes(ZoneSerializedRecord* record, int group, int first, int second);
void SelectRecordAttributeMatcher(int first, int second, ZoneRecordMatchFunction* output);
