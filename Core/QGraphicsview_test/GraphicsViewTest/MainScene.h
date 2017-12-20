#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class MainScene : public QGraphicsScene
{
	Q_OBJECT

	// 支架基本参数

public:
	MainScene(QObject *parent = nullptr);
	~MainScene();
	// 机柜模型
	void setFrontCabinet(QRectF rect);
	// LED单元
	void setLEDUnit(QRectF rect, int number, bool isVertical);
	// LCD整体项
	QGraphicsItem* addLCDPart(QRectF rect, int rows, int columns);
	// LED带封板 竖排 左
	QGraphicsItem* addVerticalLEDWithBoard(QRectF rect, int ledColumns, bool isLeft);

	// LED带封板 横排
	QGraphicsItem* addHorizontalLEDWithBoard(QRectF rect, int topRows, int ledWidth, int ledHeight);
	
	//  添加机柜
	QGraphicsItem* addCabinet(QRectF rect, int cabinetUnitWidth, int cabinetUnitHeight);

	// 添加左上角LED LCD信息
	QGraphicsItem* addLEDAndLCDInfo(QRectF rect);

	// 添加右上角文字描述信息
	QGraphicsItem* addRightTopTextInfo(QRectF rect);


	// 添加标尺  横向标尺
	QGraphicsItem* addHorizontalScaleplate(QRectF rect);
	
	// 添加标尺  垂直标尺
	QGraphicsItem* addVerticalScaleplate(QRectF rect);
private:
	QGraphicsRectItem* m_LEDUnit;   // LED单元
	QGraphicsRectItem* m_LCDUnit;   // LCD单元
	QGraphicsRectItem* m_frontCabinet; // 机柜模型


	qreal m_bashouHeight = 12;			// 门把手高度
	qreal m_bashouWidth = 4;		// 门把手宽度

	// LCD部分   
	qreal m_lcdPosX = 0;		// LCD左上角起始点位置
	qreal m_lcdPosY = 0;		// LCD左上角起始点y位置
	qreal m_lcdUnitWidth = 100;   // LCD单元宽度
	qreal m_lcdUnitHeight = 50;   // LCD单元高度
	int   m_lcdRows = 2;			// LCD行数
	int   m_lcdColumns = 3;		// LCD列数
	int   m_leftLEDColumns = 1;	// 左边LED列数
	int   m_rightLEDColumns = 2;	// 右边LED列数
	int   m_topLEDRows = 2;		// 顶部LED行数
	qreal m_ledUnitWidth = 25;	// LED宽度
	qreal m_ledUnitHeight = 15;	// LED高度
	qreal m_boardThick = 5;	    // 封板厚度
	qreal m_cabinetUnitWidth = 90;	// 机柜中间单元宽度
	qreal m_cabinetUnitHeight = 45;// 机柜中间单元高度
	qreal m_cabinetTopBoardThick = 5;// 机柜上面封板的厚度
	qreal m_cabinetSideBoardThick = 5;// 机柜之间封板的厚度
	qreal m_cabinetBottomBoardThick = 5;// 机柜底部封板的厚度
};
#endif // MAINSCENE_H
