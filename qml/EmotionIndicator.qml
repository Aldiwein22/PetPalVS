import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: emotionIndicator
    property string emotion: "Neutral"

    Image {
        id: emotionImage
        source: getEmotionImage(emotion)
        width: 100
        height: 100
        anchors.centerIn: parent
        SequentialAnimation on source {
            loops: 1
            PropertyAnimation {
                from: ""
                to: getEmotionImage(emotion)
                duration: 500
            }
            PauseAnimation {
                duration: 1000
            }
        }
    }

    function getEmotionImage(emotion) {
        switch (emotion) {
        case "Glücklich":
            return "qrc:/resources/happy.png"
        case "Zufrieden":
            return "qrc:/resources/content.png"
        case "Traurig":
            return "qrc:/resources/sad.png"
        case "Wütend":
            return "qrc:/resources/angry.png"
        default:
            return "qrc:/resources/neutral.png"
        }
    }
}
