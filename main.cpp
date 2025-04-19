#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQmlContext>
#include"gearcontrollermanager.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterSingletonInstance<GearControllerManager>("GearControllerManager",1,0,"GearControllerManager",GearControllerManager::instance());
    engine.load("qrc:/qml/Main.qml");
    return app.exec();
}
