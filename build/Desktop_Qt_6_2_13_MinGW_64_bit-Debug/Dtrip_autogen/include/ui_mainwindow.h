/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticaltool;
    QPushButton *pushButton_0;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QScrollBar *verticalScrollBar;
    QLabel *labelicon0;
    QPushButton *backgroundsky;
    QWidget *verticalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *lineEditdep;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *lineEditari;
    QPushButton *layoutbutton;
    QLabel *label_4;
    QPushButton *easystay;
    QPushButton *home_background;
    QPushButton *layoutbutton_2;
    QWidget *verticalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QLabel *label_8;
    QLabel *label_9;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModality::NonModal);
        MainWindow->resize(1280, 720);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setAnimated(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 151, 341));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 0, 0, 0);
        verticaltool = new QVBoxLayout();
        verticaltool->setObjectName(QString::fromUtf8("verticaltool"));
        verticaltool->setContentsMargins(2, -1, -1, -1);
        pushButton_0 = new QPushButton(horizontalLayoutWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("\350\217\234\345\215\225\346\240\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8("\350\217\234\345\215\225\346\240\217.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_0->setIcon(icon);
        pushButton_0->setIconSize(QSize(68, 24));
        pushButton_0->setAutoDefault(true);
        pushButton_0->setFlat(false);

        verticaltool->addWidget(pushButton_0);

        pushButton_1 = new QPushButton(horizontalLayoutWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(75, 18));
        pushButton_1->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        pushButton_1->setIconSize(QSize(12, 18));
        pushButton_1->setCheckable(false);
        pushButton_1->setChecked(false);
        pushButton_1->setAutoRepeat(false);
        pushButton_1->setAutoExclusive(false);
        pushButton_1->setAutoDefault(false);
        pushButton_1->setFlat(false);

        verticaltool->addWidget(pushButton_1);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        pushButton_2->setIconSize(QSize(12, 18));

        verticaltool->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        pushButton_3->setIconSize(QSize(12, 20));

        verticaltool->addWidget(pushButton_3);


        horizontalLayout->addLayout(verticaltool);

        verticalScrollBar = new QScrollBar(horizontalLayoutWidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);
        verticalScrollBar->setInvertedAppearance(false);
        verticalScrollBar->setInvertedControls(false);

        horizontalLayout->addWidget(verticalScrollBar);

        labelicon0 = new QLabel(centralwidget);
        labelicon0->setObjectName(QString::fromUtf8("labelicon0"));
        labelicon0->setGeometry(QRect(240, 10, 291, 51));
        labelicon0->setScaledContents(true);
        backgroundsky = new QPushButton(centralwidget);
        backgroundsky->setObjectName(QString::fromUtf8("backgroundsky"));
        backgroundsky->setGeometry(QRect(200, 80, 571, 241));
        backgroundsky->setIconSize(QSize(300, 150));
        backgroundsky->setAutoDefault(false);
        backgroundsky->setFlat(false);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(220, 159, 431, 51));
        horizontalLayout_2 = new QHBoxLayout(verticalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_2->setMargin(0);

        verticalLayout->addWidget(label_2);

        lineEditdep = new QLineEdit(verticalLayoutWidget_2);
        lineEditdep->setObjectName(QString::fromUtf8("lineEditdep"));
        lineEditdep->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        lineEditdep->setFrame(false);
        lineEditdep->setCursorPosition(0);

        verticalLayout->addWidget(lineEditdep);


        horizontalLayout_2->addLayout(verticalLayout);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 48pt \"Microsoft YaHei UI\";"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label->setMargin(0);

        verticalLayout_3->addWidget(label);

        lineEditari = new QLineEdit(verticalLayoutWidget_2);
        lineEditari->setObjectName(QString::fromUtf8("lineEditari"));
        lineEditari->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        lineEditari->setFrame(false);
        lineEditari->setCursorPosition(0);

        verticalLayout_3->addWidget(lineEditari);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_2->setStretch(0, 9);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 10);
        layoutbutton = new QPushButton(centralwidget);
        layoutbutton->setObjectName(QString::fromUtf8("layoutbutton"));
        layoutbutton->setGeometry(QRect(210, 150, 441, 71));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(210, 90, 111, 51));
        label_4->setStyleSheet(QString::fromUtf8("font: 18pt \"Microsoft YaHei UI\";"));
        label_4->setTextFormat(Qt::TextFormat::AutoText);
        label_4->setScaledContents(true);
        label_4->setWordWrap(false);
        easystay = new QPushButton(centralwidget);
        easystay->setObjectName(QString::fromUtf8("easystay"));
        easystay->setGeometry(QRect(570, 100, 181, 31));
        home_background = new QPushButton(centralwidget);
        home_background->setObjectName(QString::fromUtf8("home_background"));
        home_background->setGeometry(QRect(200, 80, 271, 71));
        layoutbutton_2 = new QPushButton(centralwidget);
        layoutbutton_2->setObjectName(QString::fromUtf8("layoutbutton_2"));
        layoutbutton_2->setGeometry(QRect(210, 230, 441, 71));
        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(220, 239, 431, 51));
        horizontalLayout_3 = new QHBoxLayout(verticalLayoutWidget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(verticalLayoutWidget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_5->setMargin(0);

        verticalLayout_4->addWidget(label_5);

        dateEdit = new QDateEdit(verticalLayoutWidget_5);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2024, 1, 1), QTime(0, 0, 0)));
        dateEdit->setMaximumDate(QDate(9999, 12, 31));
        dateEdit->setCalendarPopup(true);

        verticalLayout_4->addWidget(dateEdit);


        horizontalLayout_3->addLayout(verticalLayout_4);

        label_6 = new QLabel(verticalLayoutWidget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 48pt \"Microsoft YaHei UI\";"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_7 = new QLabel(verticalLayoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_7->setMargin(0);

        verticalLayout_5->addWidget(label_7);

        comboBox = new QComboBox(verticalLayoutWidget_5);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_5->addWidget(comboBox);


        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalLayout_3->setStretch(0, 9);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 10);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(670, 160, 81, 51));
        pushButton->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        pushButton->setCheckable(true);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(670, 240, 81, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("search.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8("search.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(12, 12));
        pushButton_4->setCheckable(true);
        pushButton_4->setAutoDefault(false);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(810, 80, 331, 541));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(440, 670, 381, 16));
        label_9->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        MainWindow->setCentralWidget(centralwidget);
        backgroundsky->raise();
        home_background->raise();
        layoutbutton->raise();
        horizontalLayoutWidget->raise();
        labelicon0->raise();
        verticalLayoutWidget_2->raise();
        label_4->raise();
        easystay->raise();
        layoutbutton_2->raise();
        verticalLayoutWidget_5->raise();
        pushButton->raise();
        pushButton_4->raise();
        label_8->raise();
        label_9->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton_0->setDefault(false);
        pushButton_1->setDefault(false);
        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_0->setText(QString());
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "\350\210\252\347\217\255\346\237\245\350\257\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\351\200\200\346\224\271\347\245\250", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\351\243\236\350\241\214\344\277\241\346\201\257\347\273\237\350\256\241", nullptr));
        labelicon0->setText(QString());
        backgroundsky->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#454545;\">\345\207\272\345\217\221\345\234\260\357\274\232</span></p></body></html>", nullptr));
        lineEditdep->setText(QString());
        lineEditdep->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\214\227\344\272\254", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "|", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#454545;\">\347\233\256\347\232\204\345\234\260\357\274\232</span></p></body></html>", nullptr));
        lineEditari->setText(QString());
        lineEditari->setPlaceholderText(QCoreApplication::translate("MainWindow", "\344\270\234\344\272\254", nullptr));
        layoutbutton->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\242\204\345\256\232\346\234\272\347\245\250</span></p></body></html>", nullptr));
        easystay->setText(QString());
        home_background->setText(QString());
        layoutbutton_2->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#454545;\">\345\207\272\350\241\214\346\227\245\346\234\237\357\274\232</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "|", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#454545;\">\346\237\245\350\257\242\346\235\241\344\273\266\357\274\232</span></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\231\272\350\203\275\346\243\200\347\264\242", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\350\264\271\347\224\250\346\234\200\345\260\221", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\234\200\347\237\255", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\345\217\252\347\234\213\347\233\264\351\243\236", nullptr));

        comboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\233\276\351\200\211\346\213\251", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "\302\251 2024 bjutSecurityst  |   \344\272\254ICP\345\244\2071145141919\345\217\267   |    \344\275\277\347\224\250\346\235\241\346\254\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H