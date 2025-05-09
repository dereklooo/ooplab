//
// Created by 羅健文 on 2025/5/2.
//

#ifndef FLAG_HPP
#define FLAG_HPP
#include "Object/SceneObject.hpp"
#include "Util/Time.hpp"
class flag : public SceneObject {
public:
    explicit flag(glm::vec2 Position);



private:
    std::shared_ptr<Util::Time> time;
};
#endif //FLAG_HPP
