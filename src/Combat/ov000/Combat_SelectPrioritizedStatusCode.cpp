#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned ReadWordFieldAtOffset1C();
unsigned char* GameState_FindIndexedObjectWithFlag400(void*,unsigned);
void* _Z11GetBTRandomv();
int _Z13NextRandomMaxP6Randomi(void*,int);
}
struct Stages {int a:3,b:3,c:3,d:3,e:3,f:3,g:3,h:3,i:3,j:3,k:2;};
struct PackedModes {unsigned short a:2,b:4,c:3,rest:7;};
// Original: arm9/ov000 @ 0x0217FF34; symbol: func_ov000_0217ff34; size: 0x460.
extern "C" int Combat_SelectPrioritizedStatusCode(void* unused,unsigned index,int* value) {
 int result=-1;
 void* state=_ZN9GameState11GetInstanceEv();
 ReadWordFieldAtOffset1C();
 unsigned char* object=GameState_FindIndexedObjectWithFlag400(state,index);
 if(!object)return result;
 unsigned flags;
 unsigned char* status;
 bool special=false;
 if(object)special=(*(unsigned*)(*(unsigned char**)(object+0x138)+0x18)&0x1000)!=0;
 status=*(unsigned char**)(object+0x138);
 flags=*(unsigned*)(status+0x14);
 unsigned mode=status[0x24];
 if(special){
   switch(_Z13NextRandomMaxP6Randomi(_Z11GetBTRandomv(),2)){case 0:result=4;break;case 1:result=5;break;}
   *value=*(short*)(*(unsigned char**)(object+0x138)+0x2e);
 }else if(mode){switch(mode){case 1:result=59;break;case 2:result=58;break;case 3:result=57;break;case 4:result=56;break;}}
 else if(flags&0x400){switch(((Stages*)(status+0x58))->a){case 2:result=31;break;case 1:result=32;break;case -1:result=33;break;case -2:result=34;break;}}
 else if(flags&0x800){switch(((Stages*)(status+0x58))->b){case 2:result=35;break;case 1:result=36;break;case -1:result=37;break;case -2:result=38;break;}}
 else if(flags&0x1000){switch(((Stages*)(status+0x58))->c){case 2:result=39;break;case 1:result=40;break;case -1:result=41;break;case -2:result=42;break;}}
 else if(flags&0x200)result=21;
 else if(flags&0x10000000)result=24;
 else if(flags&0x200000)result=25;
 else if(flags&0x10000){switch(((Stages*)(status+0x58))->g){case 2:result=48;break;case 1:result=49;break;case -1:result=50;break;case -2:result=51;break;}}
 else if((flags&0x2000000) && ((Stages*)(status+0x58))->j==2)result=55;
 else if(flags&0x4000){switch(((Stages*)(status+0x58))->e){case 2:result=44;break;case 1:result=45;break;}}
 else if(flags&0x8000){switch(((Stages*)(status+0x58))->f){case 2:result=46;break;case 1:result=47;break;}}
 else if(flags&8)result=6;
 else if(flags&16)result=7;
 else if(flags&32)result=8;
 else if(flags&0x80000){switch(((PackedModes*)(status+0x22))->b){case 2:result=9;break;case 5:result=10;break;case 3:result=11;break;case 4:result=12;break;case 7:result=14;break;case 8:result=15;break;}}
 else if(flags&0x40){switch(((PackedModes*)(status+0x22))->c){case 1:result=16;break;case 3:result=17;break;case 2:result=18;break;case 4:result=19;break;}}
 else if(flags&0x100)result=20;
 else if(flags&2){switch(((PackedModes*)(status+0x22))->a){case 2:result=22;break;case 1:result=23;break;}}
 else if((flags&0x2000) && ((Stages*)(status+0x58))->d==1)result=43;
 else if(flags&0x20000){switch(((Stages*)(status+0x58))->h){case 1:result=52;break;case 2:result=53;break;}}
 return result;
}
