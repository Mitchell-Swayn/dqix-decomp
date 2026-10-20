#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
struct Entry{virtual void V0(int);virtual void V1(int);virtual void V2(int);virtual void V3(int);virtual void V4(int);virtual void V5(int);virtual void V6(int);virtual void V7(int);virtual void V8(int);virtual void V9(int);virtual void V10(int);virtual void V11(int);virtual void V12(int);virtual void V13(int);virtual void V14(int);virtual void V15(int);virtual void V16(int);virtual void V17(int);virtual void V18(int);virtual void V19(int);virtual void V20(int);virtual void V21(int);virtual void V22(int);virtual void V23(int);virtual void V24(int);virtual void V25(int);virtual void V26(int);virtual void V27(int);virtual void V28(int);virtual void V29(int);virtual void V30(int);virtual void V31(int);};
extern "C" {void* _ZN9GameState11GetInstanceEv();void* Menu_GetDisplayRecordRegistry(void*);Entry* MenuRecordList_LocateByKey(void*,unsigned short);void Menu_SetGridCancelCallback(void*,unsigned short);void Menu_QueueScriptEntry(void*,unsigned);}typedef void(*Method)(void*,int);
// Original: arm9/ov004 @ 0x0216D720; symbol: Graphics_DisableTwoEntriesAndResetSelection; size: 0xd8.
extern "C" int TitleMenu_DisableQuickSaveChoicesAndEnterReload(void* self){_ZN9GameState11GetInstanceEv();Entry* entry=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),56);if(entry){entry->V17(0);entry->V31(0);((unsigned char*)entry)[12]|=80;}entry=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),57);if(entry){entry->V17(0);entry->V31(0);((unsigned char*)entry)[12]|=80;}entry=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),301);if(entry)Menu_SetGridCancelCallback(entry,0);Menu_QueueScriptEntry(self,701);return 0;}
