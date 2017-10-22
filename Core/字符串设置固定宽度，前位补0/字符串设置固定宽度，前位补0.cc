    QString str= QString::number(12);
    //10进制数 12  4位  前位补0  strNew = "0012"
    QString strNew = QString("%1").arg(str.toInt(), 4, 10, QLatin1Char('0'));