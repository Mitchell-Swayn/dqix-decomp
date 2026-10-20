#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
struct Packed{unsigned a:6,b:6,c:6,d:6,e:2,f:1,g:1,h:1,pad:2,invalid:1;};struct Result{unsigned first,second;Packed bits;};struct Source{unsigned first,pad[4],second;Packed bits;};extern "C" void* Text_ClearNameDescriptor(void*);
// Original: arm9/ov023 @ 0x021ed804; symbol: Resource_BuildPackedRecordSnapshot.
extern "C" Result Text_BuildMonsterNameDescriptor(Result result,const Source* src){
Text_ClearNameDescriptor(&result);result.first=src->first;result.second=src->second;result.bits.a=src->bits.a;result.bits.b=src->bits.b;result.bits.c=src->bits.c;result.bits.d=src->bits.d;result.bits.e=src->bits.e;result.bits.f=src->bits.f;result.bits.g=src->bits.g;result.bits.h=src->bits.h;result.bits.invalid=0;return result;
}
