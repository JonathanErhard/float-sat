#ifndef ECHOPLUGIN_H
#define ECHOPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include "plugin-interface.hpp"
#include <corfu/ground/telemetry.hpp>
#include <map>
#include <set>
#include <string>

class Loader : public QObject, CWLoaderInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "whatever.you.want.CWPluginInterface")
    Q_INTERFACES(CWLoaderInterface)

public:
    Loader();
    std::map<std::string, CustomWidgetInterface*(*)(QWidget*, std::string)> widgetCreators;
    std::set<CustomWidgetInterface*> widgetInstances;
    void update(const corfu::ground::Telemetry &receivedTelemetry) override;
    void updateIndividual(std::string widgetName, std::string thisField, std::string txt) override;
    void show(QWidget* parent, std::string thisFieldIdentifier, std::string name) override;
};


#endif