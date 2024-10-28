/********************************************************************************
** Form generated from reading UI file 'procedure-window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCEDURE_2D_WINDOW_H
#define UI_PROCEDURE_2D_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProcedureWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *nodeSelector;
    QLabel *label_4;
    QComboBox *hwIdSelector;
    QLabel *label_2;
    QComboBox *appSelector;
    QLabel *label_3;
    QComboBox *tcSelector;
    QToolButton *tcAddButton;
    QLabel *bakedDisclaimer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bakeTimestampsBtn;
    QPushButton *unbakeTimestampsBtn;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *sendSelectedTCsBtn;
    QPushButton *sendAllTCsBtn;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loadBtn;
    QPushButton *saveBtn;

    void setupUi(QDialog *ProcedureWindow)
    {
        if (ProcedureWindow->objectName().isEmpty())
            ProcedureWindow->setObjectName(QString::fromUtf8("ProcedureWindow"));
        ProcedureWindow->resize(1800, 1300);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ProcedureWindow->sizePolicy().hasHeightForWidth());
        ProcedureWindow->setSizePolicy(sizePolicy);
        ProcedureWindow->setMinimumSize(QSize(1000, 400));
        ProcedureWindow->setMaximumSize(QSize(5000, 5000));
        gridLayout = new QGridLayout(ProcedureWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ProcedureWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        nodeSelector = new QComboBox(ProcedureWindow);
        nodeSelector->setObjectName(QString::fromUtf8("nodeSelector"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(nodeSelector->sizePolicy().hasHeightForWidth());
        nodeSelector->setSizePolicy(sizePolicy2);
        nodeSelector->setEditable(false);

        horizontalLayout->addWidget(nodeSelector);

        label_4 = new QLabel(ProcedureWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        hwIdSelector = new QComboBox(ProcedureWindow);
        hwIdSelector->setObjectName(QString::fromUtf8("hwIdSelector"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(hwIdSelector->sizePolicy().hasHeightForWidth());
        hwIdSelector->setSizePolicy(sizePolicy3);
        hwIdSelector->setMinimumSize(QSize(235, 0));
        hwIdSelector->setMaximumSize(QSize(235, 16777215));

        horizontalLayout->addWidget(hwIdSelector);

        label_2 = new QLabel(ProcedureWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(label_2);

        appSelector = new QComboBox(ProcedureWindow);
        appSelector->setObjectName(QString::fromUtf8("appSelector"));
        sizePolicy2.setHeightForWidth(appSelector->sizePolicy().hasHeightForWidth());
        appSelector->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(appSelector);

        label_3 = new QLabel(ProcedureWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy4.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(label_3);

        tcSelector = new QComboBox(ProcedureWindow);
        tcSelector->setObjectName(QString::fromUtf8("tcSelector"));
        sizePolicy2.setHeightForWidth(tcSelector->sizePolicy().hasHeightForWidth());
        tcSelector->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(tcSelector);

        tcAddButton = new QToolButton(ProcedureWindow);
        tcAddButton->setObjectName(QString::fromUtf8("tcAddButton"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("list-add");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        tcAddButton->setIcon(icon);

        horizontalLayout->addWidget(tcAddButton);


        verticalLayout->addLayout(horizontalLayout);

        bakedDisclaimer = new QLabel(ProcedureWindow);
        bakedDisclaimer->setObjectName(QString::fromUtf8("bakedDisclaimer"));
        bakedDisclaimer->setWordWrap(true);

        verticalLayout->addWidget(bakedDisclaimer);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        bakeTimestampsBtn = new QPushButton(ProcedureWindow);
        bakeTimestampsBtn->setObjectName(QString::fromUtf8("bakeTimestampsBtn"));

        horizontalLayout_2->addWidget(bakeTimestampsBtn);

        unbakeTimestampsBtn = new QPushButton(ProcedureWindow);
        unbakeTimestampsBtn->setObjectName(QString::fromUtf8("unbakeTimestampsBtn"));

        horizontalLayout_2->addWidget(unbakeTimestampsBtn);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        sendSelectedTCsBtn = new QPushButton(ProcedureWindow);
        sendSelectedTCsBtn->setObjectName(QString::fromUtf8("sendSelectedTCsBtn"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(sendSelectedTCsBtn->sizePolicy().hasHeightForWidth());
        sendSelectedTCsBtn->setSizePolicy(sizePolicy5);
        sendSelectedTCsBtn->setMinimumSize(QSize(0, 80));

        horizontalLayout_4->addWidget(sendSelectedTCsBtn);

        sendAllTCsBtn = new QPushButton(ProcedureWindow);
        sendAllTCsBtn->setObjectName(QString::fromUtf8("sendAllTCsBtn"));
        sendAllTCsBtn->setMinimumSize(QSize(0, 80));

        horizontalLayout_4->addWidget(sendAllTCsBtn);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        loadBtn = new QPushButton(ProcedureWindow);
        loadBtn->setObjectName(QString::fromUtf8("loadBtn"));

        horizontalLayout_3->addWidget(loadBtn);

        saveBtn = new QPushButton(ProcedureWindow);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));

        horizontalLayout_3->addWidget(saveBtn);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        QWidget::setTabOrder(nodeSelector, hwIdSelector);
        QWidget::setTabOrder(hwIdSelector, appSelector);
        QWidget::setTabOrder(appSelector, tcSelector);
        QWidget::setTabOrder(tcSelector, loadBtn);
        QWidget::setTabOrder(loadBtn, saveBtn);
        QWidget::setTabOrder(saveBtn, bakeTimestampsBtn);
        QWidget::setTabOrder(bakeTimestampsBtn, unbakeTimestampsBtn);
        QWidget::setTabOrder(unbakeTimestampsBtn, sendSelectedTCsBtn);
        QWidget::setTabOrder(sendSelectedTCsBtn, tcAddButton);
        QWidget::setTabOrder(tcAddButton, sendAllTCsBtn);

        retranslateUi(ProcedureWindow);

        QMetaObject::connectSlotsByName(ProcedureWindow);
    } // setupUi

    void retranslateUi(QDialog *ProcedureWindow)
    {
        ProcedureWindow->setWindowTitle(QCoreApplication::translate("ProcedureWindow", "Procedure", nullptr));
        label->setText(QCoreApplication::translate("ProcedureWindow", "Node:", nullptr));
        label_4->setText(QCoreApplication::translate("ProcedureWindow", "HW Id:", nullptr));
        label_2->setText(QCoreApplication::translate("ProcedureWindow", "App:", nullptr));
        label_3->setText(QCoreApplication::translate("ProcedureWindow", "Telecommand:", nullptr));
        tcAddButton->setText(QCoreApplication::translate("ProcedureWindow", "...", nullptr));
        bakedDisclaimer->setText(QCoreApplication::translate("ProcedureWindow", "When entering Telecommands, you can use Instant/Relative/Absolute Timestamps. You can then Bake these with the Button below into Absolute ones. The Telecommand will always be sent with the Timestamp information in the Baked column!", nullptr));
#if QT_CONFIG(tooltip)
        bakeTimestampsBtn->setToolTip(QCoreApplication::translate("ProcedureWindow", "Bake all instant/relative Timestamps into Absolute ones", nullptr));
#endif // QT_CONFIG(tooltip)
        bakeTimestampsBtn->setText(QCoreApplication::translate("ProcedureWindow", "Bake All Timestamps", nullptr));
#if QT_CONFIG(tooltip)
        unbakeTimestampsBtn->setToolTip(QCoreApplication::translate("ProcedureWindow", "Clear Baked Timestamps", nullptr));
#endif // QT_CONFIG(tooltip)
        unbakeTimestampsBtn->setText(QCoreApplication::translate("ProcedureWindow", "Unbake All Timestamps", nullptr));
#if QT_CONFIG(tooltip)
        sendSelectedTCsBtn->setToolTip(QCoreApplication::translate("ProcedureWindow", "Send all selected TCs from this List", nullptr));
#endif // QT_CONFIG(tooltip)
        sendSelectedTCsBtn->setText(QCoreApplication::translate("ProcedureWindow", "Send Currently Selected TCs", nullptr));
#if QT_CONFIG(tooltip)
        sendAllTCsBtn->setToolTip(QCoreApplication::translate("ProcedureWindow", "Send all TCs shown in the List", nullptr));
#endif // QT_CONFIG(tooltip)
        sendAllTCsBtn->setText(QCoreApplication::translate("ProcedureWindow", "Send All TCs", nullptr));
#if QT_CONFIG(tooltip)
        loadBtn->setToolTip(QCoreApplication::translate("ProcedureWindow", "Insert a previously saved procedure", nullptr));
#endif // QT_CONFIG(tooltip)
        loadBtn->setText(QCoreApplication::translate("ProcedureWindow", "Load Procedure", nullptr));
#if QT_CONFIG(tooltip)
        saveBtn->setToolTip(QCoreApplication::translate("ProcedureWindow", "Save the current procedure to a file", nullptr));
#endif // QT_CONFIG(tooltip)
        saveBtn->setText(QCoreApplication::translate("ProcedureWindow", "Save Procedure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProcedureWindow: public Ui_ProcedureWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCEDURE_2D_WINDOW_H
