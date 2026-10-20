#include <globaldefs.h>
ARM
// Original: arm9/ov004:02167908; Looks up the selected object, requires halfword +4 equal to 0x11, and invokes its virtual method at vtable offset 0xe8; callers include placement routines.
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
struct VirtualObject {
    virtual int slot0() = 0;
    virtual int slot1() = 0;
    virtual int slot2() = 0;
    virtual int slot3() = 0;
    virtual int slot4() = 0;
    virtual int slot5() = 0;
    virtual int slot6() = 0;
    virtual int slot7() = 0;
    virtual int slot8() = 0;
    virtual int slot9() = 0;
    virtual int slot10() = 0;
    virtual int slot11() = 0;
    virtual int slot12() = 0;
    virtual int slot13() = 0;
    virtual int slot14() = 0;
    virtual int slot15() = 0;
    virtual int slot16() = 0;
    virtual int slot17() = 0;
    virtual int slot18() = 0;
    virtual int slot19() = 0;
    virtual int slot20() = 0;
    virtual int slot21() = 0;
    virtual int slot22() = 0;
    virtual int slot23() = 0;
    virtual int slot24() = 0;
    virtual int slot25() = 0;
    virtual int slot26() = 0;
    virtual int slot27() = 0;
    virtual int slot28() = 0;
    virtual int slot29() = 0;
    virtual int slot30() = 0;
    virtual int slot31() = 0;
    virtual int slot32() = 0;
    virtual int slot33() = 0;
    virtual int slot34() = 0;
    virtual int slot35() = 0;
    virtual int slot36() = 0;
    virtual int slot37() = 0;
    virtual int slot38() = 0;
    virtual int slot39() = 0;
    virtual int slot40() = 0;
    virtual int slot41() = 0;
    virtual int slot42() = 0;
    virtual int slot43() = 0;
    virtual int slot44() = 0;
    virtual int slot45() = 0;
    virtual int slot46() = 0;
    virtual int slot47() = 0;
    virtual int slot48() = 0;
    virtual int slot49() = 0;
    virtual int slot50() = 0;
    virtual int slot51() = 0;
    virtual int slot52() = 0;
    virtual int slot53() = 0;
    virtual int slot54() = 0;
    virtual int slot55() = 0;
    virtual int slot56() = 0;
    virtual int slot57() = 0;
    virtual int invoke() = 0;
};
extern "C" int MiniMedalMenu_GetPlacementState(void* self, unsigned short id) {
    void** head = (void**)Menu_GetDisplayRecordRegistry(self);
    VirtualObject* object = (VirtualObject*)MenuRecordList_LocateByKey(head, id);
    if (object == 0) goto fail;
    if (MenuRecord_GetType(object) != 0x11) goto fail;
    return object->invoke();
fail:
    return 0;
}
