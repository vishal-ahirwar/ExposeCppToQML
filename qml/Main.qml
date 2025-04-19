import QtQuick
import GearController
 import QtQuick.Layouts
 import QtQuick.Controls
import GearControllerManager
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Gear Controller")

    Connections
    {
        target: GearControllerManager
        onTotalControllersChanged:{
            repeater.model=GearControllerManager.totalControllers
        }
    }
            Rectangle
            {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                radius: 18
                width: parent.width*0.9
                height:parent.height*0.9
                ScrollView {
                        anchors
                        {
                            top:parent.top
                            bottom:bottomBar.top
                        }
                        width: parent.width
                        height:parent.height*0.95
                        anchors.horizontalCenter: parent.horizontalCenter
                        ScrollBar.horizontal.policy:ScrollBar.AlwaysOff
                        Grid
                        {
                            id: grid
                            columns: 5
                            columnSpacing: 25
                            rowSpacing: 15
                            width: parent.width
                            height:parent.height
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter

                                Repeater
                                {
                                    model: 25
                                    Gear{controller:GearController{}}
                                    Component.onCompleted: {
                                        GearControllerManager.totalControllers=model
                                    }
                                }

                        }
                    }

            }



    BottomBar
    {
        id:bottomBar
    }
}
