#include "App.hpp"
#include "Util/Time.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "iostream"
#include "Object/StillObject.hpp"

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
        m_CurrentState = State::START;
    }
    m_renderer->Update();
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}

void App::Start() {
    LOG_TRACE("Start");
    switch(level) {
        case 1:
            m_level1 = std::make_shared<Level1>();
            m_level1->Start();
            break;
        case 2:
            m_level2 = std::make_shared<Level2>();
            m_level2->Start();
            break;
        case 3:
            m_level3 = std::make_shared<Level3>();
        m_level3->Start();
            break;
        case 4:
            m_level4 = std::make_shared<Level4>();
            m_level4->Start();
            break;
        default:
            break;
    }
    m_CurrentState = State::UPDATE;
}

void App::Update() {
    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */
    switch(level) {
        case 1:
            m_level1->update();
            if(m_level1->GetGameOverState() == true && ((Util::Time::GetElapsedTimeMs() - m_level1->GetGameOverTime() )>3000.0) ) {
                m_level1 = std::make_shared<Level1>();
                m_CurrentState = State::START;
                live--;
            }
             if (m_level1->GetNextLevelFlag()==true) {
                 level++;
                 m_renderer=std::make_shared<Util::Renderer>();
                 m_CurrentState = State::START;
             }
            m_level1->SetCurrentLives(live);
            break;
        case 2:
            m_level2->update();
            if(m_level2->GetGameOverState() == true && ((Util::Time::GetElapsedTimeMs() - m_level2->GetGameOverTime() )>3000.0)) {
                m_level2 = std::make_shared<Level2>();
                m_CurrentState = State::START;
                live--;
            }
            if (m_level2->GetNextLevelFlag()==true) {
                level++;
                m_CurrentState = State::START;
            }
        m_level2->SetCurrentLives(live);
            break;
        case 3:
            m_level3->update();
            if(m_level3->GetGameOverState() == true && ((Util::Time::GetElapsedTimeMs() - m_level3->GetGameOverTime() )>3000.0)) {
                m_level3 = std::make_shared<Level3>();
                m_CurrentState = State::START;
                live--;
            }
            if (m_level3->GetNextLevelFlag()==true) {

                level++;
                m_CurrentState = State::START;
            }
        m_level3->SetCurrentLives(live);
            break;
        case 4:
            m_level4->update();
            if(m_level4->GetGameOverState() == true && ((Util::Time::GetElapsedTimeMs() - m_level4->GetGameOverTime() )>3000.0)) {
                m_level4 = std::make_shared<Level4>();
                m_CurrentState = State::START;
                live--;
            }
            if (m_level4->GetNextLevelFlag()==true) {

                level++;
                m_CurrentState = State::START;
            }
        m_level4->SetCurrentLives(live);
            break;
        case 5:
            m_Background = std::make_shared<StillObject> (RESOURCE_DIR "/image/Background/END/gameover.png");
        m_Background->SetPosition({0,0});
        m_Background->SetZIndex(49);
        m_Background->SetSize({1.6,1.2});
        m_renderer = std::make_shared<Util::Renderer>();
        m_renderer->AddChild(m_Background);

        m_renderer->Update();
        if (Util::Time::GetElapsedTimeMs()-EndTime>=5000.0) {
            EndTime = 0.0;
            m_level1 = std::make_shared<Level1>();
            m_CurrentState = State::START;
            live=3;
            level=1;
        }
            break;
        default: ;
    }

    if (live==0 & EndTime==0.0) {
        level=5;
        END_BGM->SetVolume(40);
        END_BGM->Play();
        EndTime = Util::Time::GetElapsedTimeMs();

    }
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}
void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
