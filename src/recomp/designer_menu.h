#pragma once

struct BufferedInput;

namespace DesignerMenu
{

void InitializeForGame();

bool TryToggle(const BufferedInput& tInput);

void ProcessCompoundCommands(const char* uszCommands, int nControllerIndex);

}
