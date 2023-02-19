#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui :: MainWindow) {
    ui->setupUi(this);
    load_process_into_label();
    loadSystemInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: loadSystemInfo() {
    QString model, cores, ram;
    model = QString :: fromStdString(systemInfo.getModel());
    ui -> label_3 -> setText(model);
    cores = QString :: fromStdString(ConvertData :: itoa(systemInfo.getCoresNumber()));
    ui -> label_5 -> setText(cores);
    ram = QString :: fromStdString(ConvertData :: itoa(systemInfo.getTotalRam()));
    ui -> label_7 -> setText(ram);
    ui -> progressBar -> setValue(100 * systemInfo.getTotalRamUsage() / systemInfo.getTotalRam());
    ui -> verticalLayoutWidget_4 -> setMaximumSize(400, 48 * systemInfo.getCoresNumber());

    cpuLabels.resize(systemInfo.getCoresNumber());
    cpus.resize(systemInfo.getCoresNumber());

    for (int i = 0; i < systemInfo.getCoresNumber(); i++) {
        QLabel *l = new QLabel();
        QProgressBar *b = new QProgressBar();
        QString str = QString ::fromStdString("Core №" + ConvertData :: itoa(i + 1));
        l -> setText(str);
        b -> setValue(systemInfo.getSingleCoreCpuUsage(i));
        cpuLabels[i] = l;
        cpus[i] = b;
        ui -> verticalLayout_4 -> addWidget(cpuLabels[i]);
        ui -> verticalLayout_4 -> addWidget(cpus[i]);
    }
}

void MainWindow :: load_process_into_label() {
    ui -> tableWidget -> setColumnCount(5);
    ui -> tableWidget -> setRowCount(processVectorTreatment.getProcessVector().size());
    ui -> tableWidget -> setColumnWidth(0, 150);
    ui -> tableWidget -> setColumnWidth(1, 250);
    ui -> tableWidget -> setColumnWidth(2, 150);
    ui -> tableWidget -> setColumnWidth(3, 150);
    ui -> tableWidget -> setColumnWidth(4, 100);

    ui -> tableWidget -> verticalHeader() -> setVisible(0);

    switch (sorting_type) {
    case 0:
        processVectorTreatment.sortByPid();
        break;
    case 1:
        processVectorTreatment.sortByName();
        break;
    case 2:
        processVectorTreatment.sortByMemory();
        break;
    case 3:
        processVectorTreatment.sortByThreadNumber();
        break;
    default:
        break;
    }

    for (unsigned long i = 0; i < processVectorTreatment.getProcessVector().size(); i++) {
        QString pid, name, memory, threads, user;
        QTableWidgetItem* pidItem = new QTableWidgetItem();
        QTableWidgetItem* nameItem = new QTableWidgetItem();
        QTableWidgetItem* memoryItem = new QTableWidgetItem();
        QTableWidgetItem* threadsItem = new QTableWidgetItem();
        QTableWidgetItem* userItem = new QTableWidgetItem();

        pid = QString :: fromStdString(ConvertData :: itoa(processVectorTreatment.getProcessVector()[i].getPid()));
        pidItem -> setText(pid);
        ui -> tableWidget -> setItem(i, 0, pidItem);

        name = QString :: fromStdString(processVectorTreatment.getProcessVector()[i].getProcessName());
        nameItem -> setText(name);
        ui -> tableWidget ->setItem(i, 1, nameItem);

        memory = QString :: fromStdString(ConvertData :: convertMemory(processVectorTreatment.getProcessVector()[i].getMemory()));
        memoryItem -> setText(memory);
        ui -> tableWidget -> setItem(i, 2, memoryItem);

        threads = QString :: fromStdString(ConvertData ::itoa(processVectorTreatment.getProcessVector()[i].getThreads()));
        threadsItem -> setText(threads);
        ui -> tableWidget -> setItem(i, 3, threadsItem);

        user = QString :: fromStdString(processVectorTreatment.getProcessVector()[i].getUser());
        userItem -> setText(user);
        ui -> tableWidget -> setItem(i, 4, userItem);
    }

}


void MainWindow :: on_comboBox_currentTextChanged(const QString &arg1) {
    if (arg1.toStdString() == "PID") {
        sorting_type = 0;
        load_process_into_label();
    }
    if (arg1.toStdString() == "Name") {
        sorting_type = 1;
        load_process_into_label();
    }
    if (arg1.toStdString() == "Memory"){
        sorting_type = 2;
        load_process_into_label();
    }
    if (arg1.toStdString() == "Thread") {
        sorting_type = 3;
        load_process_into_label();
    }
}

void MainWindow :: on_pushButton_clicked() {
    processVectorTreatment.getProcessVector().clear();
    ProcessVectorTreatment temp;
    processVectorTreatment.setProcessVector(temp.getProcessVector());
    load_process_into_label();
}

void MainWindow :: on_pushButton_3_clicked(){
    int pid;
    pid = ui -> lineEdit -> text().toInt();
    if (pid == 0){
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "Danger attempt");
        messageBox.setFixedSize(1000, 300);
        ui->lineEdit->clear();
        return;
    }
    int returnSig = deleteProcess(pid);
    if (returnSig == -1){
        QMessageBox messageBox;
        messageBox.critical(0, "Error", "Error in killing process");
        messageBox.setFixedSize(1000, 300);
        ui->lineEdit->clear();
        return;
    }
    load_process_into_label();
    ui -> lineEdit -> clear();
}

void MainWindow :: on_pushButton_2_clicked() {
    std :: string name = "";
    name = ui -> lineEdit -> text().toStdString();
    if (name == "") {
        return;
    }
    ProcessVectorTreatment foundVector;
    foundVector.delete_process_vector();
    foundVector.setProcessVector(processVectorTreatment.findByName(name));
    ui -> tableWidget -> setRowCount(foundVector.getProcessVector().size());

    for (unsigned long i = 0; i < foundVector.getProcessVector().size(); i++) {
        QString pid, name, memory, threads, user;
        QTableWidgetItem* pidItem = new QTableWidgetItem();
        QTableWidgetItem* nameItem = new QTableWidgetItem();
        QTableWidgetItem* memoryItem = new QTableWidgetItem();
        QTableWidgetItem* threadsItem = new QTableWidgetItem();
        QTableWidgetItem* userItem = new QTableWidgetItem();

        pid = QString :: fromStdString(ConvertData :: itoa(foundVector.getProcessVector()[i].getPid()));
        pidItem -> setText(pid);
        ui -> tableWidget -> setItem(i, 0, pidItem);

        name = QString :: fromStdString(foundVector.getProcessVector()[i].getProcessName());
        nameItem -> setText(name);
        ui -> tableWidget ->setItem(i, 1, nameItem);

        memory = QString :: fromStdString(ConvertData :: convertMemory(foundVector.getProcessVector()[i].getMemory()));
        memoryItem -> setText(memory);
        ui -> tableWidget -> setItem(i, 2, memoryItem);

        threads = QString :: fromStdString(ConvertData ::itoa(foundVector.getProcessVector()[i].getThreads()));
        threadsItem -> setText(threads);
        ui -> tableWidget -> setItem(i, 3, threadsItem);

        user = QString :: fromStdString(foundVector.getProcessVector()[i].getUser());
        userItem -> setText(user);
        ui -> tableWidget -> setItem(i, 4, userItem);
    }
}

void MainWindow :: updateSystemInformation() {
    systemInfo.updateInfo();
    ui -> progressBar -> setValue(100 * systemInfo.getTotalRamUsage() / systemInfo.getTotalRam());
    for (int i = 0; i < systemInfo.getCoresNumber(); i++) {
        cpus[i] -> setValue(systemInfo.getSingleCoreCpuUsage(i));
    }
}















