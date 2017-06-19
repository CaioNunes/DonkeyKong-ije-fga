#include "player_controller.hpp"

double jumpForce = 10;
double gravityForce = 1;
bool jump = false;
// double moveSide = 3;
double moveSide = 5;
double velocity = 0;
double aceleration = 0;
float prev_position_y = 0;
GameObject *ground;

bool PlayerController::init() { return true; }

void PlayerController::update(){
    gravity();
    move_player();
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
}

void PlayerController::move_player(){
    //Move down
    if(Game::instance.input_manager().is_button_down("down"))
        walkDown = true;

    if(Game::instance.input_manager().is_button_up("down"))
        walkDown = false;

    onCollision();

    if(walkDown){
        if(back->move_img_down(moveSide, 700)){

        }else{
            _main_game_object->main_positionY += gravityForce;
        }
    }
    //Move Up
    if(Game::instance.input_manager().is_button_down("up"))
        walkUp = true;

    if(Game::instance.input_manager().is_button_up("up"))
        walkUp = false;

    if(walkUp){
        // if(back->move_img_down(-(moveSide), 700)){

        // }else{
            // jump_player();
            // aceleration += 10;
            // _main_game_object->main_positionY -= jumpForce;
        // }
    }
    //Move Right
    if(Game::instance.input_manager().is_button_down("right"))
        walkRight = true;

    if(Game::instance.input_manager().is_button_up("right"))
        walkRight = false;

    if(walkRight){
        if(back->move_img_rect(moveSide)){

        }else{
            _main_game_object->main_positionX += moveSide;
        }
    }
    //Move Left
    if(Game::instance.input_manager().is_button_down("left")){
        walkLeft = true;
    }

    if(Game::instance.input_manager().is_button_up("left"))
        walkLeft = false;

    if(walkLeft){
        if(back->move_img_rect(-(moveSide))){

        }else{
            _main_game_object->main_positionX -= moveSide;
        }
    }
}

PlayerController::~PlayerController(){}
