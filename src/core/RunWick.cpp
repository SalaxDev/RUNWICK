#include "RunWick.hpp"
#include <format>

// Private Functions
// Initialization
bool RunWick::initWindow() {
    if (bInitFailed) return false ;
    
    if (wnd) SDL_DestroyWindow(wnd) ;
    SDL_Window *wnd = SDL_CreateWindow(sWindow.name.c_str(), sWindow.nWidth, sWindow.nHeight, 0) ;
    if (!wnd) {
        msgShow(MsgStats::ERROR, "Failed to create Window", "Failed Allocation") ;
        return false ;
    }
    
    if (rnd) SDL_DestroyRenderer(rnd) ;
    SDL_Renderer *rnd = SDL_CreateRenderer(wnd, nullptr) ;
    if (!rnd) {
        msgShow(MsgStats::ERROR, "Failed to create Window", "Failed Allocation") ;
        return false ;
    }
    
    return true ;
}

// Events
void RunWick::updateEvent() {
    // Event Loop
    while (SDL_PollEvent(&evn)) {
        switch(evn.type) {
            // Exit Event
            case SDL_EVENT_QUIT: {
                bRunning = false ;
                break ;
            }
            
            // Key Events
            case SDL_EVENT_KEY_DOWN: {
                switch(evn.key.scancode) {
                    case SDL_SCANCODE_ESCAPE: {
                        bRunning = false ;
                        break ;
                    }
                    
                    default: break ;
                }
                break ;
            }
            
            default: break ;
        }
    }
}

// Render Update
void RunWick::updateRender() {
    SDL_RenderClear(rnd) ;
    
    SDL_RenderPresent(rnd) ;
    if (sWindow.nDefaultFPS > 0) SDL_Delay(1000 / 60) ;
}

void RunWick::msgShow(MsgStats state, const char *message, const char *title) {
    using enum MsgStats ;
    switch(state) {
        case INFO: {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, title, message, nullptr) ;
            break ;
        }
        
        case ERROR: {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title, message, nullptr) ;
            break ;
        }
        
        default: {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Undefined Reference", "MessageStats Fallback to Default, Unrecognized Enum Status", nullptr) ;
            break ;
        }
    }
}

void RunWick::logError(const char *cause, bool getSDLError) {
    SDL_Log("Failed to %s", std::format("{}{}", cause, getSDLError ? SDL_GetError() : "").c_str()) ;
}

// Constructor
RunWick::RunWick(const WindowSettings windowSettings) : sWindow(windowSettings) {
    
    printf("sWindow:\nWidth: %u\nHeight: %u\nName: %s\nFPS: %d\n", sWindow.nWidth, sWindow.nHeight, sWindow.name.c_str(), sWindow.nDefaultFPS) ;
    
}

// Destructor
RunWick::~RunWick() {
    
    if (rnd) {
        SDL_DestroyRenderer(rnd) ;
    }
    
    if (wnd) {
        SDL_DestroyWindow(wnd) ;
        wnd = nullptr ;
    }
    
    SDL_Quit() ;
}
// Getter
    
// Setter
void RunWick::setRenderColor(SDL_Color color) {
    if (!bInited || bInitFailed) {
        msgShow(MsgStats::ERROR, "Can't set the render color when uninitialized, call init() first", "UnInitialized") ;
        return ;
    }
    
    SDL_SetRenderDrawColor(rnd, color.r, color.g, color.b, color.a) ;
}
// Functions
void RunWick::init() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) { 
        bInitFailed = true ;
        msgShow(MsgStats::ERROR, "Failed to initialize SDL3 VIDEO & AUDIO", "Initialization Error") ;
        return ;
    }
    
    if (!initWindow()) {
        bInitFailed = true ;
        return ;
    }
    
    bInited = true ;
    bInitFailed = false ;
}

// Game Loop
void RunWick::run() {
    if (!bInited) {
        msgShow(MsgStats::ERROR, "Not initialized, call init() first", "UnInitialized") ;
        return ;
    }
    
    if (bInitFailed) {
        msgShow(MsgStats::ERROR, "Initialization failed, call init() again", "Init Failed") ;
        return ;
    }
    
    while(bRunning) {
        updateEvent() ;
        updateRender() ;
    }
}
