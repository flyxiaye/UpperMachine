
// UpperDlg.h: 头文件
//

#pragma once


// CUpperDlg 对话框
class CUpperDlg : public CDialogEx
{
	// 构造
public:
	CUpperDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UPPER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CStatic m_jzmPicture;
public:
//	afx_msg void OnBnClickedButton1();
private:
	CString m_folder_path;
public:
//	afx_msg void OnBnClickedButton2();
private:
	CListBox m_listBox;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnLbnSelchangeList4();

public:
	BITMAP m_image;

	afx_msg void OnBnClickedButton4();
};
