#include "Filesystem/BackgroundLoader.h"

#include "SelectionEntry.h"
using namespace Ov006Selection;

// The save helpers copy 0xb0 bytes. Only the subrecord offset passed here is
// understood; preserve the opaque fields until their own source is recovered.
struct SelectionSaveState {
    unsigned char prefix[0x68];
    unsigned char counterRecord[0x48];
};
extern "C" Record* func_02071d60(void*, int);
extern "C" void func_ov006_02153e54(Entry*);
extern "C" void func_ov006_02153e8c(void*, Entry*);
extern "C" void func_ov006_02154138(void*);
extern "C" int func_020ac2d4(int, Entry*, Entry*, int);
extern "C" int func_020ac104(void*, Entry*, int);
extern "C" int func_020ac0b4(unsigned int*);
extern "C" int func_020ac08c(unsigned int*);
extern "C" int func_020ac4c0(SelectionSaveState*);
extern "C" int func_020ac494(SelectionSaveState*);
extern "C" void func_020a0228(void*, int);
extern "C" unsigned char data_0211e33c[];

extern "C" void func_ov006_02153cbc(void* self, Entry first,
                                    Entry second, void* records) {
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    Entry entry;
    func_ov006_02153e54(&entry);
    if (func_020ac2d4(0, &first, &entry, 1)) {
        entry.flag0 = 1;
        entry.flag1 = 1;
        func_020ac104(data_0211e33c, &entry, 1);
        func_ov006_02153e8c(self, &entry);
        if (records) {
            Record* record = func_02071d60(records, first.id);
            if (record) record->flags |= 0x400000;
        }
    }
    if (second.id > 0) {
        func_ov006_02153e54(&entry);
        if (func_020ac2d4(0, &second, &entry, 1)) {
            entry.id = second.id;
            entry.flag1 = 1;
            func_020ac104(data_0211e33c, &entry, 1);
            func_ov006_02153e8c(self, &entry);
            if (records) {
                Record* record = func_02071d60(records, second.id);
                if (record) record->flags |= 0x400000;
            }
            func_ov006_02154138(self);
        }
    }
    unsigned int count = 0;
    if (func_020ac0b4(&count)) {
        ++count;
        if (count > 99999) count = 99999;
        func_020ac08c(&count);
        SelectionSaveState state;
        func_020ac4c0(&state);
        func_020a0228(state.counterRecord, 1);
        func_020ac494(&state);
    }
    BackgroundLoader::RemoveLockGlobal();
}
