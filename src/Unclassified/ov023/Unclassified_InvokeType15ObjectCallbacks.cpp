#include <globaldefs.h>
ARM

extern "C" void *func_ov011_021849c8(void *self);
extern "C" void *func_ov023_021f6880(void **head, unsigned short value);
extern "C" unsigned int OV023_ReadHalfwordField04(void *);

struct DispatchObject {
    virtual void Method0(void *);
    virtual void Method1(void *);
    virtual void Method2(void *);
    virtual void Method3(void *);
    virtual void Method4(void *);
    virtual void Method5(void *);
    virtual void Method6(void *);
    virtual void Method7(void *);
    virtual void Method8(void *);
    virtual void Method9(void *);
    virtual void Method10(void *);
    virtual void Method11(void *);
    virtual void Method12(void *);
    virtual void Method13(void *);
    virtual void Method14(void *);
    virtual void Method15(void *);
    virtual void Method16(void *);
    virtual void Method17(void *);
    virtual void Method18(void *);
    virtual void Method19(void *);
    virtual void Method20(void *);
    virtual void Method21(void *);
    virtual void Method22(void *);
    virtual void Method23(void *);
    virtual void Method24(void *);
    virtual void Method25(void *);
    virtual void Method26(void *);
    virtual void Method27(void *);
    virtual void Method28(void *);
    virtual void Method29(void *);
    virtual void Method30(void *);
    virtual void Method31(void *);
    virtual void Method32(void *);
    virtual void Method33(void *);
    virtual void Method34(void *);
    virtual void Method35(void *);
    virtual void Method36(void *);
    virtual void Method37(void *);
    virtual void Method38(void *);
    virtual void Method39(void *);
    virtual void Method40(void *);
    virtual void Method41(void *);
    virtual void Method42(void *);
    virtual void Method43(void *);
    virtual void Method44(void *);
    virtual void Method45(void *);
    virtual void Method46(void *);
    virtual void Method47(void *);
    virtual void Method48(void *);
    virtual void Method49(void *);
    virtual void Method50(void *);
    virtual void Method51(void *);
    virtual void Method52(void *);
    virtual void Method53(void *);
    virtual void Method54(void *);
    virtual void Method55(void *);
    virtual void Method56(void *);
};

// Original: arm9/ov023 @ 0x021F64A8; symbol: func_ov023_021f64a8; size: 0x5C.
extern "C" void Unclassified_InvokeType15ObjectCallbacks(void *self, unsigned short key, void *first, void *second) {
    void *state = func_ov011_021849c8(self);
    void *object = func_ov023_021f6880((void **)state, key);
    if (object == 0 || OV023_ReadHalfwordField04(object) != 0xf) {
        return;
    }
    ((DispatchObject *)object)->Method56(first);
    ((DispatchObject *)object)->Method54(second);
}
