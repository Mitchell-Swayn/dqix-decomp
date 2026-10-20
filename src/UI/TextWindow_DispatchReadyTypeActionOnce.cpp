#include <globaldefs.h>
struct State {char pad[0x99c];int type;char pad9a0[0x1012];unsigned char ready,done;};
// Original data: arm9/main @ 0x2107820; symbol: data_02107820.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[],TextWindowFlushPendingResourceAction_UnknownRoleZeroInitializedStorage[];
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,void*);
// Original: arm9/main @ 0x020455F8; symbol: func_020455f8; size: 0x90.
extern "C" void TextWindow_DispatchReadyTypeActionOnce(State* p) {if(p->done==1||!p->ready)return;switch(p->type){case 0:SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,10,TextWindowFlushPendingResourceAction_UnknownRoleZeroInitializedStorage);break;case 1:SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,12,TextWindowFlushPendingResourceAction_UnknownRoleZeroInitializedStorage);break;case 2:SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,11,TextWindowFlushPendingResourceAction_UnknownRoleZeroInitializedStorage);break;}p->done=1;}
