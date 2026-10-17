#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" bool ReadAvailableMemberValueRelativeToProtagonist(int,int,int,int);
extern "C" int Object_TestNestedBitAtOffset55D(signed char);
extern "C" int data_020fdcb0[][8];
struct Cached{char pad[0x34];unsigned short current,maximum;unsigned pad38;};
// Original: arm9/ov002 @ 0x02159774; symbol: func_ov002_02159774; size: 0x18C.
extern "C" int Graphics_SelectObjectRatioColor(char* self,int index,int check,int blocked,unsigned char special) {
 char* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);
 if(!object)return 3;
 if(check){int available=0;if(*(short*)(self+0x1c26)==0xd1)available=1;
 if(!ReadAvailableMemberValueRelativeToProtagonist((unsigned char)index,blocked,special,available))return 3;}
 int* values=data_020fdcb0[*(short*)(object+4)];
 float current=(float)values[0];
 float maximum=(float)values[2];
 if((*(unsigned*)(self+0x247c)&1) || *(int*)(self+0x1bb8)==4) {
  if(Object_TestNestedBitAtOffset55D((signed char)index)) {
   current=(float)(int)*(unsigned short*)(*(char**)(object+0x130)+4);
   maximum=(float)(int)*(unsigned short*)(*(char**)(object+0x134)+0x30);
  } else {
   Cached* cached=(Cached*)(self+0x1ab0)+*(short*)(object+4);
   current=(float)(unsigned)cached->current;
   maximum=(float)(unsigned)cached->maximum;
  }
 }
 float ratio=0;
 if(current>0.0f && maximum>0.0f)ratio=current/maximum;
 int color=15;
 if(ratio<=0.0f)color=9;
 else if(ratio<=0.08f)color=11;
 else if(ratio<=0.25f)color=13;
 return color;
}
