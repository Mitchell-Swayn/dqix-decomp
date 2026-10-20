#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov017 @ 0x21d739f; symbol: data_ov017_021d739f.
// Source-defined character literal. Text: "0". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "0".
// Observed span: 5 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Bits{unsigned char a:1,b:1,c:1,d:1,e:1,f:1,g:1,h:1;};struct Request{char name[16];unsigned char enabled;Bits flags;short kind;short ids[4];short alpha;short pad;int vectors[9];int scale[3];};extern "C" {char* strcpy(char*,const char*);void Memory_WriteThreeWordsAtOffset0(unsigned*,unsigned,unsigned,unsigned);void ResourceLoader_SpawnRegisteredPresentationOnce(void*,unsigned);void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);extern char FieldSpawnSharedPresentationEffectAtPosition_Text0[],Main_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov017 @0x0218d644; symbol:Graphics_QueueNamedTypeTwoRecordAtPosition; size:0x118.
// Builds named80-byte type-two request with field defaults, position and scale266 then queues record and dispatches stored index95.
extern "C" void Field_SpawnSharedPresentationEffectAtPosition(unsigned char* self,const unsigned* position,short kind){Request request;void* owner=P(self,0x4498);request.name[0]=0;request.enabled=1;request.flags.a=0;request.flags.b=0;request.flags.c=1;request.flags.d=0;request.flags.e=0;request.flags.f=0;request.flags.g=0;request.flags.h=0;request.ids[0]=-1;request.ids[1]=-1;request.ids[2]=-1;request.ids[3]=-1;request.alpha=-4096;request.vectors[0]=0;request.vectors[1]=0;request.vectors[2]=0;request.vectors[3]=0;request.vectors[4]=0;request.vectors[5]=0;request.vectors[6]=0;request.vectors[7]=0;request.vectors[8]=0;request.scale[0]=4096;request.scale[1]=4096;request.scale[2]=4096;request.flags.c=0;request.kind=kind;strcpy(request.name,FieldSpawnSharedPresentationEffectAtPosition_Text0);request.scale[0]=266;request.scale[1]=266;request.scale[2]=266;Memory_WriteThreeWordsAtOffset0((unsigned*)&request.vectors[3],position[0],position[1],position[2]);ResourceLoader_SpawnRegisteredPresentationOnce(owner,(unsigned)&request);SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,95,0);}
