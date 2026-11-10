#pragma once

#include <atomic>

#include <rex/ui/window.h>
#include <rex/ui/window_listener.h>

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

    void OnGuestInputUpdate();

    // WindowInputListener
    void OnMouseDown(rex::ui::MouseEvent& e) override;
    void OnMouseUp(rex::ui::MouseEvent& e) override;
    void OnMouseMove(rex::ui::MouseEvent& e) override;
    void OnMouseWheel(rex::ui::MouseEvent& e) override;

private:
    InputManager();
    ~InputManager() = default;

    std::atomic<bool> m_mouseMoved;
    std::atomic<f32> m_mouseX;
    std::atomic<f32> m_mouseY;
};