#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"

std::string default_output = "Enter number of rows and number of cols, please!";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_rows->setValidator(new QIntValidator(1, 99, this));
    ui->lineEdit_cols->setValidator(new QIntValidator(1, 99, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString raw_rows = ui->lineEdit_rows->text();
    QString raw_cols = ui->lineEdit_cols->text();
    int rows = raw_rows.split(" ")[0].toInt();
    int cols = raw_cols.split(" ")[0].toInt();
    Matrix *mx = new Matrix(rows, cols);
    mx->fill_array();
    mx->generate_spiral_string();
    ui->plainTextEdit_2->clear();
    if (mx->get_array_string().length() > 0)
    {
        ui->plainTextEdit_2->insertPlainText(QString::fromStdString(mx->get_array_string()));
    } else
    {
        ui->plainTextEdit_2->appendPlainText(QString::fromStdString(default_output));
    }
    delete mx;
}
