#include "recomp/input_manager.h"

#include <rex/cvar.h>
#include <rex/logging.h>
#include <rex/ppc.h>

#include "core/memory_utils.h"

REXCVAR_DEFINE_BOOL(enable_mnk_input, false, "Hydra/Gameplay", "Enables mouse and keyboard input")
    .lifecycle(rex::cvar::Lifecycle::kHotReload);

namespace
{

REX_IMPORT(__imp__InputBufferInput, Guest_InputBufferInput, void(u32, u32));

void InputBufferInput(const BufferedInput& tInput, int bForce)
{
    auto* memory = REX_KERNEL_MEMORY();
    if (!memory)
        return;
    auto* base = memory->virtual_membase();

    rex::CallFrame frame(*rex::runtime::ThreadState::Get()->context());
    rex::ppc::stack_guard guard(frame.ctx);
    u32 tInputPtr = rex::ppc::stack_push(frame.ctx, base, &tInput, sizeof(tInput));

    Guest_InputBufferInput(tInputPtr, bForce);
}

}

InputManager::InputManager() :
    m_currentInput(std::make_unique<InputQueue>()),
    m_pendingInput(std::make_unique<InputQueue>())
{
}

void InputManager::Initialize(rex::ui::Window* window)
{
    window->AddInputListener(this, 32);
    window->AddListener(this);
    REXLOG_INFO("Input initialized");
}

void InputManager::OnGuestInputUpdate()
{
    {
        std::unique_lock<std::mutex> lock(m_inputMutex);
        std::swap(m_currentInput, m_pendingInput);
    }

    InputQueue& currentInput = *m_currentInput;
    while (!currentInput.empty())
    {
        InputBufferInput(currentInput.front(), 0);
        currentInput.pop_front();
    }
}

void InputManager::OnMouseDown(rex::ui::MouseEvent& e)
{
    if (!REXCVAR_GET(enable_mnk_input))
        return;

    BufferedInput tInput = {};

    switch (e.button())
    {
        case rex::ui::MouseEvent::Button::kLeft:
            tInput.eInputMsg = INPUTMSG_LEFTMOUSEDOWN;
            tInput.tBufMouseData.eMouseButton = LEFT_MOUSE_BUTTON;
            break;

        case rex::ui::MouseEvent::Button::kRight:
            tInput.eInputMsg = INPUTMSG_RIGHTMOUSEDOWN;
            tInput.tBufMouseData.eMouseButton = RIGHT_MOUSE_BUTTON;
            break;

        case rex::ui::MouseEvent::Button::kMiddle:
            tInput.eInputMsg = INPUTMSG_MIDDLEMOUSEDOWN;
            tInput.tBufMouseData.eMouseButton = MIDDLE_MOUSE_BUTTON;
            break;

        case rex::ui::MouseEvent::Button::kX1:
            tInput.eInputMsg = INPUTMSG_KEYDOWN;
            tInput.tBufKeyData.wPlatformKey = KEY_MOUSE4;
            break;

        case rex::ui::MouseEvent::Button::kX2:
            tInput.eInputMsg = INPUTMSG_KEYDOWN;
            tInput.tBufKeyData.wPlatformKey = KEY_MOUSE5;
            break;

        default:
            return;
    }
    
    tInput.tBufMouseData.p.x = e.x();
    tInput.tBufMouseData.p.y = e.y();

    QueueInput(tInput);
}

void InputManager::OnMouseUp(rex::ui::MouseEvent& e)
{

}

void InputManager::OnMouseMove(rex::ui::MouseEvent& e)
{
    if (!REXCVAR_GET(enable_mnk_input))
        return;

    BufferedInput tInput = {};
    tInput.eInputMsg = INPUTMSG_MOUSEMOVE;
    tInput.tBufMouseData.eMouseButton = NO_MOUSE_BUTTON;
    tInput.tBufMouseData.p.x = e.x();
    tInput.tBufMouseData.p.y = e.y();

    QueueInput(tInput);
}

void InputManager::OnMouseWheel(rex::ui::MouseEvent& e)
{

}

void InputManager::QueueInput(const BufferedInput& input)
{
    std::unique_lock<std::mutex> lock(m_inputMutex);
    m_pendingInput->push_back(input);
}
