#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(ueber_clicked_About()));
    connect(ui->actioninfo, SIGNAL(triggered(bool)), this, SLOT(ueber_clicked_info()));

}

    //Ägyptische Metode

void MainWindow::on_pushButton_Multi_clicked()
{
    QString xtext =ui->lineEdit_x->text();
    double x= xtext.toDouble();
    QString ytext =ui->lineEdit_y->text();
    double y=ytext.toDouble();
    std::vector<int> links, rechts;
    links.push_back(x);
    rechts.push_back(y);

    while(links.at(links.size()-1) != 1){
        links.push_back(links.at(links.size()-1)/2);
        rechts.push_back(rechts.at(rechts.size()-1)*2);
    }

    for(int i = 0; i < links.size(); i++){
        if(links.at(i) % 2 != 0){        
      double  Ergbnis = Ergbnis + rechts.at(i); // opt
      QString resultString = "";
      QVector<QString> resultS;

      ui->label_MalShow->setText(resultString.setNum(Ergbnis));

    }
        //um Methode zu anschauen
        QString linksS = "";
        for(int i = 0; i < links.size(); i++){
            linksS += QString::number(links.at(i))+" ";
        }

        QString rechtS = "";
        for(int i = 0; i < rechts.size(); i++){
            rechtS += QString::number(rechts.at(i))+" ";
        }

        QString linksAndrechts ="A  : " +linksS +"\n" + "B  : "+rechtS;

        ui->label_Methodeshow->setText(linksAndrechts);
    }
}

void MainWindow::on_pushButton_clear_clicked()
{
     ui->lineEdit_x->setText("");
     ui->lineEdit_y->setText("");
     ui->label_MalShow->setText("Danke..");
     ui->label_Methodeshow->setText("");
}

void MainWindow::ueber_clicked_About()
{
    QMessageBox::about(this ,"infos","Ägypter kannten die alten Methode, um schriftlich zu multiplizieren. Sie nutzen dabei die Eigenschaft aus, dass jeder Multiplikator als Summe von 2er Potenzen dargestellt werden kann. \nmore infos: https://de.wikipedia.org/wiki/Mathematik_im_Alten_Ägypten");
}

void MainWindow::ueber_clicked_info()
{
    QMessageBox::about(this ,"About"," infos unter:  \n hello@natouf.de  ");
}

MainWindow::~MainWindow()
{
    delete ui;
}
