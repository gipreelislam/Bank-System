#include <iostream>
#include "Screens/clsLoginScreen.h"

int main()
{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }
}