import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Page {
    id: interaktionsBildschirm

    property string currentWeather: "Unbekannt"
    property string emotion: "Neutral"

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
            onClicked: trainieren()
        }

        Button {
            text: "Speichern"
            onClicked: speichereStatus()
        }

        Button {
            text: "Wetter aktualisieren"
            onClicked: weatherAPI.getWeatherData("Berlin")
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
    }

    function streicheln() {
        pet.happiness = Math.min(100, pet.happiness + 10)
    }

    function trainieren() {
        pet.health = Math.min(100, pet.health + 10)
    }

    function speichereStatus() {
        var db = LocalStorage.openDatabaseSync("PetPalDB", "1.0",
                                               "PetPal Database", 1000000)
        db.transaction(function (tx) {
            tx.executeSql(
                        'CREATE TABLE IF NOT EXISTS PetStatus (name TEXT, type TEXT, hunger INTEGER, happiness INTEGER, health INTEGER)')
            tx.executeSql(
                        'INSERT OR REPLACE INTO PetStatus VALUES (?, ?, ?, ?, ?)',
                        [pet.name, pet.type, pet.hunger, pet.happiness, pet.health])
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
}
