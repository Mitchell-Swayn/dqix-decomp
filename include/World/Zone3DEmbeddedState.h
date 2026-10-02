#pragma once

class SafeAllocator;

// Partial embedded types. Names retain offsets until their gameplay purposes
// are established. Only fields touched by recovered routines are identified.

struct ZoneState0840
{
    struct Entry
    {
        char unknown_0[12];
        struct Flags
        {
            unsigned int low : 4;
            unsigned int kind : 4;
            unsigned int unknown8 : 7;
            unsigned int unknown15 : 4;
            unsigned int unknown19 : 5;
            unsigned int state : 6;
            unsigned int unknown30 : 1;
            unsigned int unknown31 : 1;
        } flags;
        struct Value
        {
            unsigned int low : 2;
            unsigned int value : 30;
        } value;
        char unknown_14[0xe8 - 0x14];
    } entries[30];
    char unknown_1b30[4];
    int unknown_1b34, unknown_1b38, unknown_1b3c;
    unsigned char unknown_1b40, unknown_1b41, unknown_1b42;
    char unknown_1b43;
    int unknown_1b44, unknown_1b48, unknown_1b4c, unknown_1b50, unknown_1b54;
    int unknown_1b58, unknown_1b5c;
    unsigned char unknown_1b60, unknown_1b61, unknown_1b62;
    char unknown_1b63;
    unsigned short unknown_1b64;
    char unknown_1b66[2];
    int unknown_1b68[3];
    int unknown_1b74;
    ZoneState0840() { Reset(); }
    ~ZoneState0840() { Finish(); }
    void Reset();
    void Finish();
    void ClearEntryStates();
    int CollectEntriesOfKind(int kind, Entry** output);
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
    struct CategoryBits
    {
        unsigned int category : 4;
        unsigned int subtype : 5;
        unsigned int unknown : 23;
    } category;
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

bool MatchRecordCategory(ZoneSerializedRecord*, int, int, int);
bool MatchRecordSubtype(ZoneSerializedRecord*, int, int, int);
bool MatchRecordCategoryRange(ZoneSerializedRecord*, int, int, int);
bool MatchRecordCategoryAndSubtype(ZoneSerializedRecord*, int, int, int);
void SelectRecordCategoryMatcher(int alternate, unsigned int kind, int first, int second,
    signed char* minimum, signed char* maximum, signed char* subtype, ZoneRecordMatchFunction* output);
