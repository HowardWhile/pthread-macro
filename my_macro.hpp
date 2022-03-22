#ifndef MY_MACRO_H_
#define MY_MACRO_H_

#pragma once

#include <pthread.h>

#define BACKGROUND_WORKER_CLOSE(cName, bgName) \
public:                                        \
    void bgName##_close(void)                  \
    {                                          \
        pthread_cancel(this->bgName);          \
    }

#define BACKGROUND_WORKER_START(cName, bgName)                       \
public:                                                              \
    void bgName##_start(void)                                        \
    {                                                                \
        pthread_create(&bgName, NULL, &cName::bgName##_sLink, this); \
    }

#define BACKGROUND_WORKER_DOWORK(cName, bgName)        \
private:                                               \
    pthread_t bgName;                                  \
                                                       \
private:                                               \
    static void *bgName##_sLink(void *iContext)        \
    {                                                  \
        return ((cName *)iContext)->bgName##_DoWork(); \
    }                                                  \
                                                       \
private:                                               \
    void *bgName##_DoWork(void)

#define BACKGROUND_WORKER(ClassName, ThreadName)   \
    BACKGROUND_WORKER_START(ClassName, ThreadName) \
    BACKGROUND_WORKER_CLOSE(ClassName, ThreadName) \
    BACKGROUND_WORKER_DOWORK(ClassName, ThreadName)

#endif