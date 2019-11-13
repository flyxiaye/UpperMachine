
// ExpForViewView.cpp: CExpForViewView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ExpForView.h"
#endif

#include "ExpForViewDoc.h"
#include "ExpForViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExpForViewView

IMPLEMENT_DYNCREATE(CExpForViewView, CView)

BEGIN_MESSAGE_MAP(CExpForViewView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CExpForViewView 构造/析构

CExpForViewView::CExpForViewView() noexcept
{
	// TODO: 在此处添加构造代码

}

CExpForViewView::~CExpForViewView()
{
}

BOOL CExpForViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExpForViewView 绘图

void CExpForViewView::OnDraw(CDC* /*pDC*/)
{
	CExpForViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExpForViewView 打印

BOOL CExpForViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExpForViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExpForViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExpForViewView 诊断

#ifdef _DEBUG
void CExpForViewView::AssertValid() const
{
	CView::AssertValid();
}

void CExpForViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExpForViewDoc* CExpForViewView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExpForViewDoc)));
	return (CExpForViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CExpForViewView 消息处理程序
