#pragma once
#include <assert.h>
#include <stdlib.h>

#pragma once


#include <cctype>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <array>
#include <chrono>
#include <functional>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <system_error>
#include <type_traits>
#include <vector>

#ifdef _WIN32
#  pragma push_macro("WIN32_LEAN_AND_MEAN")
#  pragma push_macro("NOMINMAX")
#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#  endif // WIN32_LEAN_AND_MEAN
#  ifndef NOMINMAX
#    define NOMINMAX
#  endif // NOMINMAX
#  include <winsock2.h>
#  if _WIN32_WINNT < _WIN32_WINNT_WINXP
extern "C" char* _strdup(const char* strSource);
#    define strdup _strdup
#    include <wspiapi.h>
#  endif // _WIN32_WINNT < _WIN32_WINNT_WINXP
#  include <ws2tcpip.h>
#  pragma pop_macro("WIN32_LEAN_AND_MEAN")
#  pragma pop_macro("NOMINMAX")
#else
#  include <errno.h>
#  include <fcntl.h>
#  include <netinet/in.h>
#  include <netdb.h>
#  include <sys/select.h>
#  include <sys/socket.h>
#  include <unistd.h>
#endif // _WIN32

#include <bitset>
#include <string>
#include <vector>
#include <Windows.h>
#include <iostream>
#include <WinInet.h>

#include <iostream>
#include <sstream>

#include <vector>
#include <iomanip>
#include <cstring>
#include <winioctl.h>
#pragma comment(lib, "wininet")

#define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
#define ROTRIGHT(word,bits) (((word) >> (bits)) | ((word) << (32-(bits))))
#define SSIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define SSIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))


template<typename V>
class MemoryValue {
public:
	MemoryValue(bool Allocate = true) {
		if (Allocate)
			memory = (V*)malloc(sizeof(V));
	}
	MemoryValue(V value) {
		memory = (V*)malloc(sizeof(V));
		memcpy(memory, &value, sizeof(V));


	}
	bool HasValue() {
		if (!memory)
			return false;
		return true;
	}
	void GetValue(V* value) {
		memcpy(value, memory, sizeof(V));
	}
	V GetValue() {
		V val;
		GetValue(&val);
		return val;
	}
	void SetValue(V value) {
		free(memory);
		memcpy(memory, &value, sizeof(V));
	}
	void DeAllocate() {
		free(memory);
	}
	void Clear() {
		free(memory);
	}
	void Allocate() {
		memory = (V*)malloc(sizeof(V));
	}
	void Delete() {
		free(memory);
		delete memory;
	}
private:

	V* memory;
};

class MemoryManager_t {
public:
	template<typename T>
	void GeneratePointer(MemoryValue<T>* ReturnF) {
		*ReturnF = MemoryValue<T>();
	}
	template<typename T>
	void Generate(MemoryValue<T>& ReturnF) {
		ReturnF = MemoryValue<T>();
	}
	template<typename T>
	MemoryValue<T>* GeneratePointer() {
		return new MemoryValue<T>();

	}
	template<typename T>
	MemoryValue<T>* GeneratePointer(T value) {
		return new MemoryValue<T>(value);

	}
	template<typename T>
	MemoryValue<T> Generate() {
		return MemoryValue<T>();

	}
	template<typename T>
	MemoryValue<T> Generate(T value) {
		return MemoryValue<T>(value);

	}
	template<typename T>
	void ReAllocate(MemoryValue<T>& Block) {
		Block.Allocate();
	}
	template<typename T>
	void Restore(MemoryValue<T>& Block) {
		Block = MemoryValue<T>();
	}
	template<typename T>
	void ReAllocatePointer(MemoryValue<T>* Block) {
		Block->Allocate();
	}

	template<typename T>
	void RestorePointer(MemoryValue<T>* Block) {
		Block = new MemoryValue<T>();
	}
	template<typename T>
	void DeAllocate(MemoryValue<T>& Block) {
		Block.Delete();
	}
	template<typename T>
	void DeAllocatePointer(MemoryValue<T>* Block) {
		Block->Delete();
	}
	template<typename T>
	void GeneratePointer(MemoryValue<T>* ReturnF, T value) {
		*ReturnF = MemoryValue<T>(value);
	}
	template<typename T>
	void Generate(MemoryValue<T>& ReturnF, T value) {
		ReturnF = MemoryValue<T>(value);
	}
	template<typename T>
	MemoryValue<T> Allocate() {
		return MemoryValue<T>();

	}
	template<typename T>
	MemoryValue<T> Allocate(T value) {
		return MemoryValue<T>(value);

	}
	template<typename T>
	MemoryValue<T>* AllocatePointer() {
		return new MemoryValue<T>();

	}
	template<typename T>
	MemoryValue<T>* AllocatePointer(T value) {
		return new MemoryValue<T>(value);

	}
	template<typename T>
	void AllocatePointer(MemoryValue<T>* ReturnF, T value) {
		*ReturnF = MemoryValue<T>(value);
	}
	template<typename T>
	void Allocate(MemoryValue<T>& ReturnF, T value) {
		ReturnF = MemoryValue<T>(value);
	}
	template<typename T>
	void AllocatePointer(MemoryValue<T>* ReturnF) {
		*ReturnF = MemoryValue<T>();
	}
	template<typename T>
	void Allocate(MemoryValue<T>& ReturnF) {
		ReturnF = MemoryValue<T>();
	}
	template<typename T>
	T GetValue(MemoryValue<T>& PF) {
		T val;
		PF.GetValue(&val);
		return val;
	}
	template<typename T>
	void SetValue(MemoryValue<T>& PF, T value) {
	
		PF.SetValue(value);

	}

	template<typename T>
	T GetPointerValue(MemoryValue<T>* PF) {
		T val;
		PF->GetValue(&val);
		return val;
	}
	template<typename T>
	void SetPointerValue(MemoryValue<T>* PF, T value) {

		PF->SetValue(value);
	
	}
	
};

class security_t {
public:


	std::string GetWindowsUID() {
		HW_PROFILE_INFO hwProfileInfo;
		if (GetCurrentHwProfile(&hwProfileInfo)) {
			WCHAR* GUID_ = hwProfileInfo.szHwProfileGuid;
			std::wstring GUIDWS(GUID_);
			std::string HWID(GUIDWS.begin(), GUIDWS.end());
			return HWID;
		}

		return nullptr;

	}

	std::string GetPhysicalHWID()
	{
		std::string m_sResult;

		HANDLE m_hFile = CreateFileW(L"\\\\.\\PhysicalDrive0", 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
		if (m_hFile == INVALID_HANDLE_VALUE)
			return { };

		std::unique_ptr< std::remove_pointer <HANDLE >::type, void(*)(HANDLE) > m_hDevice
		{
			m_hFile, [](HANDLE handle)
			{
				CloseHandle(handle);
			}
		};

		STORAGE_PROPERTY_QUERY m_PropertyQuery;
		m_PropertyQuery.PropertyId = StorageDeviceProperty;
		m_PropertyQuery.QueryType = PropertyStandardQuery;

		STORAGE_DESCRIPTOR_HEADER m_DescHeader;
		DWORD m_dwBytesReturned = 0;
		if (!DeviceIoControl(m_hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &m_PropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
			&m_DescHeader, sizeof(STORAGE_DESCRIPTOR_HEADER), &m_dwBytesReturned, NULL))
			return { };

		const DWORD m_dwOutBufferSize = m_DescHeader.Size;
		std::unique_ptr< BYTE[] > m_pOutBuffer{ new BYTE[m_dwOutBufferSize] { } };

		if (!DeviceIoControl(m_hDevice.get(), IOCTL_STORAGE_QUERY_PROPERTY, &m_PropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
			m_pOutBuffer.get(), m_dwOutBufferSize, &m_dwBytesReturned, NULL))
			return { };

		STORAGE_DEVICE_DESCRIPTOR* m_pDeviceDescriptor = reinterpret_cast<STORAGE_DEVICE_DESCRIPTOR*>(m_pOutBuffer.get());
		const DWORD m_dwSerialNumberOffset = m_pDeviceDescriptor->SerialNumberOffset;
		if (m_dwSerialNumberOffset == 0)
			return { };

		m_sResult = reinterpret_cast<const char*>(m_pOutBuffer.get() + m_dwSerialNumberOffset);
		m_sResult.erase(std::remove_if(m_sResult.begin(), m_sResult.end(), std::isspace), m_sResult.end());

		return m_sResult;
	}


	

	std::string CHash(std::string in) {
		std::vector<unsigned long> block;
		block =ConvertToBinary(in);
		block =PadTo512Bit(block);
		block = RBST2(block);
		return CHSTR2(block);
	}


	private:
		std::vector<unsigned long> RBST2(std::vector<unsigned long> input)
		{
			std::vector<unsigned long> output(16);

			for (int i = 0; i < 64; i = i + 4)
			{

				std::bitset<32> temp(0);


				temp = (unsigned long)input[i] << 24;
				temp |= (unsigned long)input[i + 1] << 16;
				temp |= (unsigned long)input[i + 2] << 8;
				temp |= (unsigned long)input[i + 3];


				output[i / 4] = temp.to_ulong();
			}

			return output;
		}
		std::string CHSTR2(const std::vector<unsigned long> block)
		{

			unsigned long k[64] = {
				0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,
				0x923f82a4,0xab1c5ed5,0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,
				0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,0xe49b69c1,0xefbe4786,
				0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
				0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,
				0x06ca6351,0x14292967,0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,
				0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,0xa2bfe8a1,0xa81a664b,
				0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
				0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,
				0x5b9cca4f,0x682e6ff3,0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,
				0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
			};

			unsigned long static H0 = 0x6a09e667;
			unsigned long static H1 = 0xbb67ae85;
			unsigned long static H2 = 0x3c6ef372;
			unsigned long static H3 = 0xa54ff53a;
			unsigned long static H4 = 0x510e527f;
			unsigned long static H5 = 0x9b05688c;
			unsigned long static H6 = 0x1f83d9ab;
			unsigned long static H7 = 0x5be0cd19;

			unsigned long W[64];

			for (int t = 0; t <= 15; t++)
			{
				W[t] = block[t] & 0xFFFFFFFF;


			}

			for (int t = 16; t <= 63; t++)
			{

				W[t] = SSIG1(W[t - 2]) + W[t - 7] + SSIG0(W[t - 15]) + W[t - 16];


				W[t] = W[t] & 0xFFFFFFFF;


			}

			unsigned long temp1;
			unsigned long temp2;
			unsigned long a = H0;
			unsigned long b = H1;
			unsigned long c = H2;
			unsigned long d = H3;
			unsigned long e = H4;
			unsigned long f = H5;
			unsigned long g = H6;
			unsigned long h = H7;



			for (int t = 0; t < 64; t++)
			{

				temp1 = h + EP1(e) + (((e) & (f)) ^ (~(e) & (g))) + k[t] + W[t];



				temp2 = EP0(a) + (((a) & (b)) ^ ((a) & (c)) ^ ((b) & (c)));


				h = g;
				g = f;
				f = e;
				e = (d + temp1) & 0xFFFFFFFF;
				d = c;
				c = b;
				b = a;
				a = (temp1 + temp2) & 0xFFFFFFFF;



			}


			H0 = (H0 + a) & 0xFFFFFFFF;
			H1 = (H1 + b) & 0xFFFFFFFF;
			H2 = (H2 + c) & 0xFFFFFFFF;
			H3 = (H3 + d) & 0xFFFFFFFF;
			H4 = (H4 + e) & 0xFFFFFFFF;
			H5 = (H5 + f) & 0xFFFFFFFF;
			H6 = (H6 + g) & 0xFFFFFFFF;
			H7 = (H7 + h) & 0xFFFFFFFF;

			return GetHex(H0) + GetHex(H1) + GetHex(H2) +
				GetHex(H3) + GetHex(H4) + GetHex(H5) +
				GetHex(H6) + GetHex(H7);
		}
		LPCWSTR S2LPCWSTR(const std::string& s)
		{
			int len;
			int slength = (int)s.length() + 1;
			len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
			wchar_t* buf = new wchar_t[len];
			MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
			std::wstring r(buf);
			delete[] buf;

			LPCWSTR result = r.c_str();
			return result;
		}
		std::string GetHex(unsigned long input)
		{
			std::bitset<32> bs(input);
			unsigned n = bs.to_ulong();

			std::stringstream sstream;
			sstream << std::hex << std::setw(8) << std::setfill('0') << n;
			std::string temp;
			sstream >> temp;

			return temp;
		}
		std::vector<unsigned long> ConvertToBinary(const std::string input)
		{

			std::vector<unsigned long> block;

			for (int i = 0; i < input.size(); ++i)
			{

				std::bitset<8> b(input.c_str()[i]);
				block.push_back(b.to_ulong());
			}

			return block;
		}
		std::vector<unsigned long> PadTo512Bit(std::vector<unsigned long> block)
		{
			// Variable names as per NIST.

			// l will represent the length of the message in terms of bits, with each
			// block representing one 8 bit ascii character.
			int l = block.size() * 8;

			// Equation for padding is l + 1 + k = 448 mod 512
			// Simplified to: l + 1 + k = 448
			//		  448 - 1 - l = k
			//		  447 - l = k
			// l = length of message in bits
			// k = how much zero's to add so new message will be a multiple of 512.
			int k = 447 - l;

			// First add in another 8 bit block with the first bit set to 1


			unsigned long t1 = 0x80;
			block.push_back(t1);


			k = k - 7;




			for (int i = 0; i < k / 8; i++)
				block.push_back(0x00000000);

			std::bitset<64> big_64bit_blob(l);



			std::string big_64bit_string = big_64bit_blob.to_string();


			std::bitset<8> temp_string_holder1(big_64bit_string.substr(0, 8));
			block.push_back(temp_string_holder1.to_ulong());


			for (int i = 8; i < 63; i = i + 8)
			{
				std::bitset<8> temp_string_holder2(big_64bit_string.substr(i, 8));
				block.push_back(temp_string_holder2.to_ulong());
			}


			return block;
		}

		std::string utf8_encode(const std::wstring& wstr)
		{
			int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
			std::string strTo(size_needed, 0);
			WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
			return strTo;
		}

		std::string WCHAR2STRING(WCHAR* t) {
			return(utf8_encode(std::wstring((WCHAR*)t)));
		}


};

class math_t {
public:
	float FastSQRT(const float& n)
	{
		float e;
		{
			static union { int i; float f; } u;
			u.i = 0x5F375A86 - (*(int*)&n >> 1);
			e = (int(3) - n * u.f * u.f) * n * u.f * 0.5f;
		}
		return e;
	}
	float AccurateSQRT(const float& n)
	{
		union { int i; float f; } u;
		u.i = 0x1FB5AD00 + (*(int*)&n >> 1);
		u.f = n / u.f + u.f;
		return n / u.f + u.f * 0.25f;
	}
	float SQRT(const float& n)
	{
		static union { int i; float f; } u;
		u.i = 0x2035AD0C + (*(int*)&n >> 1);
		return n / u.f + u.f * 0.25f;
	}
	float Power(const float& n, const float& p)
	{
		float A = n;
		for (int i = 1; i < p; i++) {
			A *= n;
		}
		return A;
	}
	float DefaultSQRT(const float& n) {
		float SquareRoot = 0.0f;
		__asm
		{
			sqrtss xmm0, n
			movss SquareRoot, xmm0
		}
	}

	void DefaultSQRT(const float& n, float& out) {
		__asm
		{
			sqrtss xmm0, n
			movss out, xmm0
		}
	}

};

class HTTPS_T {
public:
	std::string Get(std::string URL) {
		HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
		HINTERNET urlFile;

		std::string rtn;
		std::string rtn2;
		if (interwebs) {
			urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
			if (urlFile) {
				char buffer[2000];
				DWORD bytesRead;
				do {
					InternetReadFile(urlFile, buffer, 2000, &bytesRead);
					rtn.append(buffer, bytesRead);
					memset(buffer, 0, 2000);
				} while (bytesRead);
				InternetCloseHandle(interwebs);
				InternetCloseHandle(urlFile);

			}

		}
		else
		{
			interwebs = InternetOpenA("Mozilla/4.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
			if (interwebs) {
				urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
				if (urlFile) {
					char buffer[2000];
					DWORD bytesRead;
					do {
						InternetReadFile(urlFile, buffer, 2000, &bytesRead);
						rtn.append(buffer, bytesRead);
						memset(buffer, 0, 2000);
					} while (bytesRead);
					InternetCloseHandle(interwebs);
					InternetCloseHandle(urlFile);
					//std::string p = replaceAll(rtn, "|n", "\n");
					//return p;
				}

			}

		}
		InternetCloseHandle(interwebs);
		rtn2 = Replace(rtn, "|n", "\n");
		return rtn2;
	}
private:
	std::string Replace(std::string subject, const std::string& search,
		const std::string& replace) {
		size_t pos = 0;
		while ((pos = subject.find(search, pos)) != std::string::npos) {
			subject.replace(pos, search.length(), replace);
			pos += replace.length();
		}
		return subject;
	}
};

class util_t {
public:
	LPCWSTR StringToLPCWSTR(const std::string& s)
	{
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
		std::wstring r(buf);
		delete[] buf;

		LPCWSTR result = r.c_str();
		return result;
	}
	std::string GetHex(unsigned long input)
	{
		std::bitset<32> bs(input);
		unsigned n = bs.to_ulong();

		std::stringstream sstream;
		sstream << std::hex << std::setw(8) << std::setfill('0') << n;
		std::string temp;
		sstream >> temp;

		return temp;
	}
	std::vector<unsigned long> ConvertToBinary(const std::string input)
	{

		std::vector<unsigned long> block;

		for (int i = 0; i < input.size(); ++i)
		{

			std::bitset<8> b(input.c_str()[i]);
			block.push_back(b.to_ulong());
		}

		return block;
	}
	

	

	std::string WCharToString(WCHAR* t) {
		return(utf8_encode(std::wstring((WCHAR*)t)));
	}
private:
	std::string utf8_encode(const std::wstring& wstr)
	{
		int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
		std::string strTo(size_needed, 0);
		WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
		return strTo;
	}
};



struct {
	security_t* Security = new security_t();
	HTTPS_T* Network = new HTTPS_T();
	math_t* Math = new math_t();
	util_t* Utils = new util_t();
	MemoryManager_t* MemoryManager = new MemoryManager_t();
}interfaces;







