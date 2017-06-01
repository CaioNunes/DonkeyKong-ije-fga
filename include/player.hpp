#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__
#include <iostream>

#include "components/component.hpp"
#include "components/animation_controller.hpp"
#include "game.hpp"
#include "Logger.hpp"

using namespace engine;

class Player : public Component{
public:
  Player(GameObject &_main_game_object, std::string component_id, AnimationControllerComponent *animC):
    Component(_main_game_object,component_id), animCtrl(animC){}

    ~Player();

    bool init();
    void update();

    GameObject *player;

private:
    AnimationControllerComponent *animCtrl;

};

#endif
