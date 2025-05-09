#ifndef APP_HPP
#define APP_HPP

#include "AllInclude.hpp"
namespace Util::Logger {
    enum class Level;
}

class App {
public:
    enum class State {
        Title,
        TitleUpdate,
        START,
        UPDATE,
        GameOver,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Title();

    void TitleUpgrade();

    void Start();

    void Update();

    void GameOver();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    void ValidTask();


    std::shared_ptr<AnimationObject> m_TitleMashroom;

    std::shared_ptr<AnimationObject> m_TitleWord;

    std::shared_ptr<StillObject> m_Background;

    std::shared_ptr<Level> m_level1;

    std::shared_ptr<Level> m_level2;

    std::shared_ptr<Level> m_level3;


    std::shared_ptr <Util::Renderer> m_renderer;

    State m_CurrentState = State::Title;

    size_t level = 1;
};
#endif
