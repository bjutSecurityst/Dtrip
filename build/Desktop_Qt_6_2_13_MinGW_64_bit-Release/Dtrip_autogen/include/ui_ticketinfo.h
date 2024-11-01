/********************************************************************************
** Form generated from reading UI file 'ticketinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETINFO_H
#define UI_TICKETINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ticketInfo
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QFrame *line_3;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QWidget *ticketInfo)
    {
        if (ticketInfo->objectName().isEmpty())
            ticketInfo->setObjectName(QString::fromUtf8("ticketInfo"));
        ticketInfo->resize(1220, 101);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ticketInfo->sizePolicy().hasHeightForWidth());
        ticketInfo->setSizePolicy(sizePolicy);
        horizontalLayoutWidget = new QWidget(ticketInfo);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 1201, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 2, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft);
        label_2->setWordWrap(false);
        label_2->setIndent(-1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(15, 0));
        line->setMaximumSize(QSize(16777215, 50));
        line->setFrameShadow(QFrame::Shadow::Plain);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 19pt \"Microsoft Sans Serif\";"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayout_2->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(120, 15));
        label_4->setScaledContents(true);

        verticalLayout_4->addWidget(label_4);

        label_11 = new QLabel(horizontalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        verticalLayout_4->addWidget(label_11);

        verticalLayout_4->setStretch(0, 3);
        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 3);

        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 19pt \"Microsoft Sans Serif\";"));
        label_9->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        verticalLayout_3->addWidget(label_9);

        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayout_3->addWidget(label_10);


        horizontalLayout->addLayout(verticalLayout_3);

        line_2 = new QFrame(horizontalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(10, 0));
        line_2->setMaximumSize(QSize(16777215, 50));
        line_2->setFrameShadow(QFrame::Shadow::Plain);
        line_2->setFrameShape(QFrame::VLine);

        horizontalLayout->addWidget(line_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(label_5);

        line_3 = new QFrame(horizontalLayoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMinimumSize(QSize(0, 0));
        line_3->setMaximumSize(QSize(500, 10));
        line_3->setFrameShadow(QFrame::Shadow::Plain);
        line_3->setFrameShape(QFrame::HLine);

        verticalLayout_5->addWidget(line_3);

        label_12 = new QLabel(horizontalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_12->setFrameShape(QFrame::Shape::NoFrame);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(label_12);

        verticalLayout_5->setStretch(0, 5);
        verticalLayout_5->setStretch(1, 2);
        verticalLayout_5->setStretch(2, 5);

        horizontalLayout->addLayout(verticalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setStyleSheet(QString::fromUtf8("font: 17pt \"Microsoft Sans Serif\";color: rgb(255, 160, 8)"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_6);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(520, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(ticketInfo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 0, 1221, 101));
        pushButton_2->raise();
        horizontalLayoutWidget->raise();

        retranslateUi(ticketInfo);

        QMetaObject::connectSlotsByName(ticketInfo);
    } // setupUi

    void retranslateUi(QWidget *ticketInfo)
    {
        ticketInfo->setWindowTitle(QCoreApplication::translate("ticketInfo", "Form", nullptr));
        label->setText(QCoreApplication::translate("ticketInfo", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("ticketInfo", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("ticketInfo", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("ticketInfo", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("ticketInfo", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("ticketInfo", "-------------------", nullptr));
        label_11->setText(QCoreApplication::translate("ticketInfo", "TextLabel", nullptr));
        label_9->setText(QCoreApplication::translate("ticketInfo", "uu", nullptr));
        label_10->setText(QCoreApplication::translate("ticketInfo", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("ticketInfo", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("ticketInfo", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("ticketInfo", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("ticketInfo", "PushButton", nullptr));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ticketInfo: public Ui_ticketInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETINFO_H
