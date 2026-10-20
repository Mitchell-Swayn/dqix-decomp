#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned _ZNK9GameState12GetTickCountEv(void*);
int fix32_Divide(int,int);
}
inline int MultiplyFixed(int a,int b) { return (int)(((long long)a*b+0x800)>>12); }
// Original: arm9/ov001 @ 0x02158080; symbol: func_ov001_02158080; size: 0x2A4.
extern "C" int Graphics_UpdateTimedWrappedAngles(char* command,char* object) {
 void* state=_ZN9GameState11GetInstanceEv();
 int tick=_ZNK9GameState12GetTickCountEv(state)<<12;
 int duration=*(int*)(command+0x1c);
 if(!duration) {
  *(int*)(object+0x64)=*(int*)(command+4);
  *(int*)(object+0x68)=*(int*)(command+8);
  *(int*)(object+0x6c)=*(int*)(command+12);
  if(*(int*)(object+0x70)) {
   *(int*)(object+0x88)=*(int*)(command+4);
   *(int*)(object+0x8c)=*(int*)(command+8);
   *(int*)(object+0x90)=*(int*)(command+12);
  }
  *(int*)(object+0x3c)=0;
  return 0;
 }
 if(*(int*)(object+0x3c)<=0) {
  int direction=*(int*)(command+0x20);
  int scale=duration<<13;
  if(direction==-1) {
   int a=*(int*)(command+4)-*(int*)(object+0x64);
   if(a>0x6488)a-=0x6488;else if(a<0)a+=0x6488;
   int b=*(int*)(object+0x64)-*(int*)(command+4);
   if(b>0x6488)b-=0x6488;else if(b<0)b+=0x6488;
   if(a<b)*(int*)(object+0xcc)=fix32_Divide(a,scale);
   else *(int*)(object+0xcc)=-fix32_Divide(b,scale);
  } else {
   int delta;
   if(direction==0)delta=*(int*)(object+0x64)-*(int*)(command+4);
   else delta=*(int*)(command+4)-*(int*)(object+0x64);
   if(delta>0x6488)delta-=0x6488;else if(delta<0)delta+=0x6488;
   *(int*)(object+0xcc)=fix32_Divide(delta,scale);
   if(!*(int*)(command+0x20))*(int*)(object+0xcc)=-*(int*)(object+0xcc);
  }
  *(int*)(object+0xd4)=fix32_Divide(*(int*)(command+8)-*(int*)(object+0x68),scale);
  *(int*)(object+0xd8)=fix32_Divide(*(int*)(command+12)-*(int*)(object+0x6c),scale);
 }
 *(int*)(object+0x64)+=MultiplyFixed(*(int*)(object+0xcc),tick);
 if(*(int*)(object+0x64)>0x6488)*(int*)(object+0x64)-=0x6488;
 else if(*(int*)(object+0x64)<0)*(int*)(object+0x64)+=0x6488;
 *(int*)(object+0x68)+=MultiplyFixed(*(int*)(object+0xd4),tick);
 *(int*)(object+0x6c)+=MultiplyFixed(*(int*)(object+0xd8),tick);
 *(int*)(object+0x3c)+=_ZNK9GameState12GetTickCountEv(state);
 if(*(int*)(object+0x3c)>=(*(int*)(command+0x1c)<<1)) {
  if(*(int*)(command+0x24)) {
   *(int*)(object+0x64)=*(int*)(command+4);
   *(int*)(object+0x68)=*(int*)(command+8);
   *(int*)(object+0x6c)=*(int*)(command+12);
   if(*(int*)(object+0x70)) {
    *(int*)(object+0x88)=*(int*)(command+4);
    *(int*)(object+0x8c)=*(int*)(command+8);
    *(int*)(object+0x90)=*(int*)(command+12);
   }
  }
  *(int*)(object+0x3c)=0;
  return 0;
 }
 return 1;
}
