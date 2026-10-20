#include <globaldefs.h>
ARM
extern "C" int WM_SetIndCallback(unsigned);
extern "C" int WirelessCommand_InvokeFourArgumentRequestWithZeroMode(void*,unsigned,void*);
extern "C" void MBi_SetScanDwellTime(unsigned short);
extern "C" void MBi_OnInitializeDone(void);
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
struct CommState { unsigned char pad[0x508]; unsigned request; unsigned char pad1,started; };
struct StartContext { unsigned short value,pad; void *context; CommState *state; unsigned char *parent; };
#define S ((StartContext*)MBEnd_UnknownRoleZeroInitializedStorage)
// Original: arm9/ov027 @ 0x021DC96C; symbol: func_ov027_021dc96c; size: 0xD4.
// Resets common communication counters and starts or resumes the configured wireless session.
extern "C" int MBi_StartCommon(void)
{
    *(unsigned short*)((char*)S->state+0x528)=0;
    *(unsigned short*)((char*)S->state+0x52a)=0;
    *(unsigned short*)((char*)S->state+0x526)=0;
    *(unsigned short*)((char*)S->state+0x548)=0;
    MBi_SetScanDwellTime(10);
    if(!*(unsigned*)(S->parent+0x1320)) {
        int result;
        do { result=WirelessCommand_InvokeFourArgumentRequestWithZeroMode(S->context,S->state->request,(void*)(unsigned)S->value); }while(result==4);
        if(result!=2)return 8;
        WM_SetIndCallback(S->state->request);
        S->state->started=1;
        return 0;
    }
    WM_SetIndCallback(S->state->request);
    S->state->started=1;
    MBi_OnInitializeDone();
    return 0;
}
