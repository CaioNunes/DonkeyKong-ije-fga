# DonkeyKong

----------
## Lista de dependências

* gcc - versão 5.4.0
* g++ - versão 11
* libsdl - versão 2.0.5 (libsdl)
	* sdl_image - versão 2.0.1 dev
	* sdl_mixer - versão 2.0.1 dev
	* sdl_ttf  - versão 2.0.1 dev
* CMake - versão 3.8.1

----------
## Configurando o Jogo

### Instalando as dependências
    sudo apt-get install cmake libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev

### Configurando o Jogo
Download do repositório através do github

    git clone 

### Compilando 
Utilizando as configurações dos arquivos CmakeList.txt e Makefile

    cd 
    mkdir build && cd build
    cmake ..
    make
   
#### Execução

    ./game

#### Log de informações

    cat log.txt

----------
