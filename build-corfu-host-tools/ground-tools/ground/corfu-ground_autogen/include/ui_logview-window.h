/********************************************************************************
** Form generated from reading UI file 'logview-window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGVIEW_2D_WINDOW_H
#define UI_LOGVIEW_2D_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LogViewWindow
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *saveBtn;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *setDebug;
    QPushButton *setCritical;
    QPushButton *setWarning;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *catFilter;

    void setupUi(QDialog *LogViewWindow)
    {
        if (LogViewWindow->objectName().isEmpty())
            LogViewWindow->setObjectName(QString::fromUtf8("LogViewWindow"));
        LogViewWindow->resize(1000, 900);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LogViewWindow->sizePolicy().hasHeightForWidth());
        LogViewWindow->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(LogViewWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        saveBtn = new QPushButton(LogViewWindow);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));

        gridLayout_2->addWidget(saveBtn, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        setDebug = new QPushButton(LogViewWindow);
        setDebug->setObjectName(QString::fromUtf8("setDebug"));

        horizontalLayout->addWidget(setDebug);

        setCritical = new QPushButton(LogViewWindow);
        setCritical->setObjectName(QString::fromUtf8("setCritical"));

        horizontalLayout->addWidget(setCritical);

        setWarning = new QPushButton(LogViewWindow);
        setWarning->setObjectName(QString::fromUtf8("setWarning"));

        horizontalLayout->addWidget(setWarning);


        verticalLayout->addLayout(horizontalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(LogViewWindow);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        catFilter = new QLineEdit(LogViewWindow);
        catFilter->setObjectName(QString::fromUtf8("catFilter"));

        formLayout->setWidget(0, QFormLayout::FieldRole, catFilter);


        verticalLayout->addLayout(formLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(LogViewWindow);

        QMetaObject::connectSlotsByName(LogViewWindow);
    } // setupUi

    void retranslateUi(QDialog *LogViewWindow)
    {
        LogViewWindow->setWindowTitle(QCoreApplication::translate("LogViewWindow", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        saveBtn->setToolTip(QCoreApplication::translate("LogViewWindow", "Save current view into a file", nullptr));
#endif // QT_CONFIG(tooltip)
        saveBtn->setText(QCoreApplication::translate("LogViewWindow", "Save to File", nullptr));
        setDebug->setText(QCoreApplication::translate("LogViewWindow", "Debug", nullptr));
        setCritical->setText(QCoreApplication::translate("LogViewWindow", "Critical", nullptr));
        setWarning->setText(QCoreApplication::translate("LogViewWindow", "Warning", nullptr));
        label->setText(QCoreApplication::translate("LogViewWindow", "Category Filer:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogViewWindow: public Ui_LogViewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGVIEW_2D_WINDOW_H
