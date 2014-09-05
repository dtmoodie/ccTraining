#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	filters << "*.jpg";
	filters << "*.png";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString file = QFileDialog::getExistingDirectory(this, "Select root dir","C:/data/images/imts/negative");
    QDir dir(file);


    QFileInfoList files = dir.entryInfoList();
    for(int i = 0; i < files.size(); ++i)
    {
        if(files[i].isDir())
        {
			QString path = files[i].absoluteFilePath();
			QDir dir(path);
			QStringList entries = dir.entryList(filters);
			int numItems = entries.size();
            QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
            item->setText(0,files[i].absoluteFilePath());
            item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
            item->setCheckState(0,Qt::Checked);
			item->setText(1, QString::number(numItems));
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString file = QFileDialog::getSaveFileName(this, "Save file as","C:/data/images/imts/negative","*.txt");
	QFile out(file);
	
	if (!out.open(QIODevice::WriteOnly | QIODevice::Text)) return;
	QTextStream outStream(&out);
	for (int i = 0; i < ui->treeWidget->topLevelItemCount(); ++i)
	{
		if (ui->treeWidget->topLevelItem(i)->checkState(0) != Qt::Checked)
		{
			continue;
		}
		QStringList files = QDir(ui->treeWidget->topLevelItem(i)->text(0)).entryList(filters);
		for (int j = 0; j < files.size(); ++j)
		{
			QFileInfo info(ui->treeWidget->topLevelItem(i)->text(0));
			QString name = info.fileName() + "/" + files[j];
			outStream << name << "\n";
		}
	}
	out.close();
}
