#include "gameobject.hpp"
#include "components/image.hpp"
#include "components/animation.hpp"
#include <algorithm>

using namespace engine;

bool compare(Component* a, Component* b){
    return a->get_priority() < b->get_priority();
}

bool GameObject::init(){
    Log::instance.info("Init game object " + main_name);

    for(auto id_componentlist: main_components){
        for (auto component: id_componentlist.second){
            if(component->init() == false) return false;
        }
    }
    return true;
}

bool GameObject::shutdown(){
    Log::instance.info("Shutdown game object " + main_name);

    //Iterando o mapa de componentes, passando por cada tipo de componente.
    for(auto id_componentList: main_components){
        //Iterando a lista de componentes do tipo encontrado.
        for(auto component:id_componentList.second){
            if(component->state() == Component::State::enabled && component->shutdown() == false)
                return false;
        }
    }

    return true;
}

bool GameObject::draw(){
    //Procurando no mapa os componentes do tipo ImageComponent
    for(auto component: main_components[std::type_index(typeid(ImageComponent))]){
        /*Caso o componente encontrado esteja com estado habilitado, converte ele para um componente de imagem
        e o desenha na tela*/
        if(component->state() == Component::State::enabled)
            (dynamic_cast<ImageComponent *>(component))->draw();
    }

    for(auto component: main_components[std::type_index(typeid(Animation))]){
        /*Caso o componente encontrado esteja com estado habilitado, converte ele para um componente de imagem
          e o desenha na tela*/
        if(component->state() == Component::State::enabled)
            (dynamic_cast<Animation *>(component))->draw();
    }

    return true;
}

void GameObject::add_component(Component &component){
    Log::instance.info("Adding component: '" + component.component_id + "' to game object: '" + main_name + "'.");
    //Adiciona o componente no fim da lista referente ao tipo do mesmo.
    main_components[std::type_index(typeid(component))].push_back(&component);
    if(dynamic_cast<ImageComponent *>(&component))
        sort(main_components[std::type_index(typeid(ImageComponent))].begin(),main_components[std::type_index(typeid(ImageComponent))].end(), compare);
    else if(dynamic_cast<Animation *>(&component))
        sort(main_components[std::type_index(typeid(Animation))].begin(),main_components[std::type_index(typeid(Animation))].end(), compare);
}

void GameObject::update(){
    for(auto id_componentlist: main_components){
        for (auto component: id_componentlist.second){
            if(component->state() == Component::State::enabled){
                    component->update();
            }
        }
    }
}

Component* GameObject::get_component(std::string name){
    for(auto id_componentList: main_components){
        //Iterando a lista de componentes do tipo encontrado.
        for(auto component:id_componentList.second){
            if(component->component_id == name){
                return component;
            }
        }
    }

    Log::instance.warning("Component '"+ name + "' not found in '" + main_name + "' gameobject.");
    return NULL;
}

void GameObject::setState(State state){
    main_state = state;
}
