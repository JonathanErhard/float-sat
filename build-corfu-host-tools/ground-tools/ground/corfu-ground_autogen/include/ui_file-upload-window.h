/********************************************************************************
** Form generated from reading UI file 'file-upload-window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILE_2D_UPLOAD_2D_WINDOW_H
#define UI_FILE_2D_UPLOAD_2D_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FileUploadWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *parameters_label;
    QFormLayout *formLayout;
    QLabel *file_path_label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *file_path_edit;
    QPushButton *load_file_button;
    QLabel *file_id_label;
    QSpinBox *file_id_spinbox;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *bitmap_combobox;
    QSpinBox *from_spinbox;
    QSpinBox *to_spinbox;
    QLineEdit *bitmap_edit;
    QPushButton *load_bitmap_file_button;
    QPushButton *validate_bitmap_button;
    QSpinBox *wait_time_spinbox;
    QLabel *wait_time_label;
    QLabel *bitmap_label;
    QFrame *line;
    QLabel *upload_info_label;
    QFormLayout *formLayout_2;
    QLabel *segments_label;
    QLineEdit *segments_edit;
    QLabel *current_time_label;
    QLineEdit *current_time_edit;
    QLabel *expected_time_label;
    QLineEdit *expected_time_edit;
    QLabel *file_size_label;
    QLineEdit *file_size_edit;
    QLabel *recieved_label;
    QLabel *crc32_label;
    QLineEdit *crc32_edit;
    QLineEdit *received_edit;
    QLabel *missing_label;
    QLineEdit *missing_edit;
    QFormLayout *formLayout_3;
    QPushButton *single_segment_button;
    QSpinBox *single_segment_spinbox;
    QProgressBar *send_file_progressbar;
    QPushButton *send_file_button;
    QPushButton *abort_button;

    void setupUi(QDialog *FileUploadWindow)
    {
        if (FileUploadWindow->objectName().isEmpty())
            FileUploadWindow->setObjectName(QString::fromUtf8("FileUploadWindow"));
        FileUploadWindow->resize(736, 900);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FileUploadWindow->sizePolicy().hasHeightForWidth());
        FileUploadWindow->setSizePolicy(sizePolicy);
        FileUploadWindow->setMinimumSize(QSize(736, 564));
        gridLayout = new QGridLayout(FileUploadWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        parameters_label = new QLabel(FileUploadWindow);
        parameters_label->setObjectName(QString::fromUtf8("parameters_label"));

        verticalLayout_2->addWidget(parameters_label);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        file_path_label = new QLabel(FileUploadWindow);
        file_path_label->setObjectName(QString::fromUtf8("file_path_label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, file_path_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        file_path_edit = new QLineEdit(FileUploadWindow);
        file_path_edit->setObjectName(QString::fromUtf8("file_path_edit"));
        file_path_edit->setReadOnly(true);

        horizontalLayout->addWidget(file_path_edit);

        load_file_button = new QPushButton(FileUploadWindow);
        load_file_button->setObjectName(QString::fromUtf8("load_file_button"));
        load_file_button->setEnabled(true);
        load_file_button->setFlat(false);

        horizontalLayout->addWidget(load_file_button);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        file_id_label = new QLabel(FileUploadWindow);
        file_id_label->setObjectName(QString::fromUtf8("file_id_label"));
        file_id_label->setEnabled(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, file_id_label);

        file_id_spinbox = new QSpinBox(FileUploadWindow);
        file_id_spinbox->setObjectName(QString::fromUtf8("file_id_spinbox"));
        file_id_spinbox->setEnabled(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, file_id_spinbox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        bitmap_combobox = new QComboBox(FileUploadWindow);
        bitmap_combobox->addItem(QString());
        bitmap_combobox->addItem(QString());
        bitmap_combobox->addItem(QString());
        bitmap_combobox->addItem(QString());
        bitmap_combobox->addItem(QString());
        bitmap_combobox->setObjectName(QString::fromUtf8("bitmap_combobox"));
        bitmap_combobox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bitmap_combobox->sizePolicy().hasHeightForWidth());
        bitmap_combobox->setSizePolicy(sizePolicy1);
        bitmap_combobox->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(bitmap_combobox);

        from_spinbox = new QSpinBox(FileUploadWindow);
        from_spinbox->setObjectName(QString::fromUtf8("from_spinbox"));
        from_spinbox->setEnabled(true);
        from_spinbox->setMaximum(1000000000);

        horizontalLayout_3->addWidget(from_spinbox);

        to_spinbox = new QSpinBox(FileUploadWindow);
        to_spinbox->setObjectName(QString::fromUtf8("to_spinbox"));
        to_spinbox->setMaximum(1000000000);

        horizontalLayout_3->addWidget(to_spinbox);

        bitmap_edit = new QLineEdit(FileUploadWindow);
        bitmap_edit->setObjectName(QString::fromUtf8("bitmap_edit"));

        horizontalLayout_3->addWidget(bitmap_edit);

        load_bitmap_file_button = new QPushButton(FileUploadWindow);
        load_bitmap_file_button->setObjectName(QString::fromUtf8("load_bitmap_file_button"));

        horizontalLayout_3->addWidget(load_bitmap_file_button);

        validate_bitmap_button = new QPushButton(FileUploadWindow);
        validate_bitmap_button->setObjectName(QString::fromUtf8("validate_bitmap_button"));

        horizontalLayout_3->addWidget(validate_bitmap_button);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_3);

        wait_time_spinbox = new QSpinBox(FileUploadWindow);
        wait_time_spinbox->setObjectName(QString::fromUtf8("wait_time_spinbox"));
        wait_time_spinbox->setReadOnly(false);
        wait_time_spinbox->setMinimum(0);
        wait_time_spinbox->setMaximum(1000000);
        wait_time_spinbox->setValue(200);

        formLayout->setWidget(2, QFormLayout::FieldRole, wait_time_spinbox);

        wait_time_label = new QLabel(FileUploadWindow);
        wait_time_label->setObjectName(QString::fromUtf8("wait_time_label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, wait_time_label);

        bitmap_label = new QLabel(FileUploadWindow);
        bitmap_label->setObjectName(QString::fromUtf8("bitmap_label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, bitmap_label);


        verticalLayout_2->addLayout(formLayout);

        line = new QFrame(FileUploadWindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Sunken);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_2->addWidget(line);

        upload_info_label = new QLabel(FileUploadWindow);
        upload_info_label->setObjectName(QString::fromUtf8("upload_info_label"));

        verticalLayout_2->addWidget(upload_info_label);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        segments_label = new QLabel(FileUploadWindow);
        segments_label->setObjectName(QString::fromUtf8("segments_label"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, segments_label);

        segments_edit = new QLineEdit(FileUploadWindow);
        segments_edit->setObjectName(QString::fromUtf8("segments_edit"));
        segments_edit->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, segments_edit);

        current_time_label = new QLabel(FileUploadWindow);
        current_time_label->setObjectName(QString::fromUtf8("current_time_label"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, current_time_label);

        current_time_edit = new QLineEdit(FileUploadWindow);
        current_time_edit->setObjectName(QString::fromUtf8("current_time_edit"));
        current_time_edit->setReadOnly(true);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, current_time_edit);

        expected_time_label = new QLabel(FileUploadWindow);
        expected_time_label->setObjectName(QString::fromUtf8("expected_time_label"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, expected_time_label);

        expected_time_edit = new QLineEdit(FileUploadWindow);
        expected_time_edit->setObjectName(QString::fromUtf8("expected_time_edit"));
        expected_time_edit->setEnabled(true);
        expected_time_edit->setReadOnly(true);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, expected_time_edit);

        file_size_label = new QLabel(FileUploadWindow);
        file_size_label->setObjectName(QString::fromUtf8("file_size_label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, file_size_label);

        file_size_edit = new QLineEdit(FileUploadWindow);
        file_size_edit->setObjectName(QString::fromUtf8("file_size_edit"));
        file_size_edit->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, file_size_edit);

        recieved_label = new QLabel(FileUploadWindow);
        recieved_label->setObjectName(QString::fromUtf8("recieved_label"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, recieved_label);

        crc32_label = new QLabel(FileUploadWindow);
        crc32_label->setObjectName(QString::fromUtf8("crc32_label"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, crc32_label);

        crc32_edit = new QLineEdit(FileUploadWindow);
        crc32_edit->setObjectName(QString::fromUtf8("crc32_edit"));
        crc32_edit->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, crc32_edit);

        received_edit = new QLineEdit(FileUploadWindow);
        received_edit->setObjectName(QString::fromUtf8("received_edit"));
        received_edit->setReadOnly(true);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, received_edit);

        missing_label = new QLabel(FileUploadWindow);
        missing_label->setObjectName(QString::fromUtf8("missing_label"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, missing_label);

        missing_edit = new QLineEdit(FileUploadWindow);
        missing_edit->setObjectName(QString::fromUtf8("missing_edit"));
        missing_edit->setReadOnly(true);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, missing_edit);


        verticalLayout_2->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(-1, 10, -1, -1);
        single_segment_button = new QPushButton(FileUploadWindow);
        single_segment_button->setObjectName(QString::fromUtf8("single_segment_button"));
        sizePolicy1.setHeightForWidth(single_segment_button->sizePolicy().hasHeightForWidth());
        single_segment_button->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, single_segment_button);

        single_segment_spinbox = new QSpinBox(FileUploadWindow);
        single_segment_spinbox->setObjectName(QString::fromUtf8("single_segment_spinbox"));
        single_segment_spinbox->setMaximum(1000000000);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, single_segment_spinbox);


        verticalLayout_2->addLayout(formLayout_3);

        send_file_progressbar = new QProgressBar(FileUploadWindow);
        send_file_progressbar->setObjectName(QString::fromUtf8("send_file_progressbar"));
        send_file_progressbar->setValue(0);
        send_file_progressbar->setTextVisible(true);

        verticalLayout_2->addWidget(send_file_progressbar);

        send_file_button = new QPushButton(FileUploadWindow);
        send_file_button->setObjectName(QString::fromUtf8("send_file_button"));

        verticalLayout_2->addWidget(send_file_button);

        abort_button = new QPushButton(FileUploadWindow);
        abort_button->setObjectName(QString::fromUtf8("abort_button"));

        verticalLayout_2->addWidget(abort_button);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(FileUploadWindow);

        QMetaObject::connectSlotsByName(FileUploadWindow);
    } // setupUi

    void retranslateUi(QDialog *FileUploadWindow)
    {
        FileUploadWindow->setWindowTitle(QCoreApplication::translate("FileUploadWindow", "Upload File", nullptr));
        parameters_label->setText(QCoreApplication::translate("FileUploadWindow", "Parameters", nullptr));
#if QT_CONFIG(tooltip)
        file_path_label->setToolTip(QCoreApplication::translate("FileUploadWindow", "Path to the file you want to upload", nullptr));
#endif // QT_CONFIG(tooltip)
        file_path_label->setText(QCoreApplication::translate("FileUploadWindow", "Path", nullptr));
#if QT_CONFIG(tooltip)
        file_path_edit->setToolTip(QCoreApplication::translate("FileUploadWindow", "Path to the file you want to upload", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        load_file_button->setToolTip(QCoreApplication::translate("FileUploadWindow", "Loads a file via a file dialog", nullptr));
#endif // QT_CONFIG(tooltip)
        load_file_button->setText(QCoreApplication::translate("FileUploadWindow", "Load File", nullptr));
#if QT_CONFIG(tooltip)
        file_id_label->setToolTip(QCoreApplication::translate("FileUploadWindow", "The upload ID / file ID you with to upload the file to", nullptr));
#endif // QT_CONFIG(tooltip)
        file_id_label->setText(QCoreApplication::translate("FileUploadWindow", "File ID", nullptr));
#if QT_CONFIG(tooltip)
        file_id_spinbox->setToolTip(QCoreApplication::translate("FileUploadWindow", "The upload ID / file ID you with to upload the file to", nullptr));
#endif // QT_CONFIG(tooltip)
        bitmap_combobox->setItemText(0, QCoreApplication::translate("FileUploadWindow", "No Bitmap", nullptr));
        bitmap_combobox->setItemText(1, QCoreApplication::translate("FileUploadWindow", "Hex Bitmap", nullptr));
        bitmap_combobox->setItemText(2, QCoreApplication::translate("FileUploadWindow", "Bin Bitmap", nullptr));
        bitmap_combobox->setItemText(3, QCoreApplication::translate("FileUploadWindow", "File", nullptr));
        bitmap_combobox->setItemText(4, QCoreApplication::translate("FileUploadWindow", "Range", nullptr));

#if QT_CONFIG(tooltip)
        from_spinbox->setToolTip(QCoreApplication::translate("FileUploadWindow", "The starting segment number for your upload", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        to_spinbox->setToolTip(QCoreApplication::translate("FileUploadWindow", "The ending segment number for your upload", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        bitmap_edit->setToolTip(QCoreApplication::translate("FileUploadWindow", "The bitmap you want to use for your upload", nullptr));
#endif // QT_CONFIG(tooltip)
        bitmap_edit->setPlaceholderText(QString());
#if QT_CONFIG(tooltip)
        load_bitmap_file_button->setToolTip(QCoreApplication::translate("FileUploadWindow", "Loads a bitmap from a file ", nullptr));
#endif // QT_CONFIG(tooltip)
        load_bitmap_file_button->setText(QCoreApplication::translate("FileUploadWindow", "Load File", nullptr));
#if QT_CONFIG(tooltip)
        validate_bitmap_button->setToolTip(QCoreApplication::translate("FileUploadWindow", "Validates the Bitmap", nullptr));
#endif // QT_CONFIG(tooltip)
        validate_bitmap_button->setText(QCoreApplication::translate("FileUploadWindow", "Validate", nullptr));
#if QT_CONFIG(tooltip)
        wait_time_spinbox->setToolTip(QCoreApplication::translate("FileUploadWindow", "The time in ms the uploader waits between each segment", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        wait_time_label->setToolTip(QCoreApplication::translate("FileUploadWindow", "The time in ms the uploader waits between each segment", nullptr));
#endif // QT_CONFIG(tooltip)
        wait_time_label->setText(QCoreApplication::translate("FileUploadWindow", "Wait time", nullptr));
#if QT_CONFIG(tooltip)
        bitmap_label->setToolTip(QCoreApplication::translate("FileUploadWindow", "Select a type of bitmap or range for your upload", nullptr));
#endif // QT_CONFIG(tooltip)
        bitmap_label->setText(QCoreApplication::translate("FileUploadWindow", "Bitmap", nullptr));
        upload_info_label->setText(QCoreApplication::translate("FileUploadWindow", "Upload Info", nullptr));
#if QT_CONFIG(tooltip)
        segments_label->setToolTip(QCoreApplication::translate("FileUploadWindow", "The size of your file in segments of 200 bytes", nullptr));
#endif // QT_CONFIG(tooltip)
        segments_label->setText(QCoreApplication::translate("FileUploadWindow", "Segments", nullptr));
#if QT_CONFIG(tooltip)
        segments_edit->setToolTip(QCoreApplication::translate("FileUploadWindow", "The size of your file in segments of 200 bytes", nullptr));
#endif // QT_CONFIG(tooltip)
        current_time_label->setText(QCoreApplication::translate("FileUploadWindow", "Time", nullptr));
        expected_time_label->setText(QCoreApplication::translate("FileUploadWindow", "Expected", nullptr));
#if QT_CONFIG(tooltip)
        file_size_label->setToolTip(QCoreApplication::translate("FileUploadWindow", "The size of your file in bytes", nullptr));
#endif // QT_CONFIG(tooltip)
        file_size_label->setText(QCoreApplication::translate("FileUploadWindow", "Filesize", nullptr));
#if QT_CONFIG(tooltip)
        file_size_edit->setToolTip(QCoreApplication::translate("FileUploadWindow", "The size of your file in bytes", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        recieved_label->setToolTip(QCoreApplication::translate("FileUploadWindow", "The number of segments already recieved", nullptr));
#endif // QT_CONFIG(tooltip)
        recieved_label->setText(QCoreApplication::translate("FileUploadWindow", "Recieved", nullptr));
#if QT_CONFIG(tooltip)
        crc32_label->setToolTip(QCoreApplication::translate("FileUploadWindow", "The CRC32 checksum of your file", nullptr));
#endif // QT_CONFIG(tooltip)
        crc32_label->setText(QCoreApplication::translate("FileUploadWindow", "CRC32", nullptr));
#if QT_CONFIG(tooltip)
        crc32_edit->setToolTip(QCoreApplication::translate("FileUploadWindow", "The CRC32 checksum of your file", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        received_edit->setToolTip(QCoreApplication::translate("FileUploadWindow", "The number of segments already recieved", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        missing_label->setToolTip(QCoreApplication::translate("FileUploadWindow", "The number of segments missing", nullptr));
#endif // QT_CONFIG(tooltip)
        missing_label->setText(QCoreApplication::translate("FileUploadWindow", "Missing", nullptr));
#if QT_CONFIG(tooltip)
        missing_edit->setToolTip(QCoreApplication::translate("FileUploadWindow", "The number of segments missing", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        single_segment_button->setToolTip(QCoreApplication::translate("FileUploadWindow", "Uploads a single file segment", nullptr));
#endif // QT_CONFIG(tooltip)
        single_segment_button->setText(QCoreApplication::translate("FileUploadWindow", "Upload single segment", nullptr));
#if QT_CONFIG(tooltip)
        single_segment_spinbox->setToolTip(QCoreApplication::translate("FileUploadWindow", "Uploads a single file segment", nullptr));
#endif // QT_CONFIG(tooltip)
        send_file_button->setText(QCoreApplication::translate("FileUploadWindow", "Start Upload", nullptr));
        abort_button->setText(QCoreApplication::translate("FileUploadWindow", "Abort Upload", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileUploadWindow: public Ui_FileUploadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILE_2D_UPLOAD_2D_WINDOW_H
