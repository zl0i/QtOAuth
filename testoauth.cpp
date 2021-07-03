#include "testoauth.h"



testOAuth::testOAuth(QObject *parent) : QObject(parent)
{

    QFile googleSettingsFile(QDir::currentPath() + "/oauth.google.com.json");
    if (googleSettingsFile.open(QIODevice::ReadOnly)) {

        QJsonDocument googleDoc = QJsonDocument::fromJson(googleSettingsFile.readAll());
        googleSettings = googleDoc.object();

        google->setScope("https://www.googleapis.com/auth/user.emails.read profile");

        connect(google, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
                &QDesktopServices::openUrl);

        google->setAuthorizationUrl(QUrl("https://accounts.google.com/o/oauth2/auth"));
        google->setClientIdentifier(googleSettings.value("installed").toObject().value("client_id").toString());
        google->setAccessTokenUrl(QUrl("https://oauth2.googleapis.com/token"));
        google->setClientIdentifierSharedKey(googleSettings.value("installed").toObject().value("client_secret").toString());


        google->setModifyParametersFunction([](QAbstractOAuth::Stage, QVariantMap *parameters) {
            (*parameters)["access_type"] = "offline";
        });
    }

    QFile vkSettingsFile(QDir::currentPath() + "/oauth.vk.com.json");
    if (vkSettingsFile.open(QIODevice::ReadOnly)) {

        QJsonDocument vkDoc = QJsonDocument::fromJson(vkSettingsFile.readAll());
        vkSettings = vkDoc.object();

        vk->setScope("offline");

        connect(vk, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
                &QDesktopServices::openUrl);

        vk->setAuthorizationUrl(QUrl("https://oauth.vk.com/authorize"));
        vk->setClientIdentifier(vkSettings.value("client_id").toString());
        vk->setAccessTokenUrl(QUrl("https://oauth.vk.com/access_token"));
        vk->setClientIdentifierSharedKey(vkSettings.value("client_secret").toString());

        vk->setModifyParametersFunction([&](QAbstractOAuth::Stage, QVariantMap *parameters) {
            (*parameters)["redirect_uri"] = vkSettings.value("redirect_uris").toArray().at(0).toString();
            (*parameters)["v"] = "5.131";
            (*parameters)["display"] = "page";
            (*parameters)["response_type"] = "code";
        });
    }

    QFile yandexSettingsFile(QDir::currentPath() + "/oauth.yandex.ru.json");
    if (yandexSettingsFile.open(QIODevice::ReadOnly)) {

        QJsonDocument yandexDoc = QJsonDocument::fromJson(yandexSettingsFile.readAll());
        yandexSettings = yandexDoc.object();

        connect(yandex, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
                &QDesktopServices::openUrl);

        yandex->setAuthorizationUrl(QUrl("https://oauth.yandex.ru/authorize"));
        yandex->setClientIdentifier(yandexSettings.value("client_id").toString());
        yandex->setAccessTokenUrl(QUrl("https://oauth2.googleapis.com/token"));
        yandex->setClientIdentifierSharedKey(yandexSettings.value("client_secret").toString());

        yandex->setModifyParametersFunction([&](QAbstractOAuth::Stage, QVariantMap *parameters) {
            (*parameters)["redirect_uri"] = yandexSettings.value("redirect_uris").toArray().at(0).toString();
            (*parameters)["response_type"] = "code";
        });
    }
}

void testOAuth::googleGrant()
{
    google->grant();
}

void testOAuth::vkGrant()
{
    vk->grant();

}

void testOAuth::yandexGrant()
{
    yandex->grant();
}

