#pragma once

#define LOG_COLOR_BLACK "30"
#define LOG_COLOR_RED "31"
#define LOG_COLOR_GREEN "32"
#define LOG_COLOR_BROWN "33"
#define LOG_COLOR_BLUE "34"
#define LOG_COLOR_PURPLE "35"
#define LOG_COLOR_CYAN "36"
#define LOG_COLOR(COLOR) "\033[0;" COLOR "m"
#define LOG_RESET_COLOR "\033[0m"
#define LOG_COLOR_E LOG_COLOR(LOG_COLOR_PURPLE)
#define LOG_COLOR_W LOG_COLOR(LOG_COLOR_BROWN)
#define LOG_COLOR_I LOG_COLOR(LOG_COLOR_CYAN)
#define LOG_COLOR_D
#define LOG_COLOR_V

#define LOG_FORMAT(letter, format)                   \
    LOG_COLOR_##letter "............ [APP] " #letter \
                       "/%s: " format LOG_RESET_COLOR "\n"

#define LOGE(tag, format, ...) \
    printf(LOG_FORMAT(E, format), tag, ##__VA_ARGS__);
#define LOGW(tag, format, ...) \
    printf(LOG_FORMAT(W, format), tag, ##__VA_ARGS__);
#define LOGI(tag, format, ...) \
    printf(LOG_FORMAT(I, format), tag, ##__VA_ARGS__);
#define LOGD(tag, format, ...) \
    printf(LOG_FORMAT(D, format), tag, ##__VA_ARGS__);
#define LOGV(tag, format, ...) \
    printf(LOG_FORMAT(D, format), tag, ##__VA_ARGS__);
