#include "SysHelper.h"
#include "Helper.h"
#include "Bitmap.h"
#include "ServerClient.h"
#include "Server.h"

int main(int argc, char** argv)
{
    printf("PID %ld\n", (long)GetPid());

    NetInitServer(argc, argv);

    Halt(3000);

    InitGame();

    while (true)
    {
        FixedTimeStart();

        RenderGame();
        UpdateGame(0.010f);

        FixedTimeEnd();
    }

    return 0;
}
