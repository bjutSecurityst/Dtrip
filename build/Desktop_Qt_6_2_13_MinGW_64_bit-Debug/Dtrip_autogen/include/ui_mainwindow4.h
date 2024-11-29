/********************************************************************************
** Form generated from reading UI file 'mainwindow4.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW4_H
#define UI_MAINWINDOW4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow4
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *spinBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QLabel *label_5;
    QComboBox *comboBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_12;
    QLineEdit *lineEdit_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QDateEdit *dateEdit_2;
    QFrame *line_2;
    QLabel *label_13;
    QGridLayout *gridLayout;
    QFrame *line_3;
    QLabel *label_10;
    QGridLayout *gridLayout_2;
    QFrame *line_4;
    QLabel *label_11;
    QGridLayout *gridLayout_3;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton;
    QFrame *line;
    QLabel *label_15;
    QLineEdit *lineEdit_5;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow4)
    {
        if (MainWindow4->objectName().isEmpty())
            MainWindow4->setObjectName(QString::fromUtf8("MainWindow4"));
        MainWindow4->resize(1100, 610);
        centralwidget = new QWidget(MainWindow4);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 1081, 571));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        spinBox = new QSpinBox(verticalLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);

        horizontalLayout_3->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_5->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout->addLayout(verticalLayout_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout->addWidget(comboBox_2);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        comboBox_3 = new QComboBox(verticalLayoutWidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        horizontalLayout->addWidget(comboBox_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_8->addWidget(label_9);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_8->addWidget(lineEdit_3);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_9->addWidget(label_12);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_9->addWidget(lineEdit_4);


        verticalLayout_4->addLayout(horizontalLayout_9);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        dateEdit = new QDateEdit(verticalLayoutWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout_6->addWidget(dateEdit);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        dateEdit_2 = new QDateEdit(verticalLayoutWidget);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        horizontalLayout_7->addWidget(dateEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_7);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_5->addWidget(label_13);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout_5->addLayout(gridLayout);

        line_3 = new QFrame(verticalLayoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_3);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_5->addWidget(label_10);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        verticalLayout_5->addLayout(gridLayout_2);

        line_4 = new QFrame(verticalLayoutWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_4);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_5->addWidget(label_11);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));

        verticalLayout_5->addLayout(gridLayout_3);

        line_5 = new QFrame(verticalLayoutWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(65, 30));

        horizontalLayout_10->addWidget(pushButton);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_10->addWidget(line);

        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_10->addWidget(label_15);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy);
        lineEdit_5->setMaxLength(14);
        lineEdit_5->setReadOnly(true);

        horizontalLayout_10->addWidget(lineEdit_5);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_10->addWidget(label_14);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_10);

        verticalLayout_5->setStretch(0, 3);
        verticalLayout_5->setStretch(2, 1);
        verticalLayout_5->setStretch(3, 3);
        verticalLayout_5->setStretch(5, 1);
        verticalLayout_5->setStretch(6, 3);
        verticalLayout_5->setStretch(8, 1);
        verticalLayout_5->setStretch(9, 3);
        verticalLayout_5->setStretch(11, 1);
        MainWindow4->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow4);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow4->setStatusBar(statusbar);

        retranslateUi(MainWindow4);

        QMetaObject::connectSlotsByName(MainWindow4);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow4)
    {
        MainWindow4->setWindowTitle(QCoreApplication::translate("MainWindow4", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow4", "\347\224\250\346\210\267\347\273\204\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow4", "\347\273\204\345\206\205\347\224\250\346\210\267\346\225\260\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow4", "\347\224\250\346\210\267\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow4", "\347\224\250\346\210\267\344\275\217\346\211\200\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow4", "\347\224\250\346\210\267\347\224\273\345\203\217\357\274\232", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow4", "\346\270\270\345\256\242", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow4", "\345\225\206\345\212\241\344\272\272\345\243\253", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow4", "\345\270\270\347\224\250\346\220\234\347\264\242\346\226\271\345\274\217\357\274\232", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow4", "\350\264\271\347\224\250\346\234\200\345\260\221", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow4", "\346\227\266\351\227\264\346\234\200\347\237\255", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow4", "\344\273\205\347\233\264\351\243\236", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow4", "\345\270\270\344\271\230\350\210\252\345\217\270\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow4", "\345\207\272\350\241\214\346\254\241\346\225\260\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow4", "\347\224\250\346\210\267\345\210\235\345\247\213\350\264\255\347\245\250\346\227\245\346\234\237\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow4", "\347\224\250\346\210\267\346\234\200\350\277\221\350\264\255\347\245\250\346\227\245\346\234\237\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow4", "\345\207\272\345\217\221\345\237\216\345\270\202\346\235\203\351\207\215\350\241\250\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow4", "\345\270\270\345\216\273\345\237\216\345\270\202\346\235\203\351\207\215\350\241\250\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow4", "\345\270\270\346\220\234\347\233\256\347\232\204\345\237\216\345\270\202\346\235\203\351\207\215\350\241\250\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow4", "\347\224\237\346\210\220\347\224\250\346\210\267", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow4", "\347\224\237\346\210\220\350\277\233\345\272\246:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow4", "0%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow4: public Ui_MainWindow4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW4_H
