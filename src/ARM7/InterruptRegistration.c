/* Register IRQ callbacks; DMA/timer/VBlank use response records, other IRQs
 * update the direct dispatch table. Dispatchers retain their argument rules. */
typedef void (*Callback)(int);
typedef struct {
    Callback callback;
    unsigned int stayEnabledAfter;
    int userdata;
} InterruptResponse;

extern InterruptResponse ARM7_InterruptResponses[8];
extern InterruptResponse ARM7_VBlankResponse;
/* Only entries 0-24 are used here; the complete table extent remains external. */
extern Callback ARM7_InterruptHandlerTable[];

void ARM7_SetInterruptHandler(unsigned int mask, Callback callback)
{
    int index = 0;
    do {
        if (mask & 1) {
            InterruptResponse *response = 0;
            if (index >= 8 && index <= 11) {
                response = &ARM7_InterruptResponses[index - 8];
            } else if (index >= 3 && index <= 6) {
                response = &ARM7_InterruptResponses[index + 1];
            } else if (index == 0) {
                response = &ARM7_VBlankResponse;
            } else {
                ARM7_InterruptHandlerTable[index] = callback;
            }
            if (response) {
                response->userdata = 0;
                response->callback = callback;
                response->stayEnabledAfter = 1;
            }
        }
        mask >>= 1;
        index++;
    } while (index < 25);
}
