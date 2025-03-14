#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

#include "StillObject.hpp"

void App::Title() {
    LOG_TRACE("Title");
    m_Background = std::make_shared<StillObject> (RESOURCE_DIR "/image/Background/Title/The_Title.png");
    m_Background->SetPosition({0,0});
    m_Background->SetZIndex(49);
    m_Background->SetSize({1.6,1.2});
    m_renderer = std::make_shared<Util::Renderer>();
    m_renderer->AddChild(m_Background);

    m_TitleMashroom = std::make_shared<AnimationObject>(2,RESOURCE_DIR "/image/character/TitleMashroom/mushroom");
    m_TitleMashroom->SetPosition({-220,-103});
    m_TitleMashroom->SetSize({0.15,0.15});
    m_TitleMashroom->SetZIndex(51);
    m_renderer->AddChild(m_TitleMashroom);

    m_TitleWord = std::make_shared<AnimationObject>(2,RESOURCE_DIR "/image/character/TitleWord/EnterContinue");
    m_TitleWord->SetPosition({0,-200});
    m_TitleWord->SetZIndex(52);
    m_TitleWord->SetSize({4.5,3});
    m_renderer->AddChild(m_TitleWord);

    m_CurrentState = State::TitleUpdate;
}
void App::TitleUpgrade() {
    LOG_TRACE("TitleUpgrade");
    if (Util::Input::IsKeyPressed(Util::Keycode::KP_ENTER)|| Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
        m_CurrentState = State::END;
    }
    m_renderer->Update();
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
        }
}

void App::Start() {
    LOG_TRACE("Start");
    m_renderer = std::make_shared<Util::Renderer>();

    m_MariO = std::make_shared<m_mariO>();
    m_MariO->SetPosition({0,0});
    m_MariO->SetCurrentState(Action::Stand);
    m_MariO->SetZIndex(50);
    m_MariO->SetSize({1.6,1.2});

    m_Background->SetDrawable(std::make_shared<Util::Image>(RESOURCE_DIR"/image/Background/Level1/level_1.png"));
    m_Background->SetSize({3.5,3.5});

    m_renderer->AddChild(m_Background);
    m_renderer->AddChild(m_MariO);
    m_CurrentState = State::UPDATE;
}

void App::Update() {

    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */
    m_level->update();
    if(Util::Input::IsKeyPressed(Util::Keycode::D)) {
        m_Background->SetPosition({m_Background->GetPosition().x - 1,m_Background->GetPosition().y});
        m_MariO->SetCurrentState(Action::Run);
    }


    if(Util::Input::IsKeyPressed(Util::Keycode::A)) {
        m_Background->SetPosition({m_Background->GetPosition().x + 1,m_Background->GetPosition().y});
        m_MariO->SetCurrentState(Action::Run);
    }

    if(Util::Input::IsKeyPressed(Util::Keycode::S)) {
        m_MariO->SetCurrentState(Action::Down);
        m_MariO->SetPosition({m_MariO->GetPosition().x,m_MariO->GetPosition().y - 1});
    }

    if(Util::Input::IsKeyPressed(Util::Keycode::W)) {
        m_MariO->SetCurrentState(Action::Jump);
        m_MariO->SetPosition({m_MariO->GetPosition().x,m_MariO->GetPosition().y + 1});
    }

    if(!Util::Input::IsKeyPressed(Util::Keycode::S) &&
        !Util::Input::IsKeyPressed(Util::Keycode::W) &&
        !Util::Input::IsKeyPressed(Util::Keycode::A) &&
        !Util::Input::IsKeyPressed(Util::Keycode::D)) {
        m_MariO->SetCurrentState(Action::Stand);
    }
    m_renderer->Update();


    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
        }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
