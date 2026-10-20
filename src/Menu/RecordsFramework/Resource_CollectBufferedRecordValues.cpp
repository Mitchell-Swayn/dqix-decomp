#include <globaldefs.h>
ARM
extern "C" { unsigned TextContext_GetSharedInstance(); void Graphics_FinalizeSpriteResourceBuffers(void*); unsigned short Graphics_GetCellPaletteBank(void*,void*); void UnlinkNodeFromDoublyLinkedList(void*,void*); void MenuRecordList_ReleaseTransferSlot(void*,int,unsigned); void* Menu_GetSpriteCellByIndexOrNull(void*,unsigned short); }
// Original: arm9/ov023 @ 0x021FA7D4; symbol: func_ov023_021fa7d4; size: 0x80.
extern "C" void Resource_CollectBufferedRecordValues(unsigned char* object,void* destination) {
 UnlinkNodeFromDoublyLinkedList(destination,object+0x78);
 for(unsigned i=0;i<*(unsigned short*)(object+0x72);++i) {
  void* record=Menu_GetSpriteCellByIndexOrNull(object+0x24,(unsigned short)i);
  if(record) {
   unsigned value=Graphics_GetCellPaletteBank(object+0x24,record);
   MenuRecordList_ReleaseTransferSlot(destination,object[0x74],value);
  }
 }
 Graphics_FinalizeSpriteResourceBuffers(object+0x24);
 unsigned char* global=(unsigned char*)TextContext_GetSharedInstance();
 *(int*)(global+0x2d8)=0;
 global[0x2e6]=1;
}
