#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export
#include "StillObject.hpp"
#include "AnimationObject.hpp"
#include "Util/Renderer.hpp"
#include "m_mariO.hpp"

class App {
public:
    enum class State {
        Title,
        TitleUpdate,
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Title();

    void TitleUpgrade();

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    void ValidTask();

private:
    std::shared_ptr<AnimationObject> m_TitleMashroom;
    std::shared_ptr<AnimationObject> m_TitleWord;

    std::shared_ptr<StillObject> m_Background;

    std::shared_ptr<m_mariO> m_MariO;

    std::shared_ptr <Util::Renderer> m_renderer;

    State m_CurrentState = State::Title;
};
#endif
