#ifndef TESTOAUTH_H
#define TESTOAUTH_H

#include <QObject>
#include <QtGui>
#include <QtNetworkAuth>
#include <QOAuth2AuthorizationCodeFlow>
#include <QJsonArray>
#include <QJsonObject>


class testOAuth : public QObject
{
    Q_OBJECT
public:

    explicit testOAuth(QObject *parent = nullptr);

private:
    QOAuth2AuthorizationCodeFlow *google = new QOAuth2AuthorizationCodeFlow(this);
    QJsonObject googleSettings;

    QOAuth2AuthorizationCodeFlow *vk = new QOAuth2AuthorizationCodeFlow(this);
    QJsonObject vkSettings;

    QOAuth2AuthorizationCodeFlow *yandex = new QOAuth2AuthorizationCodeFlow(this);
    QJsonObject yandexSettings;

signals:

public slots:
    void googleGrant();
    void vkGrant();
    void yandexGrant();

};

#endif // TESTOAUTH_H
