#include <globaldefs.h>
ARM
extern "C" {
void* memset(void*,int,unsigned);
void* __clear(void*,unsigned);
void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
int EquipmentMenu_FormatEquipmentActionMessage(unsigned char*,char*);
}
#define H(o) (*(unsigned short*)(panel+(o)))
#define B(o) (*(unsigned char*)(panel+(o)))
// Original: arm9/ov005 @ 0x021589F4; symbol: func_ov005_021589f4; size: 0x148.
// Chooses text-panel dimensions by message kind and sets optional per-line styles.
extern "C" void ConfigureSelectedRecordTextPanel(unsigned char* p){
 bool mode=true;char* panel=(char*)p+0xee4;unsigned kind=p[0x3dd1];
 if(kind>=8 && kind<=14){
  H(0xa0)=32;H(0xa2)=9;mode=false;H(0xa4)=0;H(0xa6)=15;
  H(0xac)=12;H(0xae)=20;B(0xb7)=12;H(0xa8)=12;H(0xaa)=11;
 }else{
  H(0xa0)=24;H(0xa2)=5;H(0xa4)=4;H(0xa6)=10;
  H(0xac)=10;H(0xae)=14;B(0xb7)=10;H(0xa8)=6;H(0xaa)=9;
 }
 B(0xb1)=0;B(0xb5)=0;B(0xb6)=0;
 memset(*(void**)(p+0xe10),0,0x960);
 int special=EquipmentMenu_FormatEquipmentActionMessage(p,*(char**)(p+0xe10));
 unsigned char styles[4];int styled=0;__clear(styles,4);
 if(special){styled=1;for(int i=1;i<4;i++)styles[i]=2;}
 Window_PushTextCanvas(panel,*(void**)(p+0xe10),0,mode,0,styled,(int)styles,0);
}
