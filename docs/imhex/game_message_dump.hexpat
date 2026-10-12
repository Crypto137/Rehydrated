struct GameMessageInfo
{
    be u32 eMessageType;
    be u32 pTypeDescriptor;
    be u32 dwSize;
    be u32 pszMessageLabel;
};

struct GameMessageDump
{
    le u32 numGameMessages;
    GameMessageInfo gameMessages[numGameMessages];
};

GameMessageDump dump @ 0x00;