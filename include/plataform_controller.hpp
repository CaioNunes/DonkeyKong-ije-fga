#ifndef __PLATAFORM_HPP__
#define __PLATAFORM_HPP__
#include <iostream>

#include "components/component.hpp"
#include "components/animation_controller.hpp"
#include "game.hpp"
#include "Logger.hpp"
#include <utility>
#include "player_controller.hpp"

using namespace engine;

class PlataformController : public Component{
public:
  PlataformController(GameObject &main_game_object, PlayerController *main_player, std::string id):
    Component(main_game_object,id), walkDown(false), walkUp(false),
                                    walkLeft(false), walkRight(false), player(main_player){}

    ~PlataformController();

    bool init();
    void update();
    void move_plataform();
    bool walkDown;
    bool walkUp;
    bool walkLeft;
    bool walkRight;

private:
    PlayerController *player;
    double moveForceUp = 7;
    double moveForceDown = 2;
    // double moveSide = 3;
    double moveSide = 5;
};

#endif
