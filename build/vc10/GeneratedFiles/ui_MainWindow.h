/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Wed 26. Sep 14:39:09 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionPathBundles;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionQuit;
    QAction *actionNew;
    QWidget *sceneWidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *sceneView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuSettings;
    QMenu *menuView;
    QDockWidget *dockL;
    QWidget *dockWidgetContentsL;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *dockLLayout;
    QPushButton *btn_dockRefreshBundles;
    QDockWidget *dockR;
    QWidget *dockWidgetContentsR;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *dockRLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(940, 742);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionPathBundles = new QAction(MainWindow);
        actionPathBundles->setObjectName(QString::fromUtf8("actionPathBundles"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        sceneWidget = new QWidget(MainWindow);
        sceneWidget->setObjectName(QString::fromUtf8("sceneWidget"));
        horizontalLayout_3 = new QHBoxLayout(sceneWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sceneView = new QGraphicsView(sceneWidget);
        sceneView->setObjectName(QString::fromUtf8("sceneView"));
        sceneView->setMaximumSize(QSize(4000, 4000));
        sceneView->setAutoFillBackground(false);
        sceneView->setFrameShape(QFrame::Panel);
        sceneView->setFrameShadow(QFrame::Sunken);
        sceneView->setLineWidth(1);
        sceneView->setSceneRect(QRectF(0, 0, 4000, 4000));
        sceneView->setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);
        sceneView->setResizeAnchor(QGraphicsView::NoAnchor);

        horizontalLayout_2->addWidget(sceneView);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(sceneWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 940, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menubar);
        dockL = new QDockWidget(MainWindow);
        dockL->setObjectName(QString::fromUtf8("dockL"));
        dockL->setMinimumSize(QSize(80, 44));
        dockL->setStyleSheet(QString::fromUtf8(""));
        dockL->setFloating(false);
        dockL->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContentsL = new QWidget();
        dockWidgetContentsL->setObjectName(QString::fromUtf8("dockWidgetContentsL"));
        dockWidgetContentsL->setEnabled(true);
        horizontalLayout = new QHBoxLayout(dockWidgetContentsL);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dockLLayout = new QVBoxLayout();
        dockLLayout->setSpacing(0);
        dockLLayout->setObjectName(QString::fromUtf8("dockLLayout"));
        btn_dockRefreshBundles = new QPushButton(dockWidgetContentsL);
        btn_dockRefreshBundles->setObjectName(QString::fromUtf8("btn_dockRefreshBundles"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_dockRefreshBundles->sizePolicy().hasHeightForWidth());
        btn_dockRefreshBundles->setSizePolicy(sizePolicy);
        btn_dockRefreshBundles->setMinimumSize(QSize(0, 0));
        btn_dockRefreshBundles->setMaximumSize(QSize(100, 20));
        btn_dockRefreshBundles->setLayoutDirection(Qt::LeftToRight);
        btn_dockRefreshBundles->setFlat(false);

        dockLLayout->addWidget(btn_dockRefreshBundles);


        horizontalLayout->addLayout(dockLLayout);

        dockL->setWidget(dockWidgetContentsL);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockL);
        dockR = new QDockWidget(MainWindow);
        dockR->setObjectName(QString::fromUtf8("dockR"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockR->sizePolicy().hasHeightForWidth());
        dockR->setSizePolicy(sizePolicy1);
        dockR->setMinimumSize(QSize(80, 97));
        dockR->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContentsR = new QWidget();
        dockWidgetContentsR->setObjectName(QString::fromUtf8("dockWidgetContentsR"));
        sizePolicy1.setHeightForWidth(dockWidgetContentsR->sizePolicy().hasHeightForWidth());
        dockWidgetContentsR->setSizePolicy(sizePolicy1);
        horizontalLayout_4 = new QHBoxLayout(dockWidgetContentsR);
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        dockRLayout = new QVBoxLayout();
        dockRLayout->setSpacing(0);
        dockRLayout->setObjectName(QString::fromUtf8("dockRLayout"));

        horizontalLayout_4->addLayout(dockRLayout);

        dockR->setWidget(dockWidgetContentsR);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockR);
        dockR->raise();

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionAbout);
        menuSettings->addAction(actionPathBundles);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(activated()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UberCode - Visually Generating the Future", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionPathBundles->setText(QApplication::translate("MainWindow", "Path Bundles", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        btn_dockRefreshBundles->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
