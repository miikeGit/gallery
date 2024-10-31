#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graphicfilehandler.h"

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Клас для взаємодії інтерфейсу з логічною частиною
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void loadImage(); // Завантаження зображення на першу сторінку віджета
    void updateImageInfo(); // Завантаження деталей зображення на першу сторінку віджета
    void loadImagesIntoList(QVector<GraphicFile> &images); // Оновлення списку зображень
private slots:

    // Сторінка 1
    void on_P1_toList_clicked(); // Кнопка для переходу на другу сторінку віджета
    void on_P1_rotate_clicked(); // Кнопка для повороту зображення на 90 градусів за годинниковою стрілкою
    void on_P1_delete_clicked(); // Кнопка для видалення зображення з списку

    void on_P1_zoomIn_clicked(); // Кнопка для збільшення маштабу
    void on_P1_zoomOut_clicked(); // Кнопка для зменшення масштабу

    void on_P1_nextImage_clicked(); // Навігація: наступне зображення
    void on_P1_prevImage_clicked(); // Навігація: попереднє зображення

    // Сторінка 2
    void on_P2_sort_currentIndexChanged(int index); // Сортування
    void on_P2_imageListView_itemClicked(QListWidgetItem *item); // Метод опрацювання кліку на зображення в списку
    void on_P2_imageListView_itemDoubleClicked(QListWidgetItem *item); // Те саме, але з подвійним кліком/перехід на першу сторінку віджета

    void on_P2_search_clicked(); // Пошук зображення за заданими параметрами
    void on_P2_displayMinMaxSize_clicked(); // Вивід зображень з найбльшим і найменшим розміром на диску
    void on_P2_searchInSizeRange_clicked(); // Відображення зображень в заданому діапазоні розміру на диску у МБ
    void on_P2_inDescending_toggled(bool checked); // Перемикач порядкку сортування (Спадаючий/Зростаючий)

    // Меню
    void on_M_openFolder_triggered(); // Відкрити папку
    void on_M_exportToFile_triggered(); // Експорт даних у файл
    void on_M_importFromFile_triggered(); // Імпорт даних з файлу
    void on_M_changeFormat_triggered(); // Експорт зображення у інший формат
    void on_M_createObject_triggered(); // Створення об'єксу з введеними даними з клавіатури

protected:
    // Метод перехоплення колеса миші для зміни масштабу
    void wheelEvent(QWheelEvent *event);
    // Метод перехоплення клавіш для перемикання між зображеннями
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    GraphicFileHandler* handler;
};

#endif // MAINWINDOW_H
