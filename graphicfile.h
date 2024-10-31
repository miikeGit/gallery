#ifndef GRAPHICFILE_H
#define GRAPHICFILE_H

#include <QString>
#include <QImage>
#include <QTextStream>

// Відповідає за зберігання інформації про графічний файл
class GraphicFile {
private:
    QString _name;         // Назва файлу
    int _width;            // Ширина зображення у пікселях
    int _height;           // Висота зображення у пікселях
    int _size;             // Розмір файлу у байтах
    QString _format;       // Формат файлу (наприклад, "jpg", "png")
    QString _birthTime;    // Час створення файлу
    QString _editingSoftware; // Програмне забезпечення, використане для редагування файлу
    QImage _image;         // Зображення
    bool _isCompressed;    // Чи є файл стиснутим

public:
    GraphicFile();                         // Конструктор за замовчуванням
    GraphicFile(const GraphicFile& other); // Конструктор копіювання
    GraphicFile(QString name,             // Конструктор з параметрами
                int width,
                int height,
                int size,
                QString format,
                QImage& image,
                QString
                birthTime);

    // Статичний метод для пошуку файлів за діапазоном розмірів
    static QVector<GraphicFile> searchBySizeRange(const QVector<GraphicFile>& files, double minSize, double maxSize);
    // Метод для експорту зображення у новий формат
    void exportToFormat(const QString& newFormat, const QString& savePath);
    // Метод для присвоєння випадкового програмного забезпечення для редагування
    void initEditingSoftware();

    // ------------- Геттери -------------
    QString getName()            const { return _name; }
    int getWidth()               const { return _width; }
    int getHeight()              const { return _height; }
    int getSize()                const { return _size; }
    QString getFormat()          const { return _format; }
    QString getBirthTime()       const { return _birthTime; }
    QString getEditingSoftware() const { return _editingSoftware; }
    QImage getImage()            const { return _image; }
    bool isCompressed()          const { return _isCompressed; }

    // ------------- Оператори -------------
    // Дружні функції для введення-виведення
    friend QTextStream& operator<<(QTextStream& out, const GraphicFile& gf);
    friend QTextStream& operator>>(QTextStream& in, GraphicFile& gf);
};

#endif // GRAPHICFILE_H
