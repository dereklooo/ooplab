//
// Created by benson on 2025/3/14.
//

#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "Manager/BlockManager.hpp"
#include "Manager/GravityManager.hpp"
#include "Manager/ItemManager.hpp"
#include "Manager/ManagerManager.hpp"
#include "Manager/MapManager.hpp"
#include "Manager/MarioManager.hpp"
#include "Manager/MonsterManager.hpp"
#include "Manager/FlagManager.hpp"
#include "Util/Renderer.hpp"
#include "Util/BGM.hpp"
#include "Util/time.hpp"
class Level{
public:
    virtual ~Level() = default;

    Level()= default;
    bool GetNextLevelFlag (){return NextLevelFlag;}
    void SetNextLevelFlag(const bool flag){NextLevelFlag = flag;}
    void SetBackGround(std::shared_ptr<StillObject> Background);
    void SetSceneObject(std::shared_ptr<SceneObject> SceneObject);
    virtual void Update() = 0;
    void Start() const {

        m_ManagerManager->MarioInitialize();
        m_ManagerManager->FireballsInitialize();
        m_ManagerManager->TimeScoreManagerInitialize(m_renderer);
        m_renderer->AddChild(m_Background);
        m_renderer->AddChild(m_Mario);
        for (auto &[type,blocks] : *Blocks) {
            for (auto &block : blocks) {
                m_renderer->AddChild(block);
            }
        }
        for (const auto& [type,items] : *Items) {
            for(const auto &item : items) {
                m_renderer->AddChild(item);
            }
        }
    }
    void update() {
        if (Util::Input::IsKeyDown(Util::Keycode::E)) {
            m_Mario->SetPosition({m_Mario->GetPosition().x + 1000,m_Mario->GetPosition().y});
        }
        if(Util::Input::IsKeyDown(Util::Keycode::SPACE)) {
            std::cout<<m_Background->GetPosition().x<<std::endl;
        }
        this->Update();
        m_ManagerManager->Update();
        m_renderer->Update();
        SetNextLevelFlag(m_Mario->GetNextLevelFlag());
    }
    bool GetGameOverState() const {
        return GameOver;
    }

    float GetGameOverTime() {
        return GameOvertime;
    }
protected:
    bool GameOver = false;
    bool NextLevelFlag = false;

    std::shared_ptr<Util::Renderer> m_renderer = std::make_shared<Util::Renderer>();
    std::shared_ptr<Mario> m_Mario = std::make_shared<Mario>();
    std::shared_ptr<Map> m_Background;
    std::shared_ptr<Util::BGM> m_Bgm;
    std::shared_ptr<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>> Items = std::make_shared<std::unordered_map<ItemType, std::vector<std::shared_ptr<ItemObject>>>>();
    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>> Blocks = std::make_shared<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>>();
    std::shared_ptr<std::unordered_map<MonsterType,std::vector<std::shared_ptr<Monster>>>> Monsters = std::make_shared<std::unordered_map<MonsterType, std::vector<std::shared_ptr<Monster>>>>();

    std::vector<std::shared_ptr<FireBall>> FireBalls = std::vector<std::shared_ptr<FireBall>>();
    float GameOvertime=0.0;
    std::shared_ptr<ManagerManager> m_ManagerManager;
    size_t Condition_num = 1;


};
#endif //LEVEL_HPP
