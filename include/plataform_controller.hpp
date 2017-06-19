#ifndef __PLATAFORM_HPP__
#define __PLATAFORM_HPP__
#include <iostream>

#include "components/component.hpp"
#include "components/animation_controller.hpp"
#include "game.hpp"
#include "Logger.hpp"
#include <utility>

using namespace engine;

class PlataformController : public Component{
public:
  PlataformController(GameObject &_main_game_object, std::string component_id):
    Component(_main_game_object,component_id), walkDown(false), walkUp(false),
                                               walkLeft(false), walkRight(false){}

    ~PlataformController();

    bool init();
    void update();
    void move_plataform();
    bool walkDown;
    bool walkUp;
    bool walkLeft;
    bool walkRight;

private:
    double moveForceUp = 7;
    double moveForceDown = 2;
    // double moveSide = 3;
    double moveSide = 5;
};

#endif
