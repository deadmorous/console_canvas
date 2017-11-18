// defs.h

#ifndef DEFS_H
#define DEFS_H

#if defined(_WIN32) && defined(_MSC_VER)

#ifdef console_canvas_EXPORTS
#define CONSOLE_CANVAS_API __declspec(dllexport)
#else // ode_num_int_EXPORTS
#define CONSOLE_CANVAS_API __declspec(dllimport)
#endif // ode_num_int_EXPORTS
#else // defined(_WIN32) && defined(_MSC_VER)
#define CONSOLE_CANVAS_API
#endif // defined(_WIN32) && defined(_MSC_VER)

#endif // DEFS_H
