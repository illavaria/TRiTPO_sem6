/*MainWindow Class
Header: #include<MainWindow.h>

Properties:
pids_label_vector:      vector<QLabel*>                                   
threads_label_vector:   vector<QLabel*>                                
memory_label_vector:    vector<QLabel*>                                  
user_label_vector:      vector<QLabel*>                                   
name_label_vectorl:     vector<QLabel*>                                                              
cpuLabels:              vector<QLabel*> 
cpus:                   vector<QProgressBar*> 

processVectorTreatment: ProcessVectorTreatment 
systemInfo:             SystemInfo 


Public Functions

                        MainWindow(QWidget *parent = nullptr)
                        ~MainWindow()
void                    load_process_into_label()                                           
void                    loadSystemInfo()                                                     
void                    updateSystemInformation() 


Public Slots

void                    on_comboBox_currentTextChanged(const QString &arg1)                 
void                    on_pushButton_clicked()                                            
void                    on_pushButton_2_clicked()                                          
void                    on_pushButton_3_clicked()                                           
void                    on_pushButton_4_clicked()                                           
void                    themeButton()         


Member Type Documentation

pids_label_vector:vector<QLabel*>
-------------------------------------------
Поле содержит вектор parent id всех процессов

threads_label_vector:vector<QLabel*>
-------------------------------------------
Поле содержит вектор количества дочерних потоков каждого процесса

memory_label_vector:vector<QLabel*>
-------------------------------------------
Поле содержит вектор объемов оперативной памяти потребляемой каждым процессом

user_label_vector:vector<QLabel*>
-------------------------------------------
Поле содержит вектор имен пользователей, запустивших процессы

name_label_vector:vector<QLabel*>
-------------------------------------------
Поле содержит вектор имен процессов

cpuLabel:vector<QLabel*>
-------------------------------------------
Поле содержит вектор занимаемых ресурсов каждого ядра процессора

processVectorTreatment:ProcessVectorTreatment
-------------------------------------------
Поле содержит вектор всех процессов

systemInfo:SystemInfo
-------------------------------------------
Поле содержит собранную информацию о системе


Member Function Documentation

MainWindow::MainWindow(QWidget *parent = nullptr)
-------------------------------------------
Конструктор создает объект типа MainWindow, который является главным окном, 
и заполняет его информацией из полей класса

MainWindow::~MainWindow(QWidget *parent = nullptr)
-------------------------------------------
Деструктор уничтожает главное окно при завершении программы

void MainWindow::load_process_into_label()  
-------------------------------------------
Метод заполняет главное окно таблицей с информацией всех процессов

void MainWindow::loadSystemInfo() 
-------------------------------------------
Метод заполняет главное окно системной информацией

void MainWindow::updateSystemInformation() 
-------------------------------------------
Метод актуализирует информацию о занимаемых ресурсах каждого ядра процессора


Member Slots Documentation

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
-------------------------------------------
Метод описывает функционал выпадающего меню

void MainWindow::on_pushButton_clicked() 
-------------------------------------------
Метод описывает работу кнопки обновления информации

void MainWindow:: on_pushButton_2_clicked() 
-------------------------------------------
Метод описывает работу кнопки поиска процесса

void MainWindow::on_pushButton_3_clicked() 
-------------------------------------------
Метод описывает работу кнопки удаления процесса

void MainWindow::on_pushButton_4_clicked() 
-------------------------------------------
Метод описывает работу кнопки сохранения в файл

void MainWindow::themeButton() 
-------------------------------------------
Метод описывает работу кнопки смены цветовой темы приложения
*/


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
    void on_pushButton_4_clicked();                                           //метод, описывающий работу кнопки сохранения в файл
    void themeButton();                                                       //метод, описывающий работу включения/выключения темной темы


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
