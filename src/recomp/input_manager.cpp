#include "recomp/input_manager.h"

#include <rex/logging.h>
#include <rex/ppc.h>

#include "core/memory_utils.h"
#include "game/input.h"

namespace
{

REX_IMPORT(__imp__InputBufferInput, Guest_InputBufferInput, void(u32, u32));

void PostBufferedInput(const BufferedInput& tInput)
{
    auto* memory = REX_KERNEL_MEMORY();
    if (!memory)
        return;
    auto* base = memory->virtual_membase();

    rex::CallFrame frame(*rex::runtime::ThreadState::Get()->context());
    rex::ppc::stack_guard guard(frame.ctx);
    u32 tInputPtr = rex::ppc::stack_push(frame.ctx, base, &tInput, sizeof(tInput));

    Guest_InputBufferInput(tInputPtr, 0);
}

}

InputManager::InputManager()
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
    /* early experimental stuff
    if (m_mouseMoved)
    {
        f32 x = m_mouseX;
        f32 y = m_mouseY;
        m_mouseMoved = false;

        BufferedInput tInput = {};
        tInput.eInputMsg = INPUTMSG_MOUSEMOVE;
        tInput.tBufMouseData.eMouseButton = NO_MOUSE_BUTTON;
        tInput.tBufMouseData.p.x = x;
        tInput.tBufMouseData.p.y = y;

        PostBufferedInput(tInput);
    }
    */
}

void InputManager::OnMouseDown(rex::ui::MouseEvent& e)
{

}

void InputManager::OnMouseUp(rex::ui::MouseEvent& e)
{

}

void InputManager::OnMouseMove(rex::ui::MouseEvent& e)
{
    /*
    m_mouseX = e.x();
    m_mouseY = e.y();
    m_mouseMoved = true;
    */
}

void InputManager::OnMouseWheel(rex::ui::MouseEvent& e)
{

}
