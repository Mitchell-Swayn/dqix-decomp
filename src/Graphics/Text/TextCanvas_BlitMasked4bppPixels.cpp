#pragma thumb off
struct TextCanvasPixels {
    unsigned char unknown0[8];
    unsigned char* pixels;
    unsigned char unknownC[0x9c];
    short tileWidth, tileHeight;
};
// Original: arm9/main @ 0x0204E1C8; symbol: func_0204e1c8; size: 0x218.
extern "C" void TextCanvas_BlitMasked4bppPixels(TextCanvasPixels* canvas, const unsigned char* source,
    short x, short y, short width, short height, unsigned char oddMask, unsigned char evenMask)
{
    unsigned char destinationByte;
    short tileY;
    int destinationX;
    short rowInTile;
    int tileRowIndex;
    int row;
    int col;
    if (source) {
        row = 0;
        short canvasWidth = canvas->tileWidth;
        short canvasHeight = canvas->tileHeight;
        while (row < height) {
            tileY = y >> 3;
            rowInTile = y & 7;
            short rowOffset = rowInTile << 2;
            tileRowIndex = tileY;
            bool rowValid = tileRowIndex >= 0 && tileRowIndex < canvasHeight;
            tileRowIndex = (short)tileRowIndex * canvas->tileWidth;
            for (destinationX = x, col = 0; col < width;
                 destinationX = (short)(destinationX + 1), col = (short)(col + 1)) {
                short tileX = destinationX >> 3;
                bool colValid = tileX >= 0 && tileX < canvasWidth;
                short tileIndex = tileRowIndex + tileX;
                // Preserve the original OR of the tile-coordinate bounds tests.
                bool valid = colValid | rowValid;
                short offset = tileIndex << 5;
                offset = (short)(offset + ((short)(destinationX & 7) >> 1));
                offset = (short)(offset + rowOffset);
                // The original reads the destination before testing either bound.
                destinationByte = canvas->pixels[offset];
                if (x & 1) {
                    if (col & 1) {
                        if (valid) {
                            unsigned char value = *source & oddMask;
                            if (value) {
                                destinationByte &= 0xf0;
                                value >>= 4;
                                destinationByte |= value;
                            }
                            canvas->pixels[offset] = destinationByte;
                        }
                        ++source;
                    } else if (valid) {
                        unsigned char value = *source & evenMask;
                        if (value) {
                            value <<= 4;
                            destinationByte &= 0x0f;
                            destinationByte |= value;
                        }
                        canvas->pixels[offset] = destinationByte;
                    }
                } else {
                    if (col & 1) {
                        if (valid) {
                            unsigned char value = *source & oddMask;
                            if (value) {
                                destinationByte &= 0x0f;
                                destinationByte |= value;
                            }
                            canvas->pixels[offset] = destinationByte;
                        }
                        ++source;
                    } else if (valid) {
                        unsigned char value = *source & evenMask;
                        if (value) {
                            destinationByte &= 0xf0;
                            destinationByte |= value;
                        }
                        canvas->pixels[offset] = destinationByte;
                    }
                }
            }
            ++y;
            row = (short)(row + 1);
        }
    }
}
