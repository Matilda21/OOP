#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facade.h"
#include "command.h"
#include "./draw/drawer.h"
#include "./draw/factory.h"
#include "./draw/drawer_solution.h"
#include "./draw/drawer_factory_creator.h"
#define QT 1

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_move_button_clicked();

    void on_scale_button_clicked();

    void on_turn_button_clicked();

    void on_load_button_clicked();

    void on_add_camera_clicked();

    void update_scene();

    void setup_scene();

    void on_load_camera_clicked();

    void on_pushButton_clicked();

    void on_cam_left_clicked();

    void on_cam_right_clicked();

    void on_cam_down_clicked();

    void on_load_scene_clicked();

    void on_to_camera_clicked();

    void on_delete_model_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *_scene;
   // std::shared_ptr<Facade> _facade;
    std::shared_ptr<BaseDrawer> _drawer;
    DrawSolution _dr_solution;
};
#endif // MAINWINDOW_H
