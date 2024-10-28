/********************************************************************************
** Form generated from reading UI file 'telemetry-window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELEMETRY_2D_WINDOW_H
#define UI_TELEMETRY_2D_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelemetryWindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *tmMemCaution;
    QToolButton *saveCSVBtn;
    QLabel *label;
    QToolButton *backwBtn;
    QToolButton *forwBtn;
    QPushButton *liveBtn;
    QToolButton *pauseBtn;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *preserveCheck;
    QFormLayout *formLayout_2;
    QToolButton *hwidLockBtn;
    QComboBox *hwidSelector;

    void setupUi(QDialog *TelemetryWindow)
    {
        if (TelemetryWindow->objectName().isEmpty())
            TelemetryWindow->setObjectName(QString::fromUtf8("TelemetryWindow"));
        TelemetryWindow->resize(650, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TelemetryWindow->sizePolicy().hasHeightForWidth());
        TelemetryWindow->setSizePolicy(sizePolicy);
        TelemetryWindow->setMinimumSize(QSize(500, 200));
        gridLayout = new QGridLayout(TelemetryWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tmMemCaution = new QToolButton(TelemetryWindow);
        tmMemCaution->setObjectName(QString::fromUtf8("tmMemCaution"));
        tmMemCaution->setEnabled(true);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("dialog-error")));
        tmMemCaution->setIcon(icon);

        horizontalLayout->addWidget(tmMemCaution);

        saveCSVBtn = new QToolButton(TelemetryWindow);
        saveCSVBtn->setObjectName(QString::fromUtf8("saveCSVBtn"));
        saveCSVBtn->setEnabled(true);
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("document-save")));
        saveCSVBtn->setIcon(icon1);

        horizontalLayout->addWidget(saveCSVBtn);

        label = new QLabel(TelemetryWindow);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        backwBtn = new QToolButton(TelemetryWindow);
        backwBtn->setObjectName(QString::fromUtf8("backwBtn"));
        QIcon icon2;
        QString iconThemeName = QString::fromUtf8("media-seek-backward");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        backwBtn->setIcon(icon2);

        horizontalLayout->addWidget(backwBtn);

        forwBtn = new QToolButton(TelemetryWindow);
        forwBtn->setObjectName(QString::fromUtf8("forwBtn"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("media-skip-forward");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        forwBtn->setIcon(icon3);

        horizontalLayout->addWidget(forwBtn);

        liveBtn = new QPushButton(TelemetryWindow);
        liveBtn->setObjectName(QString::fromUtf8("liveBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(liveBtn->sizePolicy().hasHeightForWidth());
        liveBtn->setSizePolicy(sizePolicy1);
        liveBtn->setMinimumSize(QSize(116, 0));

        horizontalLayout->addWidget(liveBtn);

        pauseBtn = new QToolButton(TelemetryWindow);
        pauseBtn->setObjectName(QString::fromUtf8("pauseBtn"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("media-playback-pause");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pauseBtn->setIcon(icon4);

        horizontalLayout->addWidget(pauseBtn);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        scrollArea = new QScrollArea(TelemetryWindow);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 612, 168));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));

        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        preserveCheck = new QCheckBox(TelemetryWindow);
        preserveCheck->setObjectName(QString::fromUtf8("preserveCheck"));

        horizontalLayout_2->addWidget(preserveCheck);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        hwidLockBtn = new QToolButton(TelemetryWindow);
        hwidLockBtn->setObjectName(QString::fromUtf8("hwidLockBtn"));
        hwidLockBtn->setEnabled(true);
        QIcon icon5;
        iconThemeName = QString::fromUtf8("emblem-readonly");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        hwidLockBtn->setIcon(icon5);
        hwidLockBtn->setCheckable(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, hwidLockBtn);

        hwidSelector = new QComboBox(TelemetryWindow);
        hwidSelector->setObjectName(QString::fromUtf8("hwidSelector"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, hwidSelector);


        horizontalLayout_2->addLayout(formLayout_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(TelemetryWindow);

        QMetaObject::connectSlotsByName(TelemetryWindow);
    } // setupUi

    void retranslateUi(QDialog *TelemetryWindow)
    {
        TelemetryWindow->setWindowTitle(QCoreApplication::translate("TelemetryWindow", "Telemetry", nullptr));
#if QT_CONFIG(tooltip)
        tmMemCaution->setToolTip(QCoreApplication::translate("TelemetryWindow", "Current TM Index is no longer in memory!", nullptr));
#endif // QT_CONFIG(tooltip)
        tmMemCaution->setText(QCoreApplication::translate("TelemetryWindow", "...", nullptr));
#if QT_CONFIG(tooltip)
        saveCSVBtn->setToolTip(QCoreApplication::translate("TelemetryWindow", "Save current buffer as CSV file", nullptr));
#endif // QT_CONFIG(tooltip)
        saveCSVBtn->setText(QCoreApplication::translate("TelemetryWindow", "...", nullptr));
        label->setText(QCoreApplication::translate("TelemetryWindow", "TM[x/xx]", nullptr));
        backwBtn->setText(QCoreApplication::translate("TelemetryWindow", "...", nullptr));
        forwBtn->setText(QCoreApplication::translate("TelemetryWindow", "...", nullptr));
        liveBtn->setText(QCoreApplication::translate("TelemetryWindow", "Live", nullptr));
        pauseBtn->setText(QCoreApplication::translate("TelemetryWindow", "...", nullptr));
        preserveCheck->setText(QCoreApplication::translate("TelemetryWindow", "Preserve Window", nullptr));
        hwidLockBtn->setText(QCoreApplication::translate("TelemetryWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TelemetryWindow: public Ui_TelemetryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELEMETRY_2D_WINDOW_H
