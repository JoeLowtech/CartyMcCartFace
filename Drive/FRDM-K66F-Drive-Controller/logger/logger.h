/*
    Original Logger by Ollie Milton
    https://os.mbed.com/users/ollie8/code/Logger/
*/
#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "mbed.h"

#if MBED_TEST_MODE
    #define LOG_LEVEL_DEBUG
    #include "utest.h"

    #if defined LOG_LEVEL_TRACE
        #define TRACE(x, ...) utest_printf("[TRACE: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define DEBUG(x, ...) utest_printf("[DEBUG: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define INFO(x, ...) utest_printf("[INFO: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define WARN(x, ...) utest_printf("[WARN: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define ERROR(x, ...) utest_printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

    #elif defined LOG_LEVEL_DEBUG
        #define TRACE(x, ...)
        #define DEBUG(x, ...) utest_printf("[DEBUG: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define INFO(x, ...) utest_printf("[INFO: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define WARN(x, ...) utest_printf("[WARN: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define ERROR(x, ...) utest_printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

    #elif defined LOG_LEVEL_INFO
        #define TRACE(x, ...)
        #define DEBUG(x, ...)
        #define INFO(x, ...) utest_printf("[INFO: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define WARN(x, ...) utest_printf("[WARN: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define ERROR(x, ...) utest_printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

    #elif defined LOG_LEVEL_WARN
        #define TRACE(x, ...)
        #define DEBUG(x, ...)
        #define INFO(x, ...)
        #define WARN(x, ...) utest_printf("[WARN: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define ERROR(x, ...) utest_printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

    #elif defined LOG_LEVEL_ERROR
        #define TRACE(x, ...)
        #define DEBUG(x, ...)
        #define INFO(x, ...)
        #define WARN(x, ...)
        #define ERROR(x, ...) utest_printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

    #else
        #define TRACE(x, ...)
        #define DEBUG(x, ...)
        #define INFO(x, ...)
        #define WARN(x, ...)
        #define ERROR(x, ...)
    #endif

#else
    static UnbufferedSerial pc(USBTX,USBRX,115200);
    #define LOG_LEVEL_DEBUG
    #if defined LOG_LEVEL_TRACE
        #define TRACE(x, ...) std::printf("[TRACE: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define DEBUG(x, ...) std::printf("[DEBUG: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define INFO(x, ...) std::printf("[INFO: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define WARN(x, ...) std::printf("[WARN: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define ERROR(x, ...) std::printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

    #elif defined LOG_LEVEL_DEBUG
        #define TRACE(x, ...)
        #define DEBUG(x, ...) std::printf("[DEBUG: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define INFO(x, ...) std::printf("[INFO: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define WARN(x, ...) std::printf("[WARN: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define ERROR(x, ...) std::printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

    #elif defined LOG_LEVEL_INFO
        #define TRACE(x, ...)
        #define DEBUG(x, ...)
        #define INFO(x, ...) std::printf("[INFO: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define WARN(x, ...) std::printf("[WARN: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define ERROR(x, ...) std::printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

    #elif defined LOG_LEVEL_WARN
        #define TRACE(x, ...)
        #define DEBUG(x, ...)
        #define INFO(x, ...)
        #define WARN(x, ...) std::printf("[WARN: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);
        #define ERROR(x, ...) std::printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

    #elif defined LOG_LEVEL_ERROR
        #define TRACE(x, ...)
        #define DEBUG(x, ...)
        #define INFO(x, ...)
        #define WARN(x, ...)
        #define ERROR(x, ...) std::printf("[ERROR: %s:%d]"x"\r\n", __FILE__, __LINE__, ##__VA_ARGS__);

    #else
        #define TRACE(x, ...)
        #define DEBUG(x, ...)
        #define INFO(x, ...)
        #define WARN(x, ...)
        #define ERROR(x, ...)
    #endif

#endif

#endif
