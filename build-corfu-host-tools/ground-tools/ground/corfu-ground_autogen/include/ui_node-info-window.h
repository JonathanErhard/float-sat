/********************************************************************************
** Form generated from reading UI file 'node-info-window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODE_2D_INFO_2D_WINDOW_H
#define UI_NODE_2D_INFO_2D_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NodeInfoWindow
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;

    void setupUi(QDialog *NodeInfoWindow)
    {
        if (NodeInfoWindow->objectName().isEmpty())
            NodeInfoWindow->setObjectName(QString::fromUtf8("NodeInfoWindow"));
        NodeInfoWindow->resize(1400, 400);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NodeInfoWindow->sizePolicy().hasHeightForWidth());
        NodeInfoWindow->setSizePolicy(sizePolicy);
        NodeInfoWindow->setMinimumSize(QSize(200, 400));
        gridLayout = new QGridLayout(NodeInfoWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(NodeInfoWindow);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 930, 380));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));

        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(NodeInfoWindow);

        QMetaObject::connectSlotsByName(NodeInfoWindow);
    } // setupUi

    void retranslateUi(QDialog *NodeInfoWindow)
    {
        NodeInfoWindow->setWindowTitle(QCoreApplication::translate("NodeInfoWindow", "Node Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NodeInfoWindow: public Ui_NodeInfoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODE_2D_INFO_2D_WINDOW_H
