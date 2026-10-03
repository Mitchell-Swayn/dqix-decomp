#include "CountMenu.h"
#include "Memory/SafeAllocator.h"

// Only the observed virtual slots and fields are modeled here.
struct CountWidget {
    // Unidentified slots preserve the established UI virtual interface order.
#define RESERVED_SLOT(n) virtual void slot##n();
    RESERVED_SLOT(0) RESERVED_SLOT(1) RESERVED_SLOT(2) RESERVED_SLOT(3)
    RESERVED_SLOT(4) RESERVED_SLOT(5) RESERVED_SLOT(6) RESERVED_SLOT(7)
    RESERVED_SLOT(8) RESERVED_SLOT(9) RESERVED_SLOT(10) RESERVED_SLOT(11)
    RESERVED_SLOT(12) RESERVED_SLOT(13) RESERVED_SLOT(14) RESERVED_SLOT(15)
    RESERVED_SLOT(16) RESERVED_SLOT(17) RESERVED_SLOT(18) RESERVED_SLOT(19)
    RESERVED_SLOT(20) RESERVED_SLOT(21) RESERVED_SLOT(22) RESERVED_SLOT(23)
    RESERVED_SLOT(24) RESERVED_SLOT(25) RESERVED_SLOT(26) RESERVED_SLOT(27)
    RESERVED_SLOT(28) RESERVED_SLOT(29) RESERVED_SLOT(30) RESERVED_SLOT(31)
    RESERVED_SLOT(32) RESERVED_SLOT(33) RESERVED_SLOT(34) RESERVED_SLOT(35)
    RESERVED_SLOT(36) RESERVED_SLOT(37) RESERVED_SLOT(38) RESERVED_SLOT(39)
    RESERVED_SLOT(40) RESERVED_SLOT(41) RESERVED_SLOT(42) RESERVED_SLOT(43)
    RESERVED_SLOT(44) RESERVED_SLOT(45) RESERVED_SLOT(46) RESERVED_SLOT(47)
    RESERVED_SLOT(48) RESERVED_SLOT(49) RESERVED_SLOT(50) RESERVED_SLOT(51)
    RESERVED_SLOT(52) RESERVED_SLOT(53) RESERVED_SLOT(54) RESERVED_SLOT(55)
    virtual void setCount(int);
    RESERVED_SLOT(57)
    virtual int selection();
    virtual void* countList();
#undef RESERVED_SLOT
    unsigned char unknown04[8];
    unsigned char flags;
    unsigned char unknown0d[79];
    short firstPage;
    short pageCount;
};

extern "C" {
void func_ov023_021fbdcc(CountMenuEntry*, int);
int _s32_div_f(int, int);
void func_ov023_021f65d4(CountMenuContext*, int, int);
void func_ov023_021f6600(CountMenuContext*, int, int);
int func_ov023_021e1de8(void*, int, int, int);
void* func_ov011_021845f8(CountMenuContext*, int);
void func_ov004_02153b6c(CountMenuContext*, int, int, int, short*, short*);
void func_ov004_021545f0(CountCache*, unsigned char, short, short, unsigned char, unsigned char);
void func_ov023_021e1518(void*);
void func_ov023_021e1474(void*, int);
}

#pragma dont_inline on
extern "C" int func_ov004_021540a4(CountMenuContext* menu)
{
    short category, primary, secondary;
    func_ov004_02153978(menu, &category, &primary, &secondary);
    CountMenuEntry* entry = func_ov023_021f6880(func_ov011_021849c8(menu), 57);
    if (!entry) return 0;
    if (func_ov023_021f6f10(entry) != 18) return 0;
    void* list = ((CountWidget*)entry)->countList();
    if (!entry) return 0;
    int count = func_ov023_021e1de8(list, category, primary, secondary);
    short pages = (count + 15) / 16;
    if (!count) {
        func_ov023_021f65d4(menu, 10, 8);
        func_ov023_021f6600(menu, 3, 4);
        unsigned short id = 26;
        for (unsigned short i = 0; i < 16; ++id, ++i) {
            CountWidget* widget = (CountWidget*)func_ov023_021f6880(func_ov011_021849c8(menu), id);
            if (widget) widget->flags |= 8;
        }
        CountWidget* widget = (CountWidget*)func_ov023_021f6880(func_ov011_021849c8(menu), 58);
        if (widget) widget->flags &= ~8;
    } else {
        func_ov023_021f6600(menu, 10, 8);
        func_ov023_021f65d4(menu, 58, 8);
    }
    entry = func_ov023_021f6880(func_ov011_021849c8(menu), 44);
    if (!entry) return 0;
    if (func_ov023_021f6f10(entry) != 7) return 0;
    {
        ((CountWidget*)entry)->firstPage = 0;
        ((CountWidget*)entry)->pageCount = pages;
    }
    return 0;
}

extern "C" int func_ov004_02154210(CountMenuContext* menu)
{
    CountMenuEntry* entry = func_ov023_021f6880(func_ov011_021849c8(menu), 46);
    if (!entry) return 0;
    if (func_ov023_021f6f10(entry) != 16) return 0;
    func_ov023_021fbdcc(entry, -1);
    return 0;
}

extern "C" int func_ov004_02154250(CountMenuContext* menu)
{
    short total = data_ov004_021707c0->totalCount;
    short percentage = _s32_div_f(total * (short)100, data_ov004_021707c0->availableCount);
    if (!percentage && !total) percentage = 0;
    if (!percentage && total) percentage = 1;
    if (percentage > 100) percentage = 100;
    if (percentage < 0) percentage = 0;
    CountMenuEntries* entries = func_ov011_021849c8(menu);
    CountMenuEntry* entry = func_ov023_021f6880(entries, 19);
    if (!entry) return 0;
    ((CountWidget*)entry)->setCount(percentage);
    entry = func_ov023_021f6880(entries, 20);
    if (!entry) return 0;
    ((CountWidget*)entry)->setCount(total);
    func_ov004_021536e0(menu, 20, 25);
    entry = func_ov023_021f6880(entries, 16);
    if (!entry) return 0;
    if (func_ov023_021f6f10(entry) != 6) return 0;
    func_ov023_021f809c(entry, menu);
    return 0;
}

extern "C" void func_ov004_0215434c() {}

extern "C" int func_ov004_02154350(CountMenuContext* menu)
{
    void* owner = func_ov011_021845f8(menu, 0);
    if (!owner) return 0;
    CountCache* cache = (CountCache*)((SafeAllocator*)((char*)owner + 4))->Allocate(126);
    data_ov004_021707c0 = cache;
    if (!cache) return 0;
    for (unsigned char i = 0; i < 20; ++i) {
        cache->records[i].primaryKey = -1;
        cache->records[i].secondaryKey = -1;
        cache->records[i].availableCount = 0;
        cache->records[i].totalCount = 0;
    }
    cache->availableCount = 0;
    cache->totalCount = 0;
    cache->state = 0;
    unsigned char index = 0;
    short total = 0, available = 0;
    for (signed char secondary = 0; secondary <= 11; ++secondary, ++index) {
        func_ov004_02153b6c(menu, -1, 0, secondary, &total, &available);
        func_ov004_021545f0(data_ov004_021707c0, index, 0, secondary,
                            (unsigned char)available, (unsigned char)total);
    }
    for (signed char primary = 1; primary <= 6; ++primary, ++index) {
        func_ov004_02153b6c(menu, -1, primary, -1, &total, &available);
        func_ov004_021545f0(data_ov004_021707c0, index, primary, -1,
                            (unsigned char)available, (unsigned char)total);
    }
    func_ov004_02153b6c(menu, -1, 7, -1, &total, &available);
    func_ov004_021545f0(data_ov004_021707c0, index, 7, -1,
                        (unsigned char)available, (unsigned char)total);
    // Initialization accumulates unsigned halfwords; display code interprets
    // these same stored totals as signed shorts through CountCache.
    struct CacheTotals {
        CountRecord records[20];
        unsigned short availableCount, totalCount;
    };
    CacheTotals* totals = (CacheTotals*)data_ov004_021707c0;
    for (unsigned char i = 0; i < 20; ++i) {
        CountRecord* record = &totals->records[i];
        totals->availableCount += record->availableCount;
        totals->totalCount += record->totalCount;
    }
    CountMenuEntry* left = func_ov023_021f6880(func_ov011_021849c8(menu), 45);
    CountMenuEntry* right = func_ov023_021f6880(func_ov011_021849c8(menu), 57);
    if (left && right) {
        void* list = ((CountWidget*)right)->countList();
        if (list) {
            func_ov023_021e1518(list);
            int value = ((CountWidget*)left)->selection();
            func_ov023_021e1474(list, value);
        }
    }
    return 0;
}
