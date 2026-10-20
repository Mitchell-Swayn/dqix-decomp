#include <globaldefs.h>
ARM
extern "C" char* _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZNK9GameState12GetTickCountEv(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};struct Vec {int x,y,z;};
struct Widget {virtual void Slot0();virtual void Slot1();virtual void Slot2();virtual void Slot3();virtual void Slot4();virtual void Slot5();virtual void Slot6();virtual void WritePosition(const Vec&);virtual Vec ReadPosition();virtual void Slot9();virtual void Slot10();virtual void Slot11();virtual void Slot12();virtual void Slot13();virtual void Slot14();virtual void Slot15();virtual void Slot16();virtual void Slot17();virtual void Slot18();virtual void Slot19();virtual void Slot20();virtual void Slot21();virtual void Slot22();virtual void Slot23();virtual void Slot24();virtual void Slot25();virtual void Slot26();virtual void Slot27();virtual void Slot28();virtual void Slot29();virtual void Slot30();virtual void Slot31();virtual void Slot32();virtual void Slot33();virtual void Slot34();virtual void Slot35();virtual void Slot36();virtual void Slot37();virtual void Slot38();virtual void Slot39();virtual void Slot40();virtual void Slot41();virtual void Slot42();virtual void Slot43();virtual void Slot44();virtual void Slot45();virtual void Slot46();virtual void Slot47();virtual void Slot48();virtual void ApplyColor(unsigned,unsigned,unsigned);};
// Original: arm9/ov023 @ 0x021F7784; symbol: Graphics_AdvanceWrappedWidgetPositionAndApplyColor; size: 0xe0.
// Advances wrapped widget coordinates from low tick halfword, applies optional color callback and returns state word1C.
extern "C" int Graphics_AdvanceWrappedWidgetPositionAndApplyColor(char* self){if(B(self,12)&128){unsigned short tick=_ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());Vec position=((Widget*)self)->ReadPosition();position.x-=tick<<11;position.y+=tick<<11;if(position.x<-0x100000)position.x+=0x100000;if(position.y>0x100000)position.y-=0x100000;((Widget*)self)->WritePosition(position);}if(B(self,12)&1)return W(self,28);if(P(self,72))((Widget*)self)->ApplyColor(B(self,76),B(self,77),B(self,78));return W(self,28);}
