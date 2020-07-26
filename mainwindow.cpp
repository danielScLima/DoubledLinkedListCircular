#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <vector>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateDotFile();
    updateImage();
    renderImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDotFile()
{
    std::ofstream myFile;
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    myFile.open
    (
        "file.dot"
    );

    std::string textToFile = "digraph g{";
    textToFile += "start[shape=none fontcolor=blue];";

    std::string names;

    auto vec = doubledLinkedListCircular.getElementsAsVector();
    for (int index = 0; index < vec.size(); ++index)
    {
        auto entry = vec.at(index);
        textToFile += entry;

        names += entry+" ";

        if (index < vec.size()-1)
        {
            textToFile += "->";
        }
    }

    if (vec.size() > 0)
        textToFile += ";";

    for (int index = vec.size()-1; index >=0; --index)
    {
        auto entry = vec.at(index);
        textToFile += entry;

        if (index > 0)
        {
            textToFile += "->";
        }
    }

    if (vec.size() > 0)
        textToFile += ";";

    if (vec.size()>1)
    {
        textToFile += vec.front()+"->"+vec.back()+";";
        textToFile += vec.back()+"->"+vec.front()+";";
    }

    if (vec.size() == 0)
    {
        textToFile += "NULL [ fontcolor=red ];start -> NULL;";
    }
    else
    {
        textToFile += "start -> "+vec.at(0)+";";
    }

    textToFile += "{";
    textToFile += "        rank = same;";
    textToFile += names;
    textToFile += "};";

    textToFile += "{";
    textToFile += "        rank = same;";
    textToFile += "        start";
    textToFile += "};";


    textToFile += "}";

    myFile << textToFile;
    myFile.close();
}

void MainWindow::updateImage()
{
    std::string message =
                "dot -Tpng file.dot > file.png";
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    system(message.c_str());
}

void MainWindow::renderImage()
{
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    QPixmap image("file.png");
    ui->labelOfImage->setPixmap(image);
    ui->labelOfImage->show();
}


void MainWindow::on_pushButton_clicked()
{
    std::string data = ui->lineEditHead->text().toStdString();

    doubledLinkedListCircular.insertBeforeStart(data);

    updateDotFile();
    updateImage();
    renderImage();
}

void MainWindow::on_pushButton_2_clicked()
{
    std::string data = ui->lineEditTail->text().toStdString();

    doubledLinkedListCircular.insertAfterStart(data);

    updateDotFile();
    updateImage();
    renderImage();
}

void MainWindow::on_pushButton_3_clicked()
{
    DoubledLinkedCircularNode* node =
            doubledLinkedListCircular.removeBeforeStart();

    if (node != nullptr)
        delete node;

    updateDotFile();
    updateImage();
    renderImage();
}

void MainWindow::on_pushButton_4_clicked()
{
    DoubledLinkedCircularNode* node =
            doubledLinkedListCircular.removeAfterStart();

    if (node != nullptr)
        delete node;

    updateDotFile();
    updateImage();
    renderImage();
}
