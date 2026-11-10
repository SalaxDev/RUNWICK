#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <string>

struct WindowSettings {
    unsigned int nWidth, nHeight ;
    unsigned int nDefaultFPS ;
    std::string name ;
    
    /**
     * \brief Construct a new Window Settings object
     * 
     * \param windowWidth Width Size of the Window
     * \param windowHeight Height Size of the Window
     * \param windowName Title name
     * \param FPS Frame per Second, put 0 for Uncapped FPS
     */
    WindowSettings(unsigned int windowWidth = 800, unsigned int windowHeight = 600, std::string windowName = "RunWick", unsigned int FPS = 60)
        : nWidth(windowWidth), nHeight(windowHeight), name(std::move(windowName)), nDefaultFPS(FPS) {}
};

#endif // SETTINGS_HPP