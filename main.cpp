#include <QApplication>
#include <QDirIterator>
#include <QFileDialog>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDirIterator it(QFileDialog::getExistingDirectory(), QStringList() << "*.png", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QImage img;
        QString path = it.next();
        qDebug()<<"load"<<path<<img.load(path);
        qDebug()<<"save"<<img.save(path);
    }
    qDebug()<<"DONE";

    return 0;
}
