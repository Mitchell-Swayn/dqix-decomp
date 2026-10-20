#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];extern "C" unsigned short* Zone3D_GetMainInstance();extern "C" unsigned _ZNK8Object3D10GetField06Ev(void*);extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,int);
struct Field {unsigned short value:15;unsigned short flag:1;};
// Original: arm9/main @ 0x02034044; symbol: func_02034044; size: 0x58.
extern "C" void GameObject_StartMovementPause(char* p,unsigned short value){unsigned short key=*Zone3D_GetMainInstance();if(key==_ZNK8Object3D10GetField06Ev(p))SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,96,0);((Field*)(p+196))->value=value;}
