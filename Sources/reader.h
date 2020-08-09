#pragma once

#include <winsock2.h>
#include <Windows.h>

#include <memory>
#include <string>

class Reader {
protected:
	HANDLE _handle_disk = INVALID_HANDLE_VALUE;

	BYTE _boot_record[512] = { 0 };

	DWORD64 _current_position = 0;

public:
	explicit Reader(std::wstring volume_name);
	~Reader();

	HANDLE handle() const { return _handle_disk; }

	bool seek(ULONG64 position);

	bool read(LPVOID lpBuffer, ULONG32 nNumberOfBytesToRead);
};