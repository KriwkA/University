#include "Menu.h"
#include "macro.h"
#include "KeySet.h"

namespace menu
{
    int mainMenu()
    {
        initscr();
        printw("1. Open workers list\n");
        return endwin();
    }
}
