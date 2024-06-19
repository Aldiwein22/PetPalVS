import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

Page {
    id: minispielBildschirm
    title: "Minispiel"

    property int score: 0
    property int timeRemaining: 30

    Timer {
        id: gameTimer
        interval: 1000
        repeat: true
        running: true
        onTriggered: {
            if (timeRemaining > 0) {
                timeRemaining--
            } else {
                gameTimer.stop()
                endGame()
            }
        }
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        Text {
            text: "Punkte: " + score
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            text: "Verbleibende Zeit: " + timeRemaining
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            text: "Punkte sammeln"
            onClicked: score++
            enabled: timeRemaining > 0
        }
    }

    function endGame() {
        // Ergebnisse verarbeiten und an den Interaktionsbildschirm zurückgeben
        pet.health = Math.min(100, pet.health + score)
        stackView.pop()
    }
}
