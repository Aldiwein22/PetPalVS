import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Page {
    id: erstellungsBildschirm

    ColumnLayout {
        anchors.centerIn: parent

        TextField {
            id: petName
            placeholderText: "Name des Haustiers"
        }

        ComboBox {
            id: petType
            model: ["Hund", "Katze", "Vogel"]
        }

        Button {
            text: "Erstellen"
            onClicked: erstelleNeuesHaustier(petName.text, petType.currentText)
        }
    }

    function erstelleNeuesHaustier(name, type) {
        pet = {
            "name": name,
            "type": type,
            "hunger": 0,
            "happiness": 100,
            "health": 100
        }
        stackView.push("Interaktionsbildschirm.qml")
    }
}
