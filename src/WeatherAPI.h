#ifndef WEATHERAPI_H
#define WEATHERAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class WeatherAPI : public QObject {
    Q_OBJECT
public:
    explicit WeatherAPI(QObject *parent = nullptr);
    void getWeatherData(const QString &location);

signals:
    void weatherDataReceived(const QString &weather);

private slots:
    void onWeatherDataReceived(QNetworkReply *reply);

private:
    QString apiKey;
    QNetworkAccessManager *networkManager;
    void processWeatherData(const QByteArray &data);
};

#endif // WEATHERAPI_H
