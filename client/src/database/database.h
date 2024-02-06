#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

#include "totaltime/plantime.h"
#include <QVector>
#include <QNetworkAccessManager>

class Database : public QObject
{
    Q_OBJECT

public:
    static Database *instance();
    void init(QString host, int port);
    QVector<PlanTime*> getTotaTimeList();
    void login(QString login, QString password);

public slots:

signals:
    void logged(bool, QString);


private:
     explicit Database();

    QNetworkAccessManager m_manager;
    QUrl m_serverUrl;

    QString m_token;
    QString m_refreshToken;
    int baseId;

    void setHeaders(QNetworkRequest &request);
};

#endif // DATABASE_H
