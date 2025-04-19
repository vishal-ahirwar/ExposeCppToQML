#include "gearcontroller.h"
#include"gearcontrollermanager.h"
#include <QRandomGenerator>
GearController::GearController(QObject *parent)
    : QObject{parent}
{
    srand(time(nullptr));
}

void GearController::start()
{
    qDebug()<<"starting "<<m_id;
    setPlaying(true);
    GearControllerManager::instance()->increement();
}

void GearController::stop()
{
    qDebug()<<"stoping "<<m_id;
    setPlaying(false);
    GearControllerManager::instance()->decreement();
}

void GearController::init()
{
    auto newId=QRandomGenerator::global()->bounded(100, 1100);
    setId(newId);
    qDebug()<<"new id :"<<newId;
}

qint16 GearController::id() const
{
    return m_id;
}

void GearController::setId(qint16 newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

bool GearController::playing() const
{
    return m_playing;
}

void GearController::setPlaying(bool newPlaying)
{
    if (m_playing == newPlaying)
        return;
    m_playing = newPlaying;
    emit playingChanged();
}


qint16 GearController::speed() const
{
    return m_speed;
}

void GearController::setSpeed(qint16 newSpeed)
{
    if (m_speed == newSpeed)
        return;
    m_speed = newSpeed;
    emit speedChanged();
}
