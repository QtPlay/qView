#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qvinfodialog.h"
#include <QMainWindow>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void updateRecentMenu();

    void refreshProperties();

    void toggleFullScreen();

    bool getIsPixmapLoaded();

public slots:
    void openFile(QString fileName);

    void saveFrame(QString fileName);

    void slideshowAction();

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

    void showEvent(QShowEvent *event) override;

    void closeEvent(QCloseEvent *event) override;

private slots:

    void loadSettings();

    void saveGeometrySettings();

    void on_actionOpen_triggered();

    void on_actionAbout_triggered();

    void on_actionPaste_triggered();

    void on_actionOptions_triggered();

    void on_actionPrevious_File_triggered();

    void on_actionNext_File_triggered();

    void on_actionOpen_Containing_Folder_triggered();

    void on_actionWelcome_triggered();

    void on_actionRotate_Right_triggered();

    void on_actionRotate_Left_triggered();

    void on_actionFlip_Horizontally_triggered();

    void on_actionFlip_Vertically_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionReset_Zoom_triggered();

    void openRecent(int i);

    void clearRecent();

    void on_actionProperties_triggered();

    void on_actionFull_Screen_triggered();

    void on_actionOriginal_Size_triggered();

    void on_actionNew_Window_triggered();

    void on_actionSlideshow_triggered();

    void on_actionPause_triggered();

    void on_actionNext_Frame_triggered();

    void on_actionReset_Speed_triggered();

    void on_actionDecrease_Speed_triggered();

    void on_actionIncrease_Speed_triggered();

    void on_actionSave_Frame_As_triggered();

    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;

    void pickFile();

    QMenu *menu;
    QMenu *dockMenu;

    QTimer *slideshowTimer;
    QList<QAction*> recentItems;

    QVInfoDialog *info;
};

#endif // MAINWINDOW_H
