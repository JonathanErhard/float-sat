/********************************************************************************
** Form generated from reading UI file 'app-widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_2D_WIDGET_H
#define UI_APP_2D_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppWidget
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *telecommandLayout;
    QFrame *line_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *numOfEvents;
    QPushButton *viewEventsBtn;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QToolButton *stdTMViewBtn;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QFormLayout *standardTelemetryLayout;
    QFrame *line;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QVBoxLayout *extendedTelemetryLayout;

    void setupUi(QWidget *AppWidget)
    {
        if (AppWidget->objectName().isEmpty())
            AppWidget->setObjectName(QString::fromUtf8("AppWidget"));
        AppWidget->resize(523, 300);
        gridLayout = new QGridLayout(AppWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(AppWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        telecommandLayout = new QVBoxLayout();
        telecommandLayout->setObjectName(QString::fromUtf8("telecommandLayout"));

        gridLayout_2->addLayout(telecommandLayout, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, -1, 0, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        numOfEvents = new QLabel(groupBox);
        numOfEvents->setObjectName(QString::fromUtf8("numOfEvents"));

        horizontalLayout_2->addWidget(numOfEvents);

        viewEventsBtn = new QPushButton(groupBox);
        viewEventsBtn->setObjectName(QString::fromUtf8("viewEventsBtn"));

        horizontalLayout_2->addWidget(viewEventsBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShadow(QFrame::Sunken);
        line_3->setFrameShape(QFrame::HLine);

        verticalLayout->addWidget(line_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label);

        stdTMViewBtn = new QToolButton(groupBox);
        stdTMViewBtn->setObjectName(QString::fromUtf8("stdTMViewBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stdTMViewBtn->sizePolicy().hasHeightForWidth());
        stdTMViewBtn->setSizePolicy(sizePolicy1);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("computer");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        stdTMViewBtn->setIcon(icon);

        horizontalLayout_3->addWidget(stdTMViewBtn);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        standardTelemetryLayout = new QFormLayout();
        standardTelemetryLayout->setObjectName(QString::fromUtf8("standardTelemetryLayout"));

        gridLayout_3->addLayout(standardTelemetryLayout, 2, 0, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        verticalLayout->setStretch(3, 10);

        horizontalLayout->addLayout(verticalLayout);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        extendedTelemetryLayout = new QVBoxLayout();
        extendedTelemetryLayout->setObjectName(QString::fromUtf8("extendedTelemetryLayout"));

        gridLayout_4->addLayout(extendedTelemetryLayout, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_4);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(AppWidget);

        QMetaObject::connectSlotsByName(AppWidget);
    } // setupUi

    void retranslateUi(QWidget *AppWidget)
    {
        AppWidget->setWindowTitle(QCoreApplication::translate("AppWidget", "Form", nullptr));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QCoreApplication::translate("AppWidget", "Telecommands", nullptr));
        label_2->setText(QCoreApplication::translate("AppWidget", "Events:", nullptr));
        numOfEvents->setText(QCoreApplication::translate("AppWidget", "0", nullptr));
        viewEventsBtn->setText(QCoreApplication::translate("AppWidget", "View", nullptr));
        label->setText(QCoreApplication::translate("AppWidget", "Standard Telemetry", nullptr));
        stdTMViewBtn->setText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("AppWidget", "Extended Telemetry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppWidget: public Ui_AppWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_2D_WIDGET_H
