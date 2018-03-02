//
// Created by alex on 02.03.18.
//

#ifndef PROJECT_RENDER_H
#define PROJECT_RENDER_H

#include <pthread.h>

pthread_t startGameWindow(int argc, char* argv[]);
void waitForGameWindowClose(pthread_t window_thread);


#endif //PROJECT_RENDER_H
