#if defined(_WIN64)
    #include "SysNetWin.c"
#elif defined(__unix)
    #include "SysNetLinux.c"
#else
    #error "SysNet not supported"
#endif

struct NetInput
{
    bool w, a, s, d;
    bool up, left, down, right;
    bool q, e;
};

static bool NetInitServerCalled = false;
static void NetInitServer()
{
    if (NetInitServerCalled) return;
        NetInitServerCalled = true;

    NetUsePort(27015);
}
void NetSendFrame(uint64_t* addr, char* frame)
{
    NetInitServer();
    int messageSize = 1024;
    NetSend(addr, frame, &messageSize);
}
bool NetRecvInput(uint64_t* addr, NetInput* input)
{
    NetInitServer();

    char buffer[1024];
    int messageSize = 0;

    NetRecv(addr, buffer, &messageSize);

    if (messageSize < 0) return false;

    *input = {};

    uint8_t byte1 = ((uint8_t*)buffer)[0];
    uint8_t byte2 = ((uint8_t*)buffer)[1];

    input->w     = (1 << 7 & byte1) != 0;
    input->a     = (1 << 6 & byte1) != 0;
    input->s     = (1 << 5 & byte1) != 0;
    input->d     = (1 << 4 & byte1) != 0;
    input->up    = (1 << 3 & byte1) != 0;
    input->left  = (1 << 2 & byte1) != 0;
    input->down  = (1 << 1 & byte1) != 0;
    input->right = (1 << 0 & byte1) != 0;

    input->q  = (1 << 7 & byte2) != 0;
    input->e  = (1 << 6 & byte2) != 0;

    return true;
}

static bool NetInitClientCalled = false;
static void NetInitClient()
{
    if (NetInitClientCalled) return;
        NetInitClientCalled = true;

    NetUseAnyPort();
    // NetUsePort(27016);
}
bool NetRecvFrame(char* frame)
{
    NetInitClient();

    int messageSize = 0;

    uint64_t addr;

    NetRecv(&addr, frame, &messageSize);

    if (messageSize < 0) return false;

    return true;
}
void NetSendInput(NetInput* input)
{
    NetInitClient();

    uint8_t bytes[2] = {};
    // uint8_t message2 = 0;

    if (input->w)     bytes[0] += 128;
    if (input->a)     bytes[0] +=  64;
    if (input->s)     bytes[0] +=  32;
    if (input->d)     bytes[0] +=  16;
    if (input->up)    bytes[0] +=   8;
    if (input->left)  bytes[0] +=   4;
    if (input->down)  bytes[0] +=   2;
    if (input->right) bytes[0] +=   1;

    if (input->q)     bytes[1] +=  128;
    if (input->e)     bytes[1] +=   64;

    // if (input->w) message += 2;
    // if (input->a) message += 1;

    // TODO
    // uint64_t addr = NetCreateAddr(127, 0, 0, 1, 27015);
    // uint64_t addr = NetCreateAddr(89, 28, 87, 65, 27015);     // machine2
    uint64_t addr = NetCreateAddr(20, 215, 34, 35, 27015);    // azure
    // uint64_t addr = NetCreateAddr(168, 100, 238, 173, 27015); // shells

    int messageSize = 2;

    NetSend(&addr, (char*)&bytes, &messageSize);
}
