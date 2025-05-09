//
// Created by benson on 2025/5/8.
//

#ifndef LONGPIPE_HPP
#define LONGPIPE_HPP
#include "Block/Pipe.hpp"
class LongPipe final: public Pipe {
    public:
        explicit LongPipe(glm::vec2 position);
        void hit(const std::shared_ptr<Mario> &Mario) override;
        BlockType GetType() override{return BlockType::LongPipe;};
};
#endif //LONGPIPE_HPP
