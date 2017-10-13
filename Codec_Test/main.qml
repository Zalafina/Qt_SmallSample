import QtQuick 2.3

Item {
    visible: true
    width: 360
    height: 360

    MouseArea {
        anchors.fill: parent
        onClicked: {
        }
    }

    Text {
        objectName: "qmlTestText"
        id : qml_main_Text
        //text: qsTr("Hello World")
        anchors.centerIn: parent
        font.bold: true
        font.family: "Kristen ITC"
        font.pointSize: 16
    }
}
