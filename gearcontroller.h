#ifndef GEARCONTROLLER_H
#define GEARCONTROLLER_H

#include <QObject>
#include <QQmlEngine>

class GearController : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(qint16 id READ id WRITE setId NOTIFY idChanged FINAL)
    Q_PROPERTY(bool playing READ playing WRITE setPlaying NOTIFY playingChanged FINAL)
    Q_PROPERTY(qint16 speed READ speed WRITE setSpeed NOTIFY speedChanged FINAL)
public:
    explicit GearController(QObject *parent = nullptr);

signals:
    void idChanged();
    void playingChanged();

    void speedChanged();

public slots:
    void start();
    void stop();
    void init();
public:

    qint16 id() const;
    void setId(qint16 newId);

    bool playing() const;
    void setPlaying(bool newPlaying);
    qint16 speed() const;
    void setSpeed(qint16 newSpeed);

private:
    qint16 m_id{};
    bool m_playing{};
    qint16 m_speed;
};

#endif // GEARCONTROLLER_H
