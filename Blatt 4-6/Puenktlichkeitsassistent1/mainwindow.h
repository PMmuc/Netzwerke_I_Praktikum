#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "route.h"

namespace Ui {
class MainWindow;
}

QT_BEGIN_NAMESPACE
class TableModel;
class QItemSelection;
QT_END_NAMESPACE

class MyNetwork;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addEntry(Address& address);

    QString SetupMessage();

private slots:
    void AddNewWaypointDialog();
    void EditWaypointDialog();
    void RemoveWaypoint();
    void UpdateActions(const QItemSelection &selection);
    void CalcButtonPressed();
    void AboutDialog();
    void MoveUp();
    void MoveDown();

signals:
    void SelectionChanged(const QItemSelection &selected);
private:
    Ui::MainWindow *ui;
    MyNetwork *m_pNetwork;
    TableModel *m_pTableModel;
};

#endif // MAINWINDOW_H
