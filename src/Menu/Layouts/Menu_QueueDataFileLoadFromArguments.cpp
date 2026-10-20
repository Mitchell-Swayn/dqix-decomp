#include <globaldefs.h>
struct Argument { unsigned kind; const char* value; };
extern "C" void* Resource_GetSharedLoadState();
extern "C" int Menu_GetBackgroundLoadTicket(void*);
extern "C" void Menu_SetBackgroundLoadTicket(void*,unsigned);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" const char Menu_QueueDataFileLoadFromArguments_PathDataS[];
extern "C" int sprintf(char*,const char*,...);
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
// Original: arm9/ov011 @ 0x0218554C; symbol: func_ov011_0218554c; size: 0x80.
extern "C" unsigned Menu_QueueDataFileLoadFromArguments(Argument* self) {
 char filename[80];
 const char* value=self->kind==2 ? self->value : 0;
 if(!value) return 0;
 void* owner=Resource_GetSharedLoadState();
 if(Menu_GetBackgroundLoadTicket(owner)>=0) return 0;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 sprintf(filename,Menu_QueueDataFileLoadFromArguments_PathDataS,value);
 unsigned ticket=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,filename,0);
 Menu_SetBackgroundLoadTicket(owner,ticket);
 return 1;
}
