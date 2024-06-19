import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.LocalStorage 2.15

Page {
    id: bildungsschirm
    title: "Bildungsinhalte"

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        ListView {
            id: educationList
            width: parent.width
            height: parent.height - 100
            model: jsonModel
            delegate: Item {
                width: educationList.width
                height: 100
                Column {
                    Text {
                        text: model.title
                        font.pixelSize: 20
                    }
                    Text {
                        text: model.content
                        font.pixelSize: 14
                        wrapMode: Text.WordWrap
                    }
                }
            }
        }

        Button {
            text: "Zurück"
            onClicked: stackView.pop()
        }
    }
}
