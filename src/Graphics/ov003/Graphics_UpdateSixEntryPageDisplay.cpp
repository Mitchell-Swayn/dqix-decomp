#include <globaldefs.h>
ARM
extern "C" {
void ClearResolvedEntryByteC5Bit20(unsigned char*,int);
void Object_SetGroupNibbleAndTextureLowFourBits(char*,int,unsigned char);
void SetFlagOneForEachListedId(char*,int);
void Object_ApplyModeTwoToReferencedGroupParts(unsigned char*,int);
void Object_SetSelectedGroupBooleanFlag(char*,int,int);
unsigned short* FindSerializedPrimaryRecordByKey(void*,int);
unsigned ScaleResolvedHalfwordByObjectPercentage(char*,unsigned short*);
void SetKeyedRecordHalfwordField28(unsigned char*,int,int);
void Object_ApplyModeOneToSelectedPartGroup(unsigned char*,int);
void Graphics_ConfigureSelectedPartModes(char*,void*,int,int);
void SetKeyedRecordFlagMask40(unsigned char*,int);
void SetKeyedRecordFirstWord(char*,int,int);
void Object_SetSelectedPartInitialWord(char*,int,int);
void Object_ApplyModeTwoToSelectedPartGroup(unsigned char*,int);
int Object_CreateAndConfigureSelectedDisplayPart(char*,int);
}
// Original: arm9/ov003 @ 0x021767EC; symbol: func_ov003_021767ec; size: 0x200.
extern "C" void Graphics_UpdateSixEntryPageDisplay(char* self) {
 unsigned char* display=*(unsigned char**)(self+0x89c);
 short key=7,scaledKey=13,modeKey=19;
 ClearResolvedEntryByteC5Bit20(display,3);
 Object_SetGroupNibbleAndTextureLowFourBits((char*)display,3,0);
 SetFlagOneForEachListedId((char*)display,3);
 Object_ApplyModeTwoToReferencedGroupParts(display,3);
 Object_SetSelectedGroupBooleanFlag((char*)display,3,(*(unsigned short*)(self+0x1046)&0x400)!=0);
 unsigned char start=*(short*)(self+0x1014)*6;
 unsigned char end=start+6;
 for(unsigned char index=start;index<end;key++,scaledKey++,modeKey++,index++) {
  unsigned word=0;
  unsigned scaled=0;
  if(index<*(unsigned char*)(self+0x835)) {
   unsigned short* record=FindSerializedPrimaryRecordByKey(self+0x874,*(short*)(self+0x848+index*2));
   if(record) {
    word=*(unsigned*)(record+2);
    scaled=ScaleResolvedHalfwordByObjectPercentage(self,record);
    SetKeyedRecordHalfwordField28(display,key,13);
    Object_ApplyModeOneToSelectedPartGroup(display,key);
    Object_ApplyModeOneToSelectedPartGroup(display,scaledKey);
    Object_ApplyModeOneToSelectedPartGroup(display,modeKey);
    Graphics_ConfigureSelectedPartModes(self,record,scaledKey,modeKey);
   }
   SetKeyedRecordFlagMask40(display,key);
   SetKeyedRecordFirstWord((char*)display,key,word);
   Object_SetSelectedPartInitialWord((char*)display,scaledKey,scaled);
   Object_ApplyModeTwoToSelectedPartGroup(display,key);
  }
 }
 Object_ApplyModeOneToSelectedPartGroup(display,25);
 Object_ApplyModeOneToSelectedPartGroup(display,26);
 Object_ApplyModeOneToSelectedPartGroup(display,27);
 Object_SetSelectedPartInitialWord((char*)display,25,*(short*)(self+0x1014)+1);
 Object_SetSelectedPartInitialWord((char*)display,26,*(short*)(self+0x1016));
 Object_CreateAndConfigureSelectedDisplayPart((char*)display,3);
}
