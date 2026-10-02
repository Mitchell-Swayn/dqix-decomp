#include "CountMenu.h"

// The entry interface returns a three-word value through the ARM structure-return ABI.
struct EntryValue {
    unsigned int words[3];
};

// Only the invoked slots are understood here. The other declarations preserve
// the observed vtable indices; their names and signatures remain unresolved.
struct EntryValueInterface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void setValue(const EntryValue*);
    virtual EntryValue getValue();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void setState(int);
};

extern "C" {
int func_ov023_021f6378(CountMenuContext*, int);
signed char* func_ov023_021f63ac(CountMenuContext*, int, int);
void __clear(void*, unsigned int);
}

extern "C" void func_ov004_021536e0(CountMenuContext* menu, int destination, int source)
{
    CountMenuEntry* entry = func_ov023_021f6880(func_ov011_021849c8(menu), destination);
    if (!entry)
        return;
    signed char* flag = func_ov023_021f63ac(menu, 4, func_ov023_021f6378(menu, source));
    if (flag && *flag)
        return;
    CountMenuEntry* other = func_ov023_021f6880(func_ov011_021849c8(menu), source);
    if (!other)
        return;
    // Bind the returned temporary directly: a local copy adds a second buffer.
    const EntryValue& value = ((EntryValueInterface*)other)->getValue();
    ((EntryValueInterface*)entry)->setValue(&value);
}

extern "C" void func_ov004_02153778(EntryValueInterface*, const EntryValue*) {}

extern "C" EntryValue func_ov004_0215377c(EntryValueInterface*)
{
    EntryValue value;
    __clear(&value, sizeof(value));
    return value;
}

extern "C" void func_ov004_021537a8(CountMenuContext* menu, int id, int state)
{
    CountMenuEntry* entry = func_ov023_021f6880(func_ov011_021849c8(menu), id);
    if (entry)
        ((EntryValueInterface*)entry)->setState(state);
}

extern "C" void func_ov004_021537dc(EntryValueInterface*, int) {}
