#include "loader.h"
#include <iostream>
#include <QMessageBox>

//INCLUDE YOUR WIDGETS
#include "plottingWidget/plottingWidget.h"
#include "pointingWidget/pointingWidget.h"


Loader::Loader(){
  widgetCreators = {
      {"pointingWidget", createPointingWidget}, //REGISTER YOUR WIDGETS ,{"name", creationFunc}..
      {"plottingWidget", createPlottingWidget}
    };
}

//Propagate updates to widget instances
void Loader::update(const corfu::ground::Telemetry &receivedTelemetry){
  for(auto& i : widgetInstances){
    i->update(receivedTelemetry);
  }
}

void Loader::updateIndividual(std::string widgetName, std::string thisField, std::string txt){
  //std::cout<<widgetName<<thisField<<txt<<std::endl;
  for(auto& w : widgetInstances){
    if(w->fieldIdentifier == thisField){
      w->updateIndividual(txt);
      break;
    }
  }
}

void Loader::show(QWidget* parent, std::string thisFieldIdentifier, std::string name){
  if(widgetCreators.find(name) != widgetCreators.end()){
    auto w = widgetCreators[name](parent, thisFieldIdentifier);
    widgetInstances.insert(w); //Save instances
    auto s = w->getQWidget();
    QObject::connect(s, &QWidget::destroyed, s, [=]{
      widgetInstances.erase(w);
    }); //Remeber to delete them when they are closed
    w->show();
  }
  else{
    QMessageBox::information(parent, "Error", "Widget does not exist. Try recompiling the custom widgets (-DRECOMPILE_PLUGINS=ON)");
  }
}