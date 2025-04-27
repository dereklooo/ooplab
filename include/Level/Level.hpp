//
// Created by benson on 2025/3/14.
//

#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "Object/StillObject.hpp"
#include "Monsters/Monster.hpp"
#include "Object/SceneObject.hpp"
#include "Object/ItemObject.hpp"
#include "Mario/Mario.hpp"
#include "Util/Input.hpp"
#include "Util/Renderer.hpp"
#include "Manager/MapManager.hpp"
#include <iostream>


class Level{
public:
    void SetBackGround(std::shared_ptr<StillObject> Background);
    void SetSceneObject(std::shared_ptr<SceneObject> SceneObject);
    virtual void Update() = 0;
    void Start() {
        m_MariO = std::make_shared<Mario>();
        m_MariO->SetGravity(-2.0f);
        m_MariO->SetPosition({-620,-150});
        m_MariO->UpDateCurrentState(Stand);

        m_MariO->SetZIndex(50);
        m_MariO->SetSize({1.35,1.2});
        m_renderer->AddChild(m_Background);
        m_renderer->AddChild(m_MariO);
        for (auto &object : SceneManager) {
            m_renderer->AddChild(object);
        }
        for (const auto& Object : ItemManager) {
            m_renderer->AddChild(Object);
        }
    }
    void update() {
        m_MariO->update();
        if(Util::Input::IsKeyPressed(Util::Keycode::SPACE)) {
            std::cout<<m_Background->GetPosition().x << std::endl;
        }

        this->Update();
        MapManager::Update(m_MariO,Monsters,SceneManager,ItemManager);
        m_renderer->Update();
        Gravity_Manager->Update(m_MariO,Monsters,ItemManager);
    }


protected:
    std::shared_ptr<Util::Renderer> m_renderer = std::make_shared<Util::Renderer>();
    std::shared_ptr<Mario> m_MariO;
    std::shared_ptr<StillObject> m_Background;

    std::vector<std::shared_ptr<SceneObject>> SceneManager;
    std::vector<std::shared_ptr<Monster>> Monsters;
    std::vector<std::shared_ptr<ItemObject>> ItemManager;
    std::shared_ptr<MapManager> Map_Manager;
    std::shared_ptr<GravityManager> Gravity_Manager;
    size_t Condition_num = 1;
};
#endif //LEVEL_HPP
