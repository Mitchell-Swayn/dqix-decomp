#include <globaldefs.h>
#include <System/LoadToVRAM.h>
struct SpriteUploadState { char pad[0x50]; unsigned mode; char pad54[10]; unsigned char subEngine; };
// Original: arm9/main @ 0x02076994; symbol: Sprite_UploadImageAsObjTiles; size: 0xf8.
extern "C" ARM void Sprite_UploadImageAsObjTiles(SpriteUploadState* self,const unsigned char* source,unsigned destination,unsigned width,unsigned height) {
int rows=height; unsigned tileColumns=width>>3;
unsigned bytesPerRow=4; unsigned tileBytes=32; if(self->mode==1) {bytesPerRow=8;tileBytes=64;}
unsigned sourceStride=tileColumns*bytesPerRow;

unsigned sourceTileRowStride=tileColumns*tileBytes;
unsigned sourceBase=0;
for(unsigned tileRow=0;tileRow<((unsigned)rows>>3);++tileRow) {
unsigned sourceColumn=sourceBase;
for(unsigned tileColumn=0;tileColumn<tileColumns;++tileColumn) {
unsigned offset=sourceColumn;
for(unsigned row=0;row<8;++row) {
if(!self->subEngine)LoadToMainObjVRAM(source+offset,destination,bytesPerRow); else LoadToSubObjVRAM(source+offset,destination,bytesPerRow);
destination+=bytesPerRow; offset+=sourceStride;
}
sourceColumn+=bytesPerRow;
}
sourceBase+=sourceTileRowStride;
}
}
