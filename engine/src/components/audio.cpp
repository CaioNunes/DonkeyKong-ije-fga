#include "components/audio.hpp"
#include "game.hpp"

using namespace engine;

bool AudioComponent::init(){
    Log::instance.info("Iniciando audio '" + component_id +"'");

    if(m_is_music){
        gMusic = Mix_LoadMUS(main_path.c_str());

        if(gMusic == NULL){
            Log::instance.error("Failed to load audio: " + component_id);
            return false;
        }
    }else{
        //Logic to SOUNDS
    }
    return true;
}

bool AudioComponent::shutdown(){
    Log::instance.info("Shutdown Music");

    return true;
}

void AudioComponent::play(int loops, int channel){
    if(m_is_music){
        if(m_audio_state == AudioState::stopped) Mix_PlayMusic(gMusic, loops);
        else if (m_audio_state == AudioState::paused) Mix_ResumeMusic();
    } else {
        if(m_audio_state == AudioState::stopped)
            Mix_PlayChannel(channel, gSound, loops);
        else if (m_audio_state == AudioState::paused)
            Mix_Resume(channel);
    }

    m_audio_state = AudioState::playing;
}

void AudioComponent::update(){
    if(m_play_on_start){
        play();
        m_play_on_start = false;
    }
}

void AudioComponent::stop(int channel){

    if(m_is_music)
        Mix_HaltMusic();
    else
        Mix_HaltChannel(channel);

    m_audio_state = AudioState::stopped;
}

void AudioComponent::pause(int channel){
    if(m_is_music)
        Mix_PauseMusic();
    else
        Mix_Pause(channel);

    m_audio_state = AudioState::paused;
}
