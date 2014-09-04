#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString file = QFileDialog::getExistingDirectory(this, "Select root dir");
    QDir dir(file);
    QStringList filters;
    filters << ".jpg";
    filters << ".png";

    QFileInfoList files = dir.entryInfoList();
    for(int i = 0; i < files.size(); ++i)
    {
        if(files[i].isDir())
        {
            QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0,files[i].absoluteFilePath());
            item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
            item->setCheckState(0,Qt::Checked);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString file = QFileDialog::getSaveFileName(this, "Save file as");

}
