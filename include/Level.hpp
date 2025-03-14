//
// Created by benson on 2025/3/14.
//

#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "StillObject.hpp"
#include "ScenceObject.hpp"
#include "AnimationObject.hpp"
#include "m_mariO.hpp"
#include "Monster.hpp"
class Level{
  public:
    Level();
    void SetBackGround(std::shared_ptr<StillObject> Background);
    void SetMonster(std::vector<std::shared_ptr<Monster>> Monsters);
    void SetScenceObject(std::shared_ptr<ScenceObject> ScenceObject);

    void update();
  private:

      std::shared_ptr<m_mariO> m_Mari;
};
#endif //LEVEL_HPP
