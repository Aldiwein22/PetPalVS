import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.LocalStorage 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "PetPal"

    property var pet
    property var weatherAPI: WeatherAPI {}
    property var petStatus

    Component.onCompleted: initialisiereProjekt()

    function initialisiereProjekt() {
        // Initialisiere das Projekt und zeige den Hauptbildschirm an
        stackView.push("Hauptbildschirm.qml")
    }

    StackView {
        id: stackView
        anchors.fill: parent
    }
}
