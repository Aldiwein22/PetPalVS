#include "WeatherAPI.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>
#include <QUrlQuery>
#include <QNetworkRequest>

WeatherAPI::WeatherAPI(QObject *parent) : QObject(parent), apiKey("e30a931503951ea0e4e4ba412d5b5877") {
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &WeatherAPI::onWeatherDataReceived);
}

void WeatherAPI::getWeatherData(const QString &location) {
    QUrl url("<https://api.openweathermap.org/data/2.5/weather>");
    QUrlQuery query;
    query.addQueryItem("q", location);
    query.addQueryItem("appid", apiKey);
    query.addQueryItem("units", "metric");
    url.setQuery(query);

    QNetworkRequest request(url);
    networkManager->get(request);
}

void WeatherAPI::onWeatherDataReceived(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        processWeatherData(data);
    } else {
        qWarning() << "Error retrieving weather data:" << reply->errorString();
    }
    reply->deleteLater();
}

void WeatherAPI::processWeatherData(const QByteArray &data) {
    QJsonDocument document = QJsonDocument::fromJson(data);
    QJsonObject object = document.object();
    QString weather = object["weather"].toArray().at(0).toObject()["main"].toString();
    emit weatherDataReceived(weather);
}
