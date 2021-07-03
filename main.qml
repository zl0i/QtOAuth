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

        Row {
            height: 50
            spacing: 10
            Label {
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 16
                color: "#1A1A1A"
                text: qsTr("Войти с помощью Google")
            }
            Rectangle {
                width: 50
                height: 50
                radius: 25
                color: "#FFFFFF"
                Image {
                    anchors { fill: parent; margins: 7 }
                    fillMode: Image.PreserveAspectFit
                    antialiasing: true
                    mipmap: true
                    smooth: true
                    source: "qrc:/icons/google.svg"
                }
                MouseArea {
                    id: _googleMouseArea
                    anchors.fill: parent
                    onClicked: _auth.googleGrant()
                }
                layer.enabled: true
                layer.effect: DropShadow {
                    radius: _googleMouseArea.pressed ? 6 : 8
                    samples: 16
                    color: "#80000000"
                }
            }
        }

        Row {
            height: 50
            spacing: 10
            Label {
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 16
                color: "#1A1A1A"
                text: qsTr("Войти с помощью ВКонтакте")
            }
            Rectangle {
                width: 50
                height: 50
                radius: 25
                color: "#FFFFFF"
                Image {
                    anchors { fill: parent; margins: 10 }
                    fillMode: Image.PreserveAspectFit
                    antialiasing: true
                    mipmap: true
                    smooth: true
                    source: "qrc:/icons/vk.svg"
                }
                MouseArea {
                    id: _vkMouseArea
                    anchors.fill: parent
                    onClicked: _auth.vkGrant()
                }
                layer.enabled: true
                layer.effect: DropShadow {
                    radius: _vkMouseArea.pressed ? 6 : 8
                    samples: 16
                    color: "#80000000"
                }
            }
        }

        Row {
            height: 50
            spacing: 10
            Label {
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 16
                color: "#1A1A1A"
                text: qsTr("Войти с помощью Яндекс")
            }
            Rectangle {
                width: 50
                height: 50
                radius: 25
                color: "#FFFFFF"
                Image {
                    anchors { fill: parent; margins: 10 }
                    fillMode: Image.PreserveAspectFit
                    antialiasing: true
                    mipmap: true
                    smooth: true
                    source: "qrc:/icons/yandex.svg"
                }
                MouseArea {
                    id: _yandexMouseArea
                    anchors.fill: parent
                    onClicked: _auth.yandexGrant()
                }
                layer.enabled: true
                layer.effect: DropShadow {
                    radius: _yandexMouseArea.pressed ? 6 : 8
                    samples: 16
                    color: "#80000000"
                }
            }
        }
    }
}
