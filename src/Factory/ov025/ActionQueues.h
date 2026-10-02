#ifndef OV025_ACTION_QUEUES_H
#define OV025_ACTION_QUEUES_H

// Layout established by the insertion, removal and processing routines.
// Gameplay meanings of the parameters and the two queues remain uncertain.
struct Ov25ActionQueues {
    unsigned short ids[16];                 // 000
    short parameters[16];                   // 020
    short auxiliary[16];                    // 040
    short serials[16];                      // 060
    unsigned short flags[16];               // 080
    unsigned char kinds[16];                // 0a0
    void* payloads[16];                      // 0b0
    void* secondaryPayloads[16];             // 0f0
    unsigned char secondaryKinds[16];       // 130
    unsigned char secondaryFlags[16];       // 140
    unsigned char count;                    // 150
    unsigned char secondaryCount;           // 151
    short nextSerial;                       // 152
    short secondarySerial;                  // 154
    unsigned short unknown156;
    void* activePayload;                    // 158
    short insertionIndex;                   // 15c
    unsigned short activeId;                // 15e
    short delay;                            // 160
    short defaultDelay;                     // 162
    void* context;                          // 164
    void* auxiliaryContext;                 // 168
    char name[64];                          // 16c
    unsigned short unknown1ac;
    unsigned short secondaryActiveId;       // 1ae
};

#endif
