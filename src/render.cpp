//
// Created by alex on 02.03.18.
//

#include <render.h>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <pthread.h>

struct args
{
    int argc;
    char** argv;
};

void renderFunc();
void* windowThreadFunc(void* context);

pthread_t startGameWindow(int argc, char* argv[])
{
    pthread_t thread;
    struct args context = {argc, argv};

    pthread_create(&thread, NULL, (void*(*)(void*)) windowThreadFunc, &context);

    return thread;
}

void waitForGameWindowClose(pthread_t window_thread)
{
    pthread_join(window_thread, NULL);
}

void* windowThreadFunc(void* context)
{
    auto * ctx = (struct args*) context;

    glutInit(&(ctx->argc), ctx->argv);

    glutInitContextVersion(3, 0);
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    glutSetOption(
            GLUT_ACTION_ON_WINDOW_CLOSE,
            GLUT_ACTION_GLUTMAINLOOP_RETURNS
    );

    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    if (glutCreateWindow("Hello, niggas") < 1)
        return (void*)-1;

    glutDisplayFunc(renderFunc);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glutMainLoop();

    return (void*)0;
}

void renderFunc()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();
    glutPostRedisplay();
}
