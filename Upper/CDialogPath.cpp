// CDialogPath.cpp: 实现文件
//

#include "pch.h"
#include "Upper.h"
#include "CDialogPath.h"
#include "afxdialogex.h"


// CDialogPath 对话框

IMPLEMENT_DYNAMIC(CDialogPath, CDialogEx)

CDialogPath::CDialogPath(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PATH, pParent)
	, m_folder_path(_T(""))
{

}

CDialogPath::~CDialogPath()
{
}

void CDialogPath::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_folder_path);
}

void CDialogPath::setPath(CString path)
{
	m_folder_path = path;
	//UpdateData(FALSE);
}

CString CDialogPath::getPath()
{
	return m_folder_path;
}


BEGIN_MESSAGE_MAP(CDialogPath, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogPath::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CDialogPath::OnBnClickedButton5)
END_MESSAGE_MAP()


// CDialogPath 消息处理程序


void CDialogPath::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//设置路径
	UpdateData(TRUE);
	OnOK();
}


void CDialogPath::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}
