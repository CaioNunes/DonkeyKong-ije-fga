#include "player_controller.hpp"

double jumpForce = 20;
double gravityForce = 1;
bool jump = false;
// double moveSide = 3;
double moveSide = 5;
double velocity = 0;
double aceleration = 0;
float prev_position_y = 0;
bool isMove = false;
GameObject *ground;

bool PlayerController::init() {
    animCtrl->flipping(!isRightPlayer);

    return true;
}

void PlayerController::update(){
    move_player();
    if(!isMove){
        animCtrl->play_animation("donkey_idle");
    }else{
        animCtrl->play_animation("donkey_walking");
    }
    gravity();
    jump_player();
    processPos();
}

void PlayerController::gravity(){
    if(!hasGround()){
        aceleration += gravityForce;
    }else{
        aceleration = 0;
    }
}

void PlayerController::jump_player(){
    if(Game::instance.input_manager().is_button_down("up") && (aceleration==0)){
        jump = true;
        aceleration -= jumpForce;
    }
}

void PlayerController::processPos(){
    prev_position_y = _main_game_object->main_positionY;
    _main_game_object->main_positionY += aceleration;
}

bool PlayerController::hasGround(){
    ground = Game::instance.collision_manager->checkCollision(_main_game_object, "ground");
    if(ground && aceleration >= 0){
        if(aceleration > 5){
            _main_game_object->main_positionY = ground->main_positionY - _main_game_object->main_height;
        }
        return true;
    }
    return false;
}

void PlayerController::onCollision(){
    if(Game::instance.collision_manager->checkCollision(_main_game_object, "ground")){
        walkDown = false;
    }

    // if(Game::instance.collision_manager->checkCollision(_main_game_object, "mob_head"))
        // killEnemy = true;
    // } else{
    if(Game::instance.collision_manager->checkCollision(_main_game_object, "mob")){
        walkDown = false;
        animCtrl->play_animation("donkey_die", true);
        // animCtrl->play_animation("donkey_die_solo");
    }

    // }
}

void PlayerController::move_player(){
    // //Move down
    // if(Game::instance.input_manager().is_button_down("down"))
    //     walkDown = true;
    //
    // if(Game::instance.input_manager().is_button_up("down"))
    //     walkDown = false;

    onCollision();
    //
    // if(walkDown){
    //     if(back->move_img_down(moveSide, 700)){
    //
    //     }else{
    //         _main_game_object->main_positionY += gravityForce;
    //     }
    //     // if(back->move_img_down(moveSide, 3000)){
    //     //
    //     // }else{
    //     //     _main_game_object->main_positionY += moveSide;
    //     // }
    // }
    //Move Right
    if(Game::instance.input_manager().is_button_down("right")){
        walkRight = true;
        isMove = true;
        isRightPlayer = true;
    }

    if(Game::instance.input_manager().is_button_up("right")){
        walkRight = false;
        isMove = false;
    }

    if(walkRight){
        if(back->move_img_rect(moveSide)){
            limit = false;
        }else{
            limit = true;
            _main_game_object->main_positionX += moveSide;
        }
    }
    //Move Left
    if(Game::instance.input_manager().is_button_down("left")){
        walkLeft = true;
        isMove = true;
        isRightPlayer = false;
    }

    if(Game::instance.input_manager().is_button_up("left")){
        walkLeft = false;
        isMove = false;
    }

    if(walkLeft){
        if(back->move_img_rect(-(moveSide))){
            limit = false;
        }else{
            limit = true;
            _main_game_object->main_positionX -= moveSide;
        }
    }
}

PlayerController::~PlayerController(){}
