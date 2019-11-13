#pragma once


// CDialogPath 对话框

class CDialogPath : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogPath)

public:
	CDialogPath(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogPath();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PATH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_folder_path;
public:
	void setPath(CString path);
	CString getPath();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
};
