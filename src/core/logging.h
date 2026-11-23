#pragma once

#include <rex/logging.h>

#define LOG_TRACE(...) REXLOG_TRACE(__VA_ARGS__)
#define LOG_DEBUG(...) REXLOG_DEBUG(__VA_ARGS__)
#define LOG_INFO(...) REXLOG_INFO(__VA_ARGS__)
#define LOG_WARN(...) REXLOG_WARN(__VA_ARGS__)
#define LOG_ERROR(...) REXLOG_ERROR(__VA_ARGS__)
#define LOG_CRITICAL(...) REXLOG_CRITICAL(__VA_ARGS__)
