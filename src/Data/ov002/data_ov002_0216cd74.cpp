// Menu state update handlers; func_ov002_02155960 supplies adjusted menu object in r0.
// ARM member-function dispatch ABI: adjustmentAndVirtual >> 1 is the
// this adjustment; bit 0 selects a virtual-table offset. All entries here
// are direct and have zero adjustment. Function return values are unused.
typedef void (*MenuCallback)(void *menu);
struct MenuDispatchEntry { MenuCallback target; int adjustmentAndVirtual; };
extern "C" {
extern void func_ov002_0215624c(void *menu);
extern void func_ov002_021622ec(void *menu);
extern void func_ov002_0216257c(void *menu);
extern void func_ov002_02162714(void *menu);
extern void func_ov002_02162964(void *menu);
extern void func_ov002_02162e50(void *menu);
extern void func_ov002_021631e8(void *menu);
extern void func_ov002_02163664(void *menu);
extern void func_ov002_02163bd0(void *menu);
extern void func_ov002_021642e4(void *menu);
extern void func_ov002_021644a8(void *menu);
extern void func_ov002_02164744(void *menu);
extern void func_ov002_02164748(void *menu);
extern void func_ov002_02164d14(void *menu);
extern void func_ov002_021650d4(void *menu);
extern void func_ov002_02165378(void *menu);
extern void func_ov002_02165764(void *menu);
extern void func_ov002_02165b44(void *menu);
extern void func_ov002_02166168(void *menu);
extern void func_ov002_021665b0(void *menu);
extern void func_ov002_02167998(void *menu);
extern void func_ov002_02167eb0(void *menu);
extern void func_ov002_0216806c(void *menu);
extern void func_ov002_02168d54(void *menu);
extern void func_ov002_02169520(void *menu);
extern void func_ov002_021696c0(void *menu);
extern void func_ov002_0216994c(void *menu);
extern void func_ov002_02169bb0(void *menu);
extern void func_ov002_02169efc(void *menu);
extern void func_ov002_0216a300(void *menu);
extern void func_ov002_0216acf0(void *menu);
extern void func_ov002_0216bd34(void *menu);
extern void func_ov002_0216c654(void *menu);
MenuDispatchEntry data_ov002_0216cd74[44] = {
    { func_ov002_0215624c, 0 },
    { func_ov002_021622ec, 0 },
    { func_ov002_0216257c, 0 },
    { func_ov002_02162714, 0 },
    { func_ov002_02162964, 0 },
    { func_ov002_02162e50, 0 },
    { func_ov002_021631e8, 0 },
    { func_ov002_02163664, 0 },
    { 0, 0 },
    { func_ov002_02163bd0, 0 },
    { func_ov002_021642e4, 0 },
    { func_ov002_021644a8, 0 },
    { func_ov002_02164744, 0 },
    { func_ov002_02164748, 0 },
    { func_ov002_02164d14, 0 },
    { func_ov002_021650d4, 0 },
    { func_ov002_02165378, 0 },
    { func_ov002_02165764, 0 },
    { 0, 0 },
    { 0, 0 },
    { func_ov002_02165b44, 0 },
    { func_ov002_02166168, 0 },
    { 0, 0 },
    { func_ov002_021665b0, 0 },
    { func_ov002_02167998, 0 },
    { func_ov002_02167eb0, 0 },
    { 0, 0 },
    { 0, 0 },
    { func_ov002_0216806c, 0 },
    { 0, 0 },
    { func_ov002_02168d54, 0 },
    { func_ov002_02169520, 0 },
    { 0, 0 },
    { func_ov002_021696c0, 0 },
    { func_ov002_0216994c, 0 },
    { func_ov002_02169bb0, 0 },
    { func_ov002_02169efc, 0 },
    { func_ov002_0216a300, 0 },
    { func_ov002_0216acf0, 0 },
    { func_ov002_0216bd34, 0 },
    { 0, 0 },
    { 0, 0 },
    { func_ov002_0216c654, 0 },
    { 0, 0 },
};
}
