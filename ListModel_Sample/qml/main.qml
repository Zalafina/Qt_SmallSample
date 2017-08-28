import QtQuick 2.0
//import QtQuick.Window 2.0
import QtQml.Models 2.2

Rectangle {
    visible: true
    height: 480
    width: 320

    Component.onCompleted : {
        console.log("main.qml Completed Running!")
    }

    GridView {
        id: mygridview
        visible: true
        width: 320; height: 480
        cellWidth: 80; cellHeight: 80

        displaced: Transition {
            NumberAnimation { properties: "x,y"; easing.type: Easing.OutQuad }
        }

        model: DelegateModel {
            id: visualModel

//            model: ListModel {
//                id: appModel
//                ListElement { name: "ICON_01"; icon: "pics/AudioPlayer_48.png" }
//                ListElement { name: "ICON_02"; icon: "pics/VideoPlayer_48.png" }
//                ListElement { name: "ICON_03"; icon: "pics/Camera_48.png" }
//                ListElement { name: "ICON_04"; icon: "pics/DateBook_48.png" }
//                ListElement { name: "ICON_05"; icon: "pics/EMail_48.png" }
//                ListElement { name: "ICON_06"; icon: "pics/TodoList_48.png" }
//                ListElement { name: "ICON_07"; icon: "pics/AddressBook_48.png" }
//            }

            model: myModel

            delegate: MouseArea {
                id: delegateRoot

                property int visualIndex: DelegateModel.itemsIndex

                width: 80; height: 80
                drag.target: pngicons

                onClicked: {
                    console.log("VisualIndex" + visualIndex + "Clicked")
                    console.time("clickInterfaceForQML");
                    mytest.clickInterfaceForQML(visualIndex);
                    console.timeEnd("clickInterfaceForQML");
                }

//                Rectangle {
//                    id: icon
//                    width: 72; height: 72
//                    anchors {
//                        horizontalCenter: parent.horizontalCenter;
//                        verticalCenter: parent.verticalCenter
//                    }
//                    color: model.name
//                    Text {
//                        text: model.name
//                        color : "black"
//                        anchors.centerIn: parent
//                    }
//                    radius: 3

//                    Drag.active: delegateRoot.drag.active
//                    Drag.source: delegateRoot
//                    Drag.hotSpot.x: 36
//                    Drag.hotSpot.y: 36

//                    states: [
//                        State {
//                            when: icon.Drag.active
//                            ParentChange {
//                                target: icon
//                                parent: mygridview
//                            }

//                            AnchorChanges {
//                                target: icon;
//                                anchors.horizontalCenter: undefined;
//                                anchors.verticalCenter: undefined
//                            }
//                        }
//                    ]
//                }

                Item {
                    id: pngicons
                    width: 72; height: 72
                    anchors {
                        horizontalCenter: parent.horizontalCenter;
                        verticalCenter: parent.verticalCenter
                    }

                    Image {
                        id: myIcon
                        y: 20;
                        anchors.horizontalCenter: parent.horizontalCenter
                        source: model.icon
                    }

                    Text {
                        text: model.name
                        color : "#030ACC"
                        horizontalAlignment: Text.AlignHCenter
                        //anchors.bottomMargin: parent.Bottom
                        //anchors.centerIn: parent.Bottom
                    }

                    Drag.active: delegateRoot.drag.active
                    Drag.source: delegateRoot
                    Drag.hotSpot.x: 36
                    Drag.hotSpot.y: 36

                    states: [
                        State {
                            when: pngicons.Drag.active
                            ParentChange {
                                target: pngicons
                                parent: mygridview
                            }

                            AnchorChanges {
                                target: pngicons;
                                anchors.horizontalCenter: undefined;
                                anchors.verticalCenter: undefined
                            }
                        }
                    ]
                }

                DropArea {
                    anchors { fill: parent; margins: 15 }

                    onEntered: {
                        visualModel.items.move(drag.source.visualIndex, delegateRoot.visualIndex)
                        drag.accepted = true
                        if (drag.source.visualIndex !== delegateRoot.visualIndex){
                            console.log("SourceIndex:(" + drag.source.visualIndex +")," + "TargetIndex:(" + delegateRoot.visualIndex + ")");
                        }
                    }

                    onDropped: {
                        console.log("onDropped");
                    }

//                    onPositionChanged:{
//                        console.log("SourceIndex:(" + drag.source.visualIndex +")," + "TargetIndex:(" + delegateRoot.visualIndex + ")");
//                    }
                }
            }
        }

        Component.onCompleted : {
            console.log("main.qml:mygridview Completed Running!")
        }
    }
}
