//
// Created by 羅健文 on 2025/5/2.
//
#include "Manager/flagManager.hpp"

#include <iostream>
#include <ostream>


FlagManager::FlagManager(
    std::shared_ptr<Mario>& Mario,
    std::shared_ptr<Util::Renderer>& renderer,
    std::shared_ptr<std::unordered_map<BlockType, std::vector<std::shared_ptr<SceneObject>>>> &Blocks,
    std::shared_ptr<Map>& Background) :
    Blocks(Blocks),
    renderer(renderer),
    Mario_(Mario),
	Background(Background){

}
void FlagManager::HandleBlocksCollision()  {
    for(const auto &[BlockType,blocks] : *Blocks) {
          	for(const auto &block : blocks) {
                if(block->GetType()==BlockType::flag || block->GetType()==BlockType::flagball || block->GetType()==BlockType::flagpole) {

            	if((Mario_->RightCollision(block) || Mario_->LeftCollision(block) ||Mario_->UpCollision(block) ||Mario_->DownCollision(block)) && Mario_->GetTouchFlagFlag()!=true) {
            		std::cout << "aa" << std::endl;
                    Mario_->SetCanMove(false);

                    Mario_->SetCurrentState(HugFlag);
            		Mario_->UpDateCurrentState(Mario_->GetCurrentState());
            		Mario_->SetTouchFlagFlag(true);
            		FlagMoveFlag=true;
					Mario_->SetFalling(false);
					Mario_->SetAcceleration(0.0f);
            		Mario_->SetGravity(0.0f);
            		Mario_->SetFallingTime(0.0);

            	}
                }
        	}


    }
}



void FlagManager::Update() {
	std::cout << Mario_->GetGravity()<< std::endl;
	if (Mario_->GetTouchFlagFlag()==false) {
		HandleBlocksCollision();
	}

    else if(Mario_->GetTouchFlagFlag()==true){
     	if(FlagMoveFlag==true){

         	for(const auto &[BlockType,blocks] : *Blocks) {

          			for(const auto &block : blocks) {
                        if(block->GetType()==BlockType::flag){

	                        glm::vec2 FlagPosition = block->GetPosition();
	                        FlagPosition.y -= 2.0;
            				block->SetPosition(FlagPosition);
	                        //std::cout << "bb" << std::endl;

                        if(FlagPosition.y <= Mario_->GetPosition().y){
                        	FlagMoveFlag = false;
                            MarioMoveFlag = true;
                        	//std::cout << "cc" << std::endl;

                        }
        			}
        		}

    		}
     	}
        else if(MarioMoveFlag==true) {
	        Mario_->SetPosition({Mario_->GetPosition().x, Mario_->GetPosition().y-2.0});
        	for(const auto &[BlockType,blocks] : *Blocks) {
        		for(const auto &block : blocks) {
        			if(block->GetType()==BlockType::flag){
        				glm::vec2 FlagPosition = block->GetPosition();
        				FlagPosition.y -= 2.0;
        				block->SetPosition(FlagPosition);
        			}
        		}
        		if(Mario_->GetPosition().y <= -180) {
        			MarioMoveFlag = false;
        			Mario_->SetMarioGoDoorFlag(true);
        		}
        	}
        }

        else if(Mario_->GetMarioGoDoorFlag()==true){
        	Mario_->SetCurrentState(Run);
        	Mario_->UpDateCurrentState(Mario_->GetCurrentState());
        	//Mario_->SetCanMove(true);
        	Mario_->SetPosition({Mario_->GetPosition().x+3, Mario_->GetPosition().y});
        	//std::cout << Background->GetPosition().x<< std::endl;
        	if ( Background->GetPosition().x <= -9805) {
        		Mario_->SetMarioGoDoorFlag(false);
        		Mario_->SetNextLevelFlag(true);
        		Mario_->SetVisible(false);
        	}
        }
    }
}
