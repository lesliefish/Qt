    QString str= QString::number(17);
    //10进制数 17  4位  前位补0  strNew = "0017"
    QString strNew = QString("%1").arg(str.toInt(), 4, 10, QLatin1Char('0'));
	
	QString strNew16 = QString("%1").arg(str.toInt(), 4, 16, QLatin1Char('0'));