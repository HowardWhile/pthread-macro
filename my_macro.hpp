#ifndef MY_MACRO_H_
#define MY_MACRO_H_

#pragma once

#include <pthread.h>

#define BACKGROUND_WORKER_CLOSE(cName, bgName) \
    void bg_##bgName##_close(void)             \
    {                                          \
        pthread_cancel(this->bg_##bgName);     \
    }

#define BACKGROUND_WORKER_START(cName, bgName)                               \
    void bg_##bgName##_start(void)                                           \
    {                                                                        \
        pthread_create(&bg_##bgName, NULL, &cName::bg_##bgName##_sLink, this); \
    }

#define BACKGROUND_WORKER_DOWORK(cName, bgName)           \
    pthread_t bg_##bgName;                                \
    static void *bg_##bgName##_sLink(void *iContext)        \
    {                                                     \
        return ((cName *)iContext)->bg_##bgName##_DoWork(); \
    }                                                     \
    void *bg_##bgName##_DoWork(void)

#define BACKGROUND_WORKER(ClassName, ThreadName)   \
    BACKGROUND_WORKER_START(ClassName, ThreadName) \
    BACKGROUND_WORKER_CLOSE(ClassName, ThreadName) \
    BACKGROUND_WORKER_DOWORK(ClassName, ThreadName)

#endif