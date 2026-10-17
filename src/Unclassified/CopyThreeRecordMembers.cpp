// Exact original ARM fields, relocation targets and named allocator/Object3D contracts reviewed.
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Object3D.h>
#include <Memory/SignedAllocator.h>
#include <System/Interrupts.h>
ARM
#pragma force_active on
struct Entry{unsigned word;unsigned char a,b,c,pad;};struct Node{unsigned a,b;Node* next;};struct Nine{unsigned v[9];};struct Three{unsigned v[3];};struct Large{Nine a;Three b;unsigned c;};struct Bits{unsigned char a:1,b:1,c:1,d:1,rest:4;};struct Buffer{unsigned length;unsigned char* data;};extern "C"{int Object_FindSignedByteKeyInSixteenEntries(void*,int);int FindSignedByteValueInSixteenSlots(void*,int);void* GameState_GetObjectWithFlag100(GameState*,int);char* ReadWordFieldAtOffset150(void*);int TestFourMappedValuesAgainstTarget(unsigned,void*);unsigned ToggleMaskedFlagsAtOffset34(void*,unsigned);char* FindFirstOfFourRowsWithColumnStateOne(void*,int);void SetGlobalValueExceptModesNineAndTen(unsigned);Object3D* GameState_FindIndexedObjectWithFlag1000(GameState*,int);extern char data_020fe9cc[],data_0210f3d8[];extern unsigned data_02112780[],data_021117ec[],data_02111808[],data_021015a0[];}void HandleCommandReceivedFromArm7();
// Original: arm9/main @ 0x0201AE8C; symbol: func_0201ae8c; size: 0x50.
extern "C" Large* CopyThreeRecordMembers(Large* out,const Large* in){out->a=in->a;out->b=in->b;out->c=in->c;return out;}
