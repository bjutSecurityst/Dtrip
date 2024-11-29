/********************************************************************************
** Form generated from reading UI file 'userrankinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.2.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERRANKINFO_H
#define UI_USERRANKINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userRankInfo
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *userRankInfo)
    {
        if (userRankInfo->objectName().isEmpty())
            userRankInfo->setObjectName(QString::fromUtf8("userRankInfo"));
        userRankInfo->resize(270, 31);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(userRankInfo->sizePolicy().hasHeightForWidth());
        userRankInfo->setSizePolicy(sizePolicy);
        userRankInfo->setMinimumSize(QSize(200, 30));
        horizontalLayoutWidget = new QWidget(userRankInfo);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(-1, 0, 271, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(20, 0));
        label->setMaximumSize(QSize(20, 16777215));

        horizontalLayout->addWidget(label);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 4);

        retranslateUi(userRankInfo);

        QMetaObject::connectSlotsByName(userRankInfo);
    } // setupUi

    void retranslateUi(QWidget *userRankInfo)
    {
        userRankInfo->setWindowTitle(QCoreApplication::translate("userRankInfo", "Form", nullptr));
        label->setText(QCoreApplication::translate("userRankInfo", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("userRankInfo", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("userRankInfo", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userRankInfo: public Ui_userRankInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERRANKINFO_H
