#include <globaldefs.h>
#pragma optimization_level 4
#include <Memory/SafeAllocator.h>
struct Cache{unsigned words[7];};struct Entry{unsigned key;void*resource;};struct Flags{unsigned char value:3,rest:5;};
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;void*AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);void Memory_FreeThroughAllocatorUnion(AllocatorUnion*,SignedAllocatorHeader*);void CharacterTemplate_ClearScriptTable(Cache*);void LoadScriptFileOrGP2UnderLoaderLock(Cache*,SafeAllocator*,int);Entry*CharacterTemplate_FindEntryById(Cache*,short);void CharacterTemplate_ResetScriptTable(Cache*);void Text_EncodeGlyphIndices(void*,void*,int);}
// Original: arm9/main @ 0x020A93E0; symbol: func_020a93e0; size: 0x118.
extern "C" ARM void ReloadFlaggedRecordResourcesUsingTemporaryCache(unsigned char*p){unsigned char*q;int count;for(int i=0;i<13;i++){if(((Flags*)(p+i*0x23c+0x13f))->value){Cache cache;SafeAllocator arena;arena.ResetAllocatorPointer();arena.ResetAllocatorPointer();void*buffer=AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3,0x800);arena.CreateTypeA(buffer,0x800);CharacterTemplate_ClearScriptTable(&cache);LoadScriptFileOrGP2UnderLoaderLock(&cache,&arena,0);count=p[0x1d11]+p[0x1d0c];for(;i<count;i++){q=p+i*0x23c;unsigned flag=((Flags*)(q+0x13f))->value;if(flag){Entry*e=CharacterTemplate_FindEntryById(&cache,(short)(flag+7));Text_EncodeGlyphIndices(e->resource,q+0x140,1);}}SignedAllocatorHeader*allocation=arena.GetSignedAllocator();CharacterTemplate_ResetScriptTable(&cache);arena.Destroy();Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);break;}}}
