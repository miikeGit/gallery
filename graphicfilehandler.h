#ifndef GRAPHICFILEHANDLER_H
#define GRAPHICFILEHANDLER_H

#include "graphicfile.h"

#include <QStringList>
#include <QPixmap>
#include <QStringList>

// Клас для керування вектором графічних файлів
class GraphicFileHandler {
private:
    QVector<GraphicFile> _images; // Вектор для зберігання графічних файлів
    int _currentIndex;            // Поточний індекс у наборі зображень
    int _rotationAngle;           // Кут повороту зображення
    qreal _zoomFactor;            // Коефіцієнт масштабування зображення

    // Допоміжна функція для поділу вектору при швидкому сортуванні
    int partition(int low, int high, std::function<bool(const GraphicFile&, const GraphicFile&)> compare);

public:
    // Конструктор за замовчуванням
    GraphicFileHandler() : _currentIndex(0), _zoomFactor(0.5), _rotationAngle(0) {}

    // Реалізація методу швидкого сортування
    void quickSort(int left, int right, std::function<bool(const GraphicFile&, const GraphicFile&)> compare);
    // Пошук файлів за діапазоном розмірів
    QVector<GraphicFile> searchBySizeRange(QVector<GraphicFile>& files, double minSize, double maxSize);
    // Навігація між зображеннями
    void nextImage();
    void prevImage();

    // Геттери
    int getIndex()                const { return _currentIndex; }
    int getRotationAngle()        const { return _rotationAngle; }
    qreal getZoomFactor()         const { return _zoomFactor; }
    GraphicFile getCurrentImage() const { return _images.at(_currentIndex); }
    QVector<GraphicFile>& getImages()   { return _images; }

    // Сеттери
    void setZoomFactor(double newFactor) { _zoomFactor = newFactor; }
    void setRotationAngle(int degrees)   { _rotationAngle = degrees; }
    void setIndex(int index)             { _currentIndex = index; }
};

#endif // GRAPHICFILEHANDLER_H
