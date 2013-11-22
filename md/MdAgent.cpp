#include "MdAgent.h"
#include "MdApi.h"
#include "MdSpi.h"

namespace Pheux { namespace Core {

    void MdAgent::Init(const vector<string>& insts)
    {
        api = new MdApi(ADDR_MD, BROKER, USER, PASSWORD);
        spi = new MdSpi(this);

        api->Init(spi);

        for (int i = 0; i < insts.size(); i++)
            instruments.push_back(insts[i]);
    }

    void MdAgent::Join()
    {
        api->Join();
    }

    void MdAgent::Release()
    {
        api->Release();
    }
}}
