#pragma once
#include <io.h>
#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::ifstream;
using std::ofstream;
class FileInfo
{
public:
	FileInfo(string path);
	FileInfo(const char* path);
	FileInfo(CString path);
	void setPath(CString path);
	void searchFile(std::vector<CString> & vec);
private:
	long hFile;
	string path;
};


class TextInfo
{
public:
	TextInfo(string filePath);
	TextInfo(const char* filePath);
	TextInfo(CString filePath);
	TextInfo(string folderPath, string fileName);
	~TextInfo();
	bool IsOpen() { return fs.is_open(); }
	void TextWriter(const CString& buff);
	CString& TextReader();
private:
	std::fstream fs;
	string filePath;
};
