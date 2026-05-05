#include "mod.h"
#include "soh/SohGui/api/ui.h"

void SetupUI() {
    C_WidgetConfig chk = {0};
    chk.type = C_WIDGET_CVAR_CHECKBOX;
    chk.cvar = "gSkipIntro";
    chk.opts.checkbox.tooltip = "Skip the intro cutscene.";
    chk.opts.checkbox.default_val = true;
    C_AddSidebarEntry("My Mod", 1);
    C_AddWidget("My Mod", 1, "Draw Mod Hi", &chk);
}

MOD_INIT() {
    SetupUI();
}

MOD_EXIT() {
    C_RemoveSidebarEntry("My Mod");
}
