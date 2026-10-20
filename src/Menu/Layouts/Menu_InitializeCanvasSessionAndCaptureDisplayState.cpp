#include <globaldefs.h>
struct State {
 char header[0x9c]; unsigned field9c,fielda0; int fielda4; unsigned fielda8,fieldac,fieldb0,fieldb4;
 char memberb8[0x54]; unsigned field10c; int field110; unsigned field114;
 char member118[0x74]; int field18c; unsigned field190; char member194[0x10];
 unsigned char field1a4,field1a5; char pad1a6[2]; unsigned field1a8,field1ac;
 unsigned short field1b0,field1b2; unsigned field1b4,field1b8;
 unsigned short field1bc,field1be,field1c0,field1c2,field1c4,field1c6;
 unsigned field1c8; unsigned char field1cc,field1cd; char pad1ce[2]; unsigned field1d0,field1d4,field1d8,field1dc;
};
extern "C" void Menu_InitializeArenaNode(State*);
extern "C" void* memset(void*,int,unsigned);
extern "C" void Resource_InitializeRecordHeaderAndThreeEntries(void*);
extern "C" void* GameResources_GetInstance();
extern "C" void GameResources_SetSecondaryFlags(void*,unsigned);
extern "C" void Graphics_CacheFourMainBackgroundControlsOnce(void*);
extern "C" void Graphics_SnapshotSubBackgroundControlRegistersOnce(void*);
// Original: arm9/ov011 @ 0x0218438C; symbol: func_ov011_0218438c; size: 0x118.
extern "C" void Menu_InitializeCanvasSessionAndCaptureDisplayState(State* self) {
 Menu_InitializeArenaNode(self);
 self->fielda8=0; self->fieldac=0; self->field9c=0; self->fielda0=0; self->fielda4=-1;
 self->fieldb0=0; self->fieldb4=0;
 memset(self->memberb8,0,sizeof(self->memberb8));
 self->field110=-1; self->field10c=0; self->field114=0;
 Resource_InitializeRecordHeaderAndThreeEntries(self->member118);
 self->field18c=-1;
 GameResources_SetSecondaryFlags(GameResources_GetInstance(),0xc0);
 self->field190=(*(volatile unsigned short*)0x04000304 & 0x8000)>>15;
 self->field1a4=0; self->field1a5=0;
 Graphics_CacheFourMainBackgroundControlsOnce(self->member194);
 Graphics_SnapshotSubBackgroundControlRegistersOnce(self->member194);
 self->field1a8=(*(volatile unsigned*)0x04000000 & 0x1f00)>>8;
 self->field1ac=(*(volatile unsigned*)0x04001000 & 0x1f00)>>8;
 self->field1b0=0; self->field1b2=0; self->field1b4=0; self->field1b8=0;
 self->field1bc=0; self->field1be=0; self->field1c0=0; self->field1c2=0; self->field1c4=0; self->field1c6=0;
 self->field1c8=0; self->field1d0=0; self->field1d4=0; self->field1d8=0; self->field1dc=0;
 self->field1cc=0; self->field1cd=0;
}
