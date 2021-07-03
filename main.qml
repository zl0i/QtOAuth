import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.0

ApplicationWindow {
    width: 400
    height: 640
    visible: true
    title: qsTr("OAuth 2.0")

    Column {
        x: parent.width/2 - width/2
        y: 50
        spacing: 25

        OAuthLogin {
            icon: "qrc:/icons/google.svg"
            text: qsTr("Войти с помощью Google")
            onLogin: _auth.googleGrant()
        }

        OAuthLogin {
            icon: "qrc:/icons/vk.svg"
            text: qsTr("Войти с помощью ВКонтакте")
            onLogin: _auth.vkGrant()
        }

        OAuthLogin {
            icon: "qrc:/icons/yandex.svg"
            text: qsTr("Войти с помощью Яндекс")
            onLogin: _auth.yandexGrant()
        }

    }
}
