//
// Created by alex on 02.03.18.
//

#include <render.h>

#include <iostream>
#include <unistd.h>

using namespace std;

void render();

int main(int argc, char* argv[])
{
    pthread_t window_thread = startGameWindow(argc, argv);

    cout << "Hey, bulls\n";

    waitForGameWindowClose(window_thread);

    return 0;
}