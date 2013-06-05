#include "MdApi.h"

namespace Pheux { namespace Core {

	static string status(int ret)
	{
		return (ret == 0) ? "Success." : "Fail.";
	}

	MdApi::MdApi(const string& addr, const string& broker, const string& user, const string& passwd, const string& path) 
		: request_id(0)
	{
		proxy = CThostFtdcMdApi::CreateFtdcMdApi(path.c_str());
		address = Converter::StringToCharArray(addr);
		broker_id = Converter::StringToCharArray(broker);
		user_id = Converter::StringToCharArray(user);
		password = Converter::StringToCharArray(passwd);

		logger->information(
			Poco::format("MdApi::MdApi. address=%s, broker_id=%s, user_id=%s", addr, broker, user));
	}

	void MdApi::Init(CThostFtdcMdSpi* spi)
	{
		proxy->RegisterSpi((CThostFtdcMdSpi*)spi);
		proxy->RegisterFront(address);
		proxy->Init();

		logger->information("MdApi::Init.");
	}

	void MdApi::Join()
	{
		proxy->Join();
	}

	void MdApi::Release()
	{
		proxy->Release();
	}

	bool MdApi::ReqUserLogin()
	{
		CThostFtdcReqUserLoginField req;
		memset(&req, 0, sizeof(req));
		strcpy(req.BrokerID, broker_id);
		strcpy(req.UserID, user_id);
		strcpy(req.Password, password);

		int ret = proxy->ReqUserLogin(&req, ++request_id);
		logger->information("MdApi::ReqUserLogin: " + status(ret));

		return (ret == 0);
	}

	bool MdApi::SubscribeMarketData(const vector<string>& insts)
	{
		int size = insts.size();
		char **pinsts = new char*[size];

		for(int i = 0; i < size; i++)
		{
			pinsts[i] = new char[insts[i].size() + 1];
			strcpy(pinsts[i], insts[i].c_str());
		}

		int ret = proxy->SubscribeMarketData(pinsts, size);
		logger->information("MdApi::SubscribeMarketData: " + status(ret));

		return (ret == 0);
	}
}}