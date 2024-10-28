/********************************************************************************
** Form generated from reading UI file 'event-info-window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENT_2D_INFO_2D_WINDOW_H
#define UI_EVENT_2D_INFO_2D_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EventInfoWindow
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *saveBtn;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *nodeSelector;
    QLabel *label_2;
    QComboBox *hwIdSelector;
    QLabel *label_4;
    QComboBox *appSelector;

    void setupUi(QDialog *EventInfoWindow)
    {
        if (EventInfoWindow->objectName().isEmpty())
            EventInfoWindow->setObjectName(QString::fromUtf8("EventInfoWindow"));
        EventInfoWindow->resize(1300, 900);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EventInfoWindow->sizePolicy().hasHeightForWidth());
        EventInfoWindow->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(EventInfoWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        saveBtn = new QPushButton(EventInfoWindow);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));

        gridLayout_2->addWidget(saveBtn, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(EventInfoWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_3);

        nodeSelector = new QComboBox(EventInfoWindow);
        nodeSelector->setObjectName(QString::fromUtf8("nodeSelector"));

        horizontalLayout->addWidget(nodeSelector);

        label_2 = new QLabel(EventInfoWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_2);

        hwIdSelector = new QComboBox(EventInfoWindow);
        hwIdSelector->setObjectName(QString::fromUtf8("hwIdSelector"));

        horizontalLayout->addWidget(hwIdSelector);

        label_4 = new QLabel(EventInfoWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_4);

        appSelector = new QComboBox(EventInfoWindow);
        appSelector->setObjectName(QString::fromUtf8("appSelector"));

        horizontalLayout->addWidget(appSelector);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(EventInfoWindow);

        QMetaObject::connectSlotsByName(EventInfoWindow);
    } // setupUi

    void retranslateUi(QDialog *EventInfoWindow)
    {
        EventInfoWindow->setWindowTitle(QCoreApplication::translate("EventInfoWindow", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        saveBtn->setToolTip(QCoreApplication::translate("EventInfoWindow", "Save current view into a file", nullptr));
#endif // QT_CONFIG(tooltip)
        saveBtn->setText(QCoreApplication::translate("EventInfoWindow", "Save to File", nullptr));
        label_3->setText(QCoreApplication::translate("EventInfoWindow", "Node:", nullptr));
        label_2->setText(QCoreApplication::translate("EventInfoWindow", "HwID:", nullptr));
        label_4->setText(QCoreApplication::translate("EventInfoWindow", "App:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventInfoWindow: public Ui_EventInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENT_2D_INFO_2D_WINDOW_H
