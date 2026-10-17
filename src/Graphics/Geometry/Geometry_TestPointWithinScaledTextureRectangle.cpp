#include <globaldefs.h>
struct TextureRect {unsigned char unknown[0xa8];short width,height,left,top;};
extern "C" TextureRect* FindTwoHundredTwentyFourByteRecordByByteKey(void*,int);
// Original: arm9/main @ 0x02080D54; symbol: func_02080d54; size: 0x80.
extern "C" ARM int Geometry_TestPointWithinScaledTextureRectangle(void* owner,int index,int x,int y) {
 TextureRect* texture = FindTwoHundredTwentyFourByteRecordByByteKey(owner,index);
 if (!texture) return 0;
 short left = texture->left;
 short width = texture->width;
 short top = texture->top;
 short height = texture->height;
 short right = left + width;
 short bottom = top + height;
 if (x >= (short)(left*8) && x < (short)(right*8) && y >= (short)(top*8) && y < (short)(bottom*8)) return 1;
 return 0;
}
