#pragma once

#include <QApplication>

class MainApplication : public QApplication
{
    Q_OBJECT

public:
    MainApplication(int &argc, char **argv, const QString strVersionInfo);


public:
    void changeTranslate(const QString& strLanguageName);
    
signals: 
    void signalLanguageChange();
};
