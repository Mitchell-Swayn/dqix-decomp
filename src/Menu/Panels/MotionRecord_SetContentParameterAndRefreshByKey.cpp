#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F63F8; symbol: MotionRecord_SetContentParameterAndRefreshByKey; size: 0x4c.
// Updates the selected record parameter and invokes its refresh callback.
// Partial ABI view: the first 54 virtual slots are outside this operation.
// The refresh callback occupies slot 54 (byte offset 0xd8).
struct MotionRecord {
 virtual void Method0();
 virtual void Method1();
 virtual void Method2();
 virtual void Method3();
 virtual void Method4();
 virtual void Method5();
 virtual void Method6();
 virtual void Method7();
 virtual void Method8();
 virtual void Method9();
 virtual void Method10();
 virtual void Method11();
 virtual void Method12();
 virtual void Method13();
 virtual void Method14();
 virtual void Method15();
 virtual void Method16();
 virtual void Method17();
 virtual void Method18();
 virtual void Method19();
 virtual void Method20();
 virtual void Method21();
 virtual void Method22();
 virtual void Method23();
 virtual void Method24();
 virtual void Method25();
 virtual void Method26();
 virtual void Method27();
 virtual void Method28();
 virtual void Method29();
 virtual void Method30();
 virtual void Method31();
 virtual void Method32();
 virtual void Method33();
 virtual void Method34();
 virtual void Method35();
 virtual void Method36();
 virtual void Method37();
 virtual void Method38();
 virtual void Method39();
 virtual void Method40();
 virtual void Method41();
 virtual void Method42();
 virtual void Method43();
 virtual void Method44();
 virtual void Method45();
 virtual void Method46();
 virtual void Method47();
 virtual void Method48();
 virtual void Method49();
 virtual void Method50();
 virtual void Method51();
 virtual void Method52();
 virtual void Method53();
 virtual void Refresh(int);
};
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" char* MenuRecordList_LocateByKey(void*, unsigned short);
extern "C" int MenuRecord_GetType(void*);
extern "C" void MotionRecord_SetContentParameterAndRefreshByKey(void* owner, unsigned short key, unsigned value, int refresh) {
 char* record = MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(owner), key);
 if (!record) return;
 if (MenuRecord_GetType(record) != 8) return;
 *(unsigned*)(record + 0x20) = value;
 ((MotionRecord*)record)->Refresh(refresh);
}
