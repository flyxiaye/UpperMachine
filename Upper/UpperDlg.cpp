
// UpperDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Upper.h"
#include "UpperDlg.h"
#include "afxdialogex.h"
#include "FileInfo.h"
#include <vector>
#include <fstream>
#include <string>
#include "CDialogPath.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PAHT "path.txt"

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CUpperDlg 对话框



CUpperDlg::CUpperDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UPPER_DIALOG, pParent)
	, m_folder_path(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUpperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_jzmPicture);
	//DDX_Text(pDX, IDC_EDIT1, m_folder_path);
	DDX_Control(pDX, IDC_LIST4, m_listBox);
}

BEGIN_MESSAGE_MAP(CUpperDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_BUTTON1, &CUpperDlg::OnBnClickedButton1)
//	ON_BN_CLICKED(IDC_BUTTON2, &CUpperDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CUpperDlg::OnBnClickedButton3)
	ON_LBN_SELCHANGE(IDC_LIST4, &CUpperDlg::OnLbnSelchangeList4)
	ON_BN_CLICKED(IDC_BUTTON4, &CUpperDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CUpperDlg 消息处理程序

BOOL CUpperDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//初始化路径
	ifstream fin(PAHT, std::ios_base::in);
	if (fin.is_open())
	{
		string str;
		fin >> str;
		m_folder_path = CString(str.c_str());
		fin.close();
	}
	UpdateData(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CUpperDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CUpperDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CUpperDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CUpperDlg::OnBnClickedButton1()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	//CBitmap bitmap;
//	HBITMAP hBmp;
//	//bitmap.LoadBitmapW(TEXT("C:\\Users\\ChxxxXL\\source\\repos\\UpperMachine\\Upper\\res\\0000.BMP"));
//	//bitmap.LoadBitmapW(IDB_BITMAP1);
//	//hBmp = (HBITMAP)bitmap.GetSafeHandle();
//	//CString folder_path("C:\\Users\\ChxxxXL\\source\\repos\\UpperMachine\\Upper\\res\\");
//	CString file_name("0000.BMP");
//	/*打开一幅本地图片*/
//	//hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), folder_path + file_name,
//	//	IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
//	/*=============================================================*/
//	if (m_folder_path.IsEmpty())
//	{
//		MessageBox(TEXT("请输入图片路径"));
//		return;
//	}
//	hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), m_folder_path + "\\" + file_name ,
//		IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
//	m_jzmPicture.SetBitmap(hBmp);
//}


//void CUpperDlg::OnBnClickedButton2()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	//路径设置
//	UpdateData(TRUE);
//	if (m_folder_path.IsEmpty())
//	{
//		MessageBox(TEXT("路径不能为空"));
//	}
//	else
//	{
//		MessageBox(TEXT("路径设置成功"));
//	}
//}


void CUpperDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//刷新目录内容
	//读取路径
	using std::vector;
	FileInfo fin(m_folder_path);
	vector<CString> vec;
	fin.searchFile(vec);
	//显示在ListBox中
	m_listBox.ResetContent();
	for (auto it = vec.begin(); it != vec.end(); it++)
		m_listBox.AddString(*it);

}


void CUpperDlg::OnLbnSelchangeList4()
{
	// TODO: 在此添加控件通知处理程序代码
	//列表控件选择触发消息
	int idx = m_listBox.GetCurSel();
	CString fileName;
	m_listBox.GetText(idx, fileName);
	if (!fileName.IsEmpty())
	{
		//打开图片
		HBITMAP hBmp;
		CString filePath = m_folder_path + "\\" + fileName;
		/*========================打开一幅本地图片=====================*/
		//hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), folder_path + file_name,
		//	IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
		/*=============================================================*/
		hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), filePath,
			IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
		m_jzmPicture.SetBitmap(hBmp);
		GetObject(hBmp, sizeof(BITMAP), &m_image);	//获取图像数据
	}
}


void CUpperDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//设置路径
	CDialogPath dlg_path;
	dlg_path.setPath(m_folder_path);
	dlg_path.DoModal();
	m_folder_path = dlg_path.getPath();
	//保存路径
	ofstream fout(PAHT, std::ios_base::out);
	if (fout.is_open())
	{
		CStringA tmp;
		tmp = m_folder_path;
		fout << string(tmp.GetBuffer()) << std::endl;
		fout.close();
	}
}
