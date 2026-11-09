#ifndef RUNWICK_HPP
#define RUNWICK_HPP

#include <SDL3/SDL.h>
#include "Settings.hpp"

class RunWick {
private:
    // Private Variables
    bool bInited = false ;
    bool bInitFailed = false ;
    
    // Window Settings Structure, for holding initial variables building a window
   WindowSettings SWindow ;
    
    // SDL3 Variables
    SDL_Window *wnd = nullptr ;
    SDL_Renderer *rnd = nullptr ;
    
    // Event Handler
    SDL_Event evn ;
    
    // Private Functions
    bool init() ;
public:
    // Constructor
    RunWick(WindowSettings windowSettings = {}) ;
    // Destructor
    ~RunWick() ;
    
    // Getter
    
    // Setter
    
    // Functions
    void initialize() ;
    void run() ;
};

#endif // RUNWICK_HPP