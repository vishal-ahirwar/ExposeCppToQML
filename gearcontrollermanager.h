#ifndef GEARCONTROLLERMANAGER_H
#define GEARCONTROLLERMANAGER_H

#include <QObject>

class GearControllerManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint16 totalControllers READ totalControllers WRITE setTotalControllers NOTIFY totalControllersChanged FINAL)
    Q_PROPERTY(qint16 runningController READ runningController WRITE setRunningController NOTIFY runningControllerChanged FINAL)
public:
    explicit GearControllerManager(QObject *parent = nullptr);
    void increement();
    void decreement();
    qint16 totalControllers() const;
    static GearControllerManager*instance();
    qint16 runningController() const;
    void setRunningController(qint16 newRunningController);

    void setTotalControllers(qint16 newTotalControllers);

signals:
    void totalControllersChanged();
    void runningControllerChanged();

private:
    qint16 m_totalControllers;
    qint16 m_runningController;
};

#endif // GEARCONTROLLERMANAGER_H
