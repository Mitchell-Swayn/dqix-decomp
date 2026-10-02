#pragma once

#include "World/Object3D.h"

class SafeAllocator;

// Partial embedded types. Names retain offsets until their gameplay purposes
// are established. Only fields touched by recovered routines are identified.

struct ZoneState0840
{
    struct Entry
    {
        char unknown_0[11];
        struct ByteFlags { unsigned char low : 7, high : 1; } byteFlags;
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
        unsigned char identifier[6];
        union Configuration1a
        {
            struct
            {
                unsigned short values[10];
                struct Flags14
                {
                    unsigned char low : 1, middle : 3, high : 4;
                } flags14;
                struct Flags15 { unsigned char low : 4, high : 4; } flags15;
                unsigned short unknown16, unknown18, unknown1a;
            };
            unsigned short words[14];
            void Reset();
        } configuration1a;
        union Block38 { int words[6]; } unknown_38;
        unsigned short unknown_50[14];
        // Assignment copies these 124 bytes as one aligned aggregate.
        union
        {
            struct
            {
                struct Parameters6c
                {
                    unsigned int unknown0 : 12, unknown12 : 4, unknown16 : 5;
                    unsigned int unknown21 : 4, unknown25 : 1, unknown26 : 1;
                    unsigned int unknown27 : 1, unknown28 : 1, unknown29 : 1;
                    unsigned int unknown30 : 1, unknown31 : 1;
                } parameters6c;
                struct Parameters70
                {
                    unsigned int unknown0 : 9, unknown9 : 10, unknown19 : 11;
                    unsigned int unknown30 : 1, unknown31 : 1;
                } parameters70;
                unsigned char unknown_74;
                char unknown_75[0xe8 - 0x75];
            };
            unsigned int parameterWords[31];
        };
        void Reset();
    } entries[30];
    char unknown_1b30[4];
    unsigned int unknown_1b34, unknown_1b38, unknown_1b3c;
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
    bool IsEntryStateValid(int state);
    bool IsValueInRangeC3b5(int value);
    bool IsValueAtHundredBoundary(int value);
    bool IsValueInRangeC545(int value);
    int GetMappedValueRemainder(int value);
    int GetKindThreshold(int kind);
    Entry* FindEntryByState(int state);
    Entry* FindEntryByIdentifier(const void* identifier);
    Entry* FindEntryByValue(int value);
    bool IsEntryIdentifierAvailable(const Entry* entry);
    bool RemoveEntry(Entry* entry);
    int PrepareEntryInsertionSlot();
    bool AddEntry(const Entry* entry, bool incrementValue, bool updateTier);
    void UpdateEntryCountTier();
    bool ContainsStoredValue(int value);
    int CountEntriesOfKind9();
    int CountEntriesOfKind10();
    unsigned char TakeFlag1b61();
    void CopyBytesAtOffset(int offset, const void* source, unsigned int size);
};
struct ZoneState2664
{
    int unknown_0;
    int unknown_4;
    Object3D object;
    unsigned char unknown_b4;
    unsigned char unknown_b5;
    unsigned char unknown_b6;
    signed char unknown_b7;
    signed char unknown_b8;
    char unknown_b9;
    unsigned short unknown_ba;
    signed char unknown_bc;
    char unknown_bd[3];
    void DrawAtGrottoEntrance();
    void UpdateEntranceObject();
    bool ShowEntranceObject();
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
