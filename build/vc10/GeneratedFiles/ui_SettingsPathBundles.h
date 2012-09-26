/********************************************************************************
** Form generated from reading UI file 'SettingsPathBundles.ui'
**
** Created: Wed 26. Sep 14:41:16 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSPATHBUNDLES_H
#define UI_SETTINGSPATHBUNDLES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsPathBundles
{
public:
    QPushButton *btn_add;
    QPushButton *btn_delete;
    QPushButton *btn_ok;
    QPushButton *btn_cancel;
    QListWidget *pathBundleEntries;

    void setupUi(QWidget *SettingsPathBundles)
    {
        if (SettingsPathBundles->objectName().isEmpty())
            SettingsPathBundles->setObjectName(QString::fromUtf8("SettingsPathBundles"));
        SettingsPathBundles->setWindowModality(Qt::NonModal);
        SettingsPathBundles->resize(550, 219);
        btn_add = new QPushButton(SettingsPathBundles);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        btn_add->setEnabled(true);
        btn_add->setGeometry(QRect(490, 20, 20, 20));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_add->sizePolicy().hasHeightForWidth());
        btn_add->setSizePolicy(sizePolicy);
        btn_add->setMaximumSize(QSize(20, 20));
        btn_add->setCheckable(false);
        btn_delete = new QPushButton(SettingsPathBundles);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));
        btn_delete->setGeometry(QRect(510, 20, 20, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_delete->sizePolicy().hasHeightForWidth());
        btn_delete->setSizePolicy(sizePolicy1);
        btn_delete->setMaximumSize(QSize(20, 20));
        btn_ok = new QPushButton(SettingsPathBundles);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setGeometry(QRect(490, 150, 51, 23));
        btn_cancel = new QPushButton(SettingsPathBundles);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(490, 180, 51, 23));
        pathBundleEntries = new QListWidget(SettingsPathBundles);
        pathBundleEntries->setObjectName(QString::fromUtf8("pathBundleEntries"));
        pathBundleEntries->setGeometry(QRect(10, 10, 469, 199));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pathBundleEntries->sizePolicy().hasHeightForWidth());
        pathBundleEntries->setSizePolicy(sizePolicy2);
        pathBundleEntries->setGridSize(QSize(0, 22));

        retranslateUi(SettingsPathBundles);

        QMetaObject::connectSlotsByName(SettingsPathBundles);
    } // setupUi

    void retranslateUi(QWidget *SettingsPathBundles)
    {
        SettingsPathBundles->setWindowTitle(QApplication::translate("SettingsPathBundles", "Set Folder to search Bundles", 0, QApplication::UnicodeUTF8));
        btn_add->setText(QApplication::translate("SettingsPathBundles", "+", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("SettingsPathBundles", "-", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("SettingsPathBundles", "OK", 0, QApplication::UnicodeUTF8));
        btn_cancel->setText(QApplication::translate("SettingsPathBundles", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsPathBundles: public Ui_SettingsPathBundles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSPATHBUNDLES_H
