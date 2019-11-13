#include "pch.h"
#include "FileInfo.h"
#include <iostream>
using std::cout;
using std::endl;

FileInfo::FileInfo(string path)
{
	this->path = path;
	hFile = 0;
}

FileInfo::FileInfo(const char* path)
{
	this->path = string(path);
	hFile = 0;
}

FileInfo::FileInfo(CString path)
{
	CStringA tmp;
	tmp = path;
	this->path = string(tmp.GetBuffer());
}

void FileInfo::setPath(CString path)
{
	CStringA tmp;
	tmp = path;
	this->path = string(tmp.GetBuffer());
}

void FileInfo::searchFile(std::vector<CString>& vec)
{
	
	struct _finddata_t fileInfo;
	string pathName;
	if ((hFile = _findfirst(pathName.assign(path).append("\\*").c_str(), &fileInfo)) == -1)
		return;
	do {
		if (!strcmp(fileInfo.name, "..") || !strcmp(fileInfo.name, ".") || fileInfo.attrib == _A_SUBDIR)
			;
		else
			vec.push_back(CString(fileInfo.name));
		//if (strcmp(fileInfo.name, "..") && strcmp(fileInfo.name, ".") && fileInfo.attrib == _A_SUBDIR)
		//	fileSearch(path + "\\" + fileInfo.name);
	} while (_findnext(hFile, &fileInfo) == 0);

	_findclose(hFile);
	return;
}

TextInfo::TextInfo(string filePath)
{
	this->filePath = filePath;
	fs.open(this->filePath);
}

TextInfo::TextInfo(const char* filePath)
{
	this->filePath = string(filePath);
	fs.open(this->filePath);
}

TextInfo::TextInfo(CString filePath)
{
	CStringA tmp;
	tmp = filePath;
	this->filePath = string(tmp.GetBuffer());
	fs.open(this->filePath);
}

TextInfo::TextInfo(string folderPath, string fileName)
{
	this->filePath = folderPath + "\\" + fileName;
	fs.open(this->filePath);
}

TextInfo::~TextInfo()
{
	fs.close();
}

void TextInfo::TextWriter(const CString& buff)
{
	fs << buff << endl;
}

CString& TextInfo::TextReader()
{
	string tmp;
	fs >> tmp;
	return CString(tmp.c_str());
}
