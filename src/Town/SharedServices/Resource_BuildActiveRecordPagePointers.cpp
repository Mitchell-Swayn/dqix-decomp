#include <globaldefs.h>
ARM
struct Eight {short values[8];};struct Triple {int x,y,z;};
extern "C" char* Zone3D_GetMainInstance(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov003 @ 0x02170898; symbol: Resource_BuildActiveRecordPagePointers; size: 0xc8.
// Resource BuildActiveRecordPagePointers from listed field operations and calls.
extern "C" void Resource_BuildActiveRecordPagePointers(char* self){char* records=Zone3D_GetMainInstance()+0x840;int total=W(P(self,0x170),0x1b38);for(int i=0;i<30;++i)*(char**)(self+4*i+0xf4)=0;int used=0;for(int i=0;i<30;++i){char* record=records+232*i;if(U(record,16)>>2)*(char**)(self+4*used+++0xf4)=record;}int pages=(total-1)/8+1;B(self,4)=pages;if(B(self,0)>B(self,4))B(self,0)=B(self,4);if(B(self,0)==B(self,4)&&total%8){B(self,5)=total%8;return;}B(self,5)=8;}
