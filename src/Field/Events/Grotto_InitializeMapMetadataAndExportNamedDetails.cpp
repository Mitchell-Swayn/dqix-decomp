#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov017 @ 0x21d781c; symbol: data_ov017_021d781c.
// Source-defined character literal. Text: "%s". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "%s".
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" char GrottoInitializeMapMetadataAndExportNamedDetails_TextS[];extern "C" void VectorizedMemset(void*,int,unsigned),_ZN23DetailedTreasureMapData5ClearEv(void*);extern "C" unsigned short _Z24GetMain16BitTimerCounterv();extern "C" void srand(int);extern "C" void _ZN19TreasureMapMetadata24InitialiseAsNonLegacyMapEji(void*,unsigned,int),_ZN19TreasureMapMetadata25InitialiseAsLegacyBossMapEjj(void*,unsigned,unsigned);extern "C" int TreasureMap_LoadLanguageDataAndOffsets();extern "C" bool _Z29ExportDetailedTreasureMapDataPK19TreasureMapMetadataP23DetailedTreasureMapDatabPKh(const void*,void*,bool,const unsigned char*);extern "C" void GameState_FreeTreasureMapLanguageBuffersAndRestoreCache();extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original: arm9/ov017 @ 0x021a9a9c; symbol: Grotto_InitializeMapMetadataAndExportNamedDetails; size 0x128.
extern "C" void Grotto_InitializeMapMetadataAndExportNamedDetails(char* self,unsigned char kind,unsigned seed,int level,unsigned char name){B(self,0x26d)=kind;VectorizedMemset(self+10,0,28);_ZN23DetailedTreasureMapData5ClearEv(self+40);srand(_Z24GetMain16BitTimerCounterv());if(B(self,0x26d)==1){_ZN19TreasureMapMetadata24InitialiseAsNonLegacyMapEji(self+10,seed,level);B(self,0x26e)=B(self,0x21);H(self,0x270)=H(self,0x24);}else if(B(self,0x26d)==2){_ZN19TreasureMapMetadata25InitialiseAsLegacyBossMapEjj(self+10,seed,(unsigned char)level);B(self,0x26e)=B(self,0x21);H(self,0x270)=B(self,0x22);}else{_ZN19TreasureMapMetadata24InitialiseAsNonLegacyMapEji(self+10,seed,level);B(self,0x26e)=B(self,0x21);H(self,0x270)=H(self,0x24);}if(name)B(self,0x1f)=name;TreasureMap_LoadLanguageDataAndOffsets();_Z29ExportDetailedTreasureMapDataPK19TreasureMapMetadataP23DetailedTreasureMapDatabPKh(self+10,self+40,false,0);GameState_FreeTreasureMapLanguageBuffersAndRestoreCache();if(B(self,0x26d)==1)strcpy(self+0x1ec,self+0xd7);else if(B(self,0x26d)==2)strcpy(self+0x1ec,self+0x16c);sprintf(self+0x22c,GrottoInitializeMapMetadataAndExportNamedDetails_TextS,self+0x1ec);}
