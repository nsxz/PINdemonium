#pragma once

#include "WriteInterval.h"
#include "pin.H"
#include "Debug.h"
#include "Config.h"
#include "ProcInfo.h"

class WxorXHandler
{
public:
	//singleton instance
	static WxorXHandler* getInstance();
	//distruptor
	~WxorXHandler(void);
	//check if the current instruction is a write operation
	BOOL isWriteINS(INS ins);
	//manage the write set that contains the WriteInterval written by the program
	VOID writeSetManager(ADDRINT start_addr, UINT32 size);
	//check if the W xor X law is broken
	WriteInterval* getWxorXinterval(ADDRINT ip);

	//manage the write set that contains the WriteInterval written by the program and injected in another process
	VOID writeSetManager(ADDRINT start_addr, UINT32 size, W::DWORD pid);
	//check if the W xor X law is broken inside injected process
	WriteInterval* getWxorXinterval(ADDRINT ip, W::DWORD pid);
	VOID displayWriteSet();
	VOID incrementCurrJMPNumber(int writeItemIndex);
	

private: 
	map<W::DWORD, std::vector<WriteInterval>> WriteSetContainer;
	
	VOID _writeSetManager( ADDRINT start_addr, UINT32 size,std::vector<WriteInterval> &currentWriteSet);
	WriteInterval* _getWxorXinterval(ADDRINT ip,std::vector<WriteInterval> &currentWriteSet);
	
	//std::vector<WriteInterval> WritesSet;
	 static WxorXHandler* instance;
	 WxorXHandler();
	 W::DWORD pid;

};

