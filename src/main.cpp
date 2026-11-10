#include "RunWick.hpp"

int main(int argc, const char** argv) {
    RunWick rw(WindowSettings(800, 600, "RunWick", 60)) ;
    rw.init() ;
    rw.run() ;
    return 0 ;
}