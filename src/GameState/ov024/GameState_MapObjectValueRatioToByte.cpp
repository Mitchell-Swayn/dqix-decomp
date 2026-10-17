#include <globaldefs.h>
ARM
struct Threshold { float value; unsigned pad; };
extern "C" { unsigned _fdiv(unsigned,unsigned); int _fflt(int); unsigned _ffltu(unsigned); void* _ZN9GameState11GetInstanceEv(); unsigned char* GameState_GetObjectWithFlag100(void*,int); extern Threshold data_ov024_021fe970[]; extern unsigned char data_ov024_021fe974[]; }
// Original: arm9/ov024 @ 0x021EB344; symbol: func_ov024_021eb344; size: 0x9C.
extern "C" int GameState_MapObjectValueRatioToByte(void* unused,int id,int value) {
 unsigned char* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),id);
 if(!object) return 0;
 if(value<=0) return 0;
 id=*(volatile unsigned short*)(*(unsigned char**)(object+0x138)+4);
 float ratio=(float)value/(float)(unsigned)id;
 for(int i=0;i<9;++i) if(ratio>=data_ov024_021fe970[i].value) return data_ov024_021fe974[i*8];
 return 0;
}
