struct TiledPixelSurface {
    unsigned char prefix[8];
    unsigned char* pixels;
    unsigned char unknown[0x9c];
    short tileWidth, tileHeight;
};
// Original: arm9/main @ 0x0204E038; symbol: func_0204e038; size: 0x190.
// Writes nibble values to selected pixels in an 8x8-tiled four-bit surface.
extern "C" void ApplyBitMaskToTiledFourBitPixels(TiledPixelSurface* surface, const unsigned char* mask,
    short x, short y, short width, short height, unsigned char odd, unsigned char even)
{
    short tileX;
    int tileY;
    unsigned char bit;
    short row;
    short tileWidth;
    short tileHeight;
    short pixelY;
    short column;
    short rowOffset;
    int validY;
    int pixelX;
    int innerX;
    int validX;
    short index;
    unsigned char* pixels;
    if (!mask) return;
    bit = 0;
    row = 0;
    tileWidth = surface->tileWidth;
    tileHeight = surface->tileHeight;
    for (; row < height; row++) {
        pixelY = y + row;
        rowOffset = (pixelY & 7) << 2;
        tileY = (short)(pixelY >> 3);
        validY = tileY >= 0 && tileY < tileHeight;
        tileY = (short)tileY * surface->tileWidth;
        for (column = 0; column < width; column++) {
            if (validY && (*mask & (1 << bit))) {
                pixelX = (short)(x + column);
                innerX = pixelX & 7;
                tileX = pixelX >> 3;
                validX = tileX >= 0 && tileX < tileWidth;
                if (validX | validY) {
                    index = ((tileX + tileY) << 5) + rowOffset + (innerX >> 1);
                    pixels = surface->pixels;
                    if (pixelX & 1) {
                        pixels[index] &= 0x0f;
                        pixels[index] |= odd;
                    } else {
                        pixels[index] &= 0xf0;
                        pixels[index] |= even;
                    }
                }
            }
            bit++;
            if (bit >= 8) { bit = 0; mask++; }
        }
    }
}
