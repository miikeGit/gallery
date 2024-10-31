#include "graphicfilehandler.h"

QVector<GraphicFile> GraphicFileHandler::searchBySizeRange(QVector<GraphicFile>& files, double minSize, double maxSize) {
    QVector<GraphicFile> results;

    for (const GraphicFile& file : files)
        if (file.getSize() >= minSize && file.getSize() <= maxSize) // Якщо файл входить в заданий діапазон то додаємо його в кінцевий вектор
            results.append(file);

    return results;
}

int GraphicFileHandler::partition(int low, int high, std::function<bool(const GraphicFile&, const GraphicFile&)> compare) {
    // Обираємо елемент півотом (останній елемент у поточному діапазоні)
    GraphicFile pivot = _images[high];
    // Змінна i позначає межу елементів, менших за півот
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (compare(_images[j], pivot)) {
            i++; // Збільшуємо індекс для елемента, який менший за півот
            // Міняємо місцями поточний елемент з елементом на індексі i
            _images.swapItemsAt(i, j);
        }
    }
    // Міняємо місцями півот з елементом на позиції i+1
    _images.swapItemsAt(i + 1, high);
    // Повертаємо індекс півота (він уже на своєму правильному місці)
    return (i + 1);
}

void GraphicFileHandler::quickSort(int left, int right, std::function<bool(const GraphicFile&, const GraphicFile&)> compare) {
    if (left < right) { // Базова умова: якщо діапазон валідний
        int pi = partition(left, right, compare);
        // Рекурсивно сортуємо ліву частину (елементи, менші за піваот)
        quickSort(left, pi - 1, compare);
        // Рекурсивно сортуємо праву частину (елементи, більші за піваот)
        quickSort(pi + 1, right, compare);
    }
}

void GraphicFileHandler::prevImage() {
    // Попереднє зображення, якщо зараз не перше
    if (_currentIndex > 0) {
        _currentIndex--;
    } else {
        // В протилежному випадку повертаємось в кінець
        _currentIndex = _images.size() - 1;
    }
    // Скидаємо масштабування і кут повороту
    _zoomFactor = 0.5;
    _rotationAngle = 0;
}

void GraphicFileHandler::nextImage() {
    // Наступне зображення, якщо зараз не останнє
    if (_currentIndex < _images.size() - 1) {
        _currentIndex++;
    } else {
        // В протилежному випадку вертаємось на початок
        _currentIndex = 0;
    }
    // Скидаємо масштабування і кут повороту
    _zoomFactor = 0.5;
    _rotationAngle = 0;
}
