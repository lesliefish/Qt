#include "QQFriendList.h"
#include <QtWidgets/QApplication>

using namespace qqfriendlist;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QQFriendList w;
	w.show();
	return a.exec();
}
