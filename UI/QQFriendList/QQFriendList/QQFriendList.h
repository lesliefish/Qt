/** @file    QQFriendList.h
 *  @date    2019/02/04 10:37
 *  @brief   QQ∫√”—¡–±Ì
 *
 *  @author  yu
 *  @contact ylesliefish@gmail.com
 */
 
#pragma once

#include <QtWidgets/QWidget>
#include "ui_QQFriendList.h"

namespace qqfriendlist
{
	class QQFriendList : public QWidget
	{
		Q_OBJECT

	public:
		QQFriendList(QWidget *parent = Q_NULLPTR);

	private:
		Ui::QQFriendListClass ui;
	};

}
