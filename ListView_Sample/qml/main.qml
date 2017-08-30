import QtQuick 2.0
import QtQml.Models 2.2

ListView {
    id: mylistview
    width: 300; height: 350

    model: DelegateModel {
        id: visualModel

        model: myModel

        delegate: MouseArea {
            id: delegateRoot

            property int visualIndex: DelegateModel.itemsIndex

            width: 300; height: 80
            drag.target: icon

            onClicked: {
                console.log("VisualIndex" + visualIndex + "Clicked")
                mytest.clickInterfaceForQML(visualIndex, model.name);
            }
            onPressAndHold: {
                console.log("VisualIndex" + visualIndex + "PressAndHold")
                mytest.clickInterfaceForQML(visualIndex, model.name);
            }
            Rectangle {
                id: icon
                width: 292; height: 72
                anchors {
                    horizontalCenter: parent.horizontalCenter;
                    verticalCenter: parent.verticalCenter
                }
                color: model.color
                Text {
                    text: model.name + ":" + model.color
                    color : "black"
                    font.bold : true
                    anchors.centerIn: parent
                }
                radius: 3

                Drag.active: delegateRoot.drag.active
                Drag.source: delegateRoot
                Drag.hotSpot.x: 36
                Drag.hotSpot.y: 36

                states: [
                    State {
                        when: icon.Drag.active
                        ParentChange {
                            target: icon
                            parent: mylistview
                        }

                        AnchorChanges {
                            target: icon;
                            anchors.horizontalCenter: undefined;
                            anchors.verticalCenter: undefined
                        }
                    }
                ]
            }

            DropArea {
                anchors { fill: parent; margins: 15 }

                onEntered: visualModel.items.move(drag.source.visualIndex, delegateRoot.visualIndex)
            }
        }
    }
}
