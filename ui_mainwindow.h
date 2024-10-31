/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *M_exportToFile;
    QAction *M_importFromFile;
    QAction *M_changeFormat;
    QAction *action;
    QAction *M_openFolder;
    QAction *M_createObject;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QToolButton *P1_nextImage;
    QToolButton *P1_sizeIcon;
    QToolButton *P1_delete;
    QToolButton *P1_resolutionIcon;
    QToolButton *P1_zoomOut;
    QToolButton *P1_zoomIn;
    QLabel *P1_size;
    QLabel *P1_resolution;
    QLabel *P1_mainImageView;
    QToolButton *P1_prevImage;
    QLabel *P1_name;
    QLabel *P1_scale;
    QHBoxLayout *horizontalLayout;
    QToolButton *P1_toList;
    QToolButton *P1_rotate;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QGroupBox *searchGroupBox;
    QFormLayout *formLayout;
    QLineEdit *P2_widthFilter;
    QLineEdit *P2_heightFilter;
    QLineEdit *P2_sizeFilter;
    QComboBox *P2_formatFilter;
    QPushButton *P2_search;
    QListWidget *P2_imageListView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLabel *P2_detailsTitle;
    QLabel *P2_imageDetails;
    QRadioButton *P2_inAscending;
    QLabel *P2_imagePreview;
    QRadioButton *P2_inDescending;
    QComboBox *P2_sort;
    QLineEdit *P2_minSize;
    QLineEdit *P2_maxSize;
    QPushButton *P2_searchInSizeRange;
    QPushButton *P2_displayMinMaxSize;
    QFrame *P2_separator;
    QMenuBar *menuBar;
    QMenu *File;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(964, 739);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::CameraPhoto));
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        M_exportToFile = new QAction(MainWindow);
        M_exportToFile->setObjectName("M_exportToFile");
        M_importFromFile = new QAction(MainWindow);
        M_importFromFile->setObjectName("M_importFromFile");
        M_changeFormat = new QAction(MainWindow);
        M_changeFormat->setObjectName("M_changeFormat");
        action = new QAction(MainWindow);
        action->setObjectName("action");
        M_openFolder = new QAction(MainWindow);
        M_openFolder->setObjectName("M_openFolder");
        M_createObject = new QAction(MainWindow);
        M_createObject->setObjectName("M_createObject");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName("gridLayout");
        P1_nextImage = new QToolButton(page);
        P1_nextImage->setObjectName("P1_nextImage");
        P1_nextImage->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        P1_nextImage->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(P1_nextImage, 1, 7, 1, 1);

        P1_sizeIcon = new QToolButton(page);
        P1_sizeIcon->setObjectName("P1_sizeIcon");
        P1_sizeIcon->setEnabled(false);
        P1_sizeIcon->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        P1_sizeIcon->setStyleSheet(QString::fromUtf8("border:none"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentSave));
        P1_sizeIcon->setIcon(icon1);

        gridLayout->addWidget(P1_sizeIcon, 2, 5, 1, 1);

        P1_delete = new QToolButton(page);
        P1_delete->setObjectName("P1_delete");
        P1_delete->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        P1_delete->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        P1_delete->setIcon(icon2);

        gridLayout->addWidget(P1_delete, 0, 7, 1, 1);

        P1_resolutionIcon = new QToolButton(page);
        P1_resolutionIcon->setObjectName("P1_resolutionIcon");
        P1_resolutionIcon->setEnabled(false);
        P1_resolutionIcon->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        P1_resolutionIcon->setStyleSheet(QString::fromUtf8("border:none"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::ZoomFitBest));
        P1_resolutionIcon->setIcon(icon3);

        gridLayout->addWidget(P1_resolutionIcon, 2, 7, 1, 1);

        P1_zoomOut = new QToolButton(page);
        P1_zoomOut->setObjectName("P1_zoomOut");
        P1_zoomOut->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        P1_zoomOut->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::ZoomOut));
        P1_zoomOut->setIcon(icon4);

        gridLayout->addWidget(P1_zoomOut, 2, 0, 1, 1);

        P1_zoomIn = new QToolButton(page);
        P1_zoomIn->setObjectName("P1_zoomIn");
        P1_zoomIn->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        P1_zoomIn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::ZoomIn));
        P1_zoomIn->setIcon(icon5);

        gridLayout->addWidget(P1_zoomIn, 2, 2, 1, 1);

        P1_size = new QLabel(page);
        P1_size->setObjectName("P1_size");
        P1_size->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(P1_size, 2, 4, 1, 1);

        P1_resolution = new QLabel(page);
        P1_resolution->setObjectName("P1_resolution");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(P1_resolution->sizePolicy().hasHeightForWidth());
        P1_resolution->setSizePolicy(sizePolicy);
        P1_resolution->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout->addWidget(P1_resolution, 2, 6, 1, 1);

        P1_mainImageView = new QLabel(page);
        P1_mainImageView->setObjectName("P1_mainImageView");
        P1_mainImageView->setMinimumSize(QSize(800, 600));
        P1_mainImageView->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(P1_mainImageView, 1, 1, 1, 6);

        P1_prevImage = new QToolButton(page);
        P1_prevImage->setObjectName("P1_prevImage");
        P1_prevImage->setEnabled(true);
        P1_prevImage->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        P1_prevImage->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(P1_prevImage, 1, 0, 1, 1);

        P1_name = new QLabel(page);
        P1_name->setObjectName("P1_name");
        P1_name->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(P1_name, 0, 2, 1, 5);

        P1_scale = new QLabel(page);
        P1_scale->setObjectName("P1_scale");
        P1_scale->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(P1_scale->sizePolicy().hasHeightForWidth());
        P1_scale->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(P1_scale, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        P1_toList = new QToolButton(page);
        P1_toList->setObjectName("P1_toList");
        P1_toList->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::FormatJustifyCenter));
        P1_toList->setIcon(icon6);

        horizontalLayout->addWidget(P1_toList);

        P1_rotate = new QToolButton(page);
        P1_rotate->setObjectName("P1_rotate");
        P1_rotate->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        P1_rotate->setStyleSheet(QString::fromUtf8(""));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::ViewRefresh));
        P1_rotate->setIcon(icon7);

        horizontalLayout->addWidget(P1_rotate);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setObjectName("gridLayout_3");
        searchGroupBox = new QGroupBox(page_2);
        searchGroupBox->setObjectName("searchGroupBox");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(searchGroupBox->sizePolicy().hasHeightForWidth());
        searchGroupBox->setSizePolicy(sizePolicy2);
        formLayout = new QFormLayout(searchGroupBox);
        formLayout->setObjectName("formLayout");
        P2_widthFilter = new QLineEdit(searchGroupBox);
        P2_widthFilter->setObjectName("P2_widthFilter");

        formLayout->setWidget(0, QFormLayout::SpanningRole, P2_widthFilter);

        P2_heightFilter = new QLineEdit(searchGroupBox);
        P2_heightFilter->setObjectName("P2_heightFilter");

        formLayout->setWidget(1, QFormLayout::SpanningRole, P2_heightFilter);

        P2_sizeFilter = new QLineEdit(searchGroupBox);
        P2_sizeFilter->setObjectName("P2_sizeFilter");

        formLayout->setWidget(2, QFormLayout::SpanningRole, P2_sizeFilter);

        P2_formatFilter = new QComboBox(searchGroupBox);
        P2_formatFilter->addItem(QString());
        P2_formatFilter->addItem(QString());
        P2_formatFilter->addItem(QString());
        P2_formatFilter->addItem(QString());
        P2_formatFilter->addItem(QString());
        P2_formatFilter->setObjectName("P2_formatFilter");

        formLayout->setWidget(3, QFormLayout::SpanningRole, P2_formatFilter);

        P2_search = new QPushButton(searchGroupBox);
        P2_search->setObjectName("P2_search");

        formLayout->setWidget(4, QFormLayout::SpanningRole, P2_search);


        gridLayout_3->addWidget(searchGroupBox, 0, 2, 1, 1);

        P2_imageListView = new QListWidget(page_2);
        P2_imageListView->setObjectName("P2_imageListView");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(P2_imageListView->sizePolicy().hasHeightForWidth());
        P2_imageListView->setSizePolicy(sizePolicy3);
        P2_imageListView->setFrameShape(QFrame::Shape::StyledPanel);
        P2_imageListView->setFrameShadow(QFrame::Shadow::Plain);
        P2_imageListView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        P2_imageListView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        P2_imageListView->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        P2_imageListView->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked|QAbstractItemView::EditTrigger::EditKeyPressed|QAbstractItemView::EditTrigger::SelectedClicked);
        P2_imageListView->setProperty("showDropIndicator", QVariant(false));
        P2_imageListView->setDragDropMode(QAbstractItemView::DragDropMode::DragDrop);
        P2_imageListView->setDefaultDropAction(Qt::DropAction::IgnoreAction);
        P2_imageListView->setAlternatingRowColors(false);
        P2_imageListView->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
        P2_imageListView->setIconSize(QSize(64, 64));
        P2_imageListView->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        P2_imageListView->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);
        P2_imageListView->setMovement(QListView::Movement::Free);
        P2_imageListView->setFlow(QListView::Flow::LeftToRight);
        P2_imageListView->setResizeMode(QListView::ResizeMode::Adjust);
        P2_imageListView->setLayoutMode(QListView::LayoutMode::SinglePass);
        P2_imageListView->setSpacing(0);
        P2_imageListView->setGridSize(QSize(100, 100));
        P2_imageListView->setViewMode(QListView::ViewMode::IconMode);
        P2_imageListView->setModelColumn(0);
        P2_imageListView->setSortingEnabled(false);

        gridLayout_3->addWidget(P2_imageListView, 2, 2, 1, 1);

        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(300, 256));
        groupBox->setMaximumSize(QSize(256, 16777215));
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName("gridLayout_4");
        P2_detailsTitle = new QLabel(groupBox);
        P2_detailsTitle->setObjectName("P2_detailsTitle");
        sizePolicy2.setHeightForWidth(P2_detailsTitle->sizePolicy().hasHeightForWidth());
        P2_detailsTitle->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(P2_detailsTitle, 2, 0, 1, 1);

        P2_imageDetails = new QLabel(groupBox);
        P2_imageDetails->setObjectName("P2_imageDetails");
        P2_imageDetails->setMinimumSize(QSize(256, 0));
        P2_imageDetails->setFrameShape(QFrame::Shape::NoFrame);
        P2_imageDetails->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        gridLayout_4->addWidget(P2_imageDetails, 3, 0, 1, 1);

        P2_inAscending = new QRadioButton(groupBox);
        P2_inAscending->setObjectName("P2_inAscending");
        P2_inAscending->setChecked(true);

        gridLayout_4->addWidget(P2_inAscending, 4, 0, 1, 1);

        P2_imagePreview = new QLabel(groupBox);
        P2_imagePreview->setObjectName("P2_imagePreview");
        P2_imagePreview->setMinimumSize(QSize(256, 256));
        P2_imagePreview->setMaximumSize(QSize(256, 256));
        P2_imagePreview->setFrameShape(QFrame::Shape::NoFrame);
        P2_imagePreview->setMidLineWidth(0);
        P2_imagePreview->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(P2_imagePreview, 0, 0, 1, 1);

        P2_inDescending = new QRadioButton(groupBox);
        P2_inDescending->setObjectName("P2_inDescending");

        gridLayout_4->addWidget(P2_inDescending, 4, 1, 1, 1);

        P2_sort = new QComboBox(groupBox);
        P2_sort->addItem(QString());
        P2_sort->addItem(QString());
        P2_sort->addItem(QString());
        P2_sort->addItem(QString());
        P2_sort->setObjectName("P2_sort");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(P2_sort->sizePolicy().hasHeightForWidth());
        P2_sort->setSizePolicy(sizePolicy4);
        P2_sort->setFrame(true);

        gridLayout_4->addWidget(P2_sort, 5, 0, 1, 2);

        P2_minSize = new QLineEdit(groupBox);
        P2_minSize->setObjectName("P2_minSize");

        gridLayout_4->addWidget(P2_minSize, 6, 0, 1, 2);

        P2_maxSize = new QLineEdit(groupBox);
        P2_maxSize->setObjectName("P2_maxSize");

        gridLayout_4->addWidget(P2_maxSize, 7, 0, 1, 2);

        P2_searchInSizeRange = new QPushButton(groupBox);
        P2_searchInSizeRange->setObjectName("P2_searchInSizeRange");

        gridLayout_4->addWidget(P2_searchInSizeRange, 8, 0, 1, 2);

        P2_displayMinMaxSize = new QPushButton(groupBox);
        P2_displayMinMaxSize->setObjectName("P2_displayMinMaxSize");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(P2_displayMinMaxSize->sizePolicy().hasHeightForWidth());
        P2_displayMinMaxSize->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(P2_displayMinMaxSize, 9, 0, 1, 2);

        P2_separator = new QFrame(groupBox);
        P2_separator->setObjectName("P2_separator");
        P2_separator->setFrameShape(QFrame::Shape::HLine);
        P2_separator->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_4->addWidget(P2_separator, 1, 0, 1, 2);


        gridLayout_3->addWidget(groupBox, 0, 3, 3, 1);

        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 964, 25));
        menuBar->setNativeMenuBar(false);
        File = new QMenu(menuBar);
        File->setObjectName("File");
        File->setGeometry(QRect(290, 115, 280, 200));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(File->menuAction());
        File->addAction(M_openFolder);
        File->addAction(M_createObject);
        File->addSeparator();
        File->addAction(M_exportToFile);
        File->addAction(M_importFromFile);
        File->addSeparator();
        File->addAction(M_changeFormat);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        P2_sort->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\223\320\260\320\273\320\265\321\200\320\265\321\217", nullptr));
        M_exportToFile->setText(QCoreApplication::translate("MainWindow", "\320\225\320\272\321\201\320\277\320\276\321\200\321\202 \320\264\320\260\320\275\320\270\321\205 \321\203 \321\204\320\260\320\271\320\273", nullptr));
        M_importFromFile->setText(QCoreApplication::translate("MainWindow", "\320\206\320\274\320\277\320\276\321\200\321\202 \320\264\320\260\320\275\320\270\321\205 \321\226\320\267 \321\204\320\260\320\271\320\273\321\203", nullptr));
        M_changeFormat->setText(QCoreApplication::translate("MainWindow", "\320\225\320\272\321\201\320\277\320\276\321\200\321\202 \321\204\320\260\320\271\320\273\321\203 \320\262 \321\226\320\275\321\210\320\270\320\271 \321\204\320\276\321\200\320\274\320\260\321\202", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\222\321\226\320\264\320\272\321\200\320\270\321\202\320\270 \320\277\320\260\320\277\320\272\321\203", nullptr));
        M_openFolder->setText(QCoreApplication::translate("MainWindow", "\320\222\321\226\320\264\320\272\321\200\320\270\321\202\320\270 \320\277\320\260\320\277\320\272\321\203", nullptr));
        M_createObject->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270 \320\276\320\261'\321\224\320\272\321\202 \320\262\321\200\321\203\321\207\320\275\321\203", nullptr));
#if QT_CONFIG(tooltip)
        P1_nextImage->setToolTip(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\203\320\277\320\275\320\265 \320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217", nullptr));
#endif // QT_CONFIG(tooltip)
        P1_nextImage->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
#if QT_CONFIG(tooltip)
        P1_sizeIcon->setToolTip(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\267\320\274\321\226\321\200 \320\275\320\260 \320\264\320\270\321\201\320\272\321\203", nullptr));
#endif // QT_CONFIG(tooltip)
        P1_sizeIcon->setText(QString());
#if QT_CONFIG(tooltip)
        P1_delete->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
        P1_delete->setText(QString());
#if QT_CONFIG(tooltip)
        P1_resolutionIcon->setToolTip(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\267\321\210\320\270\321\200\320\265\320\275\320\275\321\217", nullptr));
#endif // QT_CONFIG(tooltip)
        P1_resolutionIcon->setText(QString());
#if QT_CONFIG(tooltip)
        P1_zoomOut->setToolTip(QCoreApplication::translate("MainWindow", "\320\227\320\274\320\265\320\275\321\210\320\270\321\202\320\270 \320\274\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
#endif // QT_CONFIG(tooltip)
        P1_zoomOut->setText(QString());
#if QT_CONFIG(tooltip)
        P1_zoomIn->setToolTip(QCoreApplication::translate("MainWindow", "\320\227\320\261\321\226\320\273\321\214\321\210\320\270\321\202\320\270 \320\274\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
#endif // QT_CONFIG(tooltip)
        P1_zoomIn->setText(QString());
        P1_size->setText(QString());
        P1_resolution->setText(QString());
        P1_mainImageView->setText(QCoreApplication::translate("MainWindow", "\320\227\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217 \320\275\320\265 \320\267\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\265\320\275\320\276", nullptr));
#if QT_CONFIG(tooltip)
        P1_prevImage->setToolTip(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\277\320\265\321\200\320\265\320\264\320\275\321\224 \320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217", nullptr));
#endif // QT_CONFIG(tooltip)
        P1_prevImage->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        P1_name->setText(QString());
        P1_scale->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261: 100%", nullptr));
#if QT_CONFIG(tooltip)
        P1_toList->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\321\226\320\264\320\272\321\200\320\270\321\202\320\270 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
#endif // QT_CONFIG(tooltip)
        P1_toList->setText(QString());
#if QT_CONFIG(tooltip)
        P1_rotate->setToolTip(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\320\270 \320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217", nullptr));
#endif // QT_CONFIG(tooltip)
        P1_rotate->setText(QString());
        searchGroupBox->setTitle(QString());
        P2_widthFilter->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\250\320\270\321\200\320\270\320\275\320\260", nullptr));
        P2_heightFilter->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\270\321\201\320\276\321\202\320\260", nullptr));
        P2_sizeFilter->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\267\320\274\321\226\321\200 (KB)", nullptr));
        P2_formatFilter->setItemText(0, QCoreApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260\321\202", nullptr));
        P2_formatFilter->setItemText(1, QCoreApplication::translate("MainWindow", "BMP", nullptr));
        P2_formatFilter->setItemText(2, QCoreApplication::translate("MainWindow", "PNG", nullptr));
        P2_formatFilter->setItemText(3, QCoreApplication::translate("MainWindow", "JPEG", nullptr));
        P2_formatFilter->setItemText(4, QCoreApplication::translate("MainWindow", "JPG", nullptr));

        P2_search->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\210\321\203\320\272", nullptr));
        groupBox->setTitle(QString());
        P2_detailsTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">\320\224\320\265\321\202\320\260\320\273\321\226:</span></p></body></html>", nullptr));
        P2_imageDetails->setText(QString());
        P2_inAscending->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260 \320\267\321\200\320\276\321\201\321\202\320\260\320\275\320\275\321\217\320\274", nullptr));
        P2_imagePreview->setText(QString());
        P2_inDescending->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260 \321\201\320\277\320\260\320\264\320\260\320\275\320\275\321\217\320\274", nullptr));
        P2_sort->setItemText(0, QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\321\203\320\262\320\260\321\202\320\270 \320\267\320\260 \321\226\320\274\320\265\320\275\320\265\320\274", nullptr));
        P2_sort->setItemText(1, QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\321\203\320\262\320\260\321\202\320\270 \320\267\320\260 \321\200\320\276\320\267\320\274\321\226\321\200\320\276\320\274", nullptr));
        P2_sort->setItemText(2, QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\321\203\320\262\320\260\321\202\320\270 \320\267\320\260 \321\210\320\270\321\200\320\270\320\275\320\276\321\216", nullptr));
        P2_sort->setItemText(3, QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\321\203\320\262\320\260\321\202\320\270 \320\267 \320\262\320\270\321\201\320\276\321\202\320\276\321\216", nullptr));

        P2_sort->setCurrentText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\321\203\320\262\320\260\321\202\320\270 \320\267\320\260 \321\226\320\274\320\265\320\275\320\265\320\274", nullptr));
        P2_minSize->setText(QString());
        P2_minSize->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\234\321\226\320\275\321\226\320\274\320\260\320\273\321\214\320\275\320\270\320\271 \321\200\320\276\320\267\320\274\321\226\321\200 (\320\234\320\221)", nullptr));
        P2_maxSize->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\270\320\271 \321\200\320\276\320\267\320\274\321\226\321\200 (\320\234\320\221)", nullptr));
        P2_searchInSizeRange->setText(QCoreApplication::translate("MainWindow", "\320\227\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217 \321\203 \320\267\320\260\320\264\320\260\320\275\320\276\320\274\321\203 \320\264\321\226\320\260\320\277\320\260\320\267\320\276\320\275\321\226", nullptr));
        P2_displayMinMaxSize->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\262\320\265\321\201\321\202\320\270 \320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\275\321\217 \320\267 \320\275\320\260\320\271\320\274\320\265\320\275\321\210\320\270\320\274\n"
" \321\226 \320\275\320\260\320\271\320\261\321\226\320\273\321\214\321\210\320\270\320\274 \321\200\320\276\320\267\320\274\321\226\321\200\320\276\320\274 \320\275\320\260 \320\264\320\270\321\201\320\272\321\203", nullptr));
        File->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
