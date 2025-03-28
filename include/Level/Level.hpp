//
// Created by benson on 2025/3/14.
//

#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "Object/StillObject.hpp"
#include "Monsters/Monster.hpp"
#include "Object/SceneObject.hpp"
#include "Mario/Mario.hpp"
#include "Util/Input.hpp"
#include "Util/Renderer.hpp"
#include "Manager/MapManerger.hpp"
#include <iostream>
class Level{
public:
    void SetBackGround(std::shared_ptr<StillObject> Background);
    void SetSceneObject(std::shared_ptr<SceneObject> SceneObject);
    virtual void condition() = 0;
    void Start() {
        m_MariO->SetPosition({-620,-235.5});
        m_MariO->SetCurrentState(Action::Stand);
        m_MariO->SetZIndex(50);
        m_MariO->SetSize({1,1});
        m_renderer->AddChild(m_Background);
        m_renderer->AddChild(m_MariO);
        for (auto &object : SceneManager) {
            m_renderer->AddChild(object);
        }
    }
    void update() {
        if (Util::Input::IsKeyPressed(Util::Keycode::SPACE)) {
            std::cout<<m_MariO->GetPosition().x<<" "<<m_MariO->GetPosition().y<<std::endl;
            std::cout<<SceneManager[0] -> GetPosition().x<<" "<<SceneManager[0] -> GetPosition().y<<std::endl;
        }
        if(Util::Input::IsKeyPressed(Util::Keycode::D)) {
            if (m_MariO->GetPosition().x >= 0) {
                m_Background->SetPosition({m_Background->GetPosition().x - 4,m_Background->GetPosition().y});
                for(auto monster : Monsters) {
                    monster->SetPosition({monster->GetPosition().x - 4,monster->GetPosition().y});
                }
                for (auto Object : SceneManager) {
                    Object->SetPosition({Object->GetPosition().x - 4 , Object->GetPosition().y});
                }
            }
            else {
                m_MariO->SetPosition({m_MariO->GetPosition().x + 4,m_MariO->GetPosition().y});
            }
            m_MariO->SetCurrentState(Action::Run);
    }


        if(Util::Input::IsKeyPressed(Util::Keycode::A)) {
            if(m_MariO->GetPosition().x - 1 <= -620) {
                m_MariO->SetPosition({-620,m_MariO->GetPosition().y});
            }
            m_MariO->SetPosition({m_MariO->GetPosition().x - 4,m_MariO->GetPosition().y});
            m_MariO->SetSize({-1,1});
            m_MariO->SetCurrentState(Action::Run);
        }

        if(Util::Input::IsKeyPressed(Util::Keycode::S)) {
            m_MariO->SetPosition({m_MariO->GetPosition().x,m_MariO->GetPosition().y - 4});
            m_MariO->SetCurrentState(Action::Down);
        }

        if(Util::Input::IsKeyPressed(Util::Keycode::W)) {
            m_MariO->SetCurrentState(Action::Jump);
            m_MariO->SetPosition({m_MariO->GetPosition().x,m_MariO->GetPosition().y + 4});
        }


        if(!Util::Input::IsKeyPressed(Util::Keycode::S) &&
            !Util::Input::IsKeyPressed(Util::Keycode::W) &&
            !Util::Input::IsKeyPressed(Util::Keycode::A) &&
            !Util::Input::IsKeyPressed(Util::Keycode::D)) {
            m_MariO->SetCurrentState(Action::Stand);
            }

        for (auto& monster : Monsters) {
            monster->Action();
        }
        this->condition();
        MapManerger->Update(m_MariO,Monsters,SceneManager);
        m_renderer->Update();
    }


protected:
    std::shared_ptr<Util::Renderer> m_renderer = std::make_shared<Util::Renderer>();
    std::shared_ptr<m_mariO> m_MariO = std::make_shared<m_mariO>();
    std::shared_ptr<StillObject> m_Background;
    std::vector<std::shared_ptr<SceneObject>> SceneManager;
    std::vector<std::shared_ptr<Monster>> Monsters;
    std::shared_ptr<MapManager> MapManerger;
    size_t Condition_num = 1;
    int moveDistange = 0;
};
#endif //LEVEL_HPP
