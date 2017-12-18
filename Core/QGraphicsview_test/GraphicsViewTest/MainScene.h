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
	QGraphicsItem* addVerticalLEDWithBoard(QRectF rect, int ledColumns, int ledWidth, int ledHeight);

	// LED带封板 横排
	QGraphicsItem* addHorizontalLEDWithBoard(QRectF rect, int topRows, int ledWidth, int ledHeight);

	QGraphicsItem* addCabinet(QRectF rect, int cabinetUnitWidth, int cabinetUnitHeight, int boardThick);
private:
	QGraphicsEllipseItem* m_ellipse;

	QGraphicsRectItem* m_LEDUnit;   // LED单元
	QGraphicsRectItem* m_LCDUnit;   // LCD单元
	QGraphicsRectItem* m_frontCabinet; // 机柜模型


	// 正视图的LED和LCD部分
	QGraphicsRectItem* m_frontViewLEDAndLCDPart;

	qreal m_bashouHeight = 9;			// 门把手高度
	qreal m_bashouWidth = 4.8;		// 门把手宽度
};

#endif // MAINSCENE_H
