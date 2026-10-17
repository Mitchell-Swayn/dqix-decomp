#include <globaldefs.h>
ARM
extern "C" {
void __clear(void*,unsigned);
void* _ZN9GameState11GetInstanceEv();
void* _ZN9GameState20GetUnknownGameObjectEv(void*);
void* ReadSignedWordField32C(void*);
int Input_TestKeyMask(unsigned short*,unsigned short);
int ReadSelectedCoordinatePair(void*,int*,int*);
void* ReadGlobalValueAt020FB3F0();
bool TestFieldAtOffsetC4(char*);
void SetByteFieldAtOffset253ToOne(void*);
void Object_ClearTwoStateFieldsAndOptionallyResetAnimation(void*,int);
int ReadByteFieldAtOffset26C(void*);
unsigned ReadWordFieldAtOffset1C();
bool TestWordMaskNonzero(const unsigned*,unsigned);
bool IsFirstSignedWordZero(const int*);
int ReadIndirectByteOrMinusOne(char**);
bool Object_TestElement380Exceeds0(signed char*);
void SetByteFieldAtOffset154ToOne(void*);
void Object_ClearByteAtOffset154(void*);
void* GetGlobalStatePointer();
extern unsigned short data_02114e30[];
extern unsigned char data_02114e54[];
}
// Original: arm9/ov017 @ 0x0219A6B8; symbol: func_ov017_0219a6b8; size: 0x3A4.
extern "C" void Input_UpdateTouchRectangleDrag(unsigned char* self) {
 unsigned char *modes, *ys, *xs;
 void* linked;
 unsigned id;
 int i;
 void* state=_ZN9GameState11GetInstanceEv();
 ReadWordFieldAtOffset1C();
 id=*(unsigned short*)ReadGlobalValueAt020FB3F0();
 unsigned* flags=(unsigned*)GetGlobalStatePointer();
 if(!IsFirstSignedWordZero(*(int**)(self+0x36fc)))return;
 if(ReadIndirectByteOrMinusOne(*(char***)(self+0x36fc))==2)return;
 if(TestWordMaskNonzero(flags,0x800))return;
 void* object=_ZN9GameState20GetUnknownGameObjectEv(state);
 if(!object)return;
 linked=ReadSignedWordField32C(state);
 if(Object_TestElement380Exceeds0((signed char*)object))return;
 if(Input_TestKeyMask(data_02114e30,2) && !self[0x3658])return;
 if(TestFieldAtOffsetC4((char*)object))return;
 if(ReadByteFieldAtOffset26C(object))return;
 if(id==0x2774)return;
 int indices[1]={0};
 i=0;
 for(;i<1;i++) {
   ys=self+0x3646;xs=self+0x3634;modes=self+0x3658;
   int index=indices[i];
   int w=24,h=24;
   if(index==0){w=32;h=32;}
   if(data_02114e54[0x55]) {
     int x,y;
     ReadSelectedCoordinatePair(data_02114e54,&x,&y);
     if(xs[index]<x && x<xs[index]+w && ys[index]<y && y<ys[index]+h){
       Object_ClearTwoStateFieldsAndOptionallyResetAnimation(object,1);
       if(linked && id==0x2710)Object_ClearByteAtOffset154(linked);
       (self+index)[0x3658]=1;
     }
   } else if(data_02114e54[0x5f] && *(unsigned short*)(data_02114e54+0x24)) {
     int x,y;
     ReadSelectedCoordinatePair(data_02114e54,&x,&y);
     if(modes[index]==1){
       if(!(xs[index]<x && x<xs[index]+w && ys[index]<y && y<ys[index]+h))modes[index]=2;
     } else if(modes[index]==2){
       int nx=(x-12+xs[index])/2,ny=(y-12+ys[index])/2;
       if(nx<0)nx=0;
       if(256-w<nx)nx=256-w;
       if(ny<0)ny=0;
       if(192-h<ny)ny=192-h;
       xs[index]=nx;ys[index]=ny;
     }
   } else if(data_02114e54[0x54]) {
     if(modes[index]){
       SetByteFieldAtOffset253ToOne(object);
       if(linked && id==0x2710)SetByteFieldAtOffset154ToOne(linked);
     }
     if(modes[index]==1){
       self[0x42e4]=1;
       SetByteFieldAtOffset253ToOne(object);
       if(linked && id==0x2710)SetByteFieldAtOffset154ToOne(linked);
     }
     modes[index]=0;
   } else if(modes[index]){
     SetByteFieldAtOffset253ToOne(object);
     if(linked && id==0x2710)SetByteFieldAtOffset154ToOne(linked);
     modes[index]=0;
   }
   if((self+index)[0x3658])break;
 }
}
