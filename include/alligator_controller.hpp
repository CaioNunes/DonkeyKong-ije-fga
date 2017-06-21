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
  AlligatorController(GameObject &main_game_object, GameObject *phead, std::string id, ImageComponent *background, AnimationControllerComponent *alligator_anim_controller):
    Component(main_game_object,id), head(phead), walkRightAlligator(true), walkDown(false),
                                    min(0), max(0), back(background), isRight(false), animController(alligator_anim_controller){}

    ~AlligatorController();

    bool init();
    void update();
    void move();
    void onCollision();

    void gravity();
    void processPos();
    bool hasGround();

    GameObject *head;

private:
    bool walkRightAlligator;
    bool walkDown;
    double min;
    double max;
    ImageComponent *back;
    bool isRight;
    AnimationControllerComponent *animController;

};

#endif
