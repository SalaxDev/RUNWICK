#ifndef RUNWICK_HPP
#define RUNWICK_HPP

#include <SDL3/SDL.h>

#include "Settings.hpp"

class RunWick {
private:
    // Private Variables
    
    // Booleans
    bool bInited = false ;
    bool bInitFailed = false ;
    bool bRunning = true ;
    
    // MessageBox Settings
    enum class MsgStats {
        INFO, ERROR
    }; 
    
    // Window Settings Structure, for holding initial variables building a window
    WindowSettings sWindow ;
    
    // SDL3 Variables
    SDL_Window *wnd = nullptr ;
    SDL_Renderer *rnd = nullptr ;
    
    // Event Handler
    SDL_Event evn ;
    
    // Private Functions
    bool initWindow() ; // Initialization
    void updateEvent() ; // Events
    void updateRender() ;
    void msgShow(MsgStats state, const char *message, const char *title) ;
    void logError(const char *cause, bool getSDLError = true) ;
public:
    // Constructor
    RunWick(WindowSettings windowSettings = {}) ;
    // Destructor
    ~RunWick() ;
    
    // Getter
    
    // Setter
    void setRenderColor(SDL_Color color) ;
    // Functions
    void init() ;
    void run() ;
};

#endif // RUNWICK_HPP
