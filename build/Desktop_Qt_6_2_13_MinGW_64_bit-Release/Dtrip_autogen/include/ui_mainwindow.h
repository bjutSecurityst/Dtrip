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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
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
    QPushButton *pushButton_back;
    QScrollBar *verticalScrollBar;
    QLabel *labelicon0;
    QPushButton *backgroundsky;
    QWidget *verticalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEditdep;
    QLabel *label_12;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEditari;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
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
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QScrollBar *verticalScrollBar_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label_14;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line;
    QPushButton *pushButton_8;
    QFrame *line_2;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_3;
    QPushButton *pushButton_10;
    QScrollBar *verticalScrollBar_3;
    QPushButton *pushButton_9;
    QComboBox *comboBox_2;
    QWidget *widget;
    QPushButton *pushButton_11;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_16;
    QLabel *label_22;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_18;
    QLabel *label_17;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_21;
    QLabel *label_20;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_23;
    QLabel *label_24;
    QFrame *line_7;
    QLabel *label_19;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_25;
    QLabel *label_26;
    QFrame *line_9;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_27;
    QLabel *label_28;
    QWidget *widget_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_12;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QDateEdit *dateEdit_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModality::NonModal);
        MainWindow->resize(1280, 720);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ApplicationIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1.000000000000000);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setAnimated(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 151, 711));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 0, 0, 0);
        verticaltool = new QVBoxLayout();
        verticaltool->setObjectName(QString::fromUtf8("verticaltool"));
        verticaltool->setContentsMargins(2, -1, -1, -1);
        pushButton_0 = new QPushButton(horizontalLayoutWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("\350\217\234\345\215\225\346\240\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8("\350\217\234\345\215\225\346\240\217.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_0->setIcon(icon1);
        pushButton_0->setIconSize(QSize(68, 24));
        pushButton_0->setAutoDefault(true);
        pushButton_0->setFlat(false);

        verticaltool->addWidget(pushButton_0);

        pushButton_1 = new QPushButton(horizontalLayoutWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(70, 18));
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

        pushButton_back = new QPushButton(horizontalLayoutWidget);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        pushButton_back->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        pushButton_back->setIconSize(QSize(12, 20));

        verticaltool->addWidget(pushButton_back);


        horizontalLayout->addLayout(verticaltool);

        verticalScrollBar = new QScrollBar(horizontalLayoutWidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);
        verticalScrollBar->setInvertedAppearance(true);
        verticalScrollBar->setInvertedControls(false);

        horizontalLayout->addWidget(verticalScrollBar);

        labelicon0 = new QLabel(centralwidget);
        labelicon0->setObjectName(QString::fromUtf8("labelicon0"));
        labelicon0->setGeometry(QRect(230, 10, 311, 51));
        labelicon0->setScaledContents(true);
        backgroundsky = new QPushButton(centralwidget);
        backgroundsky->setObjectName(QString::fromUtf8("backgroundsky"));
        backgroundsky->setGeometry(QRect(180, 80, 701, 241));
        backgroundsky->setIconSize(QSize(300, 150));
        backgroundsky->setAutoDefault(false);
        backgroundsky->setFlat(false);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(210, 160, 511, 51));
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

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEditdep = new QLineEdit(verticalLayoutWidget_2);
        lineEditdep->setObjectName(QString::fromUtf8("lineEditdep"));
        lineEditdep->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        lineEditdep->setFrame(false);
        lineEditdep->setCursorPosition(0);

        horizontalLayout_4->addWidget(lineEditdep);

        label_12 = new QLabel(verticalLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(0, 0));
        label_12->setStyleSheet(QString::fromUtf8("color:rgb(143, 143, 143);\n"
"font: 12pt \"Microsoft YaHei UI\";"));
        label_12->setWordWrap(true);

        horizontalLayout_4->addWidget(label_12);


        verticalLayout->addLayout(horizontalLayout_4);


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

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEditari = new QLineEdit(verticalLayoutWidget_2);
        lineEditari->setObjectName(QString::fromUtf8("lineEditari"));
        lineEditari->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        lineEditari->setFrame(false);
        lineEditari->setCursorPosition(0);

        horizontalLayout_5->addWidget(lineEditari);

        label_13 = new QLabel(verticalLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(0, 0));
        label_13->setStyleSheet(QString::fromUtf8("color:rgb(143, 143, 143);\n"
"font: 12pt \"Microsoft YaHei UI\";"));
        label_13->setScaledContents(false);
        label_13->setWordWrap(true);

        horizontalLayout_5->addWidget(label_13);

        horizontalSpacer_3 = new QSpacerItem(15, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(0, 9);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 10);
        layoutbutton = new QPushButton(centralwidget);
        layoutbutton->setObjectName(QString::fromUtf8("layoutbutton"));
        layoutbutton->setGeometry(QRect(200, 150, 531, 71));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(200, 90, 111, 51));
        label_4->setStyleSheet(QString::fromUtf8("font: 18pt \"Microsoft YaHei UI\";"));
        label_4->setTextFormat(Qt::TextFormat::AutoText);
        label_4->setScaledContents(true);
        label_4->setWordWrap(false);
        easystay = new QPushButton(centralwidget);
        easystay->setObjectName(QString::fromUtf8("easystay"));
        easystay->setGeometry(QRect(670, 100, 181, 31));
        home_background = new QPushButton(centralwidget);
        home_background->setObjectName(QString::fromUtf8("home_background"));
        home_background->setGeometry(QRect(180, 80, 271, 71));
        layoutbutton_2 = new QPushButton(centralwidget);
        layoutbutton_2->setObjectName(QString::fromUtf8("layoutbutton_2"));
        layoutbutton_2->setGeometry(QRect(200, 230, 531, 71));
        verticalLayoutWidget_5 = new QWidget(centralwidget);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(210, 240, 511, 51));
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
        dateEdit->setDateTime(QDateTime(QDate(2024, 9, 20), QTime(16, 0, 0)));
        dateEdit->setMaximumDate(QDate(9999, 12, 31));
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(2024, 9, 20));

        verticalLayout_4->addWidget(dateEdit);


        horizontalLayout_3->addLayout(verticalLayout_4);

        label_6 = new QLabel(verticalLayoutWidget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 48pt \"Microsoft YaHei UI\";"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(verticalLayoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_7->setMargin(0);

        horizontalLayout_6->addWidget(label_7);

        checkBox = new QCheckBox(verticalLayoutWidget_5);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_6->addWidget(checkBox);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_5->addLayout(horizontalLayout_6);

        comboBox = new QComboBox(verticalLayoutWidget_5);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_5->addWidget(comboBox);


        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_3->setStretch(0, 9);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 10);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(760, 160, 91, 51));
        pushButton->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        pushButton->setCheckable(true);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(760, 240, 91, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("search.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8("search.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_4->setIcon(icon2);
        pushButton_4->setIconSize(QSize(12, 12));
        pushButton_4->setCheckable(true);
        pushButton_4->setAutoDefault(false);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(920, 80, 331, 561));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(440, 670, 381, 16));
        label_9->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(229, 350, 601, 281));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(260, 580, 531, 41));
        label_11->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";color: rgb(255, 255, 255);\n"
""));
        verticalScrollBar_2 = new QScrollBar(centralwidget);
        verticalScrollBar_2->setObjectName(QString::fromUtf8("verticalScrollBar_2"));
        verticalScrollBar_2->setGeometry(QRect(880, 350, 17, 299));
        verticalScrollBar_2->setMinimum(1);
        verticalScrollBar_2->setMaximum(999);
        verticalScrollBar_2->setPageStep(10);
        verticalScrollBar_2->setOrientation(Qt::Orientation::Vertical);
        verticalScrollBar_2->setInvertedAppearance(false);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(150, 350, 31, 31));
        pushButton_6->setStyleSheet(QString::fromUtf8("font: 16pt \"Microsoft YaHei UI\";"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(150, 620, 31, 31));
        pushButton_7->setStyleSheet(QString::fromUtf8("font: 16pt \"Microsoft YaHei UI\";"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(180, 320, 101, 31));
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(679, 20, 511, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_5);

        horizontalSpacer_4 = new QSpacerItem(11, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        line = new QFrame(horizontalLayoutWidget_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line);

        pushButton_8 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_8);

        line_2 = new QFrame(horizontalLayoutWidget_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_2);

        label_15 = new QLabel(horizontalLayoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_15->setMargin(0);

        horizontalLayout_7->addWidget(label_15);

        horizontalSpacer_5 = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        line_3 = new QFrame(horizontalLayoutWidget_2);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_3);

        pushButton_10 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setFlat(true);

        horizontalLayout_7->addWidget(pushButton_10);

        horizontalLayout_7->setStretch(0, 6);
        horizontalLayout_7->setStretch(3, 1);
        horizontalLayout_7->setStretch(5, 1);
        verticalScrollBar_3 = new QScrollBar(centralwidget);
        verticalScrollBar_3->setObjectName(QString::fromUtf8("verticalScrollBar_3"));
        verticalScrollBar_3->setGeometry(QRect(1231, 80, 16, 569));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalScrollBar_3->sizePolicy().hasHeightForWidth());
        verticalScrollBar_3->setSizePolicy(sizePolicy);
        verticalScrollBar_3->setMaximum(999);
        verticalScrollBar_3->setValue(0);
        verticalScrollBar_3->setOrientation(Qt::Orientation::Vertical);
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(490, 324, 31, 22));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(280, 324, 201, 22));
        comboBox_2->setInsertPolicy(QComboBox::InsertPolicy::InsertAtBottom);
        comboBox_2->setDuplicatesEnabled(false);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(940, 70, 321, 491));
        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(10, 0, 301, 481));
        verticalLayoutWidget_3 = new QWidget(widget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(20, 0, 281, 471));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_16 = new QLabel(verticalLayoutWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_16->setMargin(8);

        horizontalLayout_10->addWidget(label_16);

        label_22 = new QLabel(verticalLayoutWidget_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        horizontalLayout_10->addWidget(label_22);


        verticalLayout_6->addLayout(horizontalLayout_10);

        line_4 = new QFrame(verticalLayoutWidget_3);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShadow(QFrame::Shadow::Plain);
        line_4->setFrameShape(QFrame::HLine);

        verticalLayout_6->addWidget(line_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_18 = new QLabel(verticalLayoutWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_18->setMargin(8);

        horizontalLayout_8->addWidget(label_18);

        label_17 = new QLabel(verticalLayoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        horizontalLayout_8->addWidget(label_17, 0, Qt::AlignmentFlag::AlignHCenter);


        verticalLayout_6->addLayout(horizontalLayout_8);

        line_5 = new QFrame(verticalLayoutWidget_3);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShadow(QFrame::Shadow::Plain);
        line_5->setFrameShape(QFrame::HLine);

        verticalLayout_6->addWidget(line_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_21 = new QLabel(verticalLayoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_21->setMargin(8);

        horizontalLayout_9->addWidget(label_21);

        label_20 = new QLabel(verticalLayoutWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));

        horizontalLayout_9->addWidget(label_20, 0, Qt::AlignmentFlag::AlignHCenter);


        verticalLayout_6->addLayout(horizontalLayout_9);

        line_6 = new QFrame(verticalLayoutWidget_3);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShadow(QFrame::Shadow::Plain);
        line_6->setFrameShape(QFrame::HLine);

        verticalLayout_6->addWidget(line_6);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_23 = new QLabel(verticalLayoutWidget_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_23->setMargin(8);

        horizontalLayout_11->addWidget(label_23);

        label_24 = new QLabel(verticalLayoutWidget_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_24->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_11->addWidget(label_24);


        verticalLayout_6->addLayout(horizontalLayout_11);

        line_7 = new QFrame(verticalLayoutWidget_3);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShadow(QFrame::Shadow::Plain);
        line_7->setFrameShape(QFrame::HLine);

        verticalLayout_6->addWidget(line_7);

        label_19 = new QLabel(verticalLayoutWidget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_19->setMargin(8);

        verticalLayout_6->addWidget(label_19);

        line_8 = new QFrame(verticalLayoutWidget_3);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShadow(QFrame::Shadow::Plain);
        line_8->setFrameShape(QFrame::HLine);

        verticalLayout_6->addWidget(line_8);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_25 = new QLabel(verticalLayoutWidget_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_25->setMargin(8);

        horizontalLayout_12->addWidget(label_25);

        label_26 = new QLabel(verticalLayoutWidget_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_26->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_12->addWidget(label_26);


        verticalLayout_6->addLayout(horizontalLayout_12);

        line_9 = new QFrame(verticalLayoutWidget_3);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShadow(QFrame::Shadow::Plain);
        line_9->setFrameShape(QFrame::HLine);

        verticalLayout_6->addWidget(line_9);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_27 = new QLabel(verticalLayoutWidget_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_27->setMargin(8);

        horizontalLayout_13->addWidget(label_27);

        label_28 = new QLabel(verticalLayoutWidget_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_28->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_13->addWidget(label_28);


        verticalLayout_6->addLayout(horizontalLayout_13);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(179, 350, 721, 301));
        verticalLayoutWidget = new QWidget(widget_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 721, 301));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(560, 324, 221, 22));
        pushButton_12->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::GoDown")));
        pushButton_12->setIcon(icon3);
        pushButton_12->setIconSize(QSize(12, 9));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(560, 345, 221, 131));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setWidgetResizable(false);
        scrollArea->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 219, 119));
        scrollArea->setWidget(scrollAreaWidgetContents);
        dateEdit_2 = new QDateEdit(centralwidget);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(370, 30, 110, 22));
        checkBox_2 = new QCheckBox(centralwidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(500, 30, 121, 16));
        checkBox_3 = new QCheckBox(centralwidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(600, 30, 101, 16));
        MainWindow->setCentralWidget(centralwidget);
        widget_2->raise();
        backgroundsky->raise();
        layoutbutton_2->raise();
        home_background->raise();
        layoutbutton->raise();
        horizontalLayoutWidget->raise();
        labelicon0->raise();
        verticalLayoutWidget_2->raise();
        label_4->raise();
        easystay->raise();
        verticalLayoutWidget_5->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        verticalScrollBar_2->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        label_14->raise();
        horizontalLayoutWidget_2->raise();
        verticalScrollBar_3->raise();
        pushButton_9->raise();
        comboBox_2->raise();
        pushButton->raise();
        pushButton_4->raise();
        widget->raise();
        pushButton_12->raise();
        scrollArea->raise();
        dateEdit_2->raise();
        checkBox_2->raise();
        checkBox_3->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton_0->setDefault(false);
        pushButton_1->setDefault(false);
        comboBox->setCurrentIndex(-1);
        comboBox_2->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\276\244\347\251\252\346\227\205\350\241\214", nullptr));
        pushButton_0->setText(QString());
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "\350\210\252\347\217\255\346\237\245\350\257\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\351\200\200\346\224\271\347\245\250", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\351\243\236\350\241\214\344\277\241\346\201\257\347\273\237\350\256\241", nullptr));
        pushButton_back->setText(QCoreApplication::translate("MainWindow", "\345\220\216\345\217\260", nullptr));
        labelicon0->setText(QString());
        backgroundsky->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#454545;\">\345\207\272\345\217\221\345\234\260\357\274\232</span></p></body></html>", nullptr));
        lineEditdep->setText(QString());
        lineEditdep->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\214\227\344\272\254", nullptr));
        label_12->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "|", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#454545;\">\347\233\256\347\232\204\345\234\260\357\274\232</span></p></body></html>", nullptr));
        lineEditari->setText(QString());
        lineEditari->setPlaceholderText(QCoreApplication::translate("MainWindow", "\344\270\234\344\272\254", nullptr));
        label_13->setText(QString());
        layoutbutton->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\242\204\345\256\232\346\234\272\347\245\250</span></p></body></html>", nullptr));
        easystay->setText(QString());
        home_background->setText(QString());
        layoutbutton_2->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#454545;\">\345\207\272\350\241\214\346\227\245\346\234\237\357\274\232</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "|", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#454545;\">\346\237\245\350\257\242\346\235\241\344\273\266\357\274\232</span></p></body></html>", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\346\267\261\345\272\246\346\220\234\347\264\242", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\231\272\350\203\275\346\243\200\347\264\242", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\350\264\271\347\224\250\346\234\200\345\260\221", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\234\200\347\237\255", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\345\217\252\347\234\213\347\233\264\351\243\236", nullptr));

        comboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\233\276\351\200\211\346\213\251", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        label_8->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "\302\251 2024 bjutSecurityst  |   \344\272\254ICP\345\244\2071145141919\345\217\267   |    \344\275\277\347\224\250\346\235\241\346\254\276", nullptr));
        label_10->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "\345\271\277\345\221\212\344\275\215", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\347\224\250\346\227\266\357\274\232", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\346\210\221\347\232\204\350\256\242\345\215\225", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "  \346\262\241\346\234\211\345\256\242\346\234\215", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272<<", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "\346\216\222\345\272\217", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "\344\273\267\346\240\274-\345\215\207\345\272\217", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "\344\273\267\346\240\274-\351\231\215\345\272\217", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "\351\243\236\350\241\214\346\227\266\351\227\264-\345\215\207\345\272\217", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "\351\243\236\350\241\214\346\227\266\351\227\264-\351\231\215\345\272\217", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "\350\265\267\351\243\236\346\227\266\351\227\264-\345\215\207\345\272\217", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("MainWindow", "\350\265\267\351\243\236\346\227\266\351\227\264-\351\231\215\345\272\217", nullptr));
        comboBox_2->setItemText(6, QCoreApplication::translate("MainWindow", "\351\231\215\350\220\275\346\227\266\351\227\264-\345\215\207\345\272\217", nullptr));
        comboBox_2->setItemText(7, QCoreApplication::translate("MainWindow", "\351\231\215\350\220\275\346\227\266\351\227\264-\351\231\215\345\272\217", nullptr));
        comboBox_2->setItemText(8, QCoreApplication::translate("MainWindow", "\345\207\206\347\202\271\347\216\207-\351\231\215\345\272\217", nullptr));
        comboBox_2->setItemText(9, QCoreApplication::translate("MainWindow", "\345\207\206\347\202\271\347\216\207-\345\215\207\345\272\217", nullptr));

        comboBox_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\346\216\222\345\272\217\346\226\271\345\274\217", nullptr));
        pushButton_11->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\344\277\241\346\201\257\357\274\232", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\344\275\217\346\211\200\357\274\232", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\346\246\202\347\216\207\357\274\232", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\346\203\263\345\216\273\357\274\232", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\346\246\202\347\216\207\357\274\232", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\347\224\273\345\203\217\357\274\232", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\346\246\202\347\216\207\357\274\232", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\345\270\270\347\224\250\346\220\234\347\264\242\346\226\271\345\274\217\357\274\232", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\345\270\270\346\220\234\345\247\213\345\217\221\345\234\260\357\274\232", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\346\246\202\347\216\207\357\274\232", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\345\270\270\346\220\234\347\233\256\347\232\204\345\234\260\357\274\232", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\346\246\202\347\216\207\357\274\232", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\347\255\233\351\200\211\346\226\271\345\274\217  ", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\347\255\233\351\200\211\345\275\223\345\211\215\346\227\245\346\234\237\346\234\272\347\245\250", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\244\261\346\225\210\347\245\250\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
