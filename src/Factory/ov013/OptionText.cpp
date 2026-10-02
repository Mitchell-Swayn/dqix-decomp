#include "MenuText.h"

extern "C" {
int func_02041c08(char*, int, int, int, int, int);
int func_02041ea4(char*, int);
int func_02041d9c(char*, int);
int func_02042058(char*, const char*);
int func_02041b70(char*, int, const char*);
const char* func_020e0434(Ov013StringCatalog*, short);
}

extern "C" void func_ov013_02185be0(Ov013Menu* menu, Ov013TextBuffer* buffer)
{
    if (menu->mode == 2)
        func_02041c08(buffer->text, menu->optionSelection, 9, 3, 6, 2);
    func_02041ea4(buffer->text, menu->optionSelection);
    for (int index = 0; index < 2; ++index) {
        char label[32] = {0};
        func_02041d9c(label, 12);
        func_02042058(label, func_020e0434(&menu->strings, (short)(index + 10)));
        func_02041b70(buffer->text, index, label);
        if (index < 1)
            func_02042058(buffer->text, func_020e0434(&menu->strings, 0));
    }
}
