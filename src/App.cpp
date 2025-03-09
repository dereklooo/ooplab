#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

#include "StillObject.hpp"

void App::Title() {
    LOG_TRACE("Title");
    m_Background = std::make_shared<StillCharacter> (RESOURCE_DIR "/image/Background/Title/The_Title.png");
    m_Background->SetPosition({0,0});
    m_Background->SetZIndex(50);
    m_Background->SetSize({1.6,1.2});
    m_renderer = std::make_shared<Util::Renderer>();
    m_renderer->AddChild(m_Background);

    m_CurrentState = State::TitleUpdate;
}
void App::TitleUpgrade() {
    LOG_TRACE("TitleUpgrade");
    m_renderer->Update();
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
        }
}

void App::Start() {
    LOG_TRACE("Start");

    m_renderer = std::make_shared<Util::Renderer>();
    m_CurrentState = State::UPDATE;
}

void App::Update() {

    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */
    m_renderer->Update();

    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
        }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
