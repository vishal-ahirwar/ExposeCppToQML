import QtQuick
import GearControllerManager
 import QtQuick.Controls
Rectangle
{
    width: parent.width
    height: parent.height*0.1
    border.color: "gray"
    anchors.bottom: parent.bottom
    Text
    {
        text: "Total Pokemon Running : "+(GearControllerManager.runningController)+
              "/"+(GearControllerManager.totalControllers)
        width: parent.width
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 16
    }

    Slider{
        anchors.left: parent.left
        height: parent.height
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: 25
        from: 1
        to:50
        value: GearControllerManager.totalControllers
        onValueChanged: {
            GearControllerManager.totalControllers=value
        }
    }
}
