#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QLayoutItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QTableWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>

#include "ConvertData.h"
#include <ProcessesInfo.h>
#include <ProcessVectorTreatment.h>
#include "SystemInfo.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow                                           //класс, отвечающий за отображение всей собранной информации
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void load_process_into_label();                                            //метод загрузки вектора с процессами в таблицу
    void loadSystemInfo();                                                     //метод загрузки системной информации
    void updateSystemInformation();                                            //метод актуализации системной информации

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);                 //описание работы выпадающего меню
    void on_pushButton_clicked();                                             //метод, описывающий работу кнопки обновления информации
    void on_pushButton_2_clicked();                                           //метод, описывающий работу функции поиска процесса
    void on_pushButton_3_clicked();                                           //метод, описывающий работу функции удаления процесса


private:
    std :: vector<QLabel*> pids_label_vector;                                   //вектор для отображения системных идентификаторов
    std :: vector<QLabel*> threads_label_vector;                                //вектор для отображения количества потоков
    std :: vector<QLabel*> memory_label_vector;                                 //вектор для отображения потребляемой памяти
    std :: vector<QLabel*> user_label_vector;                                   //вектор отображения имен пользователей
    std :: vector<QLabel*> name_label_vectorl;                                  //вектор отображения имен процессов                            
    std :: vector<QLabel*> cpuLabels;
    std :: vector<QProgressBar*> cpus;

    int sorting_type = 0;
    QGridLayout *g = new QGridLayout();
    std :: vector<QHBoxLayout*> h;

    ProcessVectorTreatment processVectorTreatment;
    SystemInfo systemInfo;
    Ui :: MainWindow *ui;
};
#endif // MAINWINDOW_H
