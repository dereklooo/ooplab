//
// Created by Benson on 2025/4/26.
//

#include "Manager/ItemManager.hpp"
ItemManager::ItemManager(std::vector<std::shared_ptr<SceneObject>>& SceneObjects) : AllItems(),
    SceneObjects(SceneObjects) {
}

