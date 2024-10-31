#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphicfile.h"
#include "graphicfilehandler.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QImageWriter>
#include <QInputDialog>
#include <QProgressDialog>
#include <string>
\
// Конструктор, ініціалізуємо UI
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Приховати навігацію поки зображення не завантажено
    ui->P1_nextImage->hide();
    ui->P1_prevImage->hide();

    handler = new GraphicFileHandler();
}

// Деструтктор, очищаємо виділену пам'ять
MainWindow::~MainWindow() {
    delete ui;
    delete handler;
}

// Відкриття папки та завантаження зображень
void MainWindow::on_M_openFolder_triggered() {

    // Вікно вибору папки
    QString folderPath = QFileDialog::getExistingDirectory(this, "Виберіть папку", "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    QStringList imagePaths;

    if (folderPath.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Папку не вибрано!");
        return;
    }

    QDir dir(folderPath);
    if (!dir.exists()) {
        QMessageBox::warning(this, "Помилка", "Папки не існує, або недостатньо прав доступу.");
        return;
    }

    // Завантажуємо зображення з лише заданими форматами
    QStringList filters;
    filters << "*.png" << "*.bmp" << "*.jpg" << "*.jpeg";
    imagePaths = dir.entryList(filters, QDir::Files | QDir::Readable, QDir::Name);

    if (imagePaths.isEmpty()) {
        QMessageBox::information(this, "Інформація", "В папці не знайдено фото");
        return;
    }

    // Ресет хендлера в випадку повторного завантаження з папки
    handler->getImages().clear();
    handler->setIndex(0);

    // Діалогове вікно з прогресом завантаження
    QProgressDialog progressDialog("Завантаження фото...", "Скасувати", 0, imagePaths.size(), this);
    // Заборона під час цього взаємодії з іншими елементами вікна
    progressDialog.setWindowModality(Qt::WindowModal);
    // Миттєвий запуск прогресу завантаження в секундах (по дефолту 4 секунди)
    progressDialog.setMinimumDuration(0);

    for (int i = 0; i < imagePaths.size(); ++i) {

        if (progressDialog.wasCanceled()) {
            QMessageBox::warning(this, "Помилка", "Завантажено не всі зображення");
            break;
        }

        // Оновлення прогресу
        progressDialog.setValue(i);
        progressDialog.setLabelText(tr("Завантажено зображення %1 з %2").arg(i).arg(imagePaths.size()));

        imagePaths[i] = dir.absoluteFilePath(imagePaths[i]);
        QFileInfo file(imagePaths[i]);
        QImage image(imagePaths[i]);

        handler->getImages().append(GraphicFile(file.fileName(),
                                                image.width(),
                                                image.height(),
                                                file.size() / 1024,
                                                file.suffix(),
                                                image,
                                                file.birthTime().toString("yyyy-MM-dd HH:mm:ss")));
    }

    progressDialog.setValue(imagePaths.size());

    // Можна показати навігаційні кнопки
    ui->P1_nextImage->show();
    ui->P1_prevImage->show();

    // Завантаження зображення на першу сторінку
    loadImage();
    // Завантаження зображень на другу сторінку
    loadImagesIntoList(handler->getImages());
}

void MainWindow::loadImage() {

    // На випадок помилкового виклику функції
    if (handler->getIndex() < 0 || handler->getIndex() >= handler->getImages().size()) return;

    // Присвоюємо масштабування та обертання
    QPixmap pixmap = QPixmap::fromImage(handler->getCurrentImage().getImage());
    pixmap = pixmap.scaled(pixmap.size() * handler->getZoomFactor(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    pixmap = pixmap.transformed(QTransform().rotate(handler->getRotationAngle()));

    if (!pixmap.isNull()) {
        ui->P1_mainImageView->setPixmap(pixmap);
        updateImageInfo();
    } else {
        ui->P1_mainImageView->setText("Помилка при завантаженні зображення");
    }
}

// Заповнюємо інформаційні поля на першій сторінці віджета
void MainWindow::updateImageInfo() {
    GraphicFile currentImage = handler->getCurrentImage();
    ui->P1_resolution->setText(tr("%1 x %2 px").arg(currentImage.getWidth()).arg(currentImage.getHeight()));
    ui->P1_name->setText(currentImage.getName());
    ui->P1_size->setText(tr("%1 KB").arg(currentImage.getSize()));
    ui->P1_scale->setText(tr("Масштаб: %1%").arg(static_cast<int>(handler->getZoomFactor() * 100)));
}

// Зміна масштабу реагує на колесо миші
void MainWindow::wheelEvent(QWheelEvent *event) {
    // Отримуємо новий масштаб в залежності від прокруту колеса
    qreal zoomChange = event->angleDelta().y() > 0 ? 1.05 : 0.95;
    // Встановлюємо новий масштаб
    handler->setZoomFactor(handler->getZoomFactor() * zoomChange);
    // Завантажуємо зображення з новим масштабом
    loadImage();
}

// Перемикання між зображеннями через клавіші стрілок
void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Right:
        on_P1_nextImage_clicked();
        break;
    case Qt::Key_Left:
        on_P1_prevImage_clicked();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}

// Збільшення масштабу
void MainWindow::on_P1_zoomIn_clicked() {
    // Перевірка на наявність зображення
    if (handler->getImages().isEmpty()) {
        QMessageBox::information(this, "Інформація", "Зображення не завантажено");
        return;
    }

    // Встановлюємо новий масштаб
    handler->setZoomFactor(handler->getZoomFactor() + 0.1);
    // Завантажуємо зображення з новим масштабом
    loadImage();
}

// Зменшення масштабу
void MainWindow::on_P1_zoomOut_clicked() {
    // Перевірка на наявність зображення
    if (handler->getImages().isEmpty()) {
        QMessageBox::information(this, "Інформація", "Зображення не завантажено");
        return;
    }

    // Обмеження мінімального масштабу
    if (handler->getZoomFactor() <= 0.1) return;
    // Встановлюємо новий масштаб
    handler->setZoomFactor(handler->getZoomFactor() - 0.1);
    // Завантажуємо зображення з новим масштабом
    loadImage();
}

// Поворот зображення на 90 градусів за годинниковою стрілкою
void MainWindow::on_P1_rotate_clicked() {
    // Перевірка на наявність зображення
    if (handler->getImages().isEmpty()) {
        QMessageBox::information(this, "Інформація", "Зображення не завантажено");
        return;
    }
    // Встановлення нового куту повороту
    handler->setRotationAngle(handler->getRotationAngle() + 90);
    // Завантажуємо обернене зображення
    loadImage();
}

// Видалення зображення з списку
void MainWindow::on_P1_delete_clicked() {
    // Перевірка на наявність зображення
    if (handler->getImages().isEmpty()) {
        QMessageBox::information(this, "Інформація", "Зображення не завантажено");
        return;
    }
    // Уточнюємо в користувача чи він впевнений в своїх діях
    QMessageBox::StandardButton reply =
            QMessageBox::question(this, "Підтвердження", "Ви дійсно хочете видалити це зображення?",
                                  QMessageBox::Yes |
                                  QMessageBox::No);

    // Виходимо з функції, якщо користувач передмуав
    if (reply == QMessageBox::No) return;

    // В іншому випадку видаляємо зображення з списку
    handler->getImages().removeAt(handler->getIndex());

    // Якщо зображення було останнім в списку
    if (handler->getImages().isEmpty()) {
        // Очищаємо всі поля та скидаємо поточний індекс
        handler->setIndex(-1);
        ui->P2_imageListView->clear();
        ui->P2_imagePreview->clear();
        ui->P2_imageDetails->clear();
        ui->P1_resolution->clear();
        ui->P1_size->clear();
        ui->P1_name->clear();
        ui->P1_mainImageView->setText("Зображення не завантажено.");

        // Знову приховуємо кнопки навігації
        ui->P1_nextImage->hide();
        ui->P1_prevImage->hide();
    } else { // Якщо в списку ще є зображення
        // Декрементуємо індекс
        if (handler->getIndex() >= handler->getImages().size()) {
            handler->setIndex(handler->getIndex() - 1);
        }
        // Завантажуємо попереднє зображення
        loadImage();
        // Оновлюємо список
        loadImagesIntoList(handler->getImages());
    }
}

// Навігація: попереднє зображення
void MainWindow::on_P1_prevImage_clicked() {
    handler->prevImage();
    loadImage();
}

// Навігація: наступне зображення
void MainWindow::on_P1_nextImage_clicked() {
    handler->nextImage();
    loadImage();
}


// Відкрити другу сторінку віджета з списком
void MainWindow::on_P1_toList_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

// Оновити список зображень
void MainWindow::loadImagesIntoList(QVector<GraphicFile> &images) {
    // Очищаємо поле в разі, якщо до цього були зображення
    ui->P2_imageListView->clear();

    for (const GraphicFile &file : images) {
        QListWidgetItem *item = new QListWidgetItem();
        // Додаємо Ім'я зображеняя
        item->setText(file.getName());

        // Додаємо прев'ю
        QPixmap pixmap = QPixmap::fromImage(file.getImage().scaled(64, 64, Qt::KeepAspectRatio, Qt::FastTransformation));
        item->setIcon(QIcon(pixmap));

        ui->P2_imageListView->addItem(item);
    }
}

// Перехід на першу сторіну при подвійому кліку на зображення
void MainWindow::on_P2_imageListView_itemDoubleClicked(QListWidgetItem *item) {

    // Знаходимо індекс вибраного зображення
    QString clickedFileName = item->text();
    for (int i = 0; i < handler->getImages().size(); ++i) {
        if (handler->getImages()[i].getName() == clickedFileName) {
            // Встановлюємо його як поточний
            handler->setIndex(i);
            break;
        }
    }

    // Завантажуємо зображеннмя під поточним індексом
    loadImage();
    // Перемикаємо сторінку віджета на першу
    ui->stackedWidget->setCurrentIndex(0);
}

// Сортування
void MainWindow::on_P2_sort_currentIndexChanged(int index) {
    // Очищаємо поля з пошуком в діапазоні
    ui->P2_minSize->clear();
    ui->P2_maxSize->clear();
    // Нічого сортувати - вихід з функції
    if (handler->getImages().size() <= 1) return;

    // Вибір порядку сортування
    bool sortInAscending = ui->P2_inAscending->isChecked();
    auto& files = handler->getImages();
    switch (index) {
    case 0: // Сортування за іменем
        handler->quickSort(0, files.size() - 1, [&sortInAscending](const GraphicFile& a, const GraphicFile& b) {
            return sortInAscending ? a.getName() < b.getName() : a.getName() > b.getName();
        });
        break;
    case 1: // За розміром
        handler->quickSort(0, files.size() - 1, [&sortInAscending](const GraphicFile& a, const GraphicFile& b) {
            return sortInAscending ? a.getSize() < b.getSize() : a.getSize() > b.getSize();
        });
        break;
    case 2: // За шириною
        handler->quickSort(0, files.size() - 1, [&sortInAscending](const GraphicFile& a, const GraphicFile& b) {
            return sortInAscending ? a.getWidth() < b.getWidth() : a.getWidth() > b.getWidth();
        });
        break;
    case 3: // За висотою
        handler->quickSort(0, files.size() - 1, [&sortInAscending](const GraphicFile& a, const GraphicFile& b) {
            return sortInAscending ? a.getHeight() < b.getHeight() : a.getHeight() > b.getHeight();
        });
        break;
    }

    // Виводимо посортований список
    loadImagesIntoList(handler->getImages());
}

// Відображення детальної інформації при кліку на зображення
void MainWindow::on_P2_imageListView_itemClicked(QListWidgetItem *item) {
    // Шукаємо індекс заданого зображення
    QString clickedFileName = item->text();
    for (int i = 0; i < handler->getImages().size(); ++i) {
        if (handler->getImages()[i].getName() == clickedFileName) {
            // Встановлюємо його як поточний
            handler->setIndex(i);
            break;
        }
    }

    // В міні-вікні виводимо збільшене прев'ю
    QPixmap pixmap = QPixmap::fromImage(handler->getCurrentImage().getImage().scaled(256, 256, Qt::KeepAspectRatio, Qt::FastTransformation));
    ui->P2_imagePreview->setPixmap(pixmap);
    // Виводимо деталі зображення, такі як:
    ui->P2_imageDetails->setText(QString("Ім'я:\t\t\t%1\n"
                                         "Розмір:\t\t\t%2 KB\n"
                                         "Формат:\t\t%3\n"
                                         "Розширення:\t\t%4 x %5\n"
                                         "Дата створення:\t%6\n"
                                         "ПЗ для редагування:\t%7\n"
                                         "Стиснуто?:\t\t%8")

                                         .arg(handler->getCurrentImage().getName())
                                         .arg(handler->getCurrentImage().getSize())
                                         .arg(handler->getCurrentImage().getFormat())
                                         .arg(handler->getCurrentImage().getImage().width())
                                         .arg(handler->getCurrentImage().getImage().height())
                                         .arg(handler->getCurrentImage().getBirthTime())
                                         .arg(handler->getCurrentImage().getEditingSoftware())
                                         .arg(handler->getCurrentImage().isCompressed() ? "Так" : "Ні")
    );
}

// Пошук зображення за заданими параметрами
void MainWindow::on_P2_search_clicked() {
    int width = ui->P2_widthFilter->text().toInt();
    int height = ui->P2_heightFilter->text().toInt();
    double size = ui->P2_sizeFilter->text().toDouble();
    QString format = ui->P2_formatFilter->currentText();

    QVector<GraphicFile> filteredFiles;
    const auto& images = handler->getImages();
    for (const GraphicFile &file : images) {
        // Якщо поле пусте, його як параметр не враховуємо
        bool matchWidth = (width == 0 || file.getWidth() == width);
        bool matchHeight = (height == 0 || file.getHeight() == height);
        bool matchSize = (size == 0 || file.getSize() == size);
        bool matchFormat = format == "Формат" || file.getFormat().toUpper() == format.toUpper();

        // Якщо зображення знайдено
        if (matchWidth && matchHeight && matchSize && matchFormat) {
            filteredFiles.append(file);
        }
    }

    // Пошук невдалий
    if (filteredFiles.isEmpty()) {
        QMessageBox::information(this, "Результат пошуку", "Жодне зображення не відповідає заданим параметрам.");
    }

    // Виводимо зображення, що підійшли за параметрами
    loadImagesIntoList(filteredFiles);
}

// Експорт даних у файл
void MainWindow::on_M_exportToFile_triggered() {
    // Перевірка на наявність зображення
    if (handler->getImages().isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Зображення не завантажено.");
        return;
    }

    // Відкриваємо вікно для збереження файлу
    QString filter = "Text Files (*.txt);;All Files (*)";
    QString fileName = QFileDialog::getSaveFileName(this, "Зберегти файл", QDir::homePath() + "/default.txt", filter);

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << handler->getCurrentImage();
            file.close();
            QMessageBox::information(this, "Інформація", "Файл успішно збережено.");
        } else {
            QMessageBox::warning(this, "Помилка", "Неможливо відкрити файл для запису.");
        }
    }
}

// Імпорт даних з файлу
void MainWindow::on_M_importFromFile_triggered() {
    // Відкриваємо вікно вибору файлу
    QString filter = "Text Files (*.txt)";
    QString fileName = QFileDialog::getOpenFileName(this, "Відкрити текстовий файл", QDir::homePath(), filter);

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            // Створюємо об'єкт та зчитуємо у нього дані
            GraphicFile gf;
            in >> gf;
            // Якщо не вдалось зчитати - вихід з функції
            if (gf.getImage().isNull()) {
                return;
            }
            // В іншому випадку, додаємо зображення до списку та показуємо кнопки навігації
            handler->getImages().append(gf);
            ui->P1_nextImage->show();
            ui->P1_prevImage->show();
            // Завантажуємо зображення та оновлюємо список
            loadImage();
            loadImagesIntoList(handler->getImages());
            file.close();
        } else {
            QMessageBox::warning(this, "Помилка", "Неможливо відкрити файл.");
        }
    }
}

// Пошук зображення з найбільшим та найменшим розміром на диску
void MainWindow::on_P2_displayMinMaxSize_clicked() {

    // Перевірка на наявність зображення
    if (handler->getImages().isEmpty()) {
        QMessageBox::information(this, "Інформація", "Зображення не завантажено");
        return;
    }

    // Сортуємо за розміром на диску в зростаючому порядку
    auto& files = handler->getImages();
    handler->quickSort(0, files.size() - 1, [](const GraphicFile& a, const GraphicFile& b) {
        return a.getSize() < b.getSize();
    });

    // Діалогове вікно з виводом результату
    QString output = "Файл з найменшим розміром на диску - " + handler->getImages().front().getName() +
                     "\nФайл з найбільшим розміром на диску - " + handler->getImages().back().getName();
    QMessageBox::information(this, "Information", output);
}

// Експорт зображення в інший формат
void MainWindow::on_M_changeFormat_triggered() {
    // Перевірка на наявність зображення
    if (handler->getImages().isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Зображення не завантажено.");
        return;
    }

    bool ok;
    // Доступні формати
    QStringList formats;
    for (const QByteArray &format : QImageWriter::supportedImageFormats())
        formats.append(QString(format));

    // Просимо користувача вибрати формат з переліку
    QString format = QInputDialog::getItem(this, "Вибір формату", "Виберіть новий формат зображення:", formats, 0, false, &ok);

    if (!ok) return; // Користувач передумав - вихід з функції

    // Відкриваємо вікно з вибором папки
    QString directory = QFileDialog::getExistingDirectory(this, "Вибір папки", QDir::homePath());

    if (directory.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Папку не вибрано.");
        return;
    }

    handler->getCurrentImage().exportToFormat(format, directory);
}

// Відображення зображень в заданому діапазоні
void MainWindow::on_P2_searchInSizeRange_clicked() {
    // Перевірка на наявність зображень
    if (handler->getImages().isEmpty()) {
        QMessageBox::information(this, "Інформація", "Зображення не завантажено");
        return;
    }

    QVector<GraphicFile> filteredFiles;

    // Переводимо МБ в КБ
    double minSize = ui->P2_minSize->text().toDouble() * 1024;
    double maxSize = ui->P2_maxSize->text().toDouble() * 1024;

    filteredFiles = handler->searchBySizeRange(handler->getImages(), minSize, maxSize);

    // Очищаємо список та заповнюємо знайденими зображеннями
    ui->P2_imageListView->clear();
    loadImagesIntoList(filteredFiles);

    if (filteredFiles.isEmpty()) {
        QMessageBox::information(this, "Результат пошуку", "Жодне зображення не відповідає заданим параметрам.");
    }
}

// Сортуємо список при зміні порядку сортування (Наприклад з спадаючого на зростаючий чи навпаки)
void MainWindow::on_P2_inDescending_toggled(bool checked) {
    on_P2_sort_currentIndexChanged(ui->P2_sort->currentIndex());
}

// Створення власного об'єкту типу Графіний файл
void MainWindow::on_M_createObject_triggered() {
    bool ok;

    QString imageName = QInputDialog::getText(this, tr("Назва зображення"), tr("Введіть назву зображення:"), QLineEdit::Normal, "", &ok);

    if (!ok) return;
    if (imageName.isEmpty() || std::all_of(imageName.begin(), imageName.end(), [](QChar c) { return c == ' ';}) || imageName.size() >= 100) {
        QMessageBox::warning(this, tr("Помилка"), tr("Введені дані некоретні!"));
        return;
    }

    int imageSize = QInputDialog::getInt(this, tr("Розмір зображення"), tr("Введіть розмір зображення(KB):"), 1, 1, 100000, 1, &ok);
    if (!ok) return;
    int imageWidth = QInputDialog::getInt(this, tr("Ширина зображення"), tr("Введіть ширину зображення(в пікселях):"), 1, 1, 1920, 1, &ok);
    if (!ok) return;
    int imageHeight = QInputDialog::getInt(this, tr("Висота зображення"), tr("Введіть висоту зображення:"), 1, 1, 1080, 1, &ok);
    if (!ok) return;

    QStringList formats;
    for (const QByteArray &format : QImageWriter::supportedImageFormats())
        formats.append(QString(format));

    QString format = QInputDialog::getItem(this, tr("Формат зображення"), tr("Виберіть формат зображення:"), formats, 0, false, &ok);
    if (!ok) return;

    QString dateCreated = QInputDialog::getText(this, tr("Дата створення"), tr("Введіть дату створення(РРРР-ММ-ДД):"), QLineEdit::Normal, "", &ok);

    QRegularExpression regex("^\\d{4}-\\d{2}-\\d{2}$");
    if (ok && !regex.match(dateCreated).hasMatch()) {
        QMessageBox::warning(this, tr("Помилка"), tr("Введені дані некоректні!"));
        return;
    }

    QString softwareUsed = QInputDialog::getText(this, tr("ПЗ для редагування"), tr("Введіть ПЗ для редагування:"), QLineEdit::Normal, "", &ok);

    if (softwareUsed.isEmpty() || softwareUsed.size() >= 25) {
        QMessageBox::warning(this, tr("Помилка"), tr("Введені дані некоректні!"));
        return;
    }

    int isCompressedInt = QInputDialog::getInt(this, tr("Зображення стиснуте?"),
                                               tr("Введіть 1, якщо зображення стиснуте. 0, якщо ні:"), 0, 0, 1, 1, &ok);
    bool isCompressed = (isCompressedInt == 1);

    if (!ok) return;

    // Підводимо підсумки введеної інформації
    QMessageBox::information(this, tr("Інформація"),
                             tr("Ім'я: %1\n"
                                "Розмір: %2 KB\n"
                                "Розширення : %3 x %4\n"
                                "Формат: %5\n"
                                "Дата створення: %6\n"
                                "ПЗ для редагування: %7\n"
                                "Стиснуте?: %8")
                             .arg(imageName)
                             .arg(imageSize)
                             .arg(imageWidth)
                             .arg(imageHeight)
                             .arg(format)
                             .arg(dateCreated)
                             .arg(softwareUsed)
                             .arg(isCompressed ? tr("Так") : tr("Ні")));

    // Завантажуємо ярлик, що повідомляє про відсутність зображення
    QImage image(":/new/images/C:/Users/Lenovo/Downloads/No_Image_Available.jpg");
    handler->getImages().append(GraphicFile(imageName, imageWidth, imageHeight, imageSize, format, image, dateCreated));
    loadImage();
    loadImagesIntoList(handler->getImages());
    // Показуємо кнопки навігації
    ui->P1_nextImage->show();
    ui->P1_prevImage->show();
}
