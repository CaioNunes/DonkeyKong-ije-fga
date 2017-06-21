#ifndef __ALLIGATOR_HPP__
#define __ALLIGATOR_HPP__
#include <iostream>

#include "components/component.hpp"
#include "components/animation_controller.hpp"
#include "game.hpp"
#include "Logger.hpp"
#include <utility>

using namespace engine;

class AlligatorController : public Component{
public:
  AlligatorController(GameObject &main_game_object, std::string id, ImageComponent *background):
    Component(main_game_object,id), walkRightAlligator(true), walkDown(false),
                                    min(0), max(0), back(background){}

    ~AlligatorController();

    bool init();
    void update();
    void move();
    void onCollision();

    void gravity();
    void processPos();
    bool hasGround();

private:
    bool walkRightAlligator;
    bool walkDown;
    double min;
    double max;
    ImageComponent *back;

};

#endif
