//
// Created by benson on 2025/3/25.
//

#ifndef PIPE_64_96_HPP
#define PIPE_64_96_HPP
#include "Block/Pipe.hpp"
class Pipe64_96 final : public Pipe {
public:
    explicit Pipe64_96(glm::vec2 position);
    void hit(const std::shared_ptr<Mario> &Mario) override;
    BlockType GetType() override{return BlockType::Pipe_64_96;};
};
#endif //PIPE_64_96_HPP
