#include "recomp/designer_menu.h"

#include <rex/hook.h>

#include "core/logging.h"
#include "game/input.h"

REX_IMPORT(__imp__UIConsoleDesignerMenu__InitializeForGame, Guest_UIConsoleDesignerMenu__InitializeForGame, void());
REX_IMPORT(__imp__UIConsoleDesignerMenu__ToggleOpen, Guest_UIConsoleDesignerMenu__ToggleOpen, void(u32));
REX_IMPORT(__imp__InputGetControllerState, Guest_InputGetControllerState, u32(u32));
REX_IMPORT(__imp__Console__ControllerUtils__IsButtonDown, Guest_Console__ControllerUtils__IsButtonDown, u32(u32, u32));

void DesignerMenu::InitializeForGame()
{
	Guest_UIConsoleDesignerMenu__InitializeForGame();
}

bool DesignerMenu::TryToggle(const BufferedInput& tInput)
{
    u32 ptControllerState = 0;

    switch (tInput.eInputMsg)
    {
        case INPUTMSG_CONTROLLERBUTTONDOWN:
        case INPUTMSG_CONTROLLERBUTTONREPEAT:
            ptControllerState = Guest_InputGetControllerState(0);
            if ((tInput.tBufControllerData.eInputButton == BUTTON_LEFT_STICK_BUTTON && Guest_Console__ControllerUtils__IsButtonDown(ptControllerState, BUTTON_RIGHT_STICK_BUTTON)) ||
                (tInput.tBufControllerData.eInputButton == BUTTON_RIGHT_STICK_BUTTON && Guest_Console__ControllerUtils__IsButtonDown(ptControllerState, BUTTON_LEFT_STICK_BUTTON)))
            {
                Guest_UIConsoleDesignerMenu__ToggleOpen(0);
                return true;
            }

            break;

        default:
            break;
    }

    return false;
}

void DesignerMenu::ProcessCompoundCommands(const char* uszCommands, int nControllerIndex)
{
    LOG_INFO("ProcessCompoundCommands(): [{}] {}", nControllerIndex, uszCommands);
}
