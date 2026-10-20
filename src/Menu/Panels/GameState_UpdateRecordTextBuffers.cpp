#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" int GameState_GetProgressChapter(void*);
extern "C" void *Network_GetConnectionManager();
extern "C" unsigned int MessageTextTable_FindTextById(void*,int);
extern "C" void* memset(void*,int,unsigned int);
extern "C" void* memcpy(void*,const void*,unsigned int);
extern "C" unsigned int strlen(const char*);
struct Flags { unsigned pad:29; unsigned a:1; unsigned b:1; unsigned c:1; };
struct One { unsigned char a:1; unsigned char b:7; };
// Original: arm9/ov023 @ 0x021E66AC; symbol: func_ov023_021e66ac; size: 0x148.
extern "C" void GameState_UpdateRecordTextBuffers(char* p) {
 char* gs=(char*)_ZN9GameState11GetInstanceEv();
 Flags* flags=(Flags*)(gs+0x569c);
 char* bits=gs+0x569c;
 if (!flags->a) {
  memset(p+0x1400,0,0x40);
  const char* s=(const char*)MessageTextTable_FindTextById(p+0x133c,0x6d);
  memcpy(p+0x1400,s,7);
 } else if (flags->b) {
  Network_GetConnectionManager();
  char* hero=(char*)_ZN9GameState14GetProtagonistEv(gs);
  int index=*(int*)(*(char**)(hero+0x150)+0x950);
  if(GameState_GetProgressChapter(gs)==1) index=13;
  int key=0x50dc;
  if(((One*)(*(char**)(hero+0x150)+0x49c))->a==1) key+=0x32;
  const char* s=(const char*)MessageTextTable_FindTextById(p+0x133c,(short)(key+index));
  memset(p+0x1400,0,0x40);
  memcpy(p+0x1400,s,strlen(s));
 }
 if((int)(*(unsigned*)(bits+4)<<13)>>22 == 300) {
  memset(p+0x1440,0,0x40);
  const char* s=(const char*)MessageTextTable_FindTextById(p+0x133c,0x6d);
  memcpy(p+0x1440,s,strlen(s));
 }
}
