#include "MainScene.h"
#include <QDebug>
#include <QPrinter>
#include "QPainter"

MainScene::MainScene(QObject *parent)
	: QGraphicsScene(parent)
{
	QColor borderColor("#979797");
	QPen outlinePen;
	outlinePen.setColor(borderColor);
	outlinePen.setWidth(1);


	QRectF lcdRect(m_lcdPosX, m_lcdPosY, m_lcdUnitWidth, m_lcdUnitHeight);
	QGraphicsItem* lcdPart = addLCDPart(lcdRect, m_lcdRows, m_lcdColumns);
	lcdPart->setFlag(QGraphicsItem::ItemIsMovable);

	qreal verticalLCDRectHeight = lcdPart->childrenBoundingRect().height();
	qreal verticalLCDRectWidth = lcdPart->childrenBoundingRect().width();   // LED宽度！
	QRectF verticalLeftLEDRect(m_lcdPosX - (m_ledUnitWidth*m_leftLEDColumns + 2 * m_boardThick), m_lcdPosY, m_ledUnitWidth*m_leftLEDColumns + 2 * m_boardThick, verticalLCDRectHeight);
	// 左边LED 每块LED宽 高
	QGraphicsItem* verticalLeftLEDWithBoard = addVerticalLEDWithBoard(verticalLeftLEDRect, m_leftLEDColumns, true); // 左边LED 每块LED宽60 高40
	verticalLeftLEDWithBoard->setParentItem(lcdPart);

	// 右边LED 每块LED宽 高
	QRectF verticalRightLEDRect(m_lcdPosX + verticalLCDRectWidth, m_lcdPosY, m_ledUnitWidth*m_rightLEDColumns + 2*m_boardThick, verticalLCDRectHeight);
	QGraphicsItem* verticalRightLEDWithBoard = addVerticalLEDWithBoard(verticalRightLEDRect, m_rightLEDColumns, false);
	verticalRightLEDWithBoard->setParentItem(lcdPart);

	// 顶部 每块LED宽 高
	qreal topLEDPartXPos = m_lcdPosX - (m_ledUnitWidth*m_leftLEDColumns + 2 * m_boardThick);
	qreal topLEDPartYPos = m_lcdPosY - m_ledUnitHeight*m_topLEDRows - 2 * m_boardThick;
	qreal topLEDPartWidth = verticalLCDRectWidth + m_ledUnitWidth*(m_leftLEDColumns + m_rightLEDColumns) + 4 * m_boardThick;
	qreal topLEDPartHeight = m_ledUnitHeight*m_topLEDRows + 2 * m_boardThick;
	QRectF horizontalLEDRectf(topLEDPartXPos, topLEDPartYPos, topLEDPartWidth, topLEDPartHeight);
	QGraphicsItem* horizontalRightLEDWithBoard = addHorizontalLEDWithBoard(horizontalLEDRectf, m_topLEDRows, m_ledUnitWidth, m_ledUnitHeight);
	horizontalRightLEDWithBoard->setParentItem(lcdPart);

	// --------------------------------------------下一层

	// 机柜模块
	qreal cabinetXPos = m_lcdPosX - (m_ledUnitWidth*m_leftLEDColumns + 2 * m_boardThick);
	qreal cabinetYPos = m_lcdPosY+m_lcdUnitHeight*m_lcdRows;
	QRectF cabinetPartRect(cabinetXPos, cabinetYPos, verticalLCDRectWidth + m_ledUnitWidth*(m_leftLEDColumns + m_rightLEDColumns) + 4 * m_boardThick, m_cabinetUnitHeight + m_cabinetTopBoardThick + m_cabinetBottomBoardThick);
	addCabinet(cabinetPartRect, m_cabinetUnitWidth, m_cabinetUnitHeight)->setParentItem(lcdPart);
	

	// 左上角LED、LCD尺寸信息模块	
	qreal leftTopInfoWidth = 230;
	qreal leftTopInfoHeight = 84;
	qreal leftTopInfoXPos = m_lcdPosX - (m_ledUnitWidth*m_leftLEDColumns + 2 * m_boardThick) - 30;
	qreal leftTopInfoYPos = m_lcdPosY - m_ledUnitHeight*m_topLEDRows - 2 * m_boardThick - leftTopInfoHeight - 80;

	QRectF leftTopInfoRect(leftTopInfoXPos, leftTopInfoYPos, leftTopInfoWidth, leftTopInfoHeight);
	addLEDAndLCDInfo(leftTopInfoRect)->setParentItem(lcdPart);


	// 右上角信息模块	
	qreal rightTopTextInfoWidth = 193;
	qreal rightTopTextInfoHeight = 84;
	qreal rightTopTextInfoXPos = m_lcdPosX + verticalLCDRectWidth + m_ledUnitWidth + m_rightLEDColumns*m_ledUnitWidth+120;
	qreal rightTopTextInfoYPos = m_lcdPosY - m_ledUnitHeight*m_topLEDRows - 2 * m_boardThick - leftTopInfoHeight - 80;

	QRectF rightTopTextInfoRect(rightTopTextInfoXPos, rightTopTextInfoYPos, rightTopTextInfoWidth, rightTopTextInfoHeight);
	addRightTopTextInfo(rightTopTextInfoRect)->setParentItem(lcdPart);

	//QPrinter printer(QPrinter::HighResolution);
	//printer.setPaperSize(QPrinter::A4);
	//printer.setOutputFormat(QPrinter::PdfFormat);
	//printer.setOutputFileName("C:\\BBBBB.pdf");

	////lcdPart->setRotation(90);
	//QPainter painter(&printer);
	//this->render(&painter);
}

MainScene::~MainScene()
{
	qDebug() << QString("%1  %2 ").arg(this->width()).arg(this->height());
}

/** @fn     void MainScene::setLCDUnit(QRectF rect, int rows, int columns)
 *  @brief  输入LCD行列数 画出rows行columns列
 *  @param  QRectF rect 起始位置
 *  @param  int rows 行
 *  @param  int columns列
 *  @return void
 */
QGraphicsItem* MainScene::addLCDPart(QRectF rect, int rows, int columns)
{
	QRectF lcdRectf(rect.x(), rect.y(), rect.width()*columns, rect.height()*rows);
	QGraphicsItem* LCDPartItem = this->addRect(lcdRectf);
	LCDPartItem->setFlag(QGraphicsItem::ItemIsMovable);
	

	QPen pen("#979797");
	pen.setWidth(0);
	QBrush brush("#F1F1F1");
	QGraphicsItem* LEDUnit;
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			QRectF tempRectf(rect.x() + rect.width()*j, rect.y() + rect.height()*i, rect.width(), rect.height());
			LEDUnit = this->addRect(tempRectf, pen, brush);
			LEDUnit->setParentItem(LCDPartItem);
		}
	}

	return LCDPartItem;
}


/** @fn     QGraphicsItem* MainScene::setVerticalLEDWithBoard(QRectF rect, int ledWidth, int ledHeight)
 *  @brief  垂直LED部分
 *  @param  QRectF rect
 *  @param  int ledColumns LED列数
 *  @param  int ledWidth  LED型号的宽度
 *  @param  int ledHeight LED型号的高度
 *  @return QGraphicsItem*
 */
QGraphicsItem* MainScene::addVerticalLEDWithBoard(QRectF rect, int ledColumns, bool isLeft)
{
	QPen outLinePen("#979797");
	outLinePen.setWidth(0);
	QBrush mainBrush("#BEBEBE");
	// 文本颜色
	QColor textColor("#000000");
	QFont  textFont("Microsoft JhengHei UI", 8, -1, false);

	QGraphicsItem* verticalLEDWithBoard = nullptr;
	verticalLEDWithBoard = this->addRect(rect, outLinePen, mainBrush);
	qreal xPos = rect.x();
	qreal yPos = rect.y();
	qreal width = rect.width();		//verticalLEDWithBoard 模块总宽度
	qreal height = rect.height();	//verticalLEDWithBoard 模块总高度

	// LED
	int ledCount = height / m_ledUnitHeight; //LED个数

	// 添加垂直LED高度刻度表		
	if (ledCount == 0)
	{
	}
	else if (ledCount > 0)
	{
		if (isLeft) // 左边刻度
		{
			QRectF leftLEDHeightScaleRect(xPos - m_boardThick - 8, yPos, 7, ledCount*m_ledUnitHeight);
			addVerticalScaleplate(leftLEDHeightScaleRect)->setParentItem(verticalLEDWithBoard);

			//LED总高度文本
			QString leftText = QString("%1*%2=%3").arg(QString::number(ledCount)).arg(m_ledUnitHeight).arg(QString::number(ledCount*m_ledUnitHeight));
			QGraphicsTextItem* leftTextScalePlate = this->addText(leftText);
			leftTextScalePlate->setPos(xPos - m_boardThick - 26, yPos + ledCount*m_ledUnitHeight / 2 + leftTextScalePlate->boundingRect().width() / 2);
			leftTextScalePlate->setDefaultTextColor(textColor);
			leftTextScalePlate->setParentItem(verticalLEDWithBoard);
			leftTextScalePlate->setFont(textFont);
			leftTextScalePlate->setRotation(-90); // 左转90度
		}
		else        // 右边刻度
		{

		}
	}

	qreal ledXPos = xPos + (width - m_ledUnitWidth*ledColumns) / 2; // 起始LED位置
	for (size_t j = 0; j < ledColumns; ++j)
	{
		for (size_t i = 0; i < ledCount; ++i)
		{
			QRectF ledRectf(ledXPos + m_ledUnitWidth*j, yPos + i*m_ledUnitHeight, m_ledUnitWidth, m_ledUnitHeight);
			QBrush ledBrush("#D8D8D8");
			QGraphicsItem* ledUnit = this->addRect(ledRectf, outLinePen, ledBrush);
			ledUnit->setParentItem(verticalLEDWithBoard);
		}

		qreal margin = height - ledCount*m_ledUnitHeight; // 余量
		QGraphicsItem* marginItem;		            //余量框
		QRectF marginRectf(ledXPos + m_ledUnitWidth*j, yPos + ledCount*m_ledUnitHeight, m_ledUnitWidth, margin);
		marginItem = this->addRect(marginRectf, outLinePen, mainBrush);
		marginItem->setParentItem(verticalLEDWithBoard);
	}
	return verticalLEDWithBoard;
}


/** @fn     QGraphicsItem* MainScene::addHorizontalLEDWithBoard(QRectF rect, int ledWidth, int ledHeight)
 *  @brief  横放LED部分
 *  @param  QRectF rect
 *  @param  int ledWidth
 *  @param  int ledHeight
 *  @return QGraphicsItem*
 */
QGraphicsItem* MainScene::addHorizontalLEDWithBoard(QRectF rect, int topRows, int ledWidth, int ledHeight)
{
	QPen outLinePen("#979797");
	outLinePen.setWidth(1);
	QBrush mainBrush("#BEBEBE");
	QFont  textFont("Microsoft JhengHei UI", 8, -1, false);

	QGraphicsItem* horizontalLEDWithBoard = nullptr;
	horizontalLEDWithBoard = this->addRect(rect, outLinePen, mainBrush);
	qreal xPos = rect.x();
	qreal yPos = rect.y();
	qreal width = rect.width();		//verticalLEDWithBoard 模块总宽度
	qreal height = rect.height();	//verticalLEDWithBoard 模块总高度

	// LED
	int ledCount = width / ledWidth; //每行横放LED个数
	qreal widthMargin = width - ledCount*ledWidth; // 宽度余量
	qreal ledXPos = xPos + widthMargin / 2;
	qreal ledYPos = yPos + (height-ledHeight*topRows)/2;

	for (size_t j = 0; j < topRows; ++j)
	{
		for (size_t i = 0; i < ledCount; ++i)
		{
			QRectF ledRectf(ledXPos + i*ledWidth, ledYPos+j*ledHeight, ledWidth, ledHeight);
			QBrush ledBrush("#D8D8D8");
			QGraphicsItem* ledUnit = this->addRect(ledRectf, outLinePen, ledBrush);
			ledUnit->setParentItem(horizontalLEDWithBoard);
		}

		QGraphicsItem* leftMarginItem;		//左余量框
		QRectF leftMarginRectf(xPos, ledYPos + j*ledHeight, widthMargin / 2, ledHeight);
		leftMarginItem = this->addRect(leftMarginRectf, outLinePen, mainBrush);
		leftMarginItem->setParentItem(horizontalLEDWithBoard);

		QGraphicsItem* rightMarginItem;		//右余量框
		QRectF rightMarginRectf(xPos + width - widthMargin / 2, ledYPos + j*ledHeight, widthMargin / 2, ledHeight);
		rightMarginItem = this->addRect(rightMarginRectf, outLinePen, mainBrush);
		rightMarginItem->setParentItem(horizontalLEDWithBoard);
	}

	// 文本颜色
	QColor textColor("#CCCCCC");
	// 标尺位置
	qreal scalePlateXPos = horizontalLEDWithBoard->boundingRect().x();
	qreal scalePlateYPos = horizontalLEDWithBoard->boundingRect().y() - 30;
	qreal scalePlateWidth = horizontalLEDWithBoard->boundingRect().width();
	qreal scalePlateHeight = horizontalLEDWithBoard->boundingRect().height();
	QRectF scalePlateRect(scalePlateXPos, scalePlateYPos, scalePlateWidth, scalePlateHeight);
	QGraphicsItem* horizontalScaleplateAll = addHorizontalScaleplate(scalePlateRect);
	horizontalScaleplateAll->setParentItem(horizontalLEDWithBoard);
	QString horizontalScaleplateAllWidth = QString::number(ledCount*m_ledUnitWidth + widthMargin);
	QGraphicsTextItem* text1Item = this->addText(horizontalScaleplateAllWidth);
	text1Item->setDefaultTextColor(textColor);
	text1Item->setPos(horizontalScaleplateAll->boundingRect().x() + horizontalScaleplateAll->boundingRect().width() / 2, horizontalScaleplateAll->boundingRect().y() - 15);
	text1Item->setParentItem(horizontalLEDWithBoard);
	text1Item->setFont(textFont);

	// 标尺 减去余量的部分 宽度
	QRectF scalePlateRect2(scalePlateXPos + widthMargin / 2, horizontalLEDWithBoard->boundingRect().y()-10, scalePlateWidth - widthMargin, scalePlateHeight);
	QGraphicsItem* horizontalScaleplate = addHorizontalScaleplate(scalePlateRect2);
	horizontalScaleplate->setParentItem(horizontalLEDWithBoard);
	QString horizontalLEDWidthButMargin;
	horizontalLEDWidthButMargin = QString("%1*%2=%3").arg(QString::number(ledCount)).arg(m_ledUnitWidth).arg(QString::number(ledCount*m_ledUnitWidth));
	QGraphicsTextItem* text2Item = this->addText(horizontalLEDWidthButMargin);
	text2Item->setDefaultTextColor(textColor);
	text2Item->setPos(horizontalScaleplate->boundingRect().x() + horizontalScaleplate->boundingRect().width()/2-15, horizontalScaleplate->boundingRect().y() - 15);
	text2Item->setParentItem(horizontalScaleplate);
	text2Item->setFont(textFont);

	return horizontalLEDWithBoard;
}


/** @fn     QGraphicsItem* MainScene::addCabinet(QRectF rect, int cabinetUnitWidth, int cabinetUnitHeight, int boardThick)
 *  @brief  添加机柜
 *  @param  QRectF rect
 *  @param  int cabinetUnitWidth	机柜宽度
 *  @param  int cabinetUnitHeight   机柜高度
 *  @param  int boardThick			封板厚度
 *  @return QGraphicsItem*
 */
QGraphicsItem* MainScene::addCabinet(QRectF rect, int cabinetUnitWidth, int cabinetUnitHeight)
{
	QPen outLinePen("#979797");
	outLinePen.setWidth(1);
	QBrush mainBrush("#BEBEBE");
	QGraphicsItem* cabinetPart = this->addRect(rect, outLinePen, mainBrush);

	qreal xPos = rect.x();
	qreal yPos = rect.y();
	qreal width = rect.width();
	qreal height = rect.height();

	int cabinetCount = m_lcdColumns;//= width / (cabinetUnitWidth+2*m_cabinetSideBoardThick);   // 能放下的柜子个数
	int margin = width - cabinetCount*(cabinetUnitWidth + 2 * m_cabinetSideBoardThick);// 余量 分成左右柜子

	//柜子上面的封板
	QRectF topBoardRect(xPos, yPos, width, m_cabinetTopBoardThick);
	this->addRect(topBoardRect, outLinePen, mainBrush)->setParentItem(cabinetPart);

	
	for (size_t i = 0; i < cabinetCount; ++i)
	{
		// 柜子左边封板
		qreal leftXPos = xPos + m_boardThick * 2 + m_leftLEDColumns*m_ledUnitWidth;
		QRectF leftRect(leftXPos + i*(cabinetUnitWidth + 2*m_cabinetSideBoardThick), yPos + m_cabinetTopBoardThick, m_cabinetSideBoardThick, height - m_cabinetTopBoardThick);
		this->addRect(leftRect, outLinePen, mainBrush)->setParentItem(cabinetPart);

		// 柜子右边封板
		qreal rightXPos = leftXPos + cabinetUnitWidth + m_cabinetSideBoardThick;
		QRectF rightRect(rightXPos + i*(cabinetUnitWidth + 2 * m_cabinetSideBoardThick), yPos + m_cabinetTopBoardThick, m_cabinetSideBoardThick, height - m_cabinetTopBoardThick);
		this->addRect(rightRect, outLinePen, mainBrush)->setParentItem(cabinetPart);

		// 柜子
		qreal startXPos = leftXPos + m_cabinetSideBoardThick;
		QRectF cabinetRectf(startXPos + i*(cabinetUnitWidth + 2 * m_cabinetSideBoardThick), yPos + m_cabinetTopBoardThick, cabinetUnitWidth, cabinetUnitHeight);
		QBrush cabinetBrush("#FFFFFF");
		QGraphicsItem* cabinetUnit = this->addRect(cabinetRectf, outLinePen, cabinetBrush);
		cabinetUnit->setParentItem(cabinetPart);

		qreal lineX1 = cabinetUnit->boundingRect().x() + cabinetUnitWidth / 2;
		qreal lineY1 = cabinetUnit->boundingRect().y();
		qreal lineX2 = cabinetUnit->boundingRect().x() + cabinetUnitWidth / 2;
		qreal lineY2 = cabinetUnit->boundingRect().y() + cabinetUnitHeight;
		// 门线
		QPen linePen("#979797");
		linePen.setWidth(1);
		QGraphicsItem* doorLineItem = this->addLine(lineX1, lineY1, lineX2, lineY2, linePen);
		doorLineItem->setParentItem(cabinetUnit);

		// 门把手形状
		qreal bashouXPos = cabinetUnit->boundingRect().x() + cabinetUnitWidth / 2 + 5;
		qreal bashouYPos = cabinetUnit->boundingRect().y() + cabinetUnitHeight / 2 - m_bashouHeight/2;

		QPen bashouPen("#000000");
		bashouPen.setWidth(1);
		QBrush bashouBrush("#FFFFEE");
		QGraphicsItem* lashouItem;
		QRectF lashouItemRect(bashouXPos, bashouYPos, m_bashouWidth, m_bashouHeight);
		lashouItem = this->addRect(lashouItemRect, linePen, bashouBrush);
		lashouItem->setParentItem(cabinetUnit);
	}

	return cabinetPart;
}


/** @fn     QGraphicsItem* MainScene::addLEDAndLCDInfo(QRectF rect)
 *  @brief  添加左上角信息
 *  @param  QRectF rect
 *  @return QGraphicsItem*
 */
QGraphicsItem* MainScene::addLEDAndLCDInfo(QRectF rect)
{
	QPen outLinePen("#000000");
	QBrush mainBrush("#FFFFFF");
	QColor textColor("#CCCCCC");
	QFont  textFont("Microsoft JhengHei UI", 8, -1, false);

	QPen mainPen("#FFFFFF");
	QGraphicsItem* LCDAndLEDInfoItem = this->addRect(rect, mainPen);
	qreal xPos = rect.x();
	qreal yPos = rect.y();
	qreal width = rect.width();
	qreal height = rect.height();

	// LED
	QRectF LEDRectf(xPos + 2, yPos + 20, 47, 30);
	QGraphicsItem* LEDInfoItem = this->addRect(LEDRectf, outLinePen, mainBrush);
	LEDInfoItem->setParentItem(LCDAndLEDInfoItem);	
	// LED文本
	QGraphicsTextItem* ledText = addText("LED");
	ledText->setDefaultTextColor(textColor);
	ledText->setPos(xPos - 5, yPos);
	ledText->setParentItem(LCDAndLEDInfoItem);
	ledText->setFont(textFont);
	
	// 添加LED宽度刻度
	QRectF LEDWidthScaleplateRectf(xPos + 2, yPos + 55, 47, 30);
	addHorizontalScaleplate(LEDWidthScaleplateRectf)->setParentItem(LCDAndLEDInfoItem);
	// LED 宽度文本
	QGraphicsTextItem* ledWidthScaleText = addText(QString::number(m_ledUnitWidth));
	ledWidthScaleText->setDefaultTextColor(textColor);
	ledWidthScaleText->setPos(xPos + 15, yPos + 55);
	ledWidthScaleText->setParentItem(LCDAndLEDInfoItem);
	ledWidthScaleText->setFont(textFont);

	// 添加LED高度刻度
	QRectF LEDHeightScaleplateRectf(xPos + 54, yPos + 20, 7, 30);
	addVerticalScaleplate(LEDHeightScaleplateRectf)->setParentItem(LCDAndLEDInfoItem);
	// LED 高度文本
	QGraphicsTextItem* ledHeightScaleText = addText(QString::number(m_ledUnitHeight));
	ledHeightScaleText->setDefaultTextColor(textColor);
	ledHeightScaleText->setPos(xPos + 56, yPos + 25);
	ledHeightScaleText->setParentItem(LCDAndLEDInfoItem);
	ledHeightScaleText->setFont(textFont);


	// LED带脚
	QRectF LEDFootRectf(xPos + 90, yPos + 20, 5, 47);
	this->addRect(LEDFootRectf, outLinePen, mainBrush)->setParentItem(LCDAndLEDInfoItem);
	this->addRect(xPos + 90 + 5, yPos + 20 + 5, 8, 4, outLinePen, mainBrush)->setParentItem(LCDAndLEDInfoItem);
	this->addRect(xPos + 90 + 5, yPos + 20 + 47 - 5 - 4, 8, 4, outLinePen, mainBrush)->setParentItem(LCDAndLEDInfoItem);
	//添加刻度
	QRectF footScalePlate(xPos + 90, yPos + 10, 13, 7);
	addHorizontalScaleplate(footScalePlate)->setParentItem(LCDAndLEDInfoItem);
	//LED厚度文本
	QGraphicsTextItem* footTextScalePlate = this->addText(QString::number(m_ledUnitWidth));
	footTextScalePlate->setPos(xPos + 88, yPos - 10);
	footTextScalePlate->setDefaultTextColor(textColor);
	footTextScalePlate->setParentItem(LCDAndLEDInfoItem);
	footTextScalePlate->setFont(textFont);

	// 平放LED
	QRectF LEDPlateRectf(xPos + 150, yPos + 20, 47, 30);
	this->addRect(LEDPlateRectf, outLinePen, mainBrush)->setParentItem(LCDAndLEDInfoItem);
	QRectF circleRect1(xPos + 150 + 5, yPos + 20 + 5, 3, 3);
	this->addEllipse(circleRect1, outLinePen, mainBrush)->setParentItem(LCDAndLEDInfoItem);
	QRectF circleRect2(xPos + 150 + 5, yPos + 20 + 21, 3, 3);
	this->addEllipse(circleRect2, outLinePen, mainBrush)->setParentItem(LCDAndLEDInfoItem);
	QRectF circleRect3(xPos + 150 + 5 + 33, yPos + 20 + 5, 3, 3);
	this->addEllipse(circleRect3, outLinePen, mainBrush)->setParentItem(LCDAndLEDInfoItem);
	QRectF circleRect4(xPos + 150 + 5 + 33, yPos + 20 + 21, 3, 3);
	this->addEllipse(circleRect4, outLinePen, mainBrush)->setParentItem(LCDAndLEDInfoItem);
	//添加横刻度 
	QRectF pingfangScalePlate(xPos + 150 + 5, yPos + 20 + 35, 35, 7);
	addHorizontalScaleplate(pingfangScalePlate)->setParentItem(LCDAndLEDInfoItem);
	// 底朝天平放 宽度文本 m_ledUnitWidth
	QGraphicsTextItem* pingfangWidthTextItem = this->addText(QString::number(m_ledUnitWidth));
	pingfangWidthTextItem->setPos(xPos + 150 + 5 + 10, yPos + 20 + 35);
	pingfangWidthTextItem->setDefaultTextColor(textColor);
	pingfangWidthTextItem->setParentItem(LCDAndLEDInfoItem);
	pingfangWidthTextItem->setFont(textFont);

	//添加竖刻度 
	QRectF pingfangVerticalScalePlate(xPos + 150 + 52, yPos + 25, 7, 20);
	addVerticalScaleplate(pingfangVerticalScalePlate)->setParentItem(LCDAndLEDInfoItem);
	// 底朝天平放 宽度文本 m_ledUnitWidth
	QGraphicsTextItem* pingfangHeightTextItem = this->addText(QString::number(m_ledUnitHeight));
	pingfangHeightTextItem->setPos(xPos + 150 + 55, yPos + 25);
	pingfangHeightTextItem->setDefaultTextColor(textColor);
	pingfangHeightTextItem->setParentItem(LCDAndLEDInfoItem);
	pingfangHeightTextItem->setFont(textFont);

	// LCD单元尺寸图
	QRectF LCDSizeRectf(xPos + 250, yPos + 20, 47, 30);
	this->addRect(LCDSizeRectf, outLinePen, mainBrush)->setParentItem(LCDAndLEDInfoItem);
	// 添加LCD刻度
	QRectF LCDSizeWidthRectf(xPos + 250, yPos + 55, 47, 7);
	addHorizontalScaleplate(LCDSizeWidthRectf)->setParentItem(LCDAndLEDInfoItem);
	// LCD宽度文本 m_lcdUnitWidth
	QGraphicsTextItem* lcdWidthTextItem = this->addText(QString::number(m_lcdUnitWidth));
	lcdWidthTextItem->setPos(xPos + 250 + 10, yPos + 56);
	lcdWidthTextItem->setDefaultTextColor(textColor);
	lcdWidthTextItem->setParentItem(LCDAndLEDInfoItem);
	lcdWidthTextItem->setFont(textFont);

	// 添加LCD高度量尺
	QRectF LCDSizeHeightRectf(xPos + 250 + 53, yPos + 20, 7, 30);
	addVerticalScaleplate(LCDSizeHeightRectf)->setParentItem(LCDAndLEDInfoItem);
	// 添加LCD高度量尺文本
	QGraphicsTextItem* lcdHeightTextItem = this->addText(QString::number(m_lcdUnitHeight));
	lcdHeightTextItem->setPos(xPos + 250 + 56, yPos + 25);
	lcdHeightTextItem->setDefaultTextColor(textColor);
	lcdHeightTextItem->setParentItem(LCDAndLEDInfoItem);
	lcdHeightTextItem->setFont(textFont);

	return LCDAndLEDInfoItem;
}


/** @fn     QGraphicsItem* MainScene::addRightTopTextInfo(QRectF rect)
 *  @brief  右上角文字信息
 *  @param  QRectF rect
 *  @return QGraphicsItem*
 */
QGraphicsItem* MainScene::addRightTopTextInfo(QRectF rect)
{
	QGraphicsItem* rightTopTextInfoPart = this->addRect(rect);


	return rightTopTextInfoPart;
}


/** @fn     QGraphicsItem* MainScene::addHorizontalScaleplate(QRectF rect)
 *  @brief  添加水平标尺
 *  @param  QRectF rect 添加的位置 长宽信息
 *  @return QGraphicsItem*
 */
QGraphicsItem* MainScene::addHorizontalScaleplate(QRectF rect)
{
	QPen outLinePen("#FFFFFF");
	outLinePen.setWidth(1);
	QBrush mainBrush("#FFFFFF");
	QColor textColor(Qt::darkBlue);

	QGraphicsItem* horizontalScaleplate;
	qreal xPos = rect.x();
	qreal yPos = rect.y();
	qreal width = rect.width();
	qreal height = rect.height();

	horizontalScaleplate = this->addRect(xPos, yPos, width, 7, outLinePen, mainBrush);
	QPen linePen("#CCCCCC");
	// 左刻度
	QGraphicsLineItem* leftLine = addLine(xPos, yPos, xPos, yPos + 7, linePen);
	leftLine->setParentItem(horizontalScaleplate);

	// 右刻度
	QGraphicsLineItem* rightLine = addLine(xPos + width, yPos, xPos+ width, yPos + 7, linePen);
	rightLine->setParentItem(horizontalScaleplate);

	// 中间线
	QGraphicsLineItem* middleLine = addLine(xPos, yPos + 3.5, xPos + width, yPos  + 3.5, linePen);
	middleLine->setParentItem(horizontalScaleplate);


	return horizontalScaleplate;
}


/** @fn     QGraphicsItem* MainScene::addVerticalScaleplate(QRectF rect)
 *  @brief  添加垂直标尺
 *  @param  QRectF rect
 *  @return QGraphicsItem*
 */
QGraphicsItem* MainScene::addVerticalScaleplate(QRectF rect)
{
	QPen outLinePen("#FFFFFF");
	outLinePen.setWidth(1);
	QBrush mainBrush("#FFFFFF");

	QGraphicsItem* verticalScaleplate;
	qreal xPos = rect.x();
	qreal yPos = rect.y();
	qreal width = rect.width();
	qreal height = rect.height();

	verticalScaleplate = this->addRect(xPos, yPos, 7, height, outLinePen, mainBrush);
	QPen linePen("#CCCCCC");
	// 上刻度
	QGraphicsLineItem* leftLine = addLine(xPos, yPos, xPos + 7, yPos, linePen);
	leftLine->setParentItem(verticalScaleplate);

	// 下刻度
	QGraphicsLineItem* rightLine = addLine(xPos, yPos + height, xPos + 7, yPos + height, linePen);
	rightLine->setParentItem(verticalScaleplate);

	// 中间线
	QGraphicsLineItem* middleLine = addLine(xPos + 3.5, yPos, xPos + 3.5, yPos + height, linePen);
	middleLine->setParentItem(verticalScaleplate);

	return verticalScaleplate;
}