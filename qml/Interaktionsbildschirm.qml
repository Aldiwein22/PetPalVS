import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.LocalStorage 2.15
import QtQuick.Window 2.15

Page {
    id: interaktionsBildschirm
    property string currentWeather: "Unbekannt"
    property string emotion: "Neutral"

    onActiveFocusChanged: function () {
        if (currentWeather === "Unbekannt") {
            weatherAPI.getWeatherData("Berlin")
        }
    }

    ColumnLayout {
        anchors.centerIn: parent
        Text {
            text: "Name: " + pet.name
        }
        Text {
            text: "Art: " + pet.type
        }
        Text {
            text: "Hunger: " + pet.hunger
        }
        Text {
            text: "Glück: " + pet.happiness
        }
        Text {
            text: "Gesundheit: " + pet.health
        }
        Text {
            text: "Wetter: " + currentWeather
        }
        Text {
            text: "Emotion: " + emotion
        }
        Image {
            source: "qrc:/resources/PetPal_logo.png"
            width: 100
            height: 100
        }
        Button {
            text: "Füttern"
            onClicked: fuettern()
        }
        Button {
            text: "Streicheln"
            onClicked: streicheln()
        }
        Button {
            text: "Trainieren"
            onClicked: stackView.push("MinispielBildschirm.qml")
        }
        Button {
            text: "Anpassen"
            onClicked: stackView.push("Anpassungsbildschirm.qml")
        }
        Button {
            text: "Unterhalten"
            // TODO: Implementiere die Methode "unterhalten()" hier
        }
        Button {
            text: "Speichern"
            onClicked: speichereStatus()
        }
        Button {
            text: "Bildungsinhalte"
            onClicked: stackView.push("Bildungsschirm.qml")
        }
    }

    Connections {
        target: weatherAPI
        onWeatherDataReceived: {
            currentWeather = weather
            adjustEmotionBasedOnWeather(weather)
        }
    }

    function fuettern() {
        pet.hunger = Math.max(0, pet.hunger - 10)
        updateEmotion()
    }

    function streicheln() {
        pet.happiness = Math.min(100, pet.happiness + 10)
        updateEmotion()
    }

    function trainieren() {
        pet.health = Math.min(100, pet.health + 10)
        updateEmotion()
    }

    function speichereStatus() {
        var db = LocalStorage.openDatabaseSync("PetPalDB", "1.0",
                                               "PetPal Database", 1000000)
        db.transaction(function (tx) {
            tx.executeSql(
                        'CREATE TABLE IF NOT EXISTS PetStatus (name TEXT, type TEXT, hunger INTEGER, happiness INTEGER, health INTEGER, color TEXT, pattern TEXT, accessory TEXT)')
            tx.executeSql(
                        'INSERT OR REPLACE INTO PetStatus VALUES (?, ?, ?, ?, ?, ?, ?)',
                        [pet.name, pet.type, pet.hunger, pet.happiness, pet.health, pet.color, pet.pattern, pet.accessory])
        })
    }

    function adjustEmotionBasedOnWeather(weather) {
        if (weather === "Rain") {
            emotion = "Traurig"
            pet.happiness = Math.max(0, pet.happiness - 10)
        } else if (weather === "Sunny") {
            emotion = "Glücklich"
            pet.happiness = Math.min(100, pet.happiness + 10)
        } else {
            emotion = "Neutral"
        }
    }

    function updateEmotion() {
        if (pet.happiness > 80) {
            emotion = "Glücklich"
        } else if (pet.happiness > 50) {
            emotion = "Zufrieden"
        } else if (pet.happiness > 20) {
            emotion = "Traurig"
        } else {
            emotion = "Wütend"
        }
    }

    function getPetImage() {
        return "qrc:/resources/" + pet.color + "_" + pet.pattern + "_" + pet.accessory + ".png"
    }
}
