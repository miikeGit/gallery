#include "graphicfile.h"

#include <random>
#include <QImageWriter>
#include <QFileInfo>
#include <QMessageBox>

//Конструктор за замовчуванням
GraphicFile::GraphicFile()
    : _name("Default"),
      _width(0), _height(0),
      _size(0),
      _format("None"),
      _image(nullptr),
      _birthTime("Default"),
      _editingSoftware("None"),
      _isCompressed(false)
{}

 // Конструктор копіювання
GraphicFile::GraphicFile(const GraphicFile& other)
    : _name(other._name),
      _width(other._width),
      _height(other._height),
      _size(other._size),
      _format(other._format),
      _image(other._image.copy()),
      _birthTime(other._birthTime),
      _editingSoftware(other._editingSoftware),
      _isCompressed(other._isCompressed)
{}

// Конструктор з параметрами
GraphicFile::GraphicFile(QString name,
                         int width,
                         int height,
                         int size,
                         QString format,
                         QImage& image,
                         QString birthTime)

                        : _name(std::move(name)),
                          _width(width),
                          _height(height),
                          _size(size),
                          _format(std::move(format)),
                          _image(std::move(image)),
                          _birthTime(std::move(birthTime))
{
    initEditingSoftware();
    // Визначаємо чи зображення стиснуте на основі формату
    _isCompressed = _format == "bmp" ? false : true;
}

// Встановлення випадкового програмного забезпечення для редагування
void GraphicFile::initEditingSoftware() {
    static const std::vector<std::string> softwareOptions = {
        "Adobe Photoshop", "Adobe Lightroom", "Affinity Photo",
        "GIMP", "Capture One", "Paint"
    };
    static std::mt19937 rng(time(nullptr)); // Генератор випадкових чисел
    std::uniform_int_distribution<> dist(0, softwareOptions.size() - 1);
    _editingSoftware = QString::fromStdString(softwareOptions[dist(rng)]);
}

// Метод експорту зображення в інший формат
void GraphicFile::exportToFormat(const QString& newFormat, const QString& savePath) {
    if (!QImageWriter::supportedImageFormats().contains(newFormat.toLocal8Bit())) {
        QMessageBox::warning(nullptr, "Помилка", "Формат не підтримується.");
        return;
    }
    // присвоюємо новий формат
    _format = newFormat;
    // Забираємо з поля "ім'я" формат
    QString filePath = savePath + "/" + _name.chopped(4) + "." + newFormat;
    if (!_image.save(filePath, newFormat.toLocal8Bit())) {
        QMessageBox::warning(nullptr, "Помилка", "Не вийшло зберегти зображення.");
    } else {
        QMessageBox::information(nullptr, "Інформація", "Зображення успішно збережено як " + filePath);
    }
}

// Перевантажені оператори введення/виведення для роботи з файлами
QTextStream& operator<<(QTextStream& out, const GraphicFile& gf) {
    out << "Name: " << gf._name << "\n"
        << "Width: " << gf._width << " px\n"
        << "Height: " << gf._height << " px\n"
        << "Size: " << gf._size << " bytes\n"
        << "Format: " << gf._format << "\n"
        << "Birth Time: " << gf._birthTime << "\n"
        << "Editing Software: " << gf._editingSoftware << "\n"
        << "Compressed: " << (gf._isCompressed ? "Yes" : "No") << "\n";
    return out;
}

QTextStream& operator>>(QTextStream& in, GraphicFile& gf) {
    QString line = in.readLine();

    QFileInfo file(line);
    QImage image(line);

    if (image.isNull()) {
        QMessageBox::warning(nullptr, "Помилка", "Не вдалось імпортувати дані");
        return in;
    }

    gf._name = file.fileName();
    gf._width = image.width();
    gf._height = image.height();
    gf._size = file.size();
    gf._format = file.suffix();
    gf._birthTime = file.birthTime().toString("yyyy-MM-dd HH:mm:ss");
    gf._image = image;
    gf._isCompressed = gf._format == "bmp" ? false : true;
    gf.initEditingSoftware();

    return in;
}
