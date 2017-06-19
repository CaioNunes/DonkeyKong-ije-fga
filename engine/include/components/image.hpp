#ifndef __ENGINE_COMPONENTS_IMAGE__
#define __ENGINE_COMPONENTS_IMAGE__

#include<string>
#include<utility>
#include<sdl2core.hpp>

#include "components/component.hpp"
#include "gameobject.hpp"

namespace engine{
    class ImageComponent : public Component {
        public:
            ImageComponent(GameObject &main_game_object, std::string id, std::string path, int p_priority)
            : Component(main_game_object, id, p_priority), main_path(path){}

            ~ImageComponent(){};

            bool init();
            bool shutdown();

            void set_back_rect(int pX, int pY, int width, int height);
            bool move_img_rect(int value);
            bool move_img_down(int value, int limit);

            virtual void draw();

        protected:
            //Caminho da imagem
            std::string main_path;

            SDL_Texture *main_texture;
            SDL_Rect* imagePart = NULL;
    };
}

#endif
