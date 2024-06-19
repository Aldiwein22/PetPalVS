import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Page {
    id: hauptBildschirm
    ColumnLayout {
        anchors.centerIn: parent
        Button {
            text: "Neues Haustier erstellen"
            onClicked: stackView.push("Erstellungsbildschirm.qml")
        }
        Button {
            text: "Gespeichertes Haustier laden"
            onClicked: ladeGespeichertesHaustier()
        }
    }
    function ladeGespeichertesHaustier() {
        var db = LocalStorage.openDatabaseSync("PetPalDB", "1.0", "PetPal Database", 1000000)
        db.transaction(function (tx) {
            var result = tx.executeSql('SELECT * FROM PetStatus')
            if (result.rows.length > 0) {
                petStatus = result.rows.item(0)
                stackView.push("Interaktionsbildschirm.qml")
            } else {
                console.log("No saved pet status found.")
            }
        })
    }
}
