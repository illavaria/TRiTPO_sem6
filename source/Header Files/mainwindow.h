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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void load_process_into_label();
    void loadSystemInfo();
    void updateSystemInformation();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();


private:
    std :: vector<QLabel*> pids_label_vector;
    std :: vector<QLabel*> threads_label_vector;
    std :: vector<QLabel*> memory_label_vector;
    std :: vector<QLabel*> user_label_vector;
    std :: vector<QLabel*> name_label_vectorl;
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
