#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__
#include <iostream>

#include "components/component.hpp"
#include "components/animation_controller.hpp"
#include "game.hpp"
#include "Logger.hpp"
#include <utility>

using namespace engine;

class PlayerController : public Component{
public:
  PlayerController(GameObject &_main_game_object, std::string component_id, ImageComponent *background):
    Component(_main_game_object,component_id), walkDown(false), walkUp(false),
                                               walkLeft(false), walkRight(false), back(background){}

    ~PlayerController();

    bool init();
    void update();

    void move_player();

private:
    bool walkDown;
    bool walkUp;
    bool walkLeft;
    bool walkRight;
    ImageComponent *back;

};

#endif
