/********************************************************************************
** Form generated from reading UI file 'telecommand-list-item-widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELECOMMAND_2D_LIST_2D_ITEM_2D_WIDGET_H
#define UI_TELECOMMAND_2D_LIST_2D_ITEM_2D_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelecommandListItemWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *indexLabel;
    QFrame *line_6;
    QLabel *node_label;
    QFrame *line_7;
    QLabel *app_label;
    QFrame *line_8;
    QLabel *label;
    QFrame *line_5;
    QToolButton *buttonEditTc;
    QComboBox *hwId;
    QTextBrowser *paramShortView;
    QFrame *line_2;
    QLabel *timestampLabel;
    QFrame *line_4;
    QLabel *bakedTimestampLabel;
    QFrame *line;
    QToolButton *sendIndividualBtn;
    QToolButton *closeButton;

    void setupUi(QWidget *TelecommandListItemWidget)
    {
        if (TelecommandListItemWidget->objectName().isEmpty())
            TelecommandListItemWidget->setObjectName(QString::fromUtf8("TelecommandListItemWidget"));
        TelecommandListItemWidget->resize(1052, 70);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TelecommandListItemWidget->sizePolicy().hasHeightForWidth());
        TelecommandListItemWidget->setSizePolicy(sizePolicy);
        TelecommandListItemWidget->setMinimumSize(QSize(0, 70));
        TelecommandListItemWidget->setMaximumSize(QSize(16777215, 70));
        verticalLayout_2 = new QVBoxLayout(TelecommandListItemWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 2, 3, 0);
        line_3 = new QFrame(TelecommandListItemWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        indexLabel = new QLabel(TelecommandListItemWidget);
        indexLabel->setObjectName(QString::fromUtf8("indexLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(indexLabel->sizePolicy().hasHeightForWidth());
        indexLabel->setSizePolicy(sizePolicy1);
        indexLabel->setMinimumSize(QSize(75, 0));
        indexLabel->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_3->addWidget(indexLabel);

        line_6 = new QFrame(TelecommandListItemWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShadow(QFrame::Plain);
        line_6->setFrameShape(QFrame::VLine);

        horizontalLayout_3->addWidget(line_6);

        node_label = new QLabel(TelecommandListItemWidget);
        node_label->setObjectName(QString::fromUtf8("node_label"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(node_label->sizePolicy().hasHeightForWidth());
        node_label->setSizePolicy(sizePolicy2);
        node_label->setWordWrap(true);

        horizontalLayout_3->addWidget(node_label);

        line_7 = new QFrame(TelecommandListItemWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShadow(QFrame::Plain);
        line_7->setFrameShape(QFrame::VLine);

        horizontalLayout_3->addWidget(line_7);

        app_label = new QLabel(TelecommandListItemWidget);
        app_label->setObjectName(QString::fromUtf8("app_label"));

        horizontalLayout_3->addWidget(app_label);

        line_8 = new QFrame(TelecommandListItemWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShadow(QFrame::Plain);
        line_8->setFrameShape(QFrame::VLine);

        horizontalLayout_3->addWidget(line_8);

        label = new QLabel(TelecommandListItemWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setWordWrap(true);

        horizontalLayout_3->addWidget(label);

        line_5 = new QFrame(TelecommandListItemWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setFrameShape(QFrame::VLine);

        horizontalLayout_3->addWidget(line_5);

        buttonEditTc = new QToolButton(TelecommandListItemWidget);
        buttonEditTc->setObjectName(QString::fromUtf8("buttonEditTc"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("edit-redo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        buttonEditTc->setIcon(icon);

        horizontalLayout_3->addWidget(buttonEditTc);

        hwId = new QComboBox(TelecommandListItemWidget);
        hwId->setObjectName(QString::fromUtf8("hwId"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(hwId->sizePolicy().hasHeightForWidth());
        hwId->setSizePolicy(sizePolicy3);
        hwId->setMinimumSize(QSize(235, 0));
        hwId->setMaximumSize(QSize(235, 16777215));

        horizontalLayout_3->addWidget(hwId);

        paramShortView = new QTextBrowser(TelecommandListItemWidget);
        paramShortView->setObjectName(QString::fromUtf8("paramShortView"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(paramShortView->sizePolicy().hasHeightForWidth());
        paramShortView->setSizePolicy(sizePolicy4);
        paramShortView->setMaximumSize(QSize(16777215, 42));

        horizontalLayout_3->addWidget(paramShortView);

        line_2 = new QFrame(TelecommandListItemWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::VLine);

        horizontalLayout_3->addWidget(line_2);

        timestampLabel = new QLabel(TelecommandListItemWidget);
        timestampLabel->setObjectName(QString::fromUtf8("timestampLabel"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(timestampLabel->sizePolicy().hasHeightForWidth());
        timestampLabel->setSizePolicy(sizePolicy5);
        timestampLabel->setMinimumSize(QSize(175, 0));
        timestampLabel->setMaximumSize(QSize(175, 16777215));
        timestampLabel->setMargin(3);

        horizontalLayout_3->addWidget(timestampLabel);

        line_4 = new QFrame(TelecommandListItemWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setFrameShape(QFrame::VLine);

        horizontalLayout_3->addWidget(line_4);

        bakedTimestampLabel = new QLabel(TelecommandListItemWidget);
        bakedTimestampLabel->setObjectName(QString::fromUtf8("bakedTimestampLabel"));
        bakedTimestampLabel->setMinimumSize(QSize(175, 0));
        bakedTimestampLabel->setMaximumSize(QSize(175, 16777215));
        bakedTimestampLabel->setMargin(3);

        horizontalLayout_3->addWidget(bakedTimestampLabel);

        line = new QFrame(TelecommandListItemWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout_3->addWidget(line);

        sendIndividualBtn = new QToolButton(TelecommandListItemWidget);
        sendIndividualBtn->setObjectName(QString::fromUtf8("sendIndividualBtn"));

        horizontalLayout_3->addWidget(sendIndividualBtn);

        closeButton = new QToolButton(TelecommandListItemWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("edit-delete");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        closeButton->setIcon(icon1);

        horizontalLayout_3->addWidget(closeButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(TelecommandListItemWidget);

        QMetaObject::connectSlotsByName(TelecommandListItemWidget);
    } // setupUi

    void retranslateUi(QWidget *TelecommandListItemWidget)
    {
        TelecommandListItemWidget->setWindowTitle(QCoreApplication::translate("TelecommandListItemWidget", "Form", nullptr));
        indexLabel->setText(QCoreApplication::translate("TelecommandListItemWidget", "0", nullptr));
        node_label->setText(QCoreApplication::translate("TelecommandListItemWidget", "TextLabel", nullptr));
        app_label->setText(QCoreApplication::translate("TelecommandListItemWidget", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("TelecommandListItemWidget", "TextLabel", nullptr));
        timestampLabel->setText(QCoreApplication::translate("TelecommandListItemWidget", "Instant", nullptr));
        bakedTimestampLabel->setText(QCoreApplication::translate("TelecommandListItemWidget", "Instant", nullptr));
        sendIndividualBtn->setText(QCoreApplication::translate("TelecommandListItemWidget", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TelecommandListItemWidget: public Ui_TelecommandListItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELECOMMAND_2D_LIST_2D_ITEM_2D_WIDGET_H
