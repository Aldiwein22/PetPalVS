import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.LocalStorage 2.15

Page {
    id: hauptBildschirm
    ColumnLayout {
        anchors.centerIn: parent
        Image {
            id: logo
            source: "../resources/PetPal_logo.png"
            width: 200
            height: 200
        }
        Button {
            text: "Neues Haustier erstellen"
            onClicked: stackView.push("Erstellungsbildschirm.qml")
        }
        Button {
            text: "Gespeichertes Haustier laden"
            onClicked: ladeGespeichertesHaustier()
        }
        Button {
            text: "Bildungsinhalte"
            onClicked: stackView.push("Bildungsschirm.qml")
        }
        Button {
            text: "Beenden"
            onClicked: Qt.quit()
        }
    }

    function ladeGespeichertesHaustier() {
        var db = LocalStorage.openDatabaseSync("PetPalDB", "1.0",
                                               "PetPal Database", 1000000)
        db.transaction(function (tx) {
            var result = tx.executeSql('SELECT * FROM PetStatus')
            if (result.rows.length > 0) {
                var row = result.rows.item(0)
                pet.name = row.name
                pet.type = row.type
                pet.hunger = row.hunger
                pet.happiness = row.happiness
                pet.health = row.health
                pet.color = row.color
                pet.pattern = row.pattern
                pet.accessory = row.accessory
                stackView.push("Interaktionsbildschirm.qml")
            } else {
                console.log("No saved pet status found.")
            }
        })
    }
}
