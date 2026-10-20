// Original: arm9/main @ 0x020B1FF8; symbol: func_020b1ff8; size: 0x5C.
// Fills each row with increasing tile indices and a four-bit palette selector.
extern "C" void Tilemap_FillSequentialTilesWithPalette(unsigned short *dest,int width,int height,int stride,int tile,unsigned palette)
{
    int x;
    int y=0;
    unsigned short bits=(unsigned short)(palette<<12);
    if (height<=0) return;
    do {
        unsigned short *row=dest;
        x=0;
        if(width>0) do {
            *row++=(unsigned short)(tile++|bits);
        } while(++x<width);
        dest+=stride;
    } while(++y<height);
}
