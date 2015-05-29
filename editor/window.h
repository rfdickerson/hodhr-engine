#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QSlider;
class QPushButton;
class QTextEdit;
class QListWidget;

class GLWidget;
class MainWindow;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(MainWindow *mw);

protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;

private slots:
    void dockUndock();

private:
    QSlider *createSlider();

    GLWidget *glWidget;
    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;
    QPushButton *dockBtn;
    QPushButton *addPlaneBtn;
    MainWindow *mainWindow;
    QTextEdit *debugText;
    QListWidget *gameobjectList;

};

#endif // WINDOW_H
