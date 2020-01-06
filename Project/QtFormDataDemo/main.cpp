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
		QHttpPart imagePart;
		QFileInfo filInfo(filePathIter);
		QFile file(filePathIter);
		if (!file.open(QIODevice::ReadOnly))
		{
			continue;
		}

		imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"params\"; filename=\"%1\"").arg(filInfo.fileName())));
		imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/png"));

		const auto& data = file.readAll();
		imagePart.setBody(data);
		imagePart.setHeader(QNetworkRequest::ContentLengthHeader, QVariant(data.size()));
		multiPart->append(imagePart);
	}

	QUrl url("http://www.csu.edu.cn");
	QNetworkRequest request(url);
	QNetworkAccessManager manager;
	//QNetworkReply *reply = manager.post(request, multiPart);
	QNetworkReply *reply = manager.get(request);
	multiPart->setParent(reply); // delete the multiPart with the reply

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
