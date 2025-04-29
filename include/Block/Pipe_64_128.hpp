//
// Created by benson on 2025/3/25.
//

#ifndef PIPE_64_128_HPP
#define PIPE_64_128_HPP
#include "Block/Pipe.hpp"
class Pipe64_128 final : public Pipe {
    public:
        explicit Pipe64_128(glm::vec2 position);
        void hit(const std::shared_ptr<Mario> &Mario) override;
        BlockType GetType() override{return BlockType::Pipe_64_128;};
};
#endif //PIPE_64_128_HPP
