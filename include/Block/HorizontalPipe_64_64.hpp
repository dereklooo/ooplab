//
// Created by Benson on 2025/5/8.
//

#ifndef HORIZONTALPIPE_64_64_HPP
#define HORIZONTALPIPE_64_64_HPP
#include "Block/Pipe.hpp"
class HorizontalPipe_64_64 final: public Pipe {
    public:
        explicit HorizontalPipe_64_64(glm::vec2 position,Way way);
        void hit(const std::shared_ptr<Mario> &Mario) override;
        BlockType GetType() override{return BlockType::HorizontalPipe_64_64;};
        Way GetWay() const {
            return way;
        }
        void SetWay(const Way way) {
            this->way = way;
        }
    private:
        Way way;

};
#endif //HORIZONTALPIPE_64_64_HPP
