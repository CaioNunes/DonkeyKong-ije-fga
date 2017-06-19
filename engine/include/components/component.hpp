#ifndef _ENGINE_COMPONENTS_COMPONENT
#define _ENGINE_COMPONENTS_COMPONENT

namespace engine{
  //Define a class gameobject como vazia aqui, para não ter problemas de importação cíclica.
  class GameObject;

  class Component{
  public:
    enum class State{
      enabled,
      disabled,
      invalid
    };

    //Sobrecarga do construtor para  componentes criados sem parâmetros serem invalidados.
    Component(): main_state(State::invalid), _main_game_object(NULL){}

    Component(GameObject &gameObject, std::string name)
    : main_state(State::enabled), component_id(name), _main_game_object(&gameObject){}

    //Sobrecarga do construtor para  componentes que serão renderizados (sistema de layers).
    Component(GameObject &gameObject, std::string name, int p_priority)
    : main_state(State::enabled), component_id(name),  priority(p_priority), _main_game_object(&gameObject){}


    virtual ~Component() {};
    virtual bool init(){ return true; }
    virtual bool shutdown(){ return true; }

    virtual void update(){ return; }

    inline State state(){ return main_state; }

    inline void enable() { main_state = State::enabled; }
    inline void disable() { main_state = State::disabled; }
    inline int get_priority() {return priority; }
    inline void set_priority(int p){ priority = p;}

    State main_state;
    std::string component_id;
    int priority;

  protected:
      GameObject* _main_game_object;
    //O componente guarda uma referência do game object ao qual pertence.
  };
}

#endif
