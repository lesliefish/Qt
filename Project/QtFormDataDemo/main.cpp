#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include <QHttpMultiPart>
#include <QNetworkAccessManager>
#include <QNetworkReply>

bool requestUploadImages(const QStringList& vsFileList, QString& strResp)
{
	QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
	for (const auto& filePathIter : vsFileList)
	{
		// 多个文件分成多个表单
		QHttpPart imagePart;
		QFileInfo filInfo(filePathIter);
		QFile file(filePathIter);
		if (!file.open(QIODevice::ReadOnly))
		{
			continue;
		}

		//这个根据自己的协议添加对应数据
		imagePart.setHeader(QNetworkRequest::ContentDispositionHeader,
			QVariant(QString("form-data; name=\"uploadfile\"; filename=\"%1\"").arg(filInfo.fileName()))); 
		// 类型 根据自己需要的协议进行定义
		imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/png")); 

		const auto& data = file.readAll();
		imagePart.setBody(data);// 表单body部分填入文件内容
		// 数据长度不加上可能导致失败
		imagePart.setHeader(QNetworkRequest::ContentLengthHeader, QVariant(data.size()));
		multiPart->append(imagePart);
	}

	QUrl url("http://www.csu.edu.cn"); // 测试url 要换成自己实际使用的URI
	QNetworkRequest request(url);
	QNetworkAccessManager manager;
	QNetworkReply *reply = manager.post(request, multiPart);

	multiPart->setParent(reply); // 通过reply删除multiPart对象

	QObject::connect(reply, &QNetworkReply::finished, [&reply, &strResp]
	{
		if (reply->error() == QNetworkReply::NoError)
		{
			strResp = reply->readAll();
			qDebug() << "upload file finished";
		}
		else
		{
			strResp = reply->errorString();
			qDebug() << "error string:" << reply->errorString();
		}
	});

	QEventLoop eventLoop;
	QObject::connect(&manager, &QNetworkAccessManager::finished, [&]
	{
		eventLoop.quit();
	});
	eventLoop.exec();

	reply->deleteLater();

	return true;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QString resp;
	requestUploadImages(QStringList(), resp);
	qDebug() << resp;

	return a.exec();
}
