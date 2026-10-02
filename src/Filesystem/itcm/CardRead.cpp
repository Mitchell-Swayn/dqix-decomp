// Read whole cartridge blocks, retaining only words inside the requested span.
extern "C" void func_01ff83a8(unsigned address, void* destination, int length)
{
    unsigned control = (*(volatile unsigned*)0x027ffe60 & ~0x07000000) | 0xa1000000;
    int offset = -(int)(address & 0x1ff);
    while (*(volatile unsigned*)0x040001a4 & 0x80000000) {}
    volatile unsigned char* card = (volatile unsigned char*)0x040001a1;
    *card = 0x80;
    address += offset;
    if (offset >= length) return;
    unsigned status;
    unsigned commandMiddle = address >> 8;
    do
    {
        card[7] = 0xb7;
        card[8] = address >> 24;
        card[9] = address >> 16;
        card[10] = commandMiddle;
        card[11] = address;
        card[12] = 0;
        card[13] = 0;
        card[14] = 0;
        *(volatile unsigned*)(card + 3) = control;
        do
        {
            status = *(volatile unsigned*)(card + 3);
            if (status & 0x00800000)
            {
                unsigned word = *(volatile unsigned*)0x04100010;
                if (offset >= 0 && offset < length)
                    *(unsigned*)((unsigned char*)destination + offset) = word;
                offset += 4;
            }
        } while (status & 0x80000000);
        commandMiddle += 2;
        address += 0x200;
    } while (offset < length);
}
