import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Page {
    id: erstellungsBildschirm
    ColumnLayout {
        anchors.centerIn: parent
        TextField {
            id: petName
            placeholderText: "Name des Haustiers"
            focus: true
            Keys.onPressed: {
                if (event.key === Qt.Key_Return) {
                    erstelleNeuesHaustier(petName.text, petType.currentText)
                }
            }
        }
        ComboBox {
            id: petType
            model: ["Hund", "Katze", "Vogel", "Fisch"]
        }
        Button {
            text: "Erstellen"
            onClicked: erstelleNeuesHaustier(petName.text, petType.currentText)
        }
    }
    function erstelleNeuesHaustier(name, type) {
        if (name === "" || type === "") {
            petName.focus = true
            return
        }

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
