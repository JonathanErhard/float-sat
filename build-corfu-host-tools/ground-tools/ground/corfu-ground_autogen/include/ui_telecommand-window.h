/********************************************************************************
** Form generated from reading UI file 'telecommand-window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELECOMMAND_2D_WINDOW_H
#define UI_TELECOMMAND_2D_WINDOW_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelecommandWindow
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *btnLayout;
    QPushButton *sendButton;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *preserveCheck;
    QFormLayout *formLayout_2;
    QToolButton *listenhwidLockBtn;
    QComboBox *listenhwidSelector;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QLabel *timeToExecuteLabel;
    QLineEdit *timeToExecuteLineEdit;
    QGridLayout *gridLayout_4;
    QLineEdit *timeoutEdit;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *periodEdit;
    QHBoxLayout *horizontalLayout;
    QComboBox *nodeSelector;
    QComboBox *hwIdSelector;
    QComboBox *appSelector;
    QComboBox *tmSelector;
    QComboBox *fieldSelector;
    QCheckBox *stopCheck;
    QPushButton *startPeriodic;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *valueKindCombo;
    QLineEdit *exactVal;

    void setupUi(QDialog *TelecommandWindow)
    {
        if (TelecommandWindow->objectName().isEmpty())
            TelecommandWindow->setObjectName(QString::fromUtf8("TelecommandWindow"));
        TelecommandWindow->resize(880, 680);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TelecommandWindow->sizePolicy().hasHeightForWidth());
        TelecommandWindow->setSizePolicy(sizePolicy);
        TelecommandWindow->setMinimumSize(QSize(700, 400));
        gridLayout = new QGridLayout(TelecommandWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        btnLayout = new QHBoxLayout();
        btnLayout->setObjectName(QString::fromUtf8("btnLayout"));
        sendButton = new QPushButton(TelecommandWindow);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        btnLayout->addWidget(sendButton);


        gridLayout->addLayout(btnLayout, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        preserveCheck = new QCheckBox(TelecommandWindow);
        preserveCheck->setObjectName(QString::fromUtf8("preserveCheck"));

        horizontalLayout_4->addWidget(preserveCheck);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        listenhwidLockBtn = new QToolButton(TelecommandWindow);
        listenhwidLockBtn->setObjectName(QString::fromUtf8("listenhwidLockBtn"));
        listenhwidLockBtn->setEnabled(true);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("emblem-readonly");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        listenhwidLockBtn->setIcon(icon);
        listenhwidLockBtn->setCheckable(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, listenhwidLockBtn);

        listenhwidSelector = new QComboBox(TelecommandWindow);
        listenhwidSelector->setObjectName(QString::fromUtf8("listenhwidSelector"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, listenhwidSelector);


        horizontalLayout_4->addLayout(formLayout_2);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        scrollArea = new QScrollArea(TelecommandWindow);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 842, 321));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        timeToExecuteLabel = new QLabel(scrollAreaWidgetContents);
        timeToExecuteLabel->setObjectName(QString::fromUtf8("timeToExecuteLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, timeToExecuteLabel);

        timeToExecuteLineEdit = new QLineEdit(scrollAreaWidgetContents);
        timeToExecuteLineEdit->setObjectName(QString::fromUtf8("timeToExecuteLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, timeToExecuteLineEdit);


        gridLayout_2->addLayout(formLayout, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 1, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(12);
        gridLayout_4->setVerticalSpacing(3);
        gridLayout_4->setContentsMargins(-1, 0, -1, 0);
        timeoutEdit = new QLineEdit(TelecommandWindow);
        timeoutEdit->setObjectName(QString::fromUtf8("timeoutEdit"));

        gridLayout_4->addWidget(timeoutEdit, 2, 0, 1, 1);

        label_4 = new QLabel(TelecommandWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(200, 0));

        gridLayout_4->addWidget(label_4, 2, 1, 1, 1);

        label_3 = new QLabel(TelecommandWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(200, 0));

        gridLayout_4->addWidget(label_3, 1, 1, 1, 1);

        periodEdit = new QLineEdit(TelecommandWindow);
        periodEdit->setObjectName(QString::fromUtf8("periodEdit"));

        gridLayout_4->addWidget(periodEdit, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        nodeSelector = new QComboBox(TelecommandWindow);
        nodeSelector->setObjectName(QString::fromUtf8("nodeSelector"));

        horizontalLayout->addWidget(nodeSelector);

        hwIdSelector = new QComboBox(TelecommandWindow);
        hwIdSelector->setObjectName(QString::fromUtf8("hwIdSelector"));
        hwIdSelector->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(hwIdSelector);

        appSelector = new QComboBox(TelecommandWindow);
        appSelector->setObjectName(QString::fromUtf8("appSelector"));

        horizontalLayout->addWidget(appSelector);

        tmSelector = new QComboBox(TelecommandWindow);
        tmSelector->setObjectName(QString::fromUtf8("tmSelector"));

        horizontalLayout->addWidget(tmSelector);

        fieldSelector = new QComboBox(TelecommandWindow);
        fieldSelector->setObjectName(QString::fromUtf8("fieldSelector"));

        horizontalLayout->addWidget(fieldSelector);


        gridLayout_4->addLayout(horizontalLayout, 7, 0, 1, 5);

        stopCheck = new QCheckBox(TelecommandWindow);
        stopCheck->setObjectName(QString::fromUtf8("stopCheck"));
        stopCheck->setChecked(true);

        gridLayout_4->addWidget(stopCheck, 3, 0, 1, 4);

        startPeriodic = new QPushButton(TelecommandWindow);
        startPeriodic->setObjectName(QString::fromUtf8("startPeriodic"));

        gridLayout_4->addWidget(startPeriodic, 1, 3, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(TelecommandWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        valueKindCombo = new QComboBox(TelecommandWindow);
        valueKindCombo->addItem(QString());
        valueKindCombo->addItem(QString());
        valueKindCombo->addItem(QString());
        valueKindCombo->setObjectName(QString::fromUtf8("valueKindCombo"));
        valueKindCombo->setEnabled(true);

        horizontalLayout_3->addWidget(valueKindCombo);

        exactVal = new QLineEdit(TelecommandWindow);
        exactVal->setObjectName(QString::fromUtf8("exactVal"));

        horizontalLayout_3->addWidget(exactVal);


        gridLayout_4->addLayout(horizontalLayout_3, 9, 0, 1, 4);


        gridLayout->addLayout(gridLayout_4, 3, 0, 1, 1);


        retranslateUi(TelecommandWindow);

        sendButton->setDefault(false);
        valueKindCombo->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(TelecommandWindow);
    } // setupUi

    void retranslateUi(QDialog *TelecommandWindow)
    {
        TelecommandWindow->setWindowTitle(QCoreApplication::translate("TelecommandWindow", "Telecommand", nullptr));
        sendButton->setText(QCoreApplication::translate("TelecommandWindow", "send", nullptr));
        preserveCheck->setText(QCoreApplication::translate("TelecommandWindow", "Preserve Window", nullptr));
        listenhwidLockBtn->setText(QCoreApplication::translate("TelecommandWindow", "...", nullptr));
        timeToExecuteLabel->setText(QCoreApplication::translate("TelecommandWindow", "Execution Timestamp", nullptr));
        timeToExecuteLineEdit->setText(QCoreApplication::translate("TelecommandWindow", "0", nullptr));
#if QT_CONFIG(tooltip)
        timeoutEdit->setToolTip(QCoreApplication::translate("TelecommandWindow", "Stop sending after X ms, no matter what", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        label_4->setToolTip(QCoreApplication::translate("TelecommandWindow", "Stop sending after X ms, no matter what", nullptr));
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("TelecommandWindow", "Stop After[ms]", nullptr));
#if QT_CONFIG(tooltip)
        label_3->setToolTip(QCoreApplication::translate("TelecommandWindow", "Send the TC every X ms (accuracy 10ms)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("TelecommandWindow", "Period[ms]", nullptr));
#if QT_CONFIG(tooltip)
        periodEdit->setToolTip(QCoreApplication::translate("TelecommandWindow", "Send the TC every X ms (accuracy 10ms)", nullptr));
#endif // QT_CONFIG(tooltip)
        periodEdit->setText(QCoreApplication::translate("TelecommandWindow", "1000", nullptr));
#if QT_CONFIG(tooltip)
        nodeSelector->setToolTip(QCoreApplication::translate("TelecommandWindow", "Node", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        hwIdSelector->setToolTip(QCoreApplication::translate("TelecommandWindow", "Hwid", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        appSelector->setToolTip(QCoreApplication::translate("TelecommandWindow", "App", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        tmSelector->setToolTip(QCoreApplication::translate("TelecommandWindow", "Tm", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        fieldSelector->setToolTip(QCoreApplication::translate("TelecommandWindow", "Field", nullptr));
#endif // QT_CONFIG(tooltip)
        stopCheck->setText(QCoreApplication::translate("TelecommandWindow", "Stop when Acknowledgment received on TM:", nullptr));
        startPeriodic->setText(QCoreApplication::translate("TelecommandWindow", "Start", nullptr));
        label_2->setText(QCoreApplication::translate("TelecommandWindow", "Value changes to:", nullptr));
        valueKindCombo->setItemText(0, QCoreApplication::translate("TelecommandWindow", "Increase", nullptr));
        valueKindCombo->setItemText(1, QCoreApplication::translate("TelecommandWindow", "Decrease", nullptr));
        valueKindCombo->setItemText(2, QCoreApplication::translate("TelecommandWindow", "Exact", nullptr));

    } // retranslateUi

};

namespace Ui {
    class TelecommandWindow: public Ui_TelecommandWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELECOMMAND_2D_WINDOW_H
