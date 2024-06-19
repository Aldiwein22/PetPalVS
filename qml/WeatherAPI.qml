import QtQuick 2.15
import QtQuick.Controls 2.15
import QtNetwork

QtObject {
    id: weatherAPI
    signal weatherDataReceived(string weather)
    function getWeatherData(location) {
        var url = "https://api.openweathermap.org/data/2.5/weather?q="
                + location + "&appid=e30a931503951ea0e4e4ba412d5b5877"
        var request = new XMLHttpRequest()
        request.open("GET", url, true)
        request.onreadystatechange = function () {
            if (request.readyState === XMLHttpRequest.DONE && request.status === 200) {
                var response = JSON.parse(request.responseText)
                var weather = response.weather[0].main
                weatherDataReceived(weather)
            }
        }
        request.send()
    }
}
