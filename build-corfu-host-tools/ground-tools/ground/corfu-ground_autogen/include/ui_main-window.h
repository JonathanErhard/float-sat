/********************************************************************************
** Form generated from reading UI file 'main-window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_2D_WINDOW_H
#define UI_MAIN_2D_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *loadAction;
    QAction *actionload_layout;
    QAction *actionsave_layout;
    QAction *actionclose_all;
    QAction *actionOpen_Wiki;
    QAction *actionOnly_Critical;
    QAction *actionWarnings_Critical;
    QAction *actionEverything;
    QAction *actionSee_Logs;
    QAction *actionAuto_Swap_on_Node_change;
    QAction *actionDefault_Preserve_Window_Value;
    QAction *actionAuto_Swap_on_HwID_change;
    QAction *actionLoad_TM_File;
    QAction *actionWindows_to_background;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_2;
    QLineEdit *stdTMFramesRecvLineEdit;
    QLabel *stdFrameseRecvLabel;
    QPushButton *resetStdTmCounterBtn;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lastMsgByThisNodeLabel;
    QLineEdit *lastMsgByThisNodeLineEdit;
    QLabel *label_10;
    QLabel *label_15;
    QGridLayout *gridLayout;
    QLineEdit *lastUDPRecvLineEdit;
    QLabel *lastUDPRecvLabel;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_8;
    QLineEdit *lastMsgByAnyNodeLineEdit;
    QVBoxLayout *verticalLayout_6;
    QFormLayout *formLayout_3;
    QLabel *exTMFramesRecvLabel;
    QLineEdit *exTMFramesRecvLineEdit;
    QPushButton *resetTMFrameCounterBtn;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_10;
    QFrame *line_5;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QLineEdit *telecommandsSentToThisNodeLineEdit;
    QPushButton *resetThisNodeTCbtn;
    QFrame *line_6;
    QFrame *line_4;
    QLabel *label_13;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout_5;
    QLabel *telecommandsSentLabel;
    QLineEdit *telecommandsSentLineEdit;
    QPushButton *resetTCcounterBtn;
    QLabel *label_11;
    QGridLayout *gridLayout_3;
    QComboBox *nodeComboBox;
    QLabel *label_2;
    QLabel *label;
    QComboBox *hardwareIdComboBox;
    QLabel *hw_id_label;
    QFrame *line_9;
    QHBoxLayout *connectionInfoLayout;
    QLabel *label_3;
    QLabel *uptimeSeconds;
    QFrame *line_3;
    QLabel *label_4;
    QLabel *utcTime;
    QFrame *line_2;
    QLabel *label_5;
    QLabel *packetNumber;
    QFrame *line;
    QLabel *label_6;
    QLabel *lastStdTMHwID;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QPushButton *nodeInfoButton;
    QPushButton *eventInfoButton;
    QPushButton *uploadFileButton;
    QPushButton *refocusTmTc;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *nodeLayout;
    QVBoxLayout *appsLayout;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *menulocUTCtime;
    QMenu *menuLayout;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QMenu *menuLogging;
    QMenu *menuPrintout_Level;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(2299, 1100);
        loadAction = new QAction(MainWindow);
        loadAction->setObjectName(QString::fromUtf8("loadAction"));
        actionload_layout = new QAction(MainWindow);
        actionload_layout->setObjectName(QString::fromUtf8("actionload_layout"));
        actionsave_layout = new QAction(MainWindow);
        actionsave_layout->setObjectName(QString::fromUtf8("actionsave_layout"));
        actionclose_all = new QAction(MainWindow);
        actionclose_all->setObjectName(QString::fromUtf8("actionclose_all"));
        actionOpen_Wiki = new QAction(MainWindow);
        actionOpen_Wiki->setObjectName(QString::fromUtf8("actionOpen_Wiki"));
        actionOnly_Critical = new QAction(MainWindow);
        actionOnly_Critical->setObjectName(QString::fromUtf8("actionOnly_Critical"));
        actionOnly_Critical->setCheckable(true);
        actionWarnings_Critical = new QAction(MainWindow);
        actionWarnings_Critical->setObjectName(QString::fromUtf8("actionWarnings_Critical"));
        actionWarnings_Critical->setCheckable(true);
        actionWarnings_Critical->setChecked(true);
        actionEverything = new QAction(MainWindow);
        actionEverything->setObjectName(QString::fromUtf8("actionEverything"));
        actionEverything->setCheckable(true);
        actionSee_Logs = new QAction(MainWindow);
        actionSee_Logs->setObjectName(QString::fromUtf8("actionSee_Logs"));
        actionAuto_Swap_on_Node_change = new QAction(MainWindow);
        actionAuto_Swap_on_Node_change->setObjectName(QString::fromUtf8("actionAuto_Swap_on_Node_change"));
        actionAuto_Swap_on_Node_change->setCheckable(true);
        actionAuto_Swap_on_Node_change->setChecked(true);
        actionDefault_Preserve_Window_Value = new QAction(MainWindow);
        actionDefault_Preserve_Window_Value->setObjectName(QString::fromUtf8("actionDefault_Preserve_Window_Value"));
        actionDefault_Preserve_Window_Value->setCheckable(true);
        actionAuto_Swap_on_HwID_change = new QAction(MainWindow);
        actionAuto_Swap_on_HwID_change->setObjectName(QString::fromUtf8("actionAuto_Swap_on_HwID_change"));
        actionAuto_Swap_on_HwID_change->setCheckable(true);
        actionLoad_TM_File = new QAction(MainWindow);
        actionLoad_TM_File->setObjectName(QString::fromUtf8("actionLoad_TM_File"));
        actionWindows_to_background = new QAction(MainWindow);
        actionWindows_to_background->setObjectName(QString::fromUtf8("actionWindows_to_background"));
        actionWindows_to_background->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        stdTMFramesRecvLineEdit = new QLineEdit(centralwidget);
        stdTMFramesRecvLineEdit->setObjectName(QString::fromUtf8("stdTMFramesRecvLineEdit"));
        stdTMFramesRecvLineEdit->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, stdTMFramesRecvLineEdit);

        stdFrameseRecvLabel = new QLabel(centralwidget);
        stdFrameseRecvLabel->setObjectName(QString::fromUtf8("stdFrameseRecvLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, stdFrameseRecvLabel);


        verticalLayout_3->addLayout(formLayout_2);

        resetStdTmCounterBtn = new QPushButton(centralwidget);
        resetStdTmCounterBtn->setObjectName(QString::fromUtf8("resetStdTmCounterBtn"));

        verticalLayout_3->addWidget(resetStdTmCounterBtn);


        gridLayout_2->addLayout(verticalLayout_3, 2, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lastMsgByThisNodeLabel = new QLabel(centralwidget);
        lastMsgByThisNodeLabel->setObjectName(QString::fromUtf8("lastMsgByThisNodeLabel"));

        horizontalLayout_2->addWidget(lastMsgByThisNodeLabel);

        lastMsgByThisNodeLineEdit = new QLineEdit(centralwidget);
        lastMsgByThisNodeLineEdit->setObjectName(QString::fromUtf8("lastMsgByThisNodeLineEdit"));
        lastMsgByThisNodeLineEdit->setMinimumSize(QSize(60, 0));
        lastMsgByThisNodeLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(lastMsgByThisNodeLineEdit);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_2->addWidget(label_10);


        verticalLayout_7->addLayout(horizontalLayout_2);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_7->addWidget(label_15);


        horizontalLayout->addLayout(verticalLayout_7);


        gridLayout_2->addLayout(horizontalLayout, 2, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, 10, -1);
        lastUDPRecvLineEdit = new QLineEdit(centralwidget);
        lastUDPRecvLineEdit->setObjectName(QString::fromUtf8("lastUDPRecvLineEdit"));
        lastUDPRecvLineEdit->setEnabled(true);
        lastUDPRecvLineEdit->setMinimumSize(QSize(60, 0));
        lastUDPRecvLineEdit->setReadOnly(true);

        gridLayout->addWidget(lastUDPRecvLineEdit, 0, 3, 1, 1);

        lastUDPRecvLabel = new QLabel(centralwidget);
        lastUDPRecvLabel->setObjectName(QString::fromUtf8("lastUDPRecvLabel"));

        gridLayout->addWidget(lastUDPRecvLabel, 0, 1, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 4, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 1, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 4, 1, 1);

        lastMsgByAnyNodeLineEdit = new QLineEdit(centralwidget);
        lastMsgByAnyNodeLineEdit->setObjectName(QString::fromUtf8("lastMsgByAnyNodeLineEdit"));
        lastMsgByAnyNodeLineEdit->setMinimumSize(QSize(60, 0));
        lastMsgByAnyNodeLineEdit->setReadOnly(true);

        gridLayout->addWidget(lastMsgByAnyNodeLineEdit, 1, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 9, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(-1, -1, 5, -1);
        exTMFramesRecvLabel = new QLabel(centralwidget);
        exTMFramesRecvLabel->setObjectName(QString::fromUtf8("exTMFramesRecvLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, exTMFramesRecvLabel);

        exTMFramesRecvLineEdit = new QLineEdit(centralwidget);
        exTMFramesRecvLineEdit->setObjectName(QString::fromUtf8("exTMFramesRecvLineEdit"));
        exTMFramesRecvLineEdit->setReadOnly(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, exTMFramesRecvLineEdit);


        verticalLayout_6->addLayout(formLayout_3);

        resetTMFrameCounterBtn = new QPushButton(centralwidget);
        resetTMFrameCounterBtn->setObjectName(QString::fromUtf8("resetTMFrameCounterBtn"));

        verticalLayout_6->addWidget(resetTMFrameCounterBtn);


        gridLayout_2->addLayout(verticalLayout_6, 2, 5, 1, 1);

        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_7, 1, 0, 1, 1);

        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_8, 1, 2, 1, 4);

        line_10 = new QFrame(centralwidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_10, 2, 3, 1, 1);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_5, 1, 8, 1, 2);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_6->addWidget(label_12);

        telecommandsSentToThisNodeLineEdit = new QLineEdit(centralwidget);
        telecommandsSentToThisNodeLineEdit->setObjectName(QString::fromUtf8("telecommandsSentToThisNodeLineEdit"));
        telecommandsSentToThisNodeLineEdit->setReadOnly(true);

        horizontalLayout_6->addWidget(telecommandsSentToThisNodeLineEdit);


        verticalLayout_9->addLayout(horizontalLayout_6);

        resetThisNodeTCbtn = new QPushButton(centralwidget);
        resetThisNodeTCbtn->setObjectName(QString::fromUtf8("resetThisNodeTCbtn"));

        verticalLayout_9->addWidget(resetThisNodeTCbtn);


        gridLayout_2->addLayout(verticalLayout_9, 2, 6, 1, 1);

        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShadow(QFrame::Plain);
        line_6->setFrameShape(QFrame::VLine);

        gridLayout_2->addWidget(line_6, 0, 1, 3, 1);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setFrameShape(QFrame::VLine);

        gridLayout_2->addWidget(line_4, 0, 7, 3, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 0, 8, 1, 2);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 0, 2, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        telecommandsSentLabel = new QLabel(centralwidget);
        telecommandsSentLabel->setObjectName(QString::fromUtf8("telecommandsSentLabel"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, telecommandsSentLabel);

        telecommandsSentLineEdit = new QLineEdit(centralwidget);
        telecommandsSentLineEdit->setObjectName(QString::fromUtf8("telecommandsSentLineEdit"));
        telecommandsSentLineEdit->setReadOnly(true);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, telecommandsSentLineEdit);


        verticalLayout_4->addLayout(formLayout_5);

        resetTCcounterBtn = new QPushButton(centralwidget);
        resetTCcounterBtn->setObjectName(QString::fromUtf8("resetTCcounterBtn"));

        verticalLayout_4->addWidget(resetTCcounterBtn);


        gridLayout_2->addLayout(verticalLayout_4, 2, 8, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        nodeComboBox = new QComboBox(centralwidget);
        nodeComboBox->setObjectName(QString::fromUtf8("nodeComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nodeComboBox->sizePolicy().hasHeightForWidth());
        nodeComboBox->setSizePolicy(sizePolicy1);
        nodeComboBox->setMaximumSize(QSize(800, 16777215));

        gridLayout_3->addWidget(nodeComboBox, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        hardwareIdComboBox = new QComboBox(centralwidget);
        hardwareIdComboBox->setObjectName(QString::fromUtf8("hardwareIdComboBox"));
        sizePolicy1.setHeightForWidth(hardwareIdComboBox->sizePolicy().hasHeightForWidth());
        hardwareIdComboBox->setSizePolicy(sizePolicy1);
        hardwareIdComboBox->setMaximumSize(QSize(800, 16777215));

        gridLayout_3->addWidget(hardwareIdComboBox, 2, 1, 1, 1);

        hw_id_label = new QLabel(centralwidget);
        hw_id_label->setObjectName(QString::fromUtf8("hw_id_label"));
        sizePolicy2.setHeightForWidth(hw_id_label->sizePolicy().hasHeightForWidth());
        hw_id_label->setSizePolicy(sizePolicy2);
        hw_id_label->setMinimumSize(QSize(60, 0));

        gridLayout_3->addWidget(hw_id_label, 2, 2, 1, 1);

        gridLayout_3->setColumnStretch(0, 10);
        gridLayout_3->setColumnStretch(1, 10);
        gridLayout_3->setColumnStretch(2, 10);

        gridLayout_2->addLayout(gridLayout_3, 2, 0, 1, 1);

        gridLayout_2->setColumnStretch(0, 20);
        gridLayout_2->setColumnStretch(1, 10);
        gridLayout_2->setColumnStretch(2, 10);
        gridLayout_2->setColumnStretch(3, 10);
        gridLayout_2->setColumnStretch(4, 10);
        gridLayout_2->setColumnStretch(5, 10);
        gridLayout_2->setColumnStretch(6, 10);
        gridLayout_2->setColumnStretch(7, 10);
        gridLayout_2->setColumnStretch(8, 10);
        gridLayout_2->setColumnStretch(9, 10);

        verticalLayout->addLayout(gridLayout_2);

        line_9 = new QFrame(centralwidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_9);

        connectionInfoLayout = new QHBoxLayout();
        connectionInfoLayout->setObjectName(QString::fromUtf8("connectionInfoLayout"));
        connectionInfoLayout->setContentsMargins(-1, 0, -1, -1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAutoFillBackground(true);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        connectionInfoLayout->addWidget(label_3);

        uptimeSeconds = new QLabel(centralwidget);
        uptimeSeconds->setObjectName(QString::fromUtf8("uptimeSeconds"));
        uptimeSeconds->setAutoFillBackground(true);
        uptimeSeconds->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        connectionInfoLayout->addWidget(uptimeSeconds);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        connectionInfoLayout->addWidget(line_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAutoFillBackground(true);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        connectionInfoLayout->addWidget(label_4);

        utcTime = new QLabel(centralwidget);
        utcTime->setObjectName(QString::fromUtf8("utcTime"));
        utcTime->setAutoFillBackground(true);
        utcTime->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        connectionInfoLayout->addWidget(utcTime);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        connectionInfoLayout->addWidget(line_2);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAutoFillBackground(true);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        connectionInfoLayout->addWidget(label_5);

        packetNumber = new QLabel(centralwidget);
        packetNumber->setObjectName(QString::fromUtf8("packetNumber"));
        packetNumber->setAutoFillBackground(true);

        connectionInfoLayout->addWidget(packetNumber);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        connectionInfoLayout->addWidget(line);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAutoFillBackground(true);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        connectionInfoLayout->addWidget(label_6);

        lastStdTMHwID = new QLabel(centralwidget);
        lastStdTMHwID->setObjectName(QString::fromUtf8("lastStdTMHwID"));
        lastStdTMHwID->setAutoFillBackground(true);

        connectionInfoLayout->addWidget(lastStdTMHwID);


        verticalLayout->addLayout(connectionInfoLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_5->addWidget(pushButton);

        nodeInfoButton = new QPushButton(centralwidget);
        nodeInfoButton->setObjectName(QString::fromUtf8("nodeInfoButton"));

        horizontalLayout_5->addWidget(nodeInfoButton);

        eventInfoButton = new QPushButton(centralwidget);
        eventInfoButton->setObjectName(QString::fromUtf8("eventInfoButton"));

        horizontalLayout_5->addWidget(eventInfoButton);

        uploadFileButton = new QPushButton(centralwidget);
        uploadFileButton->setObjectName(QString::fromUtf8("uploadFileButton"));

        horizontalLayout_5->addWidget(uploadFileButton);

        refocusTmTc = new QPushButton(centralwidget);
        refocusTmTc->setObjectName(QString::fromUtf8("refocusTmTc"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(refocusTmTc->sizePolicy().hasHeightForWidth());
        refocusTmTc->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(refocusTmTc);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(verticalLayout_2);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 2261, 701));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        nodeLayout = new QVBoxLayout(scrollAreaWidgetContents);
        nodeLayout->setObjectName(QString::fromUtf8("nodeLayout"));
        nodeLayout->setContentsMargins(0, 0, 0, 0);
        appsLayout = new QVBoxLayout();
        appsLayout->setObjectName(QString::fromUtf8("appsLayout"));

        nodeLayout->addLayout(appsLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 2299, 38));
        menubar->setLayoutDirection(Qt::LeftToRight);
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QString::fromUtf8("fileMenu"));
        menulocUTCtime = new QMenu(menubar);
        menulocUTCtime->setObjectName(QString::fromUtf8("menulocUTCtime"));
        menulocUTCtime->setLayoutDirection(Qt::RightToLeft);
        menuLayout = new QMenu(menubar);
        menuLayout->setObjectName(QString::fromUtf8("menuLayout"));
        menuSettings = new QMenu(menuLayout);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuLogging = new QMenu(menubar);
        menuLogging->setObjectName(QString::fromUtf8("menuLogging"));
        menuPrintout_Level = new QMenu(menuLogging);
        menuPrintout_Level->setObjectName(QString::fromUtf8("menuPrintout_Level"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(fileMenu->menuAction());
        menubar->addAction(menuLayout->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuLogging->menuAction());
        menubar->addAction(menulocUTCtime->menuAction());
        fileMenu->addAction(loadAction);
        menuLayout->addAction(actionclose_all);
        menuLayout->addAction(actionsave_layout);
        menuLayout->addAction(actionload_layout);
        menuLayout->addSeparator();
        menuLayout->addAction(menuSettings->menuAction());
        menuSettings->addAction(actionAuto_Swap_on_Node_change);
        menuSettings->addAction(actionAuto_Swap_on_HwID_change);
        menuSettings->addAction(actionDefault_Preserve_Window_Value);
        menuSettings->addAction(actionWindows_to_background);
        menuHelp->addAction(actionOpen_Wiki);
        menuLogging->addAction(menuPrintout_Level->menuAction());
        menuLogging->addAction(actionSee_Logs);
        menuLogging->addSeparator();
        menuLogging->addAction(actionLoad_TM_File);
        menuPrintout_Level->addAction(actionOnly_Critical);
        menuPrintout_Level->addAction(actionWarnings_Critical);
        menuPrintout_Level->addAction(actionEverything);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "InnoCube / Dev-EGSE", nullptr));
        loadAction->setText(QCoreApplication::translate("MainWindow", "Load Project Config", nullptr));
        actionload_layout->setText(QCoreApplication::translate("MainWindow", "Load Layout", nullptr));
        actionsave_layout->setText(QCoreApplication::translate("MainWindow", "Save Layout", nullptr));
        actionclose_all->setText(QCoreApplication::translate("MainWindow", "Close All Windows", nullptr));
#if QT_CONFIG(tooltip)
        actionclose_all->setToolTip(QCoreApplication::translate("MainWindow", "Close All Windows", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpen_Wiki->setText(QCoreApplication::translate("MainWindow", "Open Wiki", nullptr));
        actionOnly_Critical->setText(QCoreApplication::translate("MainWindow", "Only Critical", nullptr));
        actionWarnings_Critical->setText(QCoreApplication::translate("MainWindow", "Warnings+Critical", nullptr));
        actionEverything->setText(QCoreApplication::translate("MainWindow", "Everything", nullptr));
        actionSee_Logs->setText(QCoreApplication::translate("MainWindow", "See Logs", nullptr));
        actionAuto_Swap_on_Node_change->setText(QCoreApplication::translate("MainWindow", "Auto Swap on Node change", nullptr));
        actionDefault_Preserve_Window_Value->setText(QCoreApplication::translate("MainWindow", "Default Preserve Window Value", nullptr));
        actionAuto_Swap_on_HwID_change->setText(QCoreApplication::translate("MainWindow", "Auto Swap on HwID change", nullptr));
        actionLoad_TM_File->setText(QCoreApplication::translate("MainWindow", "Load TM File", nullptr));
        actionWindows_to_background->setText(QCoreApplication::translate("MainWindow", "Windows to background", nullptr));
        stdTMFramesRecvLineEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        stdFrameseRecvLabel->setText(QCoreApplication::translate("MainWindow", "Std TM-Frames", nullptr));
        resetStdTmCounterBtn->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        lastMsgByThisNodeLabel->setText(QCoreApplication::translate("MainWindow", "Msg by this Node:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "ago", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Standard TM-Bar below\342\206\223", nullptr));
        lastUDPRecvLabel->setText(QCoreApplication::translate("MainWindow", "Gateway Msg received:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "ago", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Msg by any Node:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "ago", nullptr));
        lastMsgByAnyNodeLineEdit->setText(QString());
        exTMFramesRecvLabel->setText(QCoreApplication::translate("MainWindow", "Ex TM-Frames", nullptr));
        exTMFramesRecvLineEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        resetTMFrameCounterBtn->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "TC Sent", nullptr));
        telecommandsSentToThisNodeLineEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        resetThisNodeTCbtn->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Connection-independend info", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Info for current connection:", nullptr));
        telecommandsSentLabel->setText(QCoreApplication::translate("MainWindow", "TC Sent", nullptr));
        telecommandsSentLineEdit->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        resetTCcounterBtn->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Connection Settings", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "HardwareID", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Node:", nullptr));
        hw_id_label->setText(QCoreApplication::translate("MainWindow", "0xFF", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Uptime (seconds):", nullptr));
        uptimeSeconds->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Time UTC: ", nullptr));
        utcTime->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Packet Number:", nullptr));
        packetNumber->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Last StdTM received by HwID:", nullptr));
        lastStdTMHwID->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Procedure Window", nullptr));
        nodeInfoButton->setText(QCoreApplication::translate("MainWindow", "Open Node Info", nullptr));
        eventInfoButton->setText(QCoreApplication::translate("MainWindow", "Open Events", nullptr));
        uploadFileButton->setText(QCoreApplication::translate("MainWindow", "Upload File", nullptr));
#if QT_CONFIG(tooltip)
        refocusTmTc->setToolTip(QCoreApplication::translate("MainWindow", "Refocus All TM/TC windows (Shortcut: Alt or AltGr)", nullptr));
#endif // QT_CONFIG(tooltip)
        refocusTmTc->setText(QCoreApplication::translate("MainWindow", "Refocus TM/TC", nullptr));
        fileMenu->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menulocUTCtime->setTitle(QCoreApplication::translate("MainWindow", "locUTCtime", nullptr));
        menuLayout->setTitle(QCoreApplication::translate("MainWindow", "Layout", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings:", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuLogging->setTitle(QCoreApplication::translate("MainWindow", "Logging", nullptr));
        menuPrintout_Level->setTitle(QCoreApplication::translate("MainWindow", "Printout Level", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_2D_WINDOW_H
