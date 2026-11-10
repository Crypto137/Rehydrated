#include "recomp/input_manager.h"

#include <rex/logging.h>
#include <rex/ppc.h>

#include "core/memory_utils.h"

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

}

void InputManager::OnMouseUp(rex::ui::MouseEvent& e)
{

}

void InputManager::OnMouseMove(rex::ui::MouseEvent& e)
{
    /* early experimental stuff
    BufferedInput tInput = {};
    tInput.eInputMsg = INPUTMSG_MOUSEMOVE;
    tInput.tBufMouseData.eMouseButton = NO_MOUSE_BUTTON;
    tInput.tBufMouseData.p.x = e.x();
    tInput.tBufMouseData.p.y = e.y();

    QueueInput(tInput);
    */
}

void InputManager::OnMouseWheel(rex::ui::MouseEvent& e)
{

}

void InputManager::QueueInput(const BufferedInput& input)
{
    std::unique_lock<std::mutex> lock(m_inputMutex);
    m_pendingInput->push_back(input);
}
