#pragma once

#include <list>
#include <memory>
#include <mutex>

#include <rex/ui/window.h>
#include <rex/ui/window_listener.h>

#include "game/input.h"

using InputQueue = std::list<BufferedInput>;

class InputManager : public rex::ui::WindowInputListener, public rex::ui::WindowListener
{
public:
    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    InputManager(InputManager&&) = delete;
    InputManager& operator=(InputManager&&) = delete;

    static InputManager& Instance()
    {
        static InputManager instance;
        return instance;
    }

    void Initialize(rex::ui::Window* window);

    bool OnGuestInputUpdate();

    // WindowInputListener
    void OnMouseDown(rex::ui::MouseEvent& e) override;
    void OnMouseUp(rex::ui::MouseEvent& e) override;
    void OnMouseMove(rex::ui::MouseEvent& e) override;
    void OnMouseWheel(rex::ui::MouseEvent& e) override;

private:
    InputManager();
    ~InputManager() = default;

    void QueueInput(const BufferedInput& input);

    std::unique_ptr<InputQueue> m_currentInput;
    std::unique_ptr<InputQueue> m_pendingInput;
    std::mutex m_inputMutex;
};