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
#include "Manager/MapManager.hpp"
#include "Manager/TimeManager.hpp"
#include <iostream>
#include "Mario/Mario_big.hpp"
#include "Mario/Mario_small.hpp"
#include "Mario/Mario_fire.hpp"


class Level{
public:
    void SetBackGround(std::shared_ptr<StillObject> Background);
    void SetSceneObject(std::shared_ptr<SceneObject> SceneObject);
    virtual void condition() = 0;
    void Start() {
        m_MariO->SetPosition({-620,-235.5});
        m_MariO->SetCurrentState(2);
        m_MariO->SetZIndex(50);
        m_MariO->SetSize({1,1});
        m_renderer->AddChild(m_Background);
        m_renderer->AddChild(m_MariO);
        for (auto &object : SceneManager) {
            m_renderer->AddChild(object);
        }
    }
    void update() {

        if(Util::Input::IsKeyPressed(Util::Keycode::D)) {
            if (m_MariO->GetPosition().x >= 0) {
                m_Background->SetPosition({m_Background->GetPosition().x - 4,m_Background->GetPosition().y});
                m_MariO->SetPosition({m_MariO->GetPosition().x - 4,m_MariO->GetPosition().y});
                for(const auto& monster : Monsters) {
                    monster->SetPosition({monster->GetPosition().x - 4,monster->GetPosition().y});
                }
                for (const auto& Object : SceneManager) {
                    Object->SetPosition({Object->GetPosition().x - 4 , Object->GetPosition().y});
                }
            }
        }
        m_MariO->update(m_MariO );
        if(Util::Input::IsKeyPressed(Util::Keycode::SPACE)) {
            std::cout<<m_Background->GetPosition().x<<std::endl;
        }


        for (const auto& monster : Monsters) {
            monster->Action();
        }
        this->condition();
        MapManager::Update(m_MariO,Monsters,SceneManager);
        Time_Manager->updata(m_MariO,Monsters,SceneManager);
        m_renderer->Update();
    }


protected:
    std::shared_ptr<Util::Renderer> m_renderer = std::make_shared<Util::Renderer>();
    std::shared_ptr<Mario> m_MariO = std::make_shared<Mario_small>();
    std::shared_ptr<StillObject> m_Background;
    std::vector<std::shared_ptr<SceneObject>> SceneManager;
    std::vector<std::shared_ptr<Monster>> Monsters;
    std::shared_ptr<MapManager> Map_Manager;
    std::shared_ptr<TimeManager> Time_Manager;
    size_t Condition_num = 1;
    int moveDistange = 0;
};
#endif //LEVEL_HPP
