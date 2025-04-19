import QtQuick
import QtQuick.Controls
import GearController
 import QtQuick.Layouts
Item {
    id:root
    required property GearController controller
    Component.onCompleted: {
        controller.init()
    }
    width: 256
    height: 256
    Column  {
        spacing: 8
        anchors.centerIn: parent
        AnimatedImage
        {
            width: parent.width
            height:width
            id:anime
            source:controller.id%2?"qrc:/res/pokemon.gif":"qrc:/res/loading.gif"
            playing:root.controller.playing
            speed: root.controller.speed
        }

        Text {
            text: "Pokemon : " + root.controller.id
            font.pixelSize: 18
            horizontalAlignment: Text.AlignHCenter
            width: parent.width
        }
        Slider
        {
            value: root.controller.speed
            from: 1
            to:10
            onValueChanged: {
                root.controller.speed=value
            }
        }

        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: "Start"
                onClicked: root.controller.start()
                enabled: !root.controller.playing
            }
            Button {
                text: "Stop"
                onClicked: root.controller.stop()
                enabled: root.controller.playing
            }
        }
    }

}
