import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Page {
    id: anpassungsBildschirm

    ColumnLayout {
        anchors.centerIn: parent

        Text {
            text: "Anpassung des Haustiers"
        }

        ComboBox {
            id: colorPicker
            model: ["Rot", "Blau", "Grün", "Gelb"]
            currentIndex: 0
        }

        ComboBox {
            id: patternPicker
            model: ["Streifen", "Punkte", "Einfarbig"]
            currentIndex: 0
        }

        ComboBox {
            id: accessoryPicker
            model: ["Hut", "Brille", "Schleife"]
            currentIndex: 0
        }

        Button {
            text: "Anpassen"
            onClicked: passeHaustierAn(colorPicker.currentText,
                                       patternPicker.currentText,
                                       accessoryPicker.currentText)
        }
    }

    function passeHaustierAn(farbe, muster, accessoire) {
        pet.color = farbe
        pet.pattern = muster
        pet.accessory = accessoire
        stackView.pop("Interaktionsbildschirm.qml")
    }
}
