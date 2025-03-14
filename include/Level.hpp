//
// Created by benson on 2025/3/14.
//

#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "StillObject.hpp"
#include "Monster.hpp"
#include "ScenceObject.hpp"
#include "m_mariO.hpp"
#include "Util/Input.hpp"

class Level{
public:
    void SetBackGround(std::shared_ptr<StillObject> Background);
    void SetMonster(std::vector<std::shared_ptr<Monster>> Monsters);
    void SetScenceObject(std::shared_ptr<ScenceObject> ScenceObject);

    void update() {
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
    };
private:
    std::shared_ptr<m_mariO> m_MariO;
    std::shared_ptr<StillObject> m_Background;
    std::vector<std::shared_ptr<Monster>> Monsters;
    std::shared_ptr<ScenceObject> ScenceObject;
};
#endif //LEVEL_HPP
