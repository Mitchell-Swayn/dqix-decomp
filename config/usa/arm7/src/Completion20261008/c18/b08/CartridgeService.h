#ifndef ARM7_COMPLETION_CARTRIDGE_SERVICE_H
#define ARM7_COMPLETION_CARTRIDGE_SERVICE_H
/* Partial externally owned views; these declarations allocate no storage. */
typedef struct {unsigned char cartridgeType:1,removed:1,reserved:6;} CartridgeFlags;
typedef struct {unsigned short id;unsigned char unknown2[3];CartridgeFlags flags;} SharedCartridgeMetadata;
typedef struct {unsigned int unknown0;unsigned short unknown4,lockOwner;} CartridgeLockState;
typedef struct {unsigned char prefix[0x18];unsigned int bootWord;unsigned char unknown1c[12];unsigned int bootAcknowledged;} CartridgeServiceState;
typedef struct {int ownedByOtherProcessor,interruptState;} ProtectedBusState;
extern SharedCartridgeMetadata ARM7_SharedCartridgeMetadata;
extern CartridgeLockState ARM7_CartridgeLockState;
extern unsigned int ARM7_CartridgeBootWord;
extern CartridgeServiceState ARM7_CartridgeServiceState;
#endif
