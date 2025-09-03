
# pragma once

/**
 * @file _AnsiColors.hpp
 * @brief Macros to ANSI colors (standard S_, foreground F_, background B_)
 * @note based on ANSI escape codes, see more at https://talyian.github.io/ansicolors/
 * @note to use 256 colors, use F_256(n) and B_256(n), where 0 <= n <= 255,  see more at https://upload.wikimedia.org/wikipedia/commons/1/15/Xterm_256color_chart.svg?utm_source=chatgpt.com
 * @author ivbatist
 * @compat C++98 (only macros and C-string literals)
*/

/** ========================
 *  Reset & basic styles
 * ======================== */
#define RESET            "\x1b[0m"
#define S_BOLD           "\x1b[1m"
#define S_DIM            "\x1b[2m"
#define S_ITALIC         "\x1b[3m"   /* Not all terminals */
#define S_UNDERLINE      "\x1b[4m"
#define S_BLINK          "\x1b[5m"   /* Avoid: could be desabled */
#define S_REVERSE        "\x1b[7m"
#define S_HIDDEN         "\x1b[8m"
#define S_STRIKE         "\x1b[9m"
#define S_RESET_BOLD     "\x1b[22m"
#define S_RESET_ITALIC   "\x1b[23m"
#define S_RESET_UNDER    "\x1b[24m"
#define S_RESET_BLINK    "\x1b[25m"
#define S_RESET_REVERSE  "\x1b[27m"
#define S_RESET_HIDDEN   "\x1b[28m"
#define S_RESET_STRIKE   "\x1b[29m"

/** ========================
 *  Foreground - 8 colors
 * ======================== */
#define F_DEFAULT        "\x1b[39m"
#define F_BLACK          "\x1b[30m"
#define F_RED            "\x1b[31m"
#define F_GREEN          "\x1b[32m"
#define F_YELLOW         "\x1b[33m"
#define F_BLUE           "\x1b[34m"
#define F_MAGENTA        "\x1b[35m"
#define F_CYAN           "\x1b[36m"
#define F_WHITE          "\x1b[37m"

/** ========================
 *  Foreground - 8 high-intensity (bright) colors
 * ======================== */
#define F_BRIGHT_BLACK   "\x1b[90m"
#define F_BRIGHT_RED     "\x1b[91m"
#define F_BRIGHT_GREEN   "\x1b[92m"
#define F_BRIGHT_YELLOW  "\x1b[93m"
#define F_BRIGHT_BLUE    "\x1b[94m"
#define F_BRIGHT_MAGENTA "\x1b[95m"
#define F_BRIGHT_CYAN    "\x1b[96m"
#define F_BRIGHT_WHITE   "\x1b[97m"

/** ========================
 *  Background - 8 colors
 * ======================== */
#define B_DEFAULT        "\x1b[49m"
#define B_BLACK          "\x1b[40m"
#define B_RED            "\x1b[41m"
#define B_GREEN          "\x1b[42m"
#define B_YELLOW         "\x1b[43m"
#define B_BLUE           "\x1b[44m"
#define B_MAGENTA        "\x1b[45m"
#define B_CYAN           "\x1b[46m"
#define B_WHITE          "\x1b[47m"

/** ========================
 *  Background - 8 high-intensity (bright) colors
 * ======================== */
#define B_BRIGHT_BLACK   "\x1b[100m"
#define B_BRIGHT_RED     "\x1b[101m"
#define B_BRIGHT_GREEN   "\x1b[102m"
#define B_BRIGHT_YELLOW  "\x1b[103m"
#define B_BRIGHT_BLUE    "\x1b[104m"
#define B_BRIGHT_MAGENTA "\x1b[105m"
#define B_BRIGHT_CYAN    "\x1b[106m"
#define B_BRIGHT_WHITE   "\x1b[107m"

/** ========================
 *  Paleta 256 colors (xterm)
 *  Use with F_256(n) e B_256(n), 0 <= n <= 255
 * ======================== */
#define _AC_STR_(x) #x
#define _AC_STR(x) _AC_STR_(x)
#define F_256(n) "\x1b[38;5;" _AC_STR(n) "m"
#define B_256(n) "\x1b[48;5;" _AC_STR(n) "m"

/** ========================
 *  Exemplos de uso
 * ========================
 * std::cout << F_GREEN "ok" RESET << std::endl;
 * std::cout << B_BRIGHT_BLUE F_WHITE " title " RESET << " text\n";
 * std::cout << F_256(208) "orange" RESET "\n";
 */

