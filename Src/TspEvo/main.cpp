#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Model/tspevosolverviewmodel.h"

int main(int argc, char *argv[])
{
  //  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlDebuggingEnabler enabler;
    qmlRegisterType<TspEvoSolverViewModel>("com.tspevo.data", 1, 0, "TspEvoSolverViewModel");

    QQmlContext *ctxt = engine.rootContext();
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

     return app.exec();
}
