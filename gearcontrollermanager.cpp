#include "gearcontrollermanager.h"

GearControllerManager::GearControllerManager(QObject *parent)
    : QObject{parent}
{}

void GearControllerManager::increement()
{
    ++m_runningController;
    emit totalControllersChanged();
}

void GearControllerManager::decreement()
{
    --m_runningController;
    emit totalControllersChanged();
}

qint16 GearControllerManager::totalControllers() const
{
    return m_totalControllers;
}

GearControllerManager *GearControllerManager::instance()
{
    static GearControllerManager manager;
    return &manager;
}

qint16 GearControllerManager::runningController() const
{
    return m_runningController;
}

void GearControllerManager::setRunningController(qint16 newRunningController)
{
    if (m_runningController == newRunningController)
        return;
    m_runningController = newRunningController;
    emit runningControllerChanged();
}

void GearControllerManager::setTotalControllers(qint16 newTotalControllers)
{
    if (m_totalControllers == newTotalControllers)
        return;
    m_totalControllers = newTotalControllers;
    emit totalControllersChanged();
}
