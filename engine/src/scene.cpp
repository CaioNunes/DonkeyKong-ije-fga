#include "scene.hpp"
#include <algorithm>

using namespace engine;

//Definição de game object inválido
// GameObject INVALID_GAME_OBJECT;

bool compare_scene(engine::GameObject* a, GameObject *b){
    return a->priority < b->priority;
}

void Scene::print_scene_objects(){
    Log::instance.info("====PRINTANDO LISTA DE OBJETOS DA CENA EM ORDEM====");
    for(int i=0; i<scene_objects.size(); i++){
        Log::instance.info(scene_objects[i]->name());
    }
    Log::instance.info("===================================================");
}

bool Scene::add_game_object(GameObject *obj){
    auto id = obj->name();
    Log::instance.info("Adding GameObject '"+ id +"' to scene '" + scene_name +"'.");

    //Iterando mapa para ver se aquele game object já existe nela
    // if (scene_objects.find(id) != scene_objects.end()){
    //     Log::instance.warning("Game object já existe!");
    //     return false;
    // }
    scene_objects.push_back(obj);
    // scene_objects[id] = &obj;
    sort(scene_objects.begin(), scene_objects.end(), compare_scene);
    return true;
}
//
// GameObject &Scene::get_game_object(const std::string &id){
//
//     if(scene_objects.find(id) == scene_objects.end()){
//         Log::instance.warning("Não foi possível encontrar o GameObject '" + id +"'.");
//         return INVALID_GAME_OBJECT;
//     }
//
//     return *scene_objects[id];
// }
//
// bool Scene::remove_game_object(const std::string &id){
//
//     Log::instance.info("Removendo GameObject '" + id +"' da Scene.");
//
//     if(scene_objects.find(id) == scene_objects.end()){
//         Log::instance.warning("Não foi possível encontrar o GameObject '" + id +"'.");
//         return false;
//     }
//
//     scene_objects.erase(id);
//     return true;
// }

bool Scene::init(){
    //INFO("Init scene " << name);
    for (auto id_obj: scene_objects){
        // auto obj = id_obj.second;
        if (id_obj->init() == false){
            //WARN("Could not init game object " << obj->name());
            return false;
        }

    }

return true;
}

bool Scene::shutdown(){
    Log::instance.info("Destruindo cena '" + scene_name +"'.");

    //Iterando o mapa e inicilizando cada um dos game objects.
    for(auto id_obj: scene_objects){
        // auto obj = id_obj.second;
        if(id_obj->state() == GameObject::State::enabled && id_obj->shutdown() == false)
            return false;
    }

    return true;
}

void Scene::update(){
    for (auto id_obj: scene_objects){
        // auto obj = id_obj.second;
        if (id_obj->state() == GameObject::State::enabled) id_obj->update();
    }
}

bool Scene::draw(){

    //Iterando o mapa e inicilizando cada um dos game objects.
    for(auto id_obj: scene_objects){
        // auto obj = id_obj.second;
       if(id_obj->state() == GameObject::State::enabled && id_obj->draw() == false)
            return false;
    }

    return true;
}

std::list <GameObject *> * Scene::get_collide_objects(){
    //Iterando o mapa e inicilizando cada um dos game objects.
    for(auto id_obj: scene_objects){
        // auto obj = id_obj.second;
       if(id_obj->state() == GameObject::State::enabled && id_obj->m_collision == true)
	 collide_objects.push_back(id_obj);
    }

    return &collide_objects;
}

void Scene::clear_collide_objects(){
  collide_objects.clear();
}

void Scene::game_logic(){}
