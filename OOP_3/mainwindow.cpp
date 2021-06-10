#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config/registration_maker.h"
#include "config/config_manager.h"
#define FILENAME "model1.txt"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ConfigManagerCreator().get_manager()->registrate();

    this->_scene = new QGraphicsScene;
    ui->graphicsView->setScene(_scene);

    this->_dr_solution.registration(QT, DrawerFactoryCreator::createQtFactory);
    this->setup_scene();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_move_button_clicked()
{
    double x, y, z;
    x = ui->dx_box->value();
    y = ui->dy_box->value();
    z = ui->dz_box->value();
    size_t index = ui->to_model_Edit->text().toInt()-1;
    qDebug() << "main move" << x << y << z;
    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new MoveModel(x, y, z, index));
    Facade::instance()->execute(command);

    this->update_scene();

}

void MainWindow::on_scale_button_clicked()
{
    double x, y, z;
    x = ui->kx_box->value();
    y = ui->ky_box->value();
    z = ui->kz_box->value();
    size_t index = ui->to_model_Edit->text().toInt()-1;
    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new ScaleModel(x, y, z, index));
    Facade::instance()->execute(command);

    this->update_scene();
}

void MainWindow::on_turn_button_clicked()
{
    double x, y, z;
    x = ui->ox_box->value();
    y = ui->oy_box->value();
    z = ui->oz_box->value();
    size_t index = ui->to_model_Edit->text().toInt()-1;
    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new TurnModel(x, y, z, index));
    Facade::instance()->execute(command);

    this->update_scene();
}


void MainWindow::on_load_button_clicked()
{
    QString qs = ui->model_file->text();
    std::string filename = qs.toUtf8().constData();

    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new LoadModel(filename));
    Facade::instance()->execute(command);

    this->update_scene();


}

void MainWindow::on_add_camera_clicked()
{
    double x, y, z;
    x = ui->x_cam->text().toFloat();
    y = ui->y_cam->text().toFloat();
    z = 0;
    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new AddCamera(x, y, z));
    Facade::instance()->execute(command);

    this->update_scene();
}

void MainWindow::update_scene()
{
    std::shared_ptr<BaseCommand> dr_command = std::shared_ptr<BaseCommand>(new DrawScene(this->_drawer));
    Facade::instance()->execute(dr_command);
}

void MainWindow::setup_scene()
{
    shared_ptr<AbstractFactory> factory(this->_dr_solution.create(QT));
    factory->set_scene(this->_scene);
    this->_drawer = factory->create_graphics();
}

void MainWindow::on_load_camera_clicked()
{
    QString qs = ui->camera_file->text();
    std::string filename = qs.toUtf8().constData();

    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new LoadCamera(filename));
    Facade::instance()->execute(command);

    this->update_scene();
}

void MainWindow::on_pushButton_clicked()
{
    double x, y;
    x = 0;
    y = -50;
    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new MoveCamera(x, y));
    Facade::instance()->execute(command);

    this->update_scene();
}

void MainWindow::on_cam_left_clicked()
{
    double x, y;
    x = -50;
    y = 0;
    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new MoveCamera(x, y));
    Facade::instance()->execute(command);

    this->update_scene();
}

void MainWindow::on_cam_right_clicked()
{
    double x, y;
    x = 50;
    y = 0;
    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new MoveCamera(x, y));
    Facade::instance()->execute(command);

    this->update_scene();
}

void MainWindow::on_cam_down_clicked()
{
    double x, y;
    x = 0;
    y = 50;
    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new MoveCamera(x, y));
    Facade::instance()->execute(command);

    this->update_scene();
}

void MainWindow::on_load_scene_clicked()
{
    QString qs = ui->scene_file->text();
    std::string filename = qs.toUtf8().constData();

    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new LoadScene(filename));
    Facade::instance()->execute(command);

    this->update_scene();
}

void MainWindow::on_to_camera_clicked()
{
    size_t index;
    index = ui->to_cam_Edit->text().toInt();

    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new ToCamera(index-1));
    Facade::instance()->execute(command);

    this->update_scene();
}

void MainWindow::on_delete_model_clicked()
{
    size_t index;
    index = ui->del_model_Edit->text().toInt();

    std::shared_ptr<BaseCommand> command = std::shared_ptr<BaseCommand>(new RemoveModel(index-1));
    Facade::instance()->execute(command);

    this->update_scene();
}
