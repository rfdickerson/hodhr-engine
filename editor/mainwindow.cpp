#include "mainwindow.h"
#include "window.h"

#include <QKeyEvent>
#include <QMenuBar>
#include <QMessageBox>

MainWindow::MainWindow()
{

    QMenuBar *menuBar = new QMenuBar();
    QMenu *menuWindow = menuBar->addMenu(tr("&Window"));
    // QAction *addNew = new QAction(menuWindow);

    // glWidget = new GLWidget;
    onAddNew();
}

void MainWindow::onAddNew()
{
    if (!centralWidget())
        setCentralWidget(new Window(this));
    else
        QMessageBox::information(0, tr("Cannot add new window"), tr("Already occupied. Undock first."));
}

