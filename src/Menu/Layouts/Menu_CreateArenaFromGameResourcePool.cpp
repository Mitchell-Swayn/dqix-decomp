#include <globaldefs.h>
struct Arena { unsigned id; char allocator[0x1c]; };
struct Resources { char header[0x38]; char arena38[0x64]; char arena9c[0x28]; char arenac4[0x1c]; };
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" Resources* GameResources_GetInstance();
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetRootArena(void*);
extern "C" Arena* Menu_FindArenaNodeById(void*,unsigned);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void Menu_InitializeArenaNode(Arena*);
extern "C" unsigned _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeBEPvji(void*,void*,unsigned,int);
extern "C" void Menu_AppendArenaToForwardChain(void*,Arena*);
// Original: arm9/ov011 @ 0x02184DE4; symbol: func_ov011_02184de4; size: 0xEC.
extern "C" unsigned Menu_CreateArenaFromGameResourcePool(void* self) {
 Resources* resources=GameResources_GetInstance();
 void* list=Menu_GetRootArena(Resource_GetSharedLoadState());
 unsigned kind=Menu_ReadScriptArgumentAsInteger(self);
 void* allocator;
 unsigned id=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 if(Menu_FindArenaNodeById(list,id)) return 0;
 allocator=0;
 switch(kind) {
 case 0: allocator=resources->arena38; break;
 case 1: allocator=resources->arenac4; break;
 case 2: allocator=resources->arena9c; break;
 }
 if(!allocator) return 0;
 Arena* arena=(Arena*)_ZN13SafeAllocator8AllocateEj(allocator,sizeof(Arena));
 if(!arena) return 0;
 Menu_InitializeArenaNode(arena);
 arena->id=id;
 unsigned size=_ZNK13SafeAllocator24GetMaxPossibleAllocationEv(allocator);
 void* memory=_ZN13SafeAllocator8AllocateEj(allocator,size);
 if(!memory) return 0;
 _ZN13SafeAllocator11CreateTypeBEPvji(arena->allocator,memory,size,4);
 Menu_AppendArenaToForwardChain(list,arena);
 return 1;
}
