
// UpperMachineView.cpp: CUpperMachineView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "UpperMachine.h"
#endif

#include "UpperMachineDoc.h"
#include "UpperMachineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUpperMachineView

IMPLEMENT_DYNCREATE(CUpperMachineView, CView)

BEGIN_MESSAGE_MAP(CUpperMachineView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CUpperMachineView 构造/析构

CUpperMachineView::CUpperMachineView() noexcept
{
	// TODO: 在此处添加构造代码

}

CUpperMachineView::~CUpperMachineView()
{
}

BOOL CUpperMachineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUpperMachineView 绘图

void CUpperMachineView::OnDraw(CDC* /*pDC*/)
{
	CUpperMachineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CUpperMachineView 打印

BOOL CUpperMachineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CUpperMachineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CUpperMachineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CUpperMachineView 诊断

#ifdef _DEBUG
void CUpperMachineView::AssertValid() const
{
	CView::AssertValid();
}

void CUpperMachineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUpperMachineDoc* CUpperMachineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUpperMachineDoc)));
	return (CUpperMachineDoc*)m_pDocument;
}
#endif //_DEBUG


// CUpperMachineView 消息处理程序
