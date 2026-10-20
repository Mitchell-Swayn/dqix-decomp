// Original: arm9/main @ 0x020D0078; symbol: func_020d0078; size: 0x384.
#include <globaldefs.h>
struct CARDBackupSpec {
    unsigned totalSize, sectorSize, subsectorSize, pageSize, addressWidth;
    unsigned programPage, writePage, writePageTotal, eraseChip, eraseChipTotal;
    unsigned eraseSector, eraseSectorTotal, eraseSubsector, eraseSubsectorTotal, erasePage;
    unsigned char initialStatus, padding[3]; unsigned capabilities, reserved;
};
struct CARDCommand { unsigned result; int type; unsigned id, source, destination, length; CARDBackupSpec spec; };
struct CARDCommonPrefix { CARDCommand *command; };
// Original data: arm9/main @ 0x21118e0; symbol: data_021118e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1568 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" CARDCommonPrefix TryReadViaDMA_UnknownRoleZeroInitializedStorage;
extern "C" void VectorizedMemset(void *, int, unsigned);
// ARM9 main, original func_020d0078 at 0x020d0078; SDK CARDi_IdentifyBackupCore.
// Extended spec layout derived from DQIX accesses; base algorithm is community CARD_spi.c
// at pret/pokediamond b623abef1b4dfe204ca50aab42447ac00c134290.
// Total wait expressions preserve the original reuse of each initial sector wait.
extern "C" ARM void CARDi_IdentifyBackupCore(int type)
{
    CARDCommand *const p = TryReadViaDMA_UnknownRoleZeroInitializedStorage.command;
    VectorizedMemset(&p->spec, 0, sizeof(p->spec));
    p->type = type;
    p->spec.capabilities = 0x203f;
    if (type != 0) {
        const unsigned size = 1u << ((type >> 8) & 0xff);
        const int device = type & 0xff;
        const int vendor = (type >> 16) & 0xff;
        p->spec.totalSize = size;
        p->spec.initialStatus = 0xff;
        if (device == 1) {
            switch (size) {
            default: goto invalidType;
            case 0x200:
                p->spec.pageSize = 0x10; p->spec.addressWidth = 1;
                p->spec.programPage = 5; p->spec.initialStatus = 0xf0; break;
            case 0x2000:
                p->spec.pageSize = 0x20; p->spec.addressWidth = 2;
                p->spec.programPage = 5; p->spec.initialStatus = 0; break;
            case 0x10000:
                p->spec.pageSize = 0x80; p->spec.addressWidth = 2;
                p->spec.programPage = 10; p->spec.initialStatus = 0; break;
            case 0x20000:
                p->spec.pageSize = 0x100; p->spec.addressWidth = 3;
                p->spec.programPage = 5; p->spec.initialStatus = 0; break;
            }
            p->spec.sectorSize = p->spec.pageSize;
            p->spec.capabilities |= 0x40; p->spec.capabilities |= 0x4300;
        } else if (device == 2) {
            switch (size) {
            default: goto invalidType;
            case 0x40000: case 0x80000: case 0x100000:
                p->spec.writePage = 25; p->spec.writePageTotal = 300;
                p->spec.erasePage = 300; p->spec.eraseSector = 5000;
                p->spec.capabilities |= 0x480; break;
            case 0x200000:
                p->spec.writePage = 23; p->spec.writePageTotal = 300;
                p->spec.eraseSector = 500; p->spec.eraseSectorTotal = 5000;
                p->spec.eraseChip = 10000; p->spec.eraseChipTotal = 60000;
                p->spec.initialStatus = 0; p->spec.capabilities |= 0x80; p->spec.capabilities |= 0x5400; break;
            case 0x400000:
                p->spec.eraseSectorTotal = (p->spec.eraseSector = 600) + 2400;
                p->spec.eraseSubsector = 70; p->spec.eraseSubsectorTotal = 150;
                p->spec.eraseChip = 23000; p->spec.eraseChipTotal = 800000;
                p->spec.initialStatus = 0; p->spec.subsectorSize = 4096;
                p->spec.capabilities |= 0xd000; break;
            case 0x800000:
                if (vendor == 0) {
                    p->spec.eraseSectorTotal = (p->spec.eraseSector = 1000) + 2000;
                    p->spec.eraseChip = 68000; p->spec.eraseChipTotal = 160000;
                    p->spec.initialStatus = 0; p->spec.capabilities |= 0x5000;
                } else if (vendor == 1) {
                    p->spec.eraseSectorTotal = (p->spec.eraseSector = 1000) + 2000;
                    p->spec.eraseChip = 68000; p->spec.eraseChipTotal = 160000;
                    p->spec.initialStatus = 0x84; p->spec.capabilities |= 0x5000;
                }
                break;
            }
            p->spec.sectorSize = 0x10000; p->spec.pageSize = 0x100;
            p->spec.addressWidth = 3; p->spec.programPage = 5;
            p->spec.capabilities |= 0xb40;
        } else if (device == 3) {
            switch (size) {
            default: goto invalidType;
            case 0x2000: case 0x8000: break;
            }
            p->spec.pageSize = size; p->spec.sectorSize = size;
            p->spec.addressWidth = 2; p->spec.initialStatus = 0;
            p->spec.capabilities |= 0x40; p->spec.capabilities |= 0x4300;
        } else {
invalidType:
            p->type = 0; p->spec.totalSize = 0;
            TryReadViaDMA_UnknownRoleZeroInitializedStorage.command->result = 3;
            return;
        }
    }
}
