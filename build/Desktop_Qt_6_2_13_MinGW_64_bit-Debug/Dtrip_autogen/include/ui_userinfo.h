/********************************************************************************
** Form generated from reading UI file 'userinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userinfo
{
public:
    QPushButton *pushButton_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QProgressBar *progressBar;
    QLabel *label_6;
    QLabel *label_7;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *userinfo)
    {
        if (userinfo->objectName().isEmpty())
            userinfo->setObjectName(QString::fromUtf8("userinfo"));
        userinfo->resize(331, 492);
        pushButton_4 = new QPushButton(userinfo);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);
        pushButton_4->setGeometry(QRect(0, 50, 331, 441));
        pushButton_4->setCheckable(false);
        verticalLayoutWidget = new QWidget(userinfo);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 291, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(76, 76));
        label->setMaximumSize(QSize(76, 76));
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_3);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(34, 30));
        label_5->setMaximumSize(QSize(34, 30));
        label_5->setScaledContents(true);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_5);

        progressBar = new QProgressBar(verticalLayoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_2->addWidget(progressBar);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(34, 30));
        label_6->setMaximumSize(QSize(34, 30));
        label_6->setScaledContents(true);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_2);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_7);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 35));
        pushButton->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        pushButton->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/build/Desktop_Qt_6_2_13_MinGW_64_bit-Debug/to.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(10, 10));

        verticalLayout->addWidget(pushButton);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 35));
        pushButton_2->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(10, 10));

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 35));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/build/Desktop_Qt_6_2_13_MinGW_64_bit-Debug/shutdown.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(pushButton_3);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(userinfo);

        QMetaObject::connectSlotsByName(userinfo);
    } // setupUi

    void retranslateUi(QWidget *userinfo)
    {
        userinfo->setWindowTitle(QCoreApplication::translate("userinfo", "Form", nullptr));
        pushButton_4->setText(QString());
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("userinfo", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("userinfo", "\346\266\210\350\264\271\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("userinfo", "\351\207\214\347\250\213\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("userinfo", "\351\223\202\351\207\221", nullptr));
        label_6->setText(QCoreApplication::translate("userinfo", "\351\222\273\347\237\263", nullptr));
        label_7->setText(QCoreApplication::translate("userinfo", "\345\275\223\345\211\215\346\210\220\351\225\2778000\357\274\214\350\267\235\347\246\273\345\215\207\347\272\247\351\222\273\347\237\263\344\274\232\345\221\230 \350\277\230\351\234\200\350\246\20116000", nullptr));
        pushButton->setText(QCoreApplication::translate("userinfo", "\346\266\210\350\264\271\346\216\222\350\241\214\346\246\234                                      ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("userinfo", "\351\207\214\347\250\213\346\216\222\350\241\214\346\246\234                                      ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("userinfo", "\351\200\200\345\207\272\347\231\273\345\275\225     ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userinfo: public Ui_userinfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
