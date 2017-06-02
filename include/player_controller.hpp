#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__
#include <iostream>

#include "components/component.hpp"
#include "components/animation_controller.hpp"
#include "game.hpp"
#include "Logger.hpp"

using namespace engine;

class PlayerController : public Component{
public:
  PlayerController(GameObject &_main_game_object, std::string component_id):
    Component(_main_game_object,component_id), walkDown(true), walkUp(false),
                                               walkLeft(false), walkRight(false){}

    ~PlayerController();

    bool init();
    void update();

    void move_player();

private:
    bool walkDown;
    bool walkUp;
    bool walkLeft;
    bool walkRight;

};

#endif
